// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_filecache.doc.hpp"

/* generated doc strings */
#include ".docstrings/fileinfo.doc.hpp"

/* generated doc strings */
#include ".docstrings/datagraminfo.doc.hpp"

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

#include "../internal/inputfilemanager.hpp"
#include "cache_structures/filepackageindex.hpp"
#include "datagraminfo.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

template<typename t_DatagramIdentifier>
class I_FileCache
{
    std::string file_name; // for reference / checking file validity
    size_t      file_size; // for reference / checking file validity

    /* cache positions */
    // positions of caches in files, first is first stream position, second is size in bytes
    // If not initialized, this file was not written or read yet
    std::unordered_map<std::string, std::tupel<size_t, size_t>> _cache_header;

    /* header positions */
    cache_structures::FilePackageCache<t_DatagramIdentifier> _file_package_cache;

    I_FileCache() = default;
    I_FileCache(const std::string& file_name, size_t file_size)
        : file_name(file_name)
        , file_size(file_size)
    {
    }    

    bool operator==(const I_FileCache&) const = default;

    // ----- to/from stream interface -----
    static I_FileCache from_stream(std::istream& is)
    {
        I_FileCache data;

        data.file_name = tools::classhelper::stream::container_from_stream<std::string>(is);
        is.read(reinterpret_cast<char*>(&data.file_size), sizeof(size_t));

        size_t size;
        is.read(reinterpret_cast<char*>(&size), sizeof(size_t));
        data.datagram_infos.resize(size);
        for (size_t i = 0; i < size; ++i)
        {
            data.datagram_infos[i] =
                datatypes::DatagramInfoData<t_DatagramIdentifier>::from_stream(is);
        }

        return data;
    }

    void to_stream(std::ostream& os) const
    {
        tools::classhelper::stream::container_to_stream<std::string>(os, file_name);
        os.write(reinterpret_cast<const char*>(&file_size), sizeof(size_t));

        size_t size = datagram_infos.size();
        os.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
        for (size_t i = 0; i < size; ++i)
        {
            datagram_infos[i].to_stream(os);
        }
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("DatagramInfoData", float_precision);

        // raw values
        printer.register_string("file_name", file_name);
        printer.register_value("file_size", size_t(file_size));

        // cache infos
        printer.register_section("cache infos");
        for (auto& [key, value] : _cache_header)
        {
            printer.register_value(key, value);
        }

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(I_FileCache)
};

/**
 * @brief struct for storing the file infos (returned by scan_for_datagrams)
 *
 */
template<typename t_DatagramIdentifier, typename t_ifstream>
struct FileInfos
{
    std::string file_name;
    size_t      file_size;

    /* header positions */
    std::vector<datatypes::DatagramInfo_ptr<t_DatagramIdentifier,
                                            t_ifstream>>
        datagram_infos; ///< all datagrams

    FileInfos() = default;
    FileInfos(size_t                                                  file_nr,
              std::shared_ptr<internal::InputFileManager<t_ifstream>> input_file_manager,
              const I_FileCache<t_DatagramIdentifier>&                file_info_data)
        : file_name(file_info_data.file_name)
        , file_size(file_info_data.file_size)
    {
        for (auto& datagram_info : file_info_data.datagram_infos)
        {
            datagram_infos.push_back(
                std::make_shared<datatypes::DatagramInfo<t_DatagramIdentifier, t_ifstream>>(
                    file_nr, input_file_manager, datagram_info));
        }
    }
};

}
}
}
}
