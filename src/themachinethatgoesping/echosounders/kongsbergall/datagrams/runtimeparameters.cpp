// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "runtimeparameters.hpp"

// std includes
#include <stdexcept>
#include <utility>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

RuntimeParameters::RuntimeParameters(const KongsbergAllDatagram& header)
    : KongsbergAllDatagram(header)
{
}

RuntimeParameters::RuntimeParameters()
{
    _datagram_identifier = t_KongsbergAllDatagramIdentifier::RuntimeParameters;
}

uint16_t RuntimeParameters::get_ping_counter() const
{
    return _ping_counter;
}

uint16_t RuntimeParameters::get_system_serial_number() const
{
    return _system_serial_number;
}

uint8_t RuntimeParameters::get_operator_station_status() const
{
    return _operator_station_status;
}

uint8_t RuntimeParameters::get_processing_unit_status() const
{
    return _processing_unit_status;
}

uint8_t RuntimeParameters::get_bsp_status() const
{
    return _bsp_status;
}

uint8_t RuntimeParameters::get_sonar_head_or_transceiver_status() const
{
    return _sonar_head_or_transceiver_status;
}

uint8_t RuntimeParameters::get_mode() const
{
    return _mode;
}

uint8_t RuntimeParameters::get_filter_identifier() const
{
    return _filter_identifier;
}

uint16_t RuntimeParameters::get_minimum_depth() const
{
    return _minimum_depth;
}

uint16_t RuntimeParameters::get_maximum_depth() const
{
    return _maximum_depth;
}

uint16_t RuntimeParameters::get_absorption_coefficient() const
{
    return _absorption_coefficient;
}

uint16_t RuntimeParameters::get_transmit_pulse_length() const
{
    return _transmit_pulse_length;
}

uint16_t RuntimeParameters::get_transmit_beamwidth() const
{
    return _transmit_beamwidth;
}

int8_t RuntimeParameters::get_transmit_power_relative_maximum() const
{
    return _transmit_power_relative_maximum;
}

uint8_t RuntimeParameters::get_receive_beamwidth_degree() const
{
    return _receive_beamwidth_degree;
}

uint8_t RuntimeParameters::get_receive_bandwidth_50hz() const
{
    return _receive_bandwidth_50hz;
}

uint8_t RuntimeParameters::get_mode2_or_receiver_fixed_gain_setting() const
{
    return _mode2_or_receiver_fixed_gain_setting;
}

uint8_t RuntimeParameters::get_tvg_law_crossover_angle() const
{
    return _tvg_law_crossover_angle;
}

uint8_t RuntimeParameters::get_source_of_sound_speed_at_transducer() const
{
    return _source_of_sound_speed_at_transducer;
}

uint16_t RuntimeParameters::get_maximum_port_swath_width() const
{
    return _maximum_port_swath_width;
}

uint8_t RuntimeParameters::get_beam_spacing() const
{
    return _beam_spacing;
}

uint8_t RuntimeParameters::get_maximum_port_coverage() const
{
    return _maximum_port_coverage;
}

uint8_t RuntimeParameters::get_yaw_and_pitch_stabilization_mode() const
{
    return _yaw_and_pitch_stabilization_mode;
}

uint8_t RuntimeParameters::get_maximum_starboard_coverage() const
{
    return _maximum_starboard_coverage;
}

uint16_t RuntimeParameters::get_maximum_starboard_swath_width() const
{
    return _maximum_starboard_swath_width;
}

int16_t RuntimeParameters::get_transmit_along_tilt() const
{
    return _transmit_along_tilt;
}

uint8_t RuntimeParameters::get_filter_identifier2() const
{
    return _filter_identifier2;
}

uint8_t RuntimeParameters::get_etx() const
{
    return _etx;
}

uint16_t RuntimeParameters::get_checksum() const
{
    return _checksum;
}

void RuntimeParameters::set_ping_counter(uint16_t ping_counter)
{
    _ping_counter = ping_counter;
}

void RuntimeParameters::set_system_serial_number(uint16_t system_serial_number)
{
    _system_serial_number = system_serial_number;
}

void RuntimeParameters::set_operator_station_status(uint8_t operator_station_status)
{
    _operator_station_status = operator_station_status;
}

void RuntimeParameters::set_processing_unit_status(uint8_t processing_unit_status)
{
    _processing_unit_status = processing_unit_status;
}

void RuntimeParameters::set_bsp_status(uint8_t bsp_status)
{
    _bsp_status = bsp_status;
}

void RuntimeParameters::set_sonar_head_or_transceiver_status(
    uint8_t sonar_head_or_transceiver_status)
{
    _sonar_head_or_transceiver_status = sonar_head_or_transceiver_status;
}

void RuntimeParameters::set_mode(uint8_t mode)
{
    _mode = mode;
}

void RuntimeParameters::set_filter_identifier(uint8_t filter_identifier)
{
    _filter_identifier = filter_identifier;
}

void RuntimeParameters::set_minimum_depth(uint16_t minimum_depth)
{
    _minimum_depth = minimum_depth;
}

void RuntimeParameters::set_maximum_depth(uint16_t maximum_depth)
{
    _maximum_depth = maximum_depth;
}

void RuntimeParameters::set_absorption_coefficient(uint16_t absorption_coefficient)
{
    _absorption_coefficient = absorption_coefficient;
}

void RuntimeParameters::set_transmit_pulse_length(uint16_t transmit_pulse_length)
{
    _transmit_pulse_length = transmit_pulse_length;
}

void RuntimeParameters::set_transmit_beamwidth(uint16_t transmit_beamwidth)
{
    _transmit_beamwidth = transmit_beamwidth;
}

void RuntimeParameters::set_transmit_power_relative_maximum(int8_t transmit_power_relative_maximum)
{
    _transmit_power_relative_maximum = transmit_power_relative_maximum;
}

void RuntimeParameters::set_receive_beamwidth_degree(uint8_t receive_bandwidth_degree)
{
    _receive_beamwidth_degree = receive_bandwidth_degree;
}

void RuntimeParameters::set_receive_bandwidth_50hz(uint8_t receive_bandwidth_50hz)
{
    _receive_bandwidth_50hz = receive_bandwidth_50hz;
}

void RuntimeParameters::set_mode2_or_receiver_fixed_gain_setting(
    uint8_t mode2_or_receiver_fixed_gain_setting)
{
    _mode2_or_receiver_fixed_gain_setting = mode2_or_receiver_fixed_gain_setting;
}

void RuntimeParameters::set_tvg_law_crossover_angle(uint8_t tvg_law_crossover_angle)
{
    _tvg_law_crossover_angle = tvg_law_crossover_angle;
}

void RuntimeParameters::set_source_of_sound_speed_at_transducer(uint8_t source)
{
    _source_of_sound_speed_at_transducer = source;
}

void RuntimeParameters::set_maximum_port_swath_width(uint16_t maximum_port_swath_width)
{
    _maximum_port_swath_width = maximum_port_swath_width;
}

void RuntimeParameters::set_beam_spacing(uint8_t beam_spacing)
{
    _beam_spacing = beam_spacing;
}

void RuntimeParameters::set_maximum_port_coverage(uint8_t maximum_port_coverage)
{
    _maximum_port_coverage = maximum_port_coverage;
}

void RuntimeParameters::set_yaw_and_pitch_stabilization_mode(
    uint8_t yaw_and_pitch_stabilization_mode)
{
    _yaw_and_pitch_stabilization_mode = yaw_and_pitch_stabilization_mode;
}

void RuntimeParameters::set_maximum_starboard_coverage(uint8_t maximum_starboard_coverage)
{
    _maximum_starboard_coverage = maximum_starboard_coverage;
}

void RuntimeParameters::set_maximum_starboard_swath_width(uint16_t maximum_starboard_swath_width)
{
    _maximum_starboard_swath_width = maximum_starboard_swath_width;
}

void RuntimeParameters::set_transmit_along_tilt(int16_t transmit_along_tilt)
{
    _transmit_along_tilt = transmit_along_tilt;
}

void RuntimeParameters::set_filter_identifier2(uint8_t filter_identifier2)
{
    _filter_identifier2 = filter_identifier2;
}

void RuntimeParameters::set_etx(uint8_t etx)
{
    _etx = etx;
}

void RuntimeParameters::set_checksum(uint16_t checksum)
{
    _checksum = checksum;
}

float RuntimeParameters::get_absorption_coefficient_in_db_per_meter() const
{
    return _absorption_coefficient * 0.00001f;
}

float RuntimeParameters::get_transmit_pulse_length_in_seconds() const
{
    return _transmit_pulse_length * 0.000001f;
}

float RuntimeParameters::get_transmit_beamwidth_in_degrees() const
{
    return _transmit_beamwidth * 0.1f;
}

float RuntimeParameters::get_receive_beamwidth_in_degrees() const
{
    return _receive_beamwidth_degree * 0.1f;
}

float RuntimeParameters::get_receive_bandwidth_in_hertz() const
{
    return _receive_bandwidth_50hz * 50.f;
}

float RuntimeParameters::get_transmit_along_tilt_in_degrees() const
{
    return _transmit_along_tilt * 0.1f;
}

std::optional<std::string> RuntimeParameters::get_mode_as_ping_mode(
    std::optional<std::string> unhandled_message) const
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
        case 2045:
        {
            uint_fast16_t frequency = (_mode & 0b00011111) * 10 + 180;
            return fmt::format("{} kHz", frequency);
        }
        default:
            return unhandled_message;
    }
}

std::optional<std::string> RuntimeParameters::get_mode_as_tx_pulse_form(
    std::optional<std::string> unhandled_message) const
{
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
        case 2045:
            switch (_mode & 0b00100000)
            {
                case 0b00000000:
                    return "CW";
                case 0b00100000:
                    return "FM";
                default:
                    return unhandled_message;
            }
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

std::optional<std::string> RuntimeParameters::get_mode_as_dual_swath_mode(
    std::optional<std::string> unhandled_message) const
{
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

std::optional<std::string> RuntimeParameters::get_mode2_as_rx_or_sonar_head_use(
    std::optional<std::string> unhandled_message) const
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

std::optional<std::string> RuntimeParameters::get_beam_spacing_as_string(
    std::optional<std::string> unhandled_message) const
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

std::string RuntimeParameters::get_yaw_and_pitch_stabilization_mode_as_yaw_stabilization() const
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

std::optional<std::string> RuntimeParameters::get_yaw_and_pitch_stabilization_mode_as_heading_filter(
    std::optional<std::string> unhandled_message) const
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

std::string RuntimeParameters::get_yaw_and_pitch_stabilization_mode_as_pitch_stibilization() const
{
    if (_yaw_and_pitch_stabilization_mode & 0b10000000)
        return "On";

    return "Off";
}

std::optional<std::string> RuntimeParameters::get_mode2_as_pulselength(
    std::optional<std::string> unhandled_message) const
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

std::optional<uint8_t> RuntimeParameters::get_mode2_as_receive_fixed_gain_setting_dB(
    std::optional<std::uint8_t> unhandled_value) const
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

std::string RuntimeParameters::get_filter_identifier_as_spike_filter() const
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

std::string RuntimeParameters::get_filter_identifier_as_slope_filter() const
{
    if (_filter_identifier & 0b00000100)
        return "On";

    return "Off";
}

std::optional<std::string> RuntimeParameters::get_filter_identifier_as_range_gates_size(
    std::optional<std::string> unhandled_message) const
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

std::string RuntimeParameters::get_filter_identifier_as_aeration_filter() const
{
    if (_filter_identifier & 0b00100000)
        return "On";

    return "Off";
}

std::string RuntimeParameters::get_filter_identifier_as_interference_filter() const
{
    if (_filter_identifier & 0b01000000)
        return "On";

    return "Off";
}

std::string RuntimeParameters::get_filter_identifier2_as_penetration_filter() const
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

std::string RuntimeParameters::get_filter_identifier2_as_detect_mode() const
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

std::optional<std::string> RuntimeParameters::get_filter_identifier2_as_phase_ramp(
    std::optional<std::string> unhandled_message) const
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

std::string RuntimeParameters::get_filter_identifier2_as_special_tvg() const
{
    if (_filter_identifier & 0b01000000)
        return "Normal TVG";

    return "Special TVG";
}

std::string RuntimeParameters::get_filter_identifier2_as_special_amp_detect() const
{
    if (_filter_identifier & 0b10000000)
        return "Normal amp detect";

    return "Special amp detect";
}

std::optional<std::string> RuntimeParameters::get_source_of_sound_speed_at_transducer_as_string(
    std::optional<std::string> unhandled_message) const
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

bool RuntimeParameters::get_extra_detections_enabled() const
{
    return _source_of_sound_speed_at_transducer & 0b00010000;
}

bool RuntimeParameters::get_sonar_mode_enabled() const
{
    return _source_of_sound_speed_at_transducer & 0b00100000;
}

bool RuntimeParameters::get_passive_mode_enabled() const
{
    return _source_of_sound_speed_at_transducer & 0b01000000;
}

bool RuntimeParameters::get_3d_scanning_enabled() const
{
    return _source_of_sound_speed_at_transducer & 0b10000000;
}

xxh::hash_t<64> RuntimeParameters::hash_content_only() const
{
    xxh::hash3_state_t<64> hash_stream;
    hash_stream.update(&_system_serial_number, 35);
    return hash_stream.digest();
}

size_t hash_value(const RuntimeParameters& data)
{
    return data.binary_hash();
}

RuntimeParameters RuntimeParameters::from_stream(std::istream& is, KongsbergAllDatagram header)
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

RuntimeParameters RuntimeParameters::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

RuntimeParameters RuntimeParameters::from_stream(std::istream&                    is,
                                                 t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void RuntimeParameters::to_stream(std::ostream& os) const
{
    KongsbergAllDatagram::to_stream(os);

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_ping_counter)), 40 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter RuntimeParameters::__printer__(unsigned int float_precision,
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
    printer.register_string("mode", fmt::format("0b{:08b}", _mode) /*, "encoded"*/);
    printer.register_string("filter_identifier",
                            fmt::format("0b{:08b}", _filter_identifier) /*, "encoded"*/);
    printer.register_value("minimum_depth", _minimum_depth, "m");
    printer.register_value("maximum_depth", _maximum_depth, "m");
    printer.register_value("absorption_coefficient", _absorption_coefficient, "0.01 db/km");
    printer.register_value("transmit_pulse_length", _transmit_pulse_length, "μs");
    printer.register_value("transmit_beamwidth", _transmit_beamwidth, "0.1°");
    printer.register_value(
        "transmit_power_relative_maximum", _transmit_power_relative_maximum, "dB");
    printer.register_value("receive_bandwidth_degree", _receive_beamwidth_degree, "0.1°");
    printer.register_value("receive_bandwidth_50hz", _receive_bandwidth_50hz, "50Hz");
    printer.register_string(
        "mode2_or_receiver_fixed_gain_setting",
        fmt::format("0b{:08b}", _mode2_or_receiver_fixed_gain_setting) /*, "encoded"*/);
    printer.register_value("tvg_law_crossover_angle", _tvg_law_crossover_angle, "°");
    printer.register_string(
        "source_of_sound_speed_at_transducer",
        fmt::format("0b{:08b}", _source_of_sound_speed_at_transducer) /*, "encoded"*/);
    printer.register_value("maximum_port_swath_width", _maximum_port_swath_width, "m");
    printer.register_value("beam_spacing",
                           fmt::format("0b{:08b}", _beam_spacing) /*, "encoded"*/);
    printer.register_value("maximum_port_coverage", _maximum_port_coverage, "°");
    printer.register_value(
        "yaw_and_pitch_stabilization_mode",
        fmt::format("0b{:08b}", _yaw_and_pitch_stabilization_mode) /*, "encoded"*/);
    printer.register_value("maximum_starboard_coverage", _maximum_starboard_coverage, "°");
    printer.register_value(
        "maximum_starboard_swath_width", _maximum_starboard_swath_width, "m");
    printer.register_value("transmit_along_tilt", _transmit_along_tilt, "0.1°");
    printer.register_string("filter_identifier2",
                            fmt::format("0b{:08b}", _filter_identifier2) /*, "encoded"*/);
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

    printer.register_section(fmt::format("decoded: 'mode' [{:08b}]", _mode));
    printer.register_string(
        "mode_as_ping_mode", get_mode_as_ping_mode().value_or("-None-"), "opt(string)");
    printer.register_string(
        "mode_as_tx_pulse_form", get_mode_as_tx_pulse_form().value_or("-None-"), "opt(string)");
    printer.register_string("mode_as_dual_swath_mode",
                            get_mode_as_dual_swath_mode().value_or("-None-"),
                            "opt(string)");

    printer.register_section(
        fmt::format("decoded: 'mode2' [{:08b}]", _mode2_or_receiver_fixed_gain_setting));
    printer.register_string("mode2_as_rx_or_sonar_head_use",
                            get_mode2_as_rx_or_sonar_head_use().value_or("-None-"),
                            "opt(string)");
    printer.register_string(
        "mode2_as_pulselength", get_mode2_as_pulselength().value_or("-None-"), "opt(string)");
    printer.register_optional_value("mode2_as_receive_fixed_gain_setting_dB",
                                    get_mode2_as_receive_fixed_gain_setting_dB(),
                                    "opt(dB)",
                                    "-None-");

    printer.register_section(
        fmt::format("decoded: 'filter_identifier' [{:08b}]", _filter_identifier));
    printer.register_string(
        "filter_identifier_as_spike_filter", get_filter_identifier_as_spike_filter(), "string");
    printer.register_string(
        "filter_identifier_as_slope_filter", get_filter_identifier_as_slope_filter(), "string");
    printer.register_string("filter_identifier_as_range_gates_size",
                            get_filter_identifier_as_range_gates_size().value_or("-None-"),
                            "opt(string)");
    printer.register_string("filter_identifier_as_aeration_filter",
                            get_filter_identifier_as_aeration_filter(),
                            "string");
    printer.register_string("filter_identifier_as_interference_filter",
                            get_filter_identifier_as_interference_filter(),
                            "string");

    printer.register_section(
        fmt::format("decoded: 'filter_identifier2' [{:08b}]", _filter_identifier2));
    printer.register_string("filter_identifier2_as_penetration_filter",
                            get_filter_identifier2_as_penetration_filter(),
                            "string");
    printer.register_string(
        "filter_identifier2_as_detect_mode", get_filter_identifier2_as_detect_mode(), "string");
    printer.register_string("filter_identifier2_as_phase_ramp",
                            get_filter_identifier2_as_phase_ramp().value_or("-None-"),
                            "opt(string)");
    printer.register_string(
        "filter_identifier2_as_special_tvg", get_filter_identifier2_as_special_tvg(), "string");
    printer.register_string("filter_identifier2_as_special_amp_detect",
                            get_filter_identifier2_as_special_amp_detect(),
                            "string");

    printer.register_section(
        fmt::format("decoded: 'source_of_sound_speed_at_transducer' [{:08b}]",
                    _source_of_sound_speed_at_transducer));
    printer.register_string(
        "source_of_sound_speed_at_transducer_as_string",
        get_source_of_sound_speed_at_transducer_as_string().value_or("-None-"),
        "opt(string)");
    printer.register_value("extra_detections_enabled", get_extra_detections_enabled(), "bool");
    printer.register_value("sonar_mode_enabled", get_sonar_mode_enabled(), "bool");
    printer.register_value("passive_mode_enabled", get_passive_mode_enabled(), "bool");
    printer.register_value("3d_scanning_enabled", get_3d_scanning_enabled(), "bool");

    printer.register_section(fmt::format("decoded: 'beam_spacing' [{:08b}]", _beam_spacing));
    printer.register_string("beam_spacing_as_string",
                            get_beam_spacing_as_string().value_or("-None-"),
                            "opt(string)");

    printer.register_section(fmt::format("decoded: 'yaw_and_pitch_stabilization_mode' [{:08b}]",
                                         _yaw_and_pitch_stabilization_mode));
    printer.register_string("yaw_and_pitch_stabilization_mode_as_yaw_stabilization",
                            get_yaw_and_pitch_stabilization_mode_as_yaw_stabilization(),
                            "string");
    printer.register_string(
        "yaw_and_pitch_stabilization_mode_as_heading_filter",
        get_yaw_and_pitch_stabilization_mode_as_heading_filter().value_or("-None-"),
        "opt(string)");
    printer.register_string("yaw_and_pitch_stabilization_mode_as_pitch_stibilization",
                            get_yaw_and_pitch_stabilization_mode_as_pitch_stibilization(),
                            "string");

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall  
} // namespace echosounders
} // namespace themachinethatgoesping
