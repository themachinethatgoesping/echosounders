// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawpingdatainterface.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "../../filetemplates/helper/deduplicatebuffer.hpp"
#include "simradrawconfigurationdatainterface.hpp"

#include "../simradraw_datagrams.hpp"
#include "../simradraw_types.hpp"
#include "simradrawdatagraminterface.hpp"
#include "simradrawenvironmentdatainterface.hpp"
#include "simradrawpingdatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradRawPingDataInterface
    : public filetemplates::datainterfaces::I_PingDataInterface<
          SimradRawPingDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_PingDataInterface<
        SimradRawPingDataInterfacePerFile<t_ifstream>>;

  public:
    SimradRawPingDataInterface(
        std::shared_ptr<SimradRawEnvironmentDataInterface<t_ifstream>> environment_data_interface)
        : t_base(std::move(environment_data_interface), "SimradRawPingDataInterface")
    {
    }
    ~SimradRawPingDataInterface() = default;

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
