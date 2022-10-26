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

#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"

#include "../fileinterfaces/i_navigationinterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
class SimradNavigationDataInterface
    : public fileinterfaces::I_NavigationDataInterface<t_SimradDatagramType, t_ifstream>
{

  public:
    // use base class constructors

    SimradNavigationDataInterface(const std::shared_ptr<std::vector<std::string>>& file_paths)
        : fileinterfaces::I_NavigationDataInterface<t_SimradDatagramType, t_ifstream>(
              file_paths,
              "SimradNavigationDataInterface")
    {
    }

    void add_datagram([[maybe_unused]] const datagrams::NME0&                      datagram,
                      const fileinterfaces::PackageInfo_ptr<t_SimradDatagramType, t_ifstream>& package_info)
    {
        this->add_package_info(package_info);
    }
    void add_datagram([[maybe_unused]] const datagrams::MRU0&                      datagram,
                      const fileinterfaces::PackageInfo_ptr<t_SimradDatagramType, t_ifstream>& package_info)
    {
        this->add_package_info(package_info);
    }
};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoespingction macros --
