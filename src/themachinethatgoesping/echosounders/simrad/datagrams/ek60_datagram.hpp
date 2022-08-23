// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <string>
#include <vector>
#include <unordered_map>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelpers/bitsery.hpp>
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../ek60_types.hpp"
//#include "../misc/DateTime.h"
//#include "DSMToolsLib/HelperFunctions.h"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {

enum class t_EK60_Datagram_Type : ek60_long
{
    XML0 = 810306904,
    FIL1 = 827083078,
    NME0 = 809848142,
    MRU0 = 810897997,
    RAW3 = 861356370
};

inline t_EK60_Datagram_Type peter()
{
    static std::unordered_map<t_EK60_Datagram_Type, int> test;

    test[t_EK60_Datagram_Type::XML0] = 1;

    t_EK60_Datagram_Type test2 = t_EK60_Datagram_Type::XML0;
    test2 = t_EK60_Datagram_Type(0);

    test2 = t_EK60_Datagram_Type(2);
    test2 = t_EK60_Datagram_Type(6);

    return test2;
}

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

    ek60_long   get_datagram_type() const { return _DatagramType; }
    std::string get_datagram_type_string() const { return DatagramTypeAsString(_DatagramType); }

    static std::string DatagramTypeAsString(const ek60_long& value)
    {
        std::string valueAsString;
        valueAsString.resize(sizeof(value));
        memcpy(&valueAsString[0], &value, sizeof(value));

        return valueAsString;
    }

    static ek60_long StringToDatagramType(const std::string& value)
    {
        ek60_long valueAsLong;
        memcpy(&valueAsLong, &value[0], sizeof(valueAsLong));
        return valueAsLong;
    }

    // ----- operators -----
    bool operator==(const EK60_Datagram& other) const
    {
        return _Length == other._Length && _DatagramType == other._DatagramType &&
               _LowDateTime == other._LowDateTime && _HighDateTime == other._HighDateTime;
    }
    bool operator!=(const EK60_Datagram& other) const { return !operator==(other); }

    // ----- bitsery -----
    friend bitsery::Access;
    template<typename S>
    void serialize(S& s)
    {
        s.value4b(_Length);
        s.value4b(_DatagramType);
        s.value4b(_LowDateTime);
        s.value4b(_HighDateTime);
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
        printer.register_string("datagram_type", DatagramTypeAsString(_DatagramType));
        printer.register_value("timestamp", timestamp, "s");
        printer.register_string("date", date, "MM/DD/YYYY");
        printer.register_string("time", time, "HH:MM:SS");

        return printer;
    }

    // ----- class helper macros -----
    __BITSERY_DEFAULT_TOFROM_BINARY_FUNCTIONS__(EK60_Datagram)
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace datagrams
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
