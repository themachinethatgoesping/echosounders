// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "sonarsettings.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

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
    printer.register_value("steering_vertical", get_steering_vertical_in_degrees(), "°");
    printer.register_value("steering_horizontal", get_steering_horizontal_in_degrees(), "°");
    printer.register_value("beamwidth_vertical", get_beamwidth_vertical_in_degrees(), "°");
    printer.register_value("beamwidth_horizontal", get_beamwidth_horizontal_in_degrees(), "°");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
