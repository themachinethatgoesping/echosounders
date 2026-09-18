// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/position.doc.hpp"

// std includes
#include <array>
#include <cstdint>
#include <string_view>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/option_frozen.hpp>

#include "../types.hpp"
#include "s7kdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

/**
 * @brief 7k Position Record (1003) used in conjunction with Record Type 1011 (Geodesy).
 */
class Position : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::Position;

    // ----- position type flag (7k DFD Table 15) -----
    enum class t_position_type_flag : uint8_t
    {
        geographic = 0, ///< geographical coordinates (latitude/longitude in radians)
        grid       = 1, ///< grid coordinates (northing/easting in meters)
    };
    static constexpr std::array<t_position_type_flag, 2> t_position_type_flag_values = {
        t_position_type_flag::geographic,
        t_position_type_flag::grid
    };
    static constexpr std::array<std::string_view, 2> t_position_type_flag_names = { "geographic",
                                                                                    "grid" };
    static constexpr std::array<std::string_view, 2> t_position_type_flag_alt_names = {
        "geographical coordinates",
        "grid coordinates"
    };
    using o_position_type_flag =
        tools::classhelper::OptionFrozen<t_position_type_flag,
                                         t_position_type_flag_values.size(),
                                         t_position_type_flag_values,
                                         t_position_type_flag_names,
                                         t_position_type_flag_alt_names>;

    // ----- quality flag (7k DFD Table 15) -----
    enum class t_quality_flag : uint8_t
    {
        navigation     = 0, ///< navigation data
        dead_reckoning = 1, ///< dead-reckoning
    };
    static constexpr std::array<t_quality_flag, 2> t_quality_flag_values = {
        t_quality_flag::navigation,
        t_quality_flag::dead_reckoning
    };
    static constexpr std::array<std::string_view, 2> t_quality_flag_names     = { "navigation",
                                                                                  "dead_reckoning" };
    static constexpr std::array<std::string_view, 2> t_quality_flag_alt_names = {
        "navigation data",
        "dead-reckoning"
    };
    using o_quality_flag = tools::classhelper::OptionFrozen<t_quality_flag,
                                                            t_quality_flag_values.size(),
                                                            t_quality_flag_values,
                                                            t_quality_flag_names,
                                                            t_quality_flag_alt_names>;

    // ----- positioning method (7k DFD Table 15) -----
    enum class t_position_method : uint8_t
    {
        gps                                    = 0, ///< GPS
        dgps                                   = 1, ///< DGPS
        inertial_start_from_gps                = 2, ///< start of inertial positioning from GPS
        inertial_start_from_dgps               = 3, ///< start of inertial positioning from DGPS
        inertial_start_from_bottom_correlation = 4, ///< start of inertial from bottom correlation
        inertial_start_from_bottom_object      = 5, ///< start of inertial from bottom object
        inertial_start_from_inertial           = 6, ///< start of inertial from inertial positioning
        inertial_start_from_optional_data      = 7, ///< start of inertial from optional data
        inertial_stop_to_gps                   = 8, ///< stop of inertial positioning to GPS
        inertial_stop_to_dgps                  = 9, ///< stop of inertial positioning to DGPS
        inertial_stop_to_bottom_correlation    = 10, ///< stop of inertial to bottom correlation
        inertial_stop_to_bottom_object         = 11, ///< stop of inertial to bottom object
        inertial_start_to_inertial             = 12, ///< start of inertial to inertial positioning
        inertial_start_to_optional_data        = 13, ///< start of inertial to optional data
        user_defined                           = 14, ///< user defined
        rtk_fixed                              = 15, ///< RTK fixed
        rtk_float                              = 16, ///< RTK float
    };
    static constexpr std::array<t_position_method, 17> t_position_method_values = {
        t_position_method::gps,
        t_position_method::dgps,
        t_position_method::inertial_start_from_gps,
        t_position_method::inertial_start_from_dgps,
        t_position_method::inertial_start_from_bottom_correlation,
        t_position_method::inertial_start_from_bottom_object,
        t_position_method::inertial_start_from_inertial,
        t_position_method::inertial_start_from_optional_data,
        t_position_method::inertial_stop_to_gps,
        t_position_method::inertial_stop_to_dgps,
        t_position_method::inertial_stop_to_bottom_correlation,
        t_position_method::inertial_stop_to_bottom_object,
        t_position_method::inertial_start_to_inertial,
        t_position_method::inertial_start_to_optional_data,
        t_position_method::user_defined,
        t_position_method::rtk_fixed,
        t_position_method::rtk_float,
    };
    static constexpr std::array<std::string_view, 17> t_position_method_names = {
        "gps",
        "dgps",
        "inertial_start_from_gps",
        "inertial_start_from_dgps",
        "inertial_start_from_bottom_correlation",
        "inertial_start_from_bottom_object",
        "inertial_start_from_inertial",
        "inertial_start_from_optional_data",
        "inertial_stop_to_gps",
        "inertial_stop_to_dgps",
        "inertial_stop_to_bottom_correlation",
        "inertial_stop_to_bottom_object",
        "inertial_start_to_inertial",
        "inertial_start_to_optional_data",
        "user_defined",
        "rtk_fixed",
        "rtk_float",
    };
    static constexpr std::array<std::string_view, 17> t_position_method_alt_names = {
        "GPS",
        "DGPS",
        "Start of inertial positioning system from GPS",
        "Start of inertial positioning system from DGPS",
        "Start of inertial positioning system from bottom correlation",
        "Start of inertial positioning from bottom object",
        "Start of inertial positioning from inertial positioning",
        "Start of inertial positioning from optional data",
        "Stop of inertial positioning system to GPS",
        "Stop of inertial positioning system to DGPS",
        "Stop of inertial positioning system to bottom correlation",
        "Stop of inertial positioning to bottom object",
        "Start of inertial positioning to inertial positioning",
        "Start of inertial positioning to optional data",
        "User defined",
        "RTK Fixed",
        "RTK Float",
    };
    using o_position_method = tools::classhelper::OptionFrozen<t_position_method,
                                                               t_position_method_values.size(),
                                                               t_position_method_values,
                                                               t_position_method_names,
                                                               t_position_method_alt_names>;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        uint32_t _datum_identifier = 0;   ///< datum identifier (0 = WGS84, >0 = reserved)
        float    _latency          = 0.f; ///< positioning latency in seconds (0 for 7k sonar / PDS)
        double   _latitude_or_northing =
            0.; ///< latitude in radians (geographic) or northing in meters (grid)
        double _longitude_or_easting =
            0.; ///< longitude in radians (geographic) or easting in meters (grid)
        double               _height = 0.;        ///< height relative to datum in meters
        o_position_type_flag _position_type_flag; ///< 0 = geographical, 1 = grid coordinates
        uint8_t              _utm_zone = 0;       ///< UTM zone (if grid coordinates)
        o_quality_flag       _quality_flag;       ///< 0 = navigation data, 1 = dead-reckoning
        o_position_method    _position_method;    ///< positioning method (GPS/DGPS/RTK/inertial)
        uint8_t              _number_of_satellites = 0; ///< number of satellites (optional)

        uint32_t _checksum = 0; ///< record checksum (last 4 bytes; see S7KDatagram, debugging only)

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content);

  public:
    Position();
    ~Position() = default;

    // ----- convenient member access -----
    uint32_t             get_datum_identifier() const;
    float                get_latency() const;
    double               get_latitude_or_northing() const;
    double               get_longitude_or_easting() const;
    double               get_height() const;
    o_position_type_flag get_position_type_flag() const;
    uint8_t              get_utm_zone() const;
    o_quality_flag       get_quality_flag() const;
    o_position_method    get_position_method() const;
    uint8_t              get_number_of_satellites() const;
    uint32_t             get_checksum() const;

    void set_datum_identifier(uint32_t val);
    void set_latency(float val);
    void set_latitude_or_northing(double val);
    void set_longitude_or_easting(double val);
    void set_height(double val);
    void set_position_type_flag(o_position_type_flag val);
    void set_utm_zone(uint8_t val);
    void set_quality_flag(o_quality_flag val);
    void set_position_method(o_position_method val);
    void set_number_of_satellites(uint8_t val);
    void set_checksum(uint32_t val);

    // ----- processed data access -----
    /**
     * @brief Get the latitude in degrees (only meaningful for geographical coordinates).
     * @return latitude_or_northing converted from radians to degrees.
     */
    double get_latitude_in_degrees() const;

    /**
     * @brief Get the longitude in degrees (only meaningful for geographical coordinates).
     * @return longitude_or_easting converted from radians to degrees.
     */
    double get_longitude_in_degrees() const;

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
    explicit Position(S7KDatagram header);
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping

// ----- explicit template instantiation (defined in position.cpp) -----
extern template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_type_flag,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_type_flag_values
        .size(),
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_type_flag_values,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_type_flag_names,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_type_flag_alt_names>;
extern template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_quality_flag,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_quality_flag_values.size(),
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_quality_flag_values,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_quality_flag_names,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_quality_flag_alt_names>;
extern template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_method,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_method_values.size(),
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_method_values,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_method_names,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_method_alt_names>;
