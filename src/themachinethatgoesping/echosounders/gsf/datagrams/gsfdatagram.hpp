// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/gsfdatagram.doc.hpp"

// std includes
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../types.hpp"
// #include "../misc/DateTime.h"
// #include "DSMToolsLib/HelperFunctions.h"

#include <boost/endian/conversion.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace gsf {
namespace datagrams {

class GSFDatagram
{
  public:
    using t_DatagramIdentifier = t_GSFDatagramIdentifier;

  protected:
    uint32_t _size_of_data; ///< number of bytes of the data portion of the datagram (excluding the
                            ///< header/checksum)
    t_DatagramIdentifier    _record_identifier;
    std::optional<uint32_t> _checksum;

  public:
    GSFDatagram(uint32_t                size_of_data,
                t_DatagramIdentifier    datagram_identifier = t_DatagramIdentifier::unspecified,
                std::optional<uint32_t> checksum            = std::nullopt)
        : _size_of_data(size_of_data)
        , _record_identifier(datagram_identifier)
        , _checksum(checksum)
    {
    }
    GSFDatagram()          = default;
    virtual ~GSFDatagram() = default;

    void skip(std::istream& is) const
    {
        // _bytes describes the bytes of the data portion after header
        is.seekg(_size_of_data, std::ios::cur);
    }

    // interface
    t_DatagramIdentifier get_datagram_identifier() const { return _record_identifier; }
    virtual double       get_timestamp() const { return std::numeric_limits<double>::quiet_NaN(); }

    /**
     * @brief Get the time as string
     *
     * @param fractionalSecondsDigits
     * @param format
     * @return std::string
     */
    std::string get_date_string(unsigned int       fractionalSecondsDigits = 2,
                                const std::string& format = "%z__%d-%m-%Y__%H:%M:%S") const
    {
        return tools::timeconv::unixtime_to_datestring(
            get_timestamp(), fractionalSecondsDigits, format);
    }

    // ----- convenient member access -----
    uint32_t                get_size_of_data() const { return _size_of_data; }
    t_DatagramIdentifier    get_record_identifier() const { return _record_identifier; }
    std::optional<uint32_t> get_checksum() const { return _checksum; }

    void set_size_of_data(uint32_t size_of_data) { _size_of_data = size_of_data; }
    void set_record_identifier(t_DatagramIdentifier datagram_identifier)
    {
        _record_identifier = datagram_identifier;
    }
    void set_checksum(std::optional<uint32_t> checksum) { _checksum = checksum; }

    // ----- operators -----
    bool operator==(const GSFDatagram& other) const = default;

    static GSFDatagram from_stream(std::istream& is)
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

    static GSFDatagram from_stream(std::istream& is, t_GSFDatagramIdentifier datagram_identifier)
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

    void to_stream(std::ostream& os) const
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

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
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

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(GSFDatagram)
};

} // namespace datagrams
} // namespace gsf
} // namespace echosounders
} // namespace themachinethatgoesping
