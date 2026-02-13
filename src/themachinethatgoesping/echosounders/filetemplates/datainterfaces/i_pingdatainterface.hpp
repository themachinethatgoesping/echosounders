// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_pingdatainterface.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <future>
#include <thread>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ostream.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include <themachinethatgoesping/tools/helper/defaultsharedpointermap.hpp>
#include <themachinethatgoesping/tools/helper/map_tools.hpp>

#include "i_datagraminterface.hpp"
#include "i_environmentdatainterface.hpp"
#include "i_filedatainterface.hpp"
#include "i_pingdatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datainterfaces {

template<typename t_PingDataInterfacePerFile>
class I_PingDataInterface : public I_FileDataInterface<t_PingDataInterfacePerFile>
{
    using t_base = I_FileDataInterface<t_PingDataInterfacePerFile>;

  public:
    // member types
    using type_PingDataInterfacePerFile = t_PingDataInterfacePerFile;
    using type_ConfigurationDataInterface =
        typename t_PingDataInterfacePerFile::type_ConfigurationDataInterface;
    using type_NavigationDataInterface =
        typename t_PingDataInterfacePerFile::type_NavigationDataInterface;
    using type_EnvironmentDataInterface =
        typename t_PingDataInterfacePerFile::type_EnvironmentDataInterface;

    using type_PingContainer = typename t_PingDataInterfacePerFile::type_PingContainer;
    using type_Ping          = typename t_PingDataInterfacePerFile::type_Ping;

  protected:
    type_PingContainer _ping_container;
    tools::helper::DefaultSharedPointerMap<std::string, type_PingContainer>
        _ping_container_by_channel;

    std::weak_ptr<type_EnvironmentDataInterface> _environment_data_interface;

  public:
    I_PingDataInterface(std::shared_ptr<type_EnvironmentDataInterface> environment_data_interface,
                        std::string_view                               name = "I_PingDataInterface")
        : t_base(name)
        , _environment_data_interface(environment_data_interface)
    {
    }
    virtual ~I_PingDataInterface() = default;

    type_ConfigurationDataInterface& configuration_data_interface()
    {
        return _environment_data_interface.lock()->configuration_data_interface();
    }
    const type_ConfigurationDataInterface& configuration_data_interface_const() const
    {
        return _environment_data_interface.lock()->configuration_data_interface_const();
    }
    type_NavigationDataInterface& navigation_data_interface()
    {
        return _environment_data_interface.lock()->navigation_data_interface();
    }
    const type_NavigationDataInterface& navigation_data_interface_const() const
    {
        return _environment_data_interface.lock()->navigation_data_interface_const();
    }

    type_EnvironmentDataInterface& environment_data_interface()
    {
        return *_environment_data_interface.lock();
    }
    const type_EnvironmentDataInterface& environment_data_interface_const() const
    {
        return *_environment_data_interface.lock();
    }

    const type_PingContainer& get_pings() const { return _ping_container; }
    const type_PingContainer& get_pings(const std::string& channel_id) const
    {
        return *_ping_container_by_channel.at_const(channel_id);
    }

    using I_FileDataInterface<t_PingDataInterfacePerFile>::init_from_file;
    void init_from_file(const std::unordered_map<std::string, std::string>& index_paths,
                        bool                                                force,
                        tools::progressbars::I_ProgressBar&                 progress_bar,
                        bool external_progress_tick = false,
                        int  mp_cores              = 1) final
    {
        auto primary_interfaces_per_file = this->per_primary_file();

        if (primary_interfaces_per_file.empty())
        {
            return;
        }

        // init navigation interface (must be done before read_pings)
        if (!this->navigation_data_interface().is_initialized())
        {
            this->navigation_data_interface().init_from_file(index_paths, false, progress_bar);
        }

        bool existing_progressbar = true;

        if (!progress_bar.is_initialized())
        {
            progress_bar.init(0.,
                              double(primary_interfaces_per_file.size()),
                              fmt::format("Initializing {} from file data", this->class_name()));
            existing_progressbar = false;
        }

        // Clamp mp_cores to [1, n_files]
        if (mp_cores < 1)
            mp_cores = 1;
        const size_t n_files = primary_interfaces_per_file.size();
        const size_t n_threads =
            std::min(static_cast<size_t>(mp_cores), n_files);

        // Lambda: process a single file and return its ping container
        auto process_file = [&](size_t i) -> type_PingContainer {
            std::string index_path = tools::helper::get_from_map_with_default(
                index_paths,
                primary_interfaces_per_file[i]->get_file_path(),
                std::string(""));

            primary_interfaces_per_file[i]->init_from_file(
                i == 0 ? index_path : std::string(""), force);
            return primary_interfaces_per_file[i]->read_pings(index_paths);
        };

        if (n_threads <= 1)
        {
            // ---- Single-threaded path (default, zero overhead) ----
            _ping_container = process_file(0);

            for (size_t i = 1; i < n_files; ++i)
            {
                progress_bar.set_postfix(
                    fmt::format("{}/{}", i, n_files));

                try
                {
                    auto file_pings = process_file(i);
                    _ping_container.add_pings(std::move(file_pings).get_pings());
                }
                catch (std::exception& e)
                {
                    fmt::print(
                        std::cerr,
                        "WARNING[{}::init_from_file]: Could not merge file ping data ({}): {}\n",
                        this->class_name(),
                        i,
                        e.what());
                }
                if (!existing_progressbar || external_progress_tick)
                    progress_bar.tick();
            }
        }
        else
        {
            // ---- Multi-threaded path ----
            // Process all files in parallel using a thread pool pattern.
            // Each file is independent: own per-file interface, own file streams
            // (thread_local in InputFileManager), own cache handler.

            std::vector<std::future<type_PingContainer>> futures(n_files);
            std::vector<std::string>                     errors(n_files);

            // Simple work-stealing: launch up to n_threads async tasks at a time
            // Using std::async with launch::async to get real threads
            size_t launched = 0;
            size_t merged   = 0;

            // Launch all tasks, n_threads at a time
            while (launched < n_files)
            {
                // Launch a batch of tasks
                size_t batch_end = std::min(launched + n_threads, n_files);
                for (size_t i = launched; i < batch_end; ++i)
                {
                    futures[i] = std::async(std::launch::async, [&, i]() {
                        return process_file(i);
                    });
                }

                // Wait for and merge this batch in order
                for (size_t i = launched; i < batch_end; ++i)
                {
                    try
                    {
                        auto file_pings = futures[i].get();

                        if (merged == 0)
                        {
                            _ping_container = std::move(file_pings);
                        }
                        else
                        {
                            _ping_container.add_pings(
                                std::move(file_pings).get_pings());
                        }
                    }
                    catch (std::exception& e)
                    {
                        fmt::print(
                            std::cerr,
                            "WARNING[{}::init_from_file]: Could not merge file ping data "
                            "({}): {}\n",
                            this->class_name(),
                            i,
                            e.what());
                    }

                    ++merged;
                    progress_bar.set_postfix(
                        fmt::format("{}/{}", merged, n_files));
                    if (!existing_progressbar || external_progress_tick)
                        progress_bar.tick();
                }
                launched = batch_end;
            }
        }

        // Group pings by channel
        progress_bar.set_postfix("Merging pings by channel");
        for (const auto& ping : _ping_container.get_pings())
        {
            _ping_container_by_channel.at(ping->get_channel_id())->add_ping_no_reindex(ping);
        }
        for (auto& [channel_id, container_ptr] : _ping_container_by_channel)
        {
            container_ptr->reindex();
        }

        if (!existing_progressbar)
            progress_bar.close(std::string("Done"));
    }

    std::vector<std::string> get_channel_ids() const
    {
        std::vector<std::string> channel_ids;
        for (const auto& [k, v] : _ping_container_by_channel)
        {
            channel_ids.push_back(k);
        }

        return channel_ids;
    }

    // ----- old -----

    void add_file_interface(size_t file_nr) final
    {
        if (file_nr >= this->_interface_per_file.size())
        {
            this->_environment_data_interface.lock()->add_file_interface(file_nr);

            this->_interface_per_file.reserve(file_nr + 1);

            for (size_t i = this->_interface_per_file.size(); i <= file_nr; ++i)
            {
                this->_interface_per_file.push_back(std::make_shared<t_PingDataInterfacePerFile>(
                    this->_environment_data_interface.lock()));
            }
            this->_pyindexer.reset(this->_interface_per_file.size());
        }
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        printer.register_section("FileData");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("PingData");
        printer.append(_ping_container.__printer__(float_precision, superscript_exponents), false, '^');

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