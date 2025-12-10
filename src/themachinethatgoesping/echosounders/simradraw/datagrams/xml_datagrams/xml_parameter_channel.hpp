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

#include <pugixml.hpp>

// #if defined(__x86_64__) || defined(_M_X64)
// #else
// #define _MM_PERM_ENUM int
// #endif
#include <xxhash.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/algorithms/signalprocessing/datastructures.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


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

    void initialize_channel_structure(const pugi::xml_node& node);

    void initialize(const pugi::xml_node& root_node);

    bool parsed_completely() const { return unknown_children == 0 && unknown_attributes == 0; }

    // ----- file I/O -----
    static XML_Parameter_Channel from_stream(std::istream& is);
    void to_stream(std::ostream& os) const;

    // ----- operators -----
    bool operator==(const XML_Parameter_Channel& other) const;
    bool operator!=(const XML_Parameter_Channel& other) const { return !operator==(other); }

    bool operator<(const XML_Parameter_Channel& other) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- functions used for PackageCache -----
    static XML_Parameter_Channel from_stream(
        std::istream&                                  is,
        const std::unordered_map<size_t, std::string>& hash_cache);

    void to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const;

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

// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_hash_value
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