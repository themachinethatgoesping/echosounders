// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kpingdatainterface.doc.hpp"

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "s7kconfigurationdatainterface.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"
#include "s7kdatagraminterface.hpp"
#include "s7kenvironmentdatainterface.hpp"
#include "s7kpingdatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatainterfaces {

template<typename t_ifstream>
class S7KPingDataInterface
    : public filetemplates::datainterfaces::I_PingDataInterface<
          S7KPingDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_PingDataInterface<
        S7KPingDataInterfacePerFile<t_ifstream>>;

  public:
    S7KPingDataInterface(
        std::shared_ptr<S7KEnvironmentDataInterface<t_ifstream>> environment_data_interface)
        : t_base(std::move(environment_data_interface), "S7KPingDataInterface")
    {
    }
    ~S7KPingDataInterface() = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base::__printer__(float_precision, superscript_exponents));
        return printer;
    }
};

} // namespace filedatainterfaces
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
