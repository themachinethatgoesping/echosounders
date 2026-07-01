// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/xyzdatagrambeamscontainer.doc.hpp"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/algorithms/geoprocessing/datastructures/xyz.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "flag_detection_information.hpp"
#include "xyzdatagrambeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

class XYZDatagramBeamsContainer
{
  public:
    using t_XYZ = algorithms::geoprocessing::datastructures::XYZ<1>;

    XYZDatagramBeamsContainer()  = default;
    ~XYZDatagramBeamsContainer() = default;

    const std::vector<XYZDatagramBeam>& get_beams() const;
    std::vector<XYZDatagramBeam>&       beams();
    void                                set_beams(const std::vector<XYZDatagramBeam>& beams);

    xt::xtensor<float, 1> get_depth_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<float, 1> get_acrosstrack_distance_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<float, 1> get_alongtrack_distance_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint16_t, 1> get_detection_window_length_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_quality_factor_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<int8_t, 1> get_beam_incidence_angle_adjustment_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_detection_info_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<int8_t, 1> get_realtime_cleaning_information_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<int16_t, 1> get_reflectivity_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;

    xt::xtensor<double, 1> get_backscatter_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<double, 1> get_beam_incidence_angle_adjustment_in_degrees_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_detection_is_valid_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_detection_type_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_backscatter_is_compensated_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;

    size_t get_number_of_beams() const;

    t_XYZ get_xyz() const;
    t_XYZ get_xyz(const std::vector<uint32_t>& beam_numbers) const;

    bool operator==(const XYZDatagramBeamsContainer& other) const = default;

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<XYZDatagramBeam> _beams;

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

        auto tensor = xt::xtensor<ValueType, 1>::from_shape({ beam_numbers.size() });
        for (std::size_t bi = 0; bi < beam_numbers.size(); ++bi)
        {
            auto bn = beam_numbers[bi];
            if (bn >= _beams.size())
            {
                if constexpr (std::is_floating_point_v<ValueType>)
                {
                    tensor.unchecked(bi) = std::numeric_limits<ValueType>::quiet_NaN();
                }
                else
                {
                    tensor.unchecked(bi) = ValueType{ 0 };
                }
            }
            else
            {
                tensor.unchecked(bi) = static_cast<ValueType>(getter(_beams[bn]));
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