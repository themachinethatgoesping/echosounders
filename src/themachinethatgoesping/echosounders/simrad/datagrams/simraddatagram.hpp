// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simraddatagram.doc.hpp"

// std includes
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../simrad_types.hpp"
// #include "../misc/DateTime.h"
// #include "DSMToolsLib/HelperFunctions.h"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {

class SimradDatagram
{
  protected:
    using t_DatagramIdentifier = t_SimradDatagramIdentifier;

    simrad_long _length;        ///< Raw: Length of the datagram in bytes
    simrad_long _datagram_type; ///< Raw: Datagram type as
    simrad_long
        _low_date_time; ///< Raw: Low part of Windows NT FILETIME (100ns ticks since 1601-01-01)
    simrad_long
        _high_date_time; ///< Raw: High part of Windows NT FILETIME (100ns ticks since 1601-01-01)

  protected:
    /**
     * @brief verify the datagram is read correctly by reading the length field at the end
     *
     * @param is istream. Must be at the end position of the datagram. Pos will be incremented by 4
     * bytes (simrad_long).
     */
    void _verify_datagram_end(std::istream& is) const
    {
        // verify that we are at the end of the datagram by reading the enclosing length field
        // This should be the same as _length if everything is ok
        simrad_long length;
        is.read(reinterpret_cast<char*>(&length), sizeof(length));

        // (the datagrams are encapsulated by length)
        // if the lengths do not match the datagrams was not read correctly
        if (!is || length != _length)
        {
            auto error = fmt::format(
                "ERROR[SimradDatagram]: Datagram length check failed (read). Expected: {}, got: {}",
                _length,
                length);
            [[maybe_unused]] auto error_verbose =
                fmt::format("{}\n--- read header ---\n{}\n---", error, info_string());

            throw std::runtime_error(error);
            // std::cerr << error << std::endl;
        }
    }

  public:
    SimradDatagram(simrad_long length,
                   simrad_long datagram_type,
                   simrad_long low_data_time  = 0,
                   simrad_long high_date_time = 0)
        : _length(length)
        , _datagram_type(datagram_type)
        , _low_date_time(low_data_time)
        , _high_date_time(high_date_time)
    {
    }
    SimradDatagram()          = default;
    virtual ~SimradDatagram() = default;

    void skip(std::istream& is) const
    {
        // _length is the length the datagram that is enclosed by _length
        const static simrad_long tmp = sizeof(simrad_long) * 3;

        is.seekg(_length - tmp, std::ios::cur);

        // verify the datagram is read correctly by reading the length field at the end
        _verify_datagram_end(is);
    }

    //----- convenient member access -----
    /**
     * @brief length of the datagram in bytes (excluding the length fields at the beginning and end
     * of the datagram)
     */
    simrad_long get_length() const { return _length; }
    void        set_length(simrad_long length) { _length = length; }

    simrad_long get_datagram_type() const { return _datagram_type; }
    void        set_datagram_type(simrad_long datagram_type) { _datagram_type = datagram_type; }

    simrad_long get_low_date_time() const { return _low_date_time; }
    void        set_low_date_time(simrad_long low_date_time) { _low_date_time = low_date_time; }

    simrad_long get_high_date_time() const { return _high_date_time; }
    void        set_high_date_time(simrad_long high_date_time) { _high_date_time = high_date_time; }

    /**
     * @brief Ek60 datagram type (XML0, FIL1, NME0, MRU0, RAW3, ...)
     *
     */
    t_SimradDatagramIdentifier get_datagram_identifier() const
    {
        return t_SimradDatagramIdentifier(_datagram_type);
    }
    void set_datagram_identifier(t_SimradDatagramIdentifier datagram_type)
    {
        _datagram_type = simrad_long(datagram_type);
    }

    /**
     * @brief unix timestamp in seconds since epoch (1970-01-01). Data is converted to/from internal
     * windows high/low timestamp representation.
     */
    double get_timestamp() const
    {
        return tools::timeconv::windows_filetime_to_unixtime(_high_date_time, _low_date_time);
    }

    void set_timestamp(double unixtime)
    {
        std::tie(_high_date_time, _low_date_time) =
            tools::timeconv::unixtime_to_windows_filetime(unixtime);
    }

    std::string get_date_string(unsigned int       fractionalSecondsDigits = 2,
                                const std::string& format = "%z__%d-%m-%Y__%H:%M:%S") const
    {
        return tools::timeconv::unixtime_to_datestring(
            get_timestamp(), fractionalSecondsDigits, format);
    }

    // ----- operators -----
    bool operator==(const SimradDatagram& other) const
    {
        return _length == other._length && _datagram_type == other._datagram_type &&
               _low_date_time == other._low_date_time && _high_date_time == other._high_date_time;
    }
    bool operator!=(const SimradDatagram& other) const { return !operator==(other); }

    static SimradDatagram from_stream(std::istream& is)
    {
        SimradDatagram d;
        is.read(reinterpret_cast<char*>(&d._length), 4 * sizeof(simrad_long));

        return d;
    }

    static SimradDatagram from_stream(std::istream&              is,
                                      t_SimradDatagramIdentifier datagram_identifier)
    {
        SimradDatagram d = from_stream(is);

        if (d.get_datagram_identifier() != datagram_identifier)
            throw std::runtime_error(fmt::format("SimradDatagram: Datagram identifier mismatch!"));

        return d;
    }

    void to_stream(std::ostream& os)
    {
        os.write(reinterpret_cast<char*>(&_length), 4 * sizeof(simrad_long));
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

        tools::classhelper::ObjectPrinter printer("SimradDatagram", float_precision);

        printer.register_value("length", _length, "bytes");
        printer.register_string(
            "datagram_identifier",
            datagram_identifier_to_string(t_SimradDatagramIdentifier(_datagram_type)));
        printer.register_value("timestamp", timestamp, "s");
        printer.register_string("date", date, "MM/DD/YYYY");
        printer.register_string("time", time, "HH:MM:SS");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(SimradDatagram)
};

} // namespace datagrams
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
