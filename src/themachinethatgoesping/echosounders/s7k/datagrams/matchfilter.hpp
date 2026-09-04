// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/matchfilter.doc.hpp"

// std includes
#include <array>
#include <cstdint>
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
 * @brief 7k record MatchFilter
 */
class MatchFilter : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::MatchFilter;

    // ----- operation (7k DFD Table 43) -----
    enum class t_operation : uint32_t
    {
        off = 0, ///< off
        on  = 1, ///< on
    };
    static constexpr std::array<t_operation, 2> t_operation_values = { t_operation::off,
                                                                       t_operation::on };
    static constexpr std::array<std::string_view, 2> t_operation_names     = { "off", "on" };
    static constexpr std::array<std::string_view, 2> t_operation_alt_names = { "Off", "On" };
    using o_operation = tools::classhelper::OptionFrozen<t_operation,
                                                         t_operation_values.size(),
                                                         t_operation_values,
                                                         t_operation_names,
                                                         t_operation_alt_names>;

    // ----- match filter window type (7k DFD Table 43) -----
    enum class t_window_type : uint32_t
    {
        rectangular = 0, ///< rectangular
        kaiser      = 1, ///< Kaiser
        hamming     = 2, ///< Hamming
        blackmann   = 3, ///< Blackmann
        triangular  = 4, ///< triangular
        taylor      = 5, ///< X (Taylor)
    };
    static constexpr std::array<t_window_type, 6> t_window_type_values = {
        t_window_type::rectangular, t_window_type::kaiser,     t_window_type::hamming,
        t_window_type::blackmann,   t_window_type::triangular, t_window_type::taylor
    };
    static constexpr std::array<std::string_view, 6> t_window_type_names = {
        "rectangular", "kaiser", "hamming", "blackmann", "triangular", "taylor"
    };
    static constexpr std::array<std::string_view, 6> t_window_type_alt_names = {
        "Rectangular", "Kaiser", "Hamming", "Blackmann", "Triangular", "X (Taylor)"
    };
    using o_window_type = tools::classhelper::OptionFrozen<t_window_type,
                                                           t_window_type_values.size(),
                                                           t_window_type_values,
                                                           t_window_type_names,
                                                           t_window_type_alt_names>;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        uint64_t      _serial_number   = 0;   ///< sonar serial number
        uint32_t      _ping_number     = 0;   ///< sequential ping number
        o_operation   _operation;             ///< 0 = off, 1 = on
        float         _start_frequency = 0.f; ///< start frequency in Hz
        float         _end_frequency   = 0.f; ///< stop frequency in Hz
        o_window_type _window_type;           ///< match filter window type (0-5)
        float         _shading         = 0.f; ///< shading value
        float _effective_pulse_width = 0.f; ///< effective pulse width after FM compression (s)
        uint32_t _reserved[13]       = {};  ///< reserved

        uint32_t _checksum = 0; ///< record checksum (last 4 bytes; see S7KDatagram, debugging only)

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
    uint64_t      get_serial_number() const { return _content._serial_number; }
    uint32_t      get_ping_number() const { return _content._ping_number; }
    o_operation   get_operation() const { return _content._operation; }
    float         get_start_frequency() const { return _content._start_frequency; }
    float         get_end_frequency() const { return _content._end_frequency; }
    o_window_type get_window_type() const { return _content._window_type; }
    float         get_shading() const { return _content._shading; }
    float         get_effective_pulse_width() const { return _content._effective_pulse_width; }
    uint32_t      get_checksum() const { return _content._checksum; }

    void set_serial_number(uint64_t val) { _content._serial_number = val; }
    void set_ping_number(uint32_t val) { _content._ping_number = val; }
    void set_operation(o_operation val) { _content._operation = val; }
    void set_start_frequency(float val) { _content._start_frequency = val; }
    void set_end_frequency(float val) { _content._end_frequency = val; }
    void set_window_type(o_window_type val) { _content._window_type = val; }
    void set_shading(float val) { _content._shading = val; }
    void set_effective_pulse_width(float val) { _content._effective_pulse_width = val; }
    void set_checksum(uint32_t val) { _content._checksum = val; }

    // ----- operators -----
    bool operator==(const MatchFilter& other) const = default;

    //----- to/from stream functions -----
    static MatchFilter from_stream(std::istream& is, S7KDatagram header);
    static MatchFilter from_stream(std::istream& is);
    static MatchFilter from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier);

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
