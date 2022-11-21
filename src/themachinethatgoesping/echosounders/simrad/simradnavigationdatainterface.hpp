// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../fileinterfaces/i_navigationdatainterface.hpp"
#include "simradconfigurationdatainterface.hpp"

#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"
#include "simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
class SimradNavigationPerFileDataInterface
    : public fileinterfaces::I_NavigationPerFileDataInterface<
          SimradDatagramInterface<t_ifstream>,
          SimradConfigurationPerFileDataInterface<t_ifstream>>
{
    using t_base = fileinterfaces::I_NavigationPerFileDataInterface<
        SimradDatagramInterface<t_ifstream>,
        SimradConfigurationPerFileDataInterface<t_ifstream>>;

  public:
    SimradNavigationPerFileDataInterface()
        : t_base("SimradNavigationPerFileDataInterface")
    {
    }
    SimradNavigationPerFileDataInterface(
        std::shared_ptr<SimradConfigurationPerFileDataInterface<t_ifstream>>
            configuration_data_interface)
        : t_base(std::move(configuration_data_interface), "SimradNavigationPerFileDataInterface")
    {
    }
    ~SimradNavigationPerFileDataInterface() = default;

    navigation::NavigationInterpolatorLatLon read_navigation_data() const final
    {
        navigation::NavigationInterpolatorLatLon navint(
            this->_configuration_data_interface->get_sensor_configuration());

        return navint;
    }

    // --------------------- simrad specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("SimradNavigationPerFileDataInterface");

        return printer;
    }
};

template<typename t_ifstream>
class SimradNavigationDataInterface
    : public fileinterfaces::I_NavigationDataInterface<
          SimradNavigationPerFileDataInterface<t_ifstream>,
          SimradConfigurationDataInterface<t_ifstream>>
{
    using t_base =
        fileinterfaces::I_NavigationDataInterface<SimradNavigationPerFileDataInterface<t_ifstream>,
                                                  SimradConfigurationDataInterface<t_ifstream>>;

  public:
    SimradNavigationDataInterface(
        std::shared_ptr<SimradConfigurationDataInterface<t_ifstream>> configuration_data_interface)
        : t_base(std::move(configuration_data_interface), "SimradNavigationDataInterface")
    {
    }
    ~SimradNavigationDataInterface() = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));
        return printer;
    }
};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
