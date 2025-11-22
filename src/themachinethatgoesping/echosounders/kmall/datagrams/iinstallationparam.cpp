// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "iinstallationparam.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

IInstallationParam::IInstallationParam()
{
    _datagram_identifier = DatagramIdentifier;
}
// ----- getters -----
uint16_t IInstallationParam::get_bytes_content() const
{
    return _bytes_content;
}

uint16_t IInstallationParam::get_info() const
{
    return _info;
}

uint16_t IInstallationParam::get_status() const
{
    return _status;
}

const std::string& IInstallationParam::get_install_txt() const
{
    return _install_txt;
}

uint32_t IInstallationParam::get_bytes_datagram_check() const
{
    return _bytes_datagram_check;
}

// setters
// void IInstallationParam::set_bytes_content(uint16_t bytes_content) {
//     _bytes_content = bytes_content;
// }

void IInstallationParam::set_info(uint16_t info)
{
    _info = info;
}

void IInstallationParam::set_status(uint16_t status)
{
    _status = status;
}

void IInstallationParam::set_install_txt(std::string_view install_txt)
{
    static constexpr size_t dbytes = 3 * sizeof(uint16_t) + sizeof(uint32_t);

    _bytes_content = dbytes + install_txt.size() * sizeof(char); // size of the string in bytes

    _install_txt.assign(install_txt.begin(), install_txt.end());

    // increase _bytes_content to 4 byte alignment
    if (_bytes_content % 4 != 0)
    {
        _bytes_content += 4 - (_bytes_content % 4);
    }

    _install_txt.resize(_bytes_content - dbytes, '\0'); // pad with null characters
    set_bytes_datagram(KMALLDatagram::__size + _bytes_content);
    _bytes_datagram_check = get_bytes_datagram();
}

// ----- processed data access -----

// ----- to/from stream functions -----
void IInstallationParam::__read__(std::istream& is)
{
    static constexpr size_t dbytes = 3 * sizeof(uint16_t) + sizeof(uint32_t);

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(_bytes_content)), 3 * sizeof(uint16_t));

    _install_txt.resize(compute_size_content() - dbytes); // minus size of the previous fields
    is.read(_install_txt.data(), _install_txt.size());
    is.read(reinterpret_cast<char*>(&(_bytes_datagram_check)), sizeof(_bytes_datagram_check));
}

IInstallationParam IInstallationParam::from_stream(std::istream& is, const KMALLDatagram& header)
{
    IInstallationParam datagram(header);
    datagram.__read__(is);

    return datagram;
}

IInstallationParam IInstallationParam::from_stream(std::istream&             is,
                                                   o_KMALLDatagramIdentifier datagram_identifier)
{
    IInstallationParam datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__check_datagram_identifier__(datagram_identifier, DatagramIdentifier);
    datagram.__read__(is);
    return datagram;
}

IInstallationParam IInstallationParam::from_stream(std::istream& is)
{
    IInstallationParam datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read__(is);
    return datagram;
}

void IInstallationParam::to_stream(std::ostream& os) const
{
    KMALLDatagram::to_stream(os);

    // TODO: verify sizes and alignments before writing

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&_bytes_content), 3 * sizeof(uint16_t));
    // write the installation paramaters string
    os.write(reinterpret_cast<const char*>(_install_txt.data()),
             _install_txt.size() * sizeof(char));
    os.write(reinterpret_cast<const char*>(&_bytes_datagram_check), sizeof(_bytes_datagram_check));
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter IInstallationParam::__printer__(unsigned int float_precision,
                                                                  bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "IInstallationParam", float_precision, superscript_exponents);

    printer.append(KMALLDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("bytes_content", _bytes_content);
    printer.register_value("info", _info);
    printer.register_value("status", _status);
    printer.register_value("bytes datagram check", _bytes_datagram_check, "bytes");
    printer.register_section("install_txt");
    printer.register_string("install_txt", _install_txt);
    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
