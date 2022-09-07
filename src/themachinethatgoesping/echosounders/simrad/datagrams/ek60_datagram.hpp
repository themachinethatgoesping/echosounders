// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelpers/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../ek60_types.hpp"
//#include "../misc/DateTime.h"
//#include "DSMToolsLib/HelperFunctions.h"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {

struct EK60_Datagram
{
    ek60_long _Length;       ///< Raw: Length of the datagram in bytes
    ek60_long _DatagramType; ///< Raw: Datagram type as
    ek60_long _LowDateTime; ///< Raw: Low part of Windows NT FILETIME (100ns ticks since 1601-01-01)
    ek60_long
        _HighDateTime; ///< Raw: High part of Windows NT FILETIME (100ns ticks since 1601-01-01)


  public:
    EK60_Datagram()          = default;
    virtual ~EK60_Datagram() = default;

    void skip(std::istream& is) const
    {
        // _Length is the length the datagram that is enclosed by _Length
        const static ek60_long tmp = sizeof(ek60_long) * 3;

        is.seekg(_Length - tmp, std::ios::cur);

        // verify that we are at the end of the datagram by reading the enclosing length field
        // This should be the same as _Length if everything is ok
        ek60_long length;
        is.read(reinterpret_cast<char*>(&length), sizeof(length));

        // (the packages are encapsulated by length)
        // if the lengths do not match the packages was not read correctly
        if (!is || length != _Length)
        {
            throw std::runtime_error("ERROR[EK60_Datagram::skip]: length mismatch");
        }
    }

    //----- convenient member access -----
    /**
     * @brief length of the datagram in bytes (excluding the length fields at the beginning and end
     * of the datagram)
     */
    ek60_long get_length() const { return _Length; }
    void      set_length(ek60_long length) { _Length = length; }

    /**
     * @brief Ek60 datagram type (XML0, FIL1, NME0, MRU0, RAW3, ...)
     *
     */
    t_EK60_DatagramType get_datagram_identifier() const { return t_EK60_DatagramType(_DatagramType); }
    void                 set_datagram_identifier(t_EK60_DatagramType datagram_type)
    {
        _DatagramType = ek60_long(datagram_type);
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

    std::string get_date_string(unsigned int fractionalSecondsDigits = 2, const std::string& format = "%z__%d-%m-%Y__%H:%M:%S") const
    {
        return tools::timeconv::unixtime_to_datestring(get_timestamp(), fractionalSecondsDigits, format);
    }

    // ----- operators -----
    bool operator==(const EK60_Datagram& other) const
    {
        return _Length == other._Length && _DatagramType == other._DatagramType &&
               _LowDateTime == other._LowDateTime && _HighDateTime == other._HighDateTime;
    }
    bool operator!=(const EK60_Datagram& other) const { return !operator==(other); }
    
    static EK60_Datagram from_stream(std::istream& is)
    {
        EK60_Datagram d;
        is.read(reinterpret_cast<char*>(&d._Length), 4*sizeof(ek60_long));
        
        return d;
    }
    
    static EK60_Datagram from_stream(std::istream& is, t_EK60_DatagramType datagram_identifier)
    {
        EK60_Datagram d = from_stream(is);

        if (d.get_datagram_identifier() != datagram_identifier)
            throw std::runtime_error(fmt::format("EK60_Datagram: Datagram identifier mismatch!"));

        return d;
    }

    void to_stream(std::ostream& os)
    {
        os.write(reinterpret_cast<char*>(&_Length), 4*sizeof(ek60_long));
    }

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        using tools::timeconv::unixtime_to_datestring;

        static const std::string format_data("%d/%m/%Y");
        static const std::string format_time("%H:%M:%S");
        auto                     timestamp = get_timestamp();

        auto date = unixtime_to_datestring(timestamp, 0, format_data);
        auto time = unixtime_to_datestring(timestamp, 3, format_time);

        tools::classhelpers::ObjectPrinter printer("Ek60_Datagram", float_precision);

        printer.register_value("length", _Length, "bytes");
        printer.register_string("datagram_type", datagram_type_to_string(_DatagramType));
        printer.register_value("timestamp", timestamp, "s");
        printer.register_string("date", date, "MM/DD/YYYY");
        printer.register_string("time", time, "HH:MM:SS");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(EK60_Datagram)
};

} // namespace datagrams
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
