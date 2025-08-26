// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/xml_configuration_transceiver.doc.hpp"

// std includes
#include <string>
#include <unordered_map>
#include <vector>

#include <pugixml.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "helper.hpp"
#include "xml_configuration_transceiver_channel.hpp"
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
struct XML_Configuration_Transceiver
{
    std::string TransceiverName;
    std::string TransceiverType;
    std::string MarketSegment;
    std::string EthernetAddress;
    std::string IPAddress;
    std::string TransceiverSoftwareVersion;
    std::string Version;

    double Impedance         = NAN;
    double RxSampleFrequency = NAN;
    int    SerialNumber      = -1;
    int    TransceiverNumber = 0;
    int    Multiplexing      = 0;

    std::vector<XML_Configuration_Transceiver_Channel> Channels;

    int32_t unknown_children   = 0;
    int32_t unknown_attributes = 0;

  public:
    // ----- constructors -----
    XML_Configuration_Transceiver() = default;
    XML_Configuration_Transceiver(const pugi::xml_node& node) { initialize(node); }
    ~XML_Configuration_Transceiver() = default;

    const XML_Configuration_Transceiver_Channel& get_channel(std::string_view channel_id) const;

    void initialize(const pugi::xml_node& root_node);

    bool parsed_completely() const;

    // ----- file I/O -----
    static XML_Configuration_Transceiver from_stream(std::istream& is);

    void to_stream(std::ostream& os) const;

    // ----- operators -----
    bool operator==(const XML_Configuration_Transceiver& other) const;
    bool operator!=(const XML_Configuration_Transceiver& other) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(
        XML_Configuration_Transceiver)
};

}
}
}
}
}