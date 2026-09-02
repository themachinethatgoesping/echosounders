// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "fileheader.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

void FileHeader::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);

    const size_t N = _content.number_devices;
    _device_identifier.resize({ N });
    _system_enumerator.resize({ N });

    for (size_t i = 0; i < N; ++i)
    {
        uint32_t device_id = 0;
        uint16_t enumerator = 0;
        is.read(reinterpret_cast<char*>(&device_id), sizeof(device_id));
        is.read(reinterpret_cast<char*>(&enumerator), sizeof(enumerator));
        _device_identifier.unchecked(i) = device_id;
        _system_enumerator.unchecked(i) = enumerator;
    }

    // read any trailing optional data (everything up to the 4-byte checksum at the record end)
    const size_t bytes_read = __content_size + N * 6;
    const size_t content    = compute_size_content();
    if (content > bytes_read + 4)
    {
        _optional_data.resize(content - bytes_read - 4);
        is.read(_optional_data.data(), std::streamsize(_optional_data.size()));
    }
    else
    {
        _optional_data.clear();
    }
}

FileHeader FileHeader::from_stream(std::istream& is, S7KDatagram header)
{
    FileHeader datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

FileHeader FileHeader::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

FileHeader FileHeader::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void FileHeader::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);

    for (size_t i = 0; i < _content.number_devices; ++i)
    {
        uint32_t device_id  = _device_identifier.unchecked(i);
        uint16_t enumerator = _system_enumerator.unchecked(i);
        os.write(reinterpret_cast<const char*>(&device_id), sizeof(device_id));
        os.write(reinterpret_cast<const char*>(&enumerator), sizeof(enumerator));
    }

    os.write(_optional_data.data(), std::streamsize(_optional_data.size()));
}

tools::classhelper::ObjectPrinter FileHeader::__printer__(unsigned int float_precision,
                                                          bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("FileHeader", float_precision, superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("FileHeader content");
    printer.register_value("version", _content.version);
    printer.register_value("number_devices", _content.number_devices);
    printer.register_string("recording_name", get_recording_name());
    printer.register_string("recording_version", get_recording_version());
    printer.register_string("user_defined_name", get_user_defined_name());
    printer.register_string("notes", get_notes());
    printer.register_container("device_identifier", _device_identifier);
    printer.register_container("system_enumerator", _system_enumerator);

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
