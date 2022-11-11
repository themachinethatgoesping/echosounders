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
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

#include "i_packagecontainer.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {


template<typename t_packagecontainer>
class I_EnvironmentDataInterface : public I_FileDataInterface<t_packagecontainer>
{

  public:
    I_EnvironmentDataInterface(std::string_view name = "I_EnvironmentDataInterface")
        : I_FileDataInterface<t_packagecontainer>(name)
    {
    }
    virtual ~I_EnvironmentDataInterface() = default;

    //void add_package_info(PackageInfo_ptr<t_DatagramIdentifier, t_ifstream> package)


};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping