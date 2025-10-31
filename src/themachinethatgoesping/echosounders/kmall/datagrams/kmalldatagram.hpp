// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kmalldatagram.doc.hpp"

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

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

class KMALLDatagram
{
  public:
    using t_DatagramIdentifier = t_KMALLDatagramIdentifier;
    using o_DatagramIdentifier = o_KMALLDatagramIdentifier;

    static constexpr size_t __size = 20; /// sizeof is incorrect due to virtual functions

  protected:
    uint32_t                  _bytes_datagram; ///< Number of bytes in datagram including this field
    o_KMALLDatagramIdentifier _datagram_identifier; ///< Datagram type identifier
    uint8_t                   _datagram_version;    ///< Datagram version
    uint8_t                   _system_id;           ///< Echosounder system id (serial number)
    uint16_t _echo_sounder_id; ///< Echosounder sounder identity (e.g. 124, 304, 712, 2040, 2045 (EM
                               ///< 2040C) )
    uint32_t _time_sec;        ///< unixtime (seconds since 1970-01-01 00:00:00 UTC)
    uint32_t _time_nanosec;    ///< nanoseconds since time_sec

  public:
    KMALLDatagram(uint32_t                  bytes_datagram,
                  o_KMALLDatagramIdentifier datagram_identifier,
                  uint8_t                   datagram_version,
                  uint8_t                   system_id,
                  uint16_t                  echo_sounder_id,
                  uint32_t                  time_sec,
                  uint32_t                  time_nanosec)
        : _bytes_datagram(bytes_datagram)
        , _datagram_identifier(datagram_identifier)
        , _datagram_version(datagram_version)
        , _system_id(system_id)
        , _echo_sounder_id(echo_sounder_id)
        , _time_sec(time_sec)
        , _time_nanosec(time_nanosec)
    {
    }
    KMALLDatagram()                           = default;
    virtual ~KMALLDatagram()                  = default;
    KMALLDatagram(const KMALLDatagram& other) = default;
    KMALLDatagram(KMALLDatagram&& other)      = default;

    void skip(std::istream& is) const
    {
        // _bytes describes the bytes of the data portion including header
        is.seekg(_bytes_datagram - __size, std::ios::cur);
    }

    // interface
    void set_datagram_identifier(o_DatagramIdentifier datagram_identifier)
    {
        _datagram_identifier = datagram_identifier;
    }
    o_DatagramIdentifier get_datagram_identifier() const { return _datagram_identifier; }
    virtual double       get_timestamp() const { return _time_sec + _time_nanosec * 1e-9; }

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
    uint32_t get_bytes_datagram() const { return _bytes_datagram; }
    uint8_t  get_datagram_version() const { return _datagram_version; }
    uint8_t  get_system_id() const { return _system_id; }
    uint16_t get_echo_sounder_id() const { return _echo_sounder_id; }
    uint32_t get_time_sec() const { return _time_sec; }
    uint32_t get_time_nanosec() const { return _time_nanosec; }
    void     set_bytes_datagram(uint32_t bytes_datagram) { _bytes_datagram = bytes_datagram; }
    void set_datagram_version(uint8_t datagram_version) { _datagram_version = datagram_version; }
    void set_system_id(uint8_t system_id) { _system_id = system_id; }
    void set_echo_sounder_id(uint16_t echo_sounder_id) { _echo_sounder_id = echo_sounder_id; }
    void set_time_sec(uint32_t time_sec) { _time_sec = time_sec; }
    void set_time_nanosec(uint32_t time_nanosec) { _time_nanosec = time_nanosec; }

    // ----- helper -----
    size_t compute_size_content() const { return _bytes_datagram - __size; }

    // ----- operators -----
    bool operator==(const KMALLDatagram& other) const = default;

    static KMALLDatagram from_stream(std::istream& is);

    static KMALLDatagram from_stream(std::istream&             is,
                                     o_KMALLDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(KMALLDatagram)

  protected:
    inline void __kmalldatagram_read__(std::istream& is)
    {
        is.read(reinterpret_cast<char*>(&(_bytes_datagram)), __size);
    }
    inline static void __check_datagram_identifier__(const o_KMALLDatagramIdentifier actual,
                                                     const o_KMALLDatagramIdentifier expected)
    {
        if (actual != expected)
            throw std::runtime_error(
                fmt::format("KMALLDatagram::__check_datagram_identifier__: datagram "
                            "identifier is not {}, but {}",
                            expected.name(),
                            actual.name()));
    }
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
