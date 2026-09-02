// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/soundvelocity.doc.hpp"

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
        float sound_velocity; ///< water sound velocity

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content);

  public:
    SoundVelocity()
        : _content{}
    {
        set_datagram_identifier(DatagramIdentifier);
    }
    ~SoundVelocity() = default;

    // ----- convenient member access -----
    float get_sound_velocity() const { return _content.sound_velocity; }

    void set_sound_velocity(float val) { _content.sound_velocity = val; }

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
    explicit SoundVelocity(S7KDatagram header)
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
