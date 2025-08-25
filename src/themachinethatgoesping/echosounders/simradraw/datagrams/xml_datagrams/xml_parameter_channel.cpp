// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xml_parameter_channel.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

#include <iostream>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/helper/approx.hpp>
#include <themachinethatgoesping/tools/helper/stringconversion.hpp>

void XML_Parameter_Channel::initialize_channel_structure(const pugi::xml_node& node)
{
    for (const auto& attr : node.attributes())
    {
        std::string_view name = attr.name();
        if (name == "ChannelID")
        {
            ChannelID = attr.value();
            continue;
        }
        if (name == "ChannelMode")
        {
            ChannelMode = std::stoi(attr.value());
            continue;
        }
        if (name == "PulseForm")
        {
            PulseForm = std::stoi(attr.value());
            continue;
        }
        if (name == "FrequencyStart")
        {
            FrequencyStart = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "FrequencyEnd")
        {
            FrequencyEnd = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "BandWidth")
        {
            BandWidth = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "Frequency")
        {
            Frequency = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "PulseDuration")
        {
            PulseDuration = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "PulseLength")
        {
            PulseLength = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "SampleInterval")
        {
            SampleInterval = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "TransducerDepth")
        {
            TransducerDepth = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "TransmitPower")
        {
            TransmitPower = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "Slope")
        {
            Slope = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "SoundVelocity")
        {
            SoundVelocity = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "PingId")
        {
            PingId = attr.value();
            continue;
        }
        std::cerr << "WARNING: [ParameterChannel] Unknown attribute: " << name << std::endl;
        unknown_attributes += 1;
    }
}

void XML_Parameter_Channel::initialize(const pugi::xml_node& root_node)
{
    if (strcmp(root_node.name(), "Parameter"))
    {
        throw std::runtime_error(std::string("XML_Parameter_Channel: wrong root node type '") +
                                 root_node.name() + "'");
    }
    unknown_attributes = 0;
    unknown_children   = 0; // there should only be one child for this node
    bool parsed        = false;

    // there should only be one child for this node
    for (const auto& node : root_node.children())
    {
        if (parsed || strcmp(node.name(), "Channel"))
        {
            std::cerr << "WARNING: [ParameterChannel] Unknown child: " << node.name()
                      << std::endl;

            unknown_children = 1;

            continue;
        }

        parsed = true;

        initialize_channel_structure(node);
    }
}

// ----- file I/O -----
XML_Parameter_Channel XML_Parameter_Channel::from_stream(std::istream& is)
{
    XML_Parameter_Channel xml;
    xml.ChannelID = tools::classhelper::stream::container_from_stream<std::string>(is);
    is.read(reinterpret_cast<char*>(&xml.ChannelMode), sizeof(xml.ChannelMode));
    is.read(reinterpret_cast<char*>(&xml.PulseForm), sizeof(xml.PulseForm) * 12);
    xml.PingId = tools::classhelper::stream::container_from_stream<std::string>(is);
    is.read(reinterpret_cast<char*>(&xml.unknown_children), sizeof(xml.unknown_children));
    is.read(reinterpret_cast<char*>(&xml.unknown_attributes), sizeof(xml.unknown_attributes));

    return xml;
}

void XML_Parameter_Channel::to_stream(std::ostream& os) const
{
    tools::classhelper::stream::container_to_stream(os, ChannelID);
    os.write(reinterpret_cast<const char*>(&ChannelMode), sizeof(ChannelMode));
    os.write(reinterpret_cast<const char*>(&PulseForm), sizeof(PulseForm) * 12);
    tools::classhelper::stream::container_to_stream(os, PingId);
    os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
    os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
}

// ----- operators -----
bool XML_Parameter_Channel::operator==(const XML_Parameter_Channel& other) const
{
    using tools::helper::approx;
    return ChannelID == other.ChannelID && ChannelMode == other.ChannelMode &&
           PulseForm == other.PulseForm && approx(FrequencyStart, other.FrequencyStart) &&
           approx(FrequencyEnd, other.FrequencyEnd) && approx(BandWidth, other.BandWidth) &&
           approx(Frequency, other.Frequency) && approx(PulseDuration, other.PulseDuration) &&
           approx(PulseLength, other.PulseLength) &&
           approx(SampleInterval, other.SampleInterval) &&
           approx(TransducerDepth, other.TransducerDepth) &&
           approx(TransmitPower, other.TransmitPower) && approx(Slope, other.Slope) &&
           approx(SoundVelocity, other.SoundVelocity) && PingId == other.PingId;
    // && unknown_children == other.unknown_children &&
    // unknown_attributes == other.unknown_attributes;
}

bool XML_Parameter_Channel::operator<(const XML_Parameter_Channel& other) const
{
    if (ChannelID < other.ChannelID)
        return true;
    if (ChannelID > other.ChannelID)
        return false;
    if (ChannelMode < other.ChannelMode)
        return true;
    if (ChannelMode > other.ChannelMode)
        return false;
    if (PulseForm < other.PulseForm)
        return true;
    if (PulseForm > other.PulseForm)
        return false;
    if (FrequencyStart < other.FrequencyStart)
        return true;
    if (FrequencyStart > other.FrequencyStart)
        return false;
    if (FrequencyEnd < other.FrequencyEnd)
        return true;
    if (FrequencyEnd > other.FrequencyEnd)
        return false;
    if (BandWidth < other.BandWidth)
        return true;
    if (BandWidth > other.BandWidth)
        return false;
    if (Frequency < other.Frequency)
        return true;
    if (Frequency > other.Frequency)
        return false;
    if (PulseDuration < other.PulseDuration)
        return true;
    if (PulseDuration > other.PulseDuration)
        return false;
    if (PulseLength < other.PulseLength)
        return true;
    if (PulseLength > other.PulseLength)
        return false;
    if (SampleInterval < other.SampleInterval)
        return true;
    if (SampleInterval > other.SampleInterval)
        return false;
    if (TransducerDepth < other.TransducerDepth)
        return true;
    if (TransducerDepth > other.TransducerDepth)
        return false;
    if (TransmitPower < other.TransmitPower)
        return true;
    if (TransmitPower > other.TransmitPower)
        return false;
    if (Slope < other.Slope)
        return true;
    if (Slope > other.Slope)
        return false;
    if (SoundVelocity < other.SoundVelocity)
        return true;
    if (SoundVelocity > other.SoundVelocity)
        return false;
    if (PingId < other.PingId)
        return true;
    if (PingId > other.PingId)
        return false;

    return false;
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter XML_Parameter_Channel::__printer__(unsigned int float_precision,
                                              bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "EK80 XML0 Parameter Channel", float_precision, superscript_exponents);
    printer.register_string("ChannelID", ChannelID);
    printer.register_value("ChannelMode", ChannelMode);
    printer.register_value("PulseForm", PulseForm);
    printer.register_value("FrequencyStart", FrequencyStart);
    printer.register_value("FrequencyEnd", FrequencyEnd);
    printer.register_value("BandWidth", BandWidth);
    printer.register_value("Frequency", Frequency);
    printer.register_value("PulseDuration", PulseDuration);
    printer.register_value("PulseLength", PulseLength);
    printer.register_value("SampleInterval", SampleInterval);
    printer.register_value("TransducerDepth", TransducerDepth);
    printer.register_value("TransmitPower", TransmitPower);
    printer.register_value("Slope", Slope);
    printer.register_value("SoundVelocity", SoundVelocity);
    printer.register_value("PingId", PingId);
    printer.register_value("unknown_children", unknown_children);
    printer.register_value("unknown_attributes", unknown_attributes);

    return printer;
}

// ----- functions used for PackageCache -----
XML_Parameter_Channel XML_Parameter_Channel::from_stream(
    std::istream&                                  is,
    const std::unordered_map<size_t, std::string>& hash_cache)
{
    size_t hash;
    is.read(reinterpret_cast<char*>(&hash), sizeof(hash));

    return from_binary(hash_cache.at(hash));
}

void XML_Parameter_Channel::to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const
{
    auto   cache = this->to_binary();
    size_t hash  = xxh::xxhash3<64>(cache);

    if (!hash_cache.contains(hash))
        hash_cache[hash] = std::move(cache);

    os.write(reinterpret_cast<const char*>(&hash), sizeof(hash));
}

} // namespace themachinethatgoesping
} // namespace echosounders
} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
