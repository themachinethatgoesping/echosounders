// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/heading.doc.hpp"

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
 * @brief 7k record Heading
 */
class Heading : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::Heading;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        float _heading = 0.f; ///< vessel heading in radians

        uint32_t _checksum =
            0; ///< record checksum (last 4 bytes; see S7KDatagram, debugging only)

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content);

  public:
    Heading();
    ~Heading() = default;

    // ----- convenient member access -----
    float    get_heading() const;
    uint32_t get_checksum() const;

    void set_heading(float val);
    void set_checksum(uint32_t val);

    // ----- processed data access -----
    /// @brief Get the vessel heading in degrees (converted from radians).
    float get_heading_in_degrees() const;

    // ----- operators -----
    bool operator==(const Heading& other) const = default;

    //----- to/from stream functions -----
    static Heading from_stream(std::istream& is, S7KDatagram header);
    static Heading from_stream(std::istream& is);
    static Heading from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(Heading)

  private:
    explicit Heading(S7KDatagram header);
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
