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
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
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
    std::unordered_map<size_t, std::string> _hash_cache;
    std::unordered_map<size_t, std::string> _package_buffer;

  public:
    PackageCacheBuffer()          = default;
    virtual ~PackageCacheBuffer() = default;

    bool operator==(const PackageCacheBuffer& other) const = default;

    const std::unordered_map<size_t, std::string>& get_hash_cache() const { return _hash_cache; }

    const std::unordered_map<size_t, std::string>& get_package_buffer() const
    {
        return _package_buffer;
    }

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
            for (const auto& [package_nr, buffer] : _package_buffer)
            {
                size_t buffer_size = buffer.size();
                os.write(reinterpret_cast<const char*>(&package_nr), sizeof(package_nr));
                os.write(reinterpret_cast<const char*>(&buffer_size), sizeof(buffer_size));
                os.write(reinterpret_cast<const char*>(buffer.data()), sizeof(char) * buffer_size);
            }
        }
    }

    static PackageCacheBuffer from_stream(std::istream& is)
    {
        PackageCacheBuffer data;

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
                size_t package_nr;
                size_t buffer_size;
                is.read(reinterpret_cast<char*>(&package_nr), sizeof(package_nr));
                is.read(reinterpret_cast<char*>(&buffer_size), sizeof(buffer_size));
                std::string buffer;
                buffer.resize(buffer_size);
                is.read(reinterpret_cast<char*>(buffer.data()), sizeof(char) * buffer_size);
                data._package_buffer[package_nr] = std::move(buffer);
            }
        }

        return data;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("PackageCacheBuffer", float_precision);

        print_bytes("hash_cache", _hash_cache, printer);
        print_bytes("package_cache", _package_buffer, printer);

        printer.register_value("hash_cache", _hash_cache.size(), "elements");
        printer.register_value("package_cache", _package_buffer.size(), "elements");
        return printer;
    }

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(PackageCacheBuffer)

    private:
    void print_bytes(const std::string& name, const std::unordered_map<size_t, std::string>& cache_map, tools::classhelper::ObjectPrinter& printer) const
    {
        size_t bytes = 0;
        for (const auto& [key, buffer] : cache_map)
            bytes += buffer.size();

        if (bytes < 1024)
            printer.register_value(name, bytes, "bytes");
        else if (bytes < 1024 * 1024)
            printer.register_value(name, double(bytes) / 1024., "KB");
        else if (bytes < 1024 * 1024 * 1024)
            printer.register_value(name, double(bytes) / 1024. / 1024., "MB");
        else
            printer.register_value(name, double(bytes) / 1024. / 1024. / 1024., "GB");
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping