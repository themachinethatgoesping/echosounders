// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "systeminformation.hpp"

#include <sstream>

#include <fmt/core.h>

#include <themachinethatgoesping/algorithms/signalprocessing/types.hpp>
#include <themachinethatgoesping/tools/helper/floatcompare.hpp>
#include <themachinethatgoesping/tools/helper/variant.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {
namespace _sub {

// ----- TxSignalParameterVector implementations -----

TxSignalParameterVector::TxSignalParameterVector(const HashCacheKey& hash_cache_key)
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
                    this->push_back(CWSignalParameters::from_binary(
                        hash_cache_key.buffer.substr(offset, CWSignalParameters::binary_size())));
                    offset += CWSignalParameters::binary_size();
                    break;
                }
                case 'f': {
                    this->push_back(FMSignalParameters::from_binary(
                        hash_cache_key.buffer.substr(offset, FMSignalParameters::binary_size())));
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
            throw std::runtime_error(
                fmt::format("Error while parsing transmit signal parameters: {}\n\n--- Some error"
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

void TxSignalParameterVector::to_cache(std::unordered_map<size_t, std::string>& hash_cache,
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

size_t TxSignalParameterVector::binary_hash() const
{
    return boost::hash_range(this->begin(), this->end());
}

// ----- SystemInformation implementations -----

SystemInformation::SystemInformation(
    const datagrams::RawRangeAndAngle& raw_range_and_angle_datagram)
{
    using algorithms::signalprocessing::types::t_TxSignalType;
    using namespace algorithms::signalprocessing::datastructures;

    const auto& transmit_sectors = raw_range_and_angle_datagram.get_transmit_sectors();
    const auto  nsectors         = transmit_sectors.size();

    TxSignalParameterVector tx_signal_parameters;
    _mean_absorption_coefficient_in_dB_per_m = xt::xtensor<float, 1>::from_shape({ nsectors });
    tx_signal_parameters.reserve(nsectors);

    size_t sn = 0;
    for (const auto& ts : transmit_sectors)
    {
        auto tx_signal_type = ts.get_tx_signal_type();

        switch (tx_signal_type.value)
        {
            case t_TxSignalType::CW: {
                tx_signal_parameters.emplace_back(CWSignalParameters(
                    ts.get_center_frequency(), ts.get_signal_bandwidth(), ts.get_signal_length()));
                break;
            }
            case t_TxSignalType::FM_UP_SWEEP:
                [[fallthrough]];
            case t_TxSignalType::FM_DOWN_SWEEP: {
                tx_signal_parameters.emplace_back(FMSignalParameters(ts.get_center_frequency(),
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

        _mean_absorption_coefficient_in_dB_per_m.unchecked(sn) =
            ts.get_mean_absorption_coefficient_in_dB_per_m();
        ++sn;
    }

    _tx_signal_parameters = tx_signal_parameters;
}

SystemInformation::SystemInformation(const WaterColumnInformation& wci_infos)
{
    using algorithms::signalprocessing::types::t_TxSignalType;
    using namespace algorithms::signalprocessing::datastructures;

    TxSignalParameterVector tx_signal_parameters;

    const auto& transmit_sectors = wci_infos.get_transmit_sectors();

    for (const auto& ts : transmit_sectors)
    {
        tx_signal_parameters.push_back(
            GenericSignalParameters(ts.get_center_frequency(),
                                    NAN,
                                    NAN,
                                    algorithms::signalprocessing::types::t_TxSignalType::UNKNOWN));
    }

    _mean_absorption_coefficient_in_dB_per_m =
        xt::xtensor<float, 1>::from_shape({ tx_signal_parameters.size() });
    _mean_absorption_coefficient_in_dB_per_m.fill(NAN);
    _tx_signal_parameters = tx_signal_parameters;
}

bool SystemInformation::operator==(const SystemInformation& other) const
{
    if (_tx_signal_parameters.get() != other._tx_signal_parameters.get())
        return false;

    if (_mean_absorption_coefficient_in_dB_per_m.shape() !=
        other._mean_absorption_coefficient_in_dB_per_m.shape())

        return false;

    for (size_t i = 0; i < _mean_absorption_coefficient_in_dB_per_m.size(); ++i)

        if (!tools::helper::float_equals(
                _mean_absorption_coefficient_in_dB_per_m.unchecked(i),
                other._mean_absorption_coefficient_in_dB_per_m.unchecked(i)))

            return false;

    return true;
}

const std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>&
SystemInformation::get_tx_signal_parameters() const
{
    return _tx_signal_parameters.get();
}
const xt::xtensor<float, 1>& SystemInformation::get_mean_absorption_coefficient_in_dB_per_m() const
{
    return _mean_absorption_coefficient_in_dB_per_m;
}

void SystemInformation::to_stream(std::ostream&                            os,
                                  std::unordered_map<size_t, std::string>& hash_cache) const
{
    std::vector<size_t> hashes, sizes;
    hashes.reserve(1);
    sizes.reserve(1);

    // write to cache
    _tx_signal_parameters.get().to_cache(hash_cache, hashes, sizes);

    // write hashes to stream
    os.write(reinterpret_cast<const char*>(hashes.data()), hashes.size() * sizeof(size_t));
    os.write(reinterpret_cast<const char*>(sizes.data()), sizes.size() * sizeof(size_t));

    os.write(reinterpret_cast<const char*>(_mean_absorption_coefficient_in_dB_per_m.data()),
             _mean_absorption_coefficient_in_dB_per_m.size() * sizeof(float));
}

SystemInformation SystemInformation::from_stream(
    std::istream&                                  is,
    const std::unordered_map<size_t, std::string>& hash_cache)
{
    std::vector<size_t> hashes(1);
    std::vector<size_t> sizes(1);

    // read hashes and sizes from stream
    is.read(reinterpret_cast<char*>(hashes.data()), hashes.size() * sizeof(size_t));
    is.read(reinterpret_cast<char*>(sizes.data()), sizes.size() * sizeof(size_t));

    SystemInformation system_information;
    system_information._tx_signal_parameters =
        TxSignalParameterVector(HashCacheKey(hash_cache.at(hashes[0]), sizes[0], hashes[0]));

    system_information._mean_absorption_coefficient_in_dB_per_m =
        xt::xtensor<float, 1>::from_shape({ sizes[0] });
    is.read(
        reinterpret_cast<char*>(system_information._mean_absorption_coefficient_in_dB_per_m.data()),
        system_information._mean_absorption_coefficient_in_dB_per_m.size() * sizeof(float));

    // create SystemInformation
    return system_information;
}

} // namespace _sub
} // namespace filedatatypes
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
