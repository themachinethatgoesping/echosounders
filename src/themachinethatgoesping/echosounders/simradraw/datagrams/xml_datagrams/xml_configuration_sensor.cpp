// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xml_configuration_sensor.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

#include <iostream>
#include <fmt/format.h>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/helper/approx.hpp>
#include <themachinethatgoesping/tools/helper/stringconversion.hpp>

void XML_Configuration_Sensor::initialize(const pugi::xml_node& root_node)
{
    if (strcmp(root_node.name(), "Sensor"))
    {
        throw std::runtime_error(
            std::string("XML_Configuration_Sensor: wrong root node type '") + root_node.name() +
            "'");
    }
    unknown_attributes = 0;
    unknown_children   = 0; // there should only be TelegramValue nodes

    // there should only be one child for this node
    for (const auto& node : root_node.children())
    {
        if (strcmp(node.name(), "Telegram"))
        {
            std::cerr << "WARNING: [Configuration_Sensor] Unknown child: " << node.name()
                      << std::endl;

            unknown_children = 1;

            continue;
        }

        Telegrams.emplace_back(node);
    }

    for (auto& attr : root_node.attributes())
    {
        std::string_view name = attr.name();
        if (name == "Timeout")
        {
            Timeout = tools::helper::string_to_floattype<double>(
                attr.value()); // TODO: can this value only be 0 and 1 or also true and false?
            continue;
        }
        if (name == "Unique")
        {
            Unique = std::stoi(
                attr.value()); // TODO: can this value only be 0 and 1 or also true and false?
            continue;
        }
        if (name == "AngleZ")
        {
            AngleZ = tools::helper::string_to_floattype<double>(
                attr.value()); // TODO: can this value only be 0 and 1 or also true and false?
            continue;
        }
        if (name == "AngleY")
        {
            AngleY = tools::helper::string_to_floattype<double>(
                attr.value()); // TODO: can this value only be 0 and 1 or also true and false?
            continue;
        }
        if (name == "AngleX")
        {
            AngleX = tools::helper::string_to_floattype<double>(
                attr.value()); // TODO: can this value only be 0 and 1 or also true and false?
            continue;
        }
        if (name == "Y")
        {
            Y = tools::helper::string_to_floattype<double>(
                attr.value()); // TODO: can this value only be 0 and 1 or also true and false?
            continue;
        }
        if (name == "X")
        {
            X = tools::helper::string_to_floattype<double>(
                attr.value()); // TODO: can this value only be 0 and 1 or also true and false?
            continue;
        }
        if (name == "Z")
        {
            Z = tools::helper::string_to_floattype<double>(
                attr.value()); // TODO: can this value only be 0 and 1 or also true and false?
            continue;
        }
        if (name == "Port")
        {
            Port = attr.value();
            continue;
        }
        if (name == "Type")
        {
            Type = attr.value();
            continue;
        }
        if (name == "Name")
        {
            Name = attr.value();
            continue;
        }
        if (name == "TalkerID")
        {
            TalkerID = attr.value();
            continue;
        }

        std::cerr << "WARNING: [Configuration_Sensor] Unknown attribute: " << name << std::endl;
        unknown_attributes += 1;
    }
}

// ----- file I/O -----
XML_Configuration_Sensor XML_Configuration_Sensor::from_stream(std::istream& is)
{
    XML_Configuration_Sensor xml;

    is.read(reinterpret_cast<char*>(&xml.Timeout), sizeof(xml.Timeout));
    is.read(reinterpret_cast<char*>(&xml.Unique), sizeof(xml.Unique));
    is.read(reinterpret_cast<char*>(&xml.AngleZ), sizeof(xml.AngleZ) * 6);
    xml.Port     = tools::classhelper::stream::container_from_stream<std::string>(is);
    xml.Type     = tools::classhelper::stream::container_from_stream<std::string>(is);
    xml.Name     = tools::classhelper::stream::container_from_stream<std::string>(is);
    xml.TalkerID = tools::classhelper::stream::container_from_stream<std::string>(is);

    size_t size;
    is.read(reinterpret_cast<char*>(&size), sizeof(size));
    xml.Telegrams.resize(size);
    for (auto& value : xml.Telegrams)
    {
        value = XML_Configuration_Sensor_Telegram::from_stream(is);
    }

    is.read(reinterpret_cast<char*>(&xml.unknown_children), sizeof(xml.unknown_children));
    is.read(reinterpret_cast<char*>(&xml.unknown_attributes), sizeof(xml.unknown_attributes));

    return xml;
}

void XML_Configuration_Sensor::to_stream(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(&Timeout), sizeof(Timeout));
    os.write(reinterpret_cast<const char*>(&Unique), sizeof(Unique));
    os.write(reinterpret_cast<const char*>(&AngleZ), sizeof(AngleZ) * 6);
    tools::classhelper::stream::container_to_stream(os, Port);
    tools::classhelper::stream::container_to_stream(os, Type);
    tools::classhelper::stream::container_to_stream(os, Name);
    tools::classhelper::stream::container_to_stream(os, TalkerID);

    size_t size = Telegrams.size();
    os.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const auto& value : Telegrams)
    {
        value.to_stream(os);
    }

    os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
    os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
}

// ----- operators -----
bool XML_Configuration_Sensor::operator==(const XML_Configuration_Sensor& other) const
{
    using tools::helper::approx;

    return approx(Timeout, other.Timeout) && Unique == other.Unique &&
           approx(AngleZ, other.AngleZ) && approx(AngleY, other.AngleY) &&
           approx(AngleX, other.AngleX) && approx(Y, other.Y) && approx(X, other.X) &&
           approx(Z, other.Z) && Port == other.Port && Type == other.Type &&
           Name == other.Name && TalkerID == other.TalkerID && Telegrams == other.Telegrams;

    // && unknown_children == other.unknown_children &&
    // unknown_attributes == other.unknown_attributes;
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter XML_Configuration_Sensor::__printer__(unsigned int float_precision,
                                              bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "EK80 XML0 Configuration_Sensor", float_precision, superscript_exponents);

    if (!Telegrams.empty())
    {
        printer.register_section("children (Telegrams)");
        for (const auto& telegram : Telegrams)
        {
            std::string values = "";
            for (const auto& value : telegram.Values)
            {
                values += fmt::format("{} ({}),", value.Name, value.Priority);
            }
            // remove trailing ',' if there is one
            if (!values.empty())
            {
                values.pop_back();
            }

            printer.register_value("Telegram", telegram.Name, values);
        }
    }

    printer.register_section("attributes");
    printer.register_value("Timeout", Timeout);
    printer.register_value("Unique", Unique);
    printer.register_value("AngleZ", AngleZ);
    printer.register_value("AngleY", AngleY);
    printer.register_value("AngleX", AngleX);
    printer.register_value("Y", Y);
    printer.register_value("X", X);
    printer.register_value("Z", Z);
    printer.register_value("Port", Port);
    printer.register_value("Type", Type);
    printer.register_value("Name", Name);
    printer.register_value("TalkerID", TalkerID);

    return printer;
}

} // namespace themachinethatgoesping
} // namespace echosounders
} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
