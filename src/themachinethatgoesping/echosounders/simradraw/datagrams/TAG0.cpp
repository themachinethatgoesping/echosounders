// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "TAG0.hpp"

#include <stdexcept>

#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

// ----- file I/O -----
TAG0 TAG0::from_stream(std::istream& is, SimradRawDatagram header)
{
    TAG0 datagram(std::move(header));
    datagram._text.resize(datagram.get_length() - 12);
    is.read(datagram._text.data(), datagram._text.size());

    // verify the datagram is read correctly by reading the length field at the end
    datagram._verify_datagram_end(is);

    return datagram;
}

TAG0 TAG0::from_stream(std::istream& is)
{
    return from_stream(is, SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::TAG0));
}

TAG0 TAG0::from_stream(std::istream& is, t_SimradRawDatagramIdentifier type)
{
    if (type != t_SimradRawDatagramIdentifier::TAG0)
        throw std::runtime_error("TAG0::from_stream: wrong datagram type");

    return from_stream(is, SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::TAG0));
}

void TAG0::to_stream(std::ostream& os)
{
    _length        = simradraw_long(12 + _text.size());
    _datagram_type = simradraw_long(t_SimradRawDatagramIdentifier::TAG0);
    SimradRawDatagram::to_stream(os);
    os.write(_text.data(), _text.size());
    os.write(reinterpret_cast<const char*>(&_length), sizeof(simradraw_long));
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter TAG0::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("Annotation datagram", float_precision, superscript_exponents);

    printer.append(SimradRawDatagram::__printer__(float_precision, superscript_exponents));

    printer.register_section("Annotation data");
    printer.register_string("Text", _text);

    return printer;
}

} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
