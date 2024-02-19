// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/systeminformation.doc.hpp"

/* boost includes */
#include <boost/flyweight.hpp>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

#include <themachinethatgoesping/algorithms/signalprocessing/datastructures.hpp>
#include <themachinethatgoesping/algorithms/signalprocessing/types.hpp>
#include <themachinethatgoesping/tools/classhelper/xxhashhelper.hpp>
#include <themachinethatgoesping/tools/hashhelper.hpp>

#include "../../datagrams.hpp"
#include "../../types.hpp"
#include "_sysinfos.hpp"
#include "watercolumninformation.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {
namespace _sub {

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
    boost::flyweights::flyweight<
        std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>>
        _tx_signal_parameters;

    // boost::flyweights::flyweight<_SYSInfos> _sys_infos; // not used at the moment

    SystemInformation() = default;

  public:
    SystemInformation(const datagrams::RawRangeAndAngle& raw_range_and_angle_datagram)
    {
        using algorithms::signalprocessing::types::t_TxSignalType;
        using namespace algorithms::signalprocessing::datastructures;

        std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>
            tx_signal_parameters;

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

        std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>
            tx_signal_parameters;

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

    bool operator==([[maybe_unused]] const SystemInformation& other) const = default;

    // ----- getters -----
    const std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>&
    get_tx_signal_parameters() const
    {
        return _tx_signal_parameters;
    }

    // ----- functions used for PackageCache -----
    void to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const
    {
        using namespace algorithms::signalprocessing::datastructures;

        std::string         buffer;
        std::vector<size_t> hashes, sizes;
        hashes.reserve(1);
        sizes.reserve(1);

        // _beam_crosstrack_angles
        static const size_t size_binary = sizeof(TxSignalParameters);

        hashes.push_back(xxh::xxhash3<64>(_tx_signal_parameters.get().data(),
                                          _tx_signal_parameters.get().size() * size_binary));
        sizes.push_back(_tx_signal_parameters.get().size());

        if (!hash_cache.contains(hashes.back()))
        {
            std::string       types;
            std::stringstream ss;

            for (const auto& signal_parameters : _tx_signal_parameters.get())
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

        // write hashes to stream
        os.write(reinterpret_cast<const char*>(hashes.data()), hashes.size() * sizeof(size_t));
        os.write(reinterpret_cast<const char*>(sizes.data()), sizes.size() * sizeof(size_t));
    }

    static SystemInformation from_stream(std::istream&                                  is,
                                         const std::unordered_map<size_t, std::string>& hash_cache)
    {
        using namespace algorithms::signalprocessing::datastructures;

        // create SystemInformation
        SystemInformation dat;

        std::vector<size_t> hashes(1);
        std::vector<size_t> sizes(1);

        // read hashes and sizes from stream
        is.read(reinterpret_cast<char*>(hashes.data()), hashes.size() * sizeof(size_t));
        is.read(reinterpret_cast<char*>(sizes.data()), sizes.size() * sizeof(size_t));

        // resize arrays
        std::vector<TxSignalParameters> tx_signal_parameters;
        tx_signal_parameters.reserve(sizes[0]);

        // read tx_signal_parameters from stream
        const auto& buffer = hash_cache.at(hashes[0]);

        std::string_view types  = std::string_view(buffer).substr(0, sizes[0]);
        size_t           offset = types.size();

        for (const auto type : types)
        {
            switch (type)
            {
                case 'c': {
                    tx_signal_parameters.push_back(CWSignalParameters::from_binary(
                        buffer.substr(offset, sizeof(CWSignalParameters))));
                    offset += sizeof(CWSignalParameters);
                    break;
                }
                case 'f': {
                    tx_signal_parameters.push_back(FMSignalParameters::from_binary(
                        buffer.substr(offset, sizeof(FMSignalParameters))));
                    offset += sizeof(CWSignalParameters);
                    break;
                }
                case 'g': {
                    tx_signal_parameters.push_back(GenericSignalParameters::from_binary(
                        buffer.substr(offset, sizeof(GenericSignalParameters))));
                    offset += sizeof(CWSignalParameters);
                    break;
                }
                default:
                    throw std::runtime_error("Unknown transmit signal type");
            }
        }

        dat._tx_signal_parameters = tx_signal_parameters;

        return dat;
    }
};

} // namespace substructures
} // namespace filedatatypes
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping