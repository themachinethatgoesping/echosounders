// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/rawrangeandanglebeamscontainer.doc.hpp"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "rawrangeandanglebeam.hpp"
#include "flag_detection_information.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

/**
 * @brief Container that stores a vector of RawRangeAndAngleBeam and exposes
 *        per-field vectorised (xtensor) accessors for fast bulk access from
 *        Python and C++.
 */
class RawRangeAndAngleBeamsContainer
{
  public:
    RawRangeAndAngleBeamsContainer()  = default;
    ~RawRangeAndAngleBeamsContainer() = default;

    // ----- vector access -----
    const std::vector<RawRangeAndAngleBeam>& get_beams() const;
    std::vector<RawRangeAndAngleBeam>&       beams();
    void set_beams(const std::vector<RawRangeAndAngleBeam>& beams);

    // ----- raw fields -----
    xt::xtensor<int16_t, 1> get_beam_crosstrack_angle_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_transmit_sector_number_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_detection_info_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint16_t, 1> get_detection_window_length_in_samples_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_quality_factor_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<int8_t, 1> get_d_corr_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<float, 1> get_two_way_travel_time_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<int16_t, 1> get_reflectivity_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<int8_t, 1> get_realtime_cleaning_info_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_spare_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;

    // ----- processed / converted -----
    xt::xtensor<float, 1> get_beam_crosstrack_angle_in_degrees_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<float, 1> get_reflectivity_in_db_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;

    // detection flag derived
    xt::xtensor<uint8_t, 1> get_detection_is_valid_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_detection_type_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_backscatter_is_compensated_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;

    // ----- size -----
    size_t get_number_of_beams() const;

    // ----- operators -----
    bool operator==(const RawRangeAndAngleBeamsContainer& other) const = default;

    // ----- printer -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<RawRangeAndAngleBeam> _beams;

    template<typename ValueType, typename Getter>
    xt::xtensor<ValueType, 1> build_tensor(Getter&&                     getter,
                                           const std::vector<uint32_t>& beam_numbers) const
    {
        if (beam_numbers.empty())
        {
            auto tensor = xt::xtensor<ValueType, 1>::from_shape({ _beams.size() });
            for (std::size_t idx = 0; idx < _beams.size(); ++idx)
            {
                tensor.unchecked(idx) = static_cast<ValueType>(getter(_beams[idx]));
            }
            return tensor;
        }
        else
        {
            auto tensor = xt::xtensor<ValueType, 1>::from_shape({ beam_numbers.size() });
            for (std::size_t bi = 0; bi < beam_numbers.size(); ++bi)
            {
                auto bn = beam_numbers[bi];
                if (bn >= _beams.size())
                {
                    if constexpr (std::is_floating_point_v<ValueType>)
                        tensor.unchecked(bi) = std::numeric_limits<ValueType>::quiet_NaN();
                    else
                        tensor.unchecked(bi) = ValueType{ 0 };
                }
                else
                {
                    tensor.unchecked(bi) = static_cast<ValueType>(getter(_beams[bn]));
                }
            }
            return tensor;
        }
    }
};

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
