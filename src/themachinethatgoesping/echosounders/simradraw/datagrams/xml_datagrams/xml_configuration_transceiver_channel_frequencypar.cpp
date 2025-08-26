// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xml_configuration_transceiver_channel_frequencypar.hpp"

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

void XML_Configuration_Transceiver_Channel_FrequencyPar::initialize(const pugi::xml_node& root_node)
{
    if (strcmp(root_node.name(), "FrequencyPar"))
    {
        throw std::runtime_error(
            std::string(
                "XML_Configuration_Transceiver_Channel_FrequencyPar: wrong root node type '") +
            root_node.name() + "'");
    }
    unknown_attributes = 0;
    unknown_children   = 0; // there should only be one Transducer Node

    // there should only be one child for this node
    for (const auto& node : root_node.children())
    {
        std::cerr << "WARNING: [Configuration_Transceiver_Channel_FrequencyPar] Unknown child: "
                  << node.name() << std::endl;

        unknown_children = 1;
    }

    for (auto& attr : root_node.attributes())
    {
        std::string_view name = attr.name();
        if (name == "Frequency")
        {
            Frequency = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "Gain")
        {
            Gain = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "Impedance")
        {
            Impedance = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "Phase")
        {
            Phase = tools::helper::string_to_floattype<double>(attr.value());
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

        std::cerr
            << "WARNING: [Configuration_Transceiver_Channel_FrequencyPar] Unknown attribute: "
            << name << std::endl;
        unknown_attributes += 1;
    }
}

bool XML_Configuration_Transceiver_Channel_FrequencyPar::parsed_completely() const
{
    return unknown_children == 0 && unknown_attributes == 0;
}

XML_Configuration_Transceiver_Channel_FrequencyPar XML_Configuration_Transceiver_Channel_FrequencyPar::from_stream(std::istream& is)
{
    XML_Configuration_Transceiver_Channel_FrequencyPar xml;

    is.read(reinterpret_cast<char*>(&xml.Frequency), sizeof(xml.Frequency) * 8);

    is.read(reinterpret_cast<char*>(&xml.unknown_children), sizeof(xml.unknown_children));
    is.read(reinterpret_cast<char*>(&xml.unknown_attributes), sizeof(xml.unknown_attributes));

    return xml;
}

void XML_Configuration_Transceiver_Channel_FrequencyPar::to_stream(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(&Frequency), sizeof(Frequency) * 8);

    os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
    os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
}

bool XML_Configuration_Transceiver_Channel_FrequencyPar::operator==(const XML_Configuration_Transceiver_Channel_FrequencyPar& other) const
{
    return tools::helper::float_equals(Frequency, other.Frequency) &&
           tools::helper::float_equals(Gain, other.Gain) &&
           tools::helper::float_equals(Impedance, other.Impedance) &&
           tools::helper::float_equals(Phase, other.Phase) &&
           tools::helper::float_equals(BeamWidthAlongship, other.BeamWidthAlongship) &&
           tools::helper::float_equals(BeamWidthAthwartship, other.BeamWidthAthwartship) &&
           tools::helper::float_equals(AngleOffsetAlongship, other.AngleOffsetAlongship) &&
           tools::helper::float_equals(AngleOffsetAthwartship, other.AngleOffsetAthwartship);

    // && unknown_children == other.unknown_children &&
    // unknown_attributes == other.unknown_attributes;
}

bool XML_Configuration_Transceiver_Channel_FrequencyPar::operator!=(const XML_Configuration_Transceiver_Channel_FrequencyPar& other) const
{
    return !operator==(other);
}

tools::classhelper::ObjectPrinter XML_Configuration_Transceiver_Channel_FrequencyPar::__printer__(unsigned int float_precision,
                                                                                                 bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "EK80 XML0 Configuration_Transceiver_Channel_FrequencyPar",
        float_precision,
        superscript_exponents);

    printer.register_section("attributes");
    printer.register_value("Frequency", Frequency);
    printer.register_value("Gain", Gain);
    printer.register_value("Impedance", Impedance);
    printer.register_value("Phase", Phase);
    printer.register_value("BeamWidthAlongship", BeamWidthAlongship);
    printer.register_value("BeamWidthAthwartship", BeamWidthAthwartship);
    printer.register_value("AngleOffsetAlongship", AngleOffsetAlongship);
    printer.register_value("AngleOffsetAthwartship", AngleOffsetAthwartship);

    return printer;
}

} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
