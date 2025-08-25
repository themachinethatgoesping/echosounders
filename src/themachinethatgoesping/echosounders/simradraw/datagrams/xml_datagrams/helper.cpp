// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "helper.hpp"

// std
#include <iostream>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

// Implementation file for helper.hpp
// TODO: Move appropriate implementations from header to this file

bool get_walker::for_each(pugi::xml_node& node)
{
    // touch to silence warnings (reserved for future logic)
    auto t = node.type();
    auto n = node.name();
    auto v = node.value();
    (void)t;
    (void)n;
    (void)v;

    for (pugi::xml_attribute attr : node.attributes())
    {
        _a = attr.name();
        _b = attr.value();
    }

    return true; // continue traversal
}

bool print_walker::for_each(pugi::xml_node& node)
{
    std::string indent;
    for (int i = 0; i < depth(); ++i)
        indent += "  "; // indentation

    // print node name and value
    std::cout << indent << node.type() << ": name='" << node.name() << "', value='"
              << node.value() << "'\n";

    // print node attributes
    for (pugi::xml_attribute attr : node.attributes())
        std::cout << indent << "  - " << attr.name() << " = '" << attr.value() << "'\n";

    return true; // continue traversal
}

bool objectprint_walker::for_each(pugi::xml_node& node)
{
    std::string indent;
    for (int i = 0; i < depth(); ++i)
        indent += "  "; // indentation

    char underliner = '-';
    if (depth() == 1)
        underliner = '^';
    if (depth() > 1)
        underliner = '"';

    _root_nodes[depth()] = node.name();

    std::string section_name = indent + std::to_string(depth()) + ".: " + node.name();
    if (!std::string(node.value()).empty())
        section_name += "(val: " + std::string(node.value()) + ")";
    section_name += " ";

    for (int i = 0; i < depth(); ++i)
        section_name += "[" + _root_nodes[i] + "]";

    _printer.register_section(section_name, underliner);

    // print node attributes
    for (pugi::xml_attribute attr : node.attributes())
        _printer.register_string(attr.name(), attr.value(), node.name());

    return true; // continue traversal
}

} // namespace themachinethatgoesping
} // namespace echosounders
} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
