// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xmlconfigurationtransceiverchanneltransducer.hpp"

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

void XMLConfigurationTransceiverChannelTransducer::initialize(const pugi::xml_node& root_node)
{
    if (strcmp(root_node.name(), "Transducer"))
    {
        throw std::runtime_error(
            std::string(
                "XMLConfigurationTransceiverChannelTransducer: wrong root node type '") +
            root_node.name() + "'");
    }
    unknown_attributes = 0;
    unknown_children   = 0;

    // there should only be one child for this node
    for (const auto& node : root_node.children())
    {
        if (strcmp(node.name(), "FrequencyPar"))
        {
            std::cerr
                << "WARNING: [Configuration_Transceiver_Channel_Transducer] Unknown child: "
                << node.name() << std::endl;

            unknown_children = 1;

            continue;
        }

        FrequencyPars.emplace_back(node);
    }

    for (auto& attr : root_node.attributes())
    {
        std::string_view name = attr.name();
        if (name == "TransducerName")
        {
            TransducerName = attr.value();
            continue;
        }
        if (name == "ArticleNumber")
        {
            ArticleNumber = attr.value();
            continue;
        }
        else if (name == "Gain")
        {
            Gain = tools::helper::string_to_floattype_vector<double>(attr.value(), ';');
            continue;
        }
        else if (name == "SaCorrection")
        {
            SaCorrection = tools::helper::string_to_floattype_vector<double>(attr.value(), ';');
            continue;
        }
        else if (name == "SerialNumber")
        {
            SerialNumber = std::stoi(attr.value());
            continue;
        }
        else if (name == "BeamType")
        {
            BeamType = t_BeamType(std::stoi(attr.value()));
            continue;
        }
        else if (name == "Frequency")
        {
            Frequency = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "FrequencyMinimum")
        {
            FrequencyMinimum = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "FrequencyMaximum")
        {
            FrequencyMaximum = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "EquivalentBeamAngle")
        {
            EquivalentBeamAngle = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "MaxTxPowerTransducer")
        {
            MaxTxPowerTransducer = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "BeamWidthAlongship")
        {
            BeamWidthAlongship = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "BeamWidthAthwartship")
        {
            BeamWidthAthwartship = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "AngleSensitivityAlongship")
        {
            AngleSensitivityAlongship = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "AngleSensitivityAthwartship")
        {
            AngleSensitivityAthwartship = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "AngleOffsetAlongship")
        {
            AngleOffsetAlongship = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "AngleOffsetAthwartship")
        {
            AngleOffsetAthwartship = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "DirectivityDropAt2XBeamWidth")
        {
            DirectivityDropAt2XBeamWidth = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }

        ++unknown_attributes;
        std::cerr << "WARNING: [Configuration_Transceiver_Channel_Transducer] Unknown Attribute: "
                  << attr.name() << std::endl;
    }
}

bool XMLConfigurationTransceiverChannelTransducer::parsed_completely() const
{
    return unknown_children == 0 && unknown_attributes == 0;
}

XMLConfigurationTransceiverChannelTransducer XMLConfigurationTransceiverChannelTransducer::from_stream(std::istream& is)
{
    XMLConfigurationTransceiverChannelTransducer xml;

    xml.TransducerName = tools::classhelper::stream::container_from_stream<std::string>(is);
    xml.ArticleNumber  = tools::classhelper::stream::container_from_stream<std::string>(is);
    xml.Gain = tools::classhelper::stream::container_from_stream<std::vector<double>>(is);
    xml.SaCorrection =
        tools::classhelper::stream::container_from_stream<std::vector<double>>(is);

    is.read(reinterpret_cast<char*>(&xml.SerialNumber), sizeof(xml.SerialNumber));
    is.read(reinterpret_cast<char*>(&xml.BeamType), sizeof(xml.BeamType));
    is.read(reinterpret_cast<char*>(&xml.Frequency), sizeof(xml.Frequency) * 12);

    size_t size;
    is.read(reinterpret_cast<char*>(&size), sizeof(size));
    xml.FrequencyPars.resize(size);
    for (auto& par : xml.FrequencyPars)
    {
        par = XML_Configuration_Transceiver_Channel_FrequencyPar::from_stream(is);
    }

    is.read(reinterpret_cast<char*>(&xml.unknown_children), sizeof(xml.unknown_children));
    is.read(reinterpret_cast<char*>(&xml.unknown_attributes), sizeof(xml.unknown_attributes));

    return xml;
}

void XMLConfigurationTransceiverChannelTransducer::to_stream(std::ostream& os) const
{
    tools::classhelper::stream::container_to_stream(os, TransducerName);
    tools::classhelper::stream::container_to_stream(os, ArticleNumber);
    tools::classhelper::stream::container_to_stream(os, Gain);
    tools::classhelper::stream::container_to_stream(os, SaCorrection);

    os.write(reinterpret_cast<const char*>(&SerialNumber), sizeof(SerialNumber));
    os.write(reinterpret_cast<const char*>(&BeamType), sizeof(BeamType));
    os.write(reinterpret_cast<const char*>(&Frequency), sizeof(Frequency) * 12);

    size_t size = FrequencyPars.size();
    os.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const auto& par : FrequencyPars)
    {
        par.to_stream(os);
    }

    os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
    os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
}

bool XMLConfigurationTransceiverChannelTransducer::operator==(const XMLConfigurationTransceiverChannelTransducer& other) const
{
    return TransducerName == other.TransducerName && ArticleNumber == other.ArticleNumber &&
           tools::helper::approx_container(Gain, other.Gain) &&
           tools::helper::approx_container(SaCorrection, other.SaCorrection) &&
           SerialNumber == other.SerialNumber && BeamType == other.BeamType &&
           tools::helper::float_equals(Frequency, other.Frequency) &&
           tools::helper::float_equals(FrequencyMinimum, other.FrequencyMinimum) &&
           tools::helper::float_equals(FrequencyMaximum, other.FrequencyMaximum) &&
           tools::helper::float_equals(EquivalentBeamAngle, other.EquivalentBeamAngle) &&
           tools::helper::float_equals(MaxTxPowerTransducer, other.MaxTxPowerTransducer) &&
           tools::helper::float_equals(BeamWidthAlongship, other.BeamWidthAlongship) &&
           tools::helper::float_equals(BeamWidthAthwartship, other.BeamWidthAthwartship) &&
           tools::helper::float_equals(AngleSensitivityAlongship,
                                       other.AngleSensitivityAlongship) &&
           tools::helper::float_equals(AngleSensitivityAthwartship,
                                       other.AngleSensitivityAthwartship) &&
           tools::helper::float_equals(AngleOffsetAlongship, other.AngleOffsetAlongship) &&
           tools::helper::float_equals(AngleOffsetAthwartship, other.AngleOffsetAthwartship) &&
           tools::helper::float_equals(DirectivityDropAt2XBeamWidth,
                                       other.DirectivityDropAt2XBeamWidth) &&
           FrequencyPars == other.FrequencyPars;

    // && unknown_children == other.unknown_children &&
    // unknown_attributes == other.unknown_attributes;
}

bool XMLConfigurationTransceiverChannelTransducer::operator!=(const XMLConfigurationTransceiverChannelTransducer& other) const
{
    return !operator==(other);
}

tools::classhelper::ObjectPrinter XMLConfigurationTransceiverChannelTransducer::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "EK80 XML0 Configuration_Transceiver_Channel_Transducer",
        float_precision,
        superscript_exponents);

    if (!FrequencyPars.empty())
    {
        double minFreq = NAN;
        double maxFreq = NAN;
        for (const auto& par : FrequencyPars)
        {
            if (std::isnan(minFreq) || par.Frequency < minFreq)
                minFreq = par.Frequency;
            if (std::isnan(maxFreq) || par.Frequency > maxFreq)
                maxFreq = par.Frequency;
        }

        printer.register_section("children (FrequencyPars)");
        printer.register_value(
            "FrequencyPars",
            FrequencyPars.size(),
            fmt::format("{:.2f} - {:.2f} kHz", minFreq / 1000, maxFreq / 1000));
    }

    printer.register_section("attributes");
    printer.register_string("TransducerName", TransducerName);
    printer.register_string("ArticleNumber", ArticleNumber);

    printer.register_container("Gain", Gain);
    printer.register_container("SaCorrection", SaCorrection);

    printer.register_value("SerialNumber", SerialNumber);
    printer.register_enum("BeamType", BeamType);
    printer.register_value("Frequency", Frequency);
    printer.register_value("FrequencyMinimum", FrequencyMinimum);
    printer.register_value("FrequencyMaximum", FrequencyMaximum);
    printer.register_value("EquivalentBeamAngle", EquivalentBeamAngle);
    printer.register_value("MaxTxPowerTransducer", MaxTxPowerTransducer);
    printer.register_value("BeamWidthAlongship", BeamWidthAlongship);
    printer.register_value("BeamWidthAthwartship", BeamWidthAthwartship);
    printer.register_value("AngleSensitivityAlongship", AngleSensitivityAlongship);
    printer.register_value("AngleSensitivityAthwartship", AngleSensitivityAthwartship);
    printer.register_value("AngleOffsetAlongship", AngleOffsetAlongship);
    printer.register_value("AngleOffsetAthwartship", AngleOffsetAthwartship);
    printer.register_value("DirectivityDropAt2XBeamWidth", DirectivityDropAt2XBeamWidth);

    return printer;
}

} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
