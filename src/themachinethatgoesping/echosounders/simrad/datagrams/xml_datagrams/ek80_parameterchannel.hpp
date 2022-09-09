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
#include "xml_node.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {
namespace xml_datagrams {

/**
 * @brief XML base datagram
 *
 */
class EK80_ParameterChannel : public XML_Node
{

  public:
    // ----- constructors -----
    EK80_ParameterChannel() = default;
    EK80_ParameterChannel(XML_Node xml_content, bool check = false)
        : XML_Node(std::move(xml_content))
    {
        if (check) 
            if (get_xml_datagram_type() != "Parameter") 
                {throw std::runtime_error("Invalid datagram type");}}
    }
    ~EK80_ParameterChannel() = default;

    // ----- file I/O -----
    static EK80_ParameterChannel from_stream(std::istream& is)
    {
        EK80_ParameterChannel(XML_Node::from_stream(is), true);
    }

    //----- raw xml parsing -----
    void parse_xml(int level)
    {
        pugi::xml_document doc;
        auto               result = doc.load_buffer(
            _xml_content.data(), _xml_content.size(), pugi::parse_default, pugi::encoding_utf8);
        if (!result)
            throw std::runtime_error("Error parsing XML0 datagram: " +
                                     std::string(result.description()));

        if (level == 2)
        {
            auto xml_type = doc.first_child().name();
            (void)xml_type;
        }
        else if (level > 2)
        {
            // get root child (one per datagram)
            // auto root_node = doc.first_child();
            // auto xml_type  = root_node.name();

            // get all children of root node
            get_walker walker;

            doc.traverse(walker);
        }
    }

    void test_xml()
    {
        pugi::xml_document doc;
        auto               result = doc.load_buffer(
            _xml_content.data(), _xml_content.size(), pugi::parse_default, pugi::encoding_utf8);
        if (!result)
            throw std::runtime_error("Error parsing XML0 datagram: " +
                                     std::string(result.description()));

        // get root child (one per datagram)
        auto root_node = doc.first_child();
        auto xml_type  = root_node.name();
        std::cout << "root node: " << xml_type << std::endl;

        // get all children of root node
        print_walker walker;

        doc.traverse(walker);
    }

    // ----- public methods -----
    std::string get_xml_datagram_type() const
    {
        // start at seven because the xml tag must be at least "<?xml?>"
        unsigned int i = 7;
        for (; i < _xml_content.size(); ++i)
        {
            if (_xml_content[i] == '<')
                break;
        }

        for (unsigned int j = ++i; j < _xml_content.size(); ++j)
        {
            if (_xml_content[j] == ' ' || _xml_content[j] == '>')
                return _xml_content.substr(i, j - i);
        }

        return "invalid";
    }

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        pugi::xml_document doc;
        auto               result = doc.load_buffer(
            _xml_content.data(), _xml_content.size(), pugi::parse_default, pugi::encoding_utf8);
        if (!result)
            throw std::runtime_error("Error parsing XML0 datagram: " +
                                     std::string(result.description()));

        tools::classhelpers::ObjectPrinter printer("EK80 XML0 base datagram", float_precision);

        objectprint_walker walker(printer);

        doc.traverse(walker);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(EK80_ParameterChannel)
};

}
}
}
}
}