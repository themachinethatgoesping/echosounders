// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
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
     *                          is not handled for the specific system. Otherwise: None is returned
     * @return A string representing Ping mode as encoded by 'mode'
     */
    std::optional<std::string> get_mode_as_ping_mode(
        std::optional<std::string> unhandled_message = std::nullopt) const
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
                        return unhandled_message;
                }
            case 3002:
                switch (_mode & 0b00001111)
                {
                    case 0b00000000:
                        return "Wide Tx beamwidth (4°)";
                    case 0b00000001:
                        return "Normal Tx beamwidth (1.5°)";
                    default:
                        return unhandled_message;
                }
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
                        return unhandled_message;
                }
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
                        return unhandled_message;
                }
            case 2045: // EM2040C, we decode the 'Frequency' as PingMode here, since this was also
                       // the choice for the EM2040
            {
                uint_fast16_t frequency = (_mode & 0b00011111) * 10 + 180;
                return fmt::format("{} kHz", frequency);
            }
            default:
                return unhandled_message;
        }
    }

    /**
     * @brief Retrieves Tx pulse form encoded in the mode variable
     *
     * The decoding is EM model specific. See datagram format specification for details.
     *
     * @param unhandled_message If provided, this message is used as the return value if the mode
     *                          is not handled for the specific system. Otherwise: None is returned.
     * @return A string representing Tx pulse form as encoded by 'mode'
     */
    std::optional<std::string> get_mode_as_tx_pulse_form(
        std::optional<std::string> unhandled_message = std::nullopt) const
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
                        return unhandled_message;
                }
            case 2045: // EM2040C
            {
                switch (_mode & 0b00100000)
                {
                    case 0b00000000:
                        return "CW";
                    case 0b00100000:
                        return "FM";
                    default:
                        return unhandled_message;
                }
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
                return unhandled_message;
        }
    }

    /**
     * @brief Retrieves Dual swath mode encoded in the mode variable
     *
     * The decoding is EM model specific. See datagram format specification for details.
     *
     * @param unhandled_message If provided, this message is used as the return value if the mode
     *                          is not handled for the specific system. Otherwise: None is returned
     * @return A string representing Tx pulse form as encoded by 'mode'
     */
    std::optional<std::string> get_mode_as_dual_swath_mode(
        std::optional<std::string> unhandled_message = std::nullopt) const
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
                        return unhandled_message;
                }
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
                return unhandled_message;
        }
    }

    /**
     * @brief Retrieves Rx array/ sonar head encoded in the mode2 variable
     *
     * The decoding is EM model specific. Currently only outputs sensefull values for EM2040 and
     * EM2040C. See datagram format specification for details.
     *
     * @param unhandled_message If provided, this message is used as the return value if the mode
     *                          is not handled for the specific system. Otherwise: 'None' is
     *                          returned
     * @return A string representing Rx array / Sonar head use as encoded by 'mode2'
     */
    std::optional<std::string> get_mode2_as_rx_or_sonar_head_use(
        std::optional<std::string> unhandled_message = std::nullopt) const
    {
        switch (get_model_number())
        {
            case 2040:
                switch (_mode2_or_receiver_fixed_gain_setting & 0b00000011)
                {
                    case 0b00000000:
                        return "Off (RX inactive)";
                    case 0b00000001:
                        return "RX 1 (port) active";
                    case 0b00000010:
                        return "RX 2 (starboard) active";
                    case 0b00000011:
                        return "Both RX units active";
                }
                throw std::runtime_error(
                    fmt::format("{} reached unreachable state. Please report", __func__));
            case 2045:
                switch (_mode2_or_receiver_fixed_gain_setting & 0b00000011)
                {
                    case 0b00000000:
                        return "Off ((Both inactive)";
                    case 0b00000001:
                        return "SH 1 (port) active";
                    case 0b00000010:
                        return "SH 2 (starboard) active";
                    case 0b00000011:
                        return "Both active";
                }
                throw std::runtime_error(
                    fmt::format("{} reached unreachable state. Please report", __func__));
            default:
                return unhandled_message;
        }
    }

    /**
     * @brief Retrieves beamspacing mode encoded in the beamspacing variable
     *
     * The decoding is EM model specific. Currently only outputs sensefull values for EM2040 and
     * EM2040C. See datagram format specification for details.
     *
     * @param unhandled_message If provided, this message is used as the return value if the mode
     *                          is not handled for the specific system. Otherwise: 'None' is
     *                          returned
     * @return A string representing beamspacing as encoded by 'beamspacing'
     */
    std::optional<std::string> get_beam_spacing_as_string(
        std::optional<std::string> unhandled_message = std::nullopt) const
    {
        if (get_model_number() == 3002)
            throw std::runtime_error(fmt::format(
                "{} function not implemented correctly for model 3002. Please report!", __func__));
        if (get_model_number() == 3000)
            throw std::runtime_error(fmt::format(
                "{} function not implemented correctly for model 3000. Please report!", __func__));

        switch (_beam_spacing)
        {
            case 0b00000000:
                return "Determined by beamwidth";
            case 0b00000001:
                if (get_model_number() == 122 || get_model_number() == 302)
                    return "Inbetween";
                return "Equidistant";
            case 0b00000010:
                return "Equiangle";
            case 0b00000011:
                if (get_model_number() == 2000 || get_model_number() == 120 ||
                    get_model_number() == 300 || get_model_number() == 1002)
                    return "In between";
                return "High density equidistant";
        }

        return unhandled_message;
    }

    /**
     * @brief Retrieves yaw and pitch stabilization mode encoded in the
     * yaw_and_pitch_stabilization_mode variable
     *
     * @return A string representing yaw_and_pitch_stabilization_mode as encoded by
     * 'yaw_and_pitch_stabilization_mode'
     */
    std::string get_yaw_and_pitch_stabilization_mode_as_yaw_stabilization() const
    {
        switch (_yaw_and_pitch_stabilization_mode & 0b00000011)
        {
            case 0b00000000:
                return "No yaw stabilization";
            case 0b00000001:
                return "Yaw stabilization to survey line heading (Not used)";
            case 0b00000010:
                return "Yaw stabilization to mean vessel heading";
            case 0b00000011:
                return "Yaw stabilization to manually entered heading";
        }
        throw std::runtime_error(
            fmt::format("{} reached unreachable state. Please report", __func__));
    }

    /**
     * @brief Retrieves heading filter mode encoded in the yaw_and_pitch_stabilization_mode
     * variable
     *
     * @param unhandled_message If provided, this message is used as the return value if the mode
     *                          is not handled by the function. Otherwise: 'None' is returned
     * @return A string representing heading filter mode as encoded by
     * 'yaw_and_pitch_stabilization_mode'
     */
    std::optional<std::string> get_yaw_and_pitch_stabilization_mode_as_heading_filter(
        std::optional<std::string> unhandled_message = std::nullopt) const
    {
        switch (_yaw_and_pitch_stabilization_mode & 0b00001100)
        {
            case 0b00000000:
                return "Heading filter, hard";
            case 0b00000001:
                return "Heading filter, medium";
            case 0b00000010:
                return "Heading filter, weak";
            default:
                return unhandled_message;
        }
    }

    /**
     * @brief Retrieves pitch stabilization mode (on/off) encoded in the
     * yaw_and_pitch_stabilization_mode variable
     *
     * @return A string representing pitch stabilization mode as encoded by
     * 'yaw_and_pitch_stabilization_mode'
     */
    std::string get_yaw_and_pitch_stabilization_mode_as_pitch_stibilization() const
    {
        if (_yaw_and_pitch_stabilization_mode & 0b10000000)
            return "On";

        return "Off";
    }

    /**
     * @brief Retrieves Pulselength encoded in the mode2 variable
     *
     * The decoding is EM model specific. Currently only outputs sensefull values for EM2040 and
     * EM2040C. See datagram format specification for details.
     *
     * @param unhandled_message If provided, this message is used as the return value if the mode
     *                          is not handled for the specific system. Otherwise: 'Sonar head
     * use unhandled' is returned
     * @return A string representing Pulselength as encoded by 'mode2'
     */
    std::optional<std::string> get_mode2_as_pulselength(
        std::optional<std::string> unhandled_message = std::nullopt) const
    {
        switch (get_model_number())
        {
            case 2040:
                switch (_mode2_or_receiver_fixed_gain_setting & 0b00001100)
                {
                    case 0b00000000:
                        return "Short CW";
                    case 0b00000100:
                        return "Medium CW";
                    case 0b00001000:
                        return "Long CW";
                    case 0b00001100:
                        return "FM";
                }
                throw std::runtime_error(
                    fmt::format("{} reached unreachable state. Please report", __func__));
            case 2045:
                switch (_mode2_or_receiver_fixed_gain_setting & 0b01110000)
                {
                    case 0b00000000:
                        return "Very Short CW";
                    case 0b00010000:
                        return "Short CW";
                    case 0b00100000:
                        return "Medium CW";
                    case 0b00110000:
                        return "Long CW";
                    case 0b01000000:
                        return "Very Long CW";
                    case 0b01010000:
                        return "Extra Long CW";
                    case 0b01100000:
                        return "Short FM";
                    case 0b01110000:
                        return "Long FM";
                }
                throw std::runtime_error(
                    fmt::format("{} reached unreachable state. Please report", __func__));
            default:
                return unhandled_message;
        }
    }

    /**
     * @brief Retrieves receiver fixed gain setting encoded in the mode2 variable
     *
     * The decoding is EM model specific. This only outputs sensefull values for EM2000,
     * EM1002, EM3000, EM3002, EM300, EM120. See datagram format specification for details.
     *
     * @param unhandled_value If provided, this value is used as the return value if the mode
     *                          is not handled for the specific system. Otherwise: 'None' is
     * returned
     * @return A uint8_t representing receiver fixed gain setting use as encoded by 'mode2'
     */
    std::optional<uint8_t> get_mode2_as_receive_fixed_gain_setting_dB(
        std::optional<std::uint8_t> unhandled_value = std::nullopt) const
    {
        switch (get_model_number())
        {
            case 2000:
                [[fallthrough]];
            case 1002:
                [[fallthrough]];
            case 3000:
                [[fallthrough]];
            case 3002:
                [[fallthrough]];
            case 300:
                [[fallthrough]];
            case 120:
                return _mode2_or_receiver_fixed_gain_setting;
            default:
                return unhandled_value;
        }
    }

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
     *                          gates size is not handled by the function. Otherwise: 'None' is
     * returned
     * @return A string representing Range gates size as encoded by 'mode'
     */
    std::optional<std::string> get_filter_identifier_as_range_gates_size(
        std::optional<std::string> unhandled_message = std::nullopt) const
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
                return unhandled_message;
        }
    }

    /**
     * @brief Retrieves the Aearation filter status encoded in the filter_identifier variable
     *
     * @return A string representing the Aeration filter status (On or Off) as encoded by
     * 'filter_identifier'
     */
    std::string get_filter_identifier_as_aeration_filter() const
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
    std::string get_filter_identifier_as_interference_filter() const
    {
        if (_filter_identifier & 0b01000000)
            return "On";

        return "Off";
    }

    // filter_identifier2
    /**
     * @brief Retrieves penetration filter setup encoded in the filter_identifier2 variable
     *
     * @return A string representing the penetration filter setup as encoded by 'filter_identifier2'
     */
    std::string get_filter_identifier2_as_penetration_filter() const
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
     * @brief Retrieves detect mode encoded in the filter_identifier2 variable
     *
     * @return A string representing the detect mode as encoded by 'filter_identifier2'
     */
    std::string get_filter_identifier2_as_detect_mode() const
    {
        switch (_filter_identifier & 0b00001100)
        {
            case 0b00000000:
                return "Normal";
            case 0b00000100:
                return "Waterway";
            case 0b00001000:
                return "Tracking";
            case 0b00001100:
                return "Minimum depth";
            default:
                throw std::runtime_error(
                    fmt::format("{} reached unreachable state. Please report", __func__));
        }
    }

    /**
     * @brief Retrieves phase ramp encoded in the filter_identifier2 variable
     *
     * @param unhandled_message If provided, this message is used as the return value if the value
     *                          is not handled by the function. Otherwise: 'None' is returned
     *
     * @return A string representing the phase ramp encoded by 'filter_identifier2'
     */
    std::optional<std::string> get_filter_identifier2_as_phase_ramp(
        std::optional<std::string> unhandled_message = std::nullopt) const
    {
        switch (_filter_identifier & 0b00110000)
        {
            case 0b00000000:
                return "Short phase ramp";
            case 0b00010000:
                return "Normal phase ramp";
            case 0b00100000:
                return "Long phase ramp";
            default:
                return unhandled_message;
        }
    }

    /**
     * @brief Retrieves the Special TVG mode encoded in the filter_identifier2 variable
     *
     * @return A string representing the Special TVG mode (Normal/Special) as encoded by
     * 'filter_identifier2'
     */
    std::string get_filter_identifier2_as_special_tvg() const
    {
        if (_filter_identifier & 0b01000000)
            return "Normal TVG";

        return "Special TVG";
    }

    /**
     * @brief Retrieves the Special amp detect mode encoded in the filter_identifier2 variable
     *
     * EM3002 soft sediment detection = special amp detect
     *
     * @return A string representing the Special amp detect mode (Normal/Special) as encoded by
     * 'filter_identifier2'
     */
    std::string get_filter_identifier2_as_special_amp_detect() const
    {
        if (_filter_identifier & 0b10000000)
            return "Normal amp detect";

        return "Special amp detect";
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
    std::optional<std::string> get_source_of_sound_speed_at_transducer_as_string(
        std::optional<std::string> unhandled_message = std::nullopt) const
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
                return unhandled_message;
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

    // ----- operators -----
    bool operator==(const RuntimeParameters& other) const = default;

    //----- to/from stream functions -----
    /**
     * @brief Create a RuntimeParameters object from a stream
     * 
     * @param is Input stream to read from
     * @param header KongsbergAllDatagram header that was already read from the stream
     * @return RuntimeParameters object created from stream
     */
    static RuntimeParameters from_stream(std::istream& is, KongsbergAllDatagram header);

    /**
     * @brief Create a RuntimeParameters object from a stream
     * 
     * @param is Input stream to read from
     * @return RuntimeParameters object created from stream
     */
    static RuntimeParameters from_stream(std::istream& is);

    /**
     * @brief Create a RuntimeParameters object from a stream with datagram identifier
     * 
     * @param is Input stream to read from
     * @param datagram_identifier Expected datagram identifier
     * @return RuntimeParameters object created from stream
     */
    static RuntimeParameters from_stream(std::istream&                    is,
                                         t_KongsbergAllDatagramIdentifier datagram_identifier);

    /**
     * @brief Write the RuntimeParameters object to a stream
     * 
     * @param os Output stream to write to
     */
    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    /**
     * @brief Create ObjectPrinter for this RuntimeParameters object
     * 
     * @param float_precision Precision for floating point values
     * @param superscript_exponents Whether to use superscript notation for exponents
     * @return ObjectPrinter configured for this RuntimeParameters
     */
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

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
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_pingtools_hash_value
inline size_t hash_value(const RuntimeParameters& data)
{
    // return data.hash_content_only();
    return data.binary_hash();
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
