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

SonarSettings SonarSettings::from_stream(std::istream& is, t_S7KDatagramIdentifier datagram_identifier)
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
    tools::classhelper::ObjectPrinter printer("SonarSettings", float_precision, superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("SonarSettings content");
    printer.register_value("serial_number", _content.serial_number);
    printer.register_value("ping_number", _content.ping_number);
    printer.register_value("multi_ping", _content.multi_ping);
    printer.register_value("frequency", _content.frequency, "Hz");
    printer.register_value("sample_rate", _content.sample_rate, "Hz");
    printer.register_value("receiver_bandwidth", _content.receiver_bandwidth, "Hz");
    printer.register_value("tx_pulse_width", _content.tx_pulse_width, "s");
    printer.register_value("tx_pulse_type", _content.tx_pulse_type);
    printer.register_value("tx_pulse_envelope", _content.tx_pulse_envelope);
    printer.register_value("tx_pulse_envelope_parameter", _content.tx_pulse_envelope_parameter);
    printer.register_value("tx_pulse_mode", _content.tx_pulse_mode);
    printer.register_value("max_ping_rate", _content.max_ping_rate, "1/s");
    printer.register_value("ping_period", _content.ping_period, "s");
    printer.register_value("range_selection", _content.range_selection, "m");
    printer.register_value("power_selection", _content.power_selection, "dB");
    printer.register_value("gain_selection", _content.gain_selection, "dB");
    printer.register_value("control_flags", _content.control_flags);
    printer.register_value("projector_id", _content.projector_id);
    printer.register_value("steering_vertical", _content.steering_vertical, "rad");
    printer.register_value("steering_horizontal", _content.steering_horizontal, "rad");
    printer.register_value("beamwidth_vertical", _content.beamwidth_vertical, "rad");
    printer.register_value("beamwidth_horizontal", _content.beamwidth_horizontal, "rad");
    printer.register_value("focal_point", _content.focal_point, "m");
    printer.register_value("projector_weighting", _content.projector_weighting);
    printer.register_value("projector_weighting_parameter", _content.projector_weighting_parameter);
    printer.register_value("transmit_flags", _content.transmit_flags);
    printer.register_value("hydrophone_id", _content.hydrophone_id);
    printer.register_value("rx_weighting", _content.rx_weighting);
    printer.register_value("rx_weighting_parameter", _content.rx_weighting_parameter);
    printer.register_value("rx_flags", _content.rx_flags);
    printer.register_value("rx_width", _content.rx_width, "rad");
    printer.register_value("range_minimum", _content.range_minimum, "m");
    printer.register_value("range_maximum", _content.range_maximum, "m");
    printer.register_value("depth_minimum", _content.depth_minimum, "m");
    printer.register_value("depth_maximum", _content.depth_maximum, "m");
    printer.register_value("absorption", _content.absorption, "dB/km");
    printer.register_value("sound_velocity", _content.sound_velocity, "m/s");
    printer.register_value("spreading", _content.spreading, "dB");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
