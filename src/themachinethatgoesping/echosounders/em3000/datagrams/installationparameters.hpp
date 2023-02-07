// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/installationparameters.doc.hpp"

// std includes
#include <string>
#include <vector>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/navigation/datastructures/positionaloffsets.hpp>
#include <themachinethatgoesping/navigation/sensorconfiguration.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>

#include "../em3000_types.hpp"
#include "em3000datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {

static const std::map<std::string, std::string> __parameter_explained__ = {
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

    { "MSZ", "Motion sensor 1 vertical location in m" },
    { "MSX", "Motion sensor 1 along location in m" },
    { "MSY", "Motion sensor 1 athwart location in m" },
    { "MRP", "Motion sensor 1 roll reference plane" },
    { "MSD", "Motion sensor 1 time delay in milliseconds" },
    { "MSR", "Motion sensor 1 roll offset in degrees" },
    { "MSP", "Motion sensor 1 pitch offset in degrees" },
    { "MSG", "Motion sensor 1 HEADING offset in degrees" },

    { "NSZ", "Motion sensor 2 vertical location in m" },
    { "NSX", "Motion sensor 2 along location in m" },
    { "NSY", "Motion sensor 2 athwart location in m" },
    { "NRP", "Motion sensor 2 roll reference plane" },
    { "NSD", "Motion sensor 2 time delay in milliseconds" },
    { "NSR", "Motion sensor 2 roll offset in degrees" },
    { "NSP", "Motion sensor 2 pitch offset in degrees" },
    { "NSG", "Motion sensor 2 HEADING offset in degrees" },

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

/**
 * @brief This datagram is an ASCII datagram except for the header which is formatted as in all
 * other output datagrams. The datagram is issued as a start datagram when logging is switched on
 * and as a stop datagram when logging is turned off, i.e. at the start and end of a survey line. It
 * may also be sent to a remote port as an information datagram. It is usually followed by a sound
 * speed profile datagram. In the datagram all ASCII fields start with a unique three character
 * identifier followed by “=”. This should be used when searching for a specific field as the
 * position of a field within the datagram is not guaranteed. The number or character part following
 * is in a variable format with a minus sign and decimal point if needed, and with “,” as the field
 * delimiter. The format may at any time later be expanded with the addition of new fields at any
 * place in the datagram.
 */
class InstallationParameters : public EM3000Datagram
{
  public:
    // ----- enums -----
    enum class t_ActiveAttitudeSensor
    {
        MotionSensor1           = 2, ///< COM2
        MotionSensor2           = 3, ///< COM3
        AttitudeVelocitySensor1 = 8, ///< UDP5
        AttitudeVelocitySensor2 = 9  ///< UDP6
    };

    // ----- enums -----
    enum class t_ActiveHeadingSensor
    {
        PositionSystem3 = 0, ///< UDP2 or COM4
        PositionSystem1 = 1, ///< COM1
        PositionSystem2 =
            32, ///< COM3 (it is not clear how this case is separated from 3 (motion sensor 2))
        MotionSensor1           = 2, ///< COM2
        MotionSensor2           = 3, ///< COM3
        MultiCast1              = 5, ///<
        MultiCast2              = 6, ///<
        MultiCast3              = 7, ///<
        AttitudeVelocitySensor1 = 8, ///< UDP5
        AttitudeVelocitySensor2 = 9  ///< UDP6
    };

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
    explicit InstallationParameters(EM3000Datagram header)
        : EM3000Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    InstallationParameters()
    {
        _datagram_identifier = t_EM3000DatagramIdentifier::InstallationParametersStart;
    }
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
    static InstallationParameters merge(InstallationParameters first, InstallationParameters second)
    {
        static const std::array<const std::string, 2> uncritical_keys = {
            "RFN", // raw file name
            "SID"  // survey identifier
        };

        // use the datagram with the lower timestamp as base
        if (first.get_timestamp() > second.get_timestamp())
            std::swap(first, second);

        auto& params_first  = first._parsed_installation_parameters;
        auto& params_second = second._parsed_installation_parameters;

        // if both installation parameters are the same, return the first one
        if (params_first == params_second)
            return first;

        // check if the difference is caused by an uncritical key
        for (const auto& key : uncritical_keys)
        {
            const auto& f = params_first.find(key);
            const auto& s = params_second.find(key);

            if (f == params_first.end())
            {
                if (s == params_second.end())
                    continue;

                params_first[key] = s->second;
            }
            else if (s == params_second.end())
            {
                params_second[key] = f->second;
            }
        }

        // if both installation parameters are the same now, return the first one
        if (params_first == params_second)
            return first;

        // list all keys that are missing in params_first
        std::string missing_keys_1, missing_keys_2;
        for (const auto& [key, value] : params_second)
        {
            if (params_first.find(key) == params_first.end())
                missing_keys_1 += key + " ";
        }

        // list all keys that are missing in params_second
        for (const auto& [key, value] : params_first)
        {
            if (params_second.find(key) == params_second.end())
                missing_keys_2 += key + " ";
        }

        // list all keys that are different
        std::string different_keys;
        for (const auto& [key, value] : params_first)
        {
            if (params_first.find(key) == params_first.end())
                continue;

            if (params_second.find(key) == params_second.end())
                continue;

            if (params_second.find(key) == params_second.end())
                continue;

            if (params_second[key] != value)
                different_keys += key + " ";
        }

        throw(std::runtime_error(
            fmt::format("InstallationParameters::merge: Installation parameters cannot be merged: "
                        "missing keys in first: {}"
                        "\nmissing keys in second: {}"
                        "\nkeys with different values: {}",
                        missing_keys_1,
                        missing_keys_2,
                        different_keys)));
    }

    // ----- convenient data access -----
    // getters
    uint16_t get_installation_parameters_counter() const
    {
        return _installation_parameters_counter;
    }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint16_t get_secondary_system_serial_number() const { return _secondary_system_serial_number; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    // setters
    void set_installation_parameters_counter(uint16_t installation_parameters_counter)
    {
        _installation_parameters_counter = installation_parameters_counter;
    }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_secondary_system_serial_number(uint16_t secondary_system_serial_number)
    {
        _secondary_system_serial_number = secondary_system_serial_number;
    }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // substructures
    // std::string&       installation_parameters() { return _installation_parameters; }
    const std::string& get_installation_parameters() const { return _installation_parameters; }
    void               set_installation_parameters(std::string installation_parameters)
    {
        _installation_parameters = std::move(installation_parameters);

        // reparse the installation parameters
        reparse_installation_parameters();
    }

    // ----- processed data access -----
    const std::map<std::string, std::string>& get_installation_parameters_parsed()
    {
        return _parsed_installation_parameters;
    }

    // ----- public methods -----
    /**
     * @brief parse the installation parameters string into a map
     * This happens when the datagram is read from a file, but must be called manually when the
     * installation parameters string is changed manually.
     *
     */
    void reparse_installation_parameters()
    {
        std::string        fields;
        std::istringstream iss(_installation_parameters);

        _parsed_installation_parameters.clear();

        // fields are comma separated, key value pairs are separated by '='
        while (std::getline(iss, fields, ','))
        {
            std::istringstream iss2(fields);
            std::string        key;
            std::string        value;
            std::getline(iss2, key, '=');
            std::getline(iss2, value, '=');

            // delete NULL characters
            key.erase(std::remove(key.begin(), key.end(), '\0'), key.end());

            if (key.empty())
            {
                continue;
            }

            // if key is only whitespaces skip
            if (key.find_first_not_of(" \t\r\n\0\x00") == std::string::npos)
            {
                continue;
            }

            _parsed_installation_parameters[std::move(key)] = std::move(value);
        }
    }

    // ----- high level access to installation parameters -----
    float get_water_line_vertical_location_in_meters() const { return get_value_float("WLZ", 0.f); }

    int         get_system_main_head_serial_number() const { return get_value_int("SMH"); }
    int         get_tx_serial_number() const { return get_value_int("TXS"); }
    int         get_tx2_serial_number() const { return get_value_int("T2X"); }
    int         get_rx1_serial_number() const { return get_value_int("R1S"); }
    int         get_rx2_serial_number() const { return get_value_int("R2S"); }
    std::string get_system_transducer_configuration() const
    {
        auto s = get_value_string("STC", "");

        switch (s[0])
        {
            case '0':
                return "Single TX + single RX";
            case '1':
                return "Single head";
            case '2':
                return "Dual head";
            case '3':
                return "Single TX + dual RX";
            case '4':
                return "Dual TX + dual RX";
            case '5':
                return "Portable single head";
            case '6':
                return "Modular";
            default:
                return "Unknown";
        }
    }

    std::string get_tx_array_size() const
    {
        switch (get_value_string("S1S", "")[0])
        {
            case '0':
                return "0.5°";
            case '1':
                return "1°";
            case '2':
                return "2°";
            default:
                return "Unknown";
        }
    }

    std::string get_rx_array_size() const
    {
        switch (get_value_string("S2S", "")[0])
        {
            case '0':
                return "0.5°";
            case '1':
                return "1°";
            case '2':
                return "2°";
            default:
                return "Unknown";
        }
    }

    // ----- access to selected sensor offsets -----
    /**
     * @brief Get the compass sensor offsets (Gyrocompass)
     * Includes heading offset only
     *
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_compass_offsets() const
    {
        using navigation::datastructures::PositionalOffsets;
        return PositionalOffsets("Gyrocompass", 0, 0, 0, get_value_float("GCG", 0.f), 0, 0);
    }

    /**
     * @brief Get the depth sensor offsets
     *
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_depth_sensor_offsets() const
    {
        unsupported_option_string("DSH", "NI", "get_depth_sensor_offsets");
        unsupported_option_float("DSO", 0.0f, "get_depth_sensor_offsets");
        unsupported_option_float("DSD", 0.0f, "get_depth_sensor_offsets");
        unsupported_option_float("DSF", 1.0f, "get_depth_sensor_offsets");

        return get_sensor_offsets("Depth sensor", "DS", true, false);
    }

    /**
     * @brief Get the motion sensor offsets of sensor 1 or 2
     *
     * @param sensor_number must be 1 or 2
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_motion_sensor_offsets(
        uint8_t sensor_number) const
    {
        using tools::helper::string_to_floattype;

        // check unsupported options
        // MRP, MSD
        unsupported_option_string("MRP", "RP", "get_motion_sensor_offsets");
        unsupported_option_float("MAS", 1.0f, "get_motion_sensor_offsets");

        std::string sensor_prefix;
        switch (sensor_number)
        {
            case 1:
                sensor_prefix = "MS";
                break;
            case 2:
                sensor_prefix = "NS";
                break;
            default:
                throw std::invalid_argument(fmt::format(
                    "get_motion_sensor_offsets: Invalid motion sensor number: {} (must be 1 or 2)",
                    sensor_number));
        }

        std::string time_delay_key = sensor_prefix + std::string("D");
        unsupported_option_float(time_delay_key, 0.0f, "get_motion_sensor_offsets");

        try
        {
            return get_sensor_offsets("Motion sensor " + std::to_string(sensor_number),
                                      sensor_prefix);
        }
        catch (std::invalid_argument& e)
        {
            // If entries for a second motion sensor are not included although two sensors are being
            // used, they are presumed to have the same parameters.
            if (sensor_number == 2)
            {
                sensor_prefix = "MS";
                return get_sensor_offsets("Motion sensor " + std::to_string(sensor_number),
                                          sensor_prefix);
            }
            else
            {
                throw;
            }
        }
    }

    /**
     * @brief Get the position system offsets of system 1, 2 or 3
     *
     * @param position_system_number must be 1, 2 or 3
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_position_system_offsets(
        uint8_t position_system_number) const
    {
        using tools::helper::string_to_floattype;

        if (position_system_number > 3 || position_system_number < 1)
        {
            throw std::invalid_argument(fmt::format("get_position_system_offsets: Invalid position "
                                                    "system number: {} (must be 1, 2 or 3)",
                                                    position_system_number));
        }

        std::string sensor_prefix = "P" + std::to_string(position_system_number);

        // check unsupported options
        // unsupported_option_string(sensor_prefix + "M", "1", "get_position_system_offsets");
        // unsupported_option_string(sensor_prefix + "T", "1", "get_position_system_offsets");
        unsupported_option_string(sensor_prefix + "G", "WGS84", "get_position_system_offsets");
        unsupported_option_float(sensor_prefix + "D", 0.0f, "get_position_system_offsets");

        return get_sensor_offsets("Position system " + std::to_string(position_system_number),
                                  sensor_prefix,
                                  true, // has xyz offsets
                                  false // has ypr offsets
        );
    }

    /**
     * @brief Get the transducer offsets of transducer 0, 1, 2 or 3
     *
     * @param position_system_number must be 0, 1, 2 or 3
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_transducer_offsets(
        uint8_t     transducer_number,
        std::string transducer_name = "") const
    {
        using navigation::datastructures::PositionalOffsets;

        if (transducer_number > 3)
        {
            throw std::invalid_argument(fmt::format("get_transducer_offsets: Invalid transducer "
                                                    "number: {} (must be 0, 1, 2 or 3)",
                                                    transducer_number));
        }

        std::string sensor_prefix = "S" + std::to_string(transducer_number);

        // check unsupported options
        if (transducer_name.empty())
            transducer_name = "Transducer " + std::to_string(transducer_number);

        return PositionalOffsets(transducer_name,
                                 get_value_float(sensor_prefix + std::string("X"), 0.f),
                                 get_value_float(sensor_prefix + std::string("Y"), 0.f),
                                 get_value_float(sensor_prefix + std::string("Z"), 0.f),
                                 get_value_float(sensor_prefix + std::string("H"), 0.f),
                                 get_value_float(sensor_prefix + std::string("P"), 0.f),
                                 get_value_float(sensor_prefix + std::string("R"), 0.f));
    }

    /**
     * @brief Get the active position system number
     * (APS + 1)
     * @return uint8_t
     */
    uint8_t get_active_position_system_number() const
    {
        return std::stoi(get_value_string("ARO")) + 1;
    }

    /**
     * @brief Get the active roll pitch sensor (2, 3, 8 or 9) here returned as an enum
     *
     * @return t_ActiveAttitudeSensor
     */
    t_ActiveAttitudeSensor get_active_roll_pitch_sensor() const
    {
        std::string active_sensor = get_value_string("ARO");

        switch (active_sensor[0])
        {
            case '2':
                return t_ActiveAttitudeSensor::MotionSensor1;
            case '3':
                return t_ActiveAttitudeSensor::MotionSensor2;
            case '8':
                return t_ActiveAttitudeSensor::AttitudeVelocitySensor1;
            case '9':
                return t_ActiveAttitudeSensor::AttitudeVelocitySensor2;
            default:
                throw std::invalid_argument(fmt::format("get_active_roll_pitch_sensor: Invalid "
                                                        "active roll pitch sensor: {} (must be "
                                                        "2, 3, 8 or 9)",
                                                        active_sensor));
        }
    }

    /**
     * @brief Get the active heave sensor (2, 3, 8 or 9) here returned as an enum
     *
     * @return t_ActiveAttitudeSensor
     */
    t_ActiveAttitudeSensor get_active_heave_sensor() const
    {
        std::string active_sensor = get_value_string("AHE");

        switch (active_sensor[0])
        {
            case '2':
                return t_ActiveAttitudeSensor::MotionSensor1;
            case '3':
                return t_ActiveAttitudeSensor::MotionSensor2;
            case '8':
                return t_ActiveAttitudeSensor::AttitudeVelocitySensor1;
            case '9':
                return t_ActiveAttitudeSensor::AttitudeVelocitySensor2;
            default:
                throw std::invalid_argument(fmt::format("get_active_heave_sensor: Invalid "
                                                        "active roll pitch sensor: {} (must be "
                                                        "2, 3, 8 or 9)",
                                                        active_sensor));
        }
    }

    /**
     * @brief Get the active heading sensor (0-9) here returned as an enum
     *
     * @return t_ActiveHeadingSensor
     */
    t_ActiveHeadingSensor get_active_heading_sensor() const
    {
        std::string active_sensor = get_value_string("AHE");

        switch (active_sensor[0])
        {
            case '0':
                return t_ActiveHeadingSensor::PositionSystem3; // COM4
            case '1':
                return t_ActiveHeadingSensor::PositionSystem1; // COM1
            case '2':
                return t_ActiveHeadingSensor::MotionSensor1; // COM2
            case '3':
                return t_ActiveHeadingSensor::MotionSensor2; // COM3
            case '4':
                return t_ActiveHeadingSensor::PositionSystem3; // UDP2
            case '5':
                return t_ActiveHeadingSensor::MultiCast1;
            case '6':
                return t_ActiveHeadingSensor::MultiCast2;
            case '7':
                return t_ActiveHeadingSensor::MultiCast3;
            case '8':
                return t_ActiveHeadingSensor::AttitudeVelocitySensor1;
            case '9':
                return t_ActiveHeadingSensor::AttitudeVelocitySensor2;
            default:
                throw std::invalid_argument(fmt::format("get_active_heading_sensor: Invalid "
                                                        "active roll pitch sensor: {} (must be "
                                                        "0-9)",
                                                        active_sensor));
        }
    }

    /**
     * @brief Get the active attitude velocity sensor (not active, 1 or 2)
     * 0: not used
     * 1: Attitude Velocity Sensor 1 (assumed to be physical equal to Motion Sensor 1)
     * 2: Attitude Velocity Sensor 2 (assumed to be physical equal to Motion Sensor 2)
     *
     * @return t_ActiveAttitudeSensor
     */
    uint8_t get_active_attitude_velocity_sensor() const
    {
        return std::stoi(get_value_string("VSN"));
    }

    // ----- processed access to installation parameters (internal functions) -----
    const std::string& get_value_string(const std::string& key) const
    {
        auto it = _parsed_installation_parameters.find(key);
        if (it == _parsed_installation_parameters.end())
        {
            throw std::out_of_range(fmt::format("get_value: Key not found: {}", key));
        }

        return it->second;
    }

    std::string get_value_string(const std::string& key, std::string_view default_val) const
    {
        auto it = _parsed_installation_parameters.find(key);
        if (it == _parsed_installation_parameters.end())
        {
            return std::string(default_val);
        }

        return it->second;
    }

    float get_value_float(const std::string& key) const
    {
        return tools::helper::string_to_floattype<float>(get_value_string(key));
    }

    float get_value_float(const std::string& key, float default_value) const
    {
        auto value = get_value_string(key, "");
        if (value.empty())
        {
            return default_value;
        }

        return tools::helper::string_to_floattype<float>(value);
    }

    int get_value_int(const std::string& key) const { return stoi(get_value_string(key)); }

    int get_value_int(const std::string& key, int default_value) const
    {
        auto value = get_value_string(key, "");
        if (value.empty())
        {
            return default_value;
        }

        return stoi(value);
    }

    /**
     * @brief Internal function to get the sensor offsets from the installation parameters.
     * Possible sensor prefixes are:
     * - MS for motion sensor 1
     * - NS for motion sensor 2
     * - P1 for position system 1
     * - P2 for position system 2
     * - P3 for position system 3
     * - S1 for transducer 1
     * - S2 for transducer 2
     * - S3 for transducer 3
     * - DS for depth (pressure) sensor
     *
     * @param sensor_name e.g. Motion Sensor 1
     * @param sensor_prefix see above
     * @param has_xyz sensor has xyz offsets
     * @param has_ypr sensor has yaw pitch roll offsets
     * @return PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_sensor_offsets(
        const std::string& sensor_name,
        const std::string& sensor_prefix,
        bool               has_xyz = true,
        bool               has_ypr = true) const
    {
        using navigation::datastructures::PositionalOffsets;
        using tools::helper::string_to_floattype;

        float x = 0., y = 0., z = 0., yaw = 0., pitch = 0., roll = 0.;

        if (has_xyz)
        {
            x = get_value_float(sensor_prefix + std::string("X"), 0.f);
            y = get_value_float(sensor_prefix + std::string("Y"), 0.f);
            z = get_value_float(sensor_prefix + std::string("Z"), 0.f);
        }

        if (has_ypr)
        {
            yaw   = get_value_float(sensor_prefix + std::string("G"), 0.f);
            pitch = get_value_float(sensor_prefix + std::string("P"), 0.f);
            roll  = get_value_float(sensor_prefix + std::string("R"), 0.f);
        }

        return PositionalOffsets(sensor_name, x, y, z, yaw, pitch, roll);
    }

    // ----- operators -----
    bool operator==(const InstallationParameters& other) const
    {
        return EM3000Datagram::operator==(other) &&
               _installation_parameters_counter == other._installation_parameters_counter &&
               _system_serial_number == other._system_serial_number &&
               _secondary_system_serial_number == other._secondary_system_serial_number &&
               _installation_parameters == other._installation_parameters && _etx == other._etx &&
               _checksum == other._checksum;
    }
    bool operator!=(const InstallationParameters& other) const { return !operator==(other); }

    //----- to/from stream functions -----
    static InstallationParameters from_stream(std::istream& is, EM3000Datagram header)
    {
        InstallationParameters datagram(std::move(header));

        if (datagram._datagram_identifier !=
                t_EM3000DatagramIdentifier::InstallationParametersStart &&
            datagram._datagram_identifier != t_EM3000DatagramIdentifier::InstallationParametersStop)
            throw std::runtime_error(
                fmt::format("InstallationParameters: datagram identifier is neither 0x{:02x} nor "
                            "0x{:02x}, but 0x{:02x}",
                            uint8_t(t_EM3000DatagramIdentifier::InstallationParametersStart),
                            uint8_t(t_EM3000DatagramIdentifier::InstallationParametersStop),
                            uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._installation_parameters_counter)),
                6 * sizeof(uint8_t));

        // size of the ascii datagram
        // 21 = size of EM3000Datagram(12) + etx(1) + checksum(2) + 6
        const static uint8_t tmp = sizeof(uint8_t) * (21);

        // read the ASCII datagram
        datagram._installation_parameters.resize(datagram.get_bytes() - tmp);
        is.read(reinterpret_cast<char*>(datagram._installation_parameters.data()),
                datagram._installation_parameters.size());

        // read the rest of the datagram
        is.read(reinterpret_cast<char*>(&(datagram._etx)), sizeof(uint8_t));
        is.read(reinterpret_cast<char*>(&(datagram._checksum)), sizeof(uint16_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "InstallationParameters: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        // parse the installation parameters string
        datagram.reparse_installation_parameters();

        return datagram;
    }

    static InstallationParameters from_stream(std::istream& is)
    {
        return from_stream(is, EM3000Datagram::from_stream(is));
    }

    static InstallationParameters from_stream(std::istream&              is,
                                              t_EM3000DatagramIdentifier datagram_identifier)
    {
        return from_stream(is, std::move(EM3000Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os) const
    {
        if (_bytes - 21 != _installation_parameters.size())
            throw std::runtime_error(
                fmt::format("InstallationParameters: bytes - 21 ({}) does not match the size of "
                            "the _installation_parameters string ({})",
                            _bytes - 21,
                            _installation_parameters.size()));

        EM3000Datagram::to_stream(os);

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_installation_parameters_counter)),
                 6 * sizeof(uint8_t));

        // write the installation paramaters string
        os.write(reinterpret_cast<const char*>(_installation_parameters.data()),
                 _installation_parameters.size() * sizeof(uint8_t));

        // write the rest of the datagram
        os.write(reinterpret_cast<const char*>(&(_etx)), sizeof(uint8_t));
        os.write(reinterpret_cast<const char*>(&(_checksum)), sizeof(uint16_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("InstallationParameters", float_precision);

        printer.append(EM3000Datagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("installation_parameters_counter", _installation_parameters_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("secondary_system_serial_number", _secondary_system_serial_number);
        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        printer.register_section("substructures");
        printer.register_string("installation_parameters", _installation_parameters, "", -1, 50);

        printer.register_section("processed (installation parameter fields)");
        for (const auto& [key, value] : _parsed_installation_parameters)
        {
            std::string exp;
            if (__parameter_explained__.find(key) != __parameter_explained__.end())
                exp = __parameter_explained__.at(key);
            else
                exp = "unknown parameter";

            printer.register_string(key, value, exp);
        }

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(InstallationParameters)

  private:
    // ----- private functions -----
    void unsupported_option_float(const std::string& option_key,
                                  float              supported_value,
                                  const std::string& function_name) const
    {
        // if the option_key does not exist, the function will assume the supported value as default
        // value
        auto value = get_value_float(option_key, supported_value);

        if (value != supported_value)
        {
            throw std::runtime_error(fmt::format(": Only {} ({}) == "
                                                 "{} is supported yet, but {} is {}",
                                                 function_name,
                                                 option_key,
                                                 __parameter_explained__.at(option_key),
                                                 supported_value,
                                                 option_key,
                                                 value));
        }
    }

    void unsupported_option_string(const std::string& option_key,
                                   const std::string& supported_value,
                                   const std::string& function_name) const
    {
        // if the option_key does not exist, the function will assume the supported value as default
        // value
        const auto& value = get_value_string(option_key, supported_value);

        if (value != supported_value)
        {
            throw std::runtime_error(fmt::format("{}: Only {} ({}) == "
                                                 "{} is supported yet, but {} is {}",
                                                 function_name,
                                                 option_key,
                                                 __parameter_explained__.at(option_key),
                                                 supported_value,
                                                 option_key,
                                                 value));
        }
    }
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
