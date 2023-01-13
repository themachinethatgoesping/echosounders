// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/depthorheightdatagram.doc.hpp"

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
class DepthOrHeightDatagram : public EM3000Datagram
{
  protected:
    uint16_t _height_counter; ///< Sequential Number
    uint16_t _system_serial_number;
    int32_t  _height;      ///< in cm
    uint8_t  _height_type; ///< 0: derived from GGK or GGA, 1-99 ???, 100 depth is taken from the
                           ///< DepthOrheight datagram, 200: Input from depth sensor

    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit DepthOrHeightDatagram(EM3000Datagram header)
        : EM3000Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    DepthOrHeightDatagram()
    {
        _datagram_identifier = t_EM3000DatagramIdentifier::DepthOrHeightDatagram;
    }
    ~DepthOrHeightDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_height_counter() const { return _height_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    int32_t  get_height() const { return _height; }
    uint8_t  get_height_type() const { return _height_type; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    // setters
    void set_height_counter(uint16_t height_counter) { _height_counter = height_counter; }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_height(int32_t height) { _height = height; }
    void set_height_type(uint8_t height_type) { _height_type = height_type; }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // ----- processed data access -----
    /**
     * @brief Get the height in meters
     *
     * @return _height * 0.01m (float)
     */
    float get_height_in_meters() const { return _height * 0.01; }

    /**
     * @brief Get a string description of the height_type
     *
     * @return std::string
     */
    std::string get_height_type_explained() const
    {
        if (_height_type == 0)
        {
            return "The height is derived from the GGK or GGA datagram and is the height of the "
                   "water level at the vertical datum (possibly motion corrected). \n height is "
                   "derived from the active position system only.";
        }
        if (_height_type <= 99)
        {
            return "The height type is as given in the Depth (pressure) or height input datagram";
        }
        if (_height_type == 100)
        {
            return "The input is depth taken from the OwnShipsData/S90.";
        }
        if (_height_type == 200)
        {
            return "Input from depth sensor.";
        }

        return "Unknown height type";
    }

    // ----- operators -----
    bool operator==(const DepthOrHeightDatagram& other) const
    {
        return EM3000Datagram::operator==(other) && _height_counter == other._height_counter &&
               _system_serial_number == other._system_serial_number && _height == other._height &&
               _height_type == other._height_type && _etx == other._etx &&
               _checksum == other._checksum;
    }
    bool operator!=(const DepthOrHeightDatagram& other) const { return !operator==(other); }

    //----- to/from stream functions -----
    static DepthOrHeightDatagram from_stream(std::istream& is, EM3000Datagram header)
    {
        DepthOrHeightDatagram datagram(std::move(header));

        if (datagram._datagram_identifier != t_EM3000DatagramIdentifier::DepthOrHeightDatagram)
            throw std::runtime_error(fmt::format(
                "DepthOrHeightDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                uint8_t(t_EM3000DatagramIdentifier::DepthOrHeightDatagram),
                uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._height_counter)), 12 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "DepthOrHeightDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static DepthOrHeightDatagram from_stream(std::istream& is)
    {
        return from_stream(is, EM3000Datagram::from_stream(is));
    }

    static DepthOrHeightDatagram from_stream(std::istream&              is,
                                             t_EM3000DatagramIdentifier datagram_identifier)
    {
        return from_stream(is, std::move(EM3000Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os)
    {
        EM3000Datagram::to_stream(os);

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_height_counter)), 12 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("DepthOrHeightDatagram", float_precision);

        printer.append(EM3000Datagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("height_counter", _height_counter);
        printer.register_value("height", _height, "cm");
        printer.register_value("height_type", _height_type);
        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        printer.register_section("processed");
        printer.register_value("height", get_height_in_meters(), "m");
        printer.register_string("height_type", get_height_type_explained());
        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(DepthOrHeightDatagram)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
