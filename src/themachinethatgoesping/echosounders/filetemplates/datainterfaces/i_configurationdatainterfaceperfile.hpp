// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_configurationdatainterfaceperfile.doc.hpp"

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

/* themachinethatgoesping navigation includes */
#include <themachinethatgoesping/navigation/sensorconfiguration.hpp>

#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datainterfaces {

// TODO: this should be a c++20 concept
template<typename t_datagraminterface>
class I_ConfigurationDataInterfacePerFile : public I_FileDataInterfacePerFile<t_datagraminterface>
{
    using t_base = I_FileDataInterfacePerFile<t_datagraminterface>;

  private:
    navigation::SensorConfiguration _sensor_configuration;

    bool _is_initialized_sensor_configuration = false;

  public:
    I_ConfigurationDataInterfacePerFile(
        std::string_view name = "I_ConfigurationDataInterfacePerFile")
        : t_base(name)
    {
    }
    virtual ~I_ConfigurationDataInterfacePerFile() = default;

    virtual navigation::SensorConfiguration read_sensor_configuration()
    {
        throw std::runtime_error(
            fmt::format("read_sensor_configuration not implemented for {}", this->class_name()));
    }

    bool is_initialized_sensor_configuration() const
    {
        return _is_initialized_sensor_configuration;
    }
    void deinitialize() override { _is_initialized_sensor_configuration = false; }
    bool is_initialized() const override { return _is_initialized_sensor_configuration; }

    void set_sensor_configuration(navigation::SensorConfiguration sensor_configuration)
    {
        _is_initialized_sensor_configuration = true;
        _sensor_configuration                = std::move(sensor_configuration);
    }
    const navigation::SensorConfiguration& get_sensor_configuration() const
    {
        if (!_is_initialized_sensor_configuration)
            throw std::runtime_error(
                fmt::format("ERROR[get_sensor_configuration]: Sensor configuration not initialized "
                            "for file {}",
                            this->get_file_path()));

        return _sensor_configuration;
    }

    void init_from_file([[maybe_unused]] const std::string& cache_file_path = "",
                        bool                                force           = false) final
    {
        try
        {
            if (force || !_is_initialized_sensor_configuration)
            {
                _sensor_configuration                = this->read_sensor_configuration();
                _is_initialized_sensor_configuration = true;
            }
        }
        catch (std::exception& e)
        {
            // throw std::runtime_error(
            //     fmt::format("ERROR[init_from_file]: Could not read sensor configuration from file
            //     "
            //                 "{}: {}. Error was: {}",
            //                 this->get_file_nr(),
            //                 this->get_file_path(),
            //                 e.what()));
            // TODO: use logging
            std::cerr << fmt::format("Warning[init_from_file]: Could not read sensor configuration "
                                     "from file: \n -{}: {}. \n -Using empty sensor configuration "
                                     "as fallback. \n-Error was: {}",
                                     this->get_file_nr(),
                                     this->get_file_path(),
                                     e.what())
                      << std::endl;
            _sensor_configuration                = navigation::SensorConfiguration();
            _is_initialized_sensor_configuration = true;
        }
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("ConfigurationDataInterfacePerFile");
        return printer;
    }
};
// void add_datagram(datatypes::DatagramInfo_ptr<t_Datagram

} // namespace datainterfaces
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping