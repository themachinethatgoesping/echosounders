// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* std includes */
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../fileinterfaces/i_ping.hpp"
#include "simradpinginterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
class SimradPingRawData
{
    const std::shared_ptr<SimradPingInterface<t_ifstream>> _ping_interface;

    fileinterfaces::PackageInfo<t_SimradDatagramType>
        _package_info_raw; ///< this can be RAW3 (EK80) or RAW0 (EK60)

  public:
    datagrams::RAW3
        _ping_data; ///< when implementing EK60, this must become a variant type (RAW3 or RAW0)

  public:
    SimradPingRawData(std::shared_ptr<SimradPingInterface<t_ifstream>>  ping_interface,
                      fileinterfaces::PackageInfo<t_SimradDatagramType> package_info_raw,
                      datagrams::RAW3                                   ping_data)
        : _ping_interface(std::move(ping_interface))
        , _package_info_raw(std::move(package_info_raw))
        , _ping_data(std::move(ping_data))
    {
    }

    // ----- load skipped data -----
    datagrams::RAW3_datatypes::RAW3_DataVariant sample_data()
    {
        return _ping_data.read_skipped_sample_data(
            _ping_interface->get_active_stream(_package_info_raw.file_nr),
            _package_info_raw.file_pos);
    }
};

template<typename t_ifstream>
class SimradPing : public fileinterfaces::I_Ping
{
    double      timestamp;
    std::string channel;
    std::string file_path;
    size_t      file_nr;
    size_t      ping_number;

    SimradPingRawData<t_ifstream> _raw;

  public:
    SimradPing(std::shared_ptr<SimradPingInterface<t_ifstream>>  ping_interface,
               fileinterfaces::PackageInfo<t_SimradDatagramType> package_info_raw,
               datagrams::RAW3                                   ping_data)
        : fileinterfaces::I_Ping("SimradPing")
        , _raw(std::move(ping_interface), std::move(package_info_raw), std::move(ping_data))
    {
        // timestamp = package_info_raw.timestamp;
    }
    virtual ~SimradPing() = default;

    const SimradPingRawData<t_ifstream>& raw() const { return _raw; }

    // ----- I_Ping interface -----
    size_t get_number_of_samples() const final
    {
        return _raw._ping_data.get_count();
    }

    xt::xtensor<float, 2> get_sv(bool dB = false) final
    {
        auto                  sample_data = _raw.sample_data();
        xt::xtensor<float, 1> sv =
            tools::helper::visit_variant(sample_data, [dB](auto& data) { return data.get_power(dB); });

        // convert sv to 2d xtensor and return
        return xt::view(sv, xt::newaxis(), xt::all());
    }

    xt::xtensor<float, 1> get_sv_stacked(bool dB = false) final
    {
        auto                  sample_data = _raw.sample_data();
        xt::xtensor<float, 1> sv =
            tools::helper::visit_variant(sample_data, [dB](auto& data) { return data.get_power(dB); });

        // convert sv to 2d xtensor and return
        return sv;
    }

    // xt::xtensor<float, 2> get_angle() const
    // {

    // }
    //------ interface ------//
    // virtual xt::xtensor<float, 2> get_SV() = 0;
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping