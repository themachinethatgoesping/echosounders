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
    // positions of caches in files, first is first stream position, second is the position of the
    // end of the cache If not initialized, this file was not written or read yet
    std::vector<std::tuple<std::string, size_t, size_t>> _cache_buffer_header;
    std::unordered_map<std::string, std::string>         _cache_buffer;

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

    bool path_is_valid(const std::string& cache_path) const
    {
        if (std::filesystem::exists(cache_path))
        {
            // verify that the file is a valid FileCache
            std::ifstream is(cache_path, std::ios::binary);

            // this function will throw if it is not a valid FileCache
            read_check_type_id(is);

            // check if the version is correct
            if (!read_check_type_version(is))
                return false;

            FileCache cache("", 0);
            cache.read_header_content_from_stream(is);
            if (_file_name != cache.get_file_name() || _file_size != cache.get_file_size())
                return false;
        }
        return true;
    }

    void to_file(const std::string& cache_path, bool emulate_only = false)
    {

        // only do something if this throws (id mismatch)
        path_is_valid(cache_path);

        // do not write if only emulating
        if (emulate_only)
            return;

        // create directories if does not exist
        std::filesystem::create_directories(std::filesystem::path(cache_path).parent_path());

        std::ofstream os(cache_path, std::ios::binary);

        if (!os.is_open())
        {
            throw std::runtime_error(
                fmt::format("ERROR[FileCache]: Could not open file for writing: {}", cache_path));
        }

        to_stream(os);
    }

    bool operator==(const FileCache&) const = default;

    // ----- getters -----

    const std::string& get_file_name() const { return _file_name; }

    size_t get_file_size() const { return _file_size; }

    const std::unordered_map<std::string, std::string>& get_cache_buffer() const
    {
        return _cache_buffer;
    }

    const std::vector<std::tuple<std::string, size_t, size_t>>& get_cache_buffer_header() const
    {
        return _cache_buffer_header;
    }

    // ----- cache handling -----
    template<typename t_Cache>
    void add_to_cache(const std::string& name, t_Cache& cache)
    {
        // if name exists in header get the position
        // clear all entries after that position
        std::vector<std::string> valid_keys;
        for (auto i = 0; i < _cache_buffer_header.size(); ++i)
        {
            valid_keys.push_back(std::get<0>(_cache_buffer_header[i]));
            if (std::get<0>(_cache_buffer_header[i]) == name)
            {
                _cache_buffer_header.resize(i);
            }
        }

        // clear entries in _cache_buffer after that are not in valid_keys
        for (auto it = _cache_buffer.begin(); it != _cache_buffer.end();)
        {
            if (std::find(valid_keys.begin(), valid_keys.end(), it->first) == valid_keys.end())
            {
                it = _cache_buffer.erase(it);
            }
            else
            {
                ++it;
            }
        }

        _cache_buffer_header.push_back(std::make_tuple(name, 0, 0));
        _cache_buffer[name] = cache.to_binary();
    }

    template<typename t_Cache>
    t_Cache get_from_cache(const std::string& name) const
    {
        return t_Cache::from_binary(_cache_buffer.at(name));
    }

    // ----- to/from stream interface -----

    void to_stream(std::ostream& os)
    {
        write_type_id(os);
        write_type_version(os);

        tools::classhelper::stream::container_to_stream<std::string>(os, _file_name);
        os.write(reinterpret_cast<const char*>(&_file_size), sizeof(size_t));

        // --- write cache_buffer_header (shell) ---
        std::unordered_map<std::string, size_t>
               cache_buffer_header_map; // links key to position in cache_buffer_header
        size_t size = _cache_buffer_header.size();
        os.write(reinterpret_cast<const char*>(&size), sizeof(size_t));

        auto cache_buffer_header_position = os.tellp(); // save position to update later
        for (auto& [key, pos1, pos2] : _cache_buffer_header)
        {
            tools::classhelper::stream::container_to_stream<std::string>(os, key);
            os.write(reinterpret_cast<const char*>(&pos1), sizeof(size_t));
            os.write(reinterpret_cast<const char*>(&pos2), sizeof(size_t));
        }

        // --- write cache_buffer ---
        size = _cache_buffer.size();
        os.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
        for (auto& [key, pos1, pos2] : _cache_buffer_header)
        {
            auto& value = _cache_buffer[key];

            pos1 = os.tellp(); // update start position
            tools::classhelper::stream::container_to_stream<std::string>(os, key);
            tools::classhelper::stream::container_to_stream<std::string>(os, value);
            pos2 = os.tellp(); // update end position
        }
        auto end_position = os.tellp();

        // --- write updated cache_buffer_header ---
        os.seekp(cache_buffer_header_position);
        for (auto& [key, pos1, pos2] : _cache_buffer_header)
        {
            tools::classhelper::stream::container_to_stream<std::string>(os, key);
            os.write(reinterpret_cast<const char*>(&pos1), sizeof(size_t));
            os.write(reinterpret_cast<const char*>(&pos2), sizeof(size_t));
        }
    }

    static FileCache from_stream(std::istream& is)
    {
        read_check_type_id(is);
        if (!read_check_type_version(is))
        {
            throw std::runtime_error(
                fmt::format("ERROR[FileCache]: Invalid type version in file cache"));
        }

        FileCache cache("", 0);
        cache.read_header_content_from_stream(is);
        return cache;
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
        for (auto& [key, value] : _cache_buffer)
        {
            size_t buffer_size = value.size();
            printer.register_value_bytes(key, buffer_size);
        }

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(FileCache)

  private:
    void read_header_content_from_stream(std::istream& is)
    {
        _file_name = tools::classhelper::stream::container_from_stream<std::string>(is);
        is.read(reinterpret_cast<char*>(&_file_size), sizeof(size_t));

        // --- read cache_buffer_header ---
        size_t size = 0;
        is.read(reinterpret_cast<char*>(&size), sizeof(size_t));
        _cache_buffer_header.reserve(size);

        for (size_t i = 0; i < size; ++i)
        {
            std::string key = tools::classhelper::stream::container_from_stream<std::string>(is);
            size_t      pos1, pos2;
            is.read(reinterpret_cast<char*>(&pos1), sizeof(size_t));
            is.read(reinterpret_cast<char*>(&pos2), sizeof(size_t));
            _cache_buffer_header.push_back(std::make_tuple(key, pos1, pos2));
        }

        // --- read cache_buffer ---
        is.read(reinterpret_cast<char*>(&size), sizeof(size_t));

        for (size_t i = 0; i < size; ++i)
        {
            auto& [key_, pos1, pos2] = _cache_buffer_header[i];

            if (pos1 != is.tellg())
            {
                throw std::runtime_error(
                    fmt::format("ERROR[FileCache]: Invalid cache position in "
                                "file cache [begin]. Expected: {} got {} key {}",
                                pos1,
                                size_t(is.tellg()),
                                key_));
            }

            std::string key    = tools::classhelper::stream::container_from_stream<std::string>(is);
            _cache_buffer[key] = tools::classhelper::stream::container_from_stream<std::string>(is);

            if (key != key_)
            {
                throw std::runtime_error(fmt::format(
                    "ERROR[FileCache]: Invalid cache key in file cache Expected: {} got {}",
                    key_,
                    key));
            }

            if (pos2 != is.tellg())
            {
                throw std::runtime_error(fmt::format("ERROR[FileCache]: Invalid cache position in "
                                                     "file cache [end]. Expected: {} got {} key {}",
                                                     pos1,
                                                     size_t(is.tellg()),
                                                     key));
            }
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
