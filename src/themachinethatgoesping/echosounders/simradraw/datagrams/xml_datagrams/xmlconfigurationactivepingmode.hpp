// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/xmlconfigurationactivepingmode.doc.hpp"

/* generated doc strings */
#include ".docstrings/xmlconfigurationactivepingmode.doc.hpp"

// std includes
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string/find.hpp>

#include <pugixml.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>



#include "helper.hpp"
#include "xml_node.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

/**
 * @brief XML base datagram
 *
 */
struct XMLConfigurationActivePingMode
{
    std::string Mode;

    int32_t unknown_children   = 0;
    int32_t unknown_attributes = 0;

  public:
    // ----- constructors -----
    XMLConfigurationActivePingMode() = default;
    XMLConfigurationActivePingMode(const pugi::xml_node& node) { initialize(node); }
    ~XMLConfigurationActivePingMode() = default;

    void initialize(const pugi::xml_node& root_node)
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

    bool parsed_completely() const { return unknown_children == 0 && unknown_attributes == 0; }

    // ----- file I/O -----
    static XMLConfigurationActivePingMode from_stream(std::istream& is)
    {
        XMLConfigurationActivePingMode xml;
        xml.Mode = tools::classhelper::stream::container_from_stream<std::string>(is);

        is.read(reinterpret_cast<char*>(&xml.unknown_children), sizeof(xml.unknown_children));
        is.read(reinterpret_cast<char*>(&xml.unknown_attributes), sizeof(xml.unknown_attributes));

        return xml;
    }

    void to_stream(std::ostream& os) const
    {
        tools::classhelper::stream::container_to_stream(os, Mode);

        os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
        os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
    }

    // ----- operators -----
    bool operator==(const XMLConfigurationActivePingMode& other) const
    {
        return Mode == other.Mode;
        // && unknown_children == other.unknown_children &&
        // unknown_attributes == other.unknown_attributes;
    }
    bool operator!=(const XMLConfigurationActivePingMode& other) const
    {
        return !operator==(other);
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("EK80 XML0 Configuration_ActivePingMode",
                                                  float_precision, superscript_exponents);
        printer.register_string("Mode", Mode);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(
        XMLConfigurationActivePingMode)
};

}
}
}
}
}