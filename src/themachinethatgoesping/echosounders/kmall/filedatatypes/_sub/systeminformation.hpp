// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/systeminformation.doc.hpp"

/* boost includes */
#include <boost/flyweight.hpp>

#include <themachinethatgoesping/algorithms/signalprocessing/datastructures.hpp>

#include "../../datagrams.hpp"
#include "_sysinfos.hpp"
#include "watercolumninformation.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatatypes {
namespace _sub {

struct HashCacheKey
{
    std::string_view buffer;
    size_t           size;
    size_t           hash;

  public:
    HashCacheKey() = default;

    HashCacheKey(std::string_view buffer, size_t size, size_t hash)
        : buffer(buffer)
        , size(size)
        , hash(hash)
    {
    }

    HashCacheKey(size_t hash)
        : buffer("")
        , size(0)
        , hash(hash)
    {
    }

    bool operator==(const HashCacheKey& other) const { return (hash == other.hash); }
};

// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_hash_value
/**
 * @brief Boost hash function
 *
 * @param object object to hash
 * @return std::size_t
 */
inline size_t hash_value(const HashCacheKey& object)
{
    return object.hash;
}

class TxSignalParameterVector
    : public std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>
{
  public:
    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::vector;

    TxSignalParameterVector(const HashCacheKey& hash_cache_key);

    void to_cache(std::unordered_map<size_t, std::string>& hash_cache,
                  std::vector<size_t>&                     hashes,
                  std::vector<size_t>&                     sizes) const;

    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::operator=;
    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::operator[];
    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::size;
    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::begin;
    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::end;
    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::cbegin;
    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::cend;

    size_t binary_hash() const;
};

/**
 * @brief This is a substructure of the KMALLPingWaterColumn class. It is used to store
 * information necessary to efficiently read water column data from the file. It does not hold the
 * actual water column samples
 *
 * Note this is a private substructure and is thus not part of the public API or pybind11 interface.
 *
 */
class SystemInformation
{
    // transmit signal parameters per sector
    boost::flyweights::flyweight<TxSignalParameterVector> _tx_signal_parameters;

    SystemInformation() = default;
    SystemInformation(const HashCacheKey& hash_cache_key)
        : _tx_signal_parameters(hash_cache_key)
    {
    }

  public:
    SystemInformation(const datagrams::MRangeAndDepth& mrz_datagram);

    SystemInformation(const WaterColumnInformation& wci_infos);

    bool operator==(const SystemInformation& other) const;

    // ----- getters -----
    const std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>&
    get_tx_signal_parameters() const;

    // ----- functions used for PackageCache -----
    void to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const;

    static SystemInformation from_stream(std::istream&                                  is,
                                         const std::unordered_map<size_t, std::string>& hash_cache);
};

} // namespace _sub
} // namespace filedatatypes
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping