// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/rawdetectionbeamcontainer.doc.hpp"

// std includes
#include <cstddef>
#include <cstdint>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "rawdetectionbeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Container for the per-beam raw detections (7027 RawDetectionData).
 *
 * The beam records are stored as one contiguous block and read as a single bulk read. Per-field
 * numpy arrays (tensors) are built on demand.
 */
class RawDetectionBeamContainer
{
  public:
    RawDetectionBeamContainer()  = default;
    ~RawDetectionBeamContainer() = default;

    // ----- raw struct access -----
    const std::vector<RawDetectionBeam>& get_beams() const;
    std::vector<RawDetectionBeam>&       beams();
    void                                 set_beams(const std::vector<RawDetectionBeam>& beams);

    // ----- per-field tensor access (built on demand) -----
    xt::xtensor<uint16_t, 1> get_beam_descriptor_tensor() const;
    xt::xtensor<float, 1>    get_detection_point_tensor() const;
    xt::xtensor<float, 1>    get_rx_angle_tensor() const;
    xt::xtensor<uint32_t, 1> get_flags_tensor() const;
    xt::xtensor<uint32_t, 1> get_quality_tensor() const;
    xt::xtensor<float, 1>    get_uncertainty_tensor() const;
    xt::xtensor<float, 1>    get_signal_strength_tensor() const;
    xt::xtensor<float, 1>    get_min_limit_tensor() const;
    xt::xtensor<float, 1>    get_max_limit_tensor() const;

    // ----- processed -----
    size_t get_number_of_beams() const;

    // ----- operators -----
    bool operator==(const RawDetectionBeamContainer& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<RawDetectionBeam> _beams;

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
