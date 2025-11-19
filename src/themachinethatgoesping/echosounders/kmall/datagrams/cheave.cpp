// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "cheave.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

CHeave::CHeave()
{
    _datagram_identifier = DatagramIdentifier;
}

// ----- setters -----

// ----- processed data access -----

// ----- to/from stream functions -----
void CHeave::__read__(std::istream& is)
{
    //static constexpr size_t dbytes = __size + KMALLMultibeamDatagram::__size + sizeof(uint32_t);

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&_content), __size);

    // read position data string
    is.read(reinterpret_cast<char*>(&(_bytes_datagram_check)), sizeof(_bytes_datagram_check));
}

CHeave CHeave::from_stream(std::istream& is, const KMALLDatagram& header)
{
    CHeave datagram(header);
    datagram.__read_multibeamdatagram_no_mpart__(is);
    datagram.__read__(is);

    return datagram;
}

CHeave CHeave::from_stream(std::istream& is, o_KMALLDatagramIdentifier datagram_identifier)
{
    CHeave datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__check_datagram_identifier__(datagram_identifier, DatagramIdentifier);
    datagram.__read_multibeamdatagram_no_mpart__(is);
    datagram.__read__(is);
    return datagram;
}

CHeave CHeave::from_stream(std::istream& is)
{
    CHeave datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read_multibeamdatagram_no_mpart__(is);
    datagram.__read__(is);
    return datagram;
}

void CHeave::to_stream(std::ostream& os)
{
    KMALLDatagram::to_stream(os);
    KMALLMultibeamDatagram::to_stream_no_mpart(os);

    os.write(reinterpret_cast<char*>(&_content), __size);
    os.write(reinterpret_cast<const char*>(&_bytes_datagram_check), sizeof(_bytes_datagram_check));
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter CHeave::__printer__(unsigned int float_precision,
                                                      bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("CHeave", float_precision, superscript_exponents);

    // false is mpart skipped
    printer.append(KMALLMultibeamDatagram::__printer__(float_precision, superscript_exponents, false));

    printer.register_section("datagram content");
    printer.register_value("heave_m", _content.heave_m, "m");
    printer.register_value("bytes_datagram_check", _bytes_datagram_check, "bytes");

    // printer.register_section("processed");

    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
