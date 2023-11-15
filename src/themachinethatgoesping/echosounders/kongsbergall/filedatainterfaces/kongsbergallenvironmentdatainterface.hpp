// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallenvironmentdatainterface.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_environmentdatainterface.hpp"
#include "kongsbergallconfigurationdatainterface.hpp"

#include "../kongsbergall_datagrams.hpp"
#include "../kongsbergall_types.hpp"
#include "kongsbergalldatagraminterface.hpp"
#include "kongsbergallenvironmentdatainterfaceperfile.hpp"
#include "kongsbergallnavigationdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KongsbergAllEnvironmentDataInterface
    : public filetemplates::datainterfaces::I_EnvironmentDataInterface<
          KongsbergAllEnvironmentDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_EnvironmentDataInterface<
        KongsbergAllEnvironmentDataInterfacePerFile<t_ifstream>>;

  public:
    KongsbergAllEnvironmentDataInterface(
        std::shared_ptr<KongsbergAllNavigationDataInterface<t_ifstream>> navigation_data_interface)
        : t_base(std::move(navigation_data_interface), "KongsbergAllEnvironmentDataInterface")
    {
    }
    ~KongsbergAllEnvironmentDataInterface() = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));
        return printer;
    }
};

}
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
