// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/xmlconfigurationtransceiverchanneltransducer.doc.hpp"

// std includes
#include <string>
#include <unordered_map>
#include <vector>

#include <pugixml.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "helper.hpp"
#include "xml_configuration_transceiver_channel_frequencypar.hpp"
#include "xml_node.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

enum class t_BeamType : int32_t
{
    BeamTypeSingle   = 0,
    BeamTypeSplit    = 0x1,
    BeamTypeRef      = 0x2,
    BeamTypeRefB     = 0x4,
    BeamTypeSplit3   = 0x11,
    BeamTypeSplit2   = 0x21,
    BeamTypeSplit3C  = 0x31,
    BeamTypeSplit3CN = 0x41,
    BeamTypeSplit3CW = 0x51
};

/**
 * @brief XML base datagram
 *
 */
struct XMLConfigurationTransceiverChannelTransducer
{

    std::string         TransducerName;
    std::string         ArticleNumber;
    std::vector<double> Gain;
    std::vector<double> SaCorrection;
    int32_t             SerialNumber                 = -1;
    t_BeamType          BeamType                     = t_BeamType::BeamTypeSingle;
    double              Frequency                    = NAN;
    double              FrequencyMinimum             = NAN;
    double              FrequencyMaximum             = NAN;
    double              EquivalentBeamAngle          = NAN;
    double              MaxTxPowerTransducer         = NAN;
    double              BeamWidthAlongship           = NAN;
    double              BeamWidthAthwartship         = NAN;
    double              AngleSensitivityAlongship    = NAN;
    double              AngleSensitivityAthwartship  = NAN;
    double              AngleOffsetAlongship         = NAN;
    double              AngleOffsetAthwartship       = NAN;
    double              DirectivityDropAt2XBeamWidth = NAN;

    std::vector<XML_Configuration_Transceiver_Channel_FrequencyPar> FrequencyPars;

    int32_t unknown_children   = 0;
    int32_t unknown_attributes = 0;

  public:
    // ----- constructors -----
    XMLConfigurationTransceiverChannelTransducer() = default;
    XMLConfigurationTransceiverChannelTransducer(const pugi::xml_node& node) { initialize(node); }
    ~XMLConfigurationTransceiverChannelTransducer() = default;

    void initialize(const pugi::xml_node& root_node);

    bool parsed_completely() const;

    // ----- file I/O -----
    static XMLConfigurationTransceiverChannelTransducer from_stream(std::istream& is);

    void to_stream(std::ostream& os) const;

    // ----- operators -----
    bool operator==(const XMLConfigurationTransceiverChannelTransducer& other) const;
    bool operator!=(const XMLConfigurationTransceiverChannelTransducer& other) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(
        XMLConfigurationTransceiverChannelTransducer)
};

}
}
}
}
}