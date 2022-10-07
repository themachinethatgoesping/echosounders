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
class SimradPing : public fileinterfaces::I_Ping
{
    double      timestamp;
    std::string channel;
    std::string file_path;
    size_t      file_nr;
    size_t      ping_number;

    std::shared_ptr<SimradPingInterface<t_ifstream>> _ping_interface;

  public:
    SimradPing(std::shared_ptr<SimradPingInterface<t_ifstream>>         ping_interface,
         const fileinterfaces::PackageInfo<t_SimradDatagramType>& package_info)
        : _ping_interface(ping_interface)
    {
      timestamp = package_info.timestamp;

    }
    virtual ~SimradPing() = default;

    //------ interface ------//
    // virtual xt::xtensor<float, 2> get_SV() = 0;
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping