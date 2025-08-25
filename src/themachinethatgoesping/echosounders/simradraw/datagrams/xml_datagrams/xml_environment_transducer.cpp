// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xml_environment_transducer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

#include <iostream>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/helper/approx.hpp>
#include <themachinethatgoesping/tools/helper/stringconversion.hpp>

void XML_Environment_Transducer::initialize(const pugi::xml_node& root_node)
{
    if (strcmp(root_node.name(), "Transducer"))
    {
        throw std::runtime_error(
            std::string("XML_Environment_Transducer: wrong root node type '") +
            root_node.name() + "'");
    }
    unknown_attributes = 0;
    unknown_children   = 0; // there should only be one child for this node

    // there should only be one child for this node
    for (const auto& node : root_node.children())
    {
        std::cerr << "WARNING: [Environment_Transducer] Unknown child: " << node.name()
                  << std::endl;

        unknown_children = 1;

        continue;
    }

    for (auto& attr : root_node.attributes())
    {
        std::string_view name = attr.name();
        if (name == "SoundSpeed")
        {
            SoundSpeed = tools::helper::string_to_floattype<double>(attr.value());
            continue;
        }
        if (name == "TransducerName")
        {
            TransducerName = attr.value();
            continue;
        }

        std::cerr << "WARNING: [Environment_Transducer] Unknown attribute: " << name
                  << std::endl;
        unknown_attributes += 1;
    }
}

// ----- file I/O -----
XML_Environment_Transducer XML_Environment_Transducer::from_stream(std::istream& is)
{
    XML_Environment_Transducer xml;
    is.read(reinterpret_cast<char*>(&xml.SoundSpeed), sizeof(xml.SoundSpeed));
    xml.TransducerName = tools::classhelper::stream::container_from_stream<std::string>(is);

    return xml;
}

void XML_Environment_Transducer::to_stream(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(&SoundSpeed), sizeof(SoundSpeed));
    tools::classhelper::stream::container_to_stream(os, TransducerName);
    os.write(reinterpret_cast<const char*>(&unknown_children), sizeof(unknown_children));
    os.write(reinterpret_cast<const char*>(&unknown_attributes), sizeof(unknown_attributes));
}

// ----- operators -----
bool XML_Environment_Transducer::operator==(const XML_Environment_Transducer& other) const
{
    using tools::helper::approx;
    return approx(SoundSpeed, other.SoundSpeed) && TransducerName == other.TransducerName;
    // && unknown_children == other.unknown_children &&
    // unknown_attributes == other.unknown_attributes;
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter XML_Environment_Transducer::__printer__(unsigned int float_precision,
                                              bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "EK80 XML0 Transducer [Environment]", float_precision, superscript_exponents);
    printer.register_value("SoundSpeed", SoundSpeed, "m/s");
    printer.register_string("TransducerName", TransducerName, "future use");
    printer.register_value("unknown_children", unknown_children);
    printer.register_value("unknown_attributes", unknown_attributes);

    return printer;
}

} // namespace themachinethatgoesping
} // namespace echosounders
} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
