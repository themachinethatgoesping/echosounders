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

#include "../fileinterfaces/i_pinginterface.hpp"

#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"
#include "simradfiledata.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
class SimradPingInterface : public fileinterfaces::I_PingInterface<t_SimradDatagramType, t_ifstream>
{
    std::vector<std::shared_ptr<SimradFileData>> _file_data;

    std::shared_ptr<std::vector<navigation::NavigationInterpolatorLatLon>>
        _navigation_interpolators =
            std::make_shared<std::vector<navigation::NavigationInterpolatorLatLon>>();

  public:
    SimradPingInterface(
        std::shared_ptr<std::vector<std::string>> file_paths,
        std::shared_ptr<std::vector<fileinterfaces::PackageInfo<t_SimradDatagramType>>>
            package_infos)
        : fileinterfaces::I_PingInterface<t_SimradDatagramType, t_ifstream>(file_paths,
                                                                            package_infos)
    {
    }

    template<typename t_datagram>
    void add_datagram(const t_datagram& datagram, size_t file_cnt)
    {
        file_data(file_cnt)->add_datagram(datagram);
    }

    const std::vector<navigation::NavigationInterpolatorLatLon>& get_navigation_interpolators()
        const
    {
        return *_navigation_interpolators;
    }

    const std::shared_ptr<SimradFileData>& file_data(size_t file_cnt)
    {
        while (file_cnt >= _file_data.size())
        {
            // TODO: this makes everything crash. Why?
            // if (file_cnt >= this->_file_paths->size())
            //     throw std::runtime_error(fmt::format(
            //         "ERROR[SimradPingInterface::file_data()]: file_cnt {} >= _file_paths.size() {}",
            //         file_cnt,
            //         this->_file_paths->size()));

            _file_data.push_back(std::make_shared<SimradFileData>());
        }

        return _file_data[file_cnt];
    }

  public:
    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("SimradPingInterface", float_precision);

        auto interface_printer =
            fileinterfaces::I_PingInterface<t_SimradDatagramType, t_ifstream>::__printer__(
                float_precision);

        printer.append(interface_printer);

        return printer;
    }

  public:
    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoespingction macros --