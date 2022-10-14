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
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

class MappedFileStream : public boost::iostreams::stream<boost::iostreams::mapped_file_source>
{
  public:
    MappedFileStream(const std::string&      file_path,
                     std::ios_base::openmode mode = std::ios_base::binary)
        : boost::iostreams::stream<boost::iostreams::mapped_file_source>(
              boost::iostreams::mapped_file_source(file_path),
              mode)
    {
    }
};

template<typename t_DatagramIdentifier>
struct PackageInfo
{
    size_t                  file_nr;  ///< file number of this package
    std::ifstream::pos_type file_pos; ///< file position of this package TODO: is this the same for
                                      ///< ifstream and MappedFileStream?
    double               timestamp;   ///< timestamp (unixtime) of this package
    t_DatagramIdentifier datagram_identifier; ///< datagram type of this package
};

template<typename t_DatagramIdentifier>
using PackageInfo_ptr = std::shared_ptr<PackageInfo<t_DatagramIdentifier>>;

// TODO: explicitly derive t_ from i_ using concepts from c++20
template<typename t_DatagramIdentifier>
struct DataFileInfo
{

    std::string file_path;
    size_t      file_size;

    /* header positions */
    std::shared_ptr<std::vector<PackageInfo_ptr<t_DatagramIdentifier>>> package_infos_all =
        std::make_shared<std::vector<PackageInfo_ptr<t_DatagramIdentifier>>>(); ///< all package
                                                                                ///< headers
    tools::helper::DefaultSharedPointerMap<t_DatagramIdentifier,
                                           std::vector<PackageInfo_ptr<t_DatagramIdentifier>>>
        package_infos_by_type; ///< package headers sorted by type
};

}
}
}
