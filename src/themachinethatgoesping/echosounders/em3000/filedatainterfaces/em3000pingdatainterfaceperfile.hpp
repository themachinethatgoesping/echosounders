// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/em3000pingdatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "em3000configurationdatainterface.hpp"

#include "../em3000_datagrams.hpp"
#include "../em3000_types.hpp"
#include "../filedatacontainers/em3000filedatacontainers.hpp"
#include "em3000datagraminterface.hpp"
#include "em3000environmentdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatainterfaces {

template<typename t_ifstream>
class EM3000PingDataInterfacePerFile
    : public filetemplates::datainterfaces::I_PingDataInterfacePerFile<
          EM3000EnvironmentDataInterface<t_ifstream>,
          filedatacontainers::EM3000PingContainer<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_PingDataInterfacePerFile<
        EM3000EnvironmentDataInterface<t_ifstream>,
        filedatacontainers::EM3000PingContainer<t_ifstream>>;

    // filetemplates::helper::DeduplicateBuffer<datagrams::xml_datagrams::XML_Parameter_Channel>
    //     _channel_parameter_buffer;

  public:
    EM3000PingDataInterfacePerFile()
        : t_base("EM3000PingDataInterfacePerFile")
    {
    }
    EM3000PingDataInterfacePerFile(
        std::shared_ptr<EM3000EnvironmentDataInterface<t_ifstream>> environment_data_interface)
        : t_base(std::move(environment_data_interface), "EM3000PingDataInterfacePerFile")
    {
    }
    ~EM3000PingDataInterfacePerFile() = default;

    // std::unordered_map<datagrams::xml_datagrams::XML_Parameter_Channel,
    //                    datagrams::xml_datagrams::XML_Parameter_Channel>
    // get_deduplicated_parameters()
    // {
    //     return _channel_parameter_buffer.get_all();
    // }

    filedatacontainers::EM3000PingContainer<t_ifstream> read_pings()
    {
        filedatacontainers::EM3000PingContainer<t_ifstream> pings;

        return pings;
    }

    //     for (const auto& datagram_ptr : this->_datagram_infos_all)
    //     {
    //         auto type = datagram_ptr->get_datagram_identifier();

    //         switch (type)
    //         {
    //             case t_EM3000DatagramIdentifier::XML0: {

    //                 auto& ifs = datagram_ptr->get_stream_and_seek();
    //                 auto  xml = datagrams::XML0::from_stream(ifs);

    //                 if (!ifs.good())
    //                 {
    //                     fmt::print(std::cerr, "Error reading XML0 datagram");
    //                     break;
    //                 }

    //                 auto xml_type = xml.get_xml_datagram_type();

    //                 if (xml_type == "Parameter")
    //                 {
    //                     auto channel =
    //                         std::get<datagrams::xml_datagrams::XML_Parameter>(xml.decode())
    //                             .Channels[0];
    //                     _channel_parameter_buffer.add(channel, channel.ChannelID);
    //                     break;
    //                 }
    //                 else if (xml_type == "InitialParameter")
    //                 {
    //                     auto channels =
    //                         std::get<datagrams::xml_datagrams::XML_InitialParameter>(xml.decode())
    //                             .Channels;
    //                     for (const auto& channel : channels)
    //                         _channel_parameter_buffer.add(channel, channel.ChannelID);
    //                     break;
    //                 }

    //                 fmt::print(std::cerr, "WARNING: unexpected xml datagram type: {}\n",
    //                 xml_type); break;
    //             }
    //             case t_EM3000DatagramIdentifier::RAW3: {
    //                 auto& ifs  = datagram_ptr->get_stream_and_seek();
    //                 auto  raw3 = datagrams::RAW3::from_stream(ifs, true);

    //                 auto ping = std::make_shared<filedatatypes::EM3000Ping<t_ifstream>>(
    //                     datagram_ptr, std::move(raw3));

    //                 auto channel_id = ping->get_channel_id();

    //                 if (!ifs.good())
    //                 {
    //                     fmt::print(std::cerr, "Error reading RAW3 datagram");
    //                     break;
    //                 }

    //                 ping->raw_data().add_parameter(_channel_parameter_buffer.get(channel_id));
    //                 ping->set_geolocation(this->navigation_data_interface().get_geolocation(
    //                     ping->get_channel_id(), ping->get_timestamp()));

    //                 pings.add_ping(ping);
    //                 break;
    //             }
    //             case t_EM3000DatagramIdentifier::FIL1:
    //                 [[fallthrough]];
    //             case t_EM3000DatagramIdentifier::TAG0:
    //                 [[fallthrough]];
    //             case t_EM3000DatagramIdentifier::MRU0:
    //                 [[fallthrough]];
    //             case t_EM3000DatagramIdentifier::NME0:
    //                 [[fallthrough]];
    //             default: {
    //                 fmt::print(std::cerr,
    //                            "WARNING: unexpected datagram type: {}\n",
    //                            datagram_type_to_string(type));
    //             }
    //         }
    //     }

    //     return pings;
    // }
    // --------------------- em3000 specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("EM3000PingDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping