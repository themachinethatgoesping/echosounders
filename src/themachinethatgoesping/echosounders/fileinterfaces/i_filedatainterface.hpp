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
#include "i_filedatacollection.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_filedatacollection>
class I_FileDataInterface
{
    std::string_view _name;

  protected:
    std::string_view get_name() const { return _name; }

    std::vector<t_filedatacollection> _interface_per_file;
    tools::pyhelper::PyIndexer        _pyindexer;

  public:
    I_FileDataInterface(std::string_view name = "I_FileDataInterface")
        : _name(name)
        , _pyindexer(0)
    {
    }
    virtual ~I_FileDataInterface() = default;

    void add_file_interface(size_t file_nr)
    {
        if (file_nr >= _interface_per_file.size())
        {
            _interface_per_file.resize(file_nr + 1);
            this->_pyindexer.reset(this->_interface_per_file.size());
        }
    }

    // void add_datagram(DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream> datagram)
    template<typename t_DatagramInfo_ptr>
    void add_datagram_info(const t_DatagramInfo_ptr& datagram_info)
    {
        auto file_nr = datagram_info->get_file_nr();
        add_file_interface(file_nr);

        this->_interface_per_file[file_nr].add_datagram_info(datagram_info);
    }

    const std::vector<t_filedatacollection>& per_file() { return _interface_per_file; }

    t_filedatacollection& per_file(long pyindex)
    {
        return _interface_per_file[_pyindexer(pyindex)];
    }

    void init_from_file()
    {
        for (auto& interface : this->_interface_per_file)
            interface.init_from_file();
    }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.register_value("Registered files", _interface_per_file.size());
        return printer;
    }

    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping