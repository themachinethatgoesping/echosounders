

// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallconfigurationdatainterface.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "../../filetemplates/datainterfaces/i_configurationdatainterface.hpp"

#include "../types.hpp"
#include "../datagrams.hpp"
#include "kongsbergallconfigurationdatainterfaceperfile.hpp"
#include "kongsbergalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KongsbergAllConfigurationDataInterface
    : public filetemplates::datainterfaces::I_ConfigurationDataInterface<
          KongsbergAllConfigurationDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_ConfigurationDataInterface<
        KongsbergAllConfigurationDataInterfacePerFile<t_ifstream>>;

  public:
    KongsbergAllConfigurationDataInterface()
        : t_base("KongsbergAllConfigurationDataInterface")
    {
    }
    ~KongsbergAllConfigurationDataInterface() = default;

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
