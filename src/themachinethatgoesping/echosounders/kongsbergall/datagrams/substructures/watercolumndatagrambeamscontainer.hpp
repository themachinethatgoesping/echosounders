// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/watercolumndatagrambeamscontainer.doc.hpp"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "watercolumndatagrambeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

/**
 * @brief Container that stores a vector of WatercolumnDatagramBeam and exposes
 *        per-field vectorised (xtensor) accessors for fast bulk access from
 *        Python and C++. Note: per-beam sample buffers are not vectorised here
 *        because they have variable length per beam.
 */
class WatercolumnDatagramBeamsContainer
{
  public:
    WatercolumnDatagramBeamsContainer()  = default;
    ~WatercolumnDatagramBeamsContainer() = default;

    // ----- vector access -----
    const std::vector<WatercolumnDatagramBeam>& get_beams() const;
    std::vector<WatercolumnDatagramBeam>&       beams();
    void set_beams(const std::vector<WatercolumnDatagramBeam>& beams);

    // ----- raw fields -----
    xt::xtensor<int16_t, 1> get_beam_crosstrack_angle_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint16_t, 1> get_start_range_sample_number_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint16_t, 1> get_number_of_samples_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint16_t, 1> get_detected_range_in_samples_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_transmit_sector_number_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_beam_number_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;

    // ----- processed -----
    xt::xtensor<float, 1> get_beam_crosstrack_angle_in_degrees_tensor(
        const std::vector<uint32_t>& beam_numbers = {}) const;

    // ----- size -----
    size_t get_number_of_beams() const;

    // ----- operators -----
    bool operator==(const WatercolumnDatagramBeamsContainer& other) const = default;

    // ----- printer -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<WatercolumnDatagramBeam> _beams;

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
