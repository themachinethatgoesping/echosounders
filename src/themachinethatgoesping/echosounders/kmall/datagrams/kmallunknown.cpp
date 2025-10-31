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
    _raw_content = value;
    set_bytes_datagram(_raw_content.size() + KMALLDatagram::__size + sizeof(_bytes_datagram_check));
    _bytes_datagram_check = get_bytes_datagram();
}

KMALLUnknown KMALLUnknown::from_stream(std::istream& is, KMALLDatagram header)
{
    KMALLUnknown datagram(std::move(header));

    datagram._raw_content.resize(datagram.compute_size_content() -
                                 sizeof(datagram._bytes_datagram_check));

    // verify the datagram is read correctly by reading the length field at the end
    is.read(datagram._raw_content.data(), datagram._raw_content.size());
    is.read(reinterpret_cast<char*>(&datagram._bytes_datagram_check),
            sizeof(datagram._bytes_datagram_check));

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
    os.write(reinterpret_cast<const char*>(&_bytes_datagram_check), sizeof(_bytes_datagram_check));
}

tools::classhelper::ObjectPrinter KMALLUnknown::__printer__(unsigned int float_precision,
                                                            bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "KMALLUnknown", float_precision, superscript_exponents);

    printer.append(KMALLDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("raw data", _raw_content.size(), "bytes");
    printer.register_value("bytes datagram check", _bytes_datagram_check, "bytes");

    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
