// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/puidoutput.doc.hpp"

// std includes
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../em3000_types.hpp"
#include "em3000datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {

/**
 * @brief The PU Status datagram is sent out every second if requested by the host processor. It has
 * two functions, to indicate that the system is alive and receiving sensor data, and to give sensor
 * data regularly for a potential screen update.
 */
class PUIDOutput : public EM3000Datagram
{
  protected:
    uint16_t               _byte_order_flag;
    uint16_t               _system_serial_number;
    uint16_t               _udp_port_no_1;
    uint16_t               _udp_port_no_2;
    uint16_t               _udp_port_no_3;
    uint16_t               _udp_port_no_4;
    uint32_t               _system_descriptor;
    std::array<char, 16>   _pu_software_version;
    std::array<char, 16>   _bsp_software_date;
    std::array<char, 16>   _sonar_transceiver_1_software_version;
    std::array<char, 16>   _sonar_transceiver_2_software_version;
    uint32_t               _host_ip_address;
    uint8_t                _tx_opening_angle;
    uint8_t                _rx_opening_angle;
    std::array<uint8_t, 7> _spare;

    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit PUIDOutput(EM3000Datagram header)
        : EM3000Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    PUIDOutput() { _datagram_identifier = t_EM3000DatagramIdentifier::PUIDOutput; }
    ~PUIDOutput() = default;

    // ----- convenient data access -----
    // getters
    uint16_t    get_byte_order_flag() const { return _byte_order_flag; }
    uint16_t    get_system_serial_number() const { return _system_serial_number; }
    uint16_t    get_udp_port_no_1() const { return _udp_port_no_1; }
    uint16_t    get_udp_port_no_2() const { return _udp_port_no_2; }
    uint16_t    get_udp_port_no_3() const { return _udp_port_no_3; }
    uint16_t    get_udp_port_no_4() const { return _udp_port_no_4; }
    uint32_t    get_system_descriptor() const { return _system_descriptor; }
    std::string get_pu_software_version() const
    {
        return std::string(std::begin(_pu_software_version), std::end(_pu_software_version));
    }
    std::string get_bsp_software_date() const
    {
        return std::string(std::begin(_bsp_software_date), std::end(_bsp_software_date));
    }
    std::string get_sonar_transceiver_1_software_version() const
    {
        return std::string(std::begin(_sonar_transceiver_1_software_version),
                           std::end(_sonar_transceiver_1_software_version));
    }
    std::string get_sonar_transceiver_2_software_version() const
    {
        return std::string(std::begin(_sonar_transceiver_2_software_version),
                           std::end(_sonar_transceiver_2_software_version));
    }
    uint32_t               get_host_ip_address() const { return _host_ip_address; }
    uint8_t                get_tx_opening_angle() const { return _tx_opening_angle; }
    uint8_t                get_rx_opening_angle() const { return _rx_opening_angle; }
    std::array<uint8_t, 7> get_spare() const { return _spare; }

    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    // setters
    void set_byte_order_flag(uint16_t byte_order_flag) { _byte_order_flag = byte_order_flag; }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_udp_port_no_1(uint16_t udp_port_no_1) { _udp_port_no_1 = udp_port_no_1; }
    void set_udp_port_no_2(uint16_t udp_port_no_2) { _udp_port_no_2 = udp_port_no_2; }
    void set_udp_port_no_3(uint16_t udp_port_no_3) { _udp_port_no_3 = udp_port_no_3; }
    void set_udp_port_no_4(uint16_t udp_port_no_4) { _udp_port_no_4 = udp_port_no_4; }
    void set_system_descriptor(uint32_t system_descriptor)
    {
        _system_descriptor = system_descriptor;
    }
    void set_pu_software_version(const std::string& pu_software_version)
    {
        if (pu_software_version.size() != 16)
            throw std::invalid_argument(fmt::format(
                "pu_software_version must be 16 characters long, but is {} characters long",
                pu_software_version.size()));

        std::copy(
            pu_software_version.begin(), pu_software_version.end(), _pu_software_version.begin());
    }
    void set_bsp_software_date(const std::string& bsp_software_date)
    {
        if (bsp_software_date.size() != 16)
            throw std::invalid_argument(fmt::format(
                "bsp_software_date must be 16 characters long, but is {} characters long",
                bsp_software_date.size()));

        std::copy(bsp_software_date.begin(), bsp_software_date.end(), _bsp_software_date.begin());
    }
    void set_sonar_transceiver_1_software_version(
        const std::string& sonar_transceiver_1_software_version)
    {
        if (sonar_transceiver_1_software_version.size() != 16)
            throw std::invalid_argument(fmt::format(
                "sonar_transceiver_1_software_version must be 16 characters long, but is {} "
                "characters long",
                sonar_transceiver_1_software_version.size()));

        std::copy(sonar_transceiver_1_software_version.begin(),
                  sonar_transceiver_1_software_version.end(),
                  _sonar_transceiver_1_software_version.begin());
    }
    void set_sonar_transceiver_2_software_version(
        const std::string& sonar_transceiver_2_software_version)
    {
        if (sonar_transceiver_2_software_version.size() != 16)
            throw std::invalid_argument(fmt::format(
                "sonar_transceiver_2_software_version must be 16 characters long, but is {} "
                "characters long",
                sonar_transceiver_2_software_version.size()));

        std::copy(sonar_transceiver_2_software_version.begin(),
                  sonar_transceiver_2_software_version.end(),
                  _sonar_transceiver_2_software_version.begin());
    }
    void set_host_ip_address(uint32_t host_ip_address) { _host_ip_address = host_ip_address; }
    void set_tx_opening_angle(uint8_t tx_opening_angle) { _tx_opening_angle = tx_opening_angle; }
    void set_rx_opening_angle(uint8_t rx_opening_angle) { _rx_opening_angle = rx_opening_angle; }
    void set_spare(const std::array<uint8_t, 7>& spare) { _spare = spare; }

    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // ----- processed data access -----

