// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawnavigationdatainterface.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "simradrawconfigurationdatainterface.hpp"

#include "../types.hpp"
#include "../datagrams.hpp"
#include "simradrawdatagraminterface.hpp"
#include "simradrawnavigationdatainterfaceperfile.hpp"

#include "../../filetemplates/datainterfaces/i_navigationdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradRawNavigationDataInterface
    : public filetemplates::datainterfaces::I_NavigationDataInterface<
          SimradRawNavigationDataInterfacePerFile<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_NavigationDataInterface<
        SimradRawNavigationDataInterfacePerFile<t_ifstream>>;

  public:
    SimradRawNavigationDataInterface(
        std::shared_ptr<SimradRawConfigurationDataInterface<t_ifstream>> configuration_data_interface)
        : t_base(std::move(configuration_data_interface), "SimradRawNavigationDataInterface")
    {
    }
    ~SimradRawNavigationDataInterface() = default;

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
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base::__printer__(float_precision, superscript_exponents));
        return printer;
    }
};

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
