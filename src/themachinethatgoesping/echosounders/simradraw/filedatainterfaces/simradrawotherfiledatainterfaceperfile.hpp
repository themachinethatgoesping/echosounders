// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawotherfiledatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_filedatainterface.hpp"

#include "../simradraw_datagrams.hpp"
#include "../simradraw_types.hpp"
#include "simradrawdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
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
class init_c_simradrawotherfiledatainterfaceperfile
    : public filetemplates::datainterfaces::I_FileDataInterfacePerFile<
          SimradRawDatagramInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_FileDataInterfacePerFile<
        SimradRawDatagramInterface<t_ifstream>>;

  public:
    init_c_simradrawotherfiledatainterfaceperfile()
        : t_base("init_c_simradrawotherfiledatainterfaceperfile")
    {
    }
    ~init_c_simradrawotherfiledatainterfaceperfile() = default;

    // --------------------- simradraw specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("init_c_simradrawotherfiledatainterfaceperfile");

        return printer;
    }
};

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
