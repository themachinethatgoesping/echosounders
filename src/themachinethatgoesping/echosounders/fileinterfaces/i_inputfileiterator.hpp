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
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

#include "i_package_info_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

template<typename t_DatagramType,
         typename t_DatagramIdentifier,
         typename t_ifstream,
         typename t_DatagramTypeFactory = t_DatagramType>
class I_InputFileIterator
{
  protected:
    /* header positions */
    std::shared_ptr<std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>> _package_infos;

    tools::pyhelper::PyIndexer _pyindexer;

  public:
    I_InputFileIterator(
        std::shared_ptr<std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>>
            package_infos)
        : _package_infos(package_infos)
        , _pyindexer(package_infos->size())
    {
    }

    I_InputFileIterator(
        std::shared_ptr<std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>>
             package_infos,
        long start,
        long end,
        long step = 1)
        : _package_infos(package_infos)
        , _pyindexer(package_infos->size(), start, end, step)
    {
    }

    I_InputFileIterator<t_DatagramType, t_DatagramIdentifier, t_ifstream, t_DatagramTypeFactory>&
    operator()(long start, long end, long step = 1)
    {
        _pyindexer = tools::pyhelper::PyIndexer(_package_infos->size(), start, end, step);

        return *this;
    }

    size_t size() const { return _pyindexer.size(); }

    t_DatagramType at(long index)
    {
        const auto& package_info = _package_infos->at(_pyindexer(index));
        try
        {
            auto& ifs = package_info->get_stream_and_seek();

            return t_DatagramTypeFactory::from_stream(ifs, package_info->get_datagram_identifier());
        }
        catch (std::exception& e)
        {
            auto msg = fmt::format("Error reading datagram header: {}\n", e.what());
            msg += fmt::format("index: {}\n", index);
            msg += fmt::format("pyindex: {}\n", _pyindexer(index));
            msg += fmt::format("__package_infos->size(): {}\n", _package_infos->size());
            msg += fmt::format("pos: {}\n", package_info->get_file_pos());
            throw std::runtime_error(msg);
        }
    }
};

}
}
}
