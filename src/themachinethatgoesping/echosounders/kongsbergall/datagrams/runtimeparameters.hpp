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
    explicit RuntimeParameters(const KongsbergAllDatagram& header)
        : KongsbergAllDatagram(header)
    {
    }

  public:
    // ----- public constructors -----
    RuntimeParameters()
    {
        _datagram_identifier = t_KongsbergAllDatagramIdentifier::RuntimeParameters;
    }
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

    // ----- mode/flags decoding -----

    /**
     * @brief Retrieves Ping mode decoded in the 'mode' variable.
     *
     * The decoding is EM model specific. See datagram format specification for details.
     *
     * @param unhandled_message If provided, this message is used as the return value if the mode
     *                          is not handled for the specific system. Otherwise: 'Ping mode
     * unhandled' or 'Ping mode not implemented' is returned
     * @return A string representing Ping mode as encoded by 'mode'
     */
    std::string get_mode_as_ping_mode(std::optional<std::string_view> unhandled_message) const
    {
        switch (this->get_model_number())
        {
            case 3000:
                switch (_mode & 0b00001111)
                {
                    case 0b00000000:
                        return "Nearfield (4°)";
                    case 0b00000001:
                        return "Normal (1.5°)";
                    case 0b00000010:
                        return "Target detect";
                    default:
                        break;
                }
                break;
            case 3002:
                switch (_mode & 0b00001111)
                {
                    case 0b00000000:
                        return "Wide Tx beamwidth (4°)";
                    case 0b00000001:
                        return "Normal Tx beamwidth (1.5°)";
                    default:
                        break;
                }
                break;
            case 2000:
                [[fallthrough]];
            case 710:
                [[fallthrough]];
            case 1002:
                [[fallthrough]];
            case 300:
                [[fallthrough]];
            case 302:
                [[fallthrough]];
            case 120:
                [[fallthrough]];
            case 122:
                switch (_mode & 0b00001111)
                {
                    case 0b00000000:
                        return "Very shallow";
                    case 0b00000001:
                        return "Shallow";
                    case 0b00000010:
                        return "Medium";
                    case 0b00000011:
                        return "Deep";
                    case 0b00000100:
                        return "Very deep";
                    case 0b00000101:
                        return "Extra deep";
                    default:
                        break;
                }
                break;
            case 2040:
                switch (_mode & 0b00001111)
                {
                    case 0b00000000:
                        return "200 kHz";
                    case 0b00000001:
                        return "300 kHz";
                    case 0b00000010:
                        return "400 kHz";
                    default:
                        break;
                }
                break;
            case 2045: // EM2040C, we decode the 'Frequency' as PingMode here, since this was also
                       // the choice for the EM2040
            {
                uint_fast16_t frequency = (_mode & 0b00011111) + 180;
                return fmt::format("{} kHz", frequency);
            }
            default:
                // this is returned if the model number is not handled
                return std::string(unhandled_message.value_or(
                    fmt::format("Ping mode unhandled for EM{{}} [{:08b}]", _model_number, _mode)));
        }

        // this is returned if a known model number does not handle a mode value
        return std::string(unhandled_message.value_or(fmt::format(
            "Ping mode not implemented for [{}/{:08b}]", get_model_number_as_string(), _mode)));
    }

    /**
     * @brief Retrieves Tx pulse form encoded in the mode variable
     *
     * The decoding is EM model specific. See datagram format specification for details.
     *
     * @param unhandled_message If provided, this message is used as the return value if the mode
     *                          is not handled for the specific system. Otherwise: 'Ping mode
     * unhandled' or 'Ping mode not implemented' is returned
     * @return A string representing Tx pulse form as encoded by 'mode'
     */
    std::string get_mode_as_tx_pulse_form(std::optional<std::string_view> unhandled_message) const
    {
        // handled by file: 2040,710, 302, 122, 2040C
        // Asume CW for [1002, 2000, 3000, 3002, 300, 120]
        switch (this->get_model_number())
        {
            case 2040:
                [[fallthrough]];
            case 710:
                [[fallthrough]];
            case 302:
                [[fallthrough]];
            case 122:
                switch (_mode & 00110000)
                {
                    case 0b00000000:
                        return "CW";
                    case 0b00010000:
                        return "Mixed";
                    case 0b00100000:
                        return "FM";
                    default:
                        break;
                }
                break;
            case 2045: // EM2040C
            {
                switch (_mode & 0b00100000)
                {
                    case 0b00000000:
                        return "CW";
                    case 0b00100000:
                        return "FM";
                    default:
                        break;
                }
                break;
            }
            // we assume CW for all older unhandled models
            case 1002:
                [[fallthrough]];
            case 2000:
                [[fallthrough]];
            case 3000:
                [[fallthrough]];
            case 3002:
                [[fallthrough]];
            case 300:
                [[fallthrough]];
            case 120:
                return "CW";
            default:
                // this is returned if the model number is not handled
                return std::string(unhandled_message.value_or(fmt::format(
                    "TX pulse form not implemented for EM{{}} [{:08b}]", _model_number, _mode)));
        }

        // this is returned if a known model number does not handle a mode value
        return std::string(unhandled_message.value_or(
            fmt::format("Unknown tx pulse form [{}/{:08b}]", get_model_number_as_string(), _mode)));
    }

    /**
     * @brief Retrieves Dual swath mode encoded in the mode variable
     *
     * The decoding is EM model specific. See datagram format specification for details.
     *
     * @param unhandled_message If provided, this message is used as the return value if the mode
     *                          is not handled for the specific system. Otherwise: 'Ping mode
     * unhandled' or 'Ping mode not implemented' is returned
     * @return A string representing Tx pulse form as encoded by 'mode'
     */
    std::string get_mode_as_dual_swath_mode(std::optional<std::string_view> unhandled_message) const
    {
        // handled by file: 2040,710, 302, 122,
        // Asume 'Off' for [2040C, 1002, 2000, 3000, 3002, 300, 120]
        switch (this->get_model_number())
        {
            case 2040:
                [[fallthrough]];
            case 710:
                [[fallthrough]];
            case 302:
                [[fallthrough]];
            case 122:
                switch (_mode & 11000000)
                {
                    case 0b00000000:
                        return "Off";
                    case 0b01000000:
                        return "Fixed";
                    case 0b10000000:
                        return "Dynamic";
                    default:
                        break;
                }
                break;
            // we assume 'Off' for all older (and EM2040C) unhandled models
            case 2045:
                [[fallthrough]];
            case 1002:
                [[fallthrough]];
            case 2000:
                [[fallthrough]];
            case 3000:
                [[fallthrough]];
            case 3002:
                [[fallthrough]];
            case 300:
                [[fallthrough]];
            case 120:
                return "Off";
            default:
                // this is returned if the model number is not handled
                return std::string(unhandled_message.value_or(fmt::format(
                    "Dual swath mode not implemented for EM{{}} [{:08b}]", _model_number, _mode)));
        }

        // this is returned if a known model number does not handle a mode value
        return std::string(unhandled_message.value_or(fmt::format(
            "Unknown dual swath mode [{}/{:08b}]", get_model_number_as_string(), _mode)));
    }

    // mode 2

    // /**
    //  * @brief Retrieves Rx array/ sonar head encoded in the mode2 variable
    //  *
    //  * The decoding is EM model specific. Currentylu only outputs sensefull values for EM2040 and
    //  * EM2040C. See datagram format specification for details.
    //  *
    //  * @param unhandled_message If provided, this message is used as the return value if the mode
    //  *                          is not handled for the specific system. Otherwise: 'Sonar head
    //  * use unhandled' is returned
    //  * @return A string representing Rx array / Sonar head use as encoded by 'mode2'
    //  */
    // std::string get_mode2_as_rx_or_sonar_head_use(std::optional<std::string_view> unhandled_message) const
    // {
    //     switch(get_model_number())
    //     {
    //         case 2040:
    //             [[fallthrough]];
    //         case 2045:
    //             switch (_mode2_or_receiver_fixed_gain_setting & 0b00000011)
    //             {
    //                 case 0b00000000:
    //                     return "Rx";
    //                 case 0b00000001:
    //                     return "Sonar head use";
    //                 default:
    //                     break;
    //             }
    //             break;
    //         default:
    //             break;
    //     }

    //     return std::string(unhandled_message.value_or(fmt::format(
    //         "Mode 2 not implemented for [{:08b}]", _mode2_or_receiver_fixed_gain_setting)));
    // }

    /**
     * @brief Retrieves spike filter setup encoded in the filter_identifier variable
     *
     * @return A string representing the spike filter setup as encoded by 'filter_identifier'
     */
    std::string get_filter_identifier_as_spike_filter() const
    {
        switch (_filter_identifier & 0b00000011)
        {
            case 0b00000000:
                return "Off";
            case 0b00000001:
                return "Weak";
            case 0b00000010:
                return "Medium";
            case 0b00000011:
                return "Strong";
            default:
                throw std::runtime_error(
                    fmt::format("{} reached unreachable state. Please report", __func__));
        }
    }

    /**
     * @brief Retrieves slope filter status encoded in the filter_identifier variable
     *
     * @return A string representing the slope filter status (On or Off) as encoded by
     * 'filter_identifier'
     */
    std::string get_filter_identifier_as_slope_filter() const
    {
        if (_filter_identifier & 0b00000100)
            return "On";

        return "Off";
    }

    /**
     * @brief Retrieves Range gates size encoded in the mode variable
     *
     * @param unhandled_message If provided, this message is used as the return value if the range
     *                          gates size is not handled for the specific system. Otherwise: Range
     *                          gates size not implemented' is returned
     * @return A string representing Range gates size as encoded by 'mode'
     */
    std::string get_filter_identifier_as_range_gates_size(
        std::optional<std::string_view> unhandled_message) const
    {
        switch (_filter_identifier & 0b10010000)
        {
            case 0b00000000:
                return "Normal";
            case 0b00010000:
                return "Large";
            case 0b10000000:
                return "Small";
            default:
                return std::string(unhandled_message.value_or(fmt::format(
                    "Range gates size not implemented for [{:08b}]", _filter_identifier)));
        }
    }

    // source of sound speed at transducer

    /**
     * @brief Retrieves the source of sound speed at transducer encoded in the
     * 'source of sound speed at transducer' variable
     *
     * @param unhandled_message If provided, this message is used as the return value if the source
     *                          of sound speed at transducer mode specified is not handled.
     * @return A string representing the source of sound speed at transducer as encoded by the
     * 'source of sound speed at transducer' variable
     */
    std::string get_source_of_sound_speed_at_transducer_as_string(
        std::optional<std::string_view> unhandled_message) const
    {
        switch (_source_of_sound_speed_at_transducer & 0b00001111)
        {
            case 0b00000000:
                return "From real time sensor";
            case 0b00000001:
                return "Manually entered by operator";
            case 0b00000010:
                return "Interpolated from currently used sound speed profile";
            case 0b00000011:
                return "Calculated by ME70BO TRU";
            default:
                return std::string(unhandled_message.value_or(
                    fmt::format("Source of sound speed at transducer mode not implemented [{:08b}]",
                                _source_of_sound_speed_at_transducer)));
        }
    }

    /**
     * @brief Retrieves the Extra detections option (On/Off) encoded in the
     * 'source of sound speed at transducer' variable
     *
     * @return True if the Extra detections option is enabled, false otherwise
     */
    bool get_extra_detections_enabled() const
    {
        return _source_of_sound_speed_at_transducer & 0b00010000;
    }

    /**
     * @brief Retrieves the Sonar mode option (On/Off) encoded in the
     * 'source of sound speed at transducer' variable
     *
     * @return True if the Sonar mode option is enabled, false otherwise
     */
    bool get_sonar_mode_enabled() const
    {
        return _source_of_sound_speed_at_transducer & 0b00100000;
    }

    /**
     * @brief Retrieves the Passive mode option (On/Off) encoded in the
     * 'source of sound speed at transducer' variable
     *
     * @return True if the Passive mode option is enabled, false otherwise
     */
    bool get_passive_mode_enabled() const
    {
        return _source_of_sound_speed_at_transducer & 0b01000000;
    }

    /**
     * @brief Retrieves the 3D scanning option (On/Off) encoded in the
     * 'source of sound speed at transducer' variable
     *
     * @return True if the 3D scanning option is enabled, false otherwise
     */
    bool get_3d_scanning_enabled() const
    {
        return _source_of_sound_speed_at_transducer & 0b10000000;
    }

    /**
     * @brief Retrieves the Aearation filter status encoded in the filter_identifier variable
     *
     * @return A string representing the Aeration filter status (On or Off) as encoded by
     * 'filter_identifier'
     */
    std::string get_filter_identifier_as_aeration_filter()
    {
        if (_filter_identifier & 0b00100000)
            return "On";

        return "Off";
    }

    /**
     * @brief Retrieves the Interference filter status encoded in the filter_identifier variable
     *
     * @return A string representing the Interference filter status (On or Off) as encoded by
     * 'filter_identifier'
     */
    std::string get_filter_identifier_as_interference_filter()
    {
        if (_filter_identifier & 0b01000000)
            return "On";

        return "Off";
    }

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

    static RuntimeParameters from_stream(std::istream&                    is,
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
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "RuntimeParameters", float_precision, superscript_exponents);

        printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
        printer.register_section("datagram content");
        printer.register_value("ping_counter", _ping_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("operator_station_status", _operator_station_status);
        printer.register_value("processing_unit_status", _processing_unit_status);
        printer.register_value("bsp_status", _bsp_status);
        printer.register_value("sonar_head_or_transceiver_status",
                               _sonar_head_or_transceiver_status);
        printer.register_string("mode", fmt::format("0b{:08b}", _mode), "encoded");
        printer.register_string(
            "filter_identifier", fmt::format("0b{:08b}", _filter_identifier), "encoded");
        printer.register_value("minimum_depth", _minimum_depth, "m");
        printer.register_value("maximum_depth", _maximum_depth, "m");
        printer.register_value("absorption_coefficient", _absorption_coefficient, "0.01 db/km");
        printer.register_value("transmit_pulse_length", _transmit_pulse_length, "μs");
        printer.register_value("transmit_beamwidth", _transmit_beamwidth, "0.1°");
        printer.register_value(
            "transmit_power_relative_maximum", _transmit_power_relative_maximum, "dB");
        printer.register_value("receive_bandwidth_degree", _receive_beamwidth_degree, "0.1°");
        printer.register_value("receive_bandwidth_50hz", _receive_bandwidth_50hz, "50Hz");
        printer.register_string("mode2_or_receiver_fixed_gain_setting",
                                fmt::format("0b{:08b}", _mode2_or_receiver_fixed_gain_setting),
                                "encoded");
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
        printer.register_string(
            "filter_identifier2", fmt::format("0b{:08b}", _filter_identifier2), "encoded");
        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        printer.register_section("processed");
        printer.register_value("absorption_coefficient_in_db_per_meter",
                               get_absorption_coefficient_in_db_per_meter(),
                               "db/m");
        printer.register_value(
            "transmit_pulse_length_in_seconds", get_transmit_pulse_length_in_seconds(), "s");
        printer.register_value(
            "transmit_beamwidth_in_degrees", get_transmit_beamwidth_in_degrees(), "°");
        printer.register_value(
            "receive_bandwidth_in_degrees", get_receive_beamwidth_in_degrees(), "°");
        printer.register_value(
            "receive_bandwidth_in_hertz", get_receive_bandwidth_in_hertz(), "Hz");
        printer.register_value(
            "transmit_along_tilt_in_degrees", get_transmit_along_tilt_in_degrees(), "°");

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

/**
 * @brief Provide a boost hash function for RuntimeParameters
 * - Note: this is needed to use RuntimeParameters as boost::flyweight
 * - IMPORTANT: this hash function only uses the content of the RuntimeParameters for hashing
 * (not information from header e.g. timestamp, ping counter etc.)
 *
 * @param data
 * @return std::size_t
 */
// IGNORE_DOC: __doc_themachinethatgoesping_echosounders_pingtools_hash_value
inline size_t hash_value(const RuntimeParameters& data)
{
    // return data.hash_content_only();
    return data.binary_hash();
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
