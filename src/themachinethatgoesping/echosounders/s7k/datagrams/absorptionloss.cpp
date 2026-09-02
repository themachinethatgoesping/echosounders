// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "absorptionloss.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

AbsorptionLoss AbsorptionLoss::from_stream(std::istream& is, S7KDatagram header)
{
    AbsorptionLoss datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

AbsorptionLoss AbsorptionLoss::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

AbsorptionLoss AbsorptionLoss::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void AbsorptionLoss::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);
}

tools::classhelper::ObjectPrinter AbsorptionLoss::__printer__(unsigned int float_precision,
                                                     bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("AbsorptionLoss", float_precision, superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("AbsorptionLoss content");
    printer.register_value("absorption_loss", _content.absorption_loss, "dB/km");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
