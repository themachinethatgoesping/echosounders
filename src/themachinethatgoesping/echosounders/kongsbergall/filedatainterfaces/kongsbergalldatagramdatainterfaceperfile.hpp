// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergalldatagramdatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_filedatainterface.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"
#include "kongsbergalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatainterfaces {

/**
 * @brief FileDataInterface (for single files) for packages that fit neither of the other
 * FileDataInterfaces (Configuration, Navigation, Annotation, Environment, Ping)
 *
 * No datagram caching is implemented for this interface. Accessed packages are always read from
 * file
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class KongsbergAllDatagramDataInterfacePerFile
    : public filetemplates::datainterfaces::I_FileDataInterfacePerFile<
          KongsbergAllDatagramInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_FileDataInterfacePerFile<
        KongsbergAllDatagramInterface<t_ifstream>>;

  public:
    KongsbergAllDatagramDataInterfacePerFile()
        : t_base("KongsbergAllDatagramDataInterfacePerFile")
    {
    }
    ~KongsbergAllDatagramDataInterfacePerFile() = default;

    // --------------------- kongsbergall specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("KongsbergAllDatagramDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
