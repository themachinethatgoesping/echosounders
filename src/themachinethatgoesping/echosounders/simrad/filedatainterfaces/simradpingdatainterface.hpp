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

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace filedatainterfaces {

template<typename t_datagram = datagrams::xml_datagrams::XML_Parameter_Channel>
class DeduplicateBuffer
{
    std::unordered_map<std::string, std::shared_ptr<t_datagram>> _last_datagram_per_channel_id;
    std::unordered_map<t_datagram, std::shared_ptr<t_datagram>>  _datagrams;

  public:
    DeduplicateBuffer() = default;

    void add(const t_datagram& datagram, const std::string& channel_id)
    {
        // add channel_ptr if channel is not in in channel_parameters
        // keys
        auto it = _datagrams.find(datagram);
        if (it == _datagrams.end())
        {
            auto datagram_ptr                         = std::make_shared<t_datagram>(datagram);
            _datagrams[datagram]                      = datagram_ptr;
            _last_datagram_per_channel_id[channel_id] = datagram_ptr;
        }
        else
        {
            _last_datagram_per_channel_id[channel_id] = it->second;
        }
    }

    std::shared_ptr<t_datagram> get(const std::string& channel_id)
    {
        return _last_datagram_per_channel_id[channel_id];
    }

    std::unordered_map<t_datagram, t_datagram> get_all()
    {
        std::unordered_map<t_datagram, t_datagram> datagrams;
        for (auto& [key, value] : _datagrams)
        {
            datagrams[key] = *value;
        }
        return datagrams;
    }
};

template<typename t_ifstream>
class SimradPingPerFileDataInterface
    : public filetemplates::datainterfaces::I_PingPerFileDataInterface<SimradEnvironmentDataInterface<t_ifstream>>
{
    using t_base =
        filetemplates::datainterfaces::I_PingPerFileDataInterface<SimradEnvironmentDataInterface<t_ifstream>>;

  public:


    SimradPingPerFileDataInterface()
        : t_base("SimradPingPerFileDataInterface")
    {
    }
    SimradPingPerFileDataInterface(
        std::shared_ptr<SimradEnvironmentDataInterface<t_ifstream>> environment_data_interface)
        : t_base(std::move(environment_data_interface), "SimradPingPerFileDataInterface")
    {
    }
    ~SimradPingPerFileDataInterface() = default;

    // ping::PingInterpolatorLatLon read_ping_data() const final
    // {
    //     return navi;
    // }

    // --------------------- simrad specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("SimradPingPerFileDataInterface");

        return printer;
    }
};

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
