// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/snippetdatabeamcontainer.doc.hpp"

// std includes
#include <cstddef>
#include <cstdint>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "snippetdatabeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Container for the per-beam snippet descriptors (7028 SnippetData beam headers).
 *
 * The beam headers are stored as one contiguous block and read as a single bulk read. Per-field
 * numpy arrays (tensors) are built on demand.
 */
class SnippetDataBeamContainer
{
  public:
    SnippetDataBeamContainer()  = default;
    ~SnippetDataBeamContainer() = default;

    // ----- raw struct access -----
    const std::vector<SnippetDataBeam>& get_beams() const;
    std::vector<SnippetDataBeam>&       beams();
    void                                set_beams(const std::vector<SnippetDataBeam>& beams);

    // ----- per-field tensor access (built on demand) -----
    xt::xtensor<uint16_t, 1> get_beam_descriptor_tensor() const;
    xt::xtensor<uint32_t, 1> get_snippet_start_tensor() const;
    xt::xtensor<uint32_t, 1> get_detection_sample_tensor() const;
    xt::xtensor<uint32_t, 1> get_snippet_end_tensor() const;
    xt::xtensor<uint32_t, 1> get_number_of_samples_tensor() const;

    // ----- processed -----
    size_t get_number_of_beams() const;
    size_t get_total_number_of_samples() const;

    // ----- operators -----
    bool operator==(const SnippetDataBeamContainer& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<SnippetDataBeam> _beams;

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
