// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7knavigationdatainterface.doc.hpp"

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datainterfaces/i_navigationdatainterface.hpp"
#include "s7kconfigurationdatainterface.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"
#include "s7kdatagraminterface.hpp"
#include "s7knavigationdatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatainterfaces {

template<typename t_ifstream>
class S7KNavigationDataInterface
    : public filetemplates::datainterfaces::I_NavigationDataInterface<
          S7KNavigationDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_NavigationDataInterface<
        S7KNavigationDataInterfacePerFile<t_ifstream>>;

  public:
    S7KNavigationDataInterface(
        std::shared_ptr<S7KConfigurationDataInterface<t_ifstream>> configuration_data_interface)
        : t_base(std::move(configuration_data_interface), "S7KNavigationDataInterface")
    {
    }
    ~S7KNavigationDataInterface() = default;

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
