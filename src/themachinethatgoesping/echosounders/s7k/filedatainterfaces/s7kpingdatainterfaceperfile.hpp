// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kpingdatainterfaceperfile.doc.hpp"

/* std includes */
#include <algorithm>
#include <memory>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datainterfaces/i_pingdatainterface.hpp"

#include "s7kconfigurationdatainterface.hpp"

#include "../datagrams.hpp"
#include "../filedatacontainers/s7kpingcontainer.hpp"
#include "../types.hpp"
#include "s7kdatagraminterface.hpp"
#include "s7kenvironmentdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatainterfaces {

/**
 * @brief Interface that reads the pings (bathymetry, water column) of a single .s7k file.
 *
 * @note The datagram-processing function (read_pings) is not implemented yet. The class currently
 * only provides the structure so the pings can be filled in in a later step.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class S7KPingDataInterfacePerFile
    : public filetemplates::datainterfaces::I_PingDataInterfacePerFile<
          S7KEnvironmentDataInterface<t_ifstream>,
          filedatacontainers::S7KPingContainer<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_PingDataInterfacePerFile<
        S7KEnvironmentDataInterface<t_ifstream>,
        filedatacontainers::S7KPingContainer<t_ifstream>>;

  public:
    S7KPingDataInterfacePerFile()
        : t_base("S7KPingDataInterfacePerFile")
    {
    }
    S7KPingDataInterfacePerFile(
        std::shared_ptr<S7KEnvironmentDataInterface<t_ifstream>> environment_data_interface)
        : t_base(std::move(environment_data_interface), "S7KPingDataInterfacePerFile")
    {
    }
    ~S7KPingDataInterfacePerFile() = default;

    /**
     * @brief Group this file's ping datagrams into pings.
     *
     * This first version only assembles the per-ping datagram index (ping.file_data) so that all
     * datagrams belonging to a ping can be listed via ping.file_data.datagrams(). The bottom and
     * water-column data are not read yet (that is a later step).
     *
     * Grouping is done in file order: a new ping is started at every 7000 SonarSettings record
     * (the record that starts a ping cycle in the 7k format); every following ping datagram is
     * added to the current ping. Datagrams that appear before the first SonarSettings record are
     * collected into a leading ping so no datagram is lost.
     *
     * @note This simple file-order grouping assumes each ping starts with a SonarSettings record.
     * Multi-head / multi-ping files (interleaved SonarSettings) and files without SonarSettings
     * are not handled precisely yet and can be refined later (e.g. by grouping on the record
     * ping_number).
     */
    filedatacontainers::S7KPingContainer<t_ifstream> read_pings(
        [[maybe_unused]] const std::unordered_map<std::string, std::string>& index_paths =
            std::unordered_map<std::string, std::string>()) override
    {
        using t_pingcontainer = filedatacontainers::S7KPingContainer<t_ifstream>;
        using t_ping          = filedatatypes::S7KPing<t_ifstream>;
        using t_ping_ptr      = std::shared_ptr<t_ping>;

        // sensor configuration + navigation for this file. The configuration is currently empty
        // (its read_* is not implemented), but an empty SensorConfiguration is valid: it carries a
        // default target "0", so the "Transducer" alias and the navigation interpolator below still
        // resolve and geolocation works (vessel reference point).
        const auto& base_sensor_configuration =
            this->configuration_data_interface().get_sensor_configuration(this->get_file_nr());
        auto sensor_configuration_per_channel =
            this->configuration_data_interface().get_trx_sensor_configuration_per_target_id(
                this->get_file_nr());
        auto navigation_interpolator =
            this->navigation_data_interface().get_navigation_interpolator_flyweight(
                base_sensor_configuration.binary_hash());
        const bool navigation_is_valid = navigation_interpolator.get().valid();

        // process the datagrams in file order (sort a copy so grouping is robust to storage order)
        auto datagram_infos = this->_datagram_infos_all;
        std::sort(datagram_infos.begin(), datagram_infos.end(), [](const auto& a, const auto& b) {
            if (a->get_file_nr() != b->get_file_nr())
                return a->get_file_nr() < b->get_file_nr();
            return a->get_file_pos() < b->get_file_pos();
        });

        t_pingcontainer pings;
        t_ping_ptr      current_ping = nullptr;

        for (const auto& datagram_info : datagram_infos)
        {
            const bool starts_new_ping =
                datagram_info->get_datagram_identifier() ==
                t_S7KDatagramIdentifier::SonarSettings; // 7000

            if (starts_new_ping)
            {
                current_ping = std::make_shared<t_ping>();
                current_ping->set_channel_id("0"); // single channel for now (config not read yet)
                current_ping->file_data().set_primary_file_nr(this->get_file_nr());

                if (base_sensor_configuration.has_target(current_ping->get_channel_id()))
                    current_ping->set_sensor_configuration_flyweight(
                        sensor_configuration_per_channel.at(current_ping->get_channel_id()));
                if (navigation_is_valid)
                    current_ping->set_navigation_interpolator_latlon(navigation_interpolator);

                pings.add_ping_no_reindex(current_ping);
            }

            // records before the first SonarSettings record form an incomplete leading ping and
            // are skipped (they cannot be geolocated / calibrated consistently)
            if (current_ping != nullptr)
                current_ping->add_datagram_info(datagram_info);
        }

        pings.reindex();
        return pings;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("S7KPingDataInterfacePerFile");

        return printer;
    }
};

} // namespace filedatainterfaces
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