    // ----- operators -----
    bool operator==(const PUIDOutput& other) const
    {
        return EM3000Datagram::operator==(other) && _byte_order_flag == other._byte_order_flag &&
               _system_serial_number == other._system_serial_number &&
               _udp_port_no_1 == other._udp_port_no_1 && _udp_port_no_2 == other._udp_port_no_2 &&
               _udp_port_no_3 == other._udp_port_no_3 && _udp_port_no_4 == other._udp_port_no_4 &&
               _system_descriptor == other._system_descriptor &&
               _pu_software_version == other._pu_software_version &&
               _bsp_software_date == other._bsp_software_date &&
               _sonar_transceiver_1_software_version ==
                   other._sonar_transceiver_1_software_version &&
               _sonar_transceiver_2_software_version ==
                   other._sonar_transceiver_2_software_version &&
               _host_ip_address == other._host_ip_address &&
               _tx_opening_angle == other._tx_opening_angle &&
               _rx_opening_angle == other._rx_opening_angle && _spare == other._spare &&
               _etx == other._etx && _checksum == other._checksum;
    }
    bool operator!=(const PUIDOutput& other) const { return !operator==(other); }

    //----- to/from stream functions -----
    static PUIDOutput from_stream(std::istream& is, EM3000Datagram header)
    {
        PUIDOutput datagram(std::move(header));

        if (datagram._datagram_identifier != t_EM3000DatagramIdentifier::PUIDOutput)
            throw std::runtime_error(
                fmt::format("PUIDOutput: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                            uint8_t(t_EM3000DatagramIdentifier::PUIDOutput),
                            uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._byte_order_flag)), 96 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(
                fmt::format("PUIDOutput: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static PUIDOutput from_stream(std::istream& is)
    {
        return from_stream(is, EM3000Datagram::from_stream(is));
    }

    static PUIDOutput from_stream(std::istream& is, t_EM3000DatagramIdentifier datagram_identifier)
    {
        return from_stream(is, std::move(EM3000Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os)
    {
        EM3000Datagram::to_stream(os);

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_byte_order_flag)), 96 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("PUIDOutput", float_precision);

        printer.append(EM3000Datagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("byte_order_flag", _byte_order_flag);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("udp_port_no_1", _udp_port_no_1);
        printer.register_value("udp_port_no_2", _udp_port_no_2);
        printer.register_value("udp_port_no_3", _udp_port_no_3);
        printer.register_value("udp_port_no_4", _udp_port_no_4);
        printer.register_string("pu_software_version", get_pu_software_version());
        printer.register_string("bsp_software_date", get_bsp_software_date());
        printer.register_string("sonar_transceiver_1_software_version",
                                get_sonar_transceiver_1_software_version());
        printer.register_string("sonar_transceiver_2_software_version",
                                get_sonar_transceiver_2_software_version());

        printer.register_value("host_ip_address", _host_ip_address);
        printer.register_value("tx_opening_angle", _tx_opening_angle);
        printer.register_value("rx_opening_angle", _rx_opening_angle);
        printer.register_container("spare", _spare);

        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        // printer.register_section("processed");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(PUIDOutput)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
