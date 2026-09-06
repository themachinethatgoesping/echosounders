// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kotherfiledatainterface.doc.hpp"

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"

#include "../../filetemplates/datainterfaces/i_filedatainterface.hpp"

#include "../datagrams.hpp"
#include "s7kdatagraminterface.hpp"
#include "s7kotherfiledatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatainterfaces {

/**
 * @brief FileDataInterface (for multiple files) for packages that fit neither of the other
 * FileDataInterfaces (Configuration, Navigation, Environment, Ping)
 *
 * No datagram caching is implemented for this interface. Accessed packages are always read from
 * file.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class S7KOtherFileDataInterface
    : public filetemplates::datainterfaces::I_FileDataInterface<
          S7KOtherFileDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_FileDataInterface<
        S7KOtherFileDataInterfacePerFile<t_ifstream>>;

  public:
    S7KOtherFileDataInterface()
        : t_base("S7KOtherFileDataInterface")
    {
    }
    ~S7KOtherFileDataInterface() = default;

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
