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
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "i_inputfileiterator.hpp"
#include "i_navigationdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

// using NavInterpolator_ptr = std::shared_ptr<navigation::NavigationInterpolatorLatLon>;

// template<typename t_DatagramIdentifier,
//          typename t_ifstream>
// class I_NavigationInterface
// {
//     std::string _name;
//     std::vector<std::shared_ptr<I_NavigationDataInterface<t_DatagramIdentifier,t_ifstream>>>
//     _navigation_data_interfaces;

// protected:
//     void add_package_info(const PackageInfo_ptr<t_DatagramIdentifier>& package_info)
//     {
//         file_data(package_info->file_nr)->add_package_info(package_info);
//     }

//     public:
//     I_NavigationInterface(std::shared_ptr<std::vector<std::string>> file_paths,
//                           std::string_view                          name = "Default")
//         : _name(name)
//         , _file_paths(std::move(file_paths))
//     {
//     }
//     virtual ~I_NavigationInterface() = default;

//     const std::shared_ptr<I_NavigationDataInterface<t_DatagramIdentifier,t_ifstream>>&
//     data_ptr(size_t file_cnt)
//     {
//         while (file_cnt >= _navigation_data_interfaces.size())
//         {
//             _navigation_data_interfaces.push_back(std::make_shared<I_NavigationDataInterface<t_DatagramIdentifier,t_ifstream>>());
//         }

//         return _navigation_data_interfaces[file_cnt];
//     }

//     const I_NavigationDataInterface<t_DatagramIdentifier,t_ifstream>& data(size_t file_cnt)
//     {
//         return *data_ptr(file_cnt);
//     }

// };

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping