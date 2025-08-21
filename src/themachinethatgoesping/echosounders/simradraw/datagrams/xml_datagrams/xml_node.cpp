// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xml_node.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

XML_Node::XML_Node(const pugi::xml_node& node)
{
    initialize(node);
}
void              XML_Node::name(std::string name)
{
    _name = std::move(name);
}
const XML_Node& XML_Node::first_child(const std::string& key) const
{
    return _children.at(key).at(0);
}
const std::string& XML_Node::attributes(const std::string& key) const
{
    return _attributes.at(key);
}

} // namespace simradraw
} // namespace datagrams
} // namespace xml_datagrams
} // namespace echosounders
} // namespace themachinethatgoesping
