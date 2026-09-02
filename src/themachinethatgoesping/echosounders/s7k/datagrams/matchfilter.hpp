// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/matchfilter.doc.hpp"

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
 * @brief 7k record MatchFilter
 */
class MatchFilter : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::MatchFilter;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        uint64_t serial_number; ///< sonar serial number
        uint32_t ping_number; ///< sequential ping number
        uint32_t operation; ///< 0 = off, 1 = on
        float start_frequency; ///< start frequency
        float end_frequency; ///< end frequency
        uint32_t window_type; ///< window type (0-5)
        float shading; ///< shading value
        float effective_pulse_width; ///< post-compression effective pulse width
        uint32_t reserved[13]; ///< reserved

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content);

  public:
    MatchFilter()
        : _content{}
    {
        set_datagram_identifier(DatagramIdentifier);
    }
    ~MatchFilter() = default;

    // ----- convenient member access -----
    uint64_t get_serial_number() const { return _content.serial_number; }
    uint32_t get_ping_number() const { return _content.ping_number; }
    uint32_t get_operation() const { return _content.operation; }
    float get_start_frequency() const { return _content.start_frequency; }
    float get_end_frequency() const { return _content.end_frequency; }
    uint32_t get_window_type() const { return _content.window_type; }
    float get_shading() const { return _content.shading; }
    float get_effective_pulse_width() const { return _content.effective_pulse_width; }

    void set_serial_number(uint64_t val) { _content.serial_number = val; }
    void set_ping_number(uint32_t val) { _content.ping_number = val; }
    void set_operation(uint32_t val) { _content.operation = val; }
    void set_start_frequency(float val) { _content.start_frequency = val; }
    void set_end_frequency(float val) { _content.end_frequency = val; }
    void set_window_type(uint32_t val) { _content.window_type = val; }
    void set_shading(float val) { _content.shading = val; }
    void set_effective_pulse_width(float val) { _content.effective_pulse_width = val; }

    // ----- operators -----
    bool operator==(const MatchFilter& other) const = default;

    //----- to/from stream functions -----
    static MatchFilter from_stream(std::istream& is, S7KDatagram header);
    static MatchFilter from_stream(std::istream& is);
    static MatchFilter from_stream(std::istream& is, t_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(MatchFilter)

  private:
    explicit MatchFilter(S7KDatagram header)
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
