// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "fileheader.hpp"

#include <cstring>
#include <utility>

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

// ----- helper -----
std::string FileHeader::trim(const char* s, size_t n)
{
    return std::string(s, ::strnlen(s, n));
}

// ----- constructors -----
FileHeader::FileHeader()
    : _content{}
{
    set_datagram_identifier(DatagramIdentifier);
}

FileHeader::FileHeader(S7KDatagram header)
    : S7KDatagram(std::move(header))
{
}

// ----- record type header access -----
uint16_t FileHeader::get_version() const
{
    return _content._version;
}
uint32_t FileHeader::get_record_data_size() const
{
    return _content._record_data_size;
}
uint32_t FileHeader::get_number_devices() const
{
    return _content._number_devices;
}
std::string FileHeader::get_recording_name() const
{
    return trim(_content._recording_name, 64);
}
std::string FileHeader::get_recording_version() const
{
    return trim(_content._recording_version, 16);
}
std::string FileHeader::get_user_defined_name() const
{
    return trim(_content._user_defined_name, 64);
}
std::string FileHeader::get_notes() const
{
    return trim(_content._notes, 128);
}
uint32_t FileHeader::get_checksum() const
{
    return _checksum;
}
void FileHeader::set_checksum(uint32_t val)
{
    _checksum = val;
}

// ----- substructure access -----
const substructs::FileHeaderDeviceInfoContainer& FileHeader::get_devices() const
{
    return _devices;
}
substructs::FileHeaderDeviceInfoContainer& FileHeader::devices()
{
    return _devices;
}
void FileHeader::set_devices(const substructs::FileHeaderDeviceInfoContainer& devices)
{
    _devices = devices;
}

// ----- optional data (file catalog pointer, if present) -----
const std::string& FileHeader::get_optional_data() const
{
    return _optional_data;
}
bool FileHeader::has_file_catalog_info() const
{
    return _optional_data.size() >= 12;
}
uint32_t FileHeader::get_file_catalog_size() const
{
    uint32_t v = 0;
    if (has_file_catalog_info())
        std::memcpy(&v, _optional_data.data(), sizeof(v));
    return v;
}
uint64_t FileHeader::get_file_catalog_offset() const
{
    uint64_t v = 0;
    if (has_file_catalog_info())
        std::memcpy(&v, _optional_data.data() + 4, sizeof(v));
    return v;
}

void FileHeader::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);

    const size_t N       = _content._number_devices;
    auto&        devices = _devices.devices();
    devices.resize(N);

    // read all device entries as one contiguous block
    is.read(reinterpret_cast<char*>(devices.data()),
            std::streamsize(N * sizeof(substructs::FileHeaderDeviceInfo)));

    // read any trailing optional data (everything up to the 4-byte checksum at the record end)
    const size_t bytes_read = __content_size + N * sizeof(substructs::FileHeaderDeviceInfo);
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

    // read the trailing 4-byte checksum (stored for debugging only, not verified)
    if (content >= bytes_read + 4)
        is.read(reinterpret_cast<char*>(&_checksum), sizeof(_checksum));
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

    const auto& devices = _devices.get_devices();
    os.write(reinterpret_cast<const char*>(devices.data()),
             std::streamsize(devices.size() * sizeof(substructs::FileHeaderDeviceInfo)));

    os.write(_optional_data.data(), std::streamsize(_optional_data.size()));

    os.write(reinterpret_cast<const char*>(&_checksum), sizeof(_checksum));
}

tools::classhelper::ObjectPrinter FileHeader::__printer__(unsigned int float_precision,
                                                          bool         superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("FileHeader content");
    printer.register_value("version", _content._version);
    printer.register_value("number_devices", _content._number_devices);
    printer.register_string("recording_name", get_recording_name());
    printer.register_string("recording_version", get_recording_version());
    printer.register_string("user_defined_name", get_user_defined_name());
    printer.register_string("notes", get_notes());
    printer.register_value("checksum", _checksum);

    printer.register_section("devices");
    printer.append(_devices.__printer__(float_precision, superscript_exponents));

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
