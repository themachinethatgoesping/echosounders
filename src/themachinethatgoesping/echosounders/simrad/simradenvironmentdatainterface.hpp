// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../fileinterfaces/i_environmentdatainterface.hpp"

#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"
#include "simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
class SimradEnvironmentPerFileDataInterface
    : public fileinterfaces::I_EnvironmentPerFileDataInterface<SimradDatagramInterface<t_ifstream>>
{
    using t_base =
        fileinterfaces::I_EnvironmentPerFileDataInterface<SimradDatagramInterface<t_ifstream>>;

  public:
    SimradEnvironmentPerFileDataInterface()
        : t_base("SimradEnvironmentPerFileDataInterface")
    {
    }
    ~SimradEnvironmentPerFileDataInterface() = default;

    // --------------------- simrad specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("SimradEnvironmentPerFileDataInterface");

        return printer;
    }
};

template<typename t_ifstream>
class SimradEnvironmentDataInterface
    : public fileinterfaces::I_EnvironmentDataInterface<
          SimradEnvironmentPerFileDataInterface<t_ifstream>>
{
    using t_base = fileinterfaces::I_EnvironmentDataInterface<
        SimradEnvironmentPerFileDataInterface<t_ifstream>>;

  public:
    SimradEnvironmentDataInterface()
        : t_base("SimradEnvironmentDataInterface")
    {
    }
    ~SimradEnvironmentDataInterface() = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));
        return printer;
    }
};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
