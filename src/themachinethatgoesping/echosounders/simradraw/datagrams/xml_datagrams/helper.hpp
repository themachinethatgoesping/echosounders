// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/helper.doc.hpp"

// std includes
#include <string>
#include <unordered_map>

// pugixml
#include <pugixml.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

/**
 * @brief Walker collecting last seen attribute name/value while traversing the XML tree.
 */
struct get_walker : pugi::xml_tree_walker
{
    std::string _a;
    std::string _b;

    /**
     * @brief Called for every node during traversal.
     */
    bool for_each(pugi::xml_node& node) override;
};

/**
 * @brief Walker printing nodes and attributes to std::cout (debug helper).
 */
struct print_walker : pugi::xml_tree_walker
{
    /**
     * @brief Called for every node during traversal.
     */
    bool for_each(pugi::xml_node& node) override;
};

/**
 * @brief Walker that registers XML hierarchy and attributes into an ObjectPrinter.
 */
struct objectprint_walker : pugi::xml_tree_walker
{
    std::unordered_map<int, std::string> _root_nodes;
    tools::classhelper::ObjectPrinter&   _printer;

    explicit objectprint_walker(tools::classhelper::ObjectPrinter& printer)
        : _printer(printer)
    {
    }

    /**
     * @brief Called for every node during traversal.
     */
    bool for_each(pugi::xml_node& node) override;
};

} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping