// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../em3000_types.hpp"
//#include "../misc/DateTime.h"
//#include "DSMToolsLib/HelperFunctions.h"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {

struct EM3000Datagram
{
    using t_DatagramIdentifier = t_EM3000DatagramIdentifier;

    uint32_t _Bytes;
    uint8_t  _Identifyer;
    t_DatagramIdentifier _Datagramtype;
    uint16_t _ModelNumber;
    uint32_t _Date;
    uint32_t _Time_since_midnight;  // in milliseconds

  protected:
    /**
     * @brief verify the datagram is read correctly by reading the length field at the end
     *
     * @param is istream. Must be at the end position of the datagram. Pos will be incremented by 4
     * bytes (em3000_long).
     */
    void _verify_datagram_end(std::istream& is) const
    {
        // verify that we are at the end of the datagram by reading the enclosing length field
        // This should be the same as _Length if everything is ok
        em3000_long length;
        is.read(reinterpret_cast<char*>(&length), sizeof(length));

        // (the datagrams are encapsulated by length)
        // if the lengths do not match the datagrams was not read correctly
        if (!is || length != _Length)
        {
            auto error = fmt::format(
                "ERROR[EM3000Datagram]: Datagram length check failed (read). Expected: {}, got: {}",
                _Length,
                length);
            [[maybe_unused]] auto error_verbose =
                fmt::format("{}\n--- read header ---\n{}\n---", error, info_string());

            throw std::runtime_error(error);
            // std::cerr << error << std::endl;
        }
    }

  public:
    EM3000Datagram(em3000_long length,
                   em3000_long datagram_type,
                   em3000_long low_data_time  = 0,
                   em3000_long high_date_time = 0)
        : _Length(length)
        , _DatagramType(datagram_type)
        , _LowDateTime(low_data_time)
        , _HighDateTime(high_date_time)
    {
    }
    EM3000Datagram()          = default;
    virtual ~EM3000Datagram() = default;

    void skip(std::istream& is) const
    {
        // _Length is the length the datagram that is enclosed by _Length
        const static em3000_long tmp = sizeof(em3000_long) * 3;

        is.seekg(_Length - tmp, std::ios::cur);

        // verify the datagram is read correctly by reading the length field at the end
        _verify_datagram_end(is);
    }

    //----- convenient member access -----
    /**
     * @brief length of the datagram in bytes (excluding the length fields at the beginning and end
     * of the datagram)
     */
    em3000_long get_length() const { return _Length; }
    void        set_length(em3000_long length) { _Length = length; }

    /**
     * @brief Ek60 datagram type (XML0, FIL1, NME0, MRU0, RAW3, ...)
     *
     */
    t_EM3000DatagramIdentifier get_datagram_identifier() const
    {
        return t_EM3000DatagramIdentifier(_DatagramType);
    }
    void set_datagram_identifier(t_EM3000DatagramIdentifier datagram_type)
    {
        _DatagramType = em3000_long(datagram_type);
    }

    /**
     * @brief unix timestamp in seconds since epoch (1970-01-01). Data is converted to/from internal
     * windows high/low timestamp representation.
     */
    double get_timestamp() const
    {
        return tools::timeconv::windows_filetime_to_unixtime(_HighDateTime, _LowDateTime);
    }

    void set_timestamp(double unixtime)
    {
        std::tie(_HighDateTime, _LowDateTime) =
            tools::timeconv::unixtime_to_windows_filetime(unixtime);
    }

    std::string get_date_string(unsigned int       fractionalSecondsDigits = 2,
                                const std::string& format = "%z__%d-%m-%Y__%H:%M:%S") const
    {
        return tools::timeconv::unixtime_to_datestring(
            get_timestamp(), fractionalSecondsDigits, format);
    }

    // ----- operators -----
    bool operator==(const EM3000Datagram& other) const
    {
        return _Length == other._Length && _DatagramType == other._DatagramType &&
               _LowDateTime == other._LowDateTime && _HighDateTime == other._HighDateTime;
    }
    bool operator!=(const EM3000Datagram& other) const { return !operator==(other); }

    static EM3000Datagram from_stream(std::istream& is)
    {
        EM3000Datagram d;
        is.read(reinterpret_cast<char*>(&d._Length), 4 * sizeof(em3000_long));

        return d;
    }

    static EM3000Datagram from_stream(std::istream&              is,
                                      t_EM3000DatagramIdentifier datagram_identifier)
    {
        EM3000Datagram d = from_stream(is);

        if (d.get_datagram_identifier() != datagram_identifier)
            throw std::runtime_error(fmt::format("EM3000Datagram: Datagram identifier mismatch!"));

        return d;
    }

    void to_stream(std::ostream& os)
    {
        os.write(reinterpret_cast<char*>(&_Length), 4 * sizeof(em3000_long));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        using tools::timeconv::unixtime_to_datestring;

        static const std::string format_data("%d/%m/%Y");
        static const std::string format_time("%H:%M:%S");
        auto                     timestamp = get_timestamp();

        auto date = unixtime_to_datestring(timestamp, 0, format_data);
        auto time = unixtime_to_datestring(timestamp, 3, format_time);

        tools::classhelper::ObjectPrinter printer("EM3000Datagram", float_precision);

        printer.register_value("length", _Length, "bytes");
        printer.register_string(
            "datagram_type",
            datagram_identifier_to_string(t_EM3000DatagramIdentifier(_DatagramType)));
        printer.register_value("timestamp", timestamp, "s");
        printer.register_string("date", date, "MM/DD/YYYY");
        printer.register_string("time", time, "HH:MM:SS");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(EM3000Datagram)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping