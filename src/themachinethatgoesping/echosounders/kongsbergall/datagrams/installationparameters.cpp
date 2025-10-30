// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "installationparameters.hpp"

// std includes
#include <algorithm>
#include <iostream>
#include <utility>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>
#include <xtensor/views/xview.hpp>

// external includes
#include <fmt/format.h>
#include <magic_enum/magic_enum.hpp>

#include <frozen/string.h>

// themachinethatgoesping includes
#include <themachinethatgoesping/navigation/sensorconfiguration.hpp>
#include <themachinethatgoesping/tools/helper/isviewstream.hpp>
#include <themachinethatgoesping/tools/helper/stringconversion.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

// ----- constructors -----
InstallationParameters::InstallationParameters(KongsbergAllDatagram header)
    : KongsbergAllDatagram(std::move(header))
{
}

InstallationParameters::InstallationParameters()
{
    _datagram_identifier = t_KongsbergAllDatagramIdentifier::InstallationParametersStart;
}

// ----- convenient data access -----
uint16_t InstallationParameters::read_installation_parameters_counter() const
{
    return _installation_parameters_counter;
}

uint16_t InstallationParameters::get_system_serial_number() const
{
    return _system_serial_number;
}

uint16_t InstallationParameters::get_secondary_system_serial_number() const
{
    return _secondary_system_serial_number;
}

uint8_t InstallationParameters::get_etx() const
{
    return _etx;
}

uint16_t InstallationParameters::get_checksum() const
{
    return _checksum;
}

void InstallationParameters::set_installation_parameters_counter(uint16_t installation_parameters_counter)
{
    _installation_parameters_counter = installation_parameters_counter;
}

void InstallationParameters::set_system_serial_number(uint16_t system_serial_number)
{
    _system_serial_number = system_serial_number;
}

void InstallationParameters::set_secondary_system_serial_number(uint16_t secondary_system_serial_number)
{
    _secondary_system_serial_number = secondary_system_serial_number;
}

void InstallationParameters::set_etx(uint8_t etx)
{
    _etx = etx;
}

void InstallationParameters::set_checksum(uint16_t checksum)
{
    _checksum = checksum;
}

const std::string& InstallationParameters::read_installation_parameters() const
{
    return _installation_parameters;
}

const std::map<std::string, std::string>&
InstallationParameters::read_installation_parameters_parsed()
{
    if (_parsed_installation_parameters.empty() && !_installation_parameters.empty())
    {
        reparse_installation_parameters();
    }

    return _parsed_installation_parameters;
}

// ----- factory functions -----
InstallationParameters InstallationParameters::merge(InstallationParameters first,
                                                     InstallationParameters second)
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

void InstallationParameters::set_installation_parameters(std::string installation_parameters)
{
    _installation_parameters = std::move(installation_parameters);

    // reparse the installation parameters
    reparse_installation_parameters();
}

void InstallationParameters::reparse_installation_parameters()
{
    /// TODO: there is still unecessary copying of strings (fields, key, value)
    std::string                 fields;
    tools::helper::isviewstream iss{
        std::string_view(_installation_parameters)
    }; // TODO: why does this work but iss(std::string_view(_installation_parameters) ) not?

    _parsed_installation_parameters.clear();

    // fields are comma separated, key value pairs are separated by '='
    while (std::getline(iss, fields, ','))
    {
        tools::helper::isviewstream iss2{ { fields } };
        std::string                 key;
        std::string                 value;
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

bool InstallationParameters::is_dual_rx() const
{
    auto stc = get_system_transducer_configuration();

    switch (stc.value)
    {
        case t_KongsbergAllSystemTransducerConfiguration::SingleHead:
            [[fallthrough]];
        case t_KongsbergAllSystemTransducerConfiguration::PortableSingleHead:
            [[fallthrough]];
        case t_KongsbergAllSystemTransducerConfiguration::SingleTXSingleRX:
            return false;
        case t_KongsbergAllSystemTransducerConfiguration::SingleTXDualRX:
            return true;
        default:
            throw(std::runtime_error(fmt::format("InstallationParameters::is_dual_rx: "
                                                 "unsupported transducer configuration: {}",
                                                 stc.name())));
    }
}

std::string InstallationParameters::build_channel_id() const
{
    std::string channel_id = "EM" + std::to_string(get_model_number());
    channel_id += " " + get_system_transducer_configuration().name();
    channel_id += " " + std::to_string(this->get_system_serial_number());

    if (is_dual_rx())
        channel_id += "-" + std::to_string(this->get_secondary_system_serial_number());

    return channel_id;
}

float InstallationParameters::get_water_line_vertical_location_in_meters() const
{
    return get_value_float("WLZ", 0.f);
}

int InstallationParameters::get_system_main_head_serial_number() const
{
    return get_value_int("SMH");
}

int InstallationParameters::get_tx_serial_number() const
{
    return get_value_int("TXS");
}

int InstallationParameters::get_tx2_serial_number() const
{
    return get_value_int("T2X");
}

int InstallationParameters::get_rx1_serial_number() const
{
    return get_value_int("R1S");
}

int InstallationParameters::get_rx2_serial_number() const
{
    return get_value_int("R2S");
}

o_KongsbergAllSystemTransducerConfiguration
InstallationParameters::get_system_transducer_configuration() const
{
    unsigned int val = get_value_int("STC", 0);

    if (val > 6)
        throw(std::runtime_error(
            fmt::format("InstallationParameters::get_system_transducer_configuration: "
                        "invalid transducer configuration: {}",
                        val)));

    return o_KongsbergAllSystemTransducerConfiguration(val);
}

std::string InstallationParameters::get_tx_array_size() const
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

std::string InstallationParameters::get_rx_array_size() const
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

navigation::datastructures::PositionalOffsets InstallationParameters::get_compass_offsets() const
{
    using navigation::datastructures::PositionalOffsets;
    return PositionalOffsets("Gyrocompass", 0, 0, 0, get_value_float("GCG", 0.f), 0, 0);
}

navigation::datastructures::PositionalOffsets InstallationParameters::get_depth_sensor_offsets()
    const
{
    // TODO: this option should be supported
    try
    {
        unsupported_option_string("DSH", "NI", "get_depth_sensor_offsets");
    }
    catch (std::exception& e)
    {
        std::cerr << "WARNING: " << e.what() << std::endl;
    }
    unsupported_option_float("DSO", 0.0f, "get_depth_sensor_offsets");
    unsupported_option_float("DSD", 0.0f, "get_depth_sensor_offsets");
    unsupported_option_float("DSF", 1.0f, "get_depth_sensor_offsets");

    return get_sensor_offsets("Depth sensor", "DS", true, false);
}

navigation::datastructures::PositionalOffsets InstallationParameters::get_attitude_sensor_offsets(
    o_KongsbergAllActiveSensor sensor) const
{
    switch (sensor.value)
    {
        case t_KongsbergAllActiveSensor::MotionSensor1:
            [[fallthrough]];
        case t_KongsbergAllActiveSensor::AttitudeVelocitySensor1:
            return get_attitude_sensor_offsets(1);
        case t_KongsbergAllActiveSensor::MotionSensor2:
            [[fallthrough]];
        case t_KongsbergAllActiveSensor::AttitudeVelocitySensor2:
            return get_attitude_sensor_offsets(2);
        default:
            throw std::invalid_argument("Invalid sensor number");
    }
}

navigation::datastructures::PositionalOffsets InstallationParameters::get_attitude_sensor_offsets(
    uint8_t sensor_number) const
{
    using tools::helper::string_to_floattype;

    // check unsupported options
    // MRP, MSD
    unsupported_option_string("MRP", "RP", "get_attitude_sensor_offsets");
    unsupported_option_float("MAS", 1.0f, "get_attitude_sensor_offsets");

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
            throw std::invalid_argument(
                fmt::format("get_attitude_sensor_offsets: Invalid attitude sensor number: {} "
                            "(must be 1 or 2)",
                            sensor_number));
    }

    std::string time_delay_key = sensor_prefix + std::string("D");
    // unsupported_option_float(time_delay_key, 0.0f, "get_attitude_sensor_offsets");
    // TODO: warn that time_delay is ignored for now

    try
    {
        return get_sensor_offsets("Attitude sensor " + std::to_string(sensor_number),
                                  sensor_prefix);
    }
    catch (std::invalid_argument& e)
    {
        // If entries for a second attitude sensor are not included although two sensors are
        // being used, they are presumed to have the same parameters.
        if (sensor_number == 2)
        {
            sensor_prefix = "MS";
            return get_sensor_offsets("Attitude sensor " + std::to_string(sensor_number),
                                      sensor_prefix);
        }
        else
        {
            throw;
        }
    }
}

navigation::datastructures::PositionalOffsets InstallationParameters::get_position_system_offsets(
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
    try
    {
        unsupported_option_string(sensor_prefix + "G", "WGS84", "get_position_system_offsets");
    }
    catch (std::exception& e)
    {
        std::cerr << "WARNING: " << e.what() << std::endl;
    }

    unsupported_option_float(sensor_prefix + "D", 0.0f, "get_position_system_offsets");

    return get_sensor_offsets("Position system " + std::to_string(position_system_number),
                              sensor_prefix,
                              true, // has xyz offsets
                              false // has ypr offsets
    );
}

navigation::datastructures::PositionalOffsets InstallationParameters::get_transducer_offsets(
    uint8_t     transducer_number,
    std::string transducer_name) const
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

uint8_t InstallationParameters::get_active_position_system_number() const
{
    return std::stoi(get_value_string("APS")) + 1;
}

o_KongsbergAllActiveSensor InstallationParameters::get_active_pitch_roll_sensor() const
{
    std::string active_sensor = get_value_string("ARO");

    switch (active_sensor[0])
    {
        case '2':
            return t_KongsbergAllActiveSensor::MotionSensor1;
        case '3':
            return t_KongsbergAllActiveSensor::MotionSensor2;
        case '8':
            return t_KongsbergAllActiveSensor::AttitudeVelocitySensor1;
        case '9':
            return t_KongsbergAllActiveSensor::AttitudeVelocitySensor2;
        default:
            throw std::invalid_argument(fmt::format("get_active_pitch_roll_sensor: Invalid "
                                                    "active roll pitch sensor: {} (must be "
                                                    "2, 3, 8 or 9)",
                                                    active_sensor));
    }
}

o_KongsbergAllActiveSensor InstallationParameters::get_active_heave_sensor() const
{
    std::string active_sensor = get_value_string("AHE");

    switch (active_sensor[0])
    {
        case '2':
            return t_KongsbergAllActiveSensor::MotionSensor1;
        case '3':
            return t_KongsbergAllActiveSensor::MotionSensor2;
        case '8':
            return t_KongsbergAllActiveSensor::AttitudeVelocitySensor1;
        case '9':
            return t_KongsbergAllActiveSensor::AttitudeVelocitySensor2;
        default:
            throw std::invalid_argument(fmt::format("get_active_heave_sensor: Invalid "
                                                    "active roll pitch sensor: {} (must be "
                                                    "2, 3, 8 or 9)",
                                                    active_sensor));
    }
}

o_KongsbergAllActiveSensor InstallationParameters::get_active_heading_sensor() const
{
    std::string active_sensor = get_value_string("AHE");

    switch (active_sensor[0])
    {
        case '0':
            return t_KongsbergAllActiveSensor::PositionSystem3; // COM4
        case '1':
            return t_KongsbergAllActiveSensor::PositionSystem1; // COM1
        case '2':
            return t_KongsbergAllActiveSensor::MotionSensor1; // COM2
        case '3':
            return t_KongsbergAllActiveSensor::MotionSensor2; // COM3
        case '4':
            return t_KongsbergAllActiveSensor::PositionSystem3; // UDP2
        case '5':
            return t_KongsbergAllActiveSensor::MultiCast1;
        case '6':
            return t_KongsbergAllActiveSensor::MultiCast2;
        case '7':
            return t_KongsbergAllActiveSensor::MultiCast3;
        case '8':
            return t_KongsbergAllActiveSensor::AttitudeVelocitySensor1;
        case '9':
            return t_KongsbergAllActiveSensor::AttitudeVelocitySensor2;
        default:
            throw std::invalid_argument(fmt::format("get_active_heading_sensor: Invalid "
                                                    "active roll pitch sensor: {} (must be "
                                                    "0-9)",
                                                    active_sensor));
    }
}

uint8_t InstallationParameters::get_active_attitude_velocity_sensor() const
{
    return std::stoi(get_value_string("VSN"));
}

const std::string& InstallationParameters::get_value_string(const std::string& key) const
{
    auto it = _parsed_installation_parameters.find(key);
    if (it == _parsed_installation_parameters.end())
    {
        throw std::out_of_range(fmt::format("get_value: Key not found: {}", key));
    }

    return it->second;
}

std::string InstallationParameters::get_value_string(const std::string& key,
                                                     std::string_view   default_val) const
{
    auto it = _parsed_installation_parameters.find(key);
    if (it == _parsed_installation_parameters.end())
    {
        return std::string(default_val);
    }

    return it->second;
}

float InstallationParameters::get_value_float(const std::string& key) const
{
    return tools::helper::string_to_floattype<float>(get_value_string(key));
}

float InstallationParameters::get_value_float(const std::string& key, float default_value) const
{
    auto value = get_value_string(key, "");
    if (value.empty())
    {
        return default_value;
    }

    return tools::helper::string_to_floattype<float>(value);
}

int InstallationParameters::get_value_int(const std::string& key) const
{
    return stoi(get_value_string(key));
}

int InstallationParameters::get_value_int(const std::string& key, int default_value) const
{
    auto value = get_value_string(key, "");
    if (value.empty())
    {
        return default_value;
    }

    return stoi(value);
}

navigation::datastructures::PositionalOffsets InstallationParameters::get_sensor_offsets(
    const std::string& sensor_name,
    const std::string& sensor_prefix,
    bool               has_xyz,
    bool               has_ypr) const
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

InstallationParameters InstallationParameters::from_stream(std::istream&        is,
                                                           KongsbergAllDatagram header)
{
    InstallationParameters datagram(std::move(header));

    if (datagram._datagram_identifier !=
            t_KongsbergAllDatagramIdentifier::InstallationParametersStart &&
        datagram._datagram_identifier !=
            t_KongsbergAllDatagramIdentifier::InstallationParametersStop)
        throw std::runtime_error(
            fmt::format("InstallationParameters: datagram identifier is neither 0x{:02x} nor "
                        "0x{:02x}, but 0x{:02x}",
                        uint8_t(t_KongsbergAllDatagramIdentifier::InstallationParametersStart),
                        uint8_t(t_KongsbergAllDatagramIdentifier::InstallationParametersStop),
                        uint8_t(datagram._datagram_identifier)));

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(datagram._installation_parameters_counter)),
            6 * sizeof(uint8_t));

    // size of the ascii datagram
    // 21 = size of KongsbergAllDatagram(12) + etx(1) + checksum(2) + 6
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

InstallationParameters InstallationParameters::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

InstallationParameters InstallationParameters::from_stream(
    std::istream&                    is,
    t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void InstallationParameters::to_stream(std::ostream& os) const
{
    if (_bytes - 21 != _installation_parameters.size())
        throw std::runtime_error(
            fmt::format("InstallationParameters: bytes - 21 ({}) does not match the size of "
                        "the _installation_parameters string ({})",
                        _bytes - 21,
                        _installation_parameters.size()));

    KongsbergAllDatagram::to_stream(os);

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

tools::classhelper::ObjectPrinter InstallationParameters::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "InstallationParameters", float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
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
        auto it = __parameter_explained__.find(std::string_view(key));
        if (it != __parameter_explained__.end())
            exp = it->second;
        else
            exp = "unknown parameter";

        printer.register_string(key, value, exp);
    }

    return printer;
}

void InstallationParameters::unsupported_option_float(const std::string& option_key,
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
                                             supported_value,
                                             __parameter_explained__.at(std::string_view(option_key)),
                                             value));
    }
}

void InstallationParameters::unsupported_option_string(const std::string& option_key,
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
                                             __parameter_explained__.at(std::string_view(option_key)),
                                             supported_value,
                                             option_key,
                                             value));
    }
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
