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
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "helper.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {
namespace xml_datagrams {

/**
 * @brief XML base datagram
 *
 */
class XML_Node
{
    std::string _name;
    std::unordered_map<std::string, std::vector<XML_Node>> _children;
    std::unordered_map<std::string, std::string> _attributes;

  public:
    // ----- constructors -----
    XML_Node() = default;
    XML_Node(pugi::xml_node& node)
    {
        initialize(node);
    }
    ~XML_Node() = default;

    virtual void initialize(pugi::xml_node& node)
    {
        _name = node.name();
        for (auto& child : node.children())
        {
            _children[child.name()].emplace_back(XML_Node(child));
        }
        for (auto& attribute : node.attributes())
        {
            _attributes.emplace(attribute.name(), attribute.value());
        }
    }

    // ----- getter/setter -----
    const std::unordered_map<std::string, std::vector<XML_Node>>& get_children() const
    {
        return _children;
    }
    const std::unordered_map<std::string, std::string>& get_attributes() const
    {
        return _attributes;
    }


    // ----- file I/O -----
    static XML_Node from_stream(std::istream& is)
    {
        // size_t length;
        // is.read(reinterpret_cast<char*>(&length), sizeof(length));
        // return from_stream(is, length);
    }

    void to_stream(std::ostream& os) const
    {
        // size_t size = this->size();
        // os.write(reinterpret_cast<char*>(&size), sizeof(size));
    }


    // ----- operators -----
    // bool operator==(const XML_Node& other) const { return _xml_content == other._xml_content; }
    // bool operator!=(const XML_Node& other) const { return !operator==(other); }
    

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("EK80 XML0 node '" + _name + "'", float_precision);

        if (!_children.empty())
        {
        printer.register_section("children");
        for (auto& kv : _children)
            printer.register_value(kv.first, kv.second.size());
        }

        if (!_attributes.empty())
        {
            printer.register_section("attributes");

            for (auto& kv : _attributes)
                printer.register_value(kv.first, kv.second);
        }


        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(XML_Node)
};

}
}
}
}
}