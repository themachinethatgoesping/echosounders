// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "systeminformation.hpp"

#include <cstring>
#include <ostream>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {
namespace _sub {

// ----- _SysInfos -----

_SysInfos::_SysInfos(const datagrams::SonarSettings& sonar_settings)
{
    _frequency          = sonar_settings.get_frequency();
    _receiver_bandwidth = sonar_settings.get_receiver_bandwidth();
    _tx_pulse_width     = sonar_settings.get_tx_pulse_width();
    _sound_velocity     = sonar_settings.get_sound_velocity();
    _spreading          = sonar_settings.get_spreading();
    _absorption         = sonar_settings.get_absorption();
    _power_selection    = sonar_settings.get_power_selection();
    _gain_selection     = sonar_settings.get_gain_selection();
    _tx_pulse_type      = uint32_t(sonar_settings.get_tx_pulse_type().value);
}

_SysInfos _SysInfos::from_binary(std::string_view buffer)
{
    _SysInfos dat;
    // copy via the first member (scalar pointer), mirroring _WCIInfos, to stay padding-safe and
    // clear of -Wclass-memaccess if a non-4-byte member is ever added.
    std::memcpy(&dat._frequency, buffer.data(), __binary_size);
    return dat;
}

std::string _SysInfos::to_binary() const
{
    std::string buffer;
    buffer.resize(__binary_size);
    std::memcpy(buffer.data(), &_frequency, __binary_size);
    return buffer;
}

// ----- SystemInformation -----

SystemInformation::SystemInformation(const datagrams::SonarSettings& sonar_settings)
    : _sysinfos(_SysInfos(sonar_settings))
{
}

void SystemInformation::to_stream(std::ostream&                            os,
                                  std::unordered_map<size_t, std::string>& hash_cache) const
{
    const size_t hash = hash_value(_sysinfos.get());

    if (!hash_cache.contains(hash))
        hash_cache[hash] = _sysinfos.get().to_binary();

    os.write(reinterpret_cast<const char*>(&hash), sizeof(size_t));
    // match-filter effective pulse duration (per ping, cached so the 7002 record is not re-read)
    os.write(reinterpret_cast<const char*>(&_mf_effective_pulse_duration), sizeof(float));
}

SystemInformation SystemInformation::from_stream(
    std::istream&                                  is,
    const std::unordered_map<size_t, std::string>& hash_cache)
{
    size_t hash;
    is.read(reinterpret_cast<char*>(&hash), sizeof(size_t));

    SystemInformation dat;
    is.read(reinterpret_cast<char*>(&dat._mf_effective_pulse_duration), sizeof(float));

    static thread_local std::unordered_map<size_t, boost::flyweights::flyweight<_SysInfos>>
        fw_cache_sysinfos;

    if (auto it = fw_cache_sysinfos.find(hash); it != fw_cache_sysinfos.end())
    {
        dat._sysinfos = it->second;
    }
    else
    {
        dat._sysinfos = _SysInfos::from_binary(hash_cache.at(hash));
        fw_cache_sysinfos.emplace(hash, dat._sysinfos);
    }

    return dat;
}

} // namespace _sub
} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
