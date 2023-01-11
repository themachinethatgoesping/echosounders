// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_filedatainterface_perfile.doc.hpp"

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
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datainterfaces {

// TODO: this should be a c++20 concept
template<typename t_datagraminterface>
class I_FileDataInterface_PerFile : public t_datagraminterface
{
    using t_base = t_datagraminterface;

  public:
    using type_DatagramInterface = t_datagraminterface;

  public:
    I_FileDataInterface_PerFile(std::string_view name = "I_FileDataInterface_PerFile")
        : t_base(name)
    {
    }
    virtual ~I_FileDataInterface_PerFile() = default;

    virtual void init_from_file([[maybe_unused]] bool force = false)
    {
        // this file does not need to be initialized
        return;
    }

    virtual void deinitialize()
    {
        // this file does not need to be deinitialized
        return;
    }

    virtual bool initialized() const
    {
        // this file is always initialized
        return true;
    }

    /**
     * @brief Get the file nr
     * This function assumes that the file nr is the same for all datagrams in the file
     *
     * @return size_t
     */
    size_t get_file_nr() const
    {
        if (this->_datagram_infos_all.empty())
            throw std::runtime_error("get_file_nr: no datagrams in file");

        return this->_datagram_infos_all[0]->get_file_nr();
    }

    /**
     * @brief Get the file name
     * This function assumes that the file name is the same for all datagrams in the file
     *
     * @return std::string
     */
    std::string get_file_path() const
    {
        if (this->_datagram_infos_all.empty())
            throw std::runtime_error("get_file_name: no datagrams in file");
        return this->_datagram_infos_all[0]->get_file_path();
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("File infos");
        printer.register_string("File", this->get_file_path(), std::to_string(this->get_file_nr()));
        return printer;
    }
};
// void add_datagram(datatypes::DatagramInfo_ptr<t_Datagram

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping