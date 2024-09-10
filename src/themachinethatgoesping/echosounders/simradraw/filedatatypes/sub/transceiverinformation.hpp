// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/transceiverinformation.doc.hpp"

/* boost includes */
#include <boost/flyweight.hpp>
#include <boost/flyweight/key_value.hpp>

// xtensor includes
#include <themachinethatgoesping/tools/classhelper/xxhashhelper.hpp>
#include <themachinethatgoesping/tools/hashhelper.hpp>

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
            ping_transceiver_channel)
        : _ping_transceiver(ping_transceiver)
        , _ping_transceiver_channel(ping_transceiver_channel)
    {

        float transducer_impedance  = 75; // ohm TODO: is this always 75 ohm?
        float transceiver_impedance = _ping_transceiver.Impedance;

        //_impedance factor is ((ztransceiver + ztransducer) / ztransceiver)² * 1/ tdi *
        // 1/(2*sqrt(2))²
        _impedance_factor = (transceiver_impedance + transducer_impedance) / transceiver_impedance;
        _impedance_factor *= _impedance_factor;
        _impedance_factor /= transducer_impedance;
        _impedance_factor /= 8;

        _initialized = true;
    }

    bool operator==(const TransceiverInformation& other) const = default;

    size_t get_pulse_duration_index(float pulse_duration, bool fm) const
    {
        check_initialized();

        auto pulse_durations = _ping_transceiver_channel.get_pulse_durations(fm);

        for (size_t index = 0; index < pulse_durations.size(); ++index)
        {
            if (std::abs(pulse_durations[index] - pulse_duration) < 1e-6)
                return index;
        }

        throw std::runtime_error(
            fmt::format("ERROR[{}]: Pulse duration {} not found in transceiver information",
                        __func__,
                        pulse_duration));
    }

    // ----- interface -----
    bool is_initialized() const { return _initialized; }

    void check_initialized() const
    {
        if (!_initialized)
            throw std::runtime_error("TransceiverInformation not initialized");
    }

    float get_impedance_factor() const
    {
        check_initialized();
        return _impedance_factor;
    }

    // ----- getters -----
    const datagrams::xml_datagrams::XML_Configuration_Transceiver& get_transceiver() const
    {
        check_initialized();
        return _ping_transceiver;
    }
    const datagrams::xml_datagrams::XML_Configuration_Transceiver_Channel& get_transceiver_channel()
        const
    {
        check_initialized();
        return _ping_transceiver_channel;
    }
    const datagrams::xml_datagrams::XMLConfigurationTransceiverChannelTransducer& get_transducer()
        const
    {
        check_initialized();
        return _ping_transceiver_channel.Transducer;
    }

    xxh::hash_t<64> binary_hash() const
    {
        xxh::hash3_state_t<64>               hash;
        boost::iostreams::stream<XXHashSink> stream(hash);
        _ping_transceiver.to_stream(stream);
        _ping_transceiver_channel.to_stream(stream);
        stream.flush();
        return hash.digest();
    }
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

} // namespace substructures
} // namespace filedatatypes
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping