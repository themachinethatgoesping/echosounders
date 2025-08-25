// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xml_configuration_sensor_telegram.hpp"

// std
#include <cstring>
#include <iostream>

// fmt
#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

// ----- constructors -----
XML_Configuration_Sensor_Telegram::XML_Configuration_Sensor_Telegram(const pugi::xml_node& node)
{
    initialize(node);
}

// ----- initialization -----
void XML_Configuration_Sensor_Telegram::initialize(const pugi::xml_node& root_node)
{
    if (std::strcmp(root_node.name(), "Telegram") != 0)
    {
        throw std::runtime_error(
            std::string("XML_Configuration_Sensor_Telegram: wrong root node type '") +
            root_node.name() + "'");
    }
    unknown_attributes = 0;
    unknown_children   = 0;
    Values.clear();

    // children (only <Value>)
    for (const auto& node : root_node.children())
    {
        if (std::strcmp(node.name(), "Value") != 0)
        {
            std::cerr << "WARNING: [Configuration_Sensor_Telegram] Unknown child: " << node.name()
                      << std::endl;
            unknown_children = 1;
            continue;
        }
        Values.emplace_back(node);
    }

    // attributes
    for (auto& attr : root_node.attributes())
    {
        std::string_view name = attr.name();
        if (name == "Enabled")
        {
            Enabled = std::stoi(attr.value());
            continue;
        }
        if (name == "SubscriptionPath")
        {
            SubscriptionPath = attr.value();
            continue;
        }
        if (name == "Type")
        {
            Type = attr.value();
            continue;
        }
        if (name == "SensorType")
        {
            SensorType = attr.value();
            continue;
        }
        if (name == "Name")
        {
            Name = attr.value();
            continue;
        }

        std::cerr << "WARNING: [Configuration_Sensor_Telegram] Unknown attribute: " << name
                  << std::endl;
        unknown_attributes += 1;
    }
}

bool XML_Configuration_Sensor_Telegram::parsed_completely() const
{
    return unknown_children == 0 && unknown_attributes == 0;
}

// ----- file I/O -----
XML_Configuration_Sensor_Telegram XML_Configuration_Sensor_Telegram::from_stream(std::istream& is)
{
    XML_Configuration_Sensor_Telegram xml;

    is.read(reinterpret_cast<char*>(&xml.Enabled), sizeof(xml.Enabled));
    xml.SubscriptionPath = tools::classhelper::stream::container_from_stream<std::string>(is);
    xml.Type             = tools::classhelper::stream::container_from_stream<std::string>(is);
    xml.SensorType       = tools::classhelper::stream::container_from_stream<std::string>(is);
    xml.Name             = tools::classhelper::stream::container_from_stream<std::string>(is);

    size_t size{};
    is.read(reinterpret_cast<char*>(&size), sizeof(size));
    xml.Values.resize(size);
    for (auto& value : xml.Values)
        value = XML_Configuration_Sensor_TelegramValue::from_stream(is);

    is.read(reinterpret_cast<char*>(&xml.unknown_children), sizeof(xml.unknown_children));
    is.read(reinterpret_cast<char*>(&xml.unknown_attributes), sizeof(xml.unknown_attributes));

    return xml;
}

void XML_Configuration_Sensor_Telegram::to_stream(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(&Enabled), sizeof(Enabled));
    tools::classhelper::stream::container_to_stream(os, SubscriptionPath);
    tools::classhelper::stream::container_to_stream(os, Type);
    tools::classhelper::stream::container_to_stream(os, SensorType);
    tools::classhelper::stream::container_to_stream(os, Name);

    size_t size = Values.size();
    os.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const auto& value : Values)
        value.to_stream(os);

    os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
    os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
}

// ----- operators -----
bool XML_Configuration_Sensor_Telegram::operator==(
    const XML_Configuration_Sensor_Telegram& other) const
{
    return Enabled == other.Enabled && SubscriptionPath == other.SubscriptionPath &&
           Type == other.Type && SensorType == other.SensorType && Name == other.Name &&
           Values == other.Values;
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter XML_Configuration_Sensor_Telegram::__printer__(
    unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("EK80 XML0 Configuration_Sensor_Telegram",
                                              float_precision,
                                              superscript_exponents);

    if (!Values.empty())
    {
        printer.register_section("children (Values)");
        for (const auto& value : Values)
        {
            printer.register_value(
                "Value", value.Name, fmt::format("Priority {}", value.Priority));
        }
    }

    printer.register_section("attributes");
    printer.register_value("Enabled", Enabled);
    printer.register_string("SubscriptionPath", SubscriptionPath);
    printer.register_string("Type", Type);
    printer.register_string("Name", Name);

    return printer;
}

} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
