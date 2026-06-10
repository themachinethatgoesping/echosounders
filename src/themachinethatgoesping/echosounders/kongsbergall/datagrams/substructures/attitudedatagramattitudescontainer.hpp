// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/attitudedatagramattitudescontainer.doc.hpp"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <type_traits>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "attitudedatagramattitude.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

class AttitudeDatagramAttitudesContainer
{
  public:
    AttitudeDatagramAttitudesContainer()  = default;
    ~AttitudeDatagramAttitudesContainer() = default;

    // ----- vector access -----
    const std::vector<AttitudeDatagramAttitude>& get_attitudes() const;
    std::vector<AttitudeDatagramAttitude>&       attitudes();
    void set_attitudes(const std::vector<AttitudeDatagramAttitude>& attitudes);

    // Vector-like compatibility helpers
    std::size_t size() const { return _attitudes.size(); }
    const AttitudeDatagramAttitude& operator[](std::size_t idx) const { return _attitudes[idx]; }
    AttitudeDatagramAttitude&       operator[](std::size_t idx) { return _attitudes[idx]; }
    auto begin() { return _attitudes.begin(); }
    auto end() { return _attitudes.end(); }
    auto begin() const { return _attitudes.begin(); }
    auto end() const { return _attitudes.end(); }
    auto cbegin() const { return _attitudes.cbegin(); }
    auto cend() const { return _attitudes.cend(); }

    // ----- raw fields -----
    xt::xtensor<float, 1> get_time_tensor(const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_sensor_status_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<int16_t, 1> get_roll_tensor(const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<int16_t, 1> get_pitch_tensor(const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<int16_t, 1> get_heave_tensor(const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<uint16_t, 1> get_heading_tensor(const std::vector<uint32_t>& indices = {}) const;

    // ----- processed -----
    xt::xtensor<float, 1> get_time_in_seconds_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_roll_in_degrees_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_pitch_in_degrees_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_heave_in_meters_tensor(
        const std::vector<uint32_t>& indices = {}) const;
    xt::xtensor<float, 1> get_heading_in_degrees_tensor(
        const std::vector<uint32_t>& indices = {}) const;

    // ----- size -----
    size_t get_number_of_attitudes() const;

    // ----- operators -----
    bool operator==(const AttitudeDatagramAttitudesContainer& other) const = default;

    // ----- printer -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<AttitudeDatagramAttitude> _attitudes;

    template<typename ValueType, typename Getter>
    xt::xtensor<ValueType, 1> build_tensor(Getter&&                     getter,
                                           const std::vector<uint32_t>& indices) const
    {
        if (indices.empty())
        {
            auto tensor = xt::xtensor<ValueType, 1>::from_shape({ _attitudes.size() });
            for (std::size_t idx = 0; idx < _attitudes.size(); ++idx)
            {
                tensor.unchecked(idx) = static_cast<ValueType>(getter(_attitudes[idx]));
            }
            return tensor;
        }

        auto tensor = xt::xtensor<ValueType, 1>::from_shape({ indices.size() });
        for (std::size_t ai = 0; ai < indices.size(); ++ai)
        {
            const auto idx = indices[ai];
            if (idx >= _attitudes.size())
            {
                if constexpr (std::is_floating_point_v<ValueType>)
                    tensor.unchecked(ai) = std::numeric_limits<ValueType>::quiet_NaN();
                else
                    tensor.unchecked(ai) = ValueType{ 0 };
            }
            else
            {
                tensor.unchecked(ai) = static_cast<ValueType>(getter(_attitudes[idx]));
            }
        }

        return tensor;
    }
};

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
