// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/attitudesamplecontainer.doc.hpp"

// std includes
#include <cstddef>
#include <cstdint>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "attitudesample.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Container for the attitude samples of a 1016 Attitude record.
 *
 * The samples are stored as one contiguous block and read as a single bulk read. Per-field numpy
 * arrays (tensors) are built on demand.
 */
class AttitudeSampleContainer
{
  public:
    AttitudeSampleContainer()  = default;
    ~AttitudeSampleContainer() = default;

    // ----- raw struct access -----
    const std::vector<AttitudeSample>& get_samples() const;
    std::vector<AttitudeSample>&       samples();
    void                               set_samples(const std::vector<AttitudeSample>& samples);

    // ----- per-field tensor access (built on demand) -----
    xt::xtensor<uint16_t, 1> get_delta_time_tensor() const;
    xt::xtensor<float, 1>    get_roll_tensor() const;
    xt::xtensor<float, 1>    get_pitch_tensor() const;
    xt::xtensor<float, 1>    get_heave_tensor() const;
    xt::xtensor<float, 1>    get_heading_tensor() const;

    // ----- processed -----
    size_t get_number_of_samples() const;

    // ----- operators -----
    bool operator==(const AttitudeSampleContainer& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<AttitudeSample> _samples;

    template<typename ValueType, typename Getter>
    xt::xtensor<ValueType, 1> build_tensor(Getter&& getter) const
    {
        auto tensor = xt::xtensor<ValueType, 1>::from_shape({ _samples.size() });
        for (std::size_t idx = 0; idx < _samples.size(); ++idx)
            tensor.unchecked(idx) = static_cast<ValueType>(getter(_samples[idx]));
        return tensor;
    }
};

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
