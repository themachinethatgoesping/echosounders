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
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../fileinterfaces/i_pingiterator.hpp"

#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
class SimradPingIterator : public fileinterfaces::I_PingIterator<SimradPing<t_ifstream>, t_ifstream>
{
    std::shared_ptr<std::vector<navigation::NavigationInterpolatorLatLon>>
        _navigation_interpolators =
            std::make_shared<std::vector<navigation::NavigationInterpolatorLatLon>>();

  public:
    SimradPingIterator(std::shared_ptr<std::vector<std::string>>            file_paths,
                       std::shared_ptr<std::vector<SimradPing<t_ifstream>>> pings)
        : fileinterfaces::I_PingIterator<SimradPing<t_ifstream>, t_ifstream>(file_paths, pings)
    {
    }

    SimradPingIterator(std::shared_ptr<std::vector<std::string>>            file_paths,
                       std::shared_ptr<std::vector<SimradPing<t_ifstream>>> pings,
                       long                                                 index_min,
                       long                                                 index_max,
                       long                                                 index_step)
        : fileinterfaces::I_PingIterator<SimradPing<t_ifstream>, t_ifstream>(file_paths,
                                                                             pings,
                                                                             index_min,
                                                                             index_max,
                                                                             index_step)
    {
    }

    //   public:
    //     // ----- objectprinter -----
    //     tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    //     {
    //         tools::classhelpers::ObjectPrinter printer("SimradPingIterator", float_precision);

    //         auto interface_printer =
    //             fileinterfaces::I_PingIterator<t_SimradDatagramType,
    //                                         t_ifstream>::__printer__(float_precision);

    //         printer.append(interface_printer);

    //         return printer;
    //     }

    //   public:
    //     // -- class helper function macros --
    //     // define info_string and print functions (needs the __printer__ function)
    //     __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoespingction macros --
