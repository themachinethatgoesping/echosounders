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
    xml_datagrams::XML_Node raw();

    XML_Datagram_type decode() const;

    void set_xml_content(std::string xml_content)
    {
        _length      = simradraw_long(xml_content.size() + 12);
        _xml_content = std::move(xml_content);
    }
    const std::string& get_xml_content() const { return _xml_content; }

    //----- raw xml parsing -----
    void parse_xml(int level);

    void test_xml();

    // ----- public methods -----
    std::string get_xml_datagram_type() const;

    /**
     * @brief Get the xml datagram type from input stream without reading the entire datagram
     * content
     *
     * @param is
     * @return std::string
     */
    static std::string get_xml_datagram_type_from_stream(std::istream& is);

    /**
     * @brief Get the xml datagram type from input stream without reading the entire datagram
     * content
     *
     * @param is
     * @return std::string
     */
    static std::string get_xml_datagram_type_from_stream(std::istream&  is,
                                                         SimradRawDatagram header);

    // ----- file I/O -----
    static XML0 from_stream(std::istream& is, SimradRawDatagram header);
    static XML0 from_stream(std::istream& is);
    static XML0 from_stream(std::istream& is, t_SimradRawDatagramIdentifier type);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(XML0)
};

}
}
}
}