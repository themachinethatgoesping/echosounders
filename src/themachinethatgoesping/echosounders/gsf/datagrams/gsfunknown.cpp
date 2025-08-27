// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "gsfunknown.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace gsf {
namespace datagrams {

GSFUnknown GSFUnknown::from_stream(std::istream& is, GSFDatagram header)
{
    GSFUnknown datagram(std::move(header));

    datagram._raw_content.resize(size_t(datagram._size_of_data));

    // verify the datagram is read correctly by reading the length field at the end
    is.read(datagram._raw_content.data(), datagram._raw_content.size());

    return datagram;
}

GSFUnknown GSFUnknown::from_stream(std::istream& is)
{
    return from_stream(is, GSFDatagram::from_stream(is));
}

GSFUnknown GSFUnknown::from_stream(std::istream& is, t_GSFDatagramIdentifier datagram_identifier)
{
    return from_stream(is, GSFDatagram::from_stream(is, datagram_identifier));
}

void GSFUnknown::to_stream(std::ostream& os)
{
    GSFDatagram::to_stream(os);

    os.write(_raw_content.data(), _raw_content.size());
}

tools::classhelper::ObjectPrinter GSFUnknown::__printer__(unsigned int float_precision,
                                                         bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "GSFUnknown", float_precision, superscript_exponents);

    printer.append(GSFDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("raw data", _raw_content.size(), "bytes");

    return printer;
}

} // namespace datagrams
} // namespace gsf  
} // namespace echosounders
} // namespace themachinethatgoesping
