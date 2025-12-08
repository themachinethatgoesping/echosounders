// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "iopruntime.hpp"

#include <fmt/format.h>

#include <algorithm>
#include <array>
#include <stdexcept>
#include <utility>

#include <boost/algorithm/string.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

IOpRuntime::IOpRuntime()
{
    _datagram_identifier = DatagramIdentifier;
}
// ----- getters -----
uint16_t IOpRuntime::get_bytes_content() const
{
    return _bytes_content;
}

uint16_t IOpRuntime::get_info() const
{
    return _info;
}

uint16_t IOpRuntime::get_status() const
{
    return _status;
}

const std::string& IOpRuntime::get_runtime_txt() const
{
    return _runtime_txt;
}

uint32_t IOpRuntime::get_bytes_datagram_check() const
{
    return _bytes_datagram_check;
}

// setters
// void IOpRuntime::set_bytes_content(uint16_t bytes_content) {
//     _bytes_content = bytes_content;
// }

void IOpRuntime::set_info(uint16_t info)
{
    _info = info;
}

void IOpRuntime::set_status(uint16_t status)
{
    _status = status;
}

void IOpRuntime::set_runtime_txt(std::string_view runtime_txt)
{
    static constexpr size_t dbytes = 3 * sizeof(uint16_t) + sizeof(uint32_t);

    _bytes_content = dbytes + runtime_txt.size() * sizeof(char); // size of the string in bytes

    _runtime_txt.assign(runtime_txt.begin(), runtime_txt.end());

    // increase _bytes_content to 4 byte alignment
    if (_bytes_content % 4 != 0)
    {
        _bytes_content += 4 - (_bytes_content % 4);
    }

    _runtime_txt.resize(_bytes_content - dbytes, '\0'); // pad with null characters
    set_bytes_datagram(KMALLDatagram::__size + _bytes_content);
    _bytes_datagram_check = get_bytes_datagram();
}

// ----- processed data access -----

const std::map<std::string, std::string>& IOpRuntime::get_runtime_txt_key_infos()
{
    static const std::map<std::string, std::string> key_infos = {
        { "Sector coverage", "Sector coverage settings section" },
        { "Max angle Port", "Maximum angle on port side (degrees)" },
        { "Max angle Starboard", "Maximum angle on starboard side (degrees)" },
        { "Max coverage Port", "Maximum coverage on port side (meters)" },
        { "Max coverage Starboard", "Maximum coverage on starboard side (meters)" },
        { "Angular coverage Mode", "Angular coverage mode (Auto/Manual)" },
        { "Sector mode", "Sector mode setting" },
        { "Beam spacing", "Beam spacing mode" },
        { "Depth settings", "Depth settings section" },
        { "Forced depth", "Forced depth value (meters)" },
        { "Min. depth", "Minimum depth (meters)" },
        { "Max. depth", "Maximum depth (meters)" },
        { "Dual swath", "Dual swath mode (On/Off)" },
        { "Depth mode", "Depth mode setting" },
        { "Frequency", "Operating frequency" },
        { "Detector mode", "Detector mode setting" },
        { "FM disable", "FM disable setting (On/Off)" },
        { "Water column data", "Water column data (On/Off)" },
        { "Transmit Control", "Transmit control settings section" },
        { "Pitch stabilisation", "Pitch stabilisation (On/Off)" },
        { "Transmit angle Along", "Transmit angle along (degrees)" },
        { "Max. Ping Freq. (Hz)", "Maximum ping frequency (Hz)" },
        { "Min. Swath Dist.", "Minimum swath distance" },
        { "External Trigger", "External trigger (On/Off)" },
        { "Yaw Stabilisation Mode", "Yaw stabilisation mode (On/Off)" },
        { "Sound velocity at Transducer", "Sound velocity at transducer section" },
        { "Sound Velocity source", "Sound velocity source" },
        { "Sensor Offset", "Sensor offset value" },
        { "Filter", "Filter setting" },
        { "Filtering", "Filtering settings section" },
        { "Spike filter strength", "Spike filter strength" },
        { "Range gate size", "Range gate size" },
        { "Phase ramp", "Phase ramp setting" },
        { "Penetration Filter Strength", "Penetration filter strength" },
        { "Special TVG", "Special TVG (On/Off)" },
        { "Slope", "Slope setting (On/Off)" },
        { "Aeration", "Aeration (On/Off)" },
        { "Interference", "Interference (On/Off)" },
        { "Special amp detection", "Special amplitude detection (On/Off)" },
        { "Backscatter Adjustment", "Backscatter adjustment section" },
        { "Normal incidence corr.", "Normal incidence correction (degrees)" },
        { "Use Lambert's law", "Use Lambert's law (On/Off)" },
        { "TX Power", "TX power settings section" },
        { "Transmit power level", "Transmit power level" },
        { "Water Column", "Water column settings" },
        { "Water column", "Water column parameter" },
        { "Water phase data", "Water phase data (On/Off)" },
        { "Special Mode", "Special mode settings section" },
        { "Sonar mode", "Sonar mode (On/Off)" },
        { "Passive", "Passive mode (On/Off)" },
        { "Extra Detections", "Extra detections settings section" },
        { "Extra detection", "Extra detection (On/Off)" },
        { "Simulation setup", "Simulation setup section" },
        { "Enable Simulation", "Enable simulation (On/Off)" },
        { "Scope Display", "Scope display settings section" },
        { "Scope display enabled", "Scope display enabled (On/Off)" },
    };
    return key_infos;
}

std::string IOpRuntime::get_runtime_txt_key_info(std::string_view key)
{
    const auto& key_infos = get_runtime_txt_key_infos();

    auto it = key_infos.find(std::string(key));
    if (it != key_infos.end())
    {
        return it->second;
    }

    return "Unknown key";
}

