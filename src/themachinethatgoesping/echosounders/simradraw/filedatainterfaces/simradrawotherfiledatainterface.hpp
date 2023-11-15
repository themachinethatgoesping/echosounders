// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawotherfiledatainterface.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_filedatainterface.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"
#include "simradrawdatagraminterface.hpp"
#include "simradrawotherfiledatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatainterfaces {

/**
 * @brief FileDataInterface (for multiple files) for packages that fit neither of the other
 * FileDataInterfaces (Configuration, Navigation, Annotation, Environment, Ping)
 *
 * No datagram caching is implemented for this interface. Accessed packages are always read from
 * file
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class SimradRawOtherFileDataInterface
    : public filetemplates::datainterfaces::I_FileDataInterface<
          init_c_simradrawotherfiledatainterfaceperfile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_FileDataInterface<
        init_c_simradrawotherfiledatainterfaceperfile<t_ifstream>>;

  public:
    SimradRawOtherFileDataInterface()
        : t_base("SimradRawOtherFileDataInterface")
    {
    }
    ~SimradRawOtherFileDataInterface() = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));
        return printer;
    }
};

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
