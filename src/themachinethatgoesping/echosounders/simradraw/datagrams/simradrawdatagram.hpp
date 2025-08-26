// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawdatagram.doc.hpp"

// std includes
#include <iostream>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "../types.hpp"
// #include "../misc/DateTime.h"
// #include "DSMToolsLib/HelperFunctions.h"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

class SimradRawDatagram
{
  protected:
    using t_DatagramIdentifier = t_SimradRawDatagramIdentifier;

    simradraw_long _length;        ///< Raw: Length of the datagram in bytes
    simradraw_long _datagram_type; ///< Raw: Datagram type as
    simradraw_long
        _low_date_time; ///< Raw: Low part of Windows NT FILETIME (100ns ticks since 1601-01-01)
    simradraw_long
        _high_date_time; ///< Raw: High part of Windows NT FILETIME (100ns ticks since 1601-01-01)

  protected:
    /**
     * @brief verify the datagram is read correctly by reading the length field at the end
     *
     * @param is istream. Must be at the end position of the datagram. Pos will be incremented by 4
     * bytes (simradraw_long).
     */
    void _verify_datagram_end(std::istream& is) const;

  public:
    SimradRawDatagram(simradraw_long length,
                   simradraw_long datagram_type,
                   simradraw_long low_data_time  = 0,
                   simradraw_long high_date_time = 0)
        : _length(length)
        , _datagram_type(datagram_type)
        , _low_date_time(low_data_time)
        , _high_date_time(high_date_time)
    {
    }
    SimradRawDatagram()          = default;
    virtual ~SimradRawDatagram() = default;

    void skip(std::istream& is) const;

    //----- convenient member access -----
    /**
     * @brief length of the datagram in bytes (excluding the length fields at the beginning and end
     * of the datagram)
     */
    simradraw_long get_length() const { return _length; }
    void        set_length(simradraw_long length) { _length = length; }

    simradraw_long get_datagram_type() const { return _datagram_type; }
    void        set_datagram_type(simradraw_long datagram_type) { _datagram_type = datagram_type; }

    simradraw_long get_low_date_time() const { return _low_date_time; }
    void        set_low_date_time(simradraw_long low_date_time) { _low_date_time = low_date_time; }

    simradraw_long get_high_date_time() const { return _high_date_time; }
    void        set_high_date_time(simradraw_long high_date_time) { _high_date_time = high_date_time; }

    /**
     * @brief Ek60 datagram type (XML0, FIL1, NME0, MRU0, RAW3, ...)
     *
     */
    t_SimradRawDatagramIdentifier get_datagram_identifier() const
    {
        return t_SimradRawDatagramIdentifier(_datagram_type);
    }
    void set_datagram_identifier(t_SimradRawDatagramIdentifier datagram_type)
    {
        _datagram_type = simradraw_long(datagram_type);
    }

    /**
     * @brief unix timestamp in seconds since epoch (1970-01-01). Data is converted to/from internal
     * windows high/low timestamp representation.
     */
    double get_timestamp() const;

    void set_timestamp(double unixtime);

    std::string get_date_string(unsigned int       fractionalSecondsDigits = 2,
                                const std::string& format = "%z__%d-%m-%Y__%H:%M:%S") const;

    // ----- operators -----
    bool operator==(const SimradRawDatagram& other) const = default;

    static SimradRawDatagram from_stream(std::istream& is);

    static SimradRawDatagram from_stream(std::istream&              is,
                                      t_SimradRawDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(SimradRawDatagram)
};

} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