std::map<std::string, std::string> IOpRuntime::get_runtime_txt_decoded() const
{
    return decode_runtime_txt(_runtime_txt);
}

std::map<std::string, std::string> IOpRuntime::decode_runtime_txt(std::string_view runtime_txt)
{
    std::map<std::string, std::string> values;

    // Section headers that don't have a colon but define a section
    static const std::array<std::string_view, 14> section_headers = {
        "Sector coverage",
        "Depth settings",
        "Transmit Control",
        "Sound velocity at Transducer",
        "Filtering",
        "Backscatter Adjustment",
        "TX Power",
        "Special Mode",
        "Extra Detections",
        "Simulation setup",
        "Scope Display",
        "RX in use",
        "Ping Mode",
        "Pulse Mode",
    };

    std::string current_section;

    // Split by newline
    std::vector<std::string> lines;
    boost::split(lines, runtime_txt, boost::is_any_of("\n"));

    for (const auto& raw_line : lines)
    {
        std::string line = raw_line;
        boost::trim(line);

        // Skip empty lines or null characters
        if (line.empty() || line.find_first_not_of(" \t\r\n\0") == std::string::npos)
        {
            continue;
        }

        // Check if this is a section header (no colon, matches known headers)
        bool is_section_header = false;
        for (const auto& header : section_headers)
        {
            if (line == header)
            {
                current_section  = std::string(header);
                is_section_header = true;
                // Add section marker to values
                values[fmt::format("[Section] {}", current_section)] = "";
                break;
            }
        }

        if (is_section_header)
        {
            continue;
        }

        // Skip table headers like "Class   Start  Stop  Quality..."
        if (line.find("Class") == 0 && line.find("Start") != std::string::npos &&
            line.find("Stop") != std::string::npos)
        {
            continue;
        }

        // Skip numbered rows from extra detections table (e.g., "1  Off   5.0   10.0...")
        if (!line.empty() && std::isdigit(static_cast<unsigned char>(line[0])))
        {
            // Check if it looks like a table row (starts with digit followed by spaces and more fields)
            auto first_space = line.find(' ');
            if (first_space != std::string::npos && first_space <= 2)
            {
                std::string rest = line.substr(first_space);
                boost::trim(rest);
                if (rest.find("Off") == 0 || rest.find("On") == 0)
                {
                    // This is a table row, store it with row number
                    std::string row_num = line.substr(0, first_space);
                    values[fmt::format("Extra Detections|Class {}", row_num)] = rest;
                    continue;
                }
            }
        }

        // Find the colon separator
        auto colon_pos = line.find(':');
        if (colon_pos == std::string::npos)
        {
            // No colon - could be a standalone value or unknown format
            // Add it as a parse note
            size_t n = 0;
            for (const auto& [k, v] : values)
            {
                if (k.find("ParseNote[") != std::string::npos)
                    ++n;
            }
            values[fmt::format("ParseNote[{}]", n)] = line;
            continue;
        }

        // Split by colon
        std::string key   = line.substr(0, colon_pos);
        std::string value = line.substr(colon_pos + 1);
        boost::trim(key);
        boost::trim(value);

        // Handle special case where value might be empty (like "Water Column:")
        // or where the key itself could be a section-like entry
        if (!key.empty())
        {
            // Build the full key with section prefix if appropriate
            std::string full_key;
            if (!current_section.empty() && !key.empty())
            {
                full_key = fmt::format("{}|{}", current_section, key);
            }
            else
            {
                full_key = key;
            }

            values[full_key] = value;
        }
    }

    return values;
}

// ----- to/from stream functions -----
void IOpRuntime::__read__(std::istream& is)
{
    static constexpr size_t dbytes = 3 * sizeof(uint16_t) + sizeof(uint32_t);

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(_bytes_content)), 3 * sizeof(uint16_t));

    _runtime_txt.resize(compute_size_content() - dbytes); // minus size of the previous fields
    is.read(_runtime_txt.data(), _runtime_txt.size());
    is.read(reinterpret_cast<char*>(&(_bytes_datagram_check)), sizeof(_bytes_datagram_check));
}

IOpRuntime IOpRuntime::from_stream(std::istream& is, const KMALLDatagram& header)
{
    IOpRuntime datagram(header);
    datagram.__read__(is);

    return datagram;
}

IOpRuntime IOpRuntime::from_stream(std::istream& is, o_KMALLDatagramIdentifier datagram_identifier)
{
    IOpRuntime datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__check_datagram_identifier__(datagram_identifier, DatagramIdentifier);
    datagram.__read__(is);
    return datagram;
}

IOpRuntime IOpRuntime::from_stream(std::istream& is)
{
    IOpRuntime datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read__(is);
    return datagram;
}

void IOpRuntime::to_stream(std::ostream& os) const
{
    KMALLDatagram::to_stream(os);

    // TODO: verify sizes and alignments before writing

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&_bytes_content), 3 * sizeof(uint16_t));
    // write the installation paramaters string
    os.write(reinterpret_cast<const char*>(_runtime_txt.data()),
             _runtime_txt.size() * sizeof(char));
    os.write(reinterpret_cast<const char*>(&_bytes_datagram_check), sizeof(_bytes_datagram_check));
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter IOpRuntime::__printer__(unsigned int float_precision,
                                                          bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("IOpRuntime", float_precision, superscript_exponents);

    printer.append(KMALLDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("bytes_content", _bytes_content);
    printer.register_value("info", _info);
    printer.register_value("status", _status);
    printer.register_value("bytes datagram check", _bytes_datagram_check, "bytes");
    printer.register_section("runtime_txt");
    printer.register_string("runtime_txt", _runtime_txt);
    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
