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

// themachinethatgoesping includes
#include <themachinethatgoesping/tools/classhelper/xxhashhelper.hpp>
#include <themachinethatgoesping/tools/hashhelper.hpp>

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
            ping_transceiver_channel)
        : _ping_transceiver(ping_transceiver)
        , _ping_transceiver_channel(ping_transceiver_channel)
    {
        _impedance_factor = compute_impedance_factor(_ping_transceiver.Impedance, 75);

        _initialized = true;
    }

    static float compute_impedance_factor(float transceiver_impedance,
                                          float transducer_impedance = 75)
    {
        //_impedance factor is ((ztransceiver + ztransducer) / ztransceiver)² * 1/ tdi *
        // 1/(2*sqrt(2))²
        float impedance_factor =
            (transceiver_impedance + transducer_impedance) / transceiver_impedance;
        impedance_factor *= impedance_factor;
        impedance_factor /= transducer_impedance;
        impedance_factor /= 8;

        return impedance_factor;
    }

    bool operator==(const TransceiverInformation& other) const
    {
        return _ping_transceiver == other._ping_transceiver &&
               _ping_transceiver_channel == other._ping_transceiver_channel &&
               _initialized == other._initialized &&
               tools::helper::float_equals(_impedance_factor, other._impedance_factor);
    }

    std::optional<size_t> get_pulse_duration_index_optional(
        const datagrams::xml_datagrams::XML_Parameter_Channel& parameters) const
    {
        return get_pulse_duration_index_optional(parameters.get_pulse_duration(),
                                                 parameters.get_pulse_form_is_fm());
    }

    std::optional<size_t> get_pulse_duration_index_optional(float pulse_duration, bool fm) const
    {
        check_initialized();

        auto pulse_durations = _ping_transceiver_channel.get_pulse_durations(fm);

        for (size_t index = 0; index < pulse_durations.size(); ++index)
        {
            if (std::abs(pulse_durations[index] - pulse_duration) < 1e-6)
                return index;
        }

        return std::nullopt;
    }

    size_t get_pulse_duration_index(
        const datagrams::xml_datagrams::XML_Parameter_Channel& parameters) const
    {
        return get_pulse_duration_index(parameters.get_pulse_duration(),
                                        parameters.get_pulse_form_is_fm());
    }

    size_t get_pulse_duration_index(float pulse_duration, bool fm) const
    {
        check_initialized();

        auto pulse_duration_index = get_pulse_duration_index_optional(pulse_duration, fm);

        if (pulse_duration_index.has_value())
            return pulse_duration_index.value();

        auto pulse_durations = _ping_transceiver_channel.get_pulse_durations(fm);

        std::string possible_durations = "";
        for (const auto& duration : pulse_durations)
            possible_durations += fmt::format("{}, ", duration);

        std::string mode = fm ? "FM" : "CW";

        throw std::runtime_error(fmt::format("ERROR[{}]: Pulse duration {} not found in "
                                             "transceiver information for {} mode. Possible "
                                             "durations: {}",
                                             __func__,
                                             pulse_duration,
                                             mode,
                                             possible_durations));
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

    // stream i/o
    static TransceiverInformation from_stream(std::istream& is)
    {
        TransceiverInformation tr_infos;

        tr_infos._ping_transceiver =
            datagrams::xml_datagrams::XML_Configuration_Transceiver::from_stream(is);
        tr_infos._ping_transceiver_channel =
            datagrams::xml_datagrams::XML_Configuration_Transceiver_Channel::from_stream(is);
        is.read(reinterpret_cast<char*>(&tr_infos._initialized), sizeof(tr_infos._initialized));
        is.read(reinterpret_cast<char*>(&tr_infos._impedance_factor),
                sizeof(tr_infos._impedance_factor));

        return tr_infos;
    }

    void to_stream(std::ostream& os) const
    {
        _ping_transceiver.to_stream(os);
        _ping_transceiver_channel.to_stream(os);
        os.write(reinterpret_cast<const char*>(&_initialized), sizeof(_initialized));
        os.write(reinterpret_cast<const char*>(&_impedance_factor), sizeof(_impedance_factor));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "TransceiverInformation", float_precision, superscript_exponents);

        printer.register_section("Transceiver datagrams");
        printer.register_value("Transceiver", _ping_transceiver.TransceiverName);
        printer.register_value("Transceiver Channel", _ping_transceiver_channel.ChannelID);

        printer.register_section("Impedance factor (for complex32 power conversion)");
        printer.register_value("transceiver_impedance", _ping_transceiver.Impedance, "Ohm");
        printer.register_value("transducer_impedance", 75, "Ohm [fixed]");
        printer.register_value("impedance_factor", _impedance_factor);

        return printer;
    }

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

} // namespace substructures
} // namespace filedatatypes
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping