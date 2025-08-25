// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/xml_node.doc.hpp"

// std includes
#include <string>
#include <unordered_map>
#include <vector>

#include <pugixml.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "helper.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

/**
 * @brief XML base datagram
 *
 */
class XML_Node
{
    std::string                                            _name;
    std::unordered_map<std::string, std::vector<XML_Node>> _children;
    std::unordered_map<std::string, std::string>           _attributes;

  public:
    // ----- constructors -----
    XML_Node() = default;
    XML_Node(const pugi::xml_node& node);
    ~XML_Node() = default;

    void initialize(const pugi::xml_node& node);

    // ----- operators -----
    bool operator==(const XML_Node& other) const = default;

    // ----- getter/setter -----
    const std::string name() const { return _name; }
    void              name(std::string name);

    const std::unordered_map<std::string, std::vector<XML_Node>>& children() const
    {
        return _children;
    }
    const std::vector<XML_Node>& children(const std::string& key) const
    {
        return _children.at(key);
    }
    const XML_Node& first_child(const std::string& key) const;

    const std::unordered_map<std::string, std::string>& attributes() const { return _attributes; }
    const std::string& attributes(const std::string& key) const;

    // ----- file I/O -----
    static XML_Node from_stream(std::istream& is);
    void to_stream(std::ostream& os) const;

    // ----- operators -----
    // bool operator==(const XML_Node& other) const { return _xml_content == other._xml_content; }
    // bool operator!=(const XML_Node& other) const { return !operator==(other); }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(XML_Node)
};

}
}
}
}
}