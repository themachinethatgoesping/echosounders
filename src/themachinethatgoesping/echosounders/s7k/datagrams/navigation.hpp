// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/navigation.doc.hpp"

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
 * @brief 7k record Navigation
 */
class Navigation : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::Navigation;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        uint8_t vertical_reference; ///< 1 = ellipsoid, 2 = geoid, 3 = chart datum
        double latitude; ///< latitude (-pi/2 .. +pi/2)
        double longitude; ///< longitude (-pi .. +pi)
        float position_accuracy; ///< horizontal position accuracy
        float height; ///< height of vessel reference point above vertical reference
        float height_accuracy; ///< height accuracy
        float speed; ///< speed over ground
        float course; ///< course over ground
        float heading; ///< heading

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
    uint8_t get_vertical_reference() const { return _content.vertical_reference; }
    double get_latitude() const { return _content.latitude; }
    double get_longitude() const { return _content.longitude; }
    float get_position_accuracy() const { return _content.position_accuracy; }
    float get_height() const { return _content.height; }
    float get_height_accuracy() const { return _content.height_accuracy; }
    float get_speed() const { return _content.speed; }
    float get_course() const { return _content.course; }
    float get_heading() const { return _content.heading; }

    void set_vertical_reference(uint8_t val) { _content.vertical_reference = val; }
    void set_latitude(double val) { _content.latitude = val; }
    void set_longitude(double val) { _content.longitude = val; }
    void set_position_accuracy(float val) { _content.position_accuracy = val; }
    void set_height(float val) { _content.height = val; }
    void set_height_accuracy(float val) { _content.height_accuracy = val; }
    void set_speed(float val) { _content.speed = val; }
    void set_course(float val) { _content.course = val; }
    void set_heading(float val) { _content.heading = val; }

    // ----- operators -----
    bool operator==(const Navigation& other) const = default;

    //----- to/from stream functions -----
    static Navigation from_stream(std::istream& is, S7KDatagram header);
    static Navigation from_stream(std::istream& is);
    static Navigation from_stream(std::istream& is, t_S7KDatagramIdentifier datagram_identifier);

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
