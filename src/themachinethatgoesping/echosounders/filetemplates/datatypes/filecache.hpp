// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/filecache.doc.hpp"

#include <cstddef>
#include <stdexcept>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <vector>

#include <xxhash.hpp>

#include <fmt/core.h>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



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
    FileCache(const std::string& file_name, size_t file_size);
    FileCache(const std::string&              index_path,
              const std::string&              file_name,
              size_t                          file_size,
              const std::vector<std::string>& cache_keys = std::vector<std::string>());

    std::vector<std::string> get_cache_names() const;

    std::vector<std::string> get_loaded_cache_names() const;

    std::vector<std::string> get_not_loaded_cache_names() const;

    /**
     * @brief Check if the index path contains a valid cache file
     * 
     * @param index_path Path to the index file to validate
     * @return true if the path contains a valid cache file matching this FileCache
     */
    bool path_is_valid(const std::string& index_path) const;

    /**
     * @brief Update or create the cache file at the specified path
     * 
     * @param index_path Path where to write the cache file
     * @param emulate_only If true, only simulate the update without actually writing
     */
    void update_file(const std::string& index_path, bool emulate_only = false);

    bool operator==(const FileCache&) const = default;

    // ----- getters -----

    const std::string& get_file_name() const;

    size_t get_file_size() const;

    const std::unordered_map<std::string, std::string>& get_cache_buffer() const;

    const std::vector<std::tuple<std::string, size_t, size_t>>& get_cache_buffer_header() const;

    // ----- cache handling -----
    template<typename t_Cache>
    void add_to_cache(const std::string& name, t_Cache& cache)
    {
        // remove old cache if exists and all lower priority caches
        remove_from_cache(name);

        _cache_buffer_header.push_back(std::make_tuple(name, 0, 0));
        _cache_buffer[name] = cache.to_binary();
    }

    /**
     * @brief Remove a cache entry and all entries added after it
     * 
     * @param name Name of the cache entry to remove
     */
    void remove_from_cache(const std::string& name);

    /**
     * @brief Check if a cache entry with the given name exists
     * 
     * @param name Name of the cache entry to check
     * @return true if the cache entry exists
     */
    bool has_cache(const std::string& name) const;

    template<typename t_Cache>
    t_Cache get_from_cache(const std::string& name) const
    {
        auto it = _cache_buffer.find(name);

        if (it == _cache_buffer.end())
        {
            if (has_cache(name))
                throw std::runtime_error(
                    fmt::format("ERROR[FileCache]: Cache not loaded: {}", name));
            else
                throw std::runtime_error(
                    fmt::format("ERROR[FileCache]: Cache not found in file cache: {}", name));
        }

        return t_Cache::from_binary(it->second);
    }

    template<typename t_Cache>
    t_Cache get_from_cache(const std::string& name, const t_Cache& default_val) const
    {
        auto it = _cache_buffer.find(name);

        if (it == _cache_buffer.end())
            return default_val;

        return t_Cache::from_binary(it->second);
    }

    // ----- to/from stream interface -----

    /**
     * @brief Write the FileCache to a stream
     * 
     * @param os Output stream to write to
     */
    void to_stream(std::ostream& os);

    /**
     * @brief Create a FileCache from a stream
     * 
     * @param is Input stream to read from
     * @return FileCache object created from the stream
     */
    static FileCache from_stream(std::istream& is);

    /**
     * @brief Create a FileCache from a file
     * 
     * @param index_path Path to the cache file to read
     * @return FileCache object created from the file
     */
    static FileCache from_file(const std::string& index_path);

    /**
     * @brief Create ObjectPrinter for this FileCache
     * 
     * @param float_precision Precision for floating point values
     * @param superscript_exponents Whether to use superscript for exponents
     * @return ObjectPrinter configured for this FileCache
     */
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(FileCache)

  private:
    /**
     * @brief Read header content from stream
     * 
     * @param is Input stream to read from
     */
    void read_header_content_from_stream(std::istream& is);

    /**
     * @brief Read cache buffer from stream
     * 
     * @param is Input stream to read from
     */
    void read_cache_buffer_from_stream(std::istream& is);

    /**
     * @brief Read cache buffer from stream for specific cache keys
     * 
     * @param is Input stream to read from
     * @param cache_keys Vector of cache keys to load
     */
    void read_cache_buffer_from_stream(std::istream& is, const std::vector<std::string>& cache_keys);

    // ----- private helper functions -----
    /**
     * @brief Read and verify type ID from stream
     * 
     * @param is Input stream to read from
     */
    static void read_check_type_id(std::istream& is);

    /**
     * @brief Write type ID to stream
     * 
     * @param os Output stream to write to
     */
    void write_type_id(std::ostream& os) const;

    /**
     * @brief Read and verify type version from stream
     * 
     * @param is Input stream to read from
     * @return true if version is correct
     */
    static bool read_check_type_version(std::istream& is);

    /**
     * @brief Write type version to stream
     * 
     * @param os Output stream to write to
     */
    void write_type_version(std::ostream& os) const;
};
}
}
}
}
