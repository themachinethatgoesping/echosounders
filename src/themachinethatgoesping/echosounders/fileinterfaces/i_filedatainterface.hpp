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

#include "i_packagedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {


template<typename t_packagedatainterface>
class I_FileDataInterface
{
    std::string _name;

  protected:

    std::vector<t_packagedatainterface>        _package_data_interface_per_file;
    tools::pyhelper::PyIndexer _pyindexer;

  public:
    I_FileDataInterface(std::string_view name = "Default")
        : _name(name)
        , _pyindexer(0)
    {
    }
    virtual ~I_FileDataInterface() = default;

    //void add_package(PackageInfo_ptr<t_DatagramIdentifier, t_ifstream> package)
    template<typename t_PackageInfo_ptr>
    void add_package_info(const t_PackageInfo_ptr& package_info)
    {
        auto file_nr = package_info->get_file_nr();

        if (file_nr >= _package_data_interface_per_file.size())
        {
            _package_data_interface_per_file.resize(file_nr + 1);
            this->_pyindexer.reset(this->_package_data_interface_per_file.size());
        }

        this->_package_data_interface_per_file[file_nr].add_package_info(package_info);
    }

    const std::vector<t_packagedatainterface>& package_data_interface_per_file() const { return _package_data_interface_per_file; }
    // const t_packagedatainterface& package_data_interface_per_file(long index) const { return _package_data_interface_per_file[_pyindexer(index)]; }
    // size_t size() const { return _package_data_interface_per_file.size(); }

};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping