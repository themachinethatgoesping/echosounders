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

#include "i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_datagraminterface>
class I_FileDataInterface
{
    std::string _name;

  protected:
    std::vector<t_datagraminterface> _datagram_interface_per_file;
    tools::pyhelper::PyIndexer       _pyindexer;

  public:
    I_FileDataInterface(std::string_view name = "Default")
        : _name(name)
        , _pyindexer(0)
    {
    }
    virtual ~I_FileDataInterface() = default;

    // void add_datagram(DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream> datagram)
    template<typename t_DatagramInfo_ptr>
    void add_datagram_info(const t_DatagramInfo_ptr& datagram_info)
    {
        auto file_nr = datagram_info->get_file_nr();

        if (file_nr >= _datagram_interface_per_file.size())
        {
            _datagram_interface_per_file.resize(file_nr + 1);
            this->_pyindexer.reset(this->_datagram_interface_per_file.size());
        }

        this->_datagram_interface_per_file[file_nr].add_datagram_info(datagram_info);
    }

    const std::vector<t_datagraminterface>& datagram_interface_per_file() const
    {
        return _datagram_interface_per_file;
    }
    // const t_datagraminterface& datagram_interface_per_file(long index) const { return
    // _datagram_interface_per_file[_pyindexer(index)]; } size_t size() const { return
    // _datagram_interface_per_file.size(); }
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping