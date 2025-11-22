// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "iopruntime.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

IOpRuntime::IOpRuntime()
{
    _datagram_identifier = DatagramIdentifier;
}
// ----- getters -----
uint16_t IOpRuntime::get_bytes_content() const
{
    return _bytes_content;
}

uint16_t IOpRuntime::get_info() const
{
    return _info;
}

uint16_t IOpRuntime::get_status() const
{
    return _status;
}

const std::string& IOpRuntime::get_runtime_txt() const
{
    return _runtime_txt;
}

uint32_t IOpRuntime::get_bytes_datagram_check() const
{
    return _bytes_datagram_check;
}

// setters
// void IOpRuntime::set_bytes_content(uint16_t bytes_content) {
//     _bytes_content = bytes_content;
// }

void IOpRuntime::set_info(uint16_t info)
{
    _info = info;
}

void IOpRuntime::set_status(uint16_t status)
{
    _status = status;
}

void IOpRuntime::set_runtime_txt(std::string_view runtime_txt)
{
    static constexpr size_t dbytes = 3 * sizeof(uint16_t) + sizeof(uint32_t);

    _bytes_content = dbytes + runtime_txt.size() * sizeof(char); // size of the string in bytes

    _runtime_txt.assign(runtime_txt.begin(), runtime_txt.end());

    // increase _bytes_content to 4 byte alignment
    if (_bytes_content % 4 != 0)
    {
        _bytes_content += 4 - (_bytes_content % 4);
    }

    _runtime_txt.resize(_bytes_content - dbytes, '\0'); // pad with null characters
    set_bytes_datagram(KMALLDatagram::__size + _bytes_content);
    _bytes_datagram_check = get_bytes_datagram();
}

// ----- processed data access -----

// ----- to/from stream functions -----
void IOpRuntime::__read__(std::istream& is)
{
    static constexpr size_t dbytes = 3 * sizeof(uint16_t) + sizeof(uint32_t);

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(_bytes_content)), 3 * sizeof(uint16_t));

    _runtime_txt.resize(compute_size_content() - dbytes); // minus size of the previous fields
    is.read(_runtime_txt.data(), _runtime_txt.size());
    is.read(reinterpret_cast<char*>(&(_bytes_datagram_check)), sizeof(_bytes_datagram_check));
}

IOpRuntime IOpRuntime::from_stream(std::istream& is, const KMALLDatagram& header)
{
    IOpRuntime datagram(header);
    datagram.__read__(is);

    return datagram;
}

IOpRuntime IOpRuntime::from_stream(std::istream& is, o_KMALLDatagramIdentifier datagram_identifier)
{
    IOpRuntime datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__check_datagram_identifier__(datagram_identifier, DatagramIdentifier);
    datagram.__read__(is);
    return datagram;
}

IOpRuntime IOpRuntime::from_stream(std::istream& is)
{
    IOpRuntime datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read__(is);
    return datagram;
}

void IOpRuntime::to_stream(std::ostream& os) const
{
    KMALLDatagram::to_stream(os);

    // TODO: verify sizes and alignments before writing

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&_bytes_content), 3 * sizeof(uint16_t));
    // write the installation paramaters string
    os.write(reinterpret_cast<const char*>(_runtime_txt.data()),
             _runtime_txt.size() * sizeof(char));
    os.write(reinterpret_cast<const char*>(&_bytes_datagram_check), sizeof(_bytes_datagram_check));
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter IOpRuntime::__printer__(unsigned int float_precision,
                                                          bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("IOpRuntime", float_precision, superscript_exponents);

    printer.append(KMALLDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("bytes_content", _bytes_content);
    printer.register_value("info", _info);
    printer.register_value("status", _status);
    printer.register_value("bytes datagram check", _bytes_datagram_check, "bytes");
    printer.register_section("runtime_txt");
    printer.register_string("runtime_txt", _runtime_txt);
    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
