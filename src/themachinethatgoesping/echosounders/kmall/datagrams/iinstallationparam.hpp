// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/iinstallationparam.doc.hpp"

// std includes
#include <cstdint>
#include <map>
#include <string>
#include <string_view>

// themachinethatgoesping import
#include <themachinethatgoesping/navigation/datastructures/positionaloffsets.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "kmalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

/**
 * @brief Clock datagrams
 */
class IInstallationParam : public KMALLDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KMALLDatagramIdentifier::I_INSTALLATION_PARAM;

  protected:
    uint16_t    _bytes_content;        ///<  bytes of the datagram body
    uint16_t    _info;                 ///< Information. For future use.
    uint16_t    _status;               ///< Status. For future use.
    std::string _install_txt;          ///< Runtime parameters as text format.
    uint32_t    _bytes_datagram_check; ///< Each datagram ends with the size of the datagram for
                                       ///< integrity check

    // cached decoded install txt
    std::optional<std::map<std::string, std::string>> _cached_install_txt_decoded;

  public:
    // ----- public constructors -----
    IInstallationParam();
    ~IInstallationParam() = default;

    // ----- convenient data access -----
    // getters
    uint16_t           get_bytes_content() const;
    uint16_t           get_info() const;
    uint16_t           get_status() const;
    const std::string& get_install_txt() const;
    uint32_t           get_bytes_datagram_check() const;

    const std::map<std::string, std::string>& get_install_txt_decoded_cached();
    const std::map<std::string, std::string>& get_install_txt_decoded_cached() const;
    void                                      cache_install_txt_decoded();

    // setters
    // void set_bytes_content(uint16_t bytes_content);
    void set_info(uint16_t info);
    void set_status(uint16_t status);
    void set_install_txt(std::string_view install_txt);

    // ----- flags and ping options -----
    bool                                 is_dual_rx() const;
    o_KMALLSystemTransducerConfiguration get_system_transducer_configuration() const;
    std::map<std::string, std::string>   get_transducer_serial_numbers() const;
    std::map<std::string, navigation::datastructures::PositionalOffsets> get_transducer_offsets() const;

    // ----- processed data access -----
    /**
     * @brief Decode the install_txt string into a key-value map
     *
     * This function parses the KMALL installation parameter text format.
     * The format contains comma-separated fields with different separators
     * for different field types (e.g., ':' for OSCV, '_' for PU, '=' for SN).
     *
     * @return std::map<std::string, std::string> Map of parameter names to values
     */
    std::map<std::string, std::string> get_install_txt_decoded() const;

    /**
     * @brief Decode an install_txt string into a key-value map (static version)
     *
     * @param install_txt The installation parameter text to decode
     * @return std::map<std::string, std::string> Map of parameter names to values
     */
    static std::map<std::string, std::string> decode_install_txt(std::string_view install_txt);

    /**
     * @brief Get human-readable explanation for an install_txt key
     *
     * @param key The key to look up (e.g., "OSCV", "EMXV", "PU")
     * @return std::string Human-readable explanation, or "Unknown key" if not found
     */
    static std::string get_install_txt_key_info(std::string_view key);

    /**
     * @brief Get all known install_txt key explanations
     *
     * @return const std::map<std::string, std::string>& Map of keys to their explanations
     */
    static const std::map<std::string, std::string>& get_install_txt_key_infos();

    // ----- sensor offset access -----
    /**
     * @brief Parse a semicolon-separated sensor string into key-value pairs
     *
     * For example: "X=0.000;Y=0.000;Z=0.000;R=0.000;P=0.000;H=0.000"
     *
     * @param sensor_string The sensor string to parse
     * @return std::map<std::string, std::string> Map of parameter names to values
     */
    static std::map<std::string, std::string> parse_sensor_string(std::string_view sensor_string);

    /**
     * @brief Get the transducer offsets for a given transducer
     *
     * Parses TRAI_TX1, TRAI_TX2, TRAI_RX1, TRAI_RX2, or TRAI_HD1 entries
     *
     * @param transducer_key Key like "TRAI_HD1", "TRAI_TX1", etc.
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_transducer_offsets(
        const std::string& transducer_key) const;

    /**
     * @brief Get the position system offsets for a given position system number
     *
     * Parses POSI_1, POSI_2, POSI_3, or POSI_4 entries
     *
     * @param position_system_number Position system number (1-4)
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_position_system_offsets(
        uint8_t position_system_number) const;

    /**
     * @brief Get the attitude sensor offsets for a given sensor number
     *
     * Parses ATTI_1, ATTI_2, ATTI_3, or ATTI_4 entries
     *
     * @param sensor_number Sensor number (1-4)
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_attitude_sensor_offsets(
        uint8_t sensor_number) const;

    /**
     * @brief Get the depth sensor offsets
     *
     * Parses DPHI entry
     *
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_depth_sensor_offsets() const;

    /**
     * @brief Get the waterline offset (SWLZ from EMXI)
     *
     * @return float Waterline offset in meters
     */
    float get_water_line_vertical_location_in_meters() const;

    /**
     * @brief Get the active position system number (1-4)
     *
     * Reads the U=ACTIVE field from POSI_n entries
     *
     * @return uint8_t Position system number (1-4), or 0 if none active
     */
    int8_t get_active_position_system_number() const;

    /**
     * @brief Get the active attitude sensor number (1-4)
     *
     * Reads the U=ACTIVE field from ATTI_n entries
     *
     * @return uint8_t Attitude sensor number (1-4), or 0 if none active
     */
    int8_t get_active_attitude_sensor_number() const;

    /**
     * @brief Get the system name (EMXV field)
     *
     * @return std::string System name (e.g., "EM2040P")
     */
    std::string get_system_name() const;

    /**
     * @brief Get the PU serial number (SN field)
     *
     * @return int PU serial number
     */
    int get_pu_serial_number() const;

    /**
     * @brief Get a list of available transducer keys present in the installation parameters
     *
     * Checks for TRAI_HD1, TRAI_TX1, TRAI_TX2, TRAI_RX1, TRAI_RX2
     *
     * @return std::vector<std::string> List of available transducer keys
     */
    std::vector<std::string> get_available_transducer_keys() const;

    /**
     * @brief Check if a specific transducer key is present
     *
     * @param key Transducer key (e.g., "TRAI_HD1", "TRAI_TX1")
     * @return bool True if the key is present
     */
    bool has_transducer_key(const std::string& key) const;

    // ----- operators -----
    bool operator==(const IInstallationParam& other) const = default;

    //----- to/from stream functions -----
    static IInstallationParam from_stream(std::istream& is, const KMALLDatagram& header);

    static IInstallationParam from_stream(std::istream&             is,
                                          o_KMALLDatagramIdentifier datagram_identifier);

    static IInstallationParam from_stream(std::istream& is);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(IInstallationParam)

  private:
    explicit IInstallationParam(const KMALLDatagram& header)
        : KMALLDatagram(header)
    {
    }
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
