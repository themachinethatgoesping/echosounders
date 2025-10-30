// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/installationparameters.doc.hpp"

// std includes
#include <cstdint>
#include <iosfwd>
#include <map>
#include <string>
#include <string_view>

#include <frozen/string.h>
#include <frozen/unordered_map.h>

// themachinethatgoesping import
#include <themachinethatgoesping/navigation/datastructures/positionaloffsets.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

static constexpr frozen::unordered_map<frozen::string, std::string_view, 123> __parameter_explained__ = {
    { "WLZ", "Water line vertical location in m" },
    { "SMH", "System main head serial number" },
    { "HUN", "Hull Unit" },
    { "HUT", "Hull Unit tilt offset" },
    { "TXS", "TX serial number" },
    { "T2X", "TX no. 2 serial number" },
    { "R1S", "RX no. 1, serial number" },
    { "R2S", "RX no. 2, serial number" },
    { "STC", "System transducer configuration" },

    { "S0Z", "Transducer 0 vertical location in m" },
    { "S0X", "Transducer 0 along location in m" },
    { "S0Y", "Transducer 0 athwart location in m" },
    { "S0H", "Transducer 0 heading in degrees" },
    { "S0R", "Transducer 0 roll in degrees re horizontal" },
    { "S0P", "Transducer 0 pitch in degrees" },

    { "S1Z", "Transducer 1 vertical location in m" },
    { "S1X", "Transducer 1 along location in m" },
    { "S1Y", "Transducer 1 athwart location in m" },
    { "S1H", "Transducer 1 heading in degrees" },
    { "S1R", "Transducer 1 roll in degrees re horizontal" },
    { "S1P", "Transducer 1 pitch in degrees" },

    { "S2Z", "Transducer 2 vertical location in m" },
    { "S2X", "Transducer 2 along location in m" },
    { "S2Y", "Transducer 2 athwart location in m" },
    { "S2H", "Transducer 2 heading in degrees" },
    { "S2R", "Transducer 2 roll in degrees re horizontal" },
    { "S2P", "Transducer 2 pitch in degrees" },

    { "S3Z", "Transducer 3 vertical location in m" },
    { "S3X", "Transducer 3 along location in m" },
    { "S3Y", "Transducer 3 athwart location in m" },
    { "S3H", "Transducer 3 heading in degrees" },
    { "S3R", "Transducer 3 roll in degrees re horizontal" },
    { "S3P", "Transducer 3 pitch in degrees" },

    { "S1S", "TX array size (0=0.5°, 1=1°, 2=2°)" },
    { "S2S", "RX array size (0=0.5°, 1=1°, 2=2°)" },
    { "S3S", "RX2 array size (0=0.5°, 1=1°, 2=2°)" },
    { "GO1", "System (sonar head 1) gain offset" },
    { "GO2", "Sonar head 2 gain offset" },
    { "OBO", "Outer beam offset" },
    { "FGD", "High/Low Frequency Gain Difference" },
    { "TSV", "Transmitter (sonar head no1) software version" },
    { "RSV", "Receiver (sonar head 2) software version" },
    { "BSV", "BSP software version" },
    { "PSV", "Processing unit software version" },
    { "DDS", "DDS software version" },
    { "OSV", "Operator station software version" },
    { "DSV", "Datagram format version" },
    { "DSX", "Depth (pressure) sensor along location in m" },
    { "DSY", "Depth (pressure) sensor athwart location in m" },
    { "DSZ", "Depth (pressure) sensor vertical location in m" },
    { "DSD", "Depth (pressure) sensor time delay in millisec" },
    { "DSO", "Depth (pressure) sensor offset" },
    { "DSF", "Depth (pressure) sensor scale factor" },
    { "DSH", "Depth (pressure) sensor heave" },
    { "APS", "Active position system number" },

    { "P1Q", "Position system 1, quality check of position, 0=off, 1=on" },
    { "P1M", "Position system 1 motion compensation" },
    { "P1T", "Position system 1 time stamp used" },
    { "P1Z", "Position system 1 vertical location in m" },
    { "P1X", "Position system 1 along location in m" },
    { "P1Y", "Position system 1 athwart location in m" },
    { "P1D", "Position system 1 time delay in seconds" },
    { "P1G", "Position system 1 geodetic datum" },

    { "P2Q", "Position system 2, quality check of position, 0=off, 2=on" },
    { "P2M", "Position system 2 motion compensation" },
    { "P2T", "Position system 2 time stamp used" },
    { "P2Z", "Position system 2 vertical location in m" },
    { "P2X", "Position system 2 along location in m" },
    { "P2Y", "Position system 2 athwart location in m" },
    { "P2D", "Position system 2 time delay in seconds" },
    { "P2G", "Position system 2 geodetic datum" },

    { "P3Q", "Position system 3, quality check of position, 0=off, 1=on" },
    { "P3M", "Position system 3 motion compensation" },
    { "P3T", "Position system 3 time stamp used" },
    { "P3Z", "Position system 3 vertical location in m" },
    { "P3X", "Position system 3 along location in m" },
    { "P3Y", "Position system 3 athwart location in m" },
    { "P3D", "Position system 3 time delay in seconds" },
    { "P3G", "Position system 3 geodetic datum" },
    { "P3S", "Position system 3 on serial line or Ethernet" },

    { "MSZ", "Attitude sensor 1 vertical location in m" },
    { "MSX", "Attitude sensor 1 along location in m" },
    { "MSY", "Attitude sensor 1 athwart location in m" },
    { "MRP", "Attitude sensor 1 roll reference plane" },
    { "MSD", "Attitude sensor 1 time delay in milliseconds" },
    { "MSR", "Attitude sensor 1 roll offset in degrees" },
    { "MSP", "Attitude sensor 1 pitch offset in degrees" },
    { "MSG", "Attitude sensor 1 HEADING offset in degrees" },

    { "NSZ", "Attitude sensor 2 vertical location in m" },
    { "NSX", "Attitude sensor 2 along location in m" },
    { "NSY", "Attitude sensor 2 athwart location in m" },
    { "NRP", "Attitude sensor 2 roll reference plane" },
    { "NSD", "Attitude sensor 2 time delay in milliseconds" },
    { "NSR", "Attitude sensor 2 roll offset in degrees" },
    { "NSP", "Attitude sensor 2 pitch offset in degrees" },
    { "NSG", "Attitude sensor 2 HEADING offset in degrees" },

    { "GCG", "Gyrocompass heading offset in degrees" },
    { "MAS", "Roll scaling factor" },
    { "SHC", "Transducer depth sound speed source" },
    { "PPS", "1PPS clock synchronization" },
    { "CLS", "Clock source" },
    { "CLO", "Clock offset in seconds" },
    { "VSN", "Active attitude velocity sensor" },
    { "VSU", "Attitude velocity sensor 1 UDP port address (UDP5)" },
    { "VSE", "Attitude velocity sensor 1 Ethernet port" },
    { "VTU", "Attitude velocity sensor 2 UDP port address (UDP6)" },
    { "VTE", "Attitude velocity sensor 2 Ethernet port" },
    { "ARO", "Active roll/pitch sensor" },
    { "AHE", "Active heave sensor" },
    { "AHS", "Active heading sensor" },
    { "VSI", "Ethernet 2 address" },
    { "VSM", "Ethernet 2 IP network mask" },
    { "MCAn", "Multicast sensor IP multicast address (Ethernet 2)" },
    { "MCUn", "Multicast sensor UDP port number" },
    { "MCIn", "Multicast sensor identifier" },
    { "MCPn", "Multicast position system number" },
    { "SNL", "Ships noise level" },
    { "CPR", "Cartographic projection" },
    { "ROP", "Responsible operator" },
    { "SID", "Survey identifier" },
    { "RFN", "Raw File Name" },
    { "PLL", "Survey line identifier (planned line no)" },
    { "COM", "Comment" }
};
//static constexpr auto __parameter_explained__ = frozen::make_unordered_map(__explain_pairs__);

