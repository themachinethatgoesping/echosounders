// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "channelconfiguration.hpp"

#include <themachinethatgoesping/tools/classhelper/stream.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

// Implementation file for channelconfiguration.hpp
// TODO: Move appropriate implementations from header to this file

// ----- constructors -----
ChannelConfiguration::ChannelConfiguration(std::string                           channel_id,
                                           XML_Configuration_Transceiver_Channel xml_channel,
                                           XML_Configuration_Transceiver         xml_transceiver,
                                           XML_Configuration_Transducer          xml_transducer)
    : _channel_id(std::move(channel_id))
    , _sensor_offsets(xml_transducer.get_sensor_offsets())
    , _channel(std::move(xml_channel))
    , _transceiver(std::move(xml_transceiver))
    , _transducer_offsets(std::move(xml_transducer))
{
}

// ----- file I/O -----
ChannelConfiguration ChannelConfiguration::from_stream(std::istream& is)
{
    ChannelConfiguration channel;

    channel._channel_id =
        tools::classhelper::stream::container_from_stream<std::string>(is);
    channel._sensor_offsets = navigation::datastructures::PositionalOffsets::from_stream(is);
    channel._channel        = XML_Configuration_Transceiver_Channel::from_stream(is);
    channel._transceiver    = XML_Configuration_Transceiver::from_stream(is);
    channel._transducer_offsets = XML_Configuration_Transducer::from_stream(is);

    return channel;
}

void ChannelConfiguration::to_stream(std::ostream& os) const
{
    tools::classhelper::stream::container_to_stream(os, _channel_id);
    _sensor_offsets.to_stream(os);
    _channel.to_stream(os);
    _transceiver.to_stream(os);
    _transducer_offsets.to_stream(os);
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter ChannelConfiguration::__printer__(
    unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "EK80 Channel Configuration (derived from XML Configuration Datagram)",
        float_precision,
        superscript_exponents);
    printer.register_string("Channel ID", _channel_id);

    printer.register_section("children");
    printer.register_string("Channel", _channel.ChannelID);
    printer.register_string("Transceiver", _transceiver.TransceiverName);
    printer.register_string("Transducer", _transducer_offsets.TransducerName);

    printer.register_section("sensor offsets");
    printer.append(_sensor_offsets.__printer__(float_precision, superscript_exponents));

    return printer;
}

} // namespace themachinethatgoesping
} // namespace echosounders
} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
