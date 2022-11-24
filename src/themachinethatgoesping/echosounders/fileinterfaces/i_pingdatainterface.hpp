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

#include "i_configurationdatainterface.hpp"
#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

// TODO: this should be a c++20 concept
template<typename t_datagraminterface, 
typename t_ConfigurationDataInterface,
typename t_NavigationDataInterface>
class I_PingPerFileDataInterface : public I_PerFileDataInterface<t_datagraminterface>
{
    using t_base = I_PerFileDataInterface<t_datagraminterface>;

  protected:
    std::shared_ptr<t_ConfigurationDataInterface> _configuration_data_interface;

  public:
    I_PingPerFileDataInterface(std::string_view name = "I_PingPerFileDataInterface")
        : t_base(name)
    {
        throw std::runtime_error(
            fmt::format("I_PingPerFileDataInterface({}): cannot be initialized without "
                        "existing configuration_data_interface",
                        this->get_name()));
    }

    I_PingPerFileDataInterface(
        std::shared_ptr<t_ConfigurationDataInterface> configuration_data_interface,
        std::string_view name = "I_PingPerFileDataInterface")
        : t_base(name)
        , _configuration_data_interface(configuration_data_interface)
    {
    }
    virtual ~I_PingPerFileDataInterface() = default;

    t_ConfigurationDataInterface& get_configuration_data_interface() const
    {
        return *_configuration_data_interface;
    }

    virtual ping::PingInterpolatorLatLon read_ping_data() const
    {
        throw std::runtime_error(
            fmt::format("I_PingPerFileDataInterface({}): read_ping_data() not "
                        "implemented",
                        this->get_name()));
    }

    void init_from_file() final { return; }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("PingPerFileDataInterface");
        return printer;
    }
};
// void add_datagram(DatagramInfo_ptr<t_Datagram

template<typename t_PingPerFileDataInterface, typename t_ConfigurationDataInterface>
class I_PingDataInterface : public I_FileDataInterface<t_PingPerFileDataInterface>
{
    using t_base = I_FileDataInterface<t_PingPerFileDataInterface>;

  protected:
    ping::PingInterpolatorLatLon _ping_interpolator{
        ping::SensorConfiguration()
    };

    std::shared_ptr<t_ConfigurationDataInterface> _configuration_data_interface;

  public:
    I_PingDataInterface(
        std::shared_ptr<t_ConfigurationDataInterface> configuration_data_interface,
        std::string_view                              name = "I_PingDataInterface")
        : t_base(name)
        , _configuration_data_interface(configuration_data_interface)
    {
    }
    virtual ~I_PingDataInterface() = default;

    t_ConfigurationDataInterface& get_configuration_data_interface() const
    {
        return *_configuration_data_interface;
    }

    using I_FileDataInterface<t_PingPerFileDataInterface>::init_from_file;
    void init_from_file(tools::progressbars::I_ProgressBar& progress_bar) final
    {
        if (this->_interface_per_file.empty())
        {
            return;
        }
        progress_bar.init(0.,
                          double(this->_interface_per_file.size() - 1),
                          fmt::format("Initializing {} from file data", this->get_name()));

        this->_interface_per_file.front()->init_from_file();
        _ping_interpolator = this->_interface_per_file.front()->read_ping_data();

        for (size_t i = 1; i < this->_interface_per_file.size(); ++i)
        {
            progress_bar.set_postfix(fmt::format("{}/{}", i, this->_interface_per_file.size()));

            try
            {
                this->_interface_per_file[i]->init_from_file();
                _ping_interpolator.merge(this->_interface_per_file[i]->read_ping_data());
            }
            catch (std::exception& e)
            {
                fmt::print(
                    std::cerr,
                    "WARNING[{}::init_from_file]: Could not merge file ping ({}): {}\n",
                    this->get_name(),
                    i,
                    e.what());
            }
            progress_bar.tick();
        }

        progress_bar.close(std::string("Done"));
    }

    ping::PingInterpolatorLatLon& get_ping_data()
    {
        return _ping_interpolator;
    }

    // ----- old -----

    void add_file_interface(size_t file_nr) final
    {
        if (file_nr >= this->_interface_per_file.size())
        {
            this->_configuration_data_interface->add_file_interface(file_nr);

            this->_interface_per_file.reserve(file_nr + 1);

            for (size_t i = this->_interface_per_file.size(); i <= file_nr; ++i)
            {
                this->_interface_per_file.push_back(
                    std::make_shared<t_PingPerFileDataInterface>(
                        this->_configuration_data_interface->per_file_ptr(i)));
            }
            this->_pyindexer.reset(this->_interface_per_file.size());
        }
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.register_section("FileData");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("PingDataInterface");

        return printer;
    }

    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping