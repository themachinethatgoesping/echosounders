// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/rollpitchheave.doc.hpp"

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
 * @brief 7k record RollPitchHeave
 */
class RollPitchHeave : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::RollPitchHeave;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        float roll; ///< vessel roll
        float pitch; ///< vessel pitch
        float heave; ///< vessel heave

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content);

  public:
    RollPitchHeave()
        : _content{}
    {
        set_datagram_identifier(DatagramIdentifier);
    }
    ~RollPitchHeave() = default;

    // ----- convenient member access -----
    float get_roll() const { return _content.roll; }
    float get_pitch() const { return _content.pitch; }
    float get_heave() const { return _content.heave; }

    void set_roll(float val) { _content.roll = val; }
    void set_pitch(float val) { _content.pitch = val; }
    void set_heave(float val) { _content.heave = val; }

    // ----- operators -----
    bool operator==(const RollPitchHeave& other) const = default;

    //----- to/from stream functions -----
    static RollPitchHeave from_stream(std::istream& is, S7KDatagram header);
    static RollPitchHeave from_stream(std::istream& is);
    static RollPitchHeave from_stream(std::istream& is, t_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(RollPitchHeave)

  private:
    explicit RollPitchHeave(S7KDatagram header)
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
