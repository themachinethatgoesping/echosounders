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

// ----- to/from stream functions -----
void IInstallationParam::__read__(std::istream& is)
{
    static constexpr size_t dbytes = 3 * sizeof(uint16_t) + sizeof(uint32_t);

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(_bytes_content)), 3 * sizeof(uint16_t));

    _install_txt.resize(compute_size_content() - dbytes); // minus size of the previous fields
    is.read(_install_txt.data(), _install_txt.size());
    is.read(reinterpret_cast<char*>(&(_bytes_datagram_check)), sizeof(_bytes_datagram_check));
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
    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
