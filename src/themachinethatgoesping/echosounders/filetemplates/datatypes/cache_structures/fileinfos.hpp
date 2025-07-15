// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/fileinfos.doc.hpp"

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



#include "../../internal/inputfilemanager.hpp"
#include "../datagraminfo.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {
namespace cache_structures {

/**
 * @brief struct for storing the file infos (returned by scan_for_datagrams)
 *
 */
template<typename t_DatagramIdentifier, typename t_ifstream>
struct FileInfos
{
    std::string file_path;
    size_t      file_size;

    /* header positions */
    std::vector<datatypes::DatagramInfo_ptr<t_DatagramIdentifier,
                                            t_ifstream>>
        datagram_infos; ///< all datagrams

    FileInfos() = default;
    FileInfos(
        size_t                                                                file_nr,
        const std::string&                                                    file_path,
        const size_t                                                          file_size,
        const std::vector<datatypes::DatagramInfoData<t_DatagramIdentifier>>& datagram_info_data,
        std::shared_ptr<internal::InputFileManager<t_ifstream>>               input_file_manager)
        : file_path(file_path)
        , file_size(file_size)
    {
        for (auto& datagram_info : datagram_info_data)
        {
            datagram_infos.push_back(
                std::make_shared<datatypes::DatagramInfo<t_DatagramIdentifier, t_ifstream>>(
                    file_nr, input_file_manager, datagram_info));
        }
    }
};

} // namespace cache_structures
} // namespace datatypes
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping
