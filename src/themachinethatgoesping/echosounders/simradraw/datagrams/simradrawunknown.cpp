// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "simradrawunknown.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

// ----- file I/O -----
SimradRawUnknown SimradRawUnknown::from_stream(std::istream& is, SimradRawDatagram header)
{
    SimradRawUnknown datagram(std::move(header));

    if (datagram.get_length() > 12)
        datagram._raw_content.resize(size_t(datagram.get_length() - 12));
    else
        throw std::runtime_error("ERROR[SimradRawUnknown::from_stream]: _length is too small");

    is.read(datagram._raw_content.data(), datagram._raw_content.size());

    // verify the datagram is read correctly by reading the length field at the end
    datagram._verify_datagram_end(is);

    return datagram;
}

SimradRawUnknown SimradRawUnknown::from_stream(std::istream& is)
{
    return from_stream(is, SimradRawDatagram::from_stream(is));
}

SimradRawUnknown SimradRawUnknown::from_stream(std::istream&              is,
                                             t_SimradRawDatagramIdentifier datagram_identifier)
{
    return from_stream(is, SimradRawDatagram::from_stream(is, datagram_identifier));
}

void SimradRawUnknown::to_stream(std::ostream& os)
{
    set_length(simradraw_long(12 + _raw_content.size()));
    SimradRawDatagram::to_stream(os);

    os.write(_raw_content.data(), _raw_content.size());
    os.write(reinterpret_cast<const char*>(&_length), sizeof(simradraw_long));
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter SimradRawUnknown::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("SimradRawUnknown", float_precision, superscript_exponents);

    printer.append(SimradRawDatagram::__printer__(float_precision, superscript_exponents));

    return printer;
}

} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
