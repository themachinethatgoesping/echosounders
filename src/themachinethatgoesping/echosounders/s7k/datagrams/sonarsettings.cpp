// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "sonarsettings.hpp"

#include <numbers>
#include <utility>

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

// ----- constructors -----
SonarSettings::SonarSettings()
    : _content{}
{
    set_datagram_identifier(DatagramIdentifier);
}

SonarSettings::SonarSettings(S7KDatagram header)
    : S7KDatagram(std::move(header))
{
}

// ----- convenient member access -----
uint64_t SonarSettings::get_serial_number() const
{
    return _content._serial_number;
}
uint32_t SonarSettings::get_ping_number() const
{
    return _content._ping_number;
}
uint16_t SonarSettings::get_multi_ping() const
{
    return _content._multi_ping;
}
float SonarSettings::get_frequency() const
{
    return _content._frequency;
}
float SonarSettings::get_sample_rate() const
{
    return _content._sample_rate;
}
float SonarSettings::get_receiver_bandwidth() const
{
    return _content._receiver_bandwidth;
}
float SonarSettings::get_tx_pulse_width() const
{
    return _content._tx_pulse_width;
}
SonarSettings::o_tx_pulse_type SonarSettings::get_tx_pulse_type() const
{
    return _content._tx_pulse_type;
}
SonarSettings::o_tx_pulse_envelope SonarSettings::get_tx_pulse_envelope() const
{
    return _content._tx_pulse_envelope;
}
float SonarSettings::get_tx_pulse_envelope_parameter() const
{
    return _content._tx_pulse_envelope_parameter;
}
SonarSettings::o_tx_pulse_mode SonarSettings::get_tx_pulse_mode() const
{
    return _content._tx_pulse_mode;
}
float SonarSettings::get_max_ping_rate() const
{
    return _content._max_ping_rate;
}
float SonarSettings::get_ping_period() const
{
    return _content._ping_period;
}
float SonarSettings::get_range_selection() const
{
    return _content._range_selection;
}
float SonarSettings::get_power_selection() const
{
    return _content._power_selection;
}
float SonarSettings::get_gain_selection() const
{
    return _content._gain_selection;
}
uint32_t SonarSettings::get_control_flags() const
{
    return _content._control_flags;
}
uint32_t SonarSettings::get_projector_id() const
{
    return _content._projector_id;
}
float SonarSettings::get_steering_vertical() const
{
    return _content._steering_vertical;
}
float SonarSettings::get_steering_horizontal() const
{
    return _content._steering_horizontal;
}
float SonarSettings::get_beamwidth_vertical() const
{
    return _content._beamwidth_vertical;
}
float SonarSettings::get_beamwidth_horizontal() const
{
    return _content._beamwidth_horizontal;
}
float SonarSettings::get_focal_point() const
{
    return _content._focal_point;
}
SonarSettings::o_projector_weighting SonarSettings::get_projector_weighting() const
{
    return _content._projector_weighting;
}
float SonarSettings::get_projector_weighting_parameter() const
{
    return _content._projector_weighting_parameter;
}
uint32_t SonarSettings::get_transmit_flags() const
{
    return _content._transmit_flags;
}
uint32_t SonarSettings::get_hydrophone_id() const
{
    return _content._hydrophone_id;
}
SonarSettings::o_rx_weighting SonarSettings::get_rx_weighting() const
{
    return _content._rx_weighting;
}
float SonarSettings::get_rx_weighting_parameter() const
{
    return _content._rx_weighting_parameter;
}
uint32_t SonarSettings::get_rx_flags() const
{
    return _content._rx_flags;
}
float SonarSettings::get_rx_width() const
{
    return _content._rx_width;
}
float SonarSettings::get_range_minimum() const
{
    return _content._range_minimum;
}
float SonarSettings::get_range_maximum() const
{
    return _content._range_maximum;
}
float SonarSettings::get_depth_minimum() const
{
    return _content._depth_minimum;
}
float SonarSettings::get_depth_maximum() const
{
    return _content._depth_maximum;
}
float SonarSettings::get_absorption() const
{
    return _content._absorption;
}
float SonarSettings::get_sound_velocity() const
{
    return _content._sound_velocity;
}
float SonarSettings::get_spreading() const
{
    return _content._spreading;
}
uint32_t SonarSettings::get_checksum() const
{
    return _content._checksum;
}

void SonarSettings::set_serial_number(uint64_t val)
{
    _content._serial_number = val;
}
void SonarSettings::set_ping_number(uint32_t val)
{
    _content._ping_number = val;
}
void SonarSettings::set_multi_ping(uint16_t val)
{
    _content._multi_ping = val;
}
void SonarSettings::set_frequency(float val)
{
    _content._frequency = val;
}
void SonarSettings::set_sample_rate(float val)
{
    _content._sample_rate = val;
}
void SonarSettings::set_receiver_bandwidth(float val)
{
    _content._receiver_bandwidth = val;
}
void SonarSettings::set_tx_pulse_width(float val)
{
    _content._tx_pulse_width = val;
}
void SonarSettings::set_tx_pulse_type(o_tx_pulse_type val)
{
    _content._tx_pulse_type = val;
}
void SonarSettings::set_tx_pulse_envelope(o_tx_pulse_envelope val)
{
    _content._tx_pulse_envelope = val;
}
void SonarSettings::set_tx_pulse_envelope_parameter(float val)
{
    _content._tx_pulse_envelope_parameter = val;
}
void SonarSettings::set_tx_pulse_mode(o_tx_pulse_mode val)
{
    _content._tx_pulse_mode = val;
}
void SonarSettings::set_max_ping_rate(float val)
{
    _content._max_ping_rate = val;
}
void SonarSettings::set_ping_period(float val)
{
    _content._ping_period = val;
}
void SonarSettings::set_range_selection(float val)
{
    _content._range_selection = val;
}
void SonarSettings::set_power_selection(float val)
{
    _content._power_selection = val;
}
void SonarSettings::set_gain_selection(float val)
{
    _content._gain_selection = val;
}
void SonarSettings::set_control_flags(uint32_t val)
{
    _content._control_flags = val;
}
void SonarSettings::set_projector_id(uint32_t val)
{
    _content._projector_id = val;
}
void SonarSettings::set_steering_vertical(float val)
{
    _content._steering_vertical = val;
}
void SonarSettings::set_steering_horizontal(float val)
{
    _content._steering_horizontal = val;
}
void SonarSettings::set_beamwidth_vertical(float val)
{
    _content._beamwidth_vertical = val;
}
void SonarSettings::set_beamwidth_horizontal(float val)
{
    _content._beamwidth_horizontal = val;
}
void SonarSettings::set_focal_point(float val)
{
    _content._focal_point = val;
}
void SonarSettings::set_projector_weighting(o_projector_weighting val)
{
    _content._projector_weighting = val;
}
void SonarSettings::set_projector_weighting_parameter(float val)
{
    _content._projector_weighting_parameter = val;
}
void SonarSettings::set_transmit_flags(uint32_t val)
{
    _content._transmit_flags = val;
}
void SonarSettings::set_hydrophone_id(uint32_t val)
{
    _content._hydrophone_id = val;
}
void SonarSettings::set_rx_weighting(o_rx_weighting val)
{
    _content._rx_weighting = val;
}
void SonarSettings::set_rx_weighting_parameter(float val)
{
    _content._rx_weighting_parameter = val;
}
void SonarSettings::set_rx_flags(uint32_t val)
{
    _content._rx_flags = val;
}
void SonarSettings::set_rx_width(float val)
{
    _content._rx_width = val;
}
void SonarSettings::set_range_minimum(float val)
{
    _content._range_minimum = val;
}
void SonarSettings::set_range_maximum(float val)
{
    _content._range_maximum = val;
}
void SonarSettings::set_depth_minimum(float val)
{
    _content._depth_minimum = val;
}
void SonarSettings::set_depth_maximum(float val)
{
    _content._depth_maximum = val;
}
void SonarSettings::set_absorption(float val)
{
    _content._absorption = val;
}
void SonarSettings::set_sound_velocity(float val)
{
    _content._sound_velocity = val;
}
void SonarSettings::set_spreading(float val)
{
    _content._spreading = val;
}
void SonarSettings::set_checksum(uint32_t val)
{
    _content._checksum = val;
}

// ----- processed data access -----
float SonarSettings::get_steering_vertical_in_degrees() const
{
    return _content._steering_vertical * 180.f / float(std::numbers::pi);
}
float SonarSettings::get_steering_horizontal_in_degrees() const
{
    return _content._steering_horizontal * 180.f / float(std::numbers::pi);
}
float SonarSettings::get_beamwidth_vertical_in_degrees() const
{
    return _content._beamwidth_vertical * 180.f / float(std::numbers::pi);
}
float SonarSettings::get_beamwidth_horizontal_in_degrees() const
{
    return _content._beamwidth_horizontal * 180.f / float(std::numbers::pi);
}
float SonarSettings::get_rx_width_in_degrees() const
{
    return _content._rx_width * 180.f / float(std::numbers::pi);
}

// ----- to/from stream functions -----
void SonarSettings::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);
}

SonarSettings SonarSettings::from_stream(std::istream& is, S7KDatagram header)
{
    SonarSettings datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

SonarSettings SonarSettings::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

SonarSettings SonarSettings::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void SonarSettings::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);
}

