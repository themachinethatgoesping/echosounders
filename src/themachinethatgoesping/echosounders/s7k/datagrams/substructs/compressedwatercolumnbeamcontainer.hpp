// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/compressedwatercolumnbeamcontainer.doc.hpp"

// std includes
#include <cstddef>
#include <cstdint>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "compressedwatercolumnbeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Container for the per-beam data of a 7042 CompressedWaterColumnData record.
 *
 * Holds the per-beam magnitude/phase blocks (as raw bytes, decoded on demand). If the samples were
 * skipped while reading, the file position is stored so they can be read lazily.
 */
class CompressedWaterColumnBeamContainer
{
  public:
    CompressedWaterColumnBeamContainer()  = default;
    ~CompressedWaterColumnBeamContainer() = default;

    // ----- raw struct access -----
    const std::vector<CompressedWaterColumnBeam>& get_beams() const;
    std::vector<CompressedWaterColumnBeam>&       beams();
    void set_beams(const std::vector<CompressedWaterColumnBeam>& beams);

    // ----- per-field tensor access (built on demand) -----
    xt::xtensor<uint16_t, 1> get_beam_number_tensor() const;
    xt::xtensor<uint8_t, 1>  get_segment_number_tensor() const;
    xt::xtensor<uint32_t, 1> get_sample_count_tensor() const;

    // ----- decoded per-beam access (computed on demand) -----
    xt::xtensor<float, 1> get_magnitude(size_t beam_index) const;
    xt::xtensor<float, 1> get_phase(size_t beam_index) const;
    xt::xtensor<float, 1> get_magnitude_in_db(size_t beam_index) const;
    xt::xtensor<float, 1> get_phase_in_degrees(size_t beam_index) const;

    std::vector<xt::xtensor<float, 1>> get_magnitudes() const;
    std::vector<xt::xtensor<float, 1>> get_phases() const;
    std::vector<xt::xtensor<float, 1>> get_magnitudes_in_db() const;

    // ----- processed -----
    size_t get_number_of_beams() const;
    size_t get_total_number_of_samples() const;

    // ----- skip / lazy reading -----
    bool    get_samples_are_skipped() const { return _skipped; }
    int64_t get_sample_position() const;
    void    set_skipped(int64_t sample_position)
    {
        _skipped         = true;
        _sample_position = sample_position;
    }
    void clear_skipped() { _skipped = false; }

    // ----- operators -----
    bool operator==(const CompressedWaterColumnBeamContainer& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<CompressedWaterColumnBeam> _beams;
    bool                                   _skipped         = false;
    int64_t                                _sample_position = -1;

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
