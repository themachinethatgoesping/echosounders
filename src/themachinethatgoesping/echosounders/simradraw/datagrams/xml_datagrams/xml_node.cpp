// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xml_node.hpp"

#include <themachinethatgoesping/tools/classhelper/stream.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

XML_Node::XML_Node(const pugi::xml_node& node)
{
    initialize(node);
}

void XML_Node::name(std::string name)
{
    _name = std::move(name);
}

void XML_Node::initialize(const pugi::xml_node& node)
{
    _name = node.name();
    for (const auto& child : node.children())
    {
        _children[child.name()].emplace_back(XML_Node(child));
    }
    for (const auto& attribute : node.attributes())
    {
        _attributes.emplace(attribute.name(), attribute.value());
    }
}

const XML_Node& XML_Node::first_child(const std::string& key) const
{
    return _children.at(key).at(0);
}

const std::string& XML_Node::attributes(const std::string& key) const
{
    return _attributes.at(key);
}

// ----- file I/O -----
XML_Node XML_Node::from_stream(std::istream& is)
{
    XML_Node datagram;

    datagram._name = tools::classhelper::stream::container_from_stream<std::string>(is);

    size_t size;
    is.read(reinterpret_cast<char*>(&size), sizeof(size));

    for (size_t i = 0; i < size; ++i)
    {
        std::string key = tools::classhelper::stream::container_from_stream<std::string>(is);
        size_t      size_sub;
        is.read(reinterpret_cast<char*>(&size_sub), sizeof(size_sub));
        for (size_t j = 0; j < size_sub; ++j)
        {
            datagram._children[key].emplace_back(XML_Node::from_stream(is));
        }
    }

    is.read(reinterpret_cast<char*>(&size), sizeof(size));
    for (size_t i = 0; i < size; ++i)
    {
        std::string key   = tools::classhelper::stream::container_from_stream<std::string>(is);
        std::string value = tools::classhelper::stream::container_from_stream<std::string>(is);
        datagram._attributes.emplace(key, value);
    }

    return datagram;
}

void XML_Node::to_stream(std::ostream& os) const
{
    tools::classhelper::stream::container_to_stream(os, _name);

    size_t size = _children.size();
    os.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
    for (const auto& key_node : _children)
    {
        std::string key = key_node.first;
        tools::classhelper::stream::container_to_stream(os, key);

        size_t size_sub = key_node.second.size();
        os.write(reinterpret_cast<const char*>(&size_sub), sizeof(size_t));
        for (const auto& node : key_node.second)
        {
            node.to_stream(os);
        }
    }

    size = _attributes.size();
    os.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
    for (const auto& key_value : _attributes)
    {
        std::string key   = key_value.first;
        std::string value = key_value.second;
        tools::classhelper::stream::container_to_stream(os, key);
        tools::classhelper::stream::container_to_stream(os, value);
    }
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter XML_Node::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("EK80 XML0 node '" + _name + "'",
                                              float_precision, superscript_exponents);

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

} // namespace simradraw
} // namespace datagrams
} // namespace xml_datagrams
} // namespace echosounders
} // namespace themachinethatgoesping
