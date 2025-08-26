// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "NME0.hpp"

#include <stdexcept>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

// ----- file I/O -----
NME0 NME0::from_stream(std::istream& is, SimradRawDatagram header)
{
    NME0 datagram(std::move(header));
    datagram._nmea_base =
        navigation::nmea_0183::NMEA_Base::from_stream(is, datagram._length - 12);

    // verify the datagram is read correctly by reading the length field at the end
    datagram._verify_datagram_end(is);

    return datagram;
}

NME0 NME0::from_stream(std::istream& is)
{
    return from_stream(is, SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::NME0));
}

NME0 NME0::from_stream(std::istream& is, t_SimradRawDatagramIdentifier type)
{
    if (type != t_SimradRawDatagramIdentifier::NME0)
        throw std::runtime_error("NME0::from_stream: wrong datagram type");

    return from_stream(is, SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::NME0));
}

void NME0::to_stream(std::ostream& os)
{
    _length        = simradraw_long(12 + _nmea_base.size());
    _datagram_type = simradraw_long(t_SimradRawDatagramIdentifier::NME0);
    SimradRawDatagram::to_stream(os);
    _nmea_base.to_stream_dont_write_size(os);
    os.write(reinterpret_cast<const char*>(&_length), sizeof(_length));
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter NME0::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("NMEA text datagram", float_precision, superscript_exponents);

    printer.append(SimradRawDatagram::__printer__(float_precision, superscript_exponents));

    printer.register_section("Nmea sentence");
    printer.register_value("Sender", get_sender_id(), "");
    printer.register_value("Type", get_sentence_type(), "");
    printer.register_value("Full sentence", get_sentence(), "");

    return printer;
}

} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
