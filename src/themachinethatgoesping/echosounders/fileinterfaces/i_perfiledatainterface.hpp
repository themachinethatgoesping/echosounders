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
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

// TODO: this should be a c++20 concept
template<typename t_datagraminterface>
class I_PerFileDataInterface : public t_datagraminterface
{
    using t_base = t_datagraminterface;

  public:
    I_PerFileDataInterface(std::string_view name = "I_PerFileDataInterface")
        : t_base(name)
    {
    }
    virtual ~I_PerFileDataInterface() = default;

    virtual void init_from_file()
    {
        try
        {
            throw std::runtime_error(
                fmt::format("Warning[init_from_file]: Not implemented for {} class.file "
                            "{}: {}. Using empty fallback file.",
                            this->get_name(),
                            this->get_file_nr(),
                            this->get_file_path()));
        }
        catch (std::exception& e2)
        {
            throw std::runtime_error(
                fmt::format("Warning[init_from_file]: Not implemented for {} class. Also: Could "
                            "not read datagrams from file: Error was: {}",
                            this->get_name(),
                            e2.what()));
        }
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
// void add_datagram(DatagramInfo_ptr<t_Datagram

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping