// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_pingdatainterface.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

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
    void init_from_file(const std::unordered_map<std::string, std::string>& file_cache_paths,
                        bool                                                force,
                        tools::progressbars::I_ProgressBar&                 progress_bar,
                        bool external_progress_tick = false) final
    {
        auto primary_interfaces_per_file = this->per_primary_file();

        if (primary_interfaces_per_file.empty())
        {
            return;
        }

        // init navigation interface
        if (!this->navigation_data_interface().is_initialized())
        {
            this->navigation_data_interface().init_from_file(file_cache_paths, false, progress_bar);
        }

        bool existing_progressbar = true;

        if (!progress_bar.is_initialized())
        {
            progress_bar.init(0.,
                              double(primary_interfaces_per_file.size()),
                              fmt::format("Initializing {} from file data", this->class_name()));
            existing_progressbar = false;
        }

        std::string cache_file_path = tools::helper::get_from_map_with_default(
            file_cache_paths,
            primary_interfaces_per_file.front()->get_file_path(),
            std::string(""));

        primary_interfaces_per_file.front()->init_from_file(cache_file_path, force);
        _ping_container = primary_interfaces_per_file.front()->read_pings(file_cache_paths);

        for (size_t i = 1; i < primary_interfaces_per_file.size(); ++i)
        {
            progress_bar.set_postfix(fmt::format("{}/{}", i, primary_interfaces_per_file.size()));

            try
            {

                cache_file_path = tools::helper::get_from_map_with_default(
                    file_cache_paths,
                    primary_interfaces_per_file[i]->get_file_path(),
                    std::string(""));

                primary_interfaces_per_file[i]->init_from_file("", force);
                _ping_container.add_pings(
                    primary_interfaces_per_file[i]->read_pings(file_cache_paths).get_pings());
            }
            catch (std::exception& e)
            {
                fmt::print(std::cerr,
                           "WARNING[{}::init_from_file]: Could not merge file ping data ({}): {}\n",
                           this->class_name(),
                           i,
                           e.what());
            }
            if (!existing_progressbar || external_progress_tick)
                progress_bar.tick();
        }

        progress_bar.set_postfix("Merging pings by channel");
        for (const auto& ping : _ping_container.get_pings())
        {
            _ping_container_by_channel.at(ping->get_channel_id())->add_ping(ping);
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