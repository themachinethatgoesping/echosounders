// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string/find.hpp>

#include <pugixml.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelpers/stream.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "helper.hpp"
#include "xml_configuration_activepingmode.hpp"
#include "xml_configuration_sensor.hpp"
#include "xml_configuration_transducer.hpp"
#include "xml_configuration_transceiver.hpp"
#include "xml_node.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {
namespace xml_datagrams {

/**
 * @brief XML base datagram
 *
 */
struct XML_Configuration
{
    // Header attributes
    std::string FileFormatVersion;
    std::string Version;
    std::string TimeBias;
    std::string ApplicationName;
    std::string Copyright;

    std::vector<XML_Configuration_Sensor>     ConfiguredSensors;
    std::vector<XML_Configuration_Transducer> Transducers;
    std::vector<XML_Configuration_Transceiver>                     Transceivers;
    XML_Configuration_ActivePingMode          ActivePingMode;

    int32_t unknown_children   = 0;
    int32_t unknown_attributes = 0;

  public:
    // ----- constructors -----
    XML_Configuration() = default;
    XML_Configuration(const pugi::xml_node& node) { initialize(node); }
    ~XML_Configuration() = default;

    void initialize(const pugi::xml_node& root_node)
    {
        if (strcmp(root_node.name(), "Configuration"))
        {
            throw std::runtime_error(std::string("XML_Configuration: wrong root node type '") +
                                     root_node.name() + "'");
        }
        unknown_attributes = 0;
        unknown_children   = 0; // there should only be one child for this node

        // there should only be one child for this node
        for (const auto& node : root_node.children())
        {
            if (!strcmp(node.name(), "ConfiguredSensors"))
            {
                for (const auto& sensor_node : node.children())
                {
                    ConfiguredSensors.emplace_back(sensor_node);
                }
                for (const auto& attr : node.attributes())
                {
                    if (!strcmp(attr.name(), "MergeOperation"))
                    {
                        continue;
                    }

                    ++unknown_attributes;
                    std::cerr << "WARNING: [Configuration/ConfiguredSensors] Unknown Attribute: "
                              << attr.name() << std::endl;
                }

                continue;
            }
            else if (!strcmp(node.name(), "Transducers"))
            {
                for (const auto& sensor_node : node.children())
                {
                    Transducers.emplace_back(sensor_node);
                }
                for (const auto& attr : node.attributes())
                {
                    if (!strcmp(attr.name(), "MergeOperation"))
                    {
                        continue;
                    }

                    ++unknown_attributes;
                    std::cerr << "WARNING: [Configuration/Transducers] Unknown Attribute: "
                              << attr.name() << std::endl;
                }

                continue;
            }
            else if (!strcmp(node.name(), "Transceivers"))
            {
                for (const auto& sensor_node : node.children())
                {
                    Transceivers.emplace_back(sensor_node);
                }
                for (const auto& attr : node.attributes())
                {
                    if (!strcmp(attr.name(), "MergeOperation"))
                    {
                        continue;
                    }

                    ++unknown_attributes;
                    std::cerr << "WARNING: [Configuration/Transceivers] Unknown Attribute: "
                              << attr.name() << std::endl;
                }

                continue;
            }
            else if (!strcmp(node.name(), "ActivePingMode"))
            {
                if (!ActivePingMode.Mode.empty())
                {
                    ++unknown_children;
                    std::cerr << "WARNING: [Configuration/ActivePingMode] More than one ActivePingMode element!: "
                              << node.name() << std::endl;

                    continue;
                }

                ActivePingMode = XML_Configuration_ActivePingMode(node);
                
                continue;
            }
            else if (!strcmp(node.name(), "Header"))
            {
                for (const auto& header_node : node.children())
                {
                    ++unknown_children;
                    std::cerr << "WARNING: [Configuration/THeader] Unknown children: "
                              << header_node.name() << std::endl;
                }
                for (const auto& attr : node.attributes())
                {
                    if (!strcmp(attr.name(), "FileFormatVersion"))
                    {
                        FileFormatVersion = attr.value();
                        continue;
                    }
                    else if (!strcmp(attr.name(), "Version"))
                    {
                        Version = attr.value();
                        continue;
                    }
                    else if (!strcmp(attr.name(), "TimeBias"))
                    {
                        TimeBias = attr.value();
                        continue;
                    }
                    else if (!strcmp(attr.name(), "ApplicationName"))
                    {
                        ApplicationName = attr.value();
                        continue;
                    }
                    else if (!strcmp(attr.name(), "Copyright"))
                    {
                        Copyright = attr.value();
                        continue;
                    }

                    ++unknown_attributes;
                    std::cerr << "WARNING: [Configuration/Header] Unknown Attribute: "
                              << attr.name() << std::endl;
                }

                continue;
            }

            std::cerr << "WARNING: [Configuration] Unknown child: " << node.name() << std::endl;

            ++unknown_children;
        }
    }

    bool parsed_completely() const { return unknown_children == 0 && unknown_attributes == 0; }

    // ----- file I/O -----
    static XML_Configuration from_stream(std::istream& is)
    {
        XML_Configuration xml;

        xml.FileFormatVersion = tools::classhelpers::stream::container_from_stream<std::string>(is);
        xml.Version           = tools::classhelpers::stream::container_from_stream<std::string>(is);
        xml.TimeBias          = tools::classhelpers::stream::container_from_stream<std::string>(is);
        xml.ApplicationName   = tools::classhelpers::stream::container_from_stream<std::string>(is);
        xml.Copyright         = tools::classhelpers::stream::container_from_stream<std::string>(is);

        size_t size;

        is.read(reinterpret_cast<char*>(&size), sizeof(size));
        xml.ConfiguredSensors.resize(size);
        for (auto& node : xml.ConfiguredSensors)
        {
            node = XML_Configuration_Sensor::from_stream(is);
        }

        is.read(reinterpret_cast<char*>(&size), sizeof(size));
        xml.Transducers.resize(size);
        for (auto& node : xml.Transducers)
        {
            node = XML_Configuration_Transducer::from_stream(is);
        }

        is.read(reinterpret_cast<char*>(&size), sizeof(size));
        xml.Transceivers.resize(size);
        for (auto& node : xml.Transceivers)
        {
            node = XML_Configuration_Transceiver::from_stream(is);
        }

        xml.ActivePingMode = XML_Configuration_ActivePingMode::from_stream(is);

        return xml;
    }

    void to_stream(std::ostream& os) const
    {
        tools::classhelpers::stream::container_to_stream(os, FileFormatVersion);
        tools::classhelpers::stream::container_to_stream(os, Version);
        tools::classhelpers::stream::container_to_stream(os, TimeBias);
        tools::classhelpers::stream::container_to_stream(os, ApplicationName);
        tools::classhelpers::stream::container_to_stream(os, Copyright);

        size_t size;

        size = ConfiguredSensors.size();
        os.write(reinterpret_cast<const char*>(&size), sizeof(size));
        for (const auto& node : ConfiguredSensors)
        {
            node.to_stream(os);
        }

        size = Transducers.size();
        os.write(reinterpret_cast<const char*>(&size), sizeof(size));
        for (const auto& node : Transducers)
        {
            node.to_stream(os);
        }

        size = Transceivers.size();
        os.write(reinterpret_cast<const char*>(&size), sizeof(size));
        for (const auto& node : Transceivers)
        {
            node.to_stream(os);
        }

        ActivePingMode.to_stream(os);
    }

    // ----- operators -----
    bool operator==(const XML_Configuration& other) const
    {
        return ConfiguredSensors == other.ConfiguredSensors && Transducers == other.Transducers
            && Transceivers == other.Transceivers && ActivePingMode == other.ActivePingMode
            && FileFormatVersion == other.FileFormatVersion && Version == other.Version
            && TimeBias == other.TimeBias && ApplicationName == other.ApplicationName;
    }
    bool operator!=(const XML_Configuration& other) const { return !operator==(other); }

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("EK80 XML0 Parameter Channel", float_precision);
        printer.register_section("children");
        printer.register_value("ConfiguredSensors", ConfiguredSensors.size());
        printer.register_value("Transducers", Transducers.size());
        printer.register_value("Transceivers", Transceivers.size());
        if(!ActivePingMode.Mode.empty())
        {
            printer.register_value("ActivePingMode", ActivePingMode.Mode);
        }

        printer.register_section("attributes (Header)");
        printer.register_string("FileFormatVersion", FileFormatVersion);
        printer.register_string("Version", Version);
        printer.register_string("TimeBias", TimeBias);
        printer.register_string("ApplicationName", ApplicationName);
        printer.register_string("Copyright", Copyright);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(XML_Configuration)
};

}
}
}
}
}