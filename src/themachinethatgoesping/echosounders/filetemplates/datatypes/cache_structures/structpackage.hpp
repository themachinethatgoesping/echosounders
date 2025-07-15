// SPDX-FileCopyrightText: 2022 - 2024 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/structpackage.doc.hpp"

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


#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {
namespace cache_structures {

template<typename t_struct>
class StructPackage : public t_struct
{

  public:
    // ----- constructors -----
    using t_struct::t_struct;
    StructPackage() = default;
    StructPackage(const StructPackage&) = default;
    // using std::tuple<T, Ts...>::value;
    // using std::tuple<T, Ts...>::value_type;

    // ----- comparison -----
    bool operator==(const StructPackage& other) const = default;

    // ----- objectprinter -----
    // tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    // {
    //     tools::classhelper::ObjectPrinter printer("StructPackage", float_precision, superscript_exponents);

    //     size_t i = 0;
    //     std::apply(
    //         [&printer, &i](auto&&... xs) {
    //             ((printer.register_value(fmt::format("parm{}", i++), xs)), ...);
    //         },
    //         dynamic_cast<const std::tuple<T, Ts...>&>(*this));

    //     return printer;
    // }

    // ----- file I/O -----
    static StructPackage from_stream(std::istream& is)
    {
        StructPackage dat;
        is.read(reinterpret_cast<char*>(&dat), sizeof(dat));

        return dat;
    }

    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(this), sizeof(*this));
    }

    // ----- functions used for PackageCache -----
    static StructPackage from_stream(std::istream&                                  is,
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
    //__CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(StructPackage)
};

/**
 * @brief Provide a boost hash function for StructPackage
 * - Note: this is needed to use StructPackage as boost::flyweight
 *
 * @param data
 * @return std::size_t
 */
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_pingtools_hash_value
template<typename t_struct>
inline size_t hash_value(const StructPackage<t_struct>& data)
{
    return data.binary_hash();
}

} // namespace cache_structures
} // namespace datatypes
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping
