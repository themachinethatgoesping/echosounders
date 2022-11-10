// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

#include <fstream>
#include <limits>
#include <memory>
#include <unordered_map>
#include <vector>

/* memory mapping */
#include <boost/iostreams/device/mapped_file.hpp> // for mmap
#include <boost/iostreams/stream.hpp>             // for stream

#include <fmt/core.h>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "i_inputfileiterator.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_DatagramIdentifier, typename t_ifstream>
class I_PingDataInterface
{
  protected:
    /* header positions */
    std::shared_ptr<const std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>> _package_infos;

  public:
    I_PingDataInterface(
        std::shared_ptr<std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>> package_infos)
        : _package_infos(package_infos)
    {
    }

    // const std::string& get_file_path(size_t file_nr)
    // {
    //    return  _file_paths->at(file_nr);
    // }

    size_t size() const { return _package_infos->size(); }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    t_DatagramType at(const PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>& package_info)
    {
        try
        {
            t_ifstream& ifs = package_info->get_stream_and_seek();

            return t_DatagramTypeFactory::from_stream(ifs, package_info->get_datagram_identifier());
        }
        catch (std::exception& e)
        {

            auto msg = fmt::format("Error reading datagram header: {}\n", e.what());
            msg += fmt::format("pos: {}\n", package_info->file_pos);
            throw std::runtime_error(msg);
        }
    }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    t_DatagramType at(size_t index)
    {
        return this->at<t_DatagramType, t_DatagramTypeFactory>(_package_infos->at(index));
    }
};

}
}
}
