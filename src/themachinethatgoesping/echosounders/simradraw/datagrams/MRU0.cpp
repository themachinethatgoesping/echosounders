// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "MRU0.hpp"

#include <stdexcept>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

// ----- operators -----
bool MRU0::operator==(const MRU0& other) const
{
    using tools::helper::approx;

    return SimradRawDatagram::operator==(other) && approx(_heave, other._heave) &&
           approx(_roll, other._roll) && approx(_pitch, other._pitch) &&
           approx(_heading, other._heading);
}

// ----- file I/O -----
MRU0 MRU0::from_stream(std::istream& is, SimradRawDatagram header)
{
    MRU0 datagram(std::move(header));
    is.read(reinterpret_cast<char*>(&datagram._heave), 4 * sizeof(simradraw_float));

    // verify the datagram is read correctly by reading the length field at the end
    datagram._verify_datagram_end(is);

    return datagram;
}

MRU0 MRU0::from_stream(std::istream& is)
{
    return from_stream(is,
                       SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::MRU0));
}

MRU0 MRU0::from_stream(std::istream& is, t_SimradRawDatagramIdentifier type)
{
    if (type != t_SimradRawDatagramIdentifier::MRU0)
        throw std::runtime_error("MRU0::from_stream: wrong datagram type");

    return from_stream(is,
                       SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::MRU0));
}

void MRU0::to_stream(std::ostream& os)
{
    set_length(simradraw_long(12 + 4 * sizeof(simradraw_float)));
    set_datagram_type(simradraw_long(t_SimradRawDatagramIdentifier::MRU0));
    SimradRawDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_heave), 4 * sizeof(simradraw_float));
    os.write(reinterpret_cast<const char*>(&(_length)), sizeof(simradraw_long));
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter MRU0::__printer__(unsigned int float_precision,
                                              bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "Motion binary datagram", float_precision, superscript_exponents);

    printer.append(SimradRawDatagram::__printer__(float_precision, superscript_exponents));

    printer.register_section("Motion data");
    printer.register_value("heave", _heave, "m");
    printer.register_value("roll", _roll, "°");
    printer.register_value("pitch", _pitch, "°");
    printer.register_value("heading", _heading, "°");

    return printer;
}

} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
