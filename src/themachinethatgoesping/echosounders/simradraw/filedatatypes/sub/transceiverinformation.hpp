// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/transceiverinformation.doc.hpp"

/* boost includes */
#include <boost/flyweight.hpp>
#include <boost/flyweight/key_value.hpp>

// themachinethatgoesping includes
#include <themachinethatgoesping/tools/classhelper/xxhashhelper.hpp>

// local includes
#include "../../datagrams.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {
namespace _sub {

/**
 * @brief This is a substructure of the simradrawPingWaterColumn class. It is used to store
 * information necessary to efficiently read water column data from the file. It does not hold the
 * actual water column samples
 *
 * Note this is a private substructure and is thus not part of the public API or pybind11 interface.
 *
 */
class TransceiverInformation
{
    datagrams::xml_datagrams::XML_Configuration_Transceiver         _ping_transceiver;
    datagrams::xml_datagrams::XML_Configuration_Transceiver_Channel _ping_transceiver_channel;

    bool _initialized = false;

    // used for computing power from complex 32 bit samples
    // see ek80 interface specification v23.06 p214
    // _impedance factor is ((ztransceiver + ztransducer) / ztransceiver)² * 1/ tdi * 1/(2*sqrt(2))²
    float _impedance_factor = std::numeric_limits<float>::quiet_NaN();

  public:
    TransceiverInformation() = default;
    TransceiverInformation(
        const datagrams::xml_datagrams::XML_Configuration_Transceiver& ping_transceiver,
        const datagrams::xml_datagrams::XML_Configuration_Transceiver_Channel&
            ping_transceiver_channel);

    static float compute_impedance_factor(float transceiver_impedance,
                                          float transducer_impedance = 75);

    bool operator==(const TransceiverInformation& other) const;

    std::optional<size_t> get_pulse_duration_index_optional(
        const datagrams::xml_datagrams::XML_Parameter_Channel& parameters) const;

    std::optional<size_t> get_pulse_duration_index_optional(float pulse_duration, bool fm) const;

    size_t get_pulse_duration_index(
        const datagrams::xml_datagrams::XML_Parameter_Channel& parameters) const;

    size_t get_pulse_duration_index(float pulse_duration, bool fm) const;

    // ----- interface -----
    bool is_initialized() const { return _initialized; }

    void check_initialized() const;

    float get_impedance_factor() const;

    // ----- getters -----
    const datagrams::xml_datagrams::XML_Configuration_Transceiver& get_transceiver() const;
    const datagrams::xml_datagrams::XML_Configuration_Transceiver_Channel& get_transceiver_channel()
        const;
    const datagrams::xml_datagrams::XMLConfigurationTransceiverChannelTransducer& get_transducer()
        const;

    // stream i/o
    static TransceiverInformation from_stream(std::istream& is);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(TransceiverInformation)
};

/**
 * @brief Provide a boost hash function for TransceiverInformation
 * - Note: this is needed to use TransceiverInformation as boost::flyweight
 *
 * @param data
 * @return std::size_t
 */

// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_sub_hash_value
inline size_t hash_value(const TransceiverInformation& data)
{
    return data.binary_hash();
}

} // namespace _sub
} // namespace filedatatypes
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping