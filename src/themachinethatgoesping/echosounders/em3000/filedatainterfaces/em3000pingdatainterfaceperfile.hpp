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
#include "../filedatacontainers/em3000pingcontainer.hpp"
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

    filetemplates::helper::DeduplicateBuffer<datagrams::RuntimeParameters,
                                             filetemplates::helper::ContentOnlyHash>
        _runtime_parameter_buffer;

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

    auto get_deduplicated_runtime_parameters() { return _runtime_parameter_buffer.get_all(); }

    filedatacontainers::EM3000PingContainer<t_ifstream> read_pings()
    {
        using t_pingcontainer = filedatacontainers::EM3000PingContainer<t_ifstream>;
        using t_ping          = filedatatypes::EM3000Ping<t_ifstream>;
        using t_ping_ptr      = std::shared_ptr<t_ping>;

        std::map<uint16_t, std::map<uint16_t, t_ping_ptr>> pings_by_counter_by_id;

        // read the file installation parameters and build a base ping
        auto param =
            this->configuration_data_interface_for_file_const().get_installation_parameters();

        t_ping base_ping(this->get_file_nr(), this->get_file_path(), param);

        for (const auto& [type, datagram_infos] : this->_datagram_infos_by_type)
        {
            switch (type)
            {
                case t_EM3000DatagramIdentifier::RuntimeParameters: {

                    for (const auto& datagram_ptr : datagram_infos)
                    {

                        auto rp = std::make_shared<datagrams::RuntimeParameters>(
                            datagram_ptr
                                ->template read_datagram_from_file<datagrams::RuntimeParameters>());
                        _runtime_parameter_buffer.add(
                            rp, std::to_string(rp->get_system_serial_number()));

                        // read ping counter from not deduplicated datagram
                        auto ping_counter         = rp->get_ping_counter();
                        auto system_serial_number = rp->get_system_serial_number();

                        // create a new ping if it does not exist
                        if (pings_by_counter_by_id[ping_counter].find(system_serial_number) ==
                            pings_by_counter_by_id[ping_counter].end())
                        {
                            pings_by_counter_by_id[ping_counter][system_serial_number] =
                                std::make_shared<t_ping>(base_ping);
                        }

                        // add deduplicated runtime parameters
                        pings_by_counter_by_id[ping_counter][system_serial_number]
                            ->set_runtime_parameters(_runtime_parameter_buffer.get(
                                std::to_string(rp->get_system_serial_number())));

                        // add runtime parameters datagram
                        pings_by_counter_by_id[ping_counter][system_serial_number]
                            ->add_datagram_info(datagram_ptr);
                    }
                    break;
                }
                case t_EM3000DatagramIdentifier::XYZDatagram:
                    [[fallthrough]];
                case t_EM3000DatagramIdentifier::ExtraDetections:
                    [[fallthrough]];
                case t_EM3000DatagramIdentifier::RawRangeAndAngle:
                    [[fallthrough]];
                case t_EM3000DatagramIdentifier::SeabedImageData:
                    [[fallthrough]];
                case t_EM3000DatagramIdentifier::WatercolumnDatagram:
                    [[fallthrough]];
                case t_EM3000DatagramIdentifier::QualityFactorDatagram: {

                    for (const auto& datagram_ptr : datagram_infos)
                    {
                        // read the ping counter
                        auto& ifs =
                            datagram_ptr->get_stream_and_seek(16); // offset=16 bytes (header size)
                        // ifs.seekg(16, std::ios::cur); // skip header
                        uint16_t ping_counter, system_serial_number;
                        ifs.read(reinterpret_cast<char*>(&ping_counter), sizeof(uint16_t));
                        ifs.read(reinterpret_cast<char*>(&system_serial_number), sizeof(uint16_t));

                        // create a new ping if it does not exist
                        if (pings_by_counter_by_id[ping_counter].find(system_serial_number) ==
                            pings_by_counter_by_id[ping_counter].end())
                        {
                            pings_by_counter_by_id[ping_counter][system_serial_number] =
                                std::make_shared<t_ping>(base_ping);
                        }

                        auto& ping =
                            pings_by_counter_by_id.at(ping_counter).at(system_serial_number);

                        ping->add_datagram_info(datagram_ptr);
                    }
                    break;
                }
                default:
                    throw std::runtime_error(fmt::format("Invalid datagram type {} for EM3000Ping",
                                                         magic_enum::enum_name(type)));
            }
        }

        // loop through map and copy pings to vector
        t_pingcontainer pings;
        for (auto [ping_counter, pings_by_id] : pings_by_counter_by_id)
        {
            for (auto [id, ping_ptr] : pings_by_id)
            {
                std::string channel_id = fmt::format("TRX-{}", id);

                ping_ptr->set_channel_id(channel_id);

                // load transducer locations from navigation
                try
                {
                    ping_ptr->set_geolocation(this->navigation_data_interface().get_geolocation(
                        channel_id, ping_ptr->get_timestamp()));
                }
                catch (std::exception& e)
                {
                    // throw more precise error
                    throw std::runtime_error(fmt::format(
                        "ERROR[EM3000PingDataInterfacePerFile::read_pings]: could not "
                        "set geolocation ping transducer id {} at time {}\n ERROR was: {}",
                        id,
                        ping_ptr->get_timestamp(),
                        e.what()));
                }

                // load datagrams
                ping_ptr->loadgrams();

                pings.add_ping(std::move(ping_ptr));
            }
        }

        return pings;
    }

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
