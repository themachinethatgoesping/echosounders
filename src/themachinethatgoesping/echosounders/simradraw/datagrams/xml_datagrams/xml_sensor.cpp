// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xml_sensor.hpp"

#include <iostream>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/helper/approx.hpp>
#include <themachinethatgoesping/tools/helper/stringconversion.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

void XML_Sensor::initialize(const pugi::xml_node& root_node)
{
    if (strcmp(root_node.name(), "Sensor"))
    {
        throw std::runtime_error(std::string("XML_Sensor: wrong root node type '") +
                                 root_node.name() + "'");
    }
    unknown_attributes = 0;
    unknown_children   = 0; // there should be no child

    // there should only be one child for this node
    for (const auto& node : root_node.children())
    {
        std::cerr << "WARNING: [Sensor] Unknown child: " << node.name() << std::endl;

        unknown_children = 1;
    }

    for (const auto& attr : root_node.attributes())
    {
        std::string_view name = attr.name();
        if (name == "IsManual")
        {
            IsManual = std::stoi(attr.value()); // TODO: is this only 0/1 or also false/true?
            continue;
        }
        if (name == "ManualValue")
        {
            ManualValue = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "Type")
        {
            Type = attr.value();
            continue;
        }
        std::cerr << "WARNING: [Sensor] Unknown attribute: " << name << std::endl;
        unknown_attributes += 1;
    }
}

// ----- file I/O -----
XML_Sensor XML_Sensor::from_stream(std::istream& is)
{
    XML_Sensor xml;
    is.read(reinterpret_cast<char*>(&xml.IsManual), sizeof(xml.IsManual));
    is.read(reinterpret_cast<char*>(&xml.ManualValue), sizeof(xml.ManualValue));
    xml.Type = tools::classhelper::stream::container_from_stream<std::string>(is);

    is.read(reinterpret_cast<char*>(&xml.unknown_children), sizeof(xml.unknown_children));
    is.read(reinterpret_cast<char*>(&xml.unknown_attributes), sizeof(xml.unknown_attributes));

    return xml;
}

void XML_Sensor::to_stream(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(&IsManual), sizeof(IsManual));
    os.write(reinterpret_cast<const char*>(&ManualValue), sizeof(ManualValue));
    tools::classhelper::stream::container_to_stream(os, Type);

    os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
    os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
}

// ----- operators -----
bool XML_Sensor::operator==(const XML_Sensor& other) const
{
    return IsManual == other.IsManual &&
           tools::helper::approx(ManualValue, other.ManualValue) && Type == other.Type;
    // && unknown_children == other.unknown_children &&
    // unknown_attributes == other.unknown_attributes;
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter XML_Sensor::__printer__(unsigned int float_precision,
                                              bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "EK80 XML0 Sensor", float_precision, superscript_exponents);
    printer.register_value("IsManual", IsManual);
    printer.register_value("ManualValue", ManualValue);
    printer.register_string("Type", Type);

    return printer;
}

} // namespace themachinethatgoesping
} // namespace echosounders
} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
