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

#include "../../filetemplates/datainterfaces/i_annotationdatainterface.hpp"

#include "../simrad_datagrams.hpp"
#include "../simrad_types.hpp"
#include "simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradAnnotationPerFileDataInterface
    : public filetemplates::datainterfaces::I_AnnotationPerFileDataInterface<
          SimradDatagramInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_AnnotationPerFileDataInterface<
        SimradDatagramInterface<t_ifstream>>;

  public:
    SimradAnnotationPerFileDataInterface()
        : t_base("SimradAnnotationPerFileDataInterface")
    {
    }
    ~SimradAnnotationPerFileDataInterface() = default;

    // --------------------- simrad specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("SimradAnnotationPerFileDataInterface");

        return printer;
    }
};

}
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping