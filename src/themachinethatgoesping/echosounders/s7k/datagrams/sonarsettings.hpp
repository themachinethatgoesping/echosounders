// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/sonarsettings.doc.hpp"

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
 * @brief 7k record SonarSettings
 */
class SonarSettings : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::SonarSettings;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        uint64_t serial_number; ///< sonar serial number
        uint32_t ping_number; ///< sequential ping number
        uint16_t multi_ping; ///< 0 = single ping, else multi-ping sequence number
        float frequency; ///< transmit frequency
        float sample_rate; ///< sample rate
        float receiver_bandwidth; ///< receiver bandwidth
        float tx_pulse_width; ///< transmit pulse length
        uint32_t tx_pulse_type; ///< 0 = CW, 1 = chirp
        uint32_t tx_pulse_envelope; ///< envelope/window type (0-4)
        float tx_pulse_envelope_parameter; ///< envelope parameter
        uint32_t tx_pulse_mode; ///< 1-4 (single/multi-ping mode)
        float max_ping_rate; ///< maximum ping rate
        float ping_period; ///< time since previous ping
        float range_selection; ///< range selection
        float power_selection; ///< power selection (dB re 1 uPa)
        float gain_selection; ///< gain selection
        uint32_t control_flags; ///< control flags bit field
        uint32_t projector_id; ///< transmit projector identifier
        float steering_vertical; ///< transmit steering angle vertical
        float steering_horizontal; ///< transmit steering angle horizontal
        float beamwidth_vertical; ///< transmit -3dB beam width vertical
        float beamwidth_horizontal; ///< transmit -3dB beam width horizontal
        float focal_point; ///< transmit focal point
        uint32_t projector_weighting; ///< projector weighting window type (0-2)
        float projector_weighting_parameter; ///< projector weighting parameter
        uint32_t transmit_flags; ///< transmit flags bit field
        uint32_t hydrophone_id; ///< receiver hydrophone identifier
        uint32_t rx_weighting; ///< receiver weighting window type (0-1)
        float rx_weighting_parameter; ///< receiver weighting parameter
        uint32_t rx_flags; ///< receiver flags bit field
        float rx_width; ///< receiver beam width
        float range_minimum; ///< bottom detection minimum range
        float range_maximum; ///< bottom detection maximum range
        float depth_minimum; ///< bottom detection minimum depth
        float depth_maximum; ///< bottom detection maximum depth
        float absorption; ///< absorption
        float sound_velocity; ///< sound velocity
        float spreading; ///< spreading loss
        uint16_t reserved; ///< reserved

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content);

  public:
    SonarSettings()
        : _content{}
    {
        set_datagram_identifier(DatagramIdentifier);
    }
    ~SonarSettings() = default;

    // ----- convenient member access -----
    uint64_t get_serial_number() const { return _content.serial_number; }
    uint32_t get_ping_number() const { return _content.ping_number; }
    uint16_t get_multi_ping() const { return _content.multi_ping; }
    float get_frequency() const { return _content.frequency; }
    float get_sample_rate() const { return _content.sample_rate; }
    float get_receiver_bandwidth() const { return _content.receiver_bandwidth; }
    float get_tx_pulse_width() const { return _content.tx_pulse_width; }
    uint32_t get_tx_pulse_type() const { return _content.tx_pulse_type; }
    uint32_t get_tx_pulse_envelope() const { return _content.tx_pulse_envelope; }
    float get_tx_pulse_envelope_parameter() const { return _content.tx_pulse_envelope_parameter; }
    uint32_t get_tx_pulse_mode() const { return _content.tx_pulse_mode; }
    float get_max_ping_rate() const { return _content.max_ping_rate; }
    float get_ping_period() const { return _content.ping_period; }
    float get_range_selection() const { return _content.range_selection; }
    float get_power_selection() const { return _content.power_selection; }
    float get_gain_selection() const { return _content.gain_selection; }
    uint32_t get_control_flags() const { return _content.control_flags; }
    uint32_t get_projector_id() const { return _content.projector_id; }
    float get_steering_vertical() const { return _content.steering_vertical; }
    float get_steering_horizontal() const { return _content.steering_horizontal; }
    float get_beamwidth_vertical() const { return _content.beamwidth_vertical; }
    float get_beamwidth_horizontal() const { return _content.beamwidth_horizontal; }
    float get_focal_point() const { return _content.focal_point; }
    uint32_t get_projector_weighting() const { return _content.projector_weighting; }
    float get_projector_weighting_parameter() const { return _content.projector_weighting_parameter; }
    uint32_t get_transmit_flags() const { return _content.transmit_flags; }
    uint32_t get_hydrophone_id() const { return _content.hydrophone_id; }
    uint32_t get_rx_weighting() const { return _content.rx_weighting; }
    float get_rx_weighting_parameter() const { return _content.rx_weighting_parameter; }
    uint32_t get_rx_flags() const { return _content.rx_flags; }
    float get_rx_width() const { return _content.rx_width; }
    float get_range_minimum() const { return _content.range_minimum; }
    float get_range_maximum() const { return _content.range_maximum; }
    float get_depth_minimum() const { return _content.depth_minimum; }
    float get_depth_maximum() const { return _content.depth_maximum; }
    float get_absorption() const { return _content.absorption; }
    float get_sound_velocity() const { return _content.sound_velocity; }
    float get_spreading() const { return _content.spreading; }

    void set_serial_number(uint64_t val) { _content.serial_number = val; }
    void set_ping_number(uint32_t val) { _content.ping_number = val; }
    void set_multi_ping(uint16_t val) { _content.multi_ping = val; }
    void set_frequency(float val) { _content.frequency = val; }
    void set_sample_rate(float val) { _content.sample_rate = val; }
    void set_receiver_bandwidth(float val) { _content.receiver_bandwidth = val; }
    void set_tx_pulse_width(float val) { _content.tx_pulse_width = val; }
    void set_tx_pulse_type(uint32_t val) { _content.tx_pulse_type = val; }
    void set_tx_pulse_envelope(uint32_t val) { _content.tx_pulse_envelope = val; }
    void set_tx_pulse_envelope_parameter(float val) { _content.tx_pulse_envelope_parameter = val; }
    void set_tx_pulse_mode(uint32_t val) { _content.tx_pulse_mode = val; }
    void set_max_ping_rate(float val) { _content.max_ping_rate = val; }
    void set_ping_period(float val) { _content.ping_period = val; }
    void set_range_selection(float val) { _content.range_selection = val; }
    void set_power_selection(float val) { _content.power_selection = val; }
    void set_gain_selection(float val) { _content.gain_selection = val; }
    void set_control_flags(uint32_t val) { _content.control_flags = val; }
    void set_projector_id(uint32_t val) { _content.projector_id = val; }
    void set_steering_vertical(float val) { _content.steering_vertical = val; }
    void set_steering_horizontal(float val) { _content.steering_horizontal = val; }
    void set_beamwidth_vertical(float val) { _content.beamwidth_vertical = val; }
    void set_beamwidth_horizontal(float val) { _content.beamwidth_horizontal = val; }
    void set_focal_point(float val) { _content.focal_point = val; }
    void set_projector_weighting(uint32_t val) { _content.projector_weighting = val; }
    void set_projector_weighting_parameter(float val) { _content.projector_weighting_parameter = val; }
    void set_transmit_flags(uint32_t val) { _content.transmit_flags = val; }
    void set_hydrophone_id(uint32_t val) { _content.hydrophone_id = val; }
    void set_rx_weighting(uint32_t val) { _content.rx_weighting = val; }
    void set_rx_weighting_parameter(float val) { _content.rx_weighting_parameter = val; }
    void set_rx_flags(uint32_t val) { _content.rx_flags = val; }
    void set_rx_width(float val) { _content.rx_width = val; }
    void set_range_minimum(float val) { _content.range_minimum = val; }
    void set_range_maximum(float val) { _content.range_maximum = val; }
    void set_depth_minimum(float val) { _content.depth_minimum = val; }
    void set_depth_maximum(float val) { _content.depth_maximum = val; }
    void set_absorption(float val) { _content.absorption = val; }
    void set_sound_velocity(float val) { _content.sound_velocity = val; }
    void set_spreading(float val) { _content.spreading = val; }

    // ----- operators -----
    bool operator==(const SonarSettings& other) const = default;

    //----- to/from stream functions -----
    static SonarSettings from_stream(std::istream& is, S7KDatagram header);
    static SonarSettings from_stream(std::istream& is);
    static SonarSettings from_stream(std::istream& is, t_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(SonarSettings)

  private:
    explicit SonarSettings(S7KDatagram header)
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
