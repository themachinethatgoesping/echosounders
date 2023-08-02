// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/extraparameters.doc.hpp"

// std includes
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../em3000_types.hpp"
#include "em3000datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {

/**
 * @brief Clock datagrams
 */
class ExtraParameters : public EM3000Datagram
{
  public:
    // ----- enumerator datatypes -----
    enum class t_ContentIdentifier : uint16_t
    {
        CalibTxt                  = 1, ///< Calib.txt file for angle offset
        LogAllHeights             = 2, ///< Log of all heights
        SoundVelocityAtTransducer = 3, ///< Sound velocity at transducer
        SoundVelocityProfile      = 4, ///< Sound velocity profile
        MultiCastInputStatus      = 5, ///< Multicast input status
        Bscorr                    = 6, ///< Bscorr.txt file
    };

  protected:
    uint16_t            _ping_counter;
    uint16_t            _system_serial_number;
    t_ContentIdentifier _content_identifier;
    std::string         _raw_content; ///< depends on the content identifier

    uint8_t _spare;

    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit ExtraParameters(EM3000Datagram header)
        : EM3000Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    ExtraParameters() { _datagram_identifier = t_EM3000DatagramIdentifier::ExtraParameters; }
    ~ExtraParameters() = default;

    // ----- convenient data access -----
    // getters
    uint16_t            get_ping_counter() const { return _ping_counter; }
    uint16_t            get_system_serial_number() const { return _system_serial_number; }
    t_ContentIdentifier get_content_identifier() const { return _content_identifier; }
    std::string         get_raw_content() const { return _raw_content; }
    uint8_t             get_spare() const { return _spare; }
    uint8_t             get_etx() const { return _etx; }
    uint16_t            get_checksum() const { return _checksum; }

    // setters
    void set_ping_counter(uint16_t ping_counter) { _ping_counter = ping_counter; }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_content_identifier(t_ContentIdentifier content_identifier)
    {
        _content_identifier = content_identifier;
    }
    void set_raw_content(std::string raw_content) { _raw_content = raw_content; }
    void set_spare(uint8_t spare) { _spare = spare; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }
    void set_etx(uint8_t etx) { _etx = etx; }

    // ----- processed data access -----

    // ----- operators -----
    bool operator==(const ExtraParameters& other) const = default;

    //----- to/from stream functions -----
    static ExtraParameters from_stream(std::istream& is, EM3000Datagram header)
    {
        ExtraParameters datagram(std::move(header));

        if (datagram._datagram_identifier != t_EM3000DatagramIdentifier::ExtraParameters)
            throw std::runtime_error(
                fmt::format("ExtraParameters: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                            uint8_t(t_EM3000DatagramIdentifier::ExtraParameters),
                            uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 6 * sizeof(uint8_t));

        // size of the content datagram
        // 22 = size of EM3000Datagram(12) + etx(1) + checksum(2) + spare (1) + 6
        const static uint8_t tmp = sizeof(uint8_t) * (22);

        // read the raw content datagram
        datagram._raw_content.resize(datagram.get_bytes() - tmp);
        is.read(reinterpret_cast<char*>(datagram._raw_content.data()),
                datagram._raw_content.size());

        // read the rest of the datagram
        is.read(reinterpret_cast<char*>(&(datagram._spare)), 4 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "ExtraParameters: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static ExtraParameters from_stream(std::istream& is)
    {
        return from_stream(is, EM3000Datagram::from_stream(is));
    }

    static ExtraParameters from_stream(std::istream&              is,
                                       t_EM3000DatagramIdentifier datagram_identifier)
    {
        return from_stream(is, std::move(EM3000Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os)
    {
        if (_bytes - 22 != _raw_content.size())
            throw std::runtime_error(
                fmt::format("ExtraParameters: bytes - 22 ({}) does not match the size of "
                            "the _raw_content string ({})",
                            _bytes - 22,
                            _raw_content.size()));

        EM3000Datagram::to_stream(os);

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_ping_counter)), 6 * sizeof(uint8_t));

        // write the installation paramaters string
        os.write(reinterpret_cast<const char*>(_raw_content.data()),
                 _raw_content.size() * sizeof(uint8_t));

        // write the rest of the datagram
        os.write(reinterpret_cast<const char*>(&(_spare)), 4 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("ExtraParameters", float_precision);

        printer.append(EM3000Datagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("ping_counter", _ping_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_enum("content_identifier", _content_identifier);
        printer.register_value("raw_content", _raw_content.size(), "bytes");
        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        // printer.register_section("Processed");
        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(ExtraParameters)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
