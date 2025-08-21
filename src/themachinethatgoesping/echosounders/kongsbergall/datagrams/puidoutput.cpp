// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "puidoutput.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

: PUIDOutput::KongsbergAllDatagram(std::move(header))
    {
    }
PUIDOutput::PUIDOutput()
{
    _datagram_identifier = t_KongsbergAllDatagramIdentifier::PUIDOutput;;
}
uint16_t    PUIDOutput::get_system_serial_number() const
{
    return _system_serial_number;;
}
std::string PUIDOutput::get_pu_software_version() const
    {
        return std::string(std::begin(_pu_software_version), std::end(_pu_software_version));
    }
std::string PUIDOutput::get_bsp_software_date() const
    {
        return std::string(std::begin(_bsp_software_date), std::end(_bsp_software_date));
    }
std::string PUIDOutput::get_sonar_transceiver_1_software_version() const
    {
        return std::string(std::begin(_sonar_transceiver_1_software_version),
                           std::end(_sonar_transceiver_1_software_version));
    }
std::string PUIDOutput::get_sonar_transceiver_2_software_version() const
    {
        return std::string(std::begin(_sonar_transceiver_2_software_version),
                           std::end(_sonar_transceiver_2_software_version));
    }
void PUIDOutput::set_byte_order_flag(uint16_t byte_order_flag)
{
    _byte_order_flag = byte_order_flag;;
}
void PUIDOutput::set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
void PUIDOutput::set_udp_port_no_1(uint16_t udp_port_no_1)
{
    _udp_port_no_1 = udp_port_no_1;;
}
void PUIDOutput::set_udp_port_no_2(uint16_t udp_port_no_2)
{
    _udp_port_no_2 = udp_port_no_2;;
}
void PUIDOutput::set_udp_port_no_3(uint16_t udp_port_no_3)
{
    _udp_port_no_3 = udp_port_no_3;;
}
void PUIDOutput::set_udp_port_no_4(uint16_t udp_port_no_4)
{
    _udp_port_no_4 = udp_port_no_4;;
}
void PUIDOutput::set_system_descriptor(uint32_t system_descriptor)
    {
        _system_descriptor = system_descriptor;
    }
void PUIDOutput::set_pu_software_version(const std::string& pu_software_version)
    {
        if (pu_software_version.size() != 16)
            throw std::invalid_argument(fmt::format(
                "pu_software_version must be 16 characters long, but is {} characters long",
                pu_software_version.size()));

        std::copy(
            pu_software_version.begin(), pu_software_version.end(), _pu_software_version.begin());
    }
void PUIDOutput::set_bsp_software_date(const std::string& bsp_software_date)
    {
        if (bsp_software_date.size() != 16)
            throw std::invalid_argument(fmt::format(
                "bsp_software_date must be 16 characters long, but is {} characters long",
                bsp_software_date.size()));

        std::copy(bsp_software_date.begin(), bsp_software_date.end(), _bsp_software_date.begin());
    }
void PUIDOutput::set_host_ip_address(std::array<uint8_t, 4> host_ip_address)
    {
        _host_ip_address = host_ip_address;
    }
void PUIDOutput::set_tx_opening_angle(uint8_t tx_opening_angle)
{
    _tx_opening_angle = tx_opening_angle;;
}
void PUIDOutput::set_rx_opening_angle(uint8_t rx_opening_angle)
{
    _rx_opening_angle = rx_opening_angle;;
}
void PUIDOutput::set_spare(const std::array<uint8_t, 7>& spare)
{
    _spare = spare;;
}
void PUIDOutput::set_checksum(uint16_t checksum)
{
    _checksum = checksum;;
}
std::string PUIDOutput::get_host_ip_address_as_string() const
    {
        // create the ip address by splitting the 32 bit integer in 4 bytes
        std::string ip_address =
            std::to_string(_host_ip_address[0]) + "." + std::to_string(_host_ip_address[1]) + "." +
            std::to_string(_host_ip_address[2]) + "." + std::to_string(_host_ip_address[3]);
        return ip_address;
    }
std::string PUIDOutput::get_cpu_configuration() const
    {

        uint8_t cpu_configuration_flag = (_system_descriptor & 0xFF000000) >> 24;

        switch (cpu_configuration_flag)
        {
            case 0:
                return "Old CPU card";
            case 1:
                return "VIPer or CoolMonster";
            case 2:
                return "CT7";
            case 3:
                return "Kontron";
            case 4:
                return "Kontron and BSP67B for EM 710";
            case 5:
                return "Concurrent Technologies PP432";
            case 6:
                return "EM2000 AUV";
            case 7:
                return "Concurrent Technologies PP 833";
            default:
                return "Unknown";
        }
    }
bool PUIDOutput::get_has_dual_head() const
{
    return (_system_descriptor & 0b1);;
}
bool PUIDOutput::get_has_dual_swath() const
{
    return (_system_descriptor & 0b10);;
}
bool PUIDOutput::get_has_bsp67B() const
{
    return !(_system_descriptor & 0b100);;
}
bool PUIDOutput::get_has_cbmf() const
{
    return (_system_descriptor & 0b100);;
}
bool PUIDOutput::get_has_ptp_support() const
{
    return (_system_descriptor & 0b1000);;
}
bool PUIDOutput::get_has_deep_water_sonar_head() const
{
    return !(_system_descriptor & 0b10000);;
}
bool PUIDOutput::get_has_shallow_water_sonar_head() const
{
    return (_system_descriptor & 0b10000);;
}
bool PUIDOutput::get_has_extra_detections_support() const
{
    return (_system_descriptor & 0b100000);;
}
bool PUIDOutput::get_has_rs422_support() const
{
    return (_system_descriptor & 0b1000000);;
}
std::string PUIDOutput::get_which_em2040() const
    {
        uint8_t em2040_flag = (_system_descriptor & 0b110000000) >> 7;

        switch (em2040_flag)
        {
            case 0:
                return "EM 2040 Normal";
            case 1:
                return "EM 2040 Dual TX (2*TX and 2*RX)";
            case 2:
                return "spare";
            case 3:
                return "EM 2040P";
            default:
                return "This can't happen :-)";
        }
    }
std::string PUIDOutput::get_which_em710() const
    {
        uint8_t em710_flag = (_system_descriptor & 0b0000011000000000) >> 9;

        switch (em710_flag)
        {
            case 0:
                return "EM 710";
            case 1:
                return "EM 710–MK2";
            default:
                return "Unknown";
        }
    }
std::string PUIDOutput::get_which_old_sounder() const
    {
        if ((_system_descriptor & 0x00000F00) > 0)
        {
            return "EM 3002 Rx gain not available";
        }

        uint8_t old_sounder_flag = (_system_descriptor & 0x000000FF);

        switch (old_sounder_flag)
        {
            case 1:
                return "EM 1002S";
            case 2:
                return "EM 952";
            case 3:
                return "EM 1002: with Hull Unit";
            case 4:
                return " EM 1002S: with Hull Unit";
            case 5:
                return "EM 952: with Hull Unit";
            case 8:
                return "EM 3001";
            case 9:
                return "EM 3002 long pulse available";
            default:
                return "Unknown";
        }
    }
static PUIDOutput PUIDOutput::from_stream(std::istream& is, KongsbergAllDatagram header)
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
            throw std::runtime_error(
                fmt::format("PUIDOutput: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }
static PUIDOutput PUIDOutput::from_stream(std::istream& is)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is));
    }
static PUIDOutput PUIDOutput::from_stream(std::istream& is, t_KongsbergAllDatagramIdentifier datagram_identifier)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
    }
void PUIDOutput::to_stream(std::ostream& os)
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
