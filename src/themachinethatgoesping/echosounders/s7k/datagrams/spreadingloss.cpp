// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "spreadingloss.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

SpreadingLoss SpreadingLoss::from_stream(std::istream& is, S7KDatagram header)
{
    SpreadingLoss datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

SpreadingLoss SpreadingLoss::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

SpreadingLoss SpreadingLoss::from_stream(std::istream&           is,
                                         o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void SpreadingLoss::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);
}

tools::classhelper::ObjectPrinter SpreadingLoss::__printer__(unsigned int float_precision,
                                                             bool superscript_exponents) const
{
    const auto& o_datagram_identifier =
        S7KDatagram::o_DatagramIdentifier(get_datagram_identifier());
    tools::classhelper::ObjectPrinter printer(fmt::format("S7KHeader {} ({})",
                                                          o_datagram_identifier.name(),
                                                          uint32_t(o_datagram_identifier)),
                                              float_precision,
                                              superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("SpreadingLoss content");
    printer.register_value("spreading_loss", _content.spreading_loss, "dB");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
