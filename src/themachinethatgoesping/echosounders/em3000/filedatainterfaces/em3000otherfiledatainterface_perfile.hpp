// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/em3000otherfiledatainterface_perfile.doc.hpp"

/* generated doc strings */
#include ".docstrings/simradotherfiledatainterface_perfile.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_filedatainterface.hpp"

#include "../simrad_datagrams.hpp"
#include "../simrad_types.hpp"
#include "simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradOtherFileDataInterface_PerFile
    : public filetemplates::datainterfaces::I_FileDataInterface_PerFile<
          SimradDatagramInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_FileDataInterface_PerFile<
        SimradDatagramInterface<t_ifstream>>;

  public:
    SimradOtherFileDataInterface_PerFile()
        : t_base("SimradOtherFileDataInterface_PerFile")
    {
    }
    ~SimradOtherFileDataInterface_PerFile() = default;

    // --------------------- simrad specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("SimradOtherFileDataInterface_PerFile");

        return printer;
    }
};

}
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
