// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xml_initialparameter.hpp"

#include <iostream>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

void XML_InitialParameter::initialize(const pugi::xml_node& root_node)
{
    if (strcmp(root_node.name(), "InitialParameter"))
    {
        throw std::runtime_error(std::string("XML_InitialParameter: wrong root node type '") +
                                 root_node.name() + "'");
    }
    unknown_attributes = 0;
    unknown_children   = 0; // there should be one channels structure with multiple channels
    bool parsed        = false;

    // there should only be one child for this node
    for (const auto& sub_node : root_node.children())
    {
        if (parsed || strcmp(sub_node.name(), "Channels"))
        {
            std::cerr << "WARNING: [InitialParameter] Unknown child: " << sub_node.name()
                      << std::endl;

            unknown_children = 1;

            continue;
        }

        parsed = true;

        for (const auto& node : sub_node.children())
        {
            if (strcmp(node.name(), "Channel"))
            {
                std::cerr << "WARNING: [InitialParameter::Channels] Unknown child: "
                          << node.name() << std::endl;

                unknown_children = 1;

                continue;
            }
            Channels.emplace_back();
            Channels.back().initialize_channel_structure(node);
        }
    }
}

// ----- file I/O -----
XML_InitialParameter XML_InitialParameter::from_stream(std::istream& is)
{
    XML_InitialParameter xml;
    size_t               size;
    is.read(reinterpret_cast<char*>(&size), sizeof(size));
    for (size_t i = 0; i < size; ++i)
    {
        xml.Channels.emplace_back(XML_Parameter_Channel::from_stream(is));
    }
    is.read(reinterpret_cast<char*>(&xml.unknown_children), sizeof(xml.unknown_children));
    is.read(reinterpret_cast<char*>(&xml.unknown_attributes), sizeof(xml.unknown_attributes));

    return xml;
}

void XML_InitialParameter::to_stream(std::ostream& os) const
{
    size_t size = Channels.size();
    os.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const auto& channel : Channels)
    {
        channel.to_stream(os);
    }
    os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
    os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
}

// ----- operators -----
bool XML_InitialParameter::operator==(const XML_InitialParameter& other) const
{
    if (Channels.size() != other.Channels.size())
        return false;

    for (size_t i = 0; i < Channels.size(); ++i)
    {
        if (Channels[i] != other.Channels[i])
            return false;
    }
    return true;

    // && unknown_children == other.unknown_children &&
    // unknown_attributes == other.unknown_attributes;
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter XML_InitialParameter::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("EK80 XML0 Parameter Channel", float_precision, superscript_exponents);
    printer.register_section("Channels");
    for (const auto& channel : Channels)
    {
        printer.register_string("ChannelID", channel.ChannelID);
    }

    return printer;
}

} // namespace themachinethatgoesping
} // namespace echosounders
} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