/**
 * @brief This datagram is an ASCII datagram except for the header which is formatted as in all
 * other output datagrams. The datagram is issued as a start datagram when logging is switched on
 * and as a stop datagram when logging is turned off, i.e. at the start and end of a survey line. It
 * may also be sent to a remote port as an information datagram. It is usually followed by a sound
 * speed profile datagram. In the datagram all ASCII fields start with a unique three character
 * identifier followed by "=". This should be used when searching for a specific field as the
 * position of a field within the datagram is not guaranteed. The number or character part following
 * is in a variable format with a minus sign and decimal point if needed, and with "," as the field
 * delimiter. The format may at any time later be expanded with the addition of new fields at any
 * place in the datagram.
 */
class InstallationParameters : public KongsbergAllDatagram
{
  public:
    // TODO: InstallationParameters can also have a different datagram identifier
    // (InstallationParametersStop)
    static constexpr auto DatagramIdentifier =
        t_KongsbergAllDatagramIdentifier::InstallationParametersStart;

  protected:
    uint16_t _installation_parameters_counter; ///< Sequential Number
    uint16_t _system_serial_number;
    uint16_t _secondary_system_serial_number;

    std::string _installation_parameters;

    // uint8_t  _spare;      ///< only used if number of bytes is odd
    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

    // parsed data (will not be saved)
    std::map<std::string, std::string> _parsed_installation_parameters;

