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

template<typename t_ifstream = std::ifstream>
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
};

template<typename t_ifstream = std::ifstream>
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
        : _raw(std::move(ping_interface), std::move(package_info_raw), std::move(ping_data))
    {
        //timestamp = package_info_raw.timestamp;
    }
    virtual ~SimradPing() = default;

    const SimradPingRawData<t_ifstream>& raw() const { return _raw; }



    //------ interface ------//
    // virtual xt::xtensor<float, 2> get_SV() = 0;
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping