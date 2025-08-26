// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "XML0.hpp"

#include <stdexcept>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

// ----- file I/O -----
XML0 XML0::from_stream(std::istream& is, SimradRawDatagram header)
{
    XML0 datagram(std::move(header));
    datagram._xml_content.resize(datagram._length - 12);
    is.read(datagram._xml_content.data(), datagram._xml_content.size());

    // verify the datagram is read correctly by reading the length field at the end
    datagram._verify_datagram_end(is);

    return datagram;
}

XML0 XML0::from_stream(std::istream& is)
{
    return from_stream(is, SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::XML0));
}

XML0 XML0::from_stream(std::istream& is, t_SimradRawDatagramIdentifier type)
{
    if (type != t_SimradRawDatagramIdentifier::XML0)
        throw std::runtime_error("XML0::from_stream: wrong datagram type");

    return from_stream(is, SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::XML0));
}

void XML0::to_stream(std::ostream& os)
{
    _length        = simradraw_long(12 + _xml_content.size());
    _datagram_type = simradraw_long(t_SimradRawDatagramIdentifier::XML0);
    SimradRawDatagram::to_stream(os);
    os.write(_xml_content.data(), _xml_content.size());
    os.write(reinterpret_cast<const char*>(&_length), sizeof(simradraw_long));
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter XML0::__printer__(unsigned int float_precision, bool superscript_exponents) const
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

} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