  private:
    // ----- private constructors -----
    explicit InstallationParameters(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    InstallationParameters();
    ~InstallationParameters() = default;

    // ----- factory functions -----
    /**
     * @brief Merge two InstallationParameters datagrams into one
     * If the datagrams differ because an uncritical key does not exist in one of them, the
     * uncritical key will be added to the resulting datagram.
     *
     * @param first
     * @param second
     * @return InstallationParameters
     */
    static InstallationParameters merge(InstallationParameters first,
                                        InstallationParameters second);

    // ----- convenient data access -----
    // getters
    uint16_t read_installation_parameters_counter() const;
    uint16_t get_system_serial_number() const;
    uint16_t get_secondary_system_serial_number() const;
    uint8_t  get_etx() const;
    uint16_t get_checksum() const;

    // setters
    void set_installation_parameters_counter(uint16_t installation_parameters_counter);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_secondary_system_serial_number(uint16_t secondary_system_serial_number);
    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);

    // substructures
    const std::string& read_installation_parameters() const;
    void               set_installation_parameters(std::string installation_parameters);

    // ----- processed data access -----
    const std::map<std::string, std::string>& read_installation_parameters_parsed();

    // ----- public methods -----
    /**
     * @brief parse the installation parameters string into a map
     * This happens when the datagram is read from a file, but must be called manually when the
     * installation parameters string is changed manually.
     *
     */
    void reparse_installation_parameters();

    // ----- flags and ping options -----
    bool        is_dual_rx() const;
    std::string build_channel_id() const;

    // ----- high level access to installation parameters -----
    float get_water_line_vertical_location_in_meters() const;

    int                                         get_system_main_head_serial_number() const;
    int                                         get_tx_serial_number() const;
    int                                         get_tx2_serial_number() const;
    int                                         get_rx1_serial_number() const;
    int                                         get_rx2_serial_number() const;
    o_KongsbergAllSystemTransducerConfiguration get_system_transducer_configuration() const;

    std::string get_tx_array_size() const;
    std::string get_rx_array_size() const;

