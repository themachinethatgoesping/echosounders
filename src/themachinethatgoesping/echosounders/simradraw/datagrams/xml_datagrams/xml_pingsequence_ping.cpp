// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xml_pingsequence_ping.hpp"

#include <iostream>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

void XML_PingSequence_Ping::initialize(const pugi::xml_node& root_node)
{
    if (strcmp(root_node.name(), "Ping"))
    {
        throw std::runtime_error(std::string("XML_PingSequence_Ping: wrong root node type '") +
                                 root_node.name() + "'");
    }
    unknown_attributes = 0;
    unknown_children   = 0; // there should only be one child for this node

    // there should only be one child for this node
    for (const auto& node : root_node.children())
    {
        std::cerr << "WARNING: [PingSequence_Ping] Unknown child: " << node.name() << std::endl;

        unknown_children = 1;

        continue;
    }

    for (auto& attr : root_node.attributes())
    {
        std::string_view name = attr.name();
        if (name == "ChannelID")
        {
            ChannelID = attr.value();
            continue;
        }

        std::cerr << "WARNING: [PingSequence_Ping] Unknown attribute: " << name << std::endl;
        unknown_attributes += 1;
    }
}

// ----- file I/O -----
XML_PingSequence_Ping XML_PingSequence_Ping::from_stream(std::istream& is)
{
    XML_PingSequence_Ping xml;
    xml.ChannelID = tools::classhelper::stream::container_from_stream<std::string>(is);
    is.read(reinterpret_cast<char*>(&xml.unknown_children), sizeof(xml.unknown_children));
    is.read(reinterpret_cast<char*>(&xml.unknown_attributes), sizeof(xml.unknown_attributes));

    return xml;
}

void XML_PingSequence_Ping::to_stream(std::ostream& os) const
{
    tools::classhelper::stream::container_to_stream(os, ChannelID);
    os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
    os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
}

// ----- operators -----
bool XML_PingSequence_Ping::operator==(const XML_PingSequence_Ping& other) const
{
    return ChannelID == other.ChannelID;
    // && unknown_children == other.unknown_children &&
    // unknown_attributes == other.unknown_attributes;
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter XML_PingSequence_Ping::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("EK80 XML0 PingSequence_Ping", float_precision, superscript_exponents);
    printer.register_string("ChannelID", ChannelID);
    printer.register_value("unknown_children", unknown_children);
    printer.register_value("unknown_attributes", unknown_attributes);

    return printer;
}

} // namespace themachinethatgoesping
} // namespace echosounders
} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
