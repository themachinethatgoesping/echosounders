// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/runtimeparameters.doc.hpp"

// std includes
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief Runtime parameters datagrams
 */
class RuntimeParameters : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KongsbergAllDatagramIdentifier::RuntimeParameters;

  protected:
    uint16_t _ping_counter;
    uint16_t _system_serial_number;
    uint8_t  _operator_station_status;
    uint8_t  _processing_unit_status;
    uint8_t  _bsp_status;
    uint8_t  _sonar_head_or_transceiver_status;
    uint8_t  _mode;
    uint8_t  _filter_identifier;
    uint16_t _minimum_depth;                        ///< in meter
    uint16_t _maximum_depth;                        ///< in meter
    uint16_t _absorption_coefficient;               ///< in 0.01 dB/km
    uint16_t _transmit_pulse_length;                ///< in μs
    uint16_t _transmit_beamwidth;                   ///< in 0.1 degrees
    int8_t   _transmit_power_relative_maximum;      ///< in dB
    uint8_t  _receive_beamwidth_degree;             ///< in 0.1 degrees
    uint8_t  _receive_bandwidth_50hz;               ///< in 50 Hz resolution
    uint8_t  _mode2_or_receiver_fixed_gain_setting; ///< in dB
    uint8_t  _tvg_law_crossover_angle;              ///< in degrees
    uint8_t  _source_of_sound_speed_at_transducer;
    uint16_t _maximum_port_swath_width; ///< in meter
    uint8_t  _beam_spacing;
    uint8_t  _maximum_port_coverage; ///< in degrees
    uint8_t  _yaw_and_pitch_stabilization_mode;
    uint8_t  _maximum_starboard_coverage;    ///< in degrees
    uint16_t _maximum_starboard_swath_width; ///< in meter

    int16_t _transmit_along_tilt; ///< in 0.1 degree
    // or TODO: this should be a union, Durotong speed is used for EM1002 transducer (not yet
    // supported) uint16_t _Durotong_speed; // in dm/s

    //
    uint8_t _filter_identifier2;
    // or TODO: this should be a union, _HiLo_frequency_absorption_coefficient_ratio speed is used
    // for EM1002 transducer (not yet supported) uint8_t
    // _HiLo_frequency_absorption_coefficient_ratio;

    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit RuntimeParameters(KongsbergAllDatagram header)
        : KongsbergAllDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    RuntimeParameters() { _datagram_identifier = t_KongsbergAllDatagramIdentifier::RuntimeParameters; }
    ~RuntimeParameters() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_ping_counter() const { return _ping_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint8_t  get_operator_station_status() const { return _operator_station_status; }
    uint8_t  get_processing_unit_status() const { return _processing_unit_status; }
    uint8_t  get_bsp_status() const { return _bsp_status; }
    uint8_t  get_sonar_head_or_transceiver_status() const
    {
        return _sonar_head_or_transceiver_status;
    }
    uint8_t  get_mode() const { return _mode; }
    uint8_t  get_filter_identifier() const { return _filter_identifier; }
    uint16_t get_minimum_depth() const { return _minimum_depth; }
    uint16_t get_maximum_depth() const { return _maximum_depth; }
    uint16_t get_absorption_coefficient() const { return _absorption_coefficient; }
    uint16_t get_transmit_pulse_length() const { return _transmit_pulse_length; }
    uint16_t get_transmit_beamwidth() const { return _transmit_beamwidth; }
    int8_t  get_transmit_power_relative_maximum() const { return _transmit_power_relative_maximum; }
    uint8_t get_receive_beamwidth_degree() const { return _receive_beamwidth_degree; }
    uint8_t get_receive_bandwidth_50hz() const { return _receive_bandwidth_50hz; }
    uint8_t get_mode2_or_receiver_fixed_gain_setting() const
    {
        return _mode2_or_receiver_fixed_gain_setting;
    }
    uint8_t get_tvg_law_crossover_angle() const { return _tvg_law_crossover_angle; }
    uint8_t get_source_of_sound_speed_at_transducer() const
    {
        return _source_of_sound_speed_at_transducer;
    }
    uint16_t get_maximum_port_swath_width() const { return _maximum_port_swath_width; }
    uint8_t  get_beam_spacing() const { return _beam_spacing; }
    uint8_t  get_maximum_port_coverage() const { return _maximum_port_coverage; }
    uint8_t  get_yaw_and_pitch_stabilization_mode() const
    {
        return _yaw_and_pitch_stabilization_mode;
    }
    uint8_t  get_maximum_starboard_coverage() const { return _maximum_starboard_coverage; }
    uint16_t get_maximum_starboard_swath_width() const { return _maximum_starboard_swath_width; }
    int16_t  get_transmit_along_tilt() const { return _transmit_along_tilt; }
    uint8_t  get_filter_identifier2() const { return _filter_identifier2; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    // setters
    void set_ping_counter(uint16_t ping_counter) { _ping_counter = ping_counter; }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_operator_station_status(uint8_t operator_station_status)
    {
        _operator_station_status = operator_station_status;
    }
    void set_processing_unit_status(uint8_t processing_unit_status)
    {
        _processing_unit_status = processing_unit_status;
    }
    void set_bsp_status(uint8_t bsp_status) { _bsp_status = bsp_status; }
    void set_sonar_head_or_transceiver_status(uint8_t sonar_head_or_transceiver_status)
    {
        _sonar_head_or_transceiver_status = sonar_head_or_transceiver_status;
    }
    void set_mode(uint8_t mode) { _mode = mode; }
    void set_filter_identifier(uint8_t filter_identifier)
    {
        _filter_identifier = filter_identifier;
    }
    void set_minimum_depth(uint16_t minimum_depth) { _minimum_depth = minimum_depth; }
    void set_maximum_depth(uint16_t maximum_depth) { _maximum_depth = maximum_depth; }
    void set_absorption_coefficient(uint16_t absorption_coefficient)
    {
        _absorption_coefficient = absorption_coefficient;
    }
    void set_transmit_pulse_length(uint16_t transmit_pulse_length)
    {
        _transmit_pulse_length = transmit_pulse_length;
    }
    void set_transmit_beamwidth(uint16_t transmit_beamwidth)
    {
        _transmit_beamwidth = transmit_beamwidth;
    }
    void set_transmit_power_relative_maximum(int8_t transmit_power_relative_maximum)
    {
        _transmit_power_relative_maximum = transmit_power_relative_maximum;
    }
    void set_receive_beamwidth_degree(uint8_t receive_bandwidth_degree)
    {
        _receive_beamwidth_degree = receive_bandwidth_degree;
    }
    void set_receive_bandwidth_50hz(uint8_t receive_bandwidth_50hz)
    {
        _receive_bandwidth_50hz = receive_bandwidth_50hz;
    }
    void set_mode2_or_receiver_fixed_gain_setting(uint8_t mode2_or_receiver_fixed_gain_setting)
    {
        _mode2_or_receiver_fixed_gain_setting = mode2_or_receiver_fixed_gain_setting;
    }
    void set_tvg_law_crossover_angle(uint8_t tvg_law_crossover_angle)
    {
        _tvg_law_crossover_angle = tvg_law_crossover_angle;
    }
    void set_source_of_sound_speed_at_transducer(uint8_t source)
    {
        _source_of_sound_speed_at_transducer = source;
    }
    void set_maximum_port_swath_width(uint16_t maximum_port_swath_width)
    {
        _maximum_port_swath_width = maximum_port_swath_width;
    }
    void set_beam_spacing(uint8_t beam_spacing) { _beam_spacing = beam_spacing; }
    void set_maximum_port_coverage(uint8_t maximum_port_coverage)
    {
        _maximum_port_coverage = maximum_port_coverage;
    }
    void set_yaw_and_pitch_stabilization_mode(uint8_t yaw_and_pitch_stabilization_mode)
    {
        _yaw_and_pitch_stabilization_mode = yaw_and_pitch_stabilization_mode;
    }
    void set_maximum_starboard_coverage(uint8_t maximum_starboard_coverage)
    {
        _maximum_starboard_coverage = maximum_starboard_coverage;
    }
    void set_maximum_starboard_swath_width(uint16_t maximum_starboard_swath_width)
    {
        _maximum_starboard_swath_width = maximum_starboard_swath_width;
    }
    void set_transmit_along_tilt(int16_t transmit_along_tilt)
    {
        _transmit_along_tilt = transmit_along_tilt;
    }
    void set_filter_identifier2(uint8_t filter_identifier2)
    {
        _filter_identifier2 = filter_identifier2;
    }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // ----- processed data access -----
    /**
     * @brief Get the absorption coefficient in db per meter
     *
     * @return _absorption_coefficient * 0.00001f (float)
     */
    float get_absorption_coefficient_in_db_per_meter() const
    {
        return _absorption_coefficient * 0.00001f;
    }

    /**
     * @brief Get the transmit pulse length in seconds
     *
     * @return _transmit_pulse_length * 0.000001f (float)
     */
    float get_transmit_pulse_length_in_seconds() const
    {
        return _transmit_pulse_length * 0.000001f;
    }

    /**
     * @brief Get the transmit beamwidth in degrees
     *
     * @return _transmit_beamwidth * 0.1f (float)
     */
    float get_transmit_beamwidth_in_degrees() const { return _transmit_beamwidth * 0.1f; }

    /**
     * @brief Get the receive beamwidth in degrees
     *
     * @return _receive_beamwidth_degree * 0.1f (float)
     */
    float get_receive_beamwidth_in_degrees() const { return _receive_beamwidth_degree * 0.1f; }

    /**
     * @brief Get the receive bandwidth in Hz
     *
     * @return _receive_bandwidth_50hz * 50.f (float)
     */
    float get_receive_bandwidth_in_hertz() const { return _receive_bandwidth_50hz * 50.f; }

    /**
     * @brief Get the transmit along tilt in degrees
     *
     * @return _transmit_along_tilt * 0.1f (float)
     */
    float get_transmit_along_tilt_in_degrees() const { return _transmit_along_tilt * 0.1f; }

    // ----- operators -----
    bool operator==(const RuntimeParameters& other) const = default;

    //----- to/from stream functions -----
    static RuntimeParameters from_stream(std::istream& is, KongsbergAllDatagram header)
    {
        RuntimeParameters datagram(std::move(header));

        if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::RuntimeParameters)
            throw std::runtime_error(
                fmt::format("RuntimeParameters: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                            uint8_t(t_KongsbergAllDatagramIdentifier::RuntimeParameters),
                            uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 40 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "RuntimeParameters: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static RuntimeParameters from_stream(std::istream& is)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is));
    }

    static RuntimeParameters from_stream(std::istream&              is,
                                         t_KongsbergAllDatagramIdentifier datagram_identifier)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
    }

    void to_stream(std::ostream& os) const
    {
        KongsbergAllDatagram::to_stream(os);

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_ping_counter)), 40 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("RuntimeParameters", float_precision);

        printer.append(KongsbergAllDatagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("ping_counter", _ping_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("operator_station_status", _operator_station_status);
        printer.register_value("processing_unit_status", _processing_unit_status);
        printer.register_value("bsp_status", _bsp_status);
        printer.register_value("sonar_head_or_transceiver_status",
                               _sonar_head_or_transceiver_status);
        printer.register_value("mode", _mode);
        printer.register_value("filter_identifier", _filter_identifier);
        printer.register_value("minimum_depth", _minimum_depth, "m");
        printer.register_value("maximum_depth", _maximum_depth, "m");
        printer.register_value("absorption_coefficient", _absorption_coefficient, "0.01 db/km");
        printer.register_value("transmit_pulse_length", _transmit_pulse_length, "μs");
        printer.register_value("transmit_beamwidth", _transmit_beamwidth, "0.1°");
        printer.register_value(
            "transmit_power_relative_maximum", _transmit_power_relative_maximum, "dB");
        printer.register_value("receive_bandwidth_degree", _receive_beamwidth_degree, "0.1°");
        printer.register_value("receive_bandwidth_50hz", _receive_bandwidth_50hz, "50Hz");
        printer.register_value(
            "mode2_or_receiver_fixed_gain_setting", _mode2_or_receiver_fixed_gain_setting, "dB");
        printer.register_value("tvg_law_crossover_angle", _tvg_law_crossover_angle, "°");
        printer.register_value("source_of_sound_speed_at_transducer",
                               _source_of_sound_speed_at_transducer);
        printer.register_value("maximum_port_swath_width", _maximum_port_swath_width, "m");
        printer.register_value("beam_spacing", _beam_spacing);
        printer.register_value("maximum_port_coverage", _maximum_port_coverage, "°");
        printer.register_value("yaw_and_pitch_stabilization_mode",
                               _yaw_and_pitch_stabilization_mode);
        printer.register_value("maximum_starboard_coverage", _maximum_starboard_coverage, "°");
        printer.register_value(
            "maximum_starboard_swath_width", _maximum_starboard_swath_width, "m");
        printer.register_value("transmit_along_tilt", _transmit_along_tilt, "0.1°");
        printer.register_value("filter_identifier2", _filter_identifier2);
        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        printer.register_section("processed");
        printer.register_value(
            "absorption_coefficient", get_absorption_coefficient_in_db_per_meter(), "db/m");
        printer.register_value(
            "transmit_pulse_length", get_transmit_pulse_length_in_seconds(), "s");
        printer.register_value("transmit_beamwidth", get_transmit_beamwidth_in_degrees(), "°");
        printer.register_value("receive_bandwidth", get_receive_beamwidth_in_degrees(), "°");
        printer.register_value("receive_bandwidth", get_receive_bandwidth_in_hertz(), "Hz");
        printer.register_value("transmit_along_tilt", get_transmit_along_tilt_in_degrees(), "°");

        return printer;
    }

    xxh::hash_t<64> hash_content_only() const
    {
        // hash streaming
        xxh::hash3_state_t<64> hash_stream;

        // use all variables starting from system_serial number
        // ignore e.g. timestamp and ping_counter to be useful in the deduplicate buffer
        hash_stream.update(&_system_serial_number, 35);

        return hash_stream.digest();
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(RuntimeParameters)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
