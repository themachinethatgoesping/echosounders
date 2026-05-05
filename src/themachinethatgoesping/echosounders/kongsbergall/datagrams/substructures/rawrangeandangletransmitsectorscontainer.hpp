// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/rawrangeandangletransmitsectorscontainer.doc.hpp"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/algorithms/signalprocessing/types.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "rawrangeandangletransmitsector.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

/**
 * @brief Container that stores a vector of RawRangeAndAngleTransmitSector and
 *        exposes per-field vectorised (xtensor) accessors for fast bulk access
 *        from Python and C++.
 */
class RawRangeAndAngleTransmitSectorsContainer
{
  public:
    RawRangeAndAngleTransmitSectorsContainer()  = default;
    ~RawRangeAndAngleTransmitSectorsContainer() = default;

    // ----- vector access -----
    const std::vector<RawRangeAndAngleTransmitSector>& get_transmit_sectors() const;
    std::vector<RawRangeAndAngleTransmitSector>&       transmit_sectors();
    void set_transmit_sectors(const std::vector<RawRangeAndAngleTransmitSector>& sectors);

    // ----- raw fields -----
    xt::xtensor<int16_t, 1> get_tilt_angle_tensor(
        const std::vector<uint32_t>& sector_numbers = {}) const;
    xt::xtensor<uint16_t, 1> get_focus_range_tensor(
        const std::vector<uint32_t>& sector_numbers = {}) const;
    xt::xtensor<float, 1> get_signal_length_tensor(
        const std::vector<uint32_t>& sector_numbers = {}) const;
    xt::xtensor<float, 1> get_sector_transmit_delay_tensor(
        const std::vector<uint32_t>& sector_numbers = {}) const;
    xt::xtensor<float, 1> get_center_frequency_tensor(
        const std::vector<uint32_t>& sector_numbers = {}) const;
    xt::xtensor<uint16_t, 1> get_mean_absorption_coefficient_tensor(
        const std::vector<uint32_t>& sector_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_signal_waveform_identifier_tensor(
        const std::vector<uint32_t>& sector_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_transmit_sector_number_tensor(
        const std::vector<uint32_t>& sector_numbers = {}) const;
    xt::xtensor<float, 1> get_signal_bandwidth_tensor(
        const std::vector<uint32_t>& sector_numbers = {}) const;

    // ----- processed / converted -----
    xt::xtensor<float, 1> get_tilt_angle_in_degrees_tensor(
        const std::vector<uint32_t>& sector_numbers = {}) const;
    xt::xtensor<float, 1> get_focus_range_in_m_tensor(
        const std::vector<uint32_t>& sector_numbers = {}) const;
    xt::xtensor<float, 1> get_mean_absorption_coefficient_in_dB_per_m_tensor(
        const std::vector<uint32_t>& sector_numbers = {}) const;
    xt::xtensor<uint8_t, 1> get_tx_signal_type_tensor(
        const std::vector<uint32_t>& sector_numbers = {}) const;

    // ----- size -----
    size_t get_number_of_transmit_sectors() const;

    // ----- operators -----
    bool operator==(const RawRangeAndAngleTransmitSectorsContainer& other) const = default;

    // ----- printer -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<RawRangeAndAngleTransmitSector> _transmit_sectors;

    template<typename ValueType, typename Getter>
    xt::xtensor<ValueType, 1> build_tensor(Getter&&                     getter,
                                           const std::vector<uint32_t>& sector_numbers) const
    {
        if (sector_numbers.empty())
        {
            auto tensor = xt::xtensor<ValueType, 1>::from_shape({ _transmit_sectors.size() });
            for (std::size_t idx = 0; idx < _transmit_sectors.size(); ++idx)
            {
                tensor.unchecked(idx) = static_cast<ValueType>(getter(_transmit_sectors[idx]));
            }
            return tensor;
        }
        else
        {
            auto tensor = xt::xtensor<ValueType, 1>::from_shape({ sector_numbers.size() });
            for (std::size_t bi = 0; bi < sector_numbers.size(); ++bi)
            {
                auto sn = sector_numbers[bi];
                if (sn >= _transmit_sectors.size())
                {
                    if constexpr (std::is_floating_point_v<ValueType>)
                        tensor.unchecked(bi) = std::numeric_limits<ValueType>::quiet_NaN();
                    else
                        tensor.unchecked(bi) = ValueType{ 0 };
                }
                else
                {
                    tensor.unchecked(bi) = static_cast<ValueType>(getter(_transmit_sectors[sn]));
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
