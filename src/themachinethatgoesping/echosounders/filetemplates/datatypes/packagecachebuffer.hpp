// SPDX-FileCopyrightText: 2022 - 2024 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/packagecachebuffer.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <set>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/hashhelper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

template<typename t_CachingResult>
class PackageCache
{
  protected:
    virtual std::string class_name() const { return fmt::format("PackageCache"); }
    size_t              package_nr;
    size_t              file_pos;
    double              timestamp;

    t_CachingResult _caching_result;

  public:
    PackageCache() = default;
    template<typename t_CachedPackage>
    PackageCache(size_t                 package_nr,
                 size_t                 file_pos,
                 double                 timestamp,
                 const t_CachedPackage& package)
        : package_nr(package_nr)
        , file_pos(file_pos)
        , timestamp(timestamp)
        , _caching_result(package)
    {
    }
    virtual ~PackageCache() = default;

    size_t get_package_nr() const { return package_nr; }
    size_t get_file_pos() const { return file_pos; }
    double get_timestamp() const { return timestamp; }

    bool operator==(const PackageCache& other) const = default;

    void to_stream(std::ostream& stream, std::unordered_map<size_t, std::string>& hash_cache) const
    {
        constexpr size_t size = sizeof(package_nr) + sizeof(file_pos) + sizeof(timestamp);

        stream.write(reinterpret_cast<const char*>(&package_nr), size);
        _caching_result.to_stream(stream, hash_cache);
    }
    static auto from_stream(std::istream&                                  stream,
                            const std::unordered_map<size_t, std::string>& hash_cache)
    {
        constexpr size_t size = sizeof(package_nr) + sizeof(file_pos) + sizeof(timestamp);
        PackageCache     package;
        stream.read(reinterpret_cast<char*>(&package.package_nr), size);
        package._caching_result = package._caching_result.from_stream(stream, hash_cache);

        return package;
    }

    std::string to_binary(std::unordered_map<size_t, std::string>& hash_cache) const
    {
        std::stringstream buffer_stream;

        to_stream(buffer_stream, hash_cache);
        return buffer_stream.str();
    };

    static auto from_binary(const std::string&                             buffer,
                            const std::unordered_map<size_t, std::string>& hash_cache)
    {
        std::stringstream buffer_stream{ buffer };

        return from_stream(buffer_stream, hash_cache);
    };

    const auto& get() const { return _caching_result; }
};

template<typename t_CachingResult>
class PackageCacheBuffer
{
  protected:
    virtual std::string class_name() const { return fmt::format("PackageCacheBuffer"); }
    std::string         _filename;
    std::unordered_map<size_t, std::string> _hash_cache;
    std::unordered_map<size_t, std::string> _package_buffer;
    // std::unordered_map<size_t, PackageCache<t_CachingResult>> _package_cache_buffer;

  public:
    PackageCacheBuffer(const std::string& filename)
        : _filename(filename){};
    virtual ~PackageCacheBuffer() = default;

    template<typename t_CachedPackage>
    void add_package(size_t                 package_nr,
                     size_t                 file_pos,
                     double                 timestamp,
                     const t_CachedPackage& package)
    {
        add_package(PackageCache<t_CachingResult>(package_nr, file_pos, timestamp, package));
    }

    void add_package(const PackageCache<t_CachingResult>& package)
    {
        _package_buffer[package.get_package_nr()] = package.to_binary(_hash_cache);
    }

    PackageCache<t_CachingResult> get_package_cache(size_t package_nr,
                                                    size_t file_pos,
                                                    double timestamp) const
    {
        const auto package_it = _package_buffer.find(package_nr);

        if (package_it == _package_buffer.end())
            throw std::runtime_error(
                fmt::format("{}: package {} not found in cache", class_name(), package_nr));

        PackageCache<t_CachingResult> package_cache =
            PackageCache<t_CachingResult>::from_binary(package_it->second, _hash_cache);

        if (package_cache.get_package_nr() != package_nr)
            throw std::runtime_error(fmt::format("{}: package {} has package_nr {} instead of {}",
                                                 class_name(),
                                                 package_nr,
                                                 package_cache.get_package_nr(),
                                                 package_nr));

        if (package_cache.get_file_pos() != file_pos)
            throw std::runtime_error(fmt::format("{}: package {} has file_pos {} instead of {}",
                                                 class_name(),
                                                 package_nr,
                                                 package_cache.get_file_pos(),
                                                 file_pos));

        if (package_cache.get_timestamp() != timestamp)
            throw std::runtime_error(fmt::format("{}: package {} has timestamp {} instead of {}",
                                                 class_name(),
                                                 package_nr,
                                                 package_cache.get_timestamp(),
                                                 timestamp));

        return package_cache;
    }

    t_CachingResult get_package(size_t package_nr, size_t file_pos, double timestamp) const
    {
        return get_package_cache(package_nr, file_pos, timestamp).get();
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping