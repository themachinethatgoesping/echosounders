// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergalldatagram.doc.hpp"

// std includes
#include <cstdint>
#include <iosfwd>
#include <string>
#include <unordered_map>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include <themachinethatgoesping/tools/timeconv.hpp>


#include "../types.hpp"
// #include "../misc/DateTime.h"
// #include "DSMToolsLib/HelperFunctions.h"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

class KongsbergAllDatagram
{
  public:
    using t_DatagramIdentifier = t_KongsbergAllDatagramIdentifier;

  protected:
    uint32_t _bytes; ///< number of bytes in the datagram (not including the _bytes field itself)
    uint8_t  _stx = 0x02;                      ///< (start identifier)
    t_DatagramIdentifier _datagram_identifier; ///< KongsbergAll datagram identifier
    uint16_t             _model_number; ///< KongsbergAll model number (example: EM 3002 = 3002)
    uint32_t             _date; ///< year*1000 + month*100 + day(Example:Jun 27, 2020 = 20200627)
    uint32_t             _time_since_midnight; // in milliseconds

  protected:
    /**
     * @brief verify the datagram is read correctly by reading the ETX (end identifier) field and
     * the checksum at the end of the datagram Note: the checksum is not verified. (describes sum of
     * bytes between STX and ETX)
     *
     * @param is istream. Must be at the end position of the datagram header. Pos will be
     * incremented by 3 bytes (ETX and checksum).
     */
    void _verify_datagram_end(std::istream& is) const;

  public:
    KongsbergAllDatagram(
        uint32_t             bytes,
        t_DatagramIdentifier datagram_identifier = t_DatagramIdentifier::unspecified,
        uint16_t             model_number        = 0,
        uint16_t             date                = 0,
        uint16_t             time_since_midnight = 0);
    KongsbergAllDatagram()          = default;
    virtual ~KongsbergAllDatagram() = default;

    void skip(std::istream& is) const;

    /**
     * @brief This verifies that stream_pos describes the thought datagram and skips to the
     * beginning of the datagram (without header)
     * This is used to read some variables from a datagram directly (e.g. read_xyz from XYZDatagram)
     *
     * @param is istream
     * @param stream_pos position of the datagram header
     * @param identifier datagram identifier
     *
     * @return size_t position of the datagram without header
     */
    static size_t skip_and_verify_header(std::istream&                    is,
                                         size_t                           stream_pos,
                                         t_KongsbergAllDatagramIdentifier identifier);

    // ----- convenient member access -----
    uint32_t             get_bytes() const;
    uint8_t              get_stx() const;
    t_DatagramIdentifier get_datagram_identifier() const;
    uint16_t             get_model_number() const;
    uint32_t             get_date() const;
    uint32_t             get_time_since_midnight() const;

    void set_bytes(uint32_t bytes);
    void set_stx(uint8_t stx);
    void set_datagram_identifier(t_DatagramIdentifier datagram_identifier);
    void set_model_number(uint16_t model_number);
    void set_date(uint32_t date);
    void set_time_since_midnight(uint32_t time_since_midnight);

    // ----- processed member access -----
    /**
     * @brief convert the date and time_since_midnight field to a unix timestamp
     *
     * @return unixtime as double
     */
    double get_timestamp() const;

    /**
     * @brief Get the time as string
     *
     * @param fractionalSecondsDigits
     * @param format
     * @return std::string
     */
    std::string get_date_string(unsigned int       fractionalSecondsDigits = 2,
                                const std::string& format = "%z__%d-%m-%Y__%H:%M:%S") const;

    /**
     * @brief Get the model number as string
     * EM+model_number, except 2045 which is EM2040C
     *
     * @return std::string
     */
    std::string get_model_number_as_string() const;

    // ----- operators -----
    bool operator==(const KongsbergAllDatagram& other) const = default;

    static KongsbergAllDatagram from_stream(std::istream& is);

    static KongsbergAllDatagram from_stream(std::istream&                    is,
                                            t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(KongsbergAllDatagram)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
