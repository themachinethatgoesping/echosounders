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
    size_t              file_pos;
    double              timestamp;
    unsigned int        sub_package_nr;

    t_CachingResult _caching_result;

  public:
    PackageCache() = default;
    template<typename t_CachedPackage>
    PackageCache(size_t                 file_pos,
                 double                 timestamp,
                 const t_CachedPackage& package,
                 unsigned int           sub_package_nr = 0)
        : file_pos(file_pos)
        , timestamp(timestamp)
        , _caching_result(package)
        , sub_package_nr(sub_package_nr)
    {
    }
    virtual ~PackageCache() = default;

    size_t       get_file_pos() const { return file_pos; }
    double       get_timestamp() const { return timestamp; }
    unsigned int get_sub_package_nr() const { return sub_package_nr; }

    bool operator==(const PackageCache& other) const = default;

    void to_stream(std::ostream& stream, std::unordered_map<size_t, std::string>& hash_cache) const
    {
        constexpr size_t size = sizeof(file_pos) + sizeof(timestamp) + sizeof(sub_package_nr);

        stream.write(reinterpret_cast<const char*>(&file_pos), size);
        _caching_result.to_stream(stream, hash_cache);
    }
    static auto from_stream(std::istream&                                  stream,
                            const std::unordered_map<size_t, std::string>& hash_cache)
    {
        constexpr size_t size = sizeof(file_pos) + sizeof(timestamp) + sizeof(sub_package_nr);
        PackageCache     package;
        stream.read(reinterpret_cast<char*>(&package.file_pos), size);
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
    std::unordered_map<size_t, std::string>              _hash_cache;
    std::unordered_map<size_t, std::vector<std::string>> _package_buffer;

  public:
    using type_CachingResult = t_CachingResult;

    PackageCacheBuffer()          = default;
    virtual ~PackageCacheBuffer() = default;

    bool operator==(const PackageCacheBuffer& other) const = default;

    const std::unordered_map<size_t, std::string>& get_hash_cache() const { return _hash_cache; }

    const std::unordered_map<size_t, std::vector<std::string>>& get_package_buffer() const
    {
        return _package_buffer;
    }

    template<typename t_CachedPackage>
    void add_package(size_t                 file_pos,
                     double                 timestamp,
                     const t_CachedPackage& package,
                     unsigned int           sub_package_nr = 0)
    {
        add_package(PackageCache<t_CachingResult>(file_pos, timestamp, package, sub_package_nr));
    }

    void add_package(const PackageCache<t_CachingResult>& package)
    {
        auto& package_buffer = _package_buffer[package.get_file_pos()];

        if (package_buffer.size() <= package.get_sub_package_nr())
            package_buffer.resize(package.get_sub_package_nr() + 1);

        package_buffer[package.get_sub_package_nr()] = package.to_binary(_hash_cache);
    }

    PackageCache<t_CachingResult> get_package_cache(size_t       file_pos,
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

    t_CachingResult get_package(size_t       file_pos,
                                double       timestamp,
                                unsigned int sub_package_nr = 0) const
    {
        return get_package_cache(file_pos, timestamp, sub_package_nr).get();
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
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("PackageCacheBuffer", float_precision);

        size_t bytes_hash = 0;
        for (const auto& [key, buffer] : _hash_cache)
            bytes_hash += buffer.size();

        size_t bytes_package = 0;
        for (const auto& [key, subpackages] : _package_buffer)
            for (const auto& buffer : subpackages)
                bytes_package += buffer.size();

        print_bytes("hash_cache", bytes_hash, printer);
        print_bytes("package_cache", bytes_package, printer);

        printer.register_value("hash_cache", _hash_cache.size(), "elements");
        printer.register_value("package_cache", _package_buffer.size(), "elements");
        return printer;
    }

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(PackageCacheBuffer)

  private:
    void print_bytes(const std::string&                 name,
                     size_t                             bytes,
                     tools::classhelper::ObjectPrinter& printer) const
    {

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