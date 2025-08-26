// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "puidoutput.hpp"

#include <fmt/core.h>
#include <stdexcept>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

PUIDOutput PUIDOutput::from_stream(std::istream& is, KongsbergAllDatagram header)
{
    PUIDOutput datagram(std::move(header));

    if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::PUIDOutput)
        throw std::runtime_error(
            fmt::format("PUIDOutput: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                        uint8_t(t_KongsbergAllDatagramIdentifier::PUIDOutput),
                        uint8_t(datagram._datagram_identifier)));

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(datagram._byte_order_flag)), 96 * sizeof(uint8_t));

    if (datagram._etx != 0x03)
        throw std::runtime_error(fmt::format(
            "PUIDOutput: end identifier is not 0x03, but 0x{:x}", datagram._etx));

    return datagram;
}

PUIDOutput PUIDOutput::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

PUIDOutput PUIDOutput::from_stream(std::istream& is, t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void PUIDOutput::to_stream(std::ostream& os) const
{
    KongsbergAllDatagram::to_stream(os);

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_byte_order_flag)), 96 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter PUIDOutput::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("PUIDOutput", float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("byte_order_flag", _byte_order_flag);
    printer.register_value("system_serial_number", _system_serial_number);
    printer.register_value("udp_port_no_1", _udp_port_no_1);
    printer.register_value("udp_port_no_2", _udp_port_no_2);
    printer.register_value("udp_port_no_3", _udp_port_no_3);
    printer.register_value("udp_port_no_4", _udp_port_no_4);
    printer.register_string("system_descriptor", fmt::format("0x{:08x}", _system_descriptor));
    printer.register_string("pu_software_version", get_pu_software_version());
    printer.register_string("bsp_software_date", get_bsp_software_date());
    printer.register_string("sonar_transceiver_1_software_version",
                            get_sonar_transceiver_1_software_version());
    printer.register_string("sonar_transceiver_2_software_version",
                            get_sonar_transceiver_2_software_version());

    printer.register_container("host_ip_address", _host_ip_address);
    printer.register_value("tx_opening_angle", _tx_opening_angle);
    printer.register_value("rx_opening_angle", _rx_opening_angle);
    printer.register_container("spare", _spare);

    printer.register_string("etx", fmt::format("0x{:02x}", _etx));
    printer.register_value("checksum", _checksum);

    printer.register_section("processed");
    printer.register_string("host_ip_address", get_host_ip_address_as_string());
    printer.register_string("cpu_configuration", get_cpu_configuration());
    printer.register_value("has_dual_head", get_has_dual_head());
    printer.register_value("has_dual_swath", get_has_dual_swath());
    printer.register_value("has_bsp67B", get_has_bsp67B());
    printer.register_value("has_cbmf", get_has_cbmf());
    printer.register_value("has_ptp_support", get_has_ptp_support());
    printer.register_value("has_deep_water_sonar_head", get_has_deep_water_sonar_head());
    printer.register_value("has_shallow_water_sonar_head", get_has_shallow_water_sonar_head());
    printer.register_value("has_extra_detections_support", get_has_extra_detections_support());
    printer.register_value("has_rs422_support", get_has_rs422_support());
    printer.register_string("get_which_em2040", get_which_em2040());
    printer.register_string("get_which_em710", get_which_em710());
    printer.register_string("get_which_old_sounder", get_which_old_sounder());

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping