// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kmallnavigationdatainterface.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "../../filetemplates/datainterfaces/i_navigationdatainterface.hpp"
#include "kmallconfigurationdatainterface.hpp"

#include "../types.hpp"
#include "../datagrams.hpp"
#include "kmalldatagraminterface.hpp"
#include "kmallnavigationdatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KMALLNavigationDataInterface
    : public filetemplates::datainterfaces::I_NavigationDataInterface<
          KMALLNavigationDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_NavigationDataInterface<
        KMALLNavigationDataInterfacePerFile<t_ifstream>>;

  public:
    KMALLNavigationDataInterface(
        std::shared_ptr<KMALLConfigurationDataInterface<t_ifstream>> configuration_data_interface)
        : t_base(std::move(configuration_data_interface), "KMALLNavigationDataInterface")
    {
    }
    ~KMALLNavigationDataInterface() = default;

    // ----- kmall specific functions -----

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base::__printer__(float_precision, superscript_exponents));
        return printer;
    }
};

}
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
