// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_navigationdatainterface.hpp"
#include "simradconfigurationdatainterface.hpp"

#include "../simrad_datagrams.hpp"
#include "../simrad_types.hpp"
#include "simraddatagraminterface.hpp"
#include "simradnavigationperfiledatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradNavigationDataInterface
    : public filetemplates::datainterfaces::I_NavigationDataInterface<
          SimradNavigationPerFileDataInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_NavigationDataInterface<
        SimradNavigationPerFileDataInterface<t_ifstream>>;

  public:
    SimradNavigationDataInterface(
        std::shared_ptr<SimradConfigurationDataInterface<t_ifstream>> configuration_data_interface)
        : t_base(std::move(configuration_data_interface), "SimradNavigationDataInterface")
    {
    }
    ~SimradNavigationDataInterface() = default;

    void set_min_gga_quality(int min_gga_quality)
    {
        // const auto just means that the shared_ptr does not get copied
        // but the object it points is not const
        for (const auto& inter : this->_interface_per_file)
            inter->set_min_gga_quality(min_gga_quality);
    }
    void set_max_gga_quality(int max_gga_quality)
    {
        // const auto just means that the shared_ptr does not get copied
        // but the object it points is not const
        for (const auto& inter : this->_interface_per_file)
            inter->set_max_gga_quality(max_gga_quality);
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base::__printer__(float_precision));
        return printer;
    }
};

}
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
