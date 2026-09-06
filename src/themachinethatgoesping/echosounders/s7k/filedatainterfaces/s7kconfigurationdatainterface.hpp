// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kconfigurationdatainterface.doc.hpp"

/* std includes */
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/format.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"

#include "../../filetemplates/datainterfaces/i_configurationdatainterface.hpp"
#include "s7kconfigurationdatainterfaceperfile.hpp"
#include "s7kdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatainterfaces {

template<typename t_ifstream>
class S7KConfigurationDataInterface
    : public filetemplates::datainterfaces::I_ConfigurationDataInterface<
          S7KConfigurationDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_ConfigurationDataInterface<
        S7KConfigurationDataInterfacePerFile<t_ifstream>>;

  public:
    S7KConfigurationDataInterface()
        : t_base("S7KConfigurationDataInterface")
    {
    }
    ~S7KConfigurationDataInterface() = default;

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
