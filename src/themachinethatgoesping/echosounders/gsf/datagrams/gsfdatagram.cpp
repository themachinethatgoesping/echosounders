// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "gsfdatagram.hpp"

/* std includes */
#include <fmt/core.h>

/* external includes */
#include <boost/endian/conversion.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace gsf {
namespace datagrams {

GSFDatagram GSFDatagram::from_stream(std::istream& is)
{
    GSFDatagram d;

    // Read multiple values at once
    is.read(reinterpret_cast<char*>(&d._size_of_data), 2 * sizeof(uint32_t));

    // First convert from big-endian to native endianness
    boost::endian::big_to_native_inplace(d._size_of_data);
    boost::endian::big_to_native_inplace(d._record_identifier);

    // Extract the checksum flag (bit 31, most significant bit)
    bool has_checksum = (static_cast<uint32_t>(d._record_identifier) & 0x80000000) != 0;

    // Extract the actual record identifier (bits 0-21, 22 least significant bits)
    // record identifier is combination of registry number and data type number
    d._record_identifier = static_cast<t_DatagramIdentifier>(
        static_cast<uint32_t>(d._record_identifier) & 0x003FFFFF);

    // Set the checksum flag if present
    if (has_checksum)
    {
        // If checksum flag is set, we need to read the checksum value
        uint32_t checksum;
        is.read(reinterpret_cast<char*>(&checksum), sizeof(uint32_t));
        d._checksum = boost::endian::big_to_native(checksum);
    }
    else
    {
        d._checksum = std::nullopt;
    }

    return d;
}

GSFDatagram GSFDatagram::from_stream(std::istream& is, t_GSFDatagramIdentifier datagram_identifier)
{
    GSFDatagram d = from_stream(is);

    if (d.get_record_identifier() != datagram_identifier)
        throw std::runtime_error(
            fmt::format("GSFDatagram::skip_and_verify_header: datagram "
                        "identifier is not {}, but {}",
                        datagram_type_to_string(datagram_identifier),
                        datagram_type_to_string(d.get_record_identifier())));

    return d;
}

void GSFDatagram::to_stream(std::ostream& os) const
{
    // Create copies of the values to convert
    struct
    {
        uint32_t size_of_data;
        uint32_t id_raw;
        uint32_t checksum;
    } copy;

    // Create copies of the values to convert
    copy.size_of_data = _size_of_data;

    // Prepare the record identifier with the appropriate bits set
    copy.id_raw = static_cast<uint32_t>(_record_identifier) & 0x003FFFFF; // Keep only 22 bits

    // Set checksum bit if needed
    if (_checksum.has_value())
    {
        copy.id_raw |= 0x80000000; // Set the most significant bit
    }

    // Convert to big-endian
    boost::endian::native_to_big_inplace(copy.size_of_data);
    boost::endian::native_to_big_inplace(copy.id_raw);

    // Write checksum if present
    if (_checksum.has_value())
    {
        copy.checksum = _checksum.value();
        boost::endian::native_to_big_inplace(copy.checksum);
        // Write the values
        os.write(reinterpret_cast<const char*>(&copy), sizeof(copy));
    }
    else
    {
        // Write the values without checksum
        os.write(reinterpret_cast<const char*>(&copy), sizeof(uint32_t) * 2);
    }
}

tools::classhelper::ObjectPrinter GSFDatagram::__printer__(unsigned int float_precision,
                                                          bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "GSFDatagram", float_precision, superscript_exponents);

    printer.register_value("size_of_data", _size_of_data);
    printer.register_string(
        "record_identifier",
        fmt::format("0x{:02x}", uint8_t(_record_identifier)),
        datagram_identifier_to_string(t_GSFDatagramIdentifier(_record_identifier)));

    if (_checksum.has_value())
    {
        printer.register_value("checksum", _checksum.value());
    }
    else
    {
        printer.register_string("checksum", "none");
    }

    // time processing (if time is provided)
    auto timestamp = get_timestamp();
    if (std::isfinite(timestamp))
    {
        static const std::string format_date("%d/%m/%Y");
        static const std::string format_time("%H:%M:%S");
        using tools::timeconv::unixtime_to_datestring;
        auto date = unixtime_to_datestring(timestamp, 0, format_date);
        auto time = unixtime_to_datestring(timestamp, 3, format_time);

        printer.register_section("date/time");
        printer.register_value("timestamp", timestamp, "s");
        printer.register_string("date", date, "MM/DD/YYYY");
        printer.register_string("time", time, "HH:MM:SS");
    }

    return printer;
}

} // namespace datagrams
} // namespace gsf  
} // namespace echosounders
} // namespace themachinethatgoesping
