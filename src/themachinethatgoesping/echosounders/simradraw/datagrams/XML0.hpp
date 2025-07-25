// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/XML0.doc.hpp"

// std includes
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string/find.hpp>

#include <pugixml.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "../types.hpp"
#include "simradrawdatagram.hpp"
#include "xml_datagrams/helper.hpp"
#include "xml_datagrams/xml_configuration.hpp"
#include "xml_datagrams/xml_environment.hpp"
#include "xml_datagrams/xml_initialparameter.hpp"
#include "xml_datagrams/xml_node.hpp"
#include "xml_datagrams/xml_parameter.hpp"
#include "xml_datagrams/xml_pingsequence.hpp"
#include "xml_datagrams/xml_sensor.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

using XML_Datagram_type = std::variant<xml_datagrams::XML_Node,
                                       xml_datagrams::XML_Parameter,
                                       xml_datagrams::XML_InitialParameter,
                                       xml_datagrams::XML_PingSequence,
                                       xml_datagrams::XML_Environment,
                                       xml_datagrams::XML_Sensor,
                                       xml_datagrams::XML_Configuration>;

/**
 * @brief Motion binary datagram (XML0)
 * This datagram contains heave, roll, pitch and heading as float values.
 * Conveniently, these values can be used directly in themachinethatgoesping navigation processing
 * because they are defined in the default coordinate system / value range.
 *
 */
class XML0 : public SimradRawDatagram
{
    // ----- datagram content -----
    // xml_datagrams::XML_Node _xml_datagram; ///< parsed xml datagram
    // ----- datagram content -----
    std::string _xml_content; ///< raw xml string

  private:
    // ----- private constructors -----
    explicit XML0(SimradRawDatagram header)
        : SimradRawDatagram(std::move(header))
    {
    }

  public:
    // ----- constructors -----
    XML0(std::string xml_content = "")
        : _xml_content(std::move(xml_content))
    {
        _length        = simradraw_long(_xml_content.size() + 12);
        _datagram_type = simradraw_long(t_SimradRawDatagramIdentifier::XML0);
    }
    ~XML0() = default;

    // ----- operators -----
    bool operator==(const XML0& other) const = default;

    // ----- getter/setter
    xml_datagrams::XML_Node raw()
    {
        pugi::xml_document doc;
        auto               result = doc.load_buffer(
            _xml_content.data(), _xml_content.size(), pugi::parse_default, pugi::encoding_utf8);
        if (!result)
            throw std::runtime_error("Error parsing XML0 datagram: " +
                                     std::string(result.description()));

        return xml_datagrams::XML_Node(doc.first_child());
    }

    XML_Datagram_type decode() const
    {
        pugi::xml_document doc;
        auto               result = doc.load_buffer(
            _xml_content.data(), _xml_content.size(), pugi::parse_default, pugi::encoding_utf8);
        if (!result)
            throw std::runtime_error("Error parsing XML0 datagram: " +
                                     std::string(result.description()));

        const auto& root_node = doc.first_child();
        std::string type      = get_xml_datagram_type();

        if (type == "Parameter")
        {
            return XML_Datagram_type(xml_datagrams::XML_Parameter(root_node));
        }
        else if (type == "PingSequence")
        {
            return XML_Datagram_type(xml_datagrams::XML_PingSequence(root_node));
        }
        else if (type == "InitialParameter")
        {
            return XML_Datagram_type(xml_datagrams::XML_InitialParameter(root_node));
        }
        else if (type == "Environment")
        {
            return XML_Datagram_type(xml_datagrams::XML_Environment(root_node));
        }
        else if (type == "Sensor")
        {
            return XML_Datagram_type(xml_datagrams::XML_Sensor(root_node));
        }
        else if (type == "Configuration")
        {
            return XML_Datagram_type(xml_datagrams::XML_Configuration(root_node));
        }
        else
        {
            return XML_Datagram_type(xml_datagrams::XML_Node(root_node));
        }
    }

    void set_xml_content(std::string xml_content)
    {
        _length      = simradraw_long(xml_content.size() + 12);
        _xml_content = std::move(xml_content);
    }
    const std::string& get_xml_content() const { return _xml_content; }

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
            xml_datagrams::get_walker walker;

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
        const auto& root_node = doc.first_child();
        auto        xml_type  = root_node.name();
        std::cout << "root node: " << xml_type << std::endl;

        // get all children of root node
        xml_datagrams::print_walker walker;

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

    /**
     * @brief Get the xml datagram type from input stream without reading the entire datagram
     * content
     *
     * @param is
     * @return std::string
     */
    static inline std::string get_xml_datagram_type_from_stream(std::istream& is)
    {
        return get_xml_datagram_type_from_stream(is, SimradRawDatagram::from_stream(is));
    }

    /**
     * @brief Get the xml datagram type from input stream without reading the entire datagram
     * content
     *
     * @param is
     * @return std::string
     */
    static inline std::string get_xml_datagram_type_from_stream(std::istream&  is,
                                                                SimradRawDatagram header)
    {
        // this assumes that the stream is at the beginning of the datagram (after the header)
        std::string xml_content;

        size_t buffer_size = std::min(64, header.get_length() - 12);

        xml_content.resize(buffer_size);

        is.read(xml_content.data(), buffer_size);

        // start at seven because the xml tag must be at least "<?xml?>"
        unsigned int i = 7;
        for (; i < xml_content.size(); ++i)
        {
            if (xml_content[i] == '<')
                break;
        }

        for (unsigned int j = ++i; j < xml_content.size(); ++j)
        {
            if (xml_content[j] == ' ' || xml_content[j] == '>')
                return xml_content.substr(i, j - i);
        }

        return "invalid";
    }

    // ----- file I/O -----
    static XML0 from_stream(std::istream& is, SimradRawDatagram header)
    {
        XML0 datagram(std::move(header));
        datagram._xml_content.resize(datagram._length - 12);
        is.read(datagram._xml_content.data(), datagram._xml_content.size());

        // verify the datagram is read correctly by reading the length field at the end
        datagram._verify_datagram_end(is);

        return datagram;
    }

    static XML0 from_stream(std::istream& is)
    {
        return from_stream(is, SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::XML0));
    }

    static XML0 from_stream(std::istream& is, t_SimradRawDatagramIdentifier type)
    {
        if (type != t_SimradRawDatagramIdentifier::XML0)
            throw std::runtime_error("XML0::from_stream: wrong datagram type");

        return from_stream(is, SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::XML0));
    }

    void to_stream(std::ostream& os)
    {
        _length        = simradraw_long(12 + _xml_content.size());
        _datagram_type = simradraw_long(t_SimradRawDatagramIdentifier::XML0);
        SimradRawDatagram::to_stream(os);
        os.write(_xml_content.data(), _xml_content.size());
        os.write(reinterpret_cast<const char*>(&_length), sizeof(simradraw_long));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("EK80 XML0 datagram", float_precision, superscript_exponents);
        printer.append(SimradRawDatagram::__printer__(float_precision, superscript_exponents));
        printer.register_value("Type", get_xml_datagram_type());

        pugi::xml_document doc;
        auto               result = doc.load_buffer(
            _xml_content.data(), _xml_content.size(), pugi::parse_default, pugi::encoding_utf8);
        if (!result)
            throw std::runtime_error("Error parsing XML0 datagram: " +
                                     std::string(result.description()));

        xml_datagrams::objectprint_walker walker(printer);

        doc.traverse(walker);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(XML0)
};

}
}
}
}