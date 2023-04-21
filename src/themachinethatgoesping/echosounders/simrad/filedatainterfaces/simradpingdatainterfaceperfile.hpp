// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradpingdatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "simradconfigurationdatainterface.hpp"

#include "../filedatacontainers/simradfiledatacontainers.hpp"
#include "../simrad_datagrams.hpp"
#include "../simrad_types.hpp"
#include "simraddatagraminterface.hpp"
#include "simradenvironmentdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradPingDataInterfacePerFile
    : public filetemplates::datainterfaces::I_PingDataInterfacePerFile<
          SimradEnvironmentDataInterface<t_ifstream>,
          filedatacontainers::SimradPingContainer<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_PingDataInterfacePerFile<
        SimradEnvironmentDataInterface<t_ifstream>,
        filedatacontainers::SimradPingContainer<t_ifstream>>;

    filetemplates::helper::DeduplicateBuffer<datagrams::xml_datagrams::XML_Parameter_Channel>
        _channel_parameter_buffer;

  public:
    SimradPingDataInterfacePerFile()
        : t_base("SimradPingDataInterfacePerFile")
    {
    }
    SimradPingDataInterfacePerFile(
        std::shared_ptr<SimradEnvironmentDataInterface<t_ifstream>> environment_data_interface)
        : t_base(std::move(environment_data_interface), "SimradPingDataInterfacePerFile")
    {
    }
    ~SimradPingDataInterfacePerFile() = default;

    std::unordered_map<datagrams::xml_datagrams::XML_Parameter_Channel,
                       datagrams::xml_datagrams::XML_Parameter_Channel>
    get_deduplicated_parameters()
    {
        return _channel_parameter_buffer.get_all();
    }

    filedatacontainers::SimradPingContainer<t_ifstream> read_pings()
    {
        filedatacontainers::SimradPingContainer<t_ifstream> pings;

        for (const auto& datagram_ptr : this->_datagram_infos_all)
        {
            auto type = datagram_ptr->get_datagram_identifier();

            switch (type)
            {
                case t_SimradDatagramIdentifier::XML0: {

                    auto& ifs = datagram_ptr->get_stream_and_seek();
                    auto  xml = datagrams::XML0::from_stream(ifs);

                    if (!ifs.good())
                    {
                        fmt::print(std::cerr, "Error reading XML0 datagram");
                        break;
                    }

                    auto xml_type = xml.get_xml_datagram_type();

                    if (xml_type == "Parameter")
                    {
                        auto channel =
                            std::get<datagrams::xml_datagrams::XML_Parameter>(xml.decode())
                                .Channels[0];
                        _channel_parameter_buffer.add(channel, channel.ChannelID);
                        break;
                    }
                    else if (xml_type == "InitialParameter")
                    {
                        auto channels =
                            std::get<datagrams::xml_datagrams::XML_InitialParameter>(xml.decode())
                                .Channels;
                        for (const auto& channel : channels)
                            _channel_parameter_buffer.add(channel, channel.ChannelID);
                        break;
                    }

                    fmt::print(std::cerr, "WARNING: unexpected xml datagram type: {}\n", xml_type);
                    break;
                }
                case t_SimradDatagramIdentifier::RAW3: {
                    auto& ifs  = datagram_ptr->get_stream_and_seek();
                    auto  raw3 = datagrams::RAW3::from_stream(ifs, true);

                    auto ping = std::make_shared<filedatatypes::SimradPing<t_ifstream>>(
                        datagram_ptr, std::move(raw3));

                    auto channel_id = ping->get_channel_id();

                    if (!ifs.good())
                    {
                        fmt::print(std::cerr, "Error reading RAW3 datagram");
                        break;
                    }

                    ping->raw_data().add_parameter(_channel_parameter_buffer.get(channel_id));
                    ping->set_geolocation(channel_id,
                                          this->navigation_data_interface().get_geolocation(
                                              ping->get_channel_id(), ping->get_timestamp()));

                    pings.add_ping(ping);
                    break;
                }
                case t_SimradDatagramIdentifier::FIL1:
                    [[fallthrough]];
                case t_SimradDatagramIdentifier::TAG0:
                    [[fallthrough]];
                case t_SimradDatagramIdentifier::MRU0:
                    [[fallthrough]];
                case t_SimradDatagramIdentifier::NME0:
                    [[fallthrough]];
                default: {
                    fmt::print(std::cerr,
                               "WARNING: unexpected datagram type: {}\n",
                               datagram_type_to_string(type));
                }
            }
        }

        return pings;
    }
    // --------------------- simrad specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("SimradPingDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
