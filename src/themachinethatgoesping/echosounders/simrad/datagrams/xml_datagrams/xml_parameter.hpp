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
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "helper.hpp"
#include "xml_node.hpp"
#include "xml_parameter_channel.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {
namespace xml_datagrams {

/**
 * @brief XML base datagram
 *
 */
struct XML_Parameter
{
    std::vector<XML_Parameter_Channel> Channels;

    int32_t unknown_children   = 0;
    int32_t unknown_attributes = 0;

  public:
    // ----- constructors -----
    XML_Parameter() = default;
    XML_Parameter(const pugi::xml_node& node) { initialize(node); }
    ~XML_Parameter() = default;

    void initialize(const pugi::xml_node& root_node)
    {
        if (strcmp(root_node.name(), "Parameter"))
        {
            throw std::runtime_error(std::string("XML_Parameter: wrong root node type '") +
                                     root_node.name() + "'");
        }
        unknown_attributes = 0;
        unknown_children   = 0; // there should be one channels structure with multiple channels

        // there should only be one child for this node
        for (const auto& node : root_node.children())
        {
            if (strcmp(node.name(), "Channel"))
            {
                std::cerr << "WARNING: [Parameter::Channels] Unknown child: " << node.name()
                          << std::endl;

                unknown_children = 1;

                continue;
            }
            Channels.emplace_back();
            Channels.back().initialize_channel_structure(node);
        }
    }

    bool parsed_completely() const { return unknown_children == 0 && unknown_attributes == 0; }

    // ----- file I/O -----
    static XML_Parameter from_stream(std::istream& is)
    {
        XML_Parameter xml;
        size_t        size;
        is.read(reinterpret_cast<char*>(&size), sizeof(size));
        for (size_t i = 0; i < size; ++i)
        {
            xml.Channels.emplace_back(XML_Parameter_Channel::from_stream(is));
        }
        is.read(reinterpret_cast<char*>(&xml.unknown_children), sizeof(xml.unknown_children));
        is.read(reinterpret_cast<char*>(&xml.unknown_attributes), sizeof(xml.unknown_attributes));

        return xml;
    }

    void to_stream(std::ostream& os) const
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
    bool operator==(const XML_Parameter& other) const
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
    bool operator!=(const XML_Parameter& other) const { return !operator==(other); }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("EK80 XML0 Parameter Channel", float_precision);
        printer.register_section("Channels");
        for (const auto& channel : Channels)
        {
            printer.register_string("ChannelID", channel.ChannelID);
        }

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(
        XML_Parameter)
};

}
}
}
}
}