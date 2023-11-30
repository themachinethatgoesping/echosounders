// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawpingdatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "simradrawconfigurationdatainterface.hpp"

#include "../filedatacontainers/simradrawfiledatacontainers.hpp"
#include "../datagrams.hpp"
#include "../types.hpp"
#include "simradrawdatagraminterface.hpp"
#include "simradrawenvironmentdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradRawPingDataInterfacePerFile
    : public filetemplates::datainterfaces::I_PingDataInterfacePerFile<
          SimradRawEnvironmentDataInterface<t_ifstream>,
          filedatacontainers::SimradRawPingContainer<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_PingDataInterfacePerFile<
        SimradRawEnvironmentDataInterface<t_ifstream>,
        filedatacontainers::SimradRawPingContainer<t_ifstream>>;

    filetemplates::helper::DeduplicateBuffer<datagrams::xml_datagrams::XML_Parameter_Channel>
        _channel_parameter_buffer;

  public:
    SimradRawPingDataInterfacePerFile()
        : t_base("SimradRawPingDataInterfacePerFile")
    {
    }
    SimradRawPingDataInterfacePerFile(
        std::shared_ptr<SimradRawEnvironmentDataInterface<t_ifstream>> environment_data_interface)
        : t_base(std::move(environment_data_interface), "SimradRawPingDataInterfacePerFile")
    {
    }
    ~SimradRawPingDataInterfacePerFile() = default;

    auto get_deduplicated_parameters() { return _channel_parameter_buffer.get_all(); }

    filedatacontainers::SimradRawPingContainer<t_ifstream> read_pings()
    {
        filedatacontainers::SimradRawPingContainer<t_ifstream> pings;

        const auto& base_sensor_configuration =
            this->configuration_data_interface().get_sensor_configuration(this->get_file_nr());

        for (const auto& datagram_ptr : this->_datagram_infos_all)
        {
            auto type = datagram_ptr->get_datagram_identifier();

            switch (type)
            {
                case t_SimradRawDatagramIdentifier::XML0: {

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
                            std::make_shared<datagrams::xml_datagrams::XML_Parameter_Channel>(
                                std::get<datagrams::xml_datagrams::XML_Parameter>(xml.decode())
                                    .Channels[0]);
                        _channel_parameter_buffer.add(channel, channel->ChannelID);
                        break;
                    }
                    else if (xml_type == "InitialParameter")
                    {
                        auto channels =
                            std::get<datagrams::xml_datagrams::XML_InitialParameter>(xml.decode())
                                .Channels;
                        for (const auto& channel : channels)
                            _channel_parameter_buffer.add(
                                std::make_shared<datagrams::xml_datagrams::XML_Parameter_Channel>(
                                    channel),
                                channel.ChannelID);
                        break;
                    }

                    fmt::print(std::cerr, "WARNING: unexpected xml datagram type: {}\n", xml_type);
                    break;
                }
                case t_SimradRawDatagramIdentifier::RAW3: {
                    auto& ifs  = datagram_ptr->get_stream_and_seek();
                    auto  raw3 = datagrams::RAW3::from_stream(ifs, true);

                    auto ping = std::make_shared<filedatatypes::SimradRawPing<t_ifstream>>(
                        datagram_ptr, std::move(raw3));

                    auto channel_id = ping->get_channel_id();

                    if (!ifs.good())
                    {
                        fmt::print(std::cerr, "Error reading RAW3 datagram");
                        break;
                    }

                    ping->file_data().add_parameter(_channel_parameter_buffer.get(channel_id));

                    auto sensor_configuration = base_sensor_configuration;
                    sensor_configuration.add_target("Transducer",
                                                    sensor_configuration.get_target(channel_id));
                    ping->set_sensor_configuration(sensor_configuration);

                    ping->set_sensor_data_latlon(this->navigation_data_interface().get_sensor_data(
                        base_sensor_configuration, ping->get_timestamp()));

                    //ping->file_data().set_file_ping_counter(pings.size());

                    pings.add_ping(ping);
                    break;
                }
                case t_SimradRawDatagramIdentifier::FIL1:
                    [[fallthrough]];
                case t_SimradRawDatagramIdentifier::TAG0:
                    [[fallthrough]];
                case t_SimradRawDatagramIdentifier::MRU0:
                    [[fallthrough]];
                case t_SimradRawDatagramIdentifier::NME0:
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
    // --------------------- simradraw specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("SimradRawPingDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
