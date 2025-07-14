// SPDX-FileCopyrightText: 2022 - 2024 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/packagecache.doc.hpp"

/* generated doc strings */
#include ".docstrings/filepackagecache.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
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
#include <themachinethatgoesping/tools/helper/isviewstream.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {
namespace cache_structures {

template<typename t_CachingResult>
class PackageCache
{
  protected:
    virtual std::string class_name() const { return fmt::format("PackageCache"); }
    size_t              _file_pos;
    double              _timestamp;
    unsigned int        _sub_package_nr;

    std::unique_ptr<t_CachingResult> _caching_result;

  public:
    PackageCache() = default;
    PackageCache(size_t                           file_pos,
                 double                           timestamp,
                 std::unique_ptr<t_CachingResult> package,
                 unsigned int                     sub_package_nr = 0)
        : _file_pos(file_pos)
        , _timestamp(timestamp)
        , _sub_package_nr(sub_package_nr)
        , _caching_result(std::move(package))
    {
    }

    PackageCache(const PackageCache& other)
        : _file_pos(other._file_pos)
        , _timestamp(other._timestamp)
        , _sub_package_nr(other._sub_package_nr)
        , _caching_result(std::make_unique<t_CachingResult>(*other._caching_result))
    {
    }

    bool operator==(const PackageCache& other) const
    {
        return _file_pos == other._file_pos && _timestamp == other._timestamp &&
               _sub_package_nr == other._sub_package_nr &&
               *_caching_result == *other._caching_result;
    }

    virtual ~PackageCache() = default;

    size_t       get_file_pos() const { return _file_pos; }
    double       get_timestamp() const { return _timestamp; }
    unsigned int get_sub_package_nr() const { return _sub_package_nr; }

    void to_stream(std::ostream& stream, std::unordered_map<size_t, std::string>& hash_cache) const
    {
        constexpr size_t size = sizeof(_file_pos) + sizeof(_timestamp) + sizeof(_sub_package_nr);

        stream.write(reinterpret_cast<const char*>(&_file_pos), size);
        _caching_result->to_stream(stream, hash_cache);
    }
    static auto from_stream(std::istream&                                  stream,
                            const std::unordered_map<size_t, std::string>& hash_cache)
    {
        constexpr size_t size = sizeof(_file_pos) + sizeof(_timestamp) + sizeof(_sub_package_nr);
        PackageCache     package;
        stream.read(reinterpret_cast<char*>(&package._file_pos), size);
        package._caching_result =
            std::make_unique<t_CachingResult>(t_CachingResult::from_stream(stream, hash_cache));

        return package;
    }

    std::string to_binary(std::unordered_map<size_t, std::string>& hash_cache) const
    {
        std::stringstream buffer_stream;

        to_stream(buffer_stream, hash_cache);
        return buffer_stream.str();
    };

    static auto from_binary(std::string_view                               buffer,
                            const std::unordered_map<size_t, std::string>& hash_cache)
    {
        tools::helper::isviewstream buffer_stream(buffer);

        return from_stream(buffer_stream, hash_cache);
    };

    const auto& get() const
    {
        if (!_caching_result)
        {
            throw std::runtime_error("PackageCache: no caching result available");
        }

        return *_caching_result;
    }

    std::unique_ptr<t_CachingResult> get_and_release() { return std::move(_caching_result); }
};

} // namespace cache_structures
} // namespace datatypes
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping