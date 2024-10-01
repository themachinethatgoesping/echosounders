// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/filepackageindex.doc.hpp"

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
#include <themachinethatgoesping/tools/exceptions/version_error.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../internal/inputfilemanager.hpp"
#include "../datagraminfo.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {
namespace cache_structures {

template<typename t_DatagramIdentifier>
struct FilePackageIndex
{
    inline static constexpr std::string_view _type_version = "#FPIv1.0#";

    std::string file_path;
    size_t      file_size;

    /* header positions */
    std::vector<datatypes::DatagramInfoData<t_DatagramIdentifier>>
        datagram_info_data; ///< all datagrams

    FilePackageIndex() = default;
    template<typename t_FileInfos>
    FilePackageIndex(const t_FileInfos& file_info)
        : file_path(file_info.file_path)
        , file_size(file_info.file_size)
    {
        datagram_info_data.reserve(file_info.datagram_infos.size());

        for (auto& datagram_info : file_info.datagram_infos)
        {
            datagram_info_data.push_back(*datagram_info);
        }
    }
    bool operator==(const FilePackageIndex&) const = default;

    // ----- to/from stream interface -----
    static FilePackageIndex from_stream(std::istream& is)
    {
        FilePackageIndex data;

        // check version
        std::string version = tools::classhelper::stream::container_from_stream<std::string>(is);
        if (version != _type_version)
        {
            throw tools::exceptions::version_error(fmt::format(
                "FilePackageIndex: version mismatch: {} != {}", version, _type_version));
        }

        data.file_path = tools::classhelper::stream::container_from_stream<std::string>(is);
        is.read(reinterpret_cast<char*>(&data.file_size), sizeof(size_t));

        size_t size;
        is.read(reinterpret_cast<char*>(&size), sizeof(size_t));
        data.datagram_info_data.resize(size);
        for (size_t i = 0; i < size; ++i)
        {
            data.datagram_info_data[i] =
                datatypes::DatagramInfoData<t_DatagramIdentifier>::from_stream(is);
        }

        return data;
    }

    void to_stream(std::ostream& os) const
    {
        tools::classhelper::stream::container_to_stream<std::string>(os,
                                                                     std::string(_type_version));

        tools::classhelper::stream::container_to_stream<std::string>(os, file_path);
        os.write(reinterpret_cast<const char*>(&file_size), sizeof(size_t));

        size_t size = datagram_info_data.size();
        os.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
        for (size_t i = 0; i < size; ++i)
        {
            datagram_info_data[i].to_stream(os);
        }
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("DatagramInfoData", float_precision, superscript_exponents);

        // raw values
        printer.register_string("file_path", file_path);
        printer.register_value("file_size", size_t(file_size));

        printer.register_value("datagrams", datagram_info_data.size());

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(FilePackageIndex)
};

} // namespace cache_structures
} // namespace datatypes
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping
