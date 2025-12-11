// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "iinstallationparam.hpp"

#include <fmt/format.h>

#include <algorithm>
#include <array>
#include <optional>
#include <stdexcept>
#include <utility>

#include <boost/algorithm/string.hpp>

#include <themachinethatgoesping/tools/helper/stringconversion.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

IInstallationParam::IInstallationParam()
{
    _datagram_identifier = DatagramIdentifier;
}
// ----- getters -----
uint16_t IInstallationParam::get_bytes_content() const
{
    return _bytes_content;
}

uint16_t IInstallationParam::get_info() const
{
    return _info;
}

uint16_t IInstallationParam::get_status() const
{
    return _status;
}

const std::string& IInstallationParam::get_install_txt() const
{
    return _install_txt;
}

uint32_t IInstallationParam::get_bytes_datagram_check() const
{
    return _bytes_datagram_check;
}

const std::map<std::string, std::string>& IInstallationParam::get_install_txt_decoded_cached() const
{
    if (!_cached_install_txt_decoded.has_value())
        throw(std::runtime_error("IInstallationParam::get_install_txt_decoded_cached: cached value "
                                 "not available. Call cache_install_txt() first"));

    return *_cached_install_txt_decoded;
}

const std::map<std::string, std::string>& IInstallationParam::get_install_txt_decoded_cached()
{
    if (!_cached_install_txt_decoded.has_value())
        cache_install_txt_decoded();

    return *_cached_install_txt_decoded;
}

void IInstallationParam::cache_install_txt_decoded()
{
    _cached_install_txt_decoded = get_install_txt_decoded();
}
// setters
// void IInstallationParam::set_bytes_content(uint16_t bytes_content) {
//     _bytes_content = bytes_content;
// }

void IInstallationParam::set_info(uint16_t info)
{
    _info = info;
}

void IInstallationParam::set_status(uint16_t status)
{
    _status = status;
}

void IInstallationParam::set_install_txt(std::string_view install_txt)
{
    static constexpr size_t dbytes = 3 * sizeof(uint16_t) + sizeof(uint32_t);

    _bytes_content = dbytes + install_txt.size() * sizeof(char); // size of the string in bytes

    _install_txt.assign(install_txt.begin(), install_txt.end());

    // increase _bytes_content to 4 byte alignment
    if (_bytes_content % 4 != 0)
    {
        _bytes_content += 4 - (_bytes_content % 4);
    }

    _install_txt.resize(_bytes_content - dbytes, '\0'); // pad with null characters
    set_bytes_datagram(KMALLDatagram::__size + _bytes_content);
    _bytes_datagram_check = get_bytes_datagram();

    cache_install_txt_decoded();
}

o_KMALLSystemTransducerConfiguration IInstallationParam::get_system_transducer_configuration() const
{
    const auto& install_txt_map = get_install_txt_decoded_cached();

    auto it = install_txt_map.find("SYSTEM");
    if (it == install_txt_map.end())
    {
        throw(std::runtime_error("InstallationParameters::get_system_transducer_configuration: "
                                 "missing SYSTEM key in install_txt"));
    }

    // split on '-' and take last token (like Python split('-')[-1]) then trim whitespace
    std::string              system_value = it->second;
    std::vector<std::string> parts;
    boost::split(parts, system_value, boost::is_any_of("-"));
    system_value =
        boost::trim_copy(boost::split(parts, system_value, boost::is_any_of("-")).back());

    return o_KMALLSystemTransducerConfiguration::to_value(system_value);
}

std::map<std::string, std::string> IInstallationParam::get_transducer_serial_numbers() const
{
    std::map<std::string, std::string> serial_numbers;

    for (const auto& [key, value] : get_install_txt_decoded_cached())
    {
        if (key.find("SERIALno|") != std::string::npos)
        {
            // Extract suffix after '|' (e.g. "SERIALno|RX" becomes "RX")
            std::vector<std::string> fields;
            boost::split(fields, key, boost::is_any_of("|"));

            serial_numbers[fields.back()] = value;
        }
    }

    // check for validity
    auto stc = get_system_transducer_configuration();

    switch (stc.value)
    {
        case t_KMALLSystemTransducerConfiguration::SingleHead:
            [[fallthrough]];
        case t_KMALLSystemTransducerConfiguration::PortableSingleHead:
            if (serial_numbers.size() == 2 && serial_numbers.contains("TX") &&
                serial_numbers.contains("RX"))
            {
                return { { "TRX", serial_numbers["TX"] } };
            }
            throw(std::runtime_error(
                fmt::format("InstallationParameters::get_transducer_serial_numbers: "
                            "invalid serial numbers for SingleHead configuration: {}",
                            fmt::join(serial_numbers, ", "))));
        case t_KMALLSystemTransducerConfiguration::SingleTxSingleRx:
            if (serial_numbers.size() == 2 && serial_numbers.contains("TX") &&
                serial_numbers.contains("RX"))
            {
                return serial_numbers;
            }
        default:
            throw(std::runtime_error(fmt::format("InstallationParameters::is_dual_rx: "
                                                 "unsupported transducer configuration: {}",
                                                 stc.name())));
    }
}

bool IInstallationParam::is_dual_rx() const
{
    auto stc = get_system_transducer_configuration();

    switch (stc.value)
    {
        case t_KMALLSystemTransducerConfiguration::SingleHead:
            [[fallthrough]];
        case t_KMALLSystemTransducerConfiguration::PortableSingleHead:
            [[fallthrough]];
        case t_KMALLSystemTransducerConfiguration::SingleTxSingleRx:
            return false;
        case t_KMALLSystemTransducerConfiguration::SingleTxDualRx:
            return true;
        default:
            throw(std::runtime_error(fmt::format("InstallationParameters::is_dual_rx: "
                                                 "unsupported transducer configuration: {}",
                                                 stc.name())));
    }
}

std::map<std::string, navigation::datastructures::PositionalOffsets>
IInstallationParam::get_transducer_offsets() const
{
    std::map<std::string, navigation::datastructures::PositionalOffsets> offsets;

    for (auto& [key, value] : get_transducer_serial_numbers())
    {
        if (key == "TRX") // single head transceiver
        {
            offsets["TRX"] = get_transducer_offsets("TRAI_HD1");
            offsets["TRX"].name = fmt::format("TRX-{}", value);
        }
        else if (key == "TX")
        {
            offsets["TX"] = get_transducer_offsets("TRAI_TX1");
            offsets["TX"].name = fmt::format("TX-{}", value);
        }
        else if (key == "RX")
        {
            offsets["RX"] = get_transducer_offsets("TRAI_RX1");
            offsets["RX"].name = fmt::format("RX-{}", value);
        }
        else
        {
            throw(std::runtime_error(fmt::format(
                "Installation Parameters::get_transducer_offsets: unknown transducer key: {}",
                key)));
        }
    }

    return offsets;
}

// ----- processed data access -----

const std::map<std::string, std::string>& IInstallationParam::get_install_txt_key_infos()
{
    static const std::map<std::string, std::string> key_infos = {
        { "OSCV", "Operator Controller version" },
        { "EMXV", "Multi Beam System" },
        { "PU", "PU id type" },
        { "SN", "PU serial number" },
        { "IP", "IP address and subnet mask" },
        { "UDP", "Command TCPIP port" },
        { "TYPE", "CPU type" },
        { "VERSIONS", "SW versions for the system" },
        { "SERIALno", "Sonar head or transceiver serial numbers" },
        { "ParseError", "Line not correctly parsed" },
        { "DCL", "?" },
        { "KMALL", "KMALL format revision" },
        { "SYSTEM", "System and configuration" },
        { "TRAI_TX1", "Installation parameters transmitter 1" },
        { "TRAI_TX2", "Installation parameters transmitter 2" },
        { "TRAI_RX1", "Installation parameters receiver 1" },
        { "TRAI_RX2", "Installation parameters receiver 2" },
        { "TRAI_HD1", "Installation parameters transducer 1" },
        { "POSI_1", "Installation parameters position system 1" },
        { "POSI_2", "Installation parameters position system 2" },
        { "POSI_3", "Installation parameters position system 3" },
        { "POSI_4", "Installation parameters position system 4" },
        { "ATTI_1", "Installation parameters motion sensor 1" },
        { "ATTI_2", "Installation parameters motion sensor 2" },
        { "ATTI_3", "Installation parameters motion sensor 3" },
        { "ATTI_4", "Installation parameters motion sensor 4" },
        { "CLCK", "Installation parameters clock sensor" },
        { "DPHI", "Installation parameters depth/pressure sensor" },
        { "SVPI", "Installation parameters sound velocity probe" },
        { "EMXI", "Installation parameters and settings for system" },
    };
    return key_infos;
}

std::string IInstallationParam::get_install_txt_key_info(std::string_view key)
{
    const auto& key_infos = get_install_txt_key_infos();

    // First try exact match
    auto it = key_infos.find(std::string(key));
    if (it != key_infos.end())
    {
        return it->second;
    }

    // Check if key contains a prefix (e.g., "VERSIONS|something")
    static const std::array<std::string_view, 3> prefixes = { "ParseError",
                                                              "VERSIONS",
                                                              "SERIALno" };
    for (const auto& prefix : prefixes)
    {
        if (key.find(prefix) != std::string_view::npos)
        {
            auto prefix_it = key_infos.find(std::string(prefix));
            if (prefix_it != key_infos.end())
            {
                return prefix_it->second;
            }
        }
    }

    return "Unknown key";
}

std::map<std::string, std::string> IInstallationParam::get_install_txt_decoded() const
{
    return decode_install_txt(_install_txt);
}

std::map<std::string, std::string> IInstallationParam::decode_install_txt(
    std::string_view install_txt)
{
    std::map<std::string, std::string> values;

    // Helper to split a line by separator and optionally verify expected key
    auto split_fields = [](std::string_view                line,
                           char                            sep,
                           std::optional<std::string_view> expected,
                           size_t line_nr) -> std::pair<std::string, std::string> {
        auto pos = line.find(sep);
        if (pos == std::string_view::npos)
        {
            return { std::string(line), "" };
        }

        std::string key(line.substr(0, pos));
        std::string value(line.substr(pos + 1));

        if (expected.has_value() && key != expected.value())
        {
            throw std::runtime_error(
                fmt::format("ERROR parsing installation text!\n -fields[0] != {} but {}\n -full "
                            "line: \"{}\" [line nr {}]",
                            expected.value(),
                            key,
                            line,
                            line_nr));
        }

        return { key, value };
    };

    static const std::array<std::string_view, 3> prefixes = { "ParseError",
                                                              "VERSIONS",
                                                              "SERIALno" };
    std::string                                  current_prefix;

    // Split by comma
    std::vector<std::string> lines;
    boost::split(lines, install_txt, boost::is_any_of(","));

    for (size_t i = 0; i < lines.size(); ++i)
    {
        std::string line = lines[i];
        boost::trim(line);

        // Skip empty lines or null characters
        if (line.empty() || line == "\x00" ||
            line.find_first_not_of(" \t\r\n\0") == std::string::npos)
        {
            continue;
        }

        std::string name, value;

        switch (i)
        {
            case 0:
                std::tie(name, value) = split_fields(line, ':', "OSCV", i);
                values[name]          = value;
                break;
            case 1:
                std::tie(name, value) = split_fields(line, ':', "EMXV", i);
                values[name]          = value;
                break;
            case 2: {
                std::tie(name, value) = split_fields(line, '_', "PU", i);
                if (value == "0")
                    values[name] = "Stand alone";
                else if (value == "1")
                    values[name] = "Master";
                else if (value == "2")
                    values[name] = "Slave";
                else
                    throw std::runtime_error(
                        fmt::format("ERROR parsing installation text!\n Unknown value for PU "
                                    "type: {} Must be any of [0, 1, 2]\n -full line: \"{}\" [line "
                                    "nr {}]",
                                    value,
                                    line,
                                    i));
                break;
            }
            case 3:
                std::tie(name, value) = split_fields(line, '=', "SN", i);
                values[name]          = value;
                break;
            case 4:
                std::tie(name, value) = split_fields(line, '=', "IP", i);
                values[name]          = value;
                break;
            case 5:
                std::tie(name, value) = split_fields(line, '=', "UDP", i);
                values[name]          = value;
                break;
            case 6:
                std::tie(name, value) = split_fields(line, '=', "TYPE", i);
                values[name]          = value;
                break;
            default: {
                std::tie(name, value) = split_fields(line, ':', std::nullopt, i);

                // Check if this is a prefix start or end marker
                bool is_prefix_marker = false;
                for (const auto& pr : prefixes)
                {
                    if (name == pr)
                    {
                        current_prefix   = fmt::format("{}|", pr);
                        is_prefix_marker = true;
                        break;
                    }
                    else if (name == fmt::format("{}-END", pr))
                    {
                        current_prefix.clear();
                        is_prefix_marker = true;
                        break;
                    }
                }

                // if prefix does not end with :, we need to get the value from the same line
                if (is_prefix_marker && !value.empty())
                {
                    boost::trim(value);
                    std::tie(name, value) = split_fields(value, ':', std::nullopt, i);
                    is_prefix_marker      = false;
                }

                if (!is_prefix_marker)
                {
                    if (value.empty())
                    {
                        // Count existing parse errors
                        size_t n = 0;
                        for (const auto& [k, v] : values)
                        {
                            if (k.find("ParseError[") != std::string::npos)
                                ++n;
                        }
                        values[fmt::format("ParseError[{}]{}", n, current_prefix)] = name;
                    }
                    else
                    {
                        values[fmt::format("{}{}", current_prefix, name)] = value;
                    }
                }
                break;
            }
        }
    }

    return values;
}

// ----- sensor offset access -----

std::map<std::string, std::string> IInstallationParam::parse_sensor_string(
    std::string_view sensor_string)
{
    std::map<std::string, std::string> result;

    // Split by semicolon
    std::vector<std::string> parts;
    boost::split(parts, sensor_string, boost::is_any_of(";"));

    for (const auto& part : parts)
    {
        std::string trimmed = part;
        boost::trim(trimmed);
        if (trimmed.empty())
            continue;

        auto eq_pos = trimmed.find('=');
        if (eq_pos != std::string::npos)
        {
            std::string key   = trimmed.substr(0, eq_pos);
            std::string value = trimmed.substr(eq_pos + 1);
            boost::trim(key);
            boost::trim(value);
            result[key] = value;
        }
    }

    return result;
}

navigation::datastructures::PositionalOffsets IInstallationParam::get_transducer_offsets(
    const std::string& transducer_key) const
{
    using navigation::datastructures::PositionalOffsets;
    using tools::helper::string_to_floattype;

    auto decoded = get_install_txt_decoded_cached();

    auto it = decoded.find(transducer_key);
    if (it == decoded.end())
    {
        throw std::invalid_argument(
            fmt::format("get_transducer_offsets: Key not found: {}", transducer_key));
    }

    auto params = parse_sensor_string(it->second);

    float       x = 0.f, y = 0.f, z = 0.f;
    float       yaw = 0.f, pitch = 0.f, roll = 0.f;
    std::string name = transducer_key;

    // Get name from N field if available (serial number)
    if (params.count("N"))
        name = fmt::format("{} (SN: {})", transducer_key, params["N"]);
    // Or from W field (model info)
    if (params.count("W"))
        name = fmt::format("{} ({})", transducer_key, params["W"]);

    if (params.count("X"))
        x = string_to_floattype<float>(params["X"]);
    if (params.count("Y"))
        y = string_to_floattype<float>(params["Y"]);
    if (params.count("Z"))
        z = string_to_floattype<float>(params["Z"]);
    if (params.count("H"))
        yaw = string_to_floattype<float>(params["H"]);
    if (params.count("P"))
        pitch = string_to_floattype<float>(params["P"]);
    if (params.count("R"))
        roll = string_to_floattype<float>(params["R"]);

    return PositionalOffsets(name, x, y, z, yaw, pitch, roll);
}

navigation::datastructures::PositionalOffsets IInstallationParam::get_position_system_offsets(
    uint8_t position_system_number) const
{
    using navigation::datastructures::PositionalOffsets;
    using tools::helper::string_to_floattype;

    if (position_system_number < 1 || position_system_number > 4)
    {
        throw std::invalid_argument(fmt::format(
            "get_position_system_offsets: Invalid position system number: {} (must be 1-4)",
            position_system_number));
    }

    std::string key     = fmt::format("POSI_{}", position_system_number);
    auto        decoded = get_install_txt_decoded_cached();

    auto it = decoded.find(key);
    if (it == decoded.end())
    {
        throw std::invalid_argument(
            fmt::format("get_position_system_offsets: Key not found: {}", key));
    }

    // Check if set
    if (it->second == "U=NOT_SET" || it->second.find("NOT_SET") != std::string::npos)
    {
        throw std::invalid_argument(fmt::format(
            "get_position_system_offsets: Position system {} is not set", position_system_number));
    }

    auto params = parse_sensor_string(it->second);

    float       x = 0.f, y = 0.f, z = 0.f;
    std::string name = fmt::format("Position system {}", position_system_number);

    if (params.count("X"))
        x = string_to_floattype<float>(params["X"]);
    if (params.count("Y"))
        y = string_to_floattype<float>(params["Y"]);
    if (params.count("Z"))
        z = string_to_floattype<float>(params["Z"]);

    return PositionalOffsets(name, x, y, z, 0.f, 0.f, 0.f);
}

navigation::datastructures::PositionalOffsets IInstallationParam::get_attitude_sensor_offsets(
    uint8_t sensor_number) const
{
    using navigation::datastructures::PositionalOffsets;
    using tools::helper::string_to_floattype;

    if (sensor_number < 1 || sensor_number > 4)
    {
        throw std::invalid_argument(fmt::format(
            "get_attitude_sensor_offsets: Invalid sensor number: {} (must be 1-4)", sensor_number));
    }

    std::string key     = fmt::format("ATTI_{}", sensor_number);
    auto        decoded = get_install_txt_decoded_cached();

    auto it = decoded.find(key);
    if (it == decoded.end())
    {
        throw std::invalid_argument(
            fmt::format("get_attitude_sensor_offsets: Key not found: {}", key));
    }

    // Check if set
    if (it->second == "NOT_SET" || it->second == "U=NOT_SET" ||
        it->second.find("NOT_SET") != std::string::npos)
    {
        throw std::invalid_argument(fmt::format(
            "get_attitude_sensor_offsets: Attitude sensor {} is not set", sensor_number));
    }

    auto params = parse_sensor_string(it->second);

    float       x = 0.f, y = 0.f, z = 0.f;
    float       yaw = 0.f, pitch = 0.f, roll = 0.f;
    std::string name = fmt::format("Attitude sensor {}", sensor_number);

    if (params.count("X"))
        x = string_to_floattype<float>(params["X"]);
    if (params.count("Y"))
        y = string_to_floattype<float>(params["Y"]);
    if (params.count("Z"))
        z = string_to_floattype<float>(params["Z"]);
    if (params.count("H"))
        yaw = string_to_floattype<float>(params["H"]);
    if (params.count("P"))
        pitch = string_to_floattype<float>(params["P"]);
    if (params.count("R"))
        roll = string_to_floattype<float>(params["R"]);

    return PositionalOffsets(name, x, y, z, yaw, pitch, roll);
}

navigation::datastructures::PositionalOffsets IInstallationParam::get_depth_sensor_offsets() const
{
    using navigation::datastructures::PositionalOffsets;
    using tools::helper::string_to_floattype;

    auto decoded = get_install_txt_decoded_cached();

    auto it = decoded.find("DPHI");
    if (it == decoded.end())
    {
        throw std::invalid_argument("get_depth_sensor_offsets: DPHI key not found");
    }

    // Check if set
    if (it->second == "U=NOT_SET" || it->second.find("NOT_SET") != std::string::npos)
    {
        throw std::invalid_argument("get_depth_sensor_offsets: Depth sensor is not set");
    }

    auto params = parse_sensor_string(it->second);

    float x = 0.f, y = 0.f, z = 0.f;

    if (params.count("X"))
        x = string_to_floattype<float>(params["X"]);
    if (params.count("Y"))
        y = string_to_floattype<float>(params["Y"]);
    if (params.count("Z"))
        z = string_to_floattype<float>(params["Z"]);

    return PositionalOffsets("Depth sensor", x, y, z, 0.f, 0.f, 0.f);
}

float IInstallationParam::get_water_line_vertical_location_in_meters() const
{
    using tools::helper::string_to_floattype;

    auto decoded = get_install_txt_decoded_cached();

    auto it = decoded.find("EMXI");
    if (it == decoded.end())
    {
        return 0.f;
    }

    auto params = parse_sensor_string(it->second);

    if (params.count("SWLZ"))
        return string_to_floattype<float>(params["SWLZ"]);

    return 0.f;
}

int8_t IInstallationParam::get_active_position_system_number() const
{
    auto decoded = get_install_txt_decoded_cached();

    // Check each position system for U=ACTIVE
    for (uint8_t i = 1; i <= 4; ++i)
    {
        std::string key = fmt::format("POSI_{}", i);
        auto        it  = decoded.find(key);
        if (it != decoded.end())
        {
            auto params = parse_sensor_string(it->second);
            if (params.count("U") && params["U"] == "ACTIVE")
            {
                return i - 1;
            }
        }
    }

    return -1; // None active
}

int8_t IInstallationParam::get_active_attitude_sensor_number() const
{
    auto decoded = get_install_txt_decoded_cached();

    // Check each attitude sensor for U=ACTIVE
    for (uint8_t i = 1; i <= 4; ++i)
    {
        std::string key = fmt::format("ATTI_{}", i);
        auto        it  = decoded.find(key);
        if (it != decoded.end())
        {
            auto params = parse_sensor_string(it->second);
            if (params.count("U") && params["U"] == "ACTIVE")
            {
                return i - 1;
            }
        }
    }

    return -1; // None active
}

std::string IInstallationParam::get_system_name() const
{
    auto decoded = get_install_txt_decoded_cached();

    auto it = decoded.find("EMXV");
    if (it != decoded.end())
    {
        return it->second;
    }

    return "";
}

int IInstallationParam::get_pu_serial_number() const
{
    auto decoded = get_install_txt_decoded_cached();

    auto it = decoded.find("SN");
    if (it != decoded.end())
    {
        return std::stoi(it->second);
    }

    return 0;
}

std::vector<std::string> IInstallationParam::get_available_transducer_keys() const
{
    auto                     decoded = get_install_txt_decoded_cached();
    std::vector<std::string> keys;

    // Check all possible transducer keys
    static const std::array<std::string, 5> possible_keys = {
        "TRAI_HD1", "TRAI_TX1", "TRAI_TX2", "TRAI_RX1", "TRAI_RX2"
    };

    for (const auto& key : possible_keys)
    {
        if (decoded.contains(key))
        {
            keys.push_back(key);
        }
    }

    return keys;
}

bool IInstallationParam::has_transducer_key(const std::string& key) const
{
    auto decoded = get_install_txt_decoded_cached();
    return decoded.contains(key);
}

// ----- to/from stream functions -----
void IInstallationParam::__read__(std::istream& is)
{
    static constexpr size_t dbytes = 3 * sizeof(uint16_t) + sizeof(uint32_t);

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(_bytes_content)), 3 * sizeof(uint16_t));

    _install_txt.resize(compute_size_content() - dbytes); // minus size of the previous fields
    is.read(_install_txt.data(), _install_txt.size());
    is.read(reinterpret_cast<char*>(&(_bytes_datagram_check)), sizeof(_bytes_datagram_check));

    cache_install_txt_decoded();
}

IInstallationParam IInstallationParam::from_stream(std::istream& is, const KMALLDatagram& header)
{
    IInstallationParam datagram(header);
    datagram.__read__(is);

    return datagram;
}

IInstallationParam IInstallationParam::from_stream(std::istream&             is,
                                                   o_KMALLDatagramIdentifier datagram_identifier)
{
    IInstallationParam datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__check_datagram_identifier__(datagram_identifier, DatagramIdentifier);
    datagram.__read__(is);
    return datagram;
}

IInstallationParam IInstallationParam::from_stream(std::istream& is)
{
    IInstallationParam datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read__(is);
    return datagram;
}

void IInstallationParam::to_stream(std::ostream& os) const
{
    KMALLDatagram::to_stream(os);

    // TODO: verify sizes and alignments before writing

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&_bytes_content), 3 * sizeof(uint16_t));
    // write the installation paramaters string
    os.write(reinterpret_cast<const char*>(_install_txt.data()),
             _install_txt.size() * sizeof(char));
    os.write(reinterpret_cast<const char*>(&_bytes_datagram_check), sizeof(_bytes_datagram_check));
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter IInstallationParam::__printer__(unsigned int float_precision,
                                                                  bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "IInstallationParam", float_precision, superscript_exponents);

    printer.append(KMALLDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("bytes_content", _bytes_content);
    printer.register_value("info", _info);
    printer.register_value("status", _status);
    printer.register_value("bytes datagram check", _bytes_datagram_check, "bytes");
    printer.register_section("install_txt");
    printer.register_string("install_txt", _install_txt);

    if (_cached_install_txt_decoded.has_value())
    {
        printer.register_section("decoded install_txt");
        for (const auto& [key, value] : *_cached_install_txt_decoded)
        {
            printer.register_string(key, value);
        }
    }

    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
