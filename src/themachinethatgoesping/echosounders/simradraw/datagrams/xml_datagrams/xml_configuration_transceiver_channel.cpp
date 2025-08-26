// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xml_configuration_transceiver_channel.hpp"

#include <iostream>
#include <fmt/format.h>
#include <boost/algorithm/string/find.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/helper/stringconversion.hpp>
#include <themachinethatgoesping/tools/helper/floatcompare.hpp>
#include <themachinethatgoesping/tools/helper/approx.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

void XML_Configuration_Transceiver_Channel::initialize(const pugi::xml_node& root_node)
{
    if (strcmp(root_node.name(), "Channel"))
    {
        throw std::runtime_error(
            std::string("XML_Configuration_Transceiver_Channel: wrong root node type '") +
            root_node.name() + "'");
    }
    unknown_attributes = 0;
    unknown_children   = 0; // there should only be one Transducer Node

    // there should only be one child for this node
    for (const auto& node : root_node.children())
    {
        if (strcmp(node.name(), "Transducer"))
        {
            std::cerr << "WARNING: [Configuration_Transceiver_Channel] Unknown child: "
                      << node.name() << std::endl;

            unknown_children = 1;

            continue;
        }

        Transducer = XMLConfigurationTransceiverChannelTransducer(node);
    }

    for (auto& attr : root_node.attributes())
    {
        std::string_view name = attr.name();
        if (name == "ChannelID")
        {
            ChannelID = attr.value();
            continue;
        }
        else if (name == "LogicalChannelID")
        {
            LogicalChannelID = attr.value();
            continue;
        }
        else if (name == "ChannelIdShort")
        {
            ChannelIdShort = attr.value();
            continue;
        }
        else if (name == "ChannelIDShort") ///< Sometimes it is written like this. (typo in xml)
        {
            ChannelIdShort = attr.value();
            continue;
        }
        else if (name == "PulseLength")
        {
            PulseLength = tools::helper::string_to_floattype_vector<double>(attr.value(), ';');
            continue;
        }
        else if (name == "PulseDuration")
        {
            PulseDuration =
                tools::helper::string_to_floattype_vector<double>(attr.value(), ';');
            continue;
        }
        else if (name == "PulseDurationFM")
        {
            PulseDurationFM =
                tools::helper::string_to_floattype_vector<double>(attr.value(), ';');
            continue;
        }
        else if (name == "SampleInterval")
        {
            SampleInterval =
                tools::helper::string_to_floattype_vector<double>(attr.value(), ';');
            continue;
        }
        else if (name == "MaxTxPowerTransceiver")
        {
            MaxTxPowerTransceiver = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "HWChannelConfiguration")
        {
            HWChannelConfiguration = std::stoi(attr.value());
            continue;
        }
        else if (name == "ChannelNumber")
        {
            ChannelNumber = std::stoi(attr.value());
            continue;
        }

        std::cerr << "WARNING: [Configuration_Transceiver_Channel] Unknown attribute: " << name
                  << std::endl;
        unknown_attributes += 1;
    }
}

bool XML_Configuration_Transceiver_Channel::parsed_completely() const
{
    return unknown_children == 0 && unknown_attributes == 0;
}

XML_Configuration_Transceiver_Channel XML_Configuration_Transceiver_Channel::from_stream(std::istream& is)
{
    XML_Configuration_Transceiver_Channel xml;

    xml.ChannelID        = tools::classhelper::stream::container_from_stream<std::string>(is);
    xml.LogicalChannelID = tools::classhelper::stream::container_from_stream<std::string>(is);
    xml.ChannelIdShort   = tools::classhelper::stream::container_from_stream<std::string>(is);
    xml.PulseLength =
        tools::classhelper::stream::container_from_stream<std::vector<double>>(is);
    xml.PulseDuration =
        tools::classhelper::stream::container_from_stream<std::vector<double>>(is);
    xml.PulseDurationFM =
        tools::classhelper::stream::container_from_stream<std::vector<double>>(is);
    xml.SampleInterval =
        tools::classhelper::stream::container_from_stream<std::vector<double>>(is);

    is.read(reinterpret_cast<char*>(&xml.MaxTxPowerTransceiver),
            sizeof(xml.MaxTxPowerTransceiver));
    is.read(reinterpret_cast<char*>(&xml.HWChannelConfiguration),
            sizeof(xml.HWChannelConfiguration));
    is.read(reinterpret_cast<char*>(&xml.ChannelNumber), sizeof(xml.ChannelNumber));

    xml.Transducer = XMLConfigurationTransceiverChannelTransducer::from_stream(is);

    is.read(reinterpret_cast<char*>(&xml.unknown_children), sizeof(xml.unknown_children));
    is.read(reinterpret_cast<char*>(&xml.unknown_attributes), sizeof(xml.unknown_attributes));

    return xml;
}

void XML_Configuration_Transceiver_Channel::to_stream(std::ostream& os) const
{
    tools::classhelper::stream::container_to_stream(os, ChannelID);
    tools::classhelper::stream::container_to_stream(os, LogicalChannelID);
    tools::classhelper::stream::container_to_stream(os, ChannelIdShort);
    tools::classhelper::stream::container_to_stream(os, PulseLength);
    tools::classhelper::stream::container_to_stream(os, PulseDuration);
    tools::classhelper::stream::container_to_stream(os, PulseDurationFM);
    tools::classhelper::stream::container_to_stream(os, SampleInterval);

    os.write(reinterpret_cast<const char*>(&MaxTxPowerTransceiver),
             sizeof(MaxTxPowerTransceiver));
    os.write(reinterpret_cast<const char*>(&HWChannelConfiguration),
             sizeof(HWChannelConfiguration));
    os.write(reinterpret_cast<const char*>(&ChannelNumber), sizeof(ChannelNumber));

    Transducer.to_stream(os);

    os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
    os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
}

bool XML_Configuration_Transceiver_Channel::operator==(const XML_Configuration_Transceiver_Channel& other) const
{
    using namespace tools::helper;

    return ChannelID == other.ChannelID && LogicalChannelID == other.LogicalChannelID &&
           ChannelIdShort == other.ChannelIdShort &&
           approx_container(PulseLength, other.PulseLength) &&
           approx_container(PulseDuration, other.PulseDuration) &&
           approx_container(PulseDurationFM, other.PulseDurationFM) &&
           approx_container(SampleInterval, other.SampleInterval) &&
           tools::helper::float_equals(MaxTxPowerTransceiver, other.MaxTxPowerTransceiver) &&
           HWChannelConfiguration == other.HWChannelConfiguration &&
           ChannelNumber == other.ChannelNumber && Transducer == other.Transducer;

    // && unknown_children == other.unknown_children &&
    // unknown_attributes == other.unknown_attributes;
}

bool XML_Configuration_Transceiver_Channel::operator!=(const XML_Configuration_Transceiver_Channel& other) const
{
    return !operator==(other);
}

std::vector<double> XML_Configuration_Transceiver_Channel::get_pulse_durations(bool fm) const
{
    if (fm)
        if (PulseDurationFM.size() > 0)
            return PulseDurationFM;

    if (PulseDuration.size() > 0)
        return PulseDuration;

    if (PulseLength.size() > 0)
        return PulseLength;

    throw std::runtime_error(
        "No pulse duration found in XML_Configuration_Transceiver_Channel");
}

tools::classhelper::ObjectPrinter XML_Configuration_Transceiver_Channel::__printer__(unsigned int float_precision,
                                                                                    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "EK80 XML0 Configuration_Transceiver_Channel", float_precision, superscript_exponents);

    printer.register_section("children (Transducer)");
    printer.register_value("Transducer", Transducer.TransducerName);

    printer.register_section("attributes");
    printer.register_string("ChannelID", ChannelID);
    printer.register_string("LogicalChannelID", LogicalChannelID);
    printer.register_string("ChannelIdShort", ChannelIdShort);

    printer.register_container("PulseLength", PulseLength);
    printer.register_container("PulseDuration", PulseDuration);
    printer.register_container("PulseDurationFM", PulseDurationFM);
    printer.register_container("SampleInterval", SampleInterval);

    printer.register_value("MaxTxPowerTransceiver", MaxTxPowerTransceiver);
    printer.register_value("HWChannelConfiguration", HWChannelConfiguration);
    printer.register_value("ChannelNumber", ChannelNumber);

    printer.register_value("unknown_children", unknown_children);
    printer.register_value("unknown_attributes", unknown_attributes);

    return printer;
}

} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
