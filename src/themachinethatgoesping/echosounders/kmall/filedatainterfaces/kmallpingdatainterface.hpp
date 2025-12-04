// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kmallpingdatainterface.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "../../filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "kmallconfigurationdatainterface.hpp"

#include "../types.hpp"
#include "../datagrams.hpp"
#include "kmalldatagraminterface.hpp"
#include "kmallenvironmentdatainterface.hpp"
#include "kmallpingdatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KMALLPingDataInterface
    : public filetemplates::datainterfaces::I_PingDataInterface<
          KMALLPingDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_PingDataInterface<
        KMALLPingDataInterfacePerFile<t_ifstream>>;

  public:
    KMALLPingDataInterface(
        std::shared_ptr<KMALLEnvironmentDataInterface<t_ifstream>> environment_data_interface)
        : t_base(std::move(environment_data_interface), "KMALLPingDataInterface")
    {
    }
    ~KMALLPingDataInterface() = default;

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
