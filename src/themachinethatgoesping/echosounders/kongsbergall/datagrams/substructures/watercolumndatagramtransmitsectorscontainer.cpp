// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "watercolumndatagramtransmitsectorscontainer.hpp"

#include <fmt/core.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

const std::vector<WatercolumnDatagramTransmitSector>&
WatercolumnDatagramTransmitSectorsContainer::get_transmit_sectors() const
{
    return _transmit_sectors;
}

std::vector<WatercolumnDatagramTransmitSector>&
WatercolumnDatagramTransmitSectorsContainer::transmit_sectors()
{
    return _transmit_sectors;
}

void WatercolumnDatagramTransmitSectorsContainer::set_transmit_sectors(
    const std::vector<WatercolumnDatagramTransmitSector>& sectors)
{
    _transmit_sectors = sectors;
}

xt::xtensor<int16_t, 1>
WatercolumnDatagramTransmitSectorsContainer::get_tilt_angle_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<int16_t>(
        [](const WatercolumnDatagramTransmitSector& s) { return s.get_tilt_angle(); },
        sector_numbers);
}

xt::xtensor<uint16_t, 1>
WatercolumnDatagramTransmitSectorsContainer::get_center_frequency_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<uint16_t>(
        [](const WatercolumnDatagramTransmitSector& s) { return s.get_center_frequency(); },
        sector_numbers);
}

xt::xtensor<uint8_t, 1>
WatercolumnDatagramTransmitSectorsContainer::get_transmit_sector_number_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<uint8_t>(
        [](const WatercolumnDatagramTransmitSector& s) { return s.get_transmit_sector_number(); },
        sector_numbers);
}

xt::xtensor<uint8_t, 1> WatercolumnDatagramTransmitSectorsContainer::get_spare_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<uint8_t>(
        [](const WatercolumnDatagramTransmitSector& s) { return s.get_spare(); }, sector_numbers);
}

xt::xtensor<float, 1>
WatercolumnDatagramTransmitSectorsContainer::get_tilt_angle_in_degrees_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<float>(
        [](const WatercolumnDatagramTransmitSector& s) { return s.get_tilt_angle_in_degrees(); },
        sector_numbers);
}

xt::xtensor<float, 1>
WatercolumnDatagramTransmitSectorsContainer::get_center_frequency_in_hz_tensor(
    const std::vector<uint32_t>& sector_numbers) const
{
    return build_tensor<float>(
        [](const WatercolumnDatagramTransmitSector& s) { return s.get_center_frequency_in_hz(); },
        sector_numbers);
}

size_t WatercolumnDatagramTransmitSectorsContainer::get_number_of_transmit_sectors() const
{
    return _transmit_sectors.size();
}

tools::classhelper::ObjectPrinter WatercolumnDatagramTransmitSectorsContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "WatercolumnDatagramTransmitSectorsContainer", float_precision, superscript_exponents);

    printer.register_section("TransmitSectors (.transmit_sectors)");
    printer.register_value("transmit_sectors (vector)",
                           fmt::format("size={}", get_number_of_transmit_sectors()),
                           "sectors");

    printer.register_container("tilt_angle", get_tilt_angle_tensor());
    printer.register_container("center_frequency", get_center_frequency_tensor());
    printer.register_container("transmit_sector_number", get_transmit_sector_number_tensor());
    printer.register_container("spare", get_spare_tensor());

    printer.register_section("processed");
    printer.register_value("number_of_transmit_sectors", get_number_of_transmit_sectors());
    printer.register_container(
        "tilt_angle_in_degrees", get_tilt_angle_in_degrees_tensor(), "deg");
    printer.register_container(
        "center_frequency_in_hz", get_center_frequency_in_hz_tensor(), "Hz");

    return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
