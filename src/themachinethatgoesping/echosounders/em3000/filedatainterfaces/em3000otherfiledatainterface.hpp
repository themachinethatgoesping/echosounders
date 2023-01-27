// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/em3000otherfiledatainterface.doc.hpp"

/* generated doc strings */
#include ".docstrings/simradotherfiledatainterface.doc.hpp"

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
#include "simradotherfiledatainterface_perfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradOtherDataInterface
    : public filetemplates::datainterfaces::I_FileDataInterface<
          SimradOtherFileDataInterface_PerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_FileDataInterface<
        SimradOtherFileDataInterface_PerFile<t_ifstream>>;

  public:
    SimradOtherDataInterface()
        : t_base("SimradOtherDataInterface")
    {
    }
    ~SimradOtherDataInterface() = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));
        return printer;
    }
};

}
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
