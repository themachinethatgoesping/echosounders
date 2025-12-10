// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/runtimeparameters.doc.hpp"

// std includes
#include <cstdint>
#include <iosfwd>
#include <optional>
#include <string>

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
    explicit RuntimeParameters(const KongsbergAllDatagram& header);

  public:
    // ----- public constructors -----
    RuntimeParameters();
    ~RuntimeParameters() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_ping_counter() const;
    uint16_t get_system_serial_number() const;
    uint8_t  get_operator_station_status() const;
    uint8_t  get_processing_unit_status() const;
    uint8_t  get_bsp_status() const;
    uint8_t  get_sonar_head_or_transceiver_status() const;
    uint8_t  get_mode() const;
    uint8_t  get_filter_identifier() const;
    uint16_t get_minimum_depth() const;
    uint16_t get_maximum_depth() const;
    uint16_t get_absorption_coefficient() const;
    uint16_t get_transmit_pulse_length() const;
    uint16_t get_transmit_beamwidth() const;
    int8_t   get_transmit_power_relative_maximum() const;
    uint8_t  get_receive_beamwidth_degree() const;
    uint8_t  get_receive_bandwidth_50hz() const;
    uint8_t  get_mode2_or_receiver_fixed_gain_setting() const;
    uint8_t  get_tvg_law_crossover_angle() const;
    uint8_t  get_source_of_sound_speed_at_transducer() const;
    uint16_t get_maximum_port_swath_width() const;
    uint8_t  get_beam_spacing() const;
    uint8_t  get_maximum_port_coverage() const;
    uint8_t  get_yaw_and_pitch_stabilization_mode() const;
    uint8_t  get_maximum_starboard_coverage() const;
    uint16_t get_maximum_starboard_swath_width() const;
    int16_t  get_transmit_along_tilt() const;
    uint8_t  get_filter_identifier2() const;
    uint8_t  get_etx() const;
    uint16_t get_checksum() const;

    // setters
    void set_ping_counter(uint16_t ping_counter);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_operator_station_status(uint8_t operator_station_status);
    void set_processing_unit_status(uint8_t processing_unit_status);
    void set_bsp_status(uint8_t bsp_status);
    void set_sonar_head_or_transceiver_status(uint8_t sonar_head_or_transceiver_status);
    void set_mode(uint8_t mode);
    void set_filter_identifier(uint8_t filter_identifier);
    void set_minimum_depth(uint16_t minimum_depth);
    void set_maximum_depth(uint16_t maximum_depth);
    void set_absorption_coefficient(uint16_t absorption_coefficient);
    void set_transmit_pulse_length(uint16_t transmit_pulse_length);
    void set_transmit_beamwidth(uint16_t transmit_beamwidth);
    void set_transmit_power_relative_maximum(int8_t transmit_power_relative_maximum);
    void set_receive_beamwidth_degree(uint8_t receive_bandwidth_degree);
    void set_receive_bandwidth_50hz(uint8_t receive_bandwidth_50hz);
    void set_mode2_or_receiver_fixed_gain_setting(uint8_t mode2_or_receiver_fixed_gain_setting);
    void set_tvg_law_crossover_angle(uint8_t tvg_law_crossover_angle);
    void set_source_of_sound_speed_at_transducer(uint8_t source);
    void set_maximum_port_swath_width(uint16_t maximum_port_swath_width);
    void set_beam_spacing(uint8_t beam_spacing);
    void set_maximum_port_coverage(uint8_t maximum_port_coverage);
    void set_yaw_and_pitch_stabilization_mode(uint8_t yaw_and_pitch_stabilization_mode);
    void set_maximum_starboard_coverage(uint8_t maximum_starboard_coverage);
    void set_maximum_starboard_swath_width(uint16_t maximum_starboard_swath_width);
    void set_transmit_along_tilt(int16_t transmit_along_tilt);
    void set_filter_identifier2(uint8_t filter_identifier2);
    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);

    // ----- processed data access -----

    /**
     * @brief Get the absorption coefficient in db per meter
     *
     * @return _absorption_coefficient * 0.00001f (float)
     */
    float get_absorption_coefficient_in_db_per_meter() const;

    /**
     * @brief Get the transmit pulse length in seconds
     *
     * @return _transmit_pulse_length * 0.000001f (float)
     */
    float get_transmit_pulse_length_in_seconds() const;

    /**
     * @brief Get the transmit beamwidth in degrees
     *
     * @return _transmit_beamwidth * 0.1f (float)
     */
    float get_transmit_beamwidth_in_degrees() const;

    /**
     * @brief Get the receive beamwidth in degrees
     *
     * @return _receive_beamwidth_degree * 0.1f (float)
     */
    float get_receive_beamwidth_in_degrees() const;

    /**
     * @brief Get the receive bandwidth in Hz
     *
     * @return _receive_bandwidth_50hz * 50.f (float)
     */
    float get_receive_bandwidth_in_hertz() const;

    /**
     * @brief Get the transmit along tilt in degrees
     *
     * @return _transmit_along_tilt * 0.1f (float)
     */
    float get_transmit_along_tilt_in_degrees() const;

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
        std::optional<std::string> unhandled_message = std::nullopt) const;

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
        std::optional<std::string> unhandled_message = std::nullopt) const;

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
        std::optional<std::string> unhandled_message = std::nullopt) const;

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
        std::optional<std::string> unhandled_message = std::nullopt) const;

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
        std::optional<std::string> unhandled_message = std::nullopt) const;

    /**
     * @brief Retrieves yaw and pitch stabilization mode encoded in the
     * yaw_and_pitch_stabilization_mode variable
     *
     * @return A string representing yaw_and_pitch_stabilization_mode as encoded by
     * 'yaw_and_pitch_stabilization_mode'
     */
    std::string get_yaw_and_pitch_stabilization_mode_as_yaw_stabilization() const;

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
        std::optional<std::string> unhandled_message = std::nullopt) const;

    /**
     * @brief Retrieves pitch stabilization mode (on/off) encoded in the
     * yaw_and_pitch_stabilization_mode variable
     *
     * @return A string representing pitch stabilization mode as encoded by
     * 'yaw_and_pitch_stabilization_mode'
     */
    std::string get_yaw_and_pitch_stabilization_mode_as_pitch_stibilization() const;

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
        std::optional<std::string> unhandled_message = std::nullopt) const;

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
        std::optional<std::uint8_t> unhandled_value = std::nullopt) const;

    /**
     * @brief Retrieves spike filter setup encoded in the filter_identifier variable
     *
     * @return A string representing the spike filter setup as encoded by 'filter_identifier'
     */
    std::string get_filter_identifier_as_spike_filter() const;

    /**
     * @brief Retrieves slope filter status encoded in the filter_identifier variable
     *
     * @return A string representing the slope filter status (On or Off) as encoded by
     * 'filter_identifier'
     */
    std::string get_filter_identifier_as_slope_filter() const;

    /**
     * @brief Retrieves Range gates size encoded in the mode variable
     *
     * @param unhandled_message If provided, this message is used as the return value if the range
     *                          gates size is not handled by the function. Otherwise: 'None' is
     * returned
     * @return A string representing Range gates size as encoded by 'mode'
     */
    std::optional<std::string> get_filter_identifier_as_range_gates_size(
        std::optional<std::string> unhandled_message = std::nullopt) const;

    /**
     * @brief Retrieves the Aearation filter status encoded in the filter_identifier variable
     *
     * @return A string representing the Aeration filter status (On or Off) as encoded by
     * 'filter_identifier'
     */
    std::string get_filter_identifier_as_aeration_filter() const;

    /**
     * @brief Retrieves the Interference filter status encoded in the filter_identifier variable
     *
     * @return A string representing the Interference filter status (On or Off) as encoded by
     * 'filter_identifier'
     */
    std::string get_filter_identifier_as_interference_filter() const;

    // filter_identifier2
    /**
     * @brief Retrieves penetration filter setup encoded in the filter_identifier2 variable
     *
     * @return A string representing the penetration filter setup as encoded by 'filter_identifier2'
     */
    std::string get_filter_identifier2_as_penetration_filter() const;

    /**
     * @brief Retrieves detect mode encoded in the filter_identifier2 variable
     *
     * @return A string representing the detect mode as encoded by 'filter_identifier2'
     */
    std::string get_filter_identifier2_as_detect_mode() const;

    /**
     * @brief Retrieves phase ramp encoded in the filter_identifier2 variable
     *
     * @param unhandled_message If provided, this message is used as the return value if the value
     *                          is not handled by the function. Otherwise: 'None' is returned
     *
     * @return A string representing the phase ramp encoded by 'filter_identifier2'
     */
    std::optional<std::string> get_filter_identifier2_as_phase_ramp(
        std::optional<std::string> unhandled_message = std::nullopt) const;

    /**
     * @brief Retrieves the Special TVG mode encoded in the filter_identifier2 variable
     *
     * @return A string representing the Special TVG mode (Normal/Special) as encoded by
     * 'filter_identifier2'
     */
    std::string get_filter_identifier2_as_special_tvg() const;

    /**
     * @brief Retrieves the Special amp detect mode encoded in the filter_identifier2 variable
     *
     * EM3002 soft sediment detection = special amp detect
     *
     * @return A string representing the Special amp detect mode (Normal/Special) as encoded by
     * 'filter_identifier2'
     */
    std::string get_filter_identifier2_as_special_amp_detect() const;

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
        std::optional<std::string> unhandled_message = std::nullopt) const;

    /**
     * @brief Retrieves the Extra detections option (On/Off) encoded in the
     * 'source of sound speed at transducer' variable
     *
     * @return True if the Extra detections option is enabled, false otherwise
     */
    bool get_extra_detections_enabled() const;

    /**
     * @brief Retrieves the Sonar mode option (On/Off) encoded in the
     * 'source of sound speed at transducer' variable
     *
     * @return True if the Sonar mode option is enabled, false otherwise
     */
    bool get_sonar_mode_enabled() const;

    /**
     * @brief Retrieves the Passive mode option (On/Off) encoded in the
     * 'source of sound speed at transducer' variable
     *
     * @return True if the Passive mode option is enabled, false otherwise
     */
    bool get_passive_mode_enabled() const;

    /**
     * @brief Retrieves the 3D scanning option (On/Off) encoded in the
     * 'source of sound speed at transducer' variable
     *
     * @return True if the 3D scanning option is enabled, false otherwise
     */
    bool get_3d_scanning_enabled() const;

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

    xxh::hash_t<64> hash_content_only() const;

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
// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_pingtools_hash_value
size_t hash_value(const RuntimeParameters& data);

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
