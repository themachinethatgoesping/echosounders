// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallenvironmentdatainterfaceperfile.doc.hpp"

/* std includes */
#include <algorithm>
#include <memory>
#include <vector>

/* library includes */
#include <boost/flyweight.hpp>
#include <fmt/core.h>
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "../../filetemplates/datainterfaces/i_environmentdatainterface.hpp"
#include "kongsbergallconfigurationdatainterface.hpp"

#include "../types.hpp"
#include "../datagrams.hpp"
#include "kongsbergalldatagraminterface.hpp"
#include "kongsbergallnavigationdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KongsbergAllEnvironmentDataInterfacePerFile
    : public filetemplates::datainterfaces::I_EnvironmentDataInterfacePerFile<
          KongsbergAllNavigationDataInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_EnvironmentDataInterfacePerFile<
        KongsbergAllNavigationDataInterface<t_ifstream>>;

    bool _soundspeed_profiles_initialized = false;

    /// Sound speed profile datagrams found in this file, sorted by profile timestamp
    std::vector<boost::flyweight<datagrams::SoundSpeedProfileDatagram>> _soundspeed_profiles;

    /// Cached profile timestamps for fast binary search (avoid flyweight dereference)
    std::vector<double> _soundspeed_profile_timestamps;

  public:
    KongsbergAllEnvironmentDataInterfacePerFile()
        : t_base("KongsbergAllEnvironmentDataInterfacePerFile")
    {
    }
    KongsbergAllEnvironmentDataInterfacePerFile(
        std::shared_ptr<KongsbergAllNavigationDataInterface<t_ifstream>> navigation_data_interface)
        : t_base(std::move(navigation_data_interface), "KongsbergAllEnvironmentDataInterfacePerFile")
    {
    }
    ~KongsbergAllEnvironmentDataInterfacePerFile() = default;

    // environment::EnvironmentInterpolatorLatLon read_environment_data() const final
    // {
    //     return navi;
    // }

    // --------------------- kongsbergall specific functions ---------------------
    /* get infos */

    /**
     * @brief Read all SoundSpeedProfileDatagrams registered for this file and
     * cache them sorted by their profile timestamp.
     *
     * This function is automatically called by get_soundspeed_profile.
     */
    void init_soundspeed_profiles()
    {
        if (_soundspeed_profiles_initialized)
            return;

        _soundspeed_profiles.clear();
        _soundspeed_profile_timestamps.clear();

        for (const auto& datagram_ptr :
             this->_datagram_infos_by_type[t_KongsbergAllDatagramIdentifier::SoundSpeedProfileDatagram])
        {
            _soundspeed_profiles.emplace_back(
                datagram_ptr->template read_datagram_from_file<datagrams::SoundSpeedProfileDatagram>());
        }

        // sort by profile timestamp (the profile_date + profile_time_since_midnight)
        std::sort(_soundspeed_profiles.begin(),
                  _soundspeed_profiles.end(),
                  [](const auto& a, const auto& b) {
                      return a.get().get_profile_timestamp() < b.get().get_profile_timestamp();
                  });

        _soundspeed_profile_timestamps.reserve(_soundspeed_profiles.size());
        for (const auto& fw : _soundspeed_profiles)
            _soundspeed_profile_timestamps.push_back(fw.get().get_profile_timestamp());

        _soundspeed_profiles_initialized = true;
    }

    /**
     * @brief Check whether at least one SoundSpeedProfileDatagram is available for this file.
     */
    bool has_soundspeed_profiles()
    {
        if (!_soundspeed_profiles_initialized)
            this->init_soundspeed_profiles();
        return !_soundspeed_profiles.empty();
    }

    /**
     * @brief Return the latest SoundSpeedProfileDatagram with profile timestamp <= ping_time.
     *
     * If all known profiles are newer than ping_time, the first (oldest) profile is returned.
     * Throws if no profile is available for this file.
     *
     * @param ping_time   Ping timestamp (unix seconds).
     * @param last_index  Stateful search hint (per ping stream) to avoid re-scanning.
     */
    boost::flyweight<datagrams::SoundSpeedProfileDatagram> get_soundspeed_profile(
        double                  ping_time,
        std::shared_ptr<size_t> last_index = std::make_shared<size_t>(0))
    {
        if (!_soundspeed_profiles_initialized)
            this->init_soundspeed_profiles();

        if (!last_index)
            last_index = std::make_shared<size_t>(0);

        if (_soundspeed_profiles.empty())
            throw std::runtime_error(fmt::format(
                "get_soundspeed_profile: No SoundSpeedProfileDatagram available in file nr {} [{}]",
                this->get_file_nr(),
                this->get_file_path()));

        if (*last_index >= _soundspeed_profiles.size())
            *last_index = 0;

        // binary search for largest profile timestamp <= ping_time
        auto it = std::upper_bound(
            _soundspeed_profile_timestamps.begin() + static_cast<ptrdiff_t>(*last_index),
            _soundspeed_profile_timestamps.end(),
            ping_time);

        size_t i;
        if (it == _soundspeed_profile_timestamps.begin())
            i = 0; // ping_time is before all profiles -> use first
        else
            i = static_cast<size_t>(
                    std::distance(_soundspeed_profile_timestamps.begin(), it)) -
                1;

        *last_index = i;
        return _soundspeed_profiles[i];
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("KongsbergAllEnvironmentDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
