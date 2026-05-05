// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "rawrangeandangletransmitsectorscontainer.hpp"

#include <fmt/core.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

const std::vector<RawRangeAndAngleTransmitSector>&
RawRangeAndAngleTransmitSectorsContainer::get_transmit_sectors() const
{
    return _transmit_sectors;
}

std::vector<RawRangeAndAngleTransmitSector>&
RawRangeAndAngleTransmitSectorsContainer::transmit_sectors()
{
    return _transmit_sectors;
}

void RawRangeAndAngleTransmitSectorsContainer::set_transmit_sectors(
    const std::vector<RawRangeAndAngleTransmitSector>& sectors)
{
    _transmit_sectors = sectors;
}

xt::xtensor<int16_t, 1> RawRangeAndAngleTransmitSectorsContainer::get_tilt_angle_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<int16_t>(
        [](const RawRangeAndAngleTransmitSector& s) { return s.get_tilt_angle(); },
        sector_numbers);
}

xt::xtensor<uint16_t, 1> RawRangeAndAngleTransmitSectorsContainer::get_focus_range_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<uint16_t>(
        [](const RawRangeAndAngleTransmitSector& s) { return s.get_focus_range(); },
        sector_numbers);
}

xt::xtensor<float, 1> RawRangeAndAngleTransmitSectorsContainer::get_signal_length_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<float>(
        [](const RawRangeAndAngleTransmitSector& s) { return s.get_signal_length(); },
        sector_numbers);
}

xt::xtensor<float, 1> RawRangeAndAngleTransmitSectorsContainer::get_sector_transmit_delay_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<float>(
        [](const RawRangeAndAngleTransmitSector& s) { return s.get_sector_transmit_delay(); },
        sector_numbers);
}

xt::xtensor<float, 1> RawRangeAndAngleTransmitSectorsContainer::get_center_frequency_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<float>(
        [](const RawRangeAndAngleTransmitSector& s) { return s.get_center_frequency(); },
        sector_numbers);
}

xt::xtensor<uint16_t, 1>
RawRangeAndAngleTransmitSectorsContainer::get_mean_absorption_coefficient_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<uint16_t>(
        [](const RawRangeAndAngleTransmitSector& s) {
            return s.get_mean_absorption_coefficient();
        },
        sector_numbers);
}

xt::xtensor<uint8_t, 1>
RawRangeAndAngleTransmitSectorsContainer::get_signal_waveform_identifier_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<uint8_t>(
        [](const RawRangeAndAngleTransmitSector& s) {
            return s.get_signal_waveform_identifier();
        },
        sector_numbers);
}

xt::xtensor<uint8_t, 1>
RawRangeAndAngleTransmitSectorsContainer::get_transmit_sector_number_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<uint8_t>(
        [](const RawRangeAndAngleTransmitSector& s) { return s.get_transmit_sector_number(); },
        sector_numbers);
}

xt::xtensor<float, 1> RawRangeAndAngleTransmitSectorsContainer::get_signal_bandwidth_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<float>(
        [](const RawRangeAndAngleTransmitSector& s) { return s.get_signal_bandwidth(); },
        sector_numbers);
}

xt::xtensor<float, 1> RawRangeAndAngleTransmitSectorsContainer::get_tilt_angle_in_degrees_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<float>(
        [](const RawRangeAndAngleTransmitSector& s) { return s.get_tilt_angle_in_degrees(); },
        sector_numbers);
}

xt::xtensor<float, 1> RawRangeAndAngleTransmitSectorsContainer::get_focus_range_in_m_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<float>(
        [](const RawRangeAndAngleTransmitSector& s) { return s.get_focus_range_in_m(); },
        sector_numbers);
}

xt::xtensor<float, 1>
RawRangeAndAngleTransmitSectorsContainer::get_mean_absorption_coefficient_in_dB_per_m_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<float>(
        [](const RawRangeAndAngleTransmitSector& s) {
            return s.get_mean_absorption_coefficient_in_dB_per_m();
        },
        sector_numbers);
}

xt::xtensor<uint8_t, 1> RawRangeAndAngleTransmitSectorsContainer::get_tx_signal_type_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<uint8_t>(
        [](const RawRangeAndAngleTransmitSector& s) {
            return static_cast<uint8_t>(s.get_tx_signal_type());
        },
        sector_numbers);
}

size_t RawRangeAndAngleTransmitSectorsContainer::get_number_of_transmit_sectors() const
{
    return _transmit_sectors.size();
}

tools::classhelper::ObjectPrinter RawRangeAndAngleTransmitSectorsContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "RawRangeAndAngleTransmitSectorsContainer", float_precision, superscript_exponents);

    printer.register_section("TransmitSectors (.transmit_sectors)");
    printer.register_value("transmit_sectors (vector)",
                           fmt::format("size={}", get_number_of_transmit_sectors()),
                           "sectors");

    printer.register_container("tilt_angle", get_tilt_angle_tensor());
    printer.register_container("focus_range", get_focus_range_tensor());
    printer.register_container("signal_length", get_signal_length_tensor(), "s");
    printer.register_container("sector_transmit_delay", get_sector_transmit_delay_tensor(), "s");
    printer.register_container("center_frequency", get_center_frequency_tensor(), "Hz");
    printer.register_container("mean_absorption_coefficient",
                               get_mean_absorption_coefficient_tensor());
    printer.register_container("signal_waveform_identifier",
                               get_signal_waveform_identifier_tensor());
    printer.register_container("transmit_sector_number", get_transmit_sector_number_tensor());
    printer.register_container("signal_bandwidth", get_signal_bandwidth_tensor(), "Hz");

    printer.register_section("processed");
    printer.register_value("number_of_transmit_sectors", get_number_of_transmit_sectors());
    printer.register_container(
        "tilt_angle_in_degrees", get_tilt_angle_in_degrees_tensor(), "deg");
    printer.register_container("focus_range_in_m", get_focus_range_in_m_tensor(), "m");
    printer.register_container("mean_absorption_coefficient_in_dB_per_m",
                               get_mean_absorption_coefficient_in_dB_per_m_tensor(),
                               "dB/m");
    printer.register_container("tx_signal_type", get_tx_signal_type_tensor());

    return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