    // ----- access to selected sensor offsets -----
    /**
     * @brief Get the compass sensor offsets (Gyrocompass)
     * Includes heading offset only
     *
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_compass_offsets() const;

    /**
     * @brief Get the depth sensor offsets
     *
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_depth_sensor_offsets() const;

    /**
     * @brief Get the attitude sensor offsets of sensor 1 or 2
     *
     * @param sensor_number o_KongsbergAllActiveSensor (enum)
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_attitude_sensor_offsets(
        o_KongsbergAllActiveSensor sensor) const;

    /**
     * @brief Get the attitude sensor offsets of sensor 1 or 2
     *
     * @param sensor_number must be 1 or 2
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_attitude_sensor_offsets(
        uint8_t sensor_number) const;

    /**
     * @brief Get the position system offsets of system 1, 2 or 3
     *
     * @param position_system_number must be 1, 2 or 3
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_position_system_offsets(
        uint8_t position_system_number) const;

    /**
     * @brief Get the transducer offsets of transducer 0, 1, 2 or 3
     *
     * @param position_system_number must be 0, 1, 2 or 3
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_transducer_offsets(
        uint8_t     transducer_number,
        std::string transducer_name = "") const;

    /**
     * @brief Get the active position system number
     * (APS + 1)
     * @return uint8_t
     */
    uint8_t get_active_position_system_number() const;

    /**
     * @brief Get the active roll pitch sensor (2, 3, 8 or 9) here returned as an enum
     *
     * @return o_KongsbergAllActiveSensor
     */
    o_KongsbergAllActiveSensor get_active_pitch_roll_sensor() const;

    /**
     * @brief Get the active heave sensor (2, 3, 8 or 9) here returned as an enum
     *
     * @return o_KongsbergAllActiveSensor
     */
    o_KongsbergAllActiveSensor get_active_heave_sensor() const;

    /**
     * @brief Get the active heading sensor (0-9) here returned as an enum
     *
     * @return o_KongsbergAllActiveSensor
     */
    o_KongsbergAllActiveSensor get_active_heading_sensor() const;

    /**
     * @brief Get the active attitude velocity sensor (not active, 1 or 2)
     * 0: not used
     * 1: Attitude Velocity Sensor 1 (assumed to be physical equal to Attitude sensor 1)
     * 2: Attitude Velocity Sensor 2 (assumed to be physical equal to Attitude sensor 2)
     *
     * @return o_KongsbergAllActiveSensor
     */
    uint8_t get_active_attitude_velocity_sensor() const;

    // ----- processed access to installation parameters (internal functions) -----
    const std::string& get_value_string(const std::string& key) const;
    std::string        get_value_string(const std::string& key, std::string_view default_val) const;
    float              get_value_float(const std::string& key) const;
    float              get_value_float(const std::string& key, float default_value) const;
    int                get_value_int(const std::string& key) const;
    int                get_value_int(const std::string& key, int default_value) const;

    /**
     * @brief Internal function to get the sensor offsets from the installation parameters.
     * Possible sensor prefixes are:
     * - MS for attitude sensor 1
     * - NS for attitude sensor 2
     * - P1 for position system 1
     * - P2 for position system 2
     * - P3 for position system 3
     * - S1 for transducer 1
     * - S2 for transducer 2
     * - S3 for transducer 3
     * - DS for depth (pressure) sensor
     *
     * @param sensor_name e.g. Attitude sensor 1
     * @param sensor_prefix see above
     * @param has_xyz sensor has xyz offsets
     * @param has_ypr sensor has yaw pitch roll offsets
     * @return PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_sensor_offsets(
        const std::string& sensor_name,
        const std::string& sensor_prefix,
        bool               has_xyz = true,
        bool               has_ypr = true) const;

    // ----- operators -----
    bool operator==(const InstallationParameters& other) const = default;

    //----- to/from stream functions -----
    static InstallationParameters from_stream(std::istream& is, KongsbergAllDatagram header);
    static InstallationParameters from_stream(std::istream& is);
    static InstallationParameters from_stream(std::istream&                    is,
                                              t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(InstallationParameters)

  private:
    // ----- private functions -----
    void unsupported_option_float(const std::string& option_key,
                                  float              supported_value,
                                  const std::string& function_name) const;

    void unsupported_option_string(const std::string& option_key,
                                   const std::string& supported_value,
                                   const std::string& function_name) const;
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
