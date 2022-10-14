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
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "i_inputfileiterator.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_DatagramIdentifier, typename t_ifstream>
class I_PingDataInterface
{
  protected:
    std::shared_ptr<std::vector<std::string>> _file_paths;

    /* the opened input file stream */
    std::unique_ptr<t_ifstream> _input_file_stream;
    long                        active_file_nr = -1;

    /* header positions */
    std::shared_ptr<const std::vector<PackageInfo_ptr<t_DatagramIdentifier>>> _package_infos;

  public:
    I_PingDataInterface(std::shared_ptr<std::vector<std::string>>                       file_paths,
                    std::shared_ptr<std::vector<PackageInfo_ptr<t_DatagramIdentifier>>> package_infos)
        : _file_paths(file_paths)
        , _package_infos(package_infos)
    {
    }

    // const std::string& get_file_path(size_t file_nr)
    // {
    //    return  _file_paths->at(file_nr);
    // }

    size_t size() const { return _package_infos->size(); }

    t_ifstream& get_active_stream(size_t file_nr)
    {
        // TODO: active_file_nr is currently not updated when _file_paths is changed in the master
        if (long(file_nr) != active_file_nr)
        {
            active_file_nr = long(file_nr);
            _input_file_stream =
                std::make_unique<t_ifstream>(_file_paths->at(file_nr), std::ios_base::binary);
        }
        return *_input_file_stream;
    }

    template<typename t_DatagramType, typename t_DatagramTypeFactory = t_DatagramType>
    t_DatagramType at(const PackageInfo_ptr<t_DatagramIdentifier>& package_info)
    {
        try
        {
            t_ifstream& ifs = get_active_stream(package_info->file_nr);
            ifs.seekg(package_info->file_pos);

            return t_DatagramTypeFactory::from_stream(ifs, package_info->datagram_identifier);
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
