// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "simradconfigurationdatainterface.hpp"

#include "../simrad_datagrams.hpp"
#include "../simrad_types.hpp"
#include "simraddatagraminterface.hpp"
#include "simradenvironmentdatainterface.hpp"
#include "simradpingperfiledatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace filedatainterfaces {


template<typename t_ifstream>
class SimradPingDataInterface
    : public filetemplates::datainterfaces::I_PingDataInterface<SimradPingPerFileDataInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_PingDataInterface<SimradPingPerFileDataInterface<t_ifstream>>;

    DeduplicateBuffer<datagrams::xml_datagrams::XML_Parameter_Channel> _channel_parameter_buffer;
  public:

    std::unordered_map<datagrams::xml_datagrams::XML_Parameter_Channel,
                       datagrams::xml_datagrams::XML_Parameter_Channel> get_deduplicated()
    {
        return _channel_parameter_buffer.get_all();
    }

    // add channel parameters to channel_parameters
    void add_channel_parameter(
        const datagrams::xml_datagrams::XML_Parameter_Channel& channel)
    {
        _channel_parameter_buffer.add(channel, channel.ChannelID);
    }

    // get channel parameters from channel_parameters
    std::shared_ptr<datagrams::xml_datagrams::XML_Parameter_Channel> get_channel_parameter(
        const std::string& channel_id)
    {
        return _channel_parameter_buffer.get(channel_id);
    }


    SimradPingDataInterface(
        std::shared_ptr<SimradEnvironmentDataInterface<t_ifstream>> environment_data_interface)
        : t_base(std::move(environment_data_interface), "SimradPingDataInterface")
    {
    }
    ~SimradPingDataInterface() = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));
        return printer;
    }
};

}
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
