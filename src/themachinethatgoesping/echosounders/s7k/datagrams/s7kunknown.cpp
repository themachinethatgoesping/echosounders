// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "s7kunknown.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

S7KUnknown S7KUnknown::from_stream(std::istream& is, S7KDatagram header)
{
    S7KUnknown datagram(std::move(header));

    datagram._raw_content.resize(datagram.compute_size_content());
    is.read(datagram._raw_content.data(), datagram._raw_content.size());

    return datagram;
}

S7KUnknown S7KUnknown::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

S7KUnknown S7KUnknown::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void S7KUnknown::to_stream(std::ostream& os)
{
    _size = uint32_t(_raw_content.size() + __size);
    S7KDatagram::to_stream(os);
    os.write(_raw_content.data(), _raw_content.size());
}

tools::classhelper::ObjectPrinter S7KUnknown::__printer__(unsigned int float_precision,
                                                          bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("S7KUnknown", float_precision, superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("raw data", _raw_content.size(), "bytes");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
