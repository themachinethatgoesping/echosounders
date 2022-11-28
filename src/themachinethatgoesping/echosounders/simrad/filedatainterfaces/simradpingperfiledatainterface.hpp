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
class SimradPingPerFileDataInterface
    : public filetemplates::datainterfaces::I_PingPerFileDataInterface<
          SimradEnvironmentDataInterface<t_ifstream>,
          filedatacontainers::SimradPingContainer<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_PingPerFileDataInterface<
        SimradEnvironmentDataInterface<t_ifstream>,
        filedatacontainers::SimradPingContainer<t_ifstream>>;

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

}
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
