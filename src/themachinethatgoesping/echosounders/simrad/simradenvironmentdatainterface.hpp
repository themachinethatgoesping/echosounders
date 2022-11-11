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

#include "simradpackagecontainer.hpp"
#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
class SimradEnvironmentDataInterface : public fileinterfaces::I_EnvironmentDataInterface<SimradPackageContainer<t_ifstream>>
{

  public:
    SimradEnvironmentDataInterface()
        : fileinterfaces::I_EnvironmentDataInterface<SimradPackageContainer<t_ifstream>>("SimradEnvironmentDataInterface")
    {
    }
    ~SimradEnvironmentDataInterface() = default;

};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
