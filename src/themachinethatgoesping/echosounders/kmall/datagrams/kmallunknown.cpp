// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "kmallunknown.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

void KMALLUnknown::set_raw_content(const std::string& value)
{
    _raw_content   = value;
    set_bytes_content(_raw_content.size());
}

KMALLUnknown KMALLUnknown::from_stream(std::istream& is, KMALLDatagram header)
{
    KMALLUnknown datagram(std::move(header));

    datagram._raw_content.resize(datagram.get_bytes_content());

    // verify the datagram is read correctly by reading the length field at the end
    is.read(datagram._raw_content.data(), datagram._raw_content.size());

    return datagram;
}

KMALLUnknown KMALLUnknown::from_stream(std::istream& is)
{
    return from_stream(is, KMALLDatagram::from_stream(is));
}

KMALLUnknown KMALLUnknown::from_stream(std::istream&             is,
                                       o_KMALLDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KMALLDatagram::from_stream(is, datagram_identifier));
}

void KMALLUnknown::to_stream(std::ostream& os)
{
    KMALLDatagram::to_stream(os);

    os.write(_raw_content.data(), _raw_content.size());
}

tools::classhelper::ObjectPrinter KMALLUnknown::__printer__(unsigned int float_precision,
                                                            bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "KMALLUnknown", float_precision, superscript_exponents);

    printer.append(KMALLDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("raw data", _raw_content.size(), "bytes");

    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
