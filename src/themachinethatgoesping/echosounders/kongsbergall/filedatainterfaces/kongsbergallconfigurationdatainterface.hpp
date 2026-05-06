

// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallconfigurationdatainterface.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "../../filetemplates/datainterfaces/i_configurationdatainterface.hpp"

#include "../types.hpp"
#include "../datagrams.hpp"
#include "kongsbergallconfigurationdatainterfaceperfile.hpp"
#include "kongsbergalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KongsbergAllConfigurationDataInterface
    : public filetemplates::datainterfaces::I_ConfigurationDataInterface<
          KongsbergAllConfigurationDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_ConfigurationDataInterface<
        KongsbergAllConfigurationDataInterfacePerFile<t_ifstream>>;

  public:
    KongsbergAllConfigurationDataInterface()
        : t_base("KongsbergAllConfigurationDataInterface")
    {
    }
    ~KongsbergAllConfigurationDataInterface() = default;

    /**
     * @brief Build per-TRX-channel SensorConfigurations like the base class,
     * but additionally register \"TX\" and \"RX\" aliases that point to the
     * **correct per-head** TX and RX mounts. This is required for dual-head
     * and dual-RX Kongsberg systems where the synthetic TRX target merges
     * two physically separated transducers and a global \"TX\"/\"RX\" lookup
     * would pick the wrong head for half of the pings.
     *
     * The (TX, RX) name mapping per TRX channel is populated by
     * KongsbergAllConfigurationDataInterfacePerFile::read_sensor_configuration().
     */
    boost::unordered_map<std::string, boost::flyweight<navigation::SensorConfiguration>>
    get_trx_sensor_configuration_per_target_id(int64_t pyindex) const
    {
        boost::unordered_map<std::string, boost::flyweight<navigation::SensorConfiguration>> result;

        const auto& base_sensor_configuration = this->get_sensor_configuration(pyindex);
        const auto& txrx_names_per_trx_channel =
            this->per_file_const(pyindex).get_txrx_target_names_per_trx_channel();

        for (const auto& target_id : base_sensor_configuration.get_target_ids())
        {
            auto trx_sensor_configuration = base_sensor_configuration;
            trx_sensor_configuration.add_target("Transducer",
                                                trx_sensor_configuration.get_target(target_id));

            // If we know which TX/RX targets compose this TRX channel, register
            // them as \"TX\" and \"RX\" aliases on the per-channel configuration.
            auto it = txrx_names_per_trx_channel.find(target_id);
            if (it != txrx_names_per_trx_channel.end())
            {
                const auto& [tx_name, rx_name] = it->second;
                if (base_sensor_configuration.has_target(tx_name))
                    trx_sensor_configuration.add_target(
                        "TX", base_sensor_configuration.get_target(tx_name));
                if (base_sensor_configuration.has_target(rx_name))
                    trx_sensor_configuration.add_target(
                        "RX", base_sensor_configuration.get_target(rx_name));
            }

            result[target_id] = trx_sensor_configuration;
        }

        return result;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base::__printer__(float_precision, superscript_exponents));
        return printer;
    }
};

}
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
