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
#include <boost/flyweight/key_value.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>


#include <xtensor/views/xview.hpp>

#include <themachinethatgoesping/algorithms/signalprocessing/datastructures.hpp>
#include <themachinethatgoesping/algorithms/signalprocessing/types.hpp>
#include <themachinethatgoesping/tools/classhelper/xxhashhelper.hpp>

#include <themachinethatgoesping/tools/helper/variant.hpp>

#include "../../datagrams.hpp"
#include "../../types.hpp"
#include "_sysinfos.hpp"
#include "watercolumninformation.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
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

// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_sub_hash_value
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

    TxSignalParameterVector(const HashCacheKey& hash_cache_key)
    {
        using namespace algorithms::signalprocessing::datastructures;

        // resize arrays
        this->reserve(hash_cache_key.size);

        std::string_view types  = hash_cache_key.buffer.substr(0, hash_cache_key.size);
        size_t           offset = types.size();

        for (const auto type : types)
        {
            try
            {
                switch (type)
                {
                    case 'c': {
                        this->push_back(
                            CWSignalParameters::from_binary(hash_cache_key.buffer.substr(
                                offset, CWSignalParameters::binary_size())));
                        offset += CWSignalParameters::binary_size();
                        break;
                    }
                    case 'f': {
                        this->push_back(
                            FMSignalParameters::from_binary(hash_cache_key.buffer.substr(
                                offset, FMSignalParameters::binary_size())));
                        offset += FMSignalParameters::binary_size();
                        break;
                    }
                    case 'g': {
                        this->push_back(
                            GenericSignalParameters::from_binary(hash_cache_key.buffer.substr(
                                offset, GenericSignalParameters::binary_size())));
                        offset += GenericSignalParameters::binary_size();
                        break;
                    }
                    default:
                        throw std::runtime_error("Unknown transmit signal type");
                }
            }
            catch (std::exception& e)
            {
                throw std::runtime_error(fmt::format(
                    "Error while parsing transmit signal parameters: {}\n\n--- Some error"
                    "infos---\n- type: {}\n- types: {}\n- offset: {}\n- this.size: {}\n- "
                    "hash.size: {}\n- hash.buffer.size(): {}"
                    "\n- sizeof(CWSignalParameters): {}/{}\n- "
                    "sizeof(FMSignalParameters): {}/{}\n- sizeof(GenericSignalParameters): "
                    "{}/{}\n- "
                    "hash.buffer: -{}-",
                    e.what(),
                    type,
                    types,
                    offset,
                    this->size(),
                    hash_cache_key.size,
                    hash_cache_key.buffer.size(),
                    sizeof(CWSignalParameters),
                    CWSignalParameters::binary_size(),
                    sizeof(FMSignalParameters),
                    FMSignalParameters::binary_size(),
                    sizeof(GenericSignalParameters),
                    GenericSignalParameters::binary_size(),
                    hash_cache_key.buffer));
            }
        }
    }

    void to_cache(std::unordered_map<size_t, std::string>& hash_cache,
                  std::vector<size_t>&                     hashes,
                  std::vector<size_t>&                     sizes) const
    {
        using namespace algorithms::signalprocessing::datastructures;

        hashes.push_back(this->binary_hash());
        sizes.push_back(this->size());

        if (!hash_cache.contains(hashes.back()))
        {
            std::string       types;
            std::stringstream ss;

            for (const auto& signal_parameters : *this)
            {
                tools::helper::visit_variant_no_return(
                    signal_parameters,
                    [&types, &ss](const CWSignalParameters& param) mutable {
                        types.push_back('c');
                        param.to_stream(ss);
                    },
                    [&types, &ss](const FMSignalParameters& param) mutable {
                        types.push_back('f');
                        param.to_stream(ss);
                    },
                    [&types, &ss](const GenericSignalParameters& param) mutable {
                        types.push_back('g');
                        param.to_stream(ss);
                    });
            }

            auto& buffer = hash_cache[hashes.back()];
            buffer       = types;
            buffer += ss.str();
        }
    }

    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::operator=;
    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::operator[];
    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::size;
    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::begin;
    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::end;
    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::cbegin;
    using std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>::cend;

    size_t binary_hash() const
    {
        // using algorithms::signalprocessing::datastructures::TxSignalParameters;

        // static const size_t size_binary = sizeof(TxSignalParameters);

        // return xxh::xxhash3<64>(this->data(), this->size() * size_binary);
        // REQUIRE(false);

        return boost::hash_range(this->begin(), this->end());
    }
};

// static std::unordered_map<size_t, HashCacheKey> __hash_key_cache;
// // // IGNORE_DOC:
// // // __doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_sub_hash_extractor
// struct hash_extractor
// {
//     const HashCacheKey& operator()(const TxSignalParameterVector& object) const
//     {
//         size_t hash            = object.binary_hash();
//         __hash_key_cache[hash] = HashCacheKey(hash);
//         return __hash_key_cache[hash];
//     }
// };

/**
 * @brief This is a substructure of the KongsbergAllPingWaterColumn class. It is used to store
 * information necessary to efficiently read water column data from the file. It does not hold the
 * actual water column samples
 *
 * Note this is a private substructure and is thus not part of the public API or pybind11 interface.
 *
 */
class SystemInformation
{
    // transmit signal parameters per sector
    // TODO, this should be slower, but it is faster than the other one
    boost::flyweights::flyweight<TxSignalParameterVector> _tx_signal_parameters;

    // boost::flyweights::flyweight<
    //     boost::flyweights::key_value<HashCacheKey, TxSignalParameterVector, hash_extractor>>
    //     _tx_signal_parameters;

    // boost::flyweights::flyweight<_SYSInfos> _sys_infos; // not used at the moment

    SystemInformation() = default;
    SystemInformation(const HashCacheKey& hash_cache_key)
        : _tx_signal_parameters(hash_cache_key)
    {
    }

  public:
    SystemInformation(const datagrams::RawRangeAndAngle& raw_range_and_angle_datagram)
    {
        using algorithms::signalprocessing::types::t_TxSignalType;
        using namespace algorithms::signalprocessing::datastructures;

        TxSignalParameterVector tx_signal_parameters;

        const auto& transmit_sectors = raw_range_and_angle_datagram.get_transmit_sectors();

        for (const auto& ts : transmit_sectors)
        {
            auto tx_signal_type = ts.get_tx_signal_type();

            switch (tx_signal_type)
            {
                case t_TxSignalType::CW: {
                    tx_signal_parameters.push_back(CWSignalParameters(ts.get_center_frequency(),
                                                                      ts.get_signal_bandwidth(),
                                                                      ts.get_signal_length()));
                    break;
                }
                case t_TxSignalType::FM_UP_SWEEP:
                    [[fallthrough]];
                case t_TxSignalType::FM_DOWN_SWEEP: {
                    tx_signal_parameters.push_back(FMSignalParameters(ts.get_center_frequency(),
                                                                      ts.get_signal_bandwidth(),
                                                                      ts.get_signal_length(),
                                                                      tx_signal_type));
                    break;
                }
                default:
                    // this should not happen since the get_tx_signal_type should return a valid
                    // type
                    throw std::runtime_error("Unknown transmit signal type");
            }
        }

        _tx_signal_parameters = tx_signal_parameters;

        //_sys_infos = _SYSInfos(raw_range_and_angle_datagram);
    }

    SystemInformation(const WaterColumnInformation& wci_infos)
    {
        using algorithms::signalprocessing::types::t_TxSignalType;
        using namespace algorithms::signalprocessing::datastructures;

        TxSignalParameterVector tx_signal_parameters;

        const auto& transmit_sectors = wci_infos.get_transmit_sectors();

        for (const auto& ts : transmit_sectors)
        {
            tx_signal_parameters.push_back(GenericSignalParameters(
                ts.get_center_frequency(),
                NAN,
                NAN,
                algorithms::signalprocessing::types::t_TxSignalType::UNKNOWN));
        }

        _tx_signal_parameters = tx_signal_parameters;

        //_sys_infos = _SYSInfos(wci_infos);
    }

    bool operator==([[maybe_unused]] const SystemInformation& other) const
    {
        return _tx_signal_parameters.get() == other._tx_signal_parameters.get();
    }

    // ----- getters -----
    const std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>&
    get_tx_signal_parameters() const
    {
        return _tx_signal_parameters.get();
    }

    // ----- functions used for PackageCache -----
    void to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const
    {
        using namespace algorithms::signalprocessing::datastructures;

        std::vector<size_t> hashes, sizes;
        hashes.reserve(1);
        sizes.reserve(1);

        // write to cache
        _tx_signal_parameters.get().to_cache(hash_cache, hashes, sizes);

        // write hashes to stream
        os.write(reinterpret_cast<const char*>(hashes.data()), hashes.size() * sizeof(size_t));
        os.write(reinterpret_cast<const char*>(sizes.data()), sizes.size() * sizeof(size_t));
    }

    static SystemInformation from_stream(std::istream&                                  is,
                                         const std::unordered_map<size_t, std::string>& hash_cache)
    {
        using namespace algorithms::signalprocessing::datastructures;

        std::vector<size_t> hashes(1);
        std::vector<size_t> sizes(1);

        // read hashes and sizes from stream
        is.read(reinterpret_cast<char*>(hashes.data()), hashes.size() * sizeof(size_t));
        is.read(reinterpret_cast<char*>(sizes.data()), sizes.size() * sizeof(size_t));

        // create SystemInformation
        return SystemInformation(HashCacheKey(hash_cache.at(hashes[0]), sizes[0], hashes[0]));
    }
};

} // namespace substructures
} // namespace filedatatypes
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping