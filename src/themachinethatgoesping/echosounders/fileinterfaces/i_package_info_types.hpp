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

#include "inputfilemanager.hpp"

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

template<typename t_DatagramIdentifier, typename t_ifstream>
class PackageInfo
{
    size_t                        _file_nr;  ///< file number of this package
    typename t_ifstream::pos_type _file_pos; ///< file position of this package TODO: is this the
                                             ///< same for ifstream and MappedFileStream?
    std::shared_ptr<InputFileManager<t_ifstream>> _input_file_manager; ///< input file manager

    double               _timestamp;           ///< timestamp (unixtime) of this package
    t_DatagramIdentifier _datagram_identifier; ///< datagram type of this package

  public:
    PackageInfo(size_t                                        file_nr,
                typename t_ifstream::pos_type                 file_pos,
                std::shared_ptr<InputFileManager<t_ifstream>> input_file_manager,
                double                                        timestamp,
                t_DatagramIdentifier                          datagram_identifier)
        : _file_nr(file_nr)
        , _file_pos(file_pos)
        , _input_file_manager(input_file_manager)
        , _timestamp(timestamp)
        , _datagram_identifier(datagram_identifier)
    {
    }

    size_t      get_file_nr() const { return _file_nr; }
    t_ifstream& get_stream()
    {
        auto& ifs = _input_file_manager->get_active_stream(_file_nr);

        return ifs;
    }
    t_ifstream& get_stream_and_seek()
    {
        auto& ifs = get_stream();
        ifs.seekg(_file_pos);

        return ifs;
    }
    double               get_timestamp() const { return _timestamp; }
    t_DatagramIdentifier get_datagram_identifier() const { return _datagram_identifier; }
    typename t_ifstream::pos_type get_file_pos() const { return _file_pos; }
};

template<typename t_DatagramIdentifier, typename t_ifstream>
using PackageInfo_ptr = std::shared_ptr<PackageInfo<t_DatagramIdentifier, t_ifstream>>;

// TODO: explicitly derive t_ from i_ using concepts from c++20
template<typename t_DatagramIdentifier, typename t_ifstream>
struct DataFileInfo
{

    std::string file_path;
    size_t      file_size;

    /* header positions */
    std::shared_ptr<std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>> package_infos_all =
        std::make_shared<std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>>(); ///< all package
                                                                                ///< headers
    tools::helper::DefaultSharedPointerMap<t_DatagramIdentifier,
                                           std::vector<PackageInfo_ptr<t_DatagramIdentifier, t_ifstream>>>
        package_infos_by_type; ///< package headers sorted by type
};

}
}
}
