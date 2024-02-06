// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/filecache.doc.hpp"

#include <filesystem>
#include <fstream>
#include <limits>
#include <memory>
#include <unordered_map>
#include <vector>

/* memory mapping */
#include <boost/iostreams/device/mapped_file.hpp> // for mmap
#include <boost/iostreams/stream.hpp>             // for stream

#include <xxhash.hpp>

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

class FileCache
{
    inline static constexpr std::string_view _type_id_0      = "0xTHEMACHINETHATGOESPING_TYPEx0";
    inline static constexpr std::string_view _type_id_1      = "##<FileCache>##";
    inline static constexpr std::string_view _type_version_1 = "v1.0";

    std::string _file_name; // for reference / checking file validity
    size_t      _file_size; // for reference / checking file validity

    /* cache positions */
    // positions of caches in files, first is first stream position, second is size in bytes
    // If not initialized, this file was not written or read yet
    std::unordered_map<std::string, std::pair<size_t, size_t>> _cache_header;

  public:
    FileCache(const std::string& file_name, size_t file_size)
        : _file_name(file_name)
        , _file_size(file_size)
    {
    }
    FileCache(const std::string& cache_path, const std::string& file_name, size_t file_size)
        : _file_name(file_name)
        , _file_size(file_size)
    {

        if (std::filesystem::exists(cache_path))
        {
            std::ifstream is(cache_path, std::ios::binary);

            read_check_type_id(is);
            if (read_check_type_version(is))
            {
                read_header_content_from_stream(is);

                if (_file_name != file_name || _file_size != file_size)
                {
                    throw std::runtime_error(fmt::format(
                        "ERROR[FileCache]: File name or size mismatch. Expected: {} {} got {} {}",
                        file_name,
                        file_size,
                        _file_name,
                        _file_size));
                }
            }
        }
    }

    bool operator==(const FileCache&) const = default;

    // ----- getters -----

    const std::string& get_file_name() const { return _file_name; }

    size_t get_file_size() const { return _file_size; }

    const std::unordered_map<std::string, std::pair<size_t, size_t>>& get_cache_header() const
    {
        return _cache_header;
    }

    // ----- to/from stream interface -----

    void header_to_stream(std::ostream& os) const
    {
        write_type_id(os);
        write_type_version(os);

        tools::classhelper::stream::container_to_stream<std::string>(os, _file_name);
        os.write(reinterpret_cast<const char*>(&_file_size), sizeof(size_t));

        size_t size = _cache_header.size();
        os.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
        for (auto& [key, value] : _cache_header)
        {
            tools::classhelper::stream::container_to_stream<std::string>(os, key);
            os.write(reinterpret_cast<const char*>(&value.first), sizeof(size_t));
            os.write(reinterpret_cast<const char*>(&value.second), sizeof(size_t));
        }
    }

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("DatagramInfoData", float_precision);

        // version
        printer.register_string("type_id", std::string(_type_id_1));
        printer.register_string("type_version", std::string(_type_version_1));

        // raw values
        printer.register_string("file_name", _file_name);
        printer.register_value_bytes("file_size", size_t(_file_size));

        // cache infos
        printer.register_section("cache infos");
        for (auto& [key, value] : _cache_header)
        {
            printer.register_value_bytes(key, value.second);
        }

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    //__STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(FileCache)

  private:
    void read_header_content_from_stream(std::istream& is)
    {
        _file_name = tools::classhelper::stream::container_from_stream<std::string>(is);
        is.read(reinterpret_cast<char*>(&_file_size), sizeof(size_t));

        size_t size = 0;
        is.read(reinterpret_cast<char*>(&size), sizeof(size_t));

        for (size_t i = 0; i < size; ++i)
        {
            std::string key = tools::classhelper::stream::container_from_stream<std::string>(is);
            size_t      first, second;
            is.read(reinterpret_cast<char*>(&first), sizeof(size_t));
            is.read(reinterpret_cast<char*>(&second), sizeof(size_t));
            _cache_header[key] = std::make_pair(first, second);
        }
    }

    // ----- private helper functions -----
    static void read_check_type_id(std::istream& is)
    {
        static int64_t control_hash =
            xxh::xxhash3<64>(_type_id_0.data(), _type_id_0.size() * sizeof(char));

        int64_t read_hash = 0;
        is.read(reinterpret_cast<char*>(&read_hash), sizeof(int64_t));

        if (read_hash != control_hash)
        {
            throw std::runtime_error(
                fmt::format("ERROR[FileCache]: Invalid type hash (0). Expected: {} got {}",
                            std::to_string(control_hash),
                            std::to_string(read_hash)));
        }

        std::string type_id_1 = tools::classhelper::stream::container_from_stream<std::string>(is);
        if (type_id_1 != _type_id_1)
        {
            throw std::runtime_error(
                fmt::format("ERROR[FileCache]: Invalid type id in file cache. Expected: {} got {}",
                            std::string(_type_id_1),
                            type_id_1));
        }

        is.read(reinterpret_cast<char*>(&read_hash), sizeof(int64_t));
        if (read_hash != control_hash)
        {
            throw std::runtime_error(
                fmt::format("ERROR[FileCache]: Invalid type hash (1). Expected: {} got {}",
                            std::to_string(control_hash),
                            std::to_string(read_hash)));
        }
    }

    void write_type_id(std::ostream& os) const
    {
        int64_t hash = xxh::xxhash3<64>(_type_id_0.data(), _type_id_0.size() * sizeof(char));
        os.write(reinterpret_cast<const char*>(&hash), sizeof(int64_t));
        tools::classhelper::stream::container_to_stream<std::string_view>(os, _type_id_1);
        os.write(reinterpret_cast<const char*>(&hash), sizeof(int64_t));
    }

    static bool read_check_type_version(std::istream& is)
    {
        std::string type_version_1 =
            tools::classhelper::stream::container_from_stream<std::string>(is);

        if (type_version_1 != _type_version_1)
        {
            return false;
        }
        return true;
    }
    void write_type_version(std::ostream& os) const
    {
        tools::classhelper::stream::container_to_stream<std::string_view>(os, _type_version_1);
    }
};
}
}
}
}
