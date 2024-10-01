// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/channelconfiguration.doc.hpp"

// std includes
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string/find.hpp>

#include <pugixml.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/navigation/datastructures/positionaloffsets.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "helper.hpp"
#include "xml_configuration_transceiver.hpp"
#include "xml_configuration_transducer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

/**
 * @brief XML base datagram
 *
 */
class ChannelConfiguration
{
    // Header attributes
    std::string                                   _channel_id;
    navigation::datastructures::PositionalOffsets _sensor_offsets;

    XML_Configuration_Transceiver_Channel _channel;
    XML_Configuration_Transceiver         _transceiver;
    XML_Configuration_Transducer          _transducer_offsets;

  public:
    // ----- constructors -----
    ChannelConfiguration() = default;
    ChannelConfiguration(std::string                           channel_id,
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
    ~ChannelConfiguration() = default;

    const std::string& get_channel_id() const { return _channel_id; }
    const navigation::datastructures::PositionalOffsets& get_sensor_offsets() const
    {
        return _sensor_offsets;
    }

    const XML_Configuration_Transceiver_Channel& get_channel_struct() const { return _channel; }
    const XML_Configuration_Transceiver& get_transceiver_struct() const { return _transceiver; }
    const XML_Configuration_Transducer&  get_transducer_offsets_struct() const
    {
        return _transducer_offsets;
    }

    // ----- file I/O -----
    static ChannelConfiguration from_stream(std::istream& is)
    {
        ChannelConfiguration channel;

        channel._channel_id = tools::classhelper::stream::container_from_stream<std::string>(is);
        channel._sensor_offsets = navigation::datastructures::PositionalOffsets::from_stream(is);
        channel._channel        = XML_Configuration_Transceiver_Channel::from_stream(is);
        channel._transceiver    = XML_Configuration_Transceiver::from_stream(is);
        channel._transducer_offsets = XML_Configuration_Transducer::from_stream(is);

        return channel;
    }

    void to_stream(std::ostream& os) const
    {
        tools::classhelper::stream::container_to_stream(os, _channel_id);
        _sensor_offsets.to_stream(os);
        _channel.to_stream(os);
        _transceiver.to_stream(os);
        _transducer_offsets.to_stream(os);
    }

    // ----- operators -----
    bool operator==(const ChannelConfiguration& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "EK80 Channel Configuration (derived from XML Configuration Datagram)",
            float_precision, superscript_exponents);
        printer.register_string("Channel ID", _channel_id);

        printer.register_section("children");
        printer.register_string("Channel", _channel.ChannelID);
        printer.register_string("Transceiver", _transceiver.TransceiverName);
        printer.register_string("Transducer", _transducer_offsets.TransducerName);

        printer.register_section("sensor offsets");
        printer.append(_sensor_offsets.__printer__(float_precision, superscript_exponents));

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(
        ChannelConfiguration)
};

}
}
}
}
}