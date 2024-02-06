// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_filedatainterface.doc.hpp"

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
#include "i_filedatainterfaceperfile.hpp"

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
    using type_DatagramInterface = typename type_FileDataInterface_PerFile::type_DatagramInterface;

  protected:
    std::string_view class_name() const { return _name; }

    std::vector<std::shared_ptr<t_filedatainterface_perfile>> _interface_per_file;
    tools::pyhelper::PyIndexer                                _pyindexer;

  public:
    I_FileDataInterface(std::string_view name = "I_FileDataInterface")
        : _name(name)
        , _pyindexer(0)
    {
    }
    virtual ~I_FileDataInterface() = default;

    virtual void add_file_information(const std::shared_ptr<std::vector<std::string>>& file_paths)
    {
        for (unsigned int i = 0; i < file_paths->size(); ++i)
        {
            add_file_interface(i);
            per_file(i).add_file_information(i, file_paths->at(i));
        }
    }

    virtual void add_file_interface(size_t file_nr)
    {
        if (file_nr >= this->_interface_per_file.size())
        {
            this->_interface_per_file.reserve(file_nr + 1);

            for (size_t i = this->_interface_per_file.size(); i <= file_nr; ++i)
            {
                this->_interface_per_file.push_back(
                    std::make_shared<t_filedatainterface_perfile>());
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

    static std::vector<std::shared_ptr<t_filedatainterface_perfile>> sort_by_time(
        std::vector<std::shared_ptr<t_filedatainterface_perfile>> interfaces)
    {
        boost::sort::pdqsort(
            interfaces.begin(), interfaces.end(), [](const auto& lhs, const auto& rhs) {
                if (lhs->get_timestamp_first() < rhs->get_timestamp_first())
                    return true;
                return false;
            });

        return interfaces;
    }

    /**
     * @brief get a vector with references to the per file interfaces
     * This is useful for iterating over all files
     *
     * @return std::vector<t_filedatainterface_perfile&>
     */
    std::vector<std::shared_ptr<t_filedatainterface_perfile>> per_file()
    {
        return _interface_per_file;
    }

    /**
     * @brief get a vector with references to the primary per file interfaces
     * This is useful for iterating over all primary files
     * Secondary files will be ignored (e.g. .wcd for Kongsberg data if .all is present)
     *
     * @return std::vector<t_filedatainterface_perfile&>
     */
    std::vector<std::shared_ptr<t_filedatainterface_perfile>> per_primary_file() const
    {
        std::vector<std::shared_ptr<t_filedatainterface_perfile>> primary_files;
        for (const auto& file : _interface_per_file)
        {
            if (file->is_primary_file())
                primary_files.push_back(file);
        }

        return primary_files;
    }

    /**
     * @brief get a vector with references to the secondary per file interfaces
     * This is useful for iterating over all secondary files
     * Primary files will be ignored (e.g. .all for Kongsberg data if .wcd is present)
     *
     * @return std::vector<t_filedatainterface_perfile&>
     */
    std::vector<std::shared_ptr<t_filedatainterface_perfile>> per_secondary_file() const
    {
        std::vector<std::shared_ptr<t_filedatainterface_perfile>> secondary_files;
        for (const auto& file : _interface_per_file)
        {
            if (file->is_secondary_file())
                secondary_files.push_back(file);
        }
        return secondary_files;
    }

    t_filedatainterface_perfile& per_file(long pyindex)
    {
        return *_interface_per_file[_pyindexer(pyindex)];
    }
    const t_filedatainterface_perfile& per_file_const(long pyindex) const
    {
        return *_interface_per_file[_pyindexer(pyindex)];
    }
    const std::shared_ptr<t_filedatainterface_perfile>& per_file_ptr(long pyindex)
    {
        return _interface_per_file[_pyindexer(pyindex)];
    }

    void init_from_file(
        const std::unordered_map<std::string, std::string>& cached_paths_per_file_path,
        bool                                                force         = false,
        bool                                                show_progress = true)
    {
        tools::progressbars::ProgressBarChooser progress_bar(show_progress);
        this->init_from_file(cached_paths_per_file_path, force, progress_bar.get());
    }

    virtual void init_from_file(
        const std::unordered_map<std::string, std::string>& cached_paths_per_file_path,
        bool                                                force,
        tools::progressbars::I_ProgressBar&                 progress_bar,
        bool                                                external_progress_tick = false)
    {
        // const auto just means that the shared_ptr does not get copied
        // but the object it points is not const
        bool existing_progressbar = true;

        auto primary_interfaces_per_file = this->per_primary_file();

        if (!progress_bar.is_initialized())
        {
            progress_bar.init(0.,
                              double(primary_interfaces_per_file.size()),
                              fmt::format("Initializing {} from file data", _name));

            existing_progressbar = false;
        }

        for (const auto& inter : primary_interfaces_per_file)
        {
            progress_bar.set_postfix(
                fmt::format("{}/{}", inter->get_file_nr(), primary_interfaces_per_file.size()));

            std::string cache_file_path = "";
            if (cached_paths_per_file_path.find(inter->get_file_path()) !=
                cached_paths_per_file_path.end())
            {
                cache_file_path = cached_paths_per_file_path.at(inter->get_file_path());
            }
            inter->init_from_file(cache_file_path, force);

            if (!existing_progressbar || external_progress_tick)
                progress_bar.tick();
        }

        if (!existing_progressbar)
            progress_bar.close(std::string("Done"));
    }

    /**
     * @brief This functions throws if linked file interfaces are not consistent
     *
     */
    virtual void verify_linked_file_interfaces_are_consistent() { return; }

    virtual void deinitialize()
    {
        for (std::shared_ptr<t_filedatainterface_perfile>& inter : this->_interface_per_file)
        {
            inter->deinitialize();
        }
    }

    virtual bool is_initialized() const
    {
        for (const std::shared_ptr<t_filedatainterface_perfile>& inter : this->_interface_per_file)
        {
            if (!inter->is_initialized())
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
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        auto primary_files   = this->per_primary_file();
        auto secondary_files = this->per_secondary_file();

        if (secondary_files.empty())
            printer.register_value("Registered files", _interface_per_file.size());
        else
        {
            printer.register_value("Registered primary files", primary_files.size());
            printer.register_value("Registered secondary files", secondary_files.size());
        }
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