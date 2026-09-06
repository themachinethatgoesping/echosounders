// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7knavigationdatainterfaceperfile.doc.hpp"

/* std includes */
#include <fmt/format.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datainterfaces/i_navigationdatainterface.hpp"
#include "s7kconfigurationdatainterface.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"
#include "s7kdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatainterfaces {

/**
 * @brief Interface that reads the navigation (position, attitude, heading) of a single .s7k file.
 *
 * @note The datagram-processing function (read_navigation_data) is not implemented yet. The class
 * currently only provides the structure so the navigation can be filled in in a later step.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class S7KNavigationDataInterfacePerFile
    : public filetemplates::datainterfaces::I_NavigationDataInterfacePerFile<
          S7KConfigurationDataInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_NavigationDataInterfacePerFile<
        S7KConfigurationDataInterface<t_ifstream>>;

  public:
    S7KNavigationDataInterfacePerFile()
        : t_base("S7KNavigationDataInterfacePerFile")
    {
    }
    S7KNavigationDataInterfacePerFile(
        std::shared_ptr<S7KConfigurationDataInterface<t_ifstream>> configuration_data_interface)
        : t_base(std::move(configuration_data_interface), "S7KNavigationDataInterfacePerFile")
    {
    }
    ~S7KNavigationDataInterfacePerFile() = default;

    // TODO: implement read_navigation_data() (currently inherits the base "not implemented"
    // behavior).

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("S7KNavigationDataInterfacePerFile");

        return printer;
    }
};

} // namespace filedatainterfaces
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
