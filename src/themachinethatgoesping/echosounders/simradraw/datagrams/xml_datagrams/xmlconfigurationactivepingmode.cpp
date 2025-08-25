// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xmlconfigurationactivepingmode.hpp"

#include <iostream>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

void XMLConfigurationActivePingMode::initialize(const pugi::xml_node& root_node)
{
    if (strcmp(root_node.name(), "ActivePingMode"))
    {
        throw std::runtime_error(
            std::string("XMLConfigurationActivePingMode: wrong root node type '") +
            root_node.name() + "'");
    }
    unknown_attributes = 0;
    unknown_children   = 0; // there should be no child

    // there should only be one child for this node
    for (const auto& node : root_node.children())
    {
        std::cerr << "WARNING: [Configuration_ActivePingMode] Unknown child: " << node.name()
                  << std::endl;

        unknown_children = 1;
    }

    for (const auto& attr : root_node.attributes())
    {
        std::string_view name = attr.name();
        if (name == "Mode")
        {
            Mode = attr.value();
            continue;
        }
        std::cerr << "WARNING: [Configuration_ActivePingMode] Unknown attribute: " << name
                  << std::endl;
        unknown_attributes += 1;
    }
}

// ----- file I/O -----
XMLConfigurationActivePingMode XMLConfigurationActivePingMode::from_stream(std::istream& is)
{
    XMLConfigurationActivePingMode xml;
    xml.Mode = tools::classhelper::stream::container_from_stream<std::string>(is);

    is.read(reinterpret_cast<char*>(&xml.unknown_children), sizeof(xml.unknown_children));
    is.read(reinterpret_cast<char*>(&xml.unknown_attributes), sizeof(xml.unknown_attributes));

    return xml;
}

void XMLConfigurationActivePingMode::to_stream(std::ostream& os) const
{
    tools::classhelper::stream::container_to_stream(os, Mode);

    os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
    os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
}

// ----- operators -----
bool XMLConfigurationActivePingMode::operator==(const XMLConfigurationActivePingMode& other) const
{
    return Mode == other.Mode;
    // && unknown_children == other.unknown_children &&
    // unknown_attributes == other.unknown_attributes;
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter XMLConfigurationActivePingMode::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("EK80 XML0 Configuration_ActivePingMode",
                                              float_precision, superscript_exponents);
    printer.register_string("Mode", Mode);

    return printer;
}

} // namespace themachinethatgoesping
} // namespace echosounders
} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
