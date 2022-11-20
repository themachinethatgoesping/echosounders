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

#include "../fileinterfaces/i_configurationdatainterface.hpp"

#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"
#include "simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
class SimradConfigurationDataCollection
    : public fileinterfaces::I_ConfigurationDataCollection<SimradDatagramInterface<t_ifstream>>
{
    using t_base =
        fileinterfaces::I_ConfigurationDataCollection<SimradDatagramInterface<t_ifstream>>;

  public:
    SimradConfigurationDataCollection()
        : t_base("SimradConfigurationDataCollection")
    {
    }
    ~SimradConfigurationDataCollection() = default;

    void read_sensor_configuration() final
    {
        // check that there is a configuration datagram
        if (this->_datagram_infos_by_type.at_const(t_SimradDatagramIdentifier::XML0).empty())
            throw std::runtime_error(fmt::format(
                "read_sensor_configuration: No XML0 datagram found in {}!", this->get_file_path()));

        // check that this datagram is a simrad configuration datagram

        // auto config_datagram datagram_info->read_datagram_from_file<t_DatagramType,
        // t_DatagramTypeFactory>();
        throw std::runtime_error(
            fmt::format("read_sensor_configuration not implemented for {}", this->get_name()));
    }
};

template<typename t_ifstream>
class SimradConfigurationDataInterface
    : public fileinterfaces::I_ConfigurationDataInterface<
          SimradConfigurationDataCollection<t_ifstream>>
{
    using t_base =
        fileinterfaces::I_ConfigurationDataInterface<SimradConfigurationDataCollection<t_ifstream>>;

  public:
    SimradConfigurationDataInterface()
        : t_base("SimradConfigurationDataInterface")
    {
    }
    ~SimradConfigurationDataInterface() = default;
};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