tools::classhelper::ObjectPrinter SonarSettings::__printer__(unsigned int float_precision,
                                                     bool         superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("SonarSettings content");
    printer.register_value("serial_number", _content._serial_number);
    printer.register_value("ping_number", _content._ping_number);
    printer.register_value("multi_ping", _content._multi_ping);
    printer.register_value("frequency", _content._frequency, "Hz");
    printer.register_value("sample_rate", _content._sample_rate, "Hz");
    printer.register_value("receiver_bandwidth", _content._receiver_bandwidth, "Hz");
    printer.register_value("tx_pulse_width", _content._tx_pulse_width, "s");
    printer.register_string(
        "tx_pulse_type", _content._tx_pulse_type.name(), _content._tx_pulse_type.alt_name());
    printer.register_string("tx_pulse_envelope",
                            _content._tx_pulse_envelope.name(),
                            _content._tx_pulse_envelope.alt_name());
    printer.register_value("tx_pulse_envelope_parameter", _content._tx_pulse_envelope_parameter);
    printer.register_string(
        "tx_pulse_mode", _content._tx_pulse_mode.name(), _content._tx_pulse_mode.alt_name());
    printer.register_value("max_ping_rate", _content._max_ping_rate, "1/s");
    printer.register_value("ping_period", _content._ping_period, "s");
    printer.register_value("range_selection", _content._range_selection, "m");
    printer.register_value("power_selection", _content._power_selection, "dB");
    printer.register_value("gain_selection", _content._gain_selection, "dB");
    printer.register_value("control_flags", fmt::format("0b{:032b}", _content._control_flags));
    printer.register_value("projector_id", _content._projector_id);
    printer.register_value("steering_vertical", _content._steering_vertical, "rad");
    printer.register_value("steering_horizontal", _content._steering_horizontal, "rad");
    printer.register_value("beamwidth_vertical", _content._beamwidth_vertical, "rad");
    printer.register_value("beamwidth_horizontal", _content._beamwidth_horizontal, "rad");
    printer.register_value("focal_point", _content._focal_point, "m");
    printer.register_string("projector_weighting",
                            _content._projector_weighting.name(),
                            _content._projector_weighting.alt_name());
    printer.register_value("projector_weighting_parameter",
                           _content._projector_weighting_parameter);
    printer.register_value("transmit_flags", fmt::format("0b{:032b}", _content._transmit_flags));
    printer.register_value("hydrophone_id", _content._hydrophone_id);
    printer.register_string(
        "rx_weighting", _content._rx_weighting.name(), _content._rx_weighting.alt_name());
    printer.register_value("rx_weighting_parameter", _content._rx_weighting_parameter);
    printer.register_value("rx_flags", fmt::format("0b{:032b}", _content._rx_flags));
    printer.register_value("rx_width", _content._rx_width, "rad");
    printer.register_value("range_minimum", _content._range_minimum, "m");
    printer.register_value("range_maximum", _content._range_maximum, "m");
    printer.register_value("depth_minimum", _content._depth_minimum, "m");
    printer.register_value("depth_maximum", _content._depth_maximum, "m");
    printer.register_value("absorption", _content._absorption, "dB/km");
    printer.register_value("sound_velocity", _content._sound_velocity, "m/s");
    printer.register_value("spreading", _content._spreading, "dB");
    printer.register_value("checksum", _content._checksum);

    printer.register_section("processed");
    printer.register_value(
        "steering_vertical_in_degrees", get_steering_vertical_in_degrees(), "°");
    printer.register_value(
        "steering_horizontal_in_degrees", get_steering_horizontal_in_degrees(), "°");
    printer.register_value(
        "beamwidth_vertical_in_degrees", get_beamwidth_vertical_in_degrees(), "°");
    printer.register_value(
        "beamwidth_horizontal_in_degrees", get_beamwidth_horizontal_in_degrees(), "°");
    printer.register_value("rx_width_in_degrees", get_rx_width_in_degrees(), "°");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping

// ----- explicit template instantiation (matches extern template in sonarsettings.hpp) -----
template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_type,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_type_values
        .size(),
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_type_values,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_type_names,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_type_alt_names>;
template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_envelope,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_envelope_values
        .size(),
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_envelope_values,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_envelope_names,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::
        t_tx_pulse_envelope_alt_names>;
template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_mode,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_mode_values
        .size(),
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_mode_values,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_mode_names,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_tx_pulse_mode_alt_names>;
template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_projector_weighting,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_projector_weighting_values
        .size(),
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_projector_weighting_values,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_projector_weighting_names,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::
        t_projector_weighting_alt_names>;
template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_rx_weighting,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_rx_weighting_values
        .size(),
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_rx_weighting_values,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_rx_weighting_names,
    themachinethatgoesping::echosounders::s7k::datagrams::SonarSettings::t_rx_weighting_alt_names>;
