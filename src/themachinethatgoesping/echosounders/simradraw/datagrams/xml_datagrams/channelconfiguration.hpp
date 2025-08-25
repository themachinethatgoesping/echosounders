// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/channelconfiguration.doc.hpp"

// std
#include <string>

// project (needed for member types / return types)
#include <themachinethatgoesping/navigation/datastructures/positionaloffsets.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include "xml_configuration_transceiver.hpp"
#include "xml_configuration_transducer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

class ChannelConfiguration
{
    std::string                                   _channel_id;
    navigation::datastructures::PositionalOffsets _sensor_offsets;

    XML_Configuration_Transceiver_Channel _channel;
    XML_Configuration_Transceiver         _transceiver;
    XML_Configuration_Transducer          _transducer_offsets;

  public:
    ChannelConfiguration() = default;
    ChannelConfiguration(std::string                           channel_id,
                         XML_Configuration_Transceiver_Channel xml_channel,
                         XML_Configuration_Transceiver         xml_transceiver,
                         XML_Configuration_Transducer          xml_transducer);
    ~ChannelConfiguration() = default;

    const std::string& get_channel_id() const { return _channel_id; }
    const navigation::datastructures::PositionalOffsets& get_sensor_offsets() const
    {
        return _sensor_offsets;
    }
    const XML_Configuration_Transceiver_Channel& get_channel_struct() const { return _channel; }
    const XML_Configuration_Transceiver&         get_transceiver_struct() const
    {
        return _transceiver;
    }
    const XML_Configuration_Transducer& get_transducer_offsets_struct() const
    {
        return _transducer_offsets;
    }

    static ChannelConfiguration from_stream(std::istream& is);
    void                       to_stream(std::ostream& os) const;

    bool operator==(const ChannelConfiguration& other) const = default;

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(ChannelConfiguration)
};

} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
}