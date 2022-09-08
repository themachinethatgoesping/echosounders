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
class XML_Datagram
{
    // ----- datagram content -----
    std::string _xml_content; ///< raw xml string

  public:
    // ----- constructors -----
    XML_Datagram() = default;
    XML_Datagram(std::string xml_content)
        : _xml_content(std::move(xml_content))
    {
    }
    ~XML_Datagram() = default;


    // ----- file I/O -----
    static XML_Datagram from_stream(std::istream& is, size_t length)
    {
        XML_Datagram datagram;
        datagram._xml_content.resize(length);
        is.read(datagram._xml_content.data(), datagram._xml_content.size());
        return datagram;
    }

    static XML_Datagram from_stream(std::istream& is)
    {
        size_t length;
        is.read(reinterpret_cast<char*>(&length), sizeof(length));
        return from_stream(is,length);
    }

    void to_stream(std::ostream& os) const 
    {
        size_t size = this->size();
        os.write(reinterpret_cast<char*>(&size), sizeof(size));
        os.write(_xml_content.data(), _xml_content.size());
    }

    void to_stream_dont_write_size(std::ostream& os)
    {
        os.write(_xml_content.data(), _xml_content.size());
    }

    // ----- operators -----
    bool operator==(const XML_Datagram& other) const
    {
        return _xml_content == other._xml_content;
    }
    bool operator!=(const XML_Datagram& other) const { return !operator==(other); }

    size_t size() const { return _xml_content.size(); }

    // ----- getter setter -----
    void set_xml_content(std::string xml_content)
    {
        _xml_content = std::move(xml_content);
    }
    const std::string& get_xml_content() const { return _xml_content; }

    //----- raw xml parsing -----
    void parse_xml(int level)
    {
        pugi::xml_document doc;
        auto               result = doc.load_buffer_inplace(
            _xml_content.data(), _xml_content.size(), pugi::parse_default, pugi::encoding_utf8);
        if (!result)
            throw std::runtime_error("Error parsing XML0 datagram: " +
                                     std::string(result.description()));

        if (level == 2)
        {
            auto xml_type = doc.first_child().name();
            (void) xml_type;
        }
        else if (level > 2)
        {
            // get root child (one per datagram)
            //auto root_node = doc.first_child();
            //auto xml_type  = root_node.name();

            
            // get all children of root node
            get_walker walker;

            doc.traverse(walker);
        }
    }

    void test_xml()
    {
        pugi::xml_document doc;
        auto               result = doc.load_buffer_inplace(
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
        tools::classhelpers::ObjectPrinter printer("EK80 XML0 base datagram", float_precision);

        printer.register_section("XML data");
        printer.register_value("Type", get_xml_datagram_type());

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(XML_Datagram)
};

}
}
}
}
}