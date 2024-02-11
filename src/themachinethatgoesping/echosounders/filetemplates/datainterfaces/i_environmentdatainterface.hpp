// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_environmentdatainterface.doc.hpp"

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
#include "i_environmentdatainterfaceperfile.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datainterfaces {

template<typename t_EnvironmentDataInterfacePerFile>
class I_EnvironmentDataInterface : public I_FileDataInterface<t_EnvironmentDataInterfacePerFile>
{
    using t_base = I_FileDataInterface<t_EnvironmentDataInterfacePerFile>;

  public:
    using type_ConfigurationDataInterface =
        typename t_EnvironmentDataInterfacePerFile::type_ConfigurationDataInterface;
    using type_NavigationDataInterface =
        typename t_EnvironmentDataInterfacePerFile::type_NavigationDataInterface;

  protected:
    // environment::EnvironmentInterpolatorLatLon _environment_interpolator{
    //     environment::SensorConfiguration()
    // };

    std::weak_ptr<type_NavigationDataInterface> _navigation_data_interface;

  public:
    I_EnvironmentDataInterface(
        std::shared_ptr<type_NavigationDataInterface> navigation_data_interface,
        std::string_view                              name = "I_EnvironmentDataInterface")
        : t_base(name)
        , _navigation_data_interface(navigation_data_interface)
    {
    }
    virtual ~I_EnvironmentDataInterface() = default;

    type_ConfigurationDataInterface& configuration_data_interface()
    {
        return _navigation_data_interface.lock()->configuration_data_interface();
    }
    const type_ConfigurationDataInterface& configuration_data_interface_const() const
    {
        return _navigation_data_interface.lock()->configuration_data_interface_const();
    }

    type_NavigationDataInterface& navigation_data_interface()
    {
        return *_navigation_data_interface.lock();
    }
    const type_NavigationDataInterface& navigation_data_interface_const() const
    {
        return *_navigation_data_interface.lock();
    }

    using I_FileDataInterface<t_EnvironmentDataInterfacePerFile>::init_from_file;

    // environment::EnvironmentInterpolatorLatLon& get_environment_data()
    // {
    //     return _environment_interpolator;
    // }

    // ----- old -----

    void add_file_interface(size_t file_nr) final
    {
        if (file_nr >= this->_interface_per_file.size())
        {
            this->_navigation_data_interface.lock()->add_file_interface(file_nr);

            this->_interface_per_file.reserve(file_nr + 1);

            for (size_t i = this->_interface_per_file.size(); i <= file_nr; ++i)
            {
                this->_interface_per_file.push_back(
                    std::make_shared<t_EnvironmentDataInterfacePerFile>(
                        this->_navigation_data_interface.lock()));
            }
            this->_pyindexer.reset(this->_interface_per_file.size());
        }
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        printer.register_section("FileData");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("EnvironmentDataInterface");

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