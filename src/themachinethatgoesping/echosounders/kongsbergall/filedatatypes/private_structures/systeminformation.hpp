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

#include "../../datagrams.hpp"
#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {
namespace sub {

/**
 * @brief This is a substructure of the KongsbergAllPingWaterColumn class. It is used to store
 * information necessary to efficiently read water column data from the file. It does not hold the
 * actual water column samples
 *
 * Note this is a private substructure and is thus not part of the public API or pybind11 interface.
 *
 * @tparam t_rawdata
 */
template<typename t_rawdata>
class SystemInformation
{
    // transmit signal parameters per sector
    boost::flyweights::flyweight<
        std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>>
        _tx_signal_parameters;

  public:
    SystemInformation(std::shared_ptr<t_rawdata> file_data)
    {
        using algorithms::signalprocessing::types::TxSignalType;
        using namespace algorithms::signalprocessing::datastructures;

        // best if RawRangeAndAngle datagram exists
        auto raw_range_and_angle_datagrams = file_data.get_datagram_infos_by_type(
            t_KongsbergAllDatagramIdentifier::RawRangeAndAngle);

        if (raw_range_and_angle_datagrams.size() > 0)
        {
            auto datagram =
                raw_range_and_angle_datagrams.at(0)
                    ->template read_datagram_from_file<datagrams::RawRangeAndAngle>(skip_data);

            auto transmit_sectors = datagram.get_transmit_sectors();

            for (const auto& ts : transmit_sectors)
            {
                auto tx_signal_type = ts.get_tx_signal_type();

                switch (tx_signal_type)
                {
                    case TxSignalType::CW: {
                        _tx_signal_parameters.push_back(
                            CWSignalParameters tx_signal_parameters(ts.get_center_frequency(),
                                                                    ts.get_signal_bandwidth(),
                                                                    ts.get_signal_length()));
                    }
                    case TxSignalType::FM_UP_SWEEP:
                        [[fallthrough]];
                    case TxSignalType::FM_DOWN_SWEEP: {
                        throw std::runtime_error(
                            "FM_UP_SWEEP and FM_DOWN_SWEEP transmit signal types are not "
                            "supported yet");
                        // auto tx_signal_parameters = ts.get_tx_signal_parameters();
                        // _tx_signal_parameters     = tx_signal_parameters;
                        break;
                    }
                }
            }
        }
    }
};

} // namespace substructures
} // namespace filedatatypes
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping