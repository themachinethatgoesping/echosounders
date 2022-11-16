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

#include "../fileinterfaces/i_annotationdatainterface.hpp"

#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"
#include "simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
class SimradAnnotationDataInterface
    : public fileinterfaces::I_AnnotationDataInterface<SimradDatagramInterface<t_ifstream>>
{

  public:
    SimradAnnotationDataInterface()
        : fileinterfaces::I_AnnotationDataInterface<SimradDatagramInterface<t_ifstream>>(
              "SimradAnnotationDataInterface")
    {
    }
    ~SimradAnnotationDataInterface() = default;
};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
