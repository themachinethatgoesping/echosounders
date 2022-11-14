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

#include "../fileinterfaces/i_filedatainterface.hpp"

#include "simradpackagedatainterface.hpp"
#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
class SimradOtherDataInterface : public fileinterfaces::I_FileDataInterface<SimradPackageDataInterface<t_ifstream>>
{

  public:
    SimradOtherDataInterface()
        : fileinterfaces::I_FileDataInterface<SimradPackageDataInterface<t_ifstream>>("SimradOtherDataInterface")
    {
    }
    ~SimradOtherDataInterface() = default;

};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
