// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/referencepoint.doc.hpp"

// std includes
#include <cstdint>

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
        float _offset_x = 0.f; ///< vehicle reference X offset to center of gravity (meters)
        float _offset_y = 0.f; ///< vehicle reference Y offset to center of gravity (meters)
        float _offset_z = 0.f; ///< vehicle reference Z offset to center of gravity (meters)
        float _water_z  = 0.f; ///< water level Z offset to center of gravity (meters)

        uint32_t _checksum =
            0; ///< record checksum (last 4 bytes; see S7KDatagram, debugging only)

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content);

  public:
    ReferencePoint();
    ~ReferencePoint() = default;

    // ----- convenient member access -----
    float    get_offset_x() const;
    float    get_offset_y() const;
    float    get_offset_z() const;
    float    get_water_z() const;
    uint32_t get_checksum() const;

    void set_offset_x(float val);
    void set_offset_y(float val);
    void set_offset_z(float val);
    void set_water_z(float val);
    void set_checksum(uint32_t val);

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
    explicit ReferencePoint(S7KDatagram header);
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
