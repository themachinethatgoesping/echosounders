// SPDX-FileCopyrightText: 2022 - 2024 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/filepackagecache.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/hashhelper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "packagecache.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {
namespace cache_structures {

template<typename t_CachingResult>
class FilePackageCache
{
  protected:
    virtual std::string class_name() const { return fmt::format("FilePackageCache"); }
    std::unordered_map<size_t, std::string>              _hash_cache;
    std::unordered_map<size_t, std::vector<std::string>> _package_buffer;

  public:
    using type_CachingResult = t_CachingResult;

    FilePackageCache()          = default;
    virtual ~FilePackageCache() = default;

    bool operator==(const FilePackageCache& other) const = default;

    const std::unordered_map<size_t, std::string>& get_hash_cache() const { return _hash_cache; }

    const std::unordered_map<size_t, std::vector<std::string>>& get_package_buffer() const
    {
        return _package_buffer;
    }

    void add_package(size_t                           file_pos,
                     double                           timestamp,
                     std::unique_ptr<t_CachingResult> package,
                     unsigned int                     sub_package_nr = 0)
    {
        add_package(
            PackageCache<t_CachingResult>(file_pos, timestamp, std::move(package), sub_package_nr));
    }

    void add_package(const PackageCache<t_CachingResult>& package)
    {
        auto& package_buffer = _package_buffer[package.get_file_pos()];

        if (package_buffer.size() <= package.get_sub_package_nr())
            package_buffer.resize(package.get_sub_package_nr() + 1);

        package_buffer[package.get_sub_package_nr()] = package.to_binary(_hash_cache);
    }

    bool has_package(size_t file_pos) const
    {
        return _package_buffer.find(file_pos) != _package_buffer.end();
    }

    PackageCache<t_CachingResult> get_from_cache(size_t       file_pos,
                                                 double       timestamp,
                                                 unsigned int sub_package_nr = 0) const
    {
        const auto package_it = _package_buffer.find(file_pos);

        if (package_it == _package_buffer.end())
            throw std::runtime_error(
                fmt::format("{}: package {} not found in cache", class_name(), file_pos));

        if (package_it->second.size() <= sub_package_nr)
            throw std::runtime_error(fmt::format(
                "{}: package {} has no sub_package_nr {}", class_name(), file_pos, sub_package_nr));

        PackageCache<t_CachingResult> package_cache = PackageCache<t_CachingResult>::from_binary(
            package_it->second[sub_package_nr], _hash_cache);

        if (package_cache.get_file_pos() != file_pos)
            throw std::runtime_error(fmt::format("{}: package {} has file_pos {} instead of {}",
                                                 class_name(),
                                                 file_pos,
                                                 package_cache.get_file_pos(),
                                                 file_pos));

        if (package_cache.get_timestamp() != timestamp)
            throw std::runtime_error(fmt::format("{}: package {} has timestamp {} instead of {}",
                                                 class_name(),
                                                 file_pos,
                                                 package_cache.get_timestamp(),
                                                 timestamp));

        if (package_cache.get_sub_package_nr() != sub_package_nr)
            throw std::runtime_error(
                fmt::format("{}: package {} has sub_package_nr {} instead of {}",
                            class_name(),
                            file_pos,
                            package_cache.get_sub_package_nr(),
                            sub_package_nr));

        return package_cache;
    }

    unsigned int get_subpackage_count(size_t file_pos) const
    {
        const auto package_it = _package_buffer.find(file_pos);

        if (package_it == _package_buffer.end())
            return 0;

        return package_it->second.size();
    }

    std::unique_ptr<t_CachingResult> get_package(size_t       file_pos,
                                                 double       timestamp,
                                                 unsigned int sub_package_nr = 0) const
    {
        return get_from_cache(file_pos, timestamp, sub_package_nr).get_and_release();
    }

    std::vector<std::unique_ptr<t_CachingResult>> get_packages(size_t file_pos,
                                                               double timestamp) const
    {
        const auto package_it = _package_buffer.find(file_pos);

        if (package_it == _package_buffer.end())
            throw std::runtime_error(
                fmt::format("{}: package {} not found in cache", class_name(), file_pos));

        std::vector<std::unique_ptr<t_CachingResult>> packages;
        auto                                          subpackage_count = package_it->second.size();
        for (unsigned int i = 0; i < subpackage_count; ++i)
            packages.push_back(get_from_cache(file_pos, timestamp, i).get_and_release());

        return packages;
    }

    void to_stream(std::ostream& os) const
    {
        // write hash cache
        {
            size_t map_size = _hash_cache.size();
            os.write(reinterpret_cast<const char*>(&map_size), sizeof(size_t));
            for (const auto& [hash, buffer] : _hash_cache)
            {
                size_t buffer_size = buffer.size();
                os.write(reinterpret_cast<const char*>(&hash), sizeof(hash));
                os.write(reinterpret_cast<const char*>(&buffer_size), sizeof(buffer_size));
                os.write(reinterpret_cast<const char*>(buffer.data()), sizeof(char) * buffer_size);
            }
        }

        // write package buffer
        {
            size_t map_size = _package_buffer.size();
            os.write(reinterpret_cast<const char*>(&map_size), sizeof(size_t));
            for (const auto& [file_pos, subpackages] : _package_buffer)
            {
                os.write(reinterpret_cast<const char*>(&file_pos), sizeof(file_pos));
                size_t subpackage_size = subpackages.size();
                os.write(reinterpret_cast<const char*>(&subpackage_size), sizeof(subpackage_size));
                for (const auto& buffer : subpackages)
                {
                    size_t buffer_size = buffer.size();
                    os.write(reinterpret_cast<const char*>(&buffer_size), sizeof(buffer_size));
                    os.write(reinterpret_cast<const char*>(buffer.data()),
                             sizeof(char) * buffer_size);
                }
            }
        }
    }

    static FilePackageCache from_stream(std::istream& is)
    {
        FilePackageCache data;

        // read hash cache
        {
            size_t map_size;
            is.read(reinterpret_cast<char*>(&map_size), sizeof(size_t));
            for (size_t i = 0; i < map_size; i++)
            {
                size_t hash;
                size_t buffer_size;
                is.read(reinterpret_cast<char*>(&hash), sizeof(hash));
                is.read(reinterpret_cast<char*>(&buffer_size), sizeof(buffer_size));
                std::string buffer;
                buffer.resize(buffer_size);
                is.read(reinterpret_cast<char*>(buffer.data()), sizeof(char) * buffer_size);
                data._hash_cache[hash] = std::move(buffer);
            }
        }

        // read package buffer
        {
            size_t map_size;
            is.read(reinterpret_cast<char*>(&map_size), sizeof(size_t));
            for (size_t i = 0; i < map_size; i++)
            {
                size_t file_pos;
                is.read(reinterpret_cast<char*>(&file_pos), sizeof(file_pos));
                size_t subpackage_size;
                is.read(reinterpret_cast<char*>(&subpackage_size), sizeof(subpackage_size));
                std::vector<std::string> subpackages;
                subpackages.resize(subpackage_size);
                for (size_t j = 0; j < subpackage_size; j++)
                {
                    size_t buffer_size;
                    is.read(reinterpret_cast<char*>(&buffer_size), sizeof(buffer_size));
                    subpackages[j].resize(buffer_size);
                    is.read(reinterpret_cast<char*>(subpackages[j].data()),
                            sizeof(char) * buffer_size);
                }
                data._package_buffer[file_pos] = std::move(subpackages);
            }
        }

        return data;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("FilePackageCache", float_precision, superscript_exponents);

        size_t bytes_hash = 0;
        for (const auto& [key, buffer] : _hash_cache)
            bytes_hash += buffer.size();

        size_t bytes_package = 0;
        for (const auto& [key, subpackages] : _package_buffer)
            for (const auto& buffer : subpackages)
                bytes_package += buffer.size();

        printer.register_value_bytes("hash_cache", bytes_hash);
        printer.register_value_bytes("package_cache", bytes_package);
        printer.register_value("hash_cache", _hash_cache.size(), "elements");
        printer.register_value("package_cache", _package_buffer.size(), "elements");
        return printer;
    }

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(FilePackageCache)
};

} // namespace cache_structures
} // namespace datatypes
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping