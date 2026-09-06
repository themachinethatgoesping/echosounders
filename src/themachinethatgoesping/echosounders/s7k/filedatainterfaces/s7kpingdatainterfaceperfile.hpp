// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kpingdatainterfaceperfile.doc.hpp"

/* std includes */
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

    // TODO: implement read_pings() (currently inherits the base "not implemented" behavior).

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
