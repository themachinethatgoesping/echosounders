// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradenvironmentdatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_environmentdatainterface.hpp"
#include "simradconfigurationdatainterface.hpp"

#include "../simrad_datagrams.hpp"
#include "../simrad_types.hpp"
#include "simraddatagraminterface.hpp"
#include "simradnavigationdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradEnvironmentDataInterfacePerFile
    : public filetemplates::datainterfaces::I_EnvironmentDataInterfacePerFile<
          SimradNavigationDataInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_EnvironmentDataInterfacePerFile<
        SimradNavigationDataInterface<t_ifstream>>;

  public:
    SimradEnvironmentDataInterfacePerFile()
        : t_base("SimradEnvironmentDataInterfacePerFile")
    {
    }
    SimradEnvironmentDataInterfacePerFile(
        std::shared_ptr<SimradNavigationDataInterface<t_ifstream>> navigation_data_interface)
        : t_base(std::move(navigation_data_interface), "SimradEnvironmentDataInterfacePerFile")
    {
    }
    ~SimradEnvironmentDataInterfacePerFile() = default;

    // environment::EnvironmentInterpolatorLatLon read_environment_data() const final
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

        printer.register_section("SimradEnvironmentDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
