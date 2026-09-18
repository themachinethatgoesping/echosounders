// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/compressedwatercolumnbeamcontainer.doc.hpp"

// std includes
#include <cstddef>
#include <cstdint>
#include <numbers>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "compressedwatercolumnbeam.hpp"
#include "compressedwatercolumndatatypes.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Container for the per-beam data of a 7042 CompressedWaterColumnData record.
 *
 * Holds the per-beam samples (each beam stores its data in its native, on-disk encoding, see
 * CompressedWaterColumnDataVariant) and the record-wide sample encoding (magnitude bit depth,
 * presence of phase). Magnitude/phase are converted to float / dB / degrees on demand; the dB and
 * phase conversions are centralized here (convert_magnitude_to_db / phase constants) and reused by
 * the ping water column accessor for the deferred, vectorized bulk conversion. If the samples were
 * skipped while reading, the file position is stored so they can be read lazily.
 */
class CompressedWaterColumnBeamContainer
{
  public:
    static constexpr float PHASE_TO_RADIANS = 1.f / 10430.f; ///< int16 phase value * this = radians

    CompressedWaterColumnBeamContainer()  = default;
    ~CompressedWaterColumnBeamContainer() = default;

    // ----- raw struct access -----
    const std::vector<CompressedWaterColumnBeam>& get_beams() const;
    std::vector<CompressedWaterColumnBeam>&       beams();
    void set_beams(const std::vector<CompressedWaterColumnBeam>& beams);

    // ----- record-wide sample encoding -----
    uint8_t get_magnitude_bytes() const;
    bool    get_has_phase() const;
    bool    get_magnitude_is_db() const;
    bool    get_magnitude_is_32bit() const;

    void set_magnitude_bytes(uint8_t val);
    void set_has_phase(bool val);
    void set_magnitude_is_db(bool val);

    /// the per-sample encoding of this record (derived from the encoding flags)
    t_CompressedWaterColumnDataType get_data_type() const;

    // ----- per-field tensor access (built on demand) -----
    xt::xtensor<uint16_t, 1> get_beam_number_tensor() const;
    xt::xtensor<uint8_t, 1>  get_segment_number_tensor() const;
    xt::xtensor<uint32_t, 1> get_sample_count_tensor() const;

    // ----- decoded per-beam access (computed on demand from the native samples) -----
    /// magnitude of a beam (raw values as float, not dB)
    xt::xtensor<float, 1> get_magnitude(size_t beam_index) const;
    /// phase of a beam in radians (empty if there is no phase)
    xt::xtensor<float, 1> get_phase(size_t beam_index) const;
    /// magnitude of a beam in dB (already-dB values pass through, else 20*log10(mag/full_scale))
    xt::xtensor<float, 1> get_magnitude_in_db(size_t beam_index) const;
    /// phase of a beam in degrees (empty if there is no phase)
    xt::xtensor<float, 1> get_phase_in_degrees(size_t beam_index) const;

    std::vector<xt::xtensor<float, 1>> get_magnitudes() const;
    std::vector<xt::xtensor<float, 1>> get_phases() const;
    std::vector<xt::xtensor<float, 1>> get_magnitudes_in_db() const;

    /**
     * @brief Convert raw magnitude values (as float) to dB, according to the record encoding.
     *
     * This is a vectorized (xsimd-friendly) expression that is reused by the ping water column
     * accessor to convert only the selected beams/samples. 8 bit values are already stored in a
     * (compressed) dB scale and pass through; 16/32 bit values are 20*log10(mag/full_scale).
     *
     * @tparam Tensor xtensor of float (1D per beam or 2D beams x samples)
     */
    template<class Tensor>
    Tensor convert_magnitude_to_db(Tensor magnitude) const
    {
        if (_magnitude_is_db)
            return magnitude;

        const float full_scale = get_magnitude_is_32bit() ? 1.f : 65535.f;
        magnitude              = xt::eval(20.f * xt::log10(magnitude / full_scale));
        return magnitude;
    }

    // ----- processed -----
    size_t get_number_of_beams() const;
    size_t get_total_number_of_samples() const;

    // ----- skip / lazy reading -----
    bool    get_samples_are_skipped() const;
    int64_t get_sample_position() const;
    void    set_skipped(int64_t sample_position);
    void    clear_skipped();

    // ----- operators -----
    bool operator==(const CompressedWaterColumnBeamContainer& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<CompressedWaterColumnBeam> _beams;

    // record-wide sample encoding (from the record flags)
    uint8_t _magnitude_bytes = 2;
    bool    _has_phase       = false;
    bool    _magnitude_is_db = false;

    bool    _skipped         = false;
    int64_t _sample_position = -1;

    template<typename ValueType, typename Getter>
    xt::xtensor<ValueType, 1> build_tensor(Getter&& getter) const
    {
        auto tensor = xt::xtensor<ValueType, 1>::from_shape({ _beams.size() });
        for (std::size_t idx = 0; idx < _beams.size(); ++idx)
            tensor.unchecked(idx) = static_cast<ValueType>(getter(_beams[idx]));
        return tensor;
    }
};

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
