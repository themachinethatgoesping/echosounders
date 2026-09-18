// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/navigation.doc.hpp"

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
    Navigation();
    ~Navigation() = default;

    // ----- convenient member access -----
    o_vertical_reference get_vertical_reference() const;
    double               get_latitude() const;
    double               get_longitude() const;
    float                get_position_accuracy() const;
    float                get_height() const;
    float                get_height_accuracy() const;
    float                get_speed() const;
    float                get_course() const;
    float                get_heading() const;
    uint32_t             get_checksum() const;

    void set_vertical_reference(o_vertical_reference val);
    void set_latitude(double val);
    void set_longitude(double val);
    void set_position_accuracy(float val);
    void set_height(float val);
    void set_height_accuracy(float val);
    void set_speed(float val);
    void set_course(float val);
    void set_heading(float val);
    void set_checksum(uint32_t val);

    // ----- processed data access -----
    /// @brief Get the latitude in degrees (converted from radians).
    double get_latitude_in_degrees() const;
    /// @brief Get the longitude in degrees (converted from radians).
    double get_longitude_in_degrees() const;
    /// @brief Get the course over ground in degrees (converted from radians).
    float get_course_in_degrees() const;
    /// @brief Get the heading in degrees (converted from radians).
    float get_heading_in_degrees() const;

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
    explicit Navigation(S7KDatagram header);
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping

// ----- explicit template instantiation (defined in navigation.cpp) -----
extern template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::Navigation::t_vertical_reference,
    themachinethatgoesping::echosounders::s7k::datagrams::Navigation::t_vertical_reference_values
        .size(),
    themachinethatgoesping::echosounders::s7k::datagrams::Navigation::t_vertical_reference_values,
    themachinethatgoesping::echosounders::s7k::datagrams::Navigation::t_vertical_reference_names,
    themachinethatgoesping::echosounders::s7k::datagrams::Navigation::t_vertical_reference_alt_names>;
