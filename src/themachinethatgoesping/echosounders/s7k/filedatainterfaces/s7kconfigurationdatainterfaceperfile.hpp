// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kconfigurationdatainterfaceperfile.doc.hpp"

/* std includes */
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/format.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../datagrams.hpp"
#include "../types.hpp"

#include "../../filetemplates/datainterfaces/i_configurationdatainterfaceperfile.hpp"
#include "s7kdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatainterfaces {

/**
 * @brief Interface that reads the sensor/sonar configuration (installation offsets, transducer
 * setup) of a single .s7k file.
 *
 * @note The datagram-processing functions (read_sensor_configuration) are not implemented yet. The
 * class currently only provides the structure so the configuration can be filled in in a later
 * step; until then the inherited base behavior (empty configuration fallback) is used.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class S7KConfigurationDataInterfacePerFile
    : public filetemplates::datainterfaces::I_ConfigurationDataInterfacePerFile<
          S7KDatagramInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_ConfigurationDataInterfacePerFile<
        S7KDatagramInterface<t_ifstream>>;

  public:
    S7KConfigurationDataInterfacePerFile()
        : t_base("S7KConfigurationDataInterfacePerFile")
    {
    }
    ~S7KConfigurationDataInterfacePerFile() = default;

    // TODO: implement read_sensor_configuration() (currently inherits the base "not implemented"
    // behavior which the base init_from_file catches and falls back to an empty configuration).
    navigation::SensorConfiguration read_sensor_configuration() final
    {
        // We do not have files with test datagrams so far, so if there is any datagram to read,
        // fail.
        uint64_t n_ok_datgrams = 0;
        n_ok_datgrams +=
            this->_datagram_infos_by_type.at_const(t_S7KDatagramIdentifier::FileHeader).size();

        if (this->_datagram_infos_all.size() != n_ok_datgrams)
        {
            throw std::runtime_error("Datagrams available, but read_sensor_configuration is not "
                                     "implemented for this yet.");
        }

        // If no datagram is available, return an empty navigation data object.
        return navigation::SensorConfiguration();
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("S7KConfigurationDataInterfacePerFile");

        return printer;
    }
};

} // namespace filedatainterfaces
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
