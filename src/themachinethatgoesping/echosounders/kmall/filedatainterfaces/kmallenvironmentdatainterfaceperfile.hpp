// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kmallenvironmentdatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "../../filetemplates/datainterfaces/i_environmentdatainterface.hpp"
#include "kmallconfigurationdatainterface.hpp"

#include "../types.hpp"
#include "../datagrams.hpp"
#include "kmalldatagraminterface.hpp"
#include "kmallnavigationdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KMALLEnvironmentDataInterfacePerFile
    : public filetemplates::datainterfaces::I_EnvironmentDataInterfacePerFile<
          KMALLNavigationDataInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_EnvironmentDataInterfacePerFile<
        KMALLNavigationDataInterface<t_ifstream>>;

  public:
    KMALLEnvironmentDataInterfacePerFile()
        : t_base("KMALLEnvironmentDataInterfacePerFile")
    {
    }
    KMALLEnvironmentDataInterfacePerFile(
        std::shared_ptr<KMALLNavigationDataInterface<t_ifstream>> navigation_data_interface)
        : t_base(std::move(navigation_data_interface), "KMALLEnvironmentDataInterfacePerFile")
    {
    }
    ~KMALLEnvironmentDataInterfacePerFile() = default;

    // environment::EnvironmentInterpolatorLatLon read_environment_data() const final
    // {
    //     return navi;
    // }

    // --------------------- kmall specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("KMALLEnvironmentDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
