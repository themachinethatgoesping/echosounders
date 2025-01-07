// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean
// Research Kiel SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz
// Centre for Ocean Research Kiel SPDX-FileCopyrightText: 2022 Peter Urban,
// Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/xml_parameter_channel.doc.hpp"

// std includes
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string/find.hpp>

#include <pugixml.hpp>

// #if defined(__x86_64__) || defined(_M_X64)
// #else
// #define _MM_PERM_ENUM int
// #endif
#include <xxhash.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/algorithms/signalprocessing/datastructures.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "helper.hpp"
#include "xml_node.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

/**
 * @brief XML base datagram
 *
 */
struct XML_Parameter_Channel
{
    std::string ChannelID;
    int64_t     ChannelMode     = -1;
    int64_t     PulseForm       = 0;   ///< 0 means cw, ?1 means chirp?
    double      FrequencyStart  = NAN; ///< used used for chirp pulse (PulseForm > 0)
    double      FrequencyEnd    = NAN; ///< used used for chirp pulse (PulseForm > 0)
    double      BandWidth       = NAN; ///< TODO: when is this one used
    double      Frequency       = NAN; ///< used for cv ( PulseForm == 0)
    double      PulseDuration   = NAN; ///< used for cv ( PulseForm == 0)
    double      PulseLength     = NAN; ///< used for chirp pulse (PulseForm > 0)
    double      SampleInterval  = NAN;
    double      TransducerDepth = NAN; ///< when is this one used? only old format?
    double      TransmitPower   = NAN;
    double      Slope           = NAN;
    double      SoundVelocity   = NAN;
    std::string PingId; ///< this is used in the InitialParameter datagram

    int32_t unknown_children   = 0;
    int32_t unknown_attributes = 0;

  public:
    // ----- constructors -----
    XML_Parameter_Channel() = default;
    XML_Parameter_Channel(const pugi::xml_node& node) { initialize(node); }
    ~XML_Parameter_Channel() = default;


    // ----- getters -----
    double get_pulse_duration() const
    {
        return (std::isnan(PulseDuration)) ? PulseLength : PulseDuration;
    }

    bool get_pulse_form_is_cw() const { return PulseForm == 0; }
    bool get_pulse_form_is_fm() const { return PulseForm == 1; }

    themachinethatgoesping::algorithms::signalprocessing::datastructures::TxSignalParameters
    get_tx_signal_parameters() const
    {
        using algorithms::signalprocessing::datastructures::CWSignalParameters;
        using algorithms::signalprocessing::datastructures::FMSignalParameters;

        switch (PulseForm)
        {
            case 0: // CW
                return CWSignalParameters(Frequency,
                                          BandWidth // this is NAN for CW ...
                                          ,
                                          (std::isnan(PulseDuration)) ? PulseLength
                                                                      : PulseDuration);

            case 1: // FM?
                // FM is not yet properly supported
                // we should also save frequency start and frequency end
                return FMSignalParameters(Frequency,
                                          BandWidth,
                                          (std::isnan(PulseLength)) ? PulseDuration : PulseLength,
                                          FrequencyEnd > FrequencyStart);
            default:
                // this should not happen since the get_tx_signal_type should return a valid
                // type
                throw std::runtime_error("Unknown transmit signal type");
        }
    }

    void initialize_channel_structure(const pugi::xml_node& node)
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

    void initialize(const pugi::xml_node& root_node)
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

    bool parsed_completely() const { return unknown_children == 0 && unknown_attributes == 0; }

    // ----- file I/O -----
    static XML_Parameter_Channel from_stream(std::istream& is)
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

    void to_stream(std::ostream& os) const
    {
        tools::classhelper::stream::container_to_stream(os, ChannelID);
        os.write(reinterpret_cast<const char*>(&ChannelMode), sizeof(ChannelMode));
        os.write(reinterpret_cast<const char*>(&PulseForm), sizeof(PulseForm) * 12);
        tools::classhelper::stream::container_to_stream(os, PingId);
        os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
        os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
    }

    // ----- operators -----
    bool operator==(const XML_Parameter_Channel& other) const
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
    bool operator!=(const XML_Parameter_Channel& other) const { return !operator==(other); }

    bool operator<(const XML_Parameter_Channel& other) const
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
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("EK80 XML0 Parameter Channel", float_precision, superscript_exponents);
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
    static XML_Parameter_Channel from_stream(
        std::istream&                                  is,
        const std::unordered_map<size_t, std::string>& hash_cache)
    {
        size_t hash;
        is.read(reinterpret_cast<char*>(&hash), sizeof(hash));

        return from_binary(hash_cache.at(hash));
    }

    void to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const
    {
        auto   cache = this->to_binary();
        size_t hash  = xxh::xxhash3<64>(cache);

        if (!hash_cache.contains(hash))
            hash_cache[hash] = std::move(cache);

        os.write(reinterpret_cast<const char*>(&hash), sizeof(hash));
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(XML_Parameter_Channel)
};

/**
 * @brief Provide a boost hash function for XML_Parameter_Channel
 * - Note: this is needed to use XML_Parameter_Channel as boost::flyweight
 *
 * @param data
 * @return std::size_t
 */

// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_hash_value
inline size_t hash_value(const XML_Parameter_Channel& data)
{
    return data.binary_hash();
}

}
}
}
}
}

namespace std {
template<>
struct hash<themachinethatgoesping::echosounders::simradraw::datagrams::xml_datagrams::
                XML_Parameter_Channel>
{
    size_t operator()(const themachinethatgoesping::echosounders::simradraw::datagrams::
                          xml_datagrams::XML_Parameter_Channel& arg) const
    {
        return arg.binary_hash();
    }
};
}