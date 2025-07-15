// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallnavigationdatainterface.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "../../filetemplates/datainterfaces/i_navigationdatainterface.hpp"
#include "kongsbergallconfigurationdatainterface.hpp"

#include "../types.hpp"
#include "../datagrams.hpp"
#include "kongsbergalldatagraminterface.hpp"
#include "kongsbergallnavigationdatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KongsbergAllNavigationDataInterface
    : public filetemplates::datainterfaces::I_NavigationDataInterface<
          KongsbergAllNavigationDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_NavigationDataInterface<
        KongsbergAllNavigationDataInterfacePerFile<t_ifstream>>;

  public:
    KongsbergAllNavigationDataInterface(
        std::shared_ptr<KongsbergAllConfigurationDataInterface<t_ifstream>> configuration_data_interface)
        : t_base(std::move(configuration_data_interface), "KongsbergAllNavigationDataInterface")
    {
    }
    ~KongsbergAllNavigationDataInterface() = default;

    // ----- kongsbergall specific functions -----

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base::__printer__(float_precision, superscript_exponents));
        return printer;
    }
};

}
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
