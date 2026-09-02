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

    const size_t N       = _content.number_devices;
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
    printer.register_value("version", _content.version);
    printer.register_value("number_devices", _content.number_devices);
    printer.register_string("recording_name", get_recording_name());
    printer.register_string("recording_version", get_recording_version());
    printer.register_string("user_defined_name", get_user_defined_name());
    printer.register_string("notes", get_notes());

    printer.register_section("devices");
    printer.append(_devices.__printer__(float_precision, superscript_exponents));

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
