// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xml_configuration_transducer.hpp"

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

navigation::datastructures::PositionalOffsets XML_Configuration_Transducer::get_sensor_offsets() const
{
    // TODO: check angle directions
    // TODO: include transducer mounting and transducer orientation?
    // TODO: do we need HeadingQuickCalibration? And if so how to use it?
    return navigation::datastructures::PositionalOffsets(TransducerName,
                                                         TransducerOffsetX,
                                                         TransducerOffsetY,
                                                         TransducerOffsetZ,
                                                         TransducerAlphaZ,
                                                         TransducerAlphaY,
                                                         TransducerAlphaX);
}

void XML_Configuration_Transducer::initialize(const pugi::xml_node& root_node)
{
    if (strcmp(root_node.name(), "Transducer"))
    {
        throw std::runtime_error(
            std::string("XML_Configuration_Transducer: wrong root node type '") +
            root_node.name() + "'");
    }
    unknown_attributes = 0;
    unknown_children   = 0; // there should only be TelegramValue nodes

    // there should only be one child for this node
    for (const auto& node : root_node.children())
    {
        std::cerr << "WARNING: [Configuration_Transducer] Unknown child: " << node.name()
                  << std::endl;

        unknown_children = 1;
    }

    for (auto& attr : root_node.attributes())
    {
        std::string_view name = attr.name();
        if (name == "TransducerAlphaX")
        {
            TransducerAlphaX = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        else if (name == "TransducerAlphaY")
        {
            TransducerAlphaY = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "TransducerAlphaZ")
        {
            TransducerAlphaZ = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "TransducerOffsetX")
        {
            TransducerOffsetX = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "TransducerOffsetY")
        {
            TransducerOffsetY = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "TransducerOffsetZ")
        {
            TransducerOffsetZ = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "HeadingQuickCalibration")
        {
            HeadingQuickCalibration = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "TransducerSerialNumber")
        {
            TransducerSerialNumber = std::stoi(attr.value());
            continue;
        }
        if (name == "TransducerMounting")
        {
            TransducerMounting = attr.value();
            continue;
        }
        if (name == "TransducerOrientation")
        {
            TransducerOrientation = attr.value();
            continue;
        }
        if (name == "TransducerName")
        {
            TransducerName = attr.value();
            continue;
        }
        if (name == "TransducerCustomName")
        {
            TransducerCustomName = attr.value();
            continue;
        }

        std::cerr << "WARNING: [Configuration_Transducer] Unknown attribute: " << name
                  << std::endl;
        unknown_attributes += 1;
    }
}

bool XML_Configuration_Transducer::parsed_completely() const
{
    return unknown_children == 0 && unknown_attributes == 0;
}

XML_Configuration_Transducer XML_Configuration_Transducer::from_stream(std::istream& is)
{
    XML_Configuration_Transducer xml;

    is.read(reinterpret_cast<char*>(&xml.TransducerAlphaX), sizeof(xml.TransducerAlphaX) * 6);
    is.read(reinterpret_cast<char*>(&xml.TransducerSerialNumber),
            sizeof(xml.TransducerSerialNumber));
    xml.TransducerMounting = tools::classhelper::stream::container_from_stream<std::string>(is);
    xml.TransducerOrientation =
        tools::classhelper::stream::container_from_stream<std::string>(is);
    xml.TransducerName = tools::classhelper::stream::container_from_stream<std::string>(is);
    xml.TransducerCustomName =
        tools::classhelper::stream::container_from_stream<std::string>(is);

    is.read(reinterpret_cast<char*>(&xml.unknown_children), sizeof(xml.unknown_children));
    is.read(reinterpret_cast<char*>(&xml.unknown_attributes), sizeof(xml.unknown_attributes));

    return xml;
}

void XML_Configuration_Transducer::to_stream(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(&TransducerAlphaX), sizeof(TransducerAlphaX) * 6);
    os.write(reinterpret_cast<const char*>(&TransducerSerialNumber),
             sizeof(TransducerSerialNumber));
    tools::classhelper::stream::container_to_stream(os, TransducerMounting);
    tools::classhelper::stream::container_to_stream(os, TransducerOrientation);
    tools::classhelper::stream::container_to_stream(os, TransducerName);
    tools::classhelper::stream::container_to_stream(os, TransducerCustomName);

    os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
    os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
}

bool XML_Configuration_Transducer::operator==(const XML_Configuration_Transducer& other) const
{
    using tools::helper::approx;

    return approx(TransducerAlphaX, other.TransducerAlphaX) &&
           approx(TransducerAlphaY, other.TransducerAlphaY) &&
           approx(TransducerAlphaZ, other.TransducerAlphaZ) &&
           approx(TransducerOffsetX, other.TransducerOffsetX) &&
           approx(TransducerOffsetY, other.TransducerOffsetY) &&
           approx(TransducerOffsetZ, other.TransducerOffsetZ) &&
           approx(HeadingQuickCalibration, other.HeadingQuickCalibration) &&
           TransducerSerialNumber == other.TransducerSerialNumber &&
           TransducerMounting == other.TransducerMounting &&
           TransducerOrientation == other.TransducerOrientation &&
           TransducerName == other.TransducerName &&
           TransducerCustomName == other.TransducerCustomName;

    // && unknown_children == other.unknown_children &&
    // unknown_attributes == other.unknown_attributes;
}

bool XML_Configuration_Transducer::operator!=(const XML_Configuration_Transducer& other) const
{
    return !operator==(other);
}

tools::classhelper::ObjectPrinter XML_Configuration_Transducer::__printer__(unsigned int float_precision,
                                                                           bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "EK80 XML0 Configuration_Transducer", float_precision, superscript_exponents);

    printer.register_section("attributes");
    printer.register_value("TransducerAlphaX", TransducerAlphaX);
    printer.register_value("TransducerAlphaY", TransducerAlphaY);
    printer.register_value("TransducerAlphaZ", TransducerAlphaZ);
    printer.register_value("TransducerOffsetX", TransducerOffsetX);
    printer.register_value("TransducerOffsetY", TransducerOffsetY);
    printer.register_value("TransducerOffsetZ", TransducerOffsetZ);
    printer.register_value(
        "HeadingQuickCalibration", HeadingQuickCalibration, "not used so far");
    printer.register_value("TransducerSerialNumber", TransducerSerialNumber);
    printer.register_value("TransducerMounting", TransducerMounting);
    printer.register_value("TransducerOrientation", TransducerOrientation);
    printer.register_value("TransducerName", TransducerName);
    printer.register_value("TransducerCustomName", TransducerCustomName);

    return printer;
}

} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
