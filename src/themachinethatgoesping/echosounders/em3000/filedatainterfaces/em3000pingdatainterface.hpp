// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/em3000pingdatainterface.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "../../filetemplates/helper/deduplicatebuffer.hpp"
#include "em3000configurationdatainterface.hpp"

#include "../em3000_datagrams.hpp"
#include "../em3000_types.hpp"
#include "em3000datagraminterface.hpp"
#include "em3000environmentdatainterface.hpp"
#include "em3000pingdatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatainterfaces {

template<typename t_ifstream>
class EM3000PingDataInterface
    : public filetemplates::datainterfaces::I_PingDataInterface<
          EM3000PingDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_PingDataInterface<
        EM3000PingDataInterfacePerFile<t_ifstream>>;

  public:
    EM3000PingDataInterface(
        std::shared_ptr<EM3000EnvironmentDataInterface<t_ifstream>> environment_data_interface)
        : t_base(std::move(environment_data_interface), "EM3000PingDataInterface")
    {
    }
    ~EM3000PingDataInterface() = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));
        return printer;
    }
};

}
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
