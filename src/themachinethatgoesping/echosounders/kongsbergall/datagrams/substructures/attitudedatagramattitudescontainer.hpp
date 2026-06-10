// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/attitudedatagramattitudescontainer.doc.hpp"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cmath>
#include <limits>
#include <numeric>
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

    // Build a reusable permutation once, then pass it into tensor getters.
    // This avoids repeated sort work when fetching many fields in time order.
    std::vector<uint32_t> get_indices_sorted_by_time(
        const std::vector<uint32_t>& indices = {}) const
    {
        std::vector<uint32_t> sorted_indices;
        if (indices.empty())
        {
            sorted_indices.resize(_attitudes.size());
            std::iota(sorted_indices.begin(), sorted_indices.end(), uint32_t{ 0 });
        }
        else
        {
            sorted_indices = indices;
        }

        std::stable_sort(sorted_indices.begin(),
                         sorted_indices.end(),
                         [this](uint32_t a, uint32_t b) {
                             const bool valid_a = a < _attitudes.size();
                             const bool valid_b = b < _attitudes.size();

                             if (!valid_a || !valid_b)
                             {
                                 if (!valid_a && !valid_b)
                                     return a < b;
                                 return valid_a;
                             }

                             const float ta = _attitudes[a].get_time();
                             const float tb = _attitudes[b].get_time();
                             const bool  fa = std::isfinite(ta);
                             const bool  fb = std::isfinite(tb);

                             if (fa != fb)
                                 return fa;
                             if (!fa && !fb)
                                 return a < b;

                             return ta < tb;
                         });

        return sorted_indices;
    }

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
