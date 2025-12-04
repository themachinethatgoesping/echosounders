// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kmallotherfiledatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"

#include "../../filetemplates/datainterfaces/i_filedatainterface.hpp"

#include "../datagrams.hpp"
#include "kmalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatainterfaces {

/**
 * @brief FileDataInterface (for single files) for packages that fit neither of the other
 * FileDataInterfaces (Configuration, Navigation, Environment, Ping)
 *
 * No datagram caching is implemented for this interface. Accessed packages are always read from
 * file
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class KMALLOtherFileDataInterfacePerFile
    : public filetemplates::datainterfaces::I_FileDataInterfacePerFile<
          KMALLDatagramInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_FileDataInterfacePerFile<
        KMALLDatagramInterface<t_ifstream>>;

  public:
    KMALLOtherFileDataInterfacePerFile()
        : t_base("KMALLOtherFileDataInterfacePerFile")
    {
    }
    ~KMALLOtherFileDataInterfacePerFile() = default;

    // --------------------- kmall specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("KMALLOtherFileDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
