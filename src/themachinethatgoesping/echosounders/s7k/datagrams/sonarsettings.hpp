// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/sonarsettings.doc.hpp"

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
 * @brief 7k record SonarSettings
 */
class SonarSettings : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::SonarSettings;

    // ----- transmit pulse type (7k DFD Table 42) -----
    enum class t_tx_pulse_type : uint32_t
    {
        cw    = 0, ///< CW
        chirp = 1, ///< linear chirp (FM)
    };
    static constexpr std::array<t_tx_pulse_type, 2> t_tx_pulse_type_values = {
        t_tx_pulse_type::cw, t_tx_pulse_type::chirp
    };
    static constexpr std::array<std::string_view, 2> t_tx_pulse_type_names     = { "cw", "chirp" };
    static constexpr std::array<std::string_view, 2> t_tx_pulse_type_alt_names = {
        "CW", "linear chirp (FM)"
    };
    using o_tx_pulse_type = tools::classhelper::OptionFrozen<t_tx_pulse_type,
                                                            t_tx_pulse_type_values.size(),
                                                            t_tx_pulse_type_values,
                                                            t_tx_pulse_type_names,
                                                            t_tx_pulse_type_alt_names>;

    // ----- transmit pulse envelope (7k DFD Table 42) -----
    enum class t_tx_pulse_envelope : uint32_t
    {
        tapered_rectangular = 0, ///< tapered rectangular
        tukey               = 1, ///< Tukey
        hamming             = 2, ///< Hamming
        han                 = 3, ///< Han
        rectangular         = 4, ///< rectangular
    };
    static constexpr std::array<t_tx_pulse_envelope, 5> t_tx_pulse_envelope_values = {
        t_tx_pulse_envelope::tapered_rectangular, t_tx_pulse_envelope::tukey,
        t_tx_pulse_envelope::hamming,             t_tx_pulse_envelope::han,
        t_tx_pulse_envelope::rectangular
    };
    static constexpr std::array<std::string_view, 5> t_tx_pulse_envelope_names = {
        "tapered_rectangular", "tukey", "hamming", "han", "rectangular"
    };
    static constexpr std::array<std::string_view, 5> t_tx_pulse_envelope_alt_names = {
        "Tapered rectangular", "Tukey", "Hamming", "Han", "Rectangular"
    };
    using o_tx_pulse_envelope = tools::classhelper::OptionFrozen<t_tx_pulse_envelope,
                                                                t_tx_pulse_envelope_values.size(),
                                                                t_tx_pulse_envelope_values,
                                                                t_tx_pulse_envelope_names,
                                                                t_tx_pulse_envelope_alt_names>;

    // ----- transmit pulse mode (7k DFD Table 42; low 16 bits, high 16 bits reserved) -----
    enum class t_tx_pulse_mode : uint32_t
    {
        undefined    = 0, ///< undefined / not set (written by some sonars, e.g. Norbit)
        single_ping  = 1, ///< single ping
        multi_ping_2 = 2, ///< multi-ping 2
        multi_ping_3 = 3, ///< multi-ping 3
        multi_ping_4 = 4, ///< multi-ping 4
    };
    static constexpr std::array<t_tx_pulse_mode, 5> t_tx_pulse_mode_values = {
        t_tx_pulse_mode::undefined, t_tx_pulse_mode::single_ping, t_tx_pulse_mode::multi_ping_2,
        t_tx_pulse_mode::multi_ping_3, t_tx_pulse_mode::multi_ping_4
    };
    static constexpr std::array<std::string_view, 5> t_tx_pulse_mode_names = {
        "undefined", "single_ping", "multi_ping_2", "multi_ping_3", "multi_ping_4"
    };
    static constexpr std::array<std::string_view, 5> t_tx_pulse_mode_alt_names = {
        "Undefined", "Single ping", "Multi-ping 2", "Multi-ping 3", "Multi-ping 4"
    };
    using o_tx_pulse_mode = tools::classhelper::OptionFrozen<t_tx_pulse_mode,
                                                            t_tx_pulse_mode_values.size(),
                                                            t_tx_pulse_mode_values,
                                                            t_tx_pulse_mode_names,
                                                            t_tx_pulse_mode_alt_names>;

    // ----- projector beam weighting window type (7k DFD Table 42) -----
    enum class t_projector_weighting : uint32_t
    {
        rectangular = 0, ///< rectangular
        chebychev   = 1, ///< Chebychev
        gauss       = 2, ///< Gauss
    };
    static constexpr std::array<t_projector_weighting, 3> t_projector_weighting_values = {
        t_projector_weighting::rectangular, t_projector_weighting::chebychev,
        t_projector_weighting::gauss
    };
    static constexpr std::array<std::string_view, 3> t_projector_weighting_names = {
        "rectangular", "chebychev", "gauss"
    };
    static constexpr std::array<std::string_view, 3> t_projector_weighting_alt_names = {
        "Rectangular", "Chebychev", "Gauss"
    };
    using o_projector_weighting =
        tools::classhelper::OptionFrozen<t_projector_weighting,
                                         t_projector_weighting_values.size(),
                                         t_projector_weighting_values,
                                         t_projector_weighting_names,
                                         t_projector_weighting_alt_names>;

    // ----- receive beam weighting window (7k DFD Table 42) -----
    enum class t_rx_weighting : uint32_t
    {
        chebychev = 0, ///< Chebychev
        kaiser    = 1, ///< Kaiser
    };
    static constexpr std::array<t_rx_weighting, 2> t_rx_weighting_values = {
        t_rx_weighting::chebychev, t_rx_weighting::kaiser
    };
    static constexpr std::array<std::string_view, 2> t_rx_weighting_names = { "chebychev",
                                                                              "kaiser" };
    static constexpr std::array<std::string_view, 2> t_rx_weighting_alt_names = { "Chebychev",
                                                                                  "Kaiser" };
    using o_rx_weighting = tools::classhelper::OptionFrozen<t_rx_weighting,
                                                            t_rx_weighting_values.size(),
                                                            t_rx_weighting_values,
                                                            t_rx_weighting_names,
                                                            t_rx_weighting_alt_names>;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        uint64_t            _serial_number       = 0;   ///< sonar serial number
        uint32_t            _ping_number         = 0;   ///< sequential ping number
        uint16_t            _multi_ping          = 0;   ///< 0 = single ping, else multi-ping seq
        float               _frequency           = 0.f; ///< transmit frequency in Hz
        float               _sample_rate         = 0.f; ///< sample rate in Hz
        float               _receiver_bandwidth  = 0.f; ///< receiver bandwidth in Hz
        float               _tx_pulse_width      = 0.f; ///< transmit pulse length in seconds
        o_tx_pulse_type     _tx_pulse_type;             ///< 0 = CW, 1 = chirp
        o_tx_pulse_envelope _tx_pulse_envelope;         ///< envelope/window type (0-4)
        float               _tx_pulse_envelope_parameter = 0.f; ///< envelope parameter
        o_tx_pulse_mode     _tx_pulse_mode;             ///< 1-4 (single/multi-ping mode)
        float               _max_ping_rate       = 0.f; ///< maximum ping rate in pings per second
        float               _ping_period         = 0.f; ///< seconds since previous ping
        float               _range_selection     = 0.f; ///< range selection in meters
        float               _power_selection     = 0.f; ///< power selection in dB re 1 uPa
        float               _gain_selection      = 0.f; ///< gain selection in dB
        uint32_t            _control_flags       = 0;   ///< control flags bit field (7k DFD Tbl 42)
        uint32_t            _projector_id        = 0;   ///< transmit projector identifier
        float               _steering_vertical   = 0.f; ///< transmit steering angle vertical (rad)
        float               _steering_horizontal = 0.f; ///< transmit steering angle horizontal (rad)
        float               _beamwidth_vertical  = 0.f; ///< transmit -3dB beam width vertical (rad)
        float               _beamwidth_horizontal = 0.f; ///< transmit -3dB beam width horizontal (rad)
        float               _focal_point         = 0.f; ///< transmit focal point in meters
        o_projector_weighting _projector_weighting;     ///< projector weighting window type (0-2)
        float               _projector_weighting_parameter = 0.f; ///< projector weighting parameter
        uint32_t            _transmit_flags      = 0;   ///< transmit flags bit field (7k DFD Tbl 42)
        uint32_t            _hydrophone_id       = 0;   ///< receiver hydrophone identifier
        o_rx_weighting      _rx_weighting;              ///< receiver weighting window type (0-1)
        float               _rx_weighting_parameter = 0.f; ///< receiver weighting parameter
        uint32_t            _rx_flags            = 0;   ///< receiver flags bit field (7k DFD Tbl 42)
        float               _rx_width            = 0.f; ///< receiver beam width in radians
        float               _range_minimum       = 0.f; ///< bottom detection minimum range (m)
        float               _range_maximum       = 0.f; ///< bottom detection maximum range (m)
        float               _depth_minimum       = 0.f; ///< bottom detection minimum depth (m)
        float               _depth_maximum       = 0.f; ///< bottom detection maximum depth (m)
        float               _absorption          = 0.f; ///< absorption
        float               _sound_velocity      = 0.f; ///< sound velocity
        float               _spreading           = 0.f; ///< spreading loss
        uint16_t            _reserved            = 0;   ///< reserved

        uint32_t _checksum = 0; ///< record checksum (last 4 bytes; see S7KDatagram, debugging only)

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content);

  public:
    SonarSettings();
    ~SonarSettings() = default;

    // ----- convenient member access -----
    uint64_t              get_serial_number() const;
    uint32_t              get_ping_number() const;
    uint16_t              get_multi_ping() const;
    float                 get_frequency() const;
    float                 get_sample_rate() const;
    float                 get_receiver_bandwidth() const;
    float                 get_tx_pulse_width() const;
    o_tx_pulse_type       get_tx_pulse_type() const;
    o_tx_pulse_envelope   get_tx_pulse_envelope() const;
    float                 get_tx_pulse_envelope_parameter() const;
    o_tx_pulse_mode       get_tx_pulse_mode() const;
    float                 get_max_ping_rate() const;
    float                 get_ping_period() const;
    float                 get_range_selection() const;
    float                 get_power_selection() const;
    float                 get_gain_selection() const;
    uint32_t              get_control_flags() const;
    uint32_t              get_projector_id() const;
    float                 get_steering_vertical() const;
    float                 get_steering_horizontal() const;
    float                 get_beamwidth_vertical() const;
    float                 get_beamwidth_horizontal() const;
    float                 get_focal_point() const;
    o_projector_weighting get_projector_weighting() const;
    float                 get_projector_weighting_parameter() const;
    uint32_t              get_transmit_flags() const;
    uint32_t              get_hydrophone_id() const;
    o_rx_weighting        get_rx_weighting() const;
    float                 get_rx_weighting_parameter() const;
    uint32_t              get_rx_flags() const;
    float                 get_rx_width() const;
    float                 get_range_minimum() const;
    float                 get_range_maximum() const;
    float                 get_depth_minimum() const;
    float                 get_depth_maximum() const;
    float                 get_absorption() const;
    float                 get_sound_velocity() const;
    float                 get_spreading() const;
    uint32_t              get_checksum() const;

    void set_serial_number(uint64_t val);
    void set_ping_number(uint32_t val);
    void set_multi_ping(uint16_t val);
    void set_frequency(float val);
    void set_sample_rate(float val);
    void set_receiver_bandwidth(float val);
    void set_tx_pulse_width(float val);
    void set_tx_pulse_type(o_tx_pulse_type val);
    void set_tx_pulse_envelope(o_tx_pulse_envelope val);
    void set_tx_pulse_envelope_parameter(float val);
    void set_tx_pulse_mode(o_tx_pulse_mode val);
    void set_max_ping_rate(float val);
    void set_ping_period(float val);
    void set_range_selection(float val);
    void set_power_selection(float val);
    void set_gain_selection(float val);
    void set_control_flags(uint32_t val);
    void set_projector_id(uint32_t val);
    void set_steering_vertical(float val);
    void set_steering_horizontal(float val);
    void set_beamwidth_vertical(float val);
    void set_beamwidth_horizontal(float val);
    void set_focal_point(float val);
    void set_projector_weighting(o_projector_weighting val);
    void set_projector_weighting_parameter(float val);
    void set_transmit_flags(uint32_t val);
    void set_hydrophone_id(uint32_t val);
    void set_rx_weighting(o_rx_weighting val);
    void set_rx_weighting_parameter(float val);
    void set_rx_flags(uint32_t val);
    void set_rx_width(float val);
    void set_range_minimum(float val);
    void set_range_maximum(float val);
    void set_depth_minimum(float val);
    void set_depth_maximum(float val);
    void set_absorption(float val);
    void set_sound_velocity(float val);
    void set_spreading(float val);
    void set_checksum(uint32_t val);

    // ----- processed data access -----
    /// @brief Get the transmit steering angle vertical in degrees (converted from radians).
    float get_steering_vertical_in_degrees() const;
    /// @brief Get the transmit steering angle horizontal in degrees (converted from radians).
    float get_steering_horizontal_in_degrees() const;
    /// @brief Get the transmit -3dB beam width vertical in degrees (converted from radians).
    float get_beamwidth_vertical_in_degrees() const;
    /// @brief Get the transmit -3dB beam width horizontal in degrees (converted from radians).
    float get_beamwidth_horizontal_in_degrees() const;
    /// @brief Get the receiver beam width in degrees (converted from radians).
    float get_rx_width_in_degrees() const;

    // ----- operators -----
    bool operator==(const SonarSettings& other) const = default;

    //----- to/from stream functions -----
    static SonarSettings from_stream(std::istream& is, S7KDatagram header);
    static SonarSettings from_stream(std::istream& is);
    static SonarSettings from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(SonarSettings)

  private:
    explicit SonarSettings(S7KDatagram header);
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping

// ----- explicit template instantiation (defined in sonarsettings.cpp) -----
extern template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_type,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_type_values
        .size(),
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_type_values,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_type_names,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_type_alt_names>;
extern template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_envelope,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_envelope_values
        .size(),
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_envelope_values,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_envelope_names,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::
        t_tx_pulse_envelope_alt_names>;
extern template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_mode,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_mode_values
        .size(),
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_mode_values,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_mode_names,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_mode_alt_names>;
extern template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_projector_weighting,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_projector_weighting_values
        .size(),
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_projector_weighting_values,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_projector_weighting_names,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::
        t_projector_weighting_alt_names>;
extern template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_rx_weighting,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_rx_weighting_values
        .size(),
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_rx_weighting_values,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_rx_weighting_names,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_rx_weighting_alt_names>;
