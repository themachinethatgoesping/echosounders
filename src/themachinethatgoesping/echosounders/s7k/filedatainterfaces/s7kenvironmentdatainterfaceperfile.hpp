// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kenvironmentdatainterfaceperfile.doc.hpp"

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datainterfaces/i_environmentdatainterface.hpp"
#include "s7kconfigurationdatainterface.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"
#include "s7kdatagraminterface.hpp"
#include "s7knavigationdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatainterfaces {

/**
 * @brief Interface that reads the environment (sound velocity, CTD, water properties) of a single
 * .s7k file.
 *
 * @note The datagram-processing functions are not implemented yet. The class currently only
 * provides the structure so the environment can be filled in in a later step.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class S7KEnvironmentDataInterfacePerFile
    : public filetemplates::datainterfaces::I_EnvironmentDataInterfacePerFile<
          S7KNavigationDataInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_EnvironmentDataInterfacePerFile<
        S7KNavigationDataInterface<t_ifstream>>;

  public:
    S7KEnvironmentDataInterfacePerFile()
        : t_base("S7KEnvironmentDataInterfacePerFile")
    {
    }
    S7KEnvironmentDataInterfacePerFile(
        std::shared_ptr<S7KNavigationDataInterface<t_ifstream>> navigation_data_interface)
        : t_base(std::move(navigation_data_interface), "S7KEnvironmentDataInterfacePerFile")
    {
    }
    ~S7KEnvironmentDataInterfacePerFile() = default;

    // TODO: implement read_environment_data() (currently inherits the base behavior).

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("S7KEnvironmentDataInterfacePerFile");

        return printer;
    }
};

} // namespace filedatainterfaces
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
