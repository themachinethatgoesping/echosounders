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
#include "i_filedatainterface_perfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datainterfaces {

template<typename t_filedatainterface_perfile>
class I_FileDataInterface
{
    std::string_view _name;

  public:
    // member types
    using type_FileDataInterface_PerFile = t_filedatainterface_perfile;
    using type_DatagramInterface    = typename type_FileDataInterface_PerFile::type_DatagramInterface;

  protected:
    std::string_view get_name() const { return _name; }

    std::vector<std::shared_ptr<t_filedatainterface_perfile>> _interface_per_file;
    tools::pyhelper::PyIndexer                           _pyindexer;

  public:
    I_FileDataInterface(std::string_view name = "I_FileDataInterface")
        : _name(name)
        , _pyindexer(0)
    {
    }
    virtual ~I_FileDataInterface() = default;

    virtual void add_file_interface(size_t file_nr)
    {
        if (file_nr >= this->_interface_per_file.size())
        {
            this->_interface_per_file.reserve(file_nr + 1);

            for (size_t i = this->_interface_per_file.size(); i <= file_nr; ++i)
            {
                this->_interface_per_file.push_back(std::make_shared<t_filedatainterface_perfile>());
            }
            this->_pyindexer.reset(this->_interface_per_file.size());
        }
    }

    // void add_datagram(datatypes::DatagramInfo_ptr<t_DatagramIdentifier, t_ifstream> datagram)
    template<typename t_DatagramInfo_ptr>
    void add_datagram_info(const t_DatagramInfo_ptr& datagram_info)
    {
        auto file_nr = datagram_info->get_file_nr();
        add_file_interface(file_nr);

        this->_interface_per_file[file_nr]->add_datagram_info(datagram_info);
        deinitialize();
    }

    // const std::vector<std::shared_ptr<t_filedatainterface_perfile>>& per_file() { return
    // _interface_per_file; }

    t_filedatainterface_perfile& per_file(long pyindex)
    {
        return *_interface_per_file[_pyindexer(pyindex)];
    }
    const t_filedatainterface_perfile& per_file_const(long pyindex) const
    {
        return *_interface_per_file[_pyindexer(pyindex)];
    }

    void init_from_file(bool force = false, bool show_progress = true)
    {
        tools::progressbars::ProgressBarChooser progress_bar(show_progress);
        this->init_from_file(force, progress_bar.get());
    }

    virtual void init_from_file(bool force, tools::progressbars::I_ProgressBar& progress_bar)
    {
        // const auto just means that the shared_ptr does not get copied
        // but the object it points is not const
        bool existing_progressbar = true;

        if (!progress_bar.is_initialized())
        {
            progress_bar.init(0.,
                              double(_interface_per_file.size()),
                              fmt::format("Initializing {} from file data", _name));

            existing_progressbar = false;
        }

        for (const auto& inter : _interface_per_file)
        {
            progress_bar.set_postfix(
                fmt::format("{}/{}", inter->get_file_nr(), _interface_per_file.size()));
            inter->init_from_file(force);

            if (!existing_progressbar)
                progress_bar.tick();
        }

        if (!existing_progressbar)
            progress_bar.close(std::string("Done"));
    }

    virtual void deinitialize()
    {
        for (std::shared_ptr<t_filedatainterface_perfile>& inter : this->_interface_per_file)
        {
            inter->deinitialize();
        }
    }

    virtual bool initialized() const
    {
        for (const std::shared_ptr<t_filedatainterface_perfile>& inter : this->_interface_per_file)
        {
            if (!inter->initialized())
            {
                return false;
            }
        }

        return true;
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

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping