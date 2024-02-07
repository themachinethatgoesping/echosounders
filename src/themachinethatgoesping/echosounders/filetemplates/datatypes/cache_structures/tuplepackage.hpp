// SPDX-FileCopyrightText: 2022 - 2024 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/tuplepackage.doc.hpp"

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
namespace cache_structures {

template<class T, class... Ts>
class TuplePackage : public std::tuple<T, Ts...>
{

  public:
    // ----- constructors -----
    using std::tuple<T, Ts...>::tuple;
    // using std::tuple<T, Ts...>::value;
    // using std::tuple<T, Ts...>::value_type;

    // ----- comparison -----
    bool operator==(const TuplePackage& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("TuplePackage", float_precision);

        size_t i = 0;
        std::apply(
            [&printer, &i](auto&&... xs) {
                ((printer.register_value(fmt::format("parm{}", i++), xs)), ...);
            },
            dynamic_cast<const std::tuple<T, Ts...>&>(*this));

        return printer;
    }

    // ----- file I/O -----
    static TuplePackage from_stream(std::istream& is)
    {
        TuplePackage dat;
        is.read(reinterpret_cast<char*>(&dat), sizeof(dat));

        return dat;
    }

    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(this), sizeof(*this));
    }

    // ----- functions used for PackageCache -----
    static TuplePackage from_stream(std::istream&                                  is,
                                    const std::unordered_map<size_t, std::string>& hash_cache)
    {
        size_t hash;
        is.read(reinterpret_cast<char*>(&hash), sizeof(hash));

        return from_binary(hash_cache.at(hash));
    }

    void to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const
    {
        auto   cache = this->to_binary();
        size_t hash  = xxh::xxhash3<64>(cache);

        if (!hash_cache.contains(hash))
            hash_cache[hash] = std::move(cache);

        os.write(reinterpret_cast<const char*>(&hash), sizeof(hash));
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(TuplePackage)
};

/**
 * @brief Provide a boost hash function for TuplePackage
 * - Note: this is needed to use TuplePackage as boost::flyweight
 *
 * @param data
 * @return std::size_t
 */
// IGNORE_DOC: __doc_themachinethatgoesping_echosounders_pingtools_hash_value
template<class T, class... Ts>
inline size_t hash_value(const TuplePackage<T, Ts...>& data)
{
    return data.binary_hash();
}

} // namespace cache_structures
} // namespace datatypes
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping

/* add get overloads for TuplePackage
 * source:
 * https://stackoverflow.com/questions/37186443/confusion-while-deriving-from-stdtuple-can-not-handle-stdget
 */
namespace std {

template<std::size_t I, typename... T>
decltype(auto) get(
    themachinethatgoesping::echosounders::filetemplates::datatypes::cache_structures::TuplePackage<
        T...>&& v)
{
    return std::get<I>(static_cast<std::tuple<T...>&&>(v));
}
template<std::size_t I, typename... T>
decltype(auto) get(
    themachinethatgoesping::echosounders::filetemplates::datatypes::cache_structures::TuplePackage<
        T...>& v)
{
    return std::get<I>(static_cast<std::tuple<T...>&>(v));
}
template<std::size_t I, typename... T>
decltype(auto) get(
    themachinethatgoesping::echosounders::filetemplates::datatypes::cache_structures::TuplePackage<
        T...> const& v)
{
    return std::get<I>(static_cast<std::tuple<T...> const&>(v));
}
}