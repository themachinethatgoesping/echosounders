#include "xml_configuration_sensor_telegramvalue.hpp"

// std
#include <cstring>
#include <iostream>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/stream.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

// ----- constructors -----
XML_Configuration_Sensor_TelegramValue::XML_Configuration_Sensor_TelegramValue(
    const pugi::xml_node& node)
{
    initialize(node);
}

// ----- initialization -----
void XML_Configuration_Sensor_TelegramValue::initialize(const pugi::xml_node& root_node)
{
    if (std::strcmp(root_node.name(), "Value") != 0)
    {
        throw std::runtime_error(
            std::string("XML_Configuration_Sensor_TelegramValue: wrong root node type '") +
            root_node.name() + "'");
    }
    unknown_attributes = 0;
    unknown_children   = 0; // there should be no child

    // there should only be one child for this node
    for (const auto& node : root_node.children())
    {
        std::cerr << "WARNING: [Value] Unknown child: " << node.name() << std::endl;
        unknown_children = 1;
    }

    for (const auto& attr : root_node.attributes())
    {
        std::string_view name = attr.name();
        if (name == "Priority")
        {
            Priority = std::stoi(attr.value()); // TODO: is this only 0/1 or also false/true?
            continue;
        }
        if (name == "Name")
        {
            Name = attr.value();
            continue;
        }
        std::cerr << "WARNING: [Value] Unknown attribute: " << name << std::endl;
        unknown_attributes += 1;
    }
}

bool XML_Configuration_Sensor_TelegramValue::parsed_completely() const
{
    return unknown_children == 0 && unknown_attributes == 0;
}

// ----- file I/O -----
XML_Configuration_Sensor_TelegramValue XML_Configuration_Sensor_TelegramValue::from_stream(
    std::istream& is)
{
    XML_Configuration_Sensor_TelegramValue xml;
    is.read(reinterpret_cast<char*>(&xml.Priority), sizeof(xml.Priority));
    xml.Name = tools::classhelper::stream::container_from_stream<std::string>(is);

    is.read(reinterpret_cast<char*>(&xml.unknown_children), sizeof(xml.unknown_children));
    is.read(reinterpret_cast<char*>(&xml.unknown_attributes), sizeof(xml.unknown_attributes));

    return xml;
}

void XML_Configuration_Sensor_TelegramValue::to_stream(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(&Priority), sizeof(Priority));
    tools::classhelper::stream::container_to_stream(os, Name);

    os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
    os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
}

// ----- operators -----
bool XML_Configuration_Sensor_TelegramValue::operator==(
    const XML_Configuration_Sensor_TelegramValue& other) const
{
    return Priority == other.Priority && Name == other.Name;
    // && unknown_children == other.unknown_children &&
    // unknown_attributes == other.unknown_attributes;
}

bool XML_Configuration_Sensor_TelegramValue::operator!=(
    const XML_Configuration_Sensor_TelegramValue& other) const
{
    return !operator==(other);
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter XML_Configuration_Sensor_TelegramValue::__printer__(
    unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "EK80 XML0 Value", float_precision, superscript_exponents);
    printer.register_value("Priority", Priority);
    printer.register_string("Name", Name);

    return printer;
}

} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping