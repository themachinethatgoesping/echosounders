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

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

using NavInterpolator_ptr = std::shared_ptr<navigation::NavigationInterpolatorLatLon>;

template<typename t_DatagramIdentifier,
         typename t_ifstream>
class I_NavigationDataInterface
{
    std::string _name;

    /* some file information */
    std::shared_ptr<std::vector<std::string>> _file_paths =
        std::make_shared<std::vector<std::string>>();

    /* header positions */
    std::shared_ptr<std::vector<PackageInfo_ptr<t_DatagramIdentifier>>> _package_infos_all =
        std::make_shared<std::vector<PackageInfo_ptr<t_DatagramIdentifier>>>();
    tools::helper::DefaultSharedPointerMap<t_DatagramIdentifier,
                                           std::vector<PackageInfo_ptr<t_DatagramIdentifier>>>
        _package_infos_by_type;

  protected:
    void add_package_info(const PackageInfo_ptr<t_DatagramIdentifier>& package_info) 
    {
        _package_infos_all->push_back(package_info);
        _package_infos_by_type.at(package_info->datagram_identifier)->push_back(package_info);
    }

  public:
    I_NavigationDataInterface(std::shared_ptr<std::vector<std::string>> file_paths,
                          std::string_view                          name = "Default")
        : _name(name)
        , _file_paths(std::move(file_paths))
    {
    }
    virtual ~I_NavigationDataInterface() = default;

    // void add_ping(const std::shared_ptr<t_Ping> ping) { this->_pings->push_back(ping); }

    // const std::shared_ptr<NavigationVector>& get_pings() const { return _pings; }

    // ----- compute ping information -----

    // ----- iterator interface -----
    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
    get_iterator(t_DatagramIdentifier datagram_identifier) const
    {
        return I_InputFileIterator<t_DatagramType,
                                   t_DatagramIdentifier,
                                   t_ifstream,
                                   t_DatagramTypeFactory>(
            _file_paths, _package_infos_by_type.at_const(datagram_identifier));
    }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
    get_iterator(t_DatagramIdentifier datagram_identifier,
                 long                 index_min,
                 long                 index_max,
                 long                 index_step) const
    {
        return I_InputFileIterator<t_DatagramType,
                                   t_DatagramIdentifier,
                                   t_ifstream,
                                   t_DatagramTypeFactory>(
            _file_paths,
            _package_infos_by_type.at_const(datagram_identifier),
            index_min,
            index_max,
            index_step);
    }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
    get_iterator() const
    {
        return I_InputFileIterator<t_DatagramType,
                                   t_DatagramIdentifier,
                                   t_ifstream,
                                   t_DatagramTypeFactory>(_file_paths, _package_infos_all);
    }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>
    get_iterator(long index_min, long index_max, long index_step) const
    {
        return I_InputFileIterator<t_DatagramType,
                                   t_DatagramIdentifier,
                                   t_ifstream,
                                   t_DatagramTypeFactory>(
            _file_paths, _package_infos_all, index_min, index_max, index_step);
    }
};


} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping