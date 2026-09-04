// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/navigation.doc.hpp"

// std includes
#include <array>
#include <cstdint>
#include <numbers>
#include <string>
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
 * @brief 7k record Navigation
 */
class Navigation : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::Navigation;

    // ----- vertical reference (7k DFD 1015 Record Type Header) -----
    enum class t_vertical_reference : uint8_t
    {
        ellipsoid   = 1, ///< ellipsoid
        geoid       = 2, ///< geoid
        chart_datum = 3, ///< chart datum
    };
    static constexpr std::array<t_vertical_reference, 3> t_vertical_reference_values = {
        t_vertical_reference::ellipsoid, t_vertical_reference::geoid, t_vertical_reference::chart_datum
    };
    static constexpr std::array<std::string_view, 3> t_vertical_reference_names = { "ellipsoid",
                                                                                    "geoid",
                                                                                    "chart_datum" };
    static constexpr std::array<std::string_view, 3> t_vertical_reference_alt_names = {
        "Ellipsoid", "Geoid", "Chart datum"
    };
    using o_vertical_reference = tools::classhelper::OptionFrozen<t_vertical_reference,
                                                                 t_vertical_reference_values.size(),
                                                                 t_vertical_reference_values,
                                                                 t_vertical_reference_names,
                                                                 t_vertical_reference_alt_names>;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        o_vertical_reference _vertical_reference; ///< 1 = ellipsoid, 2 = geoid, 3 = chart datum
        double               _latitude  = 0.; ///< latitude in radians (-pi/2 .. +pi/2)
        double               _longitude = 0.; ///< longitude in radians (-pi .. +pi)
        float                _position_accuracy = 0.f; ///< horizontal position accuracy in meters
        float _height = 0.f; ///< height of vessel reference point above vertical reference (meters)
        float _height_accuracy = 0.f; ///< height accuracy in meters
        float _speed           = 0.f; ///< speed over ground in meters per second
        float _course          = 0.f; ///< course over ground in radians
        float _heading         = 0.f; ///< heading in radians

        uint32_t _checksum = 0; ///< record checksum (last 4 bytes; see S7KDatagram, debugging only)

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content);

  public:
    Navigation()
        : _content{}
    {
        set_datagram_identifier(DatagramIdentifier);
    }
    ~Navigation() = default;

    // ----- convenient member access -----
    o_vertical_reference get_vertical_reference() const { return _content._vertical_reference; }
    double               get_latitude() const { return _content._latitude; }
    double               get_longitude() const { return _content._longitude; }
    float                get_position_accuracy() const { return _content._position_accuracy; }
    float                get_height() const { return _content._height; }
    float                get_height_accuracy() const { return _content._height_accuracy; }
    float                get_speed() const { return _content._speed; }
    float                get_course() const { return _content._course; }
    float                get_heading() const { return _content._heading; }
    uint32_t             get_checksum() const { return _content._checksum; }

    void set_vertical_reference(o_vertical_reference val) { _content._vertical_reference = val; }
    void set_latitude(double val) { _content._latitude = val; }
    void set_longitude(double val) { _content._longitude = val; }
    void set_position_accuracy(float val) { _content._position_accuracy = val; }
    void set_height(float val) { _content._height = val; }
    void set_height_accuracy(float val) { _content._height_accuracy = val; }
    void set_speed(float val) { _content._speed = val; }
    void set_course(float val) { _content._course = val; }
    void set_heading(float val) { _content._heading = val; }
    void set_checksum(uint32_t val) { _content._checksum = val; }

    // ----- processed data access -----
    /// @brief Get the latitude in degrees (converted from radians).
    double get_latitude_in_degrees() const { return _content._latitude * 180.0 / std::numbers::pi; }
    /// @brief Get the longitude in degrees (converted from radians).
    double get_longitude_in_degrees() const
    {
        return _content._longitude * 180.0 / std::numbers::pi;
    }
    /// @brief Get the course over ground in degrees (converted from radians).
    float get_course_in_degrees() const
    {
        return _content._course * 180.f / float(std::numbers::pi);
    }
    /// @brief Get the heading in degrees (converted from radians).
    float get_heading_in_degrees() const
    {
        return _content._heading * 180.f / float(std::numbers::pi);
    }

    // ----- operators -----
    bool operator==(const Navigation& other) const = default;

    //----- to/from stream functions -----
    static Navigation from_stream(std::istream& is, S7KDatagram header);
    static Navigation from_stream(std::istream& is);
    static Navigation from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(Navigation)

  private:
    explicit Navigation(S7KDatagram header)
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
