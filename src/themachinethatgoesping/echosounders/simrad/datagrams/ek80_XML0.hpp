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
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../ek60_types.hpp"
#include "ek60_datagram.hpp"
#include "xml_datagrams/helper.hpp"
#include "xml_datagrams/xml_datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {

/**
 * @brief Motion binary datagram (XML0)
 * This datagram contains heave, roll, pitch and heading as float values.
 * Conveniently, these values can be used directly in themachinethatgoesping navigation processing
 * because they are defined in the default coordinate system / value range.
 *
 */
class EK80_XML0 : public EK60_Datagram
{
    // ----- datagram content -----
    xml_datagrams::XML_Datagram _xml_datagram; ///< parsed xml datagram

  private:
    // ----- private constructors -----
    explicit EK80_XML0(EK60_Datagram header)
        : EK60_Datagram(std::move(header))
    {
    }

  public:
    // ----- constructors -----
    EK80_XML0(std::string xml_content = "")
        : _xml_datagram(std::move(xml_content))
    {
        _Length       = _xml_datagram.size() + 12;
        _DatagramType = ek60_long(t_EK60_DatagramType::XML0);
    }
    ~EK80_XML0() = default;

    // ----- operators -----
    bool operator==(const EK80_XML0& other) const
    {
        return EK60_Datagram::operator==(other) && _xml_datagram == other._xml_datagram;
    }
    bool operator!=(const EK80_XML0& other) const { return !operator==(other); }

    // ----- getter/setter
    xml_datagrams::XML_Datagram& get_xml_structure() { return _xml_datagram; }
    void set_xml_structure(xml_datagrams::XML_Datagram xml_datagram)
    {
        _xml_datagram = xml_datagram;
    }

    // ----- convinient xml access -----
    void set_xml_content(std::string xml_content)
    {
        _Length       = xml_content.size() + 12;
        _xml_datagram = xml_datagrams::XML_Datagram(std::move(xml_content));
    }
    const std::string& get_xml_content() const { return _xml_datagram.get_xml_content(); }

    std::string get_xml_datagram_type() const { return _xml_datagram.get_xml_datagram_type(); }

    // ----- file I/O -----
    static EK80_XML0 from_stream(std::istream& is, EK60_Datagram header)
    {
        EK80_XML0 datagram(std::move(header));
        datagram._xml_datagram =
            xml_datagrams::XML_Datagram::from_stream(is, datagram._Length - 12);

        // verify the datagram is read correctly by reading the length field at the end
        datagram._verify_datagram_end(is);

        return datagram;
    }

    static EK80_XML0 from_stream(std::istream& is)
    {
        return from_stream(is, EK60_Datagram::from_stream(is, t_EK60_DatagramType::XML0));
    }

    static EK80_XML0 from_stream(std::istream& is, t_EK60_DatagramType type)
    {
        if (type != t_EK60_DatagramType::XML0)
            throw std::runtime_error("EK80_XML0::from_stream: wrong datagram type");

        return from_stream(is, EK60_Datagram::from_stream(is, t_EK60_DatagramType::XML0));
    }

    void to_stream(std::ostream& os)
    {
        _Length       = 12 + _xml_datagram.size();
        _DatagramType = ek60_long(t_EK60_DatagramType::XML0);
        EK60_Datagram::to_stream(os);
        _xml_datagram.to_stream_dont_write_size(os);
        os.write(reinterpret_cast<const char*>(&_Length), sizeof(ek60_float));
    }

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("EK80 XML0 datagram", float_precision);

        printer.append(EK60_Datagram::__printer__(float_precision));

        printer.register_section("XML data");
        printer.register_value("Type", _xml_datagram.get_xml_datagram_type());

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(EK80_XML0)
};

}
}
}
}