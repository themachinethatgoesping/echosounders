// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "spreadingloss.hpp"

#include <utility>

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

// ----- constructors -----
SpreadingLoss::SpreadingLoss()
    : _content{}
{
    set_datagram_identifier(DatagramIdentifier);
}

SpreadingLoss::SpreadingLoss(S7KDatagram header)
    : S7KDatagram(std::move(header))
{
}

// ----- convenient member access -----
float SpreadingLoss::get_spreading_loss() const
{
    return _content._spreading_loss;
}
uint32_t SpreadingLoss::get_checksum() const
{
    return _content._checksum;
}

void SpreadingLoss::set_spreading_loss(float val)
{
    _content._spreading_loss = val;
}
void SpreadingLoss::set_checksum(uint32_t val)
{
    _content._checksum = val;
}

// ----- to/from stream functions -----
void SpreadingLoss::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);
}

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
        S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(fmt::format("S7K {} ({})",
                                                          o_datagram_identifier.name(),
                                                          uint32_t(o_datagram_identifier)),
                                              float_precision,
                                              superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("SpreadingLoss content");
    printer.register_value("spreading_loss", _content._spreading_loss, "dB");
    printer.register_value("checksum", _content._checksum);

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
