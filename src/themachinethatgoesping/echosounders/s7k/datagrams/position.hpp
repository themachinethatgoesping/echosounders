// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/position.doc.hpp"

// std includes
#include <cstdint>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "s7kdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

/**
 * @brief 7k record Position
 */
class Position : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::Position;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        uint32_t datum; ///< datum identifier (0 = WGS84)
        float latency; ///< position latency
        double latitude_northing; ///< latitude (rad) if geographic, else northing (m)
        double longitude_easting; ///< longitude (rad) if geographic, else easting (m)
        double height; ///< height relative to datum
        uint8_t position_type; ///< 0 = geographic, 1 = grid coordinates
        uint8_t utm_zone; ///< UTM zone (if grid)
        uint8_t quality; ///< 0 = navigation, 1 = dead reckoning
        uint8_t position_method; ///< positioning method (GPS/DGPS/RTK/... 0-16)

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content);

  public:
    Position()
        : _content{}
    {
        set_datagram_identifier(DatagramIdentifier);
    }
    ~Position() = default;

    // ----- convenient member access -----
    uint32_t get_datum() const { return _content.datum; }
    float get_latency() const { return _content.latency; }
    double get_latitude_northing() const { return _content.latitude_northing; }
    double get_longitude_easting() const { return _content.longitude_easting; }
    double get_height() const { return _content.height; }
    uint8_t get_position_type() const { return _content.position_type; }
    uint8_t get_utm_zone() const { return _content.utm_zone; }
    uint8_t get_quality() const { return _content.quality; }
    uint8_t get_position_method() const { return _content.position_method; }

    void set_datum(uint32_t val) { _content.datum = val; }
    void set_latency(float val) { _content.latency = val; }
    void set_latitude_northing(double val) { _content.latitude_northing = val; }
    void set_longitude_easting(double val) { _content.longitude_easting = val; }
    void set_height(double val) { _content.height = val; }
    void set_position_type(uint8_t val) { _content.position_type = val; }
    void set_utm_zone(uint8_t val) { _content.utm_zone = val; }
    void set_quality(uint8_t val) { _content.quality = val; }
    void set_position_method(uint8_t val) { _content.position_method = val; }

    // ----- operators -----
    bool operator==(const Position& other) const = default;

    //----- to/from stream functions -----
    static Position from_stream(std::istream& is, S7KDatagram header);
    static Position from_stream(std::istream& is);
    static Position from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(Position)

  private:
    explicit Position(S7KDatagram header)
        : S7KDatagram(std::move(header))
    {
    }
    void __read__(std::istream& is)
    {
        is.read(reinterpret_cast<char*>(&_content), __content_size);
    }
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
