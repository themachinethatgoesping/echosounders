// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/systeminformation.doc.hpp"

/* std includes */
#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

/* boost includes */
#include <boost/flyweight.hpp>

#include <xxhash.hpp>

#include <themachinethatgoesping/algorithms/signalprocessing/datastructures.hpp>

#include "../../datagrams/sonarsettings.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {
namespace _sub {

/**
 * @brief Record-wide system settings of a ping, extracted from the 7000 SonarSettings record.
 *
 * All fields are small scalars that are constant for a given sonar configuration, so the whole
 * structure is held as a flyweight (identical configurations across pings are stored once). 6
 * contiguous floats -> no padding, so the raw bytes are used for serialization and hashing.
 *
 * Note this is a private substructure and thus not part of the public API or nanobind interface.
 */
class _SysInfos
{
    float _frequency          = 0.f; ///< transmit frequency (Hz)
    float _receiver_bandwidth = 0.f; ///< receiver bandwidth (Hz)
    float _tx_pulse_width     = 0.f; ///< transmit pulse length (s)
    float _sound_velocity     = 0.f; ///< sound velocity (m/s)
    float _spreading          = 0.f; ///< spreading loss / applied TVG log factor
    float _absorption         = 0.f; ///< absorption (dB/km, as stored in the 7000 record)

  public:
    static constexpr std::size_t __binary_size = 6 * sizeof(float);

    _SysInfos() = default;

    explicit _SysInfos(const datagrams::SonarSettings& sonar_settings);

    bool operator==(const _SysInfos& other) const = default;

    float get_frequency() const { return _frequency; }
    float get_receiver_bandwidth() const { return _receiver_bandwidth; }
    float get_tx_pulse_width() const { return _tx_pulse_width; }
    float get_sound_velocity() const { return _sound_velocity; }
    float get_spreading() const { return _spreading; }
    float get_absorption() const { return _absorption; }

    static _SysInfos from_binary(std::string_view buffer);
    std::string      to_binary() const;
};

// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_hash_value
inline std::size_t hash_value(const _SysInfos& data)
{
    return xxh::xxhash3<64>(&data, _SysInfos::__binary_size);
}

/**
 * @brief Lightweight system information of a single s7k ping (7000 SonarSettings).
 *
 * Provides the transmit signal parameters (a single CW sector for s7k) and the scalars needed to
 * build the water-column calibration (sound velocity, pulse duration, applied TVG factor,
 * absorption). The 7000 record itself is not retained; identical configurations are deduplicated
 * via the _SysInfos flyweight.
 *
 * Note this is a private substructure and thus not part of the public API or nanobind interface.
 */
class SystemInformation
{
    boost::flyweights::flyweight<_SysInfos> _sysinfos;

    SystemInformation() = default; // for from_stream

  public:
    explicit SystemInformation(const datagrams::SonarSettings& sonar_settings);

    bool operator==(const SystemInformation& other) const = default;

    // ----- transmit signal parameters (single CW sector for s7k) -----
    std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>
    get_tx_signal_parameters() const
    {
        namespace sp = algorithms::signalprocessing::datastructures;
        std::vector<sp::TxSignalParameters> parameters;
        parameters.push_back(sp::CWSignalParameters(_sysinfos.get().get_frequency(),
                                                    _sysinfos.get().get_receiver_bandwidth(),
                                                    _sysinfos.get().get_tx_pulse_width()));
        return parameters;
    }

    size_t get_number_of_tx_sectors() const { return 1; }

    // ----- calibration inputs -----
    float get_sound_velocity() const { return _sysinfos.get().get_sound_velocity(); }
    float get_pulse_duration() const { return _sysinfos.get().get_tx_pulse_width(); }
    /// applied TVG log-range factor ("spreading": 0 / 20 / 40)
    float get_tvg_factor() const { return _sysinfos.get().get_spreading(); }
    /// absorption to (un)apply in dB/m (7000 absorption is dB/km)
    float get_absorption_db_m() const { return _sysinfos.get().get_absorption() * 0.001f; }

    // ----- functions used for PackageCache -----
    void to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const;

    static SystemInformation from_stream(
        std::istream&                                  is,
        const std::unordered_map<size_t, std::string>& hash_cache);
};

} // namespace _sub
} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
