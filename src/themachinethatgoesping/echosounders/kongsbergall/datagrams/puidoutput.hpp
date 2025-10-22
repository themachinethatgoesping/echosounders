// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/puidoutput.doc.hpp"

// std includes
#include <array>
#include <cstdint>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief The PU Status datagram is sent out every second if requested by the host processor. It has
 * two functions, to indicate that the system is alive and receiving sensor data, and to give sensor
 * data regularly for a potential screen update.
 */
class PUIDOutput : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KongsbergAllDatagramIdentifier::PUIDOutput;

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
    std::array<uint8_t, 4> _host_ip_address;
    uint8_t                _tx_opening_angle;
    uint8_t                _rx_opening_angle;
    std::array<uint8_t, 7> _spare;

    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit PUIDOutput(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    PUIDOutput();
    ~PUIDOutput() = default;

    // ----- convenient data access -----
    // getters
    uint16_t               get_byte_order_flag() const;
    uint16_t               get_system_serial_number() const;
    uint16_t               get_udp_port_no_1() const;
    uint16_t               get_udp_port_no_2() const;
    uint16_t               get_udp_port_no_3() const;
    uint16_t               get_udp_port_no_4() const;
    uint32_t               get_system_descriptor() const;
    std::string            get_pu_software_version() const;
    std::string            get_bsp_software_date() const;
    std::string            get_sonar_transceiver_1_software_version() const;
    std::string            get_sonar_transceiver_2_software_version() const;
    std::array<uint8_t, 4> get_host_ip_address() const;
    uint8_t                get_tx_opening_angle() const;
    uint8_t                get_rx_opening_angle() const;
    std::array<uint8_t, 7> get_spare() const;

    uint8_t  get_etx() const;
    uint16_t get_checksum() const;

    // setters
    void set_byte_order_flag(uint16_t byte_order_flag);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_udp_port_no_1(uint16_t udp_port_no_1);
    void set_udp_port_no_2(uint16_t udp_port_no_2);
    void set_udp_port_no_3(uint16_t udp_port_no_3);
    void set_udp_port_no_4(uint16_t udp_port_no_4);
    void set_system_descriptor(uint32_t system_descriptor);
    void set_pu_software_version(const std::string& pu_software_version);
    void set_bsp_software_date(const std::string& bsp_software_date);
    void set_sonar_transceiver_1_software_version(
        const std::string& sonar_transceiver_1_software_version);
    void set_sonar_transceiver_2_software_version(
        const std::string& sonar_transceiver_2_software_version);
    void set_host_ip_address(std::array<uint8_t, 4> host_ip_address);
    void set_tx_opening_angle(uint8_t tx_opening_angle);
    void set_rx_opening_angle(uint8_t rx_opening_angle);
    void set_spare(const std::array<uint8_t, 7>& spare);

    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);

    // ----- processed data access -----
    /**
     * @brief Get the host ip address as string
     *
     * @return std::string
     */
    std::string get_host_ip_address_as_string() const;

    /**
     * @brief Convert the system descriptor flag to a cpu configuration
     *
     * @return std::string
     */
    std::string get_cpu_configuration() const;

    /**
     * @brief Evaluate the system_descriptor flag to determine if the system is a dual head system
     *
     * @return true
     * @return false
     */
    bool get_has_dual_head() const;

    /**
     * @brief Evaluate the system_descriptor flag to determine if the system is a dual swath system
     *
     * @return true
     * @return false
     */
    bool get_has_dual_swath() const;

    /**
     * @brief Evaluate the system_descriptor flag to determine if the system is a BSP67B system
     *
     * This means it is not a CBMF system
     *
     * @return true
     * @return false
     */
    bool get_has_bsp67B() const;

    /**
     * @brief Evaluate the system_descriptor flag to determine if the system is a CBMF system
     *
     * This means it is not a BSP67B system
     *
     * @return true
     * @return false
     */
    bool get_has_cbmf() const;

    /**
     * @brief Evaluate the system_descriptor flag to determine if the system is a PTP (IEEE 1588
     * clock sync) support
     *
     * @return true
     * @return false
     */
    bool get_has_ptp_support() const;

    /**
     * @brief Evaluate the system_descriptor flag to determine if the system has a deep water sonar
     * head
     *
     * @return true (deep water sonar head)
     * @return false (shallow water sonar head)s
     */
    bool get_has_deep_water_sonar_head() const;

    /**
     * @brief Evaluate the system_descriptor flag to determine if the system has a shallow water
     * sonar head
     *
     * @return true (shallow water sonar head)
     * @return false (deep water sonar head)
     */
    bool get_has_shallow_water_sonar_head() const;

    /**
     * @brief Evaluate the system_descriptor flag to determine if the system has extra detections
     * support
     *
     * @return true
     * @return false
     */
    bool get_has_extra_detections_support() const;

    /**
     * @brief Evaluate the system_descriptor flag to determine if the system has RS422 serial lines
     * support
     *
     * @return true
     * @return false
     */
    bool get_has_rs422_support() const;

    /**
     * @brief Evaluate the system_descriptor flag to determine the em2040 flag
     *
     * @return true
     * @return false
     */
    std::string get_which_em2040() const;

    /**
     * @brief Evaluate the system_descriptor flag to determine the EM710 flag
     *
     * @return true
     * @return false
     */
    std::string get_which_em710() const;

    /**
     * @brief Evaluate the system_descriptor flag to determine the old sounder flag
     *
     * @return true
     * @return false
     */
    std::string get_which_old_sounder() const;

    // ----- operators -----
    bool operator==(const PUIDOutput& other) const = default;

    //----- to/from stream functions -----
    static PUIDOutput from_stream(std::istream& is, KongsbergAllDatagram header);

    static PUIDOutput from_stream(std::istream& is);

    static PUIDOutput from_stream(std::istream& is, t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(PUIDOutput)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
