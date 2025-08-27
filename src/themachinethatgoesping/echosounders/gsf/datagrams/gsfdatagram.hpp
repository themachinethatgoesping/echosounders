// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
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

    static GSFDatagram from_stream(std::istream& is);

    static GSFDatagram from_stream(std::istream& is, t_GSFDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(GSFDatagram)
};

} // namespace datagrams
} // namespace gsf
} // namespace echosounders
} // namespace themachinethatgoesping
