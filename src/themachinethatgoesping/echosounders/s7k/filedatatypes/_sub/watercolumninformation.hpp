// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/watercolumninformation.doc.hpp"

/* std includes */
#include <cmath>
#include <cstdint>
#include <string>
#include <unordered_map>

/* boost includes */
#include <boost/flyweight.hpp>

// xtensor includes
#include <xtensor/containers/xtensor.hpp>
#include <xtensor/core/xmath.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/helper/xtensor_hash.hpp>

#include "../../datagrams/compressedwatercolumn.hpp"
#include "../../datagrams/substructs/compressedwatercolumndatatypes.hpp"

#include "_wciinfos.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {
namespace _sub {

/**
 * @brief Lightweight water-column information of a single s7k ping (7042 CompressedWaterColumnData).
 *
 * It stores only what is needed to read the water column efficiently - the per-beam sample counts
 * and the per-beam file positions of the samples - but NOT the samples themselves. The samples are
 * read on demand (a subset of beams / samples at a time) directly from the file via
 * read_beam_samples() and returned to the caller, so they are never held in memory. The per-beam
 * numbers / sample counts and the record-wide information are deduplicated across pings with
 * flyweights.
 *
 * Note this is a private substructure and thus not part of the public API or nanobind interface.
 */
class WaterColumnInformation
{
    // deduplicated (identical across consecutive pings in the common case)
    boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>> _beam_numbers;
    boost::flyweights::flyweight<xt::xtensor<uint32_t, 1>> _sample_counts;
    boost::flyweights::flyweight<_WCIInfos>                _wci_infos;

    // unique per ping (file offsets of each beam's samples)
    xt::xtensor<int64_t, 1> _sample_positions;

    WaterColumnInformation() = default; // for from_stream

  public:
    /**
     * @brief Build the water-column information from a 7042 record that was read with skip_data =
     * true (i.e. only the per-beam headers + sample positions were read, not the samples).
     */
    explicit WaterColumnInformation(const datagrams::CompressedWaterColumn& water_column_datagram);

    bool operator==(const WaterColumnInformation& other) const = default;

    // ----- accessors -----
    const xt::xtensor<uint16_t, 1>& get_beam_numbers() const { return _beam_numbers.get(); }
    const xt::xtensor<uint32_t, 1>& get_sample_counts() const { return _sample_counts.get(); }
    const xt::xtensor<int64_t, 1>&  get_sample_positions() const { return _sample_positions; }

    size_t   get_number_of_beams() const { return _beam_numbers.get().size(); }
    uint32_t get_first_sample() const { return _wci_infos.get().get_first_sample(); }
    float    get_sample_rate() const { return _wci_infos.get().get_sample_rate(); }
    uint8_t  get_downsampling_divisor() const { return _wci_infos.get().get_downsampling_divisor(); }
    bool     get_has_phase() const { return _wci_infos.get().get_has_phase(); }
    bool     get_magnitude_is_db() const { return _wci_infos.get().get_magnitude_is_db(); }
    bool     get_magnitude_is_32bit() const { return _wci_infos.get().get_magnitude_is_32bit(); }
    float    get_magnitude_compression_factor() const
    {
        return _wci_infos.get().get_magnitude_compression_factor();
    }

    datagrams::substructs::t_CompressedWaterColumnDataType get_data_type() const
    {
        return _wci_infos.get().get_data_type();
    }

    /**
     * @brief Read a (contiguous) sub-range of one beam's samples from the file.
     *
     * The samples are returned in their native (on-disk) encoding as a
     * CompressedWaterColumnDataVariant (magnitude / phase decoding is deferred to the accessor). The
     * data is read directly from the stream and returned - it is never stored on this object.
     *
     * @tparam t_ifstream input stream type
     * @param beam_number index of the beam (0-based, into the per-beam arrays)
     * @param first_sample first sample (within the beam) to read
     * @param number_of_samples number of samples to read
     * @param ifs input stream of the file the 7042 record was read from
     */
    template<typename t_ifstream>
    datagrams::substructs::CompressedWaterColumnDataVariant read_beam_samples(
        uint16_t    beam_number,
        uint32_t    first_sample,
        uint32_t    number_of_samples,
        t_ifstream& ifs) const
    {
        ifs.seekg(_sample_positions.unchecked(beam_number) +
                  int64_t(first_sample) * _wci_infos.get().get_bytes_per_sample());
        return datagrams::substructs::compressed_water_column_data_from_stream(
            ifs, _wci_infos.get().get_data_type(), number_of_samples);
    }

    /**
     * @brief Convert raw magnitude values (as float) to dB according to the record encoding.
     *
     * Vectorized (xsimd friendly) expression reused by the ping water-column accessor to convert
     * only the selected beams/samples. 16/32-bit values are 20*log10(mag/full_scale). 8-bit values
     * store floor(factor*log10(mag)+0.5) (a compressed dB; DFD Appendix I) and are expanded back to
     * the same full-scale-referenced dB scale using the record's compression factor.
     */
    template<class Tensor>
    Tensor convert_magnitude_to_db(Tensor magnitude) const
    {
        if (_wci_infos.get().get_magnitude_is_db())
        {
            // stored = factor*log10(mag) -> 20*log10(mag) = stored * 20/factor. Reference it to full
            // scale (65535) so 8-bit data lands on the same dB scale as the 16-bit path (the
            // constant offset is otherwise absorbed by the system gain offset).
            const float factor        = _wci_infos.get().get_magnitude_compression_factor();
            const float scale         = (factor > 0.f) ? (20.f / factor) : 1.f;
            const float full_scale_db = 20.f * std::log10(65535.f);
            return xt::eval(magnitude * scale - full_scale_db);
        }

        const float full_scale = _wci_infos.get().get_magnitude_is_32bit() ? 1.f : 65535.f;
        magnitude              = xt::eval(20.f * xt::log10(magnitude / full_scale));
        return magnitude;
    }

    // ----- functions used for PackageCache -----
    void to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const;

    static WaterColumnInformation from_stream(
        std::istream&                                  is,
        const std::unordered_map<size_t, std::string>& hash_cache);
};

} // namespace _sub
} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
