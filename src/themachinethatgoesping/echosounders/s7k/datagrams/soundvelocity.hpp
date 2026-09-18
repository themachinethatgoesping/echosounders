// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/soundvelocity.doc.hpp"

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
 * @brief 7k record SoundVelocity
 */
class SoundVelocity : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::SoundVelocity;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        float _sound_velocity = 0.f; ///< water sound velocity in meters per second

        uint32_t _checksum =
            0; ///< record checksum (last 4 bytes; see S7KDatagram, debugging only)

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content);

  public:
    SoundVelocity();
    ~SoundVelocity() = default;

    // ----- convenient member access -----
    float    get_sound_velocity() const;
    uint32_t get_checksum() const;

    void set_sound_velocity(float val);
    void set_checksum(uint32_t val);

    // ----- operators -----
    bool operator==(const SoundVelocity& other) const = default;

    //----- to/from stream functions -----
    static SoundVelocity from_stream(std::istream& is, S7KDatagram header);
    static SoundVelocity from_stream(std::istream& is);
    static SoundVelocity from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(SoundVelocity)

  private:
    explicit SoundVelocity(S7KDatagram header);
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
