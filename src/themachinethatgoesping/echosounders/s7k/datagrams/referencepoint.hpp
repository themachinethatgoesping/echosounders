// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/referencepoint.doc.hpp"

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
 * @brief 7k record ReferencePoint
 */
class ReferencePoint : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::ReferencePoint;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        float offset_x; ///< vehicle reference X offset to center of gravity
        float offset_y; ///< vehicle reference Y offset to center of gravity
        float offset_z; ///< vehicle reference Z offset to center of gravity
        float water_z; ///< water level Z offset to center of gravity

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content);

  public:
    ReferencePoint()
        : _content{}
    {
        set_datagram_identifier(DatagramIdentifier);
    }
    ~ReferencePoint() = default;

    // ----- convenient member access -----
    float get_offset_x() const { return _content.offset_x; }
    float get_offset_y() const { return _content.offset_y; }
    float get_offset_z() const { return _content.offset_z; }
    float get_water_z() const { return _content.water_z; }

    void set_offset_x(float val) { _content.offset_x = val; }
    void set_offset_y(float val) { _content.offset_y = val; }
    void set_offset_z(float val) { _content.offset_z = val; }
    void set_water_z(float val) { _content.water_z = val; }

    // ----- operators -----
    bool operator==(const ReferencePoint& other) const = default;

    //----- to/from stream functions -----
    static ReferencePoint from_stream(std::istream& is, S7KDatagram header);
    static ReferencePoint from_stream(std::istream& is);
    static ReferencePoint from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(ReferencePoint)

  private:
    explicit ReferencePoint(S7KDatagram header)
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
