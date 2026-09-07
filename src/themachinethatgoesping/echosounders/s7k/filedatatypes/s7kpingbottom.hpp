// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kpingbottom.doc.hpp"

/* std includes */
#include <limits>
#include <memory>
#include <vector>

#include <fmt/format.h>

// xtensor includes
#include <xtensor/containers/xtensor.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datatypes/i_pingbottom.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"

#include "s7kpingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {

/**
 * @brief Bottom detection (bathymetry) accessor of an s7k ping.
 *
 * The bottom detections come from the 7027 RawDetection record. s7k raw detections do not carry a
 * ready-made XYZ position (has_xyz() is false); the per-beam receive angles and two-way travel
 * times are provided as best guesses so the bottom can be raytraced later.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class S7KPingBottom
    : public filetemplates::datatypes::I_PingBottom
    , public S7KPingCommon<t_ifstream>
{
  public:
    using t_base1 = filetemplates::datatypes::I_PingBottom;
    using t_base2 = S7KPingCommon<t_ifstream>;

    using t_base2::_file_data;
    using typename t_base2::t_rawdata;

  protected:
    std::string class_name() const override { return "S7KPingBottom"; }

  public:
    S7KPingBottom(std::shared_ptr<t_rawdata> file_data)
        : t_base1()
        , t_base2(std::move(file_data))
    {
    }
    virtual ~S7KPingBottom() = default;

    // un-hide the base no-argument convenience overloads (hidden by the selection overrides below)
    using t_base1::get_beam_crosstrack_angles;
    using t_base1::get_beam_numbers_per_tx_sector;
    using t_base1::get_tx_sector_per_beam;
    using t_base1::get_two_way_travel_times;

    // ----- transmit sectors (single sector for now) -----
    size_t get_number_of_tx_sectors() override { return 1; }

    xt::xtensor<size_t, 1> get_tx_sector_per_beam(
        const pingtools::BeamSelection& selection) override
    {
        auto sectors = xt::xtensor<size_t, 1>::from_shape({ selection.get_number_of_beams() });
        sectors.fill(0);
        return sectors;
    }

    std::vector<std::vector<size_t>> get_beam_numbers_per_tx_sector(
        const pingtools::BeamSelection& selection) override
    {
        std::vector<std::vector<size_t>> beam_numbers_per_tx_sector(1);
        for (size_t i = 0; i < selection.get_number_of_beams(); ++i)
            beam_numbers_per_tx_sector[0].push_back(i);
        return beam_numbers_per_tx_sector;
    }

    // ----- feature checks -----
    // s7k raw detections carry angles + travel times, but no ready-made XYZ position
    bool has_xyz() const override { return false; }
    bool has_two_way_travel_times() const override { return _file_data->has_raw_detection(); }
    bool has_beam_crosstrack_angles() const override { return has_two_way_travel_times(); }

    // ----- geometry -----
    uint32_t get_number_of_beams() override
    {
        if (!_file_data->has_raw_detection())
            return 0;
        // one beam per distinct beam number (the raw detection may hold several detections per beam)
        return uint32_t(_file_data->get_rx_angle_in_degrees_per_beam_number().size());
    }

    xt::xtensor<float, 1> get_beam_crosstrack_angles(
        const pingtools::BeamSelection& selection) override
    {
        return index_beams(_file_data->get_rx_angle_in_degrees_per_beam_number(),
                           selection.get_beam_numbers(),
                           std::numeric_limits<float>::quiet_NaN());
    }

    xt::xtensor<float, 1> get_two_way_travel_times(
        const pingtools::BeamSelection& selection) override
    {
        // detected bottom sample number / sample rate -> two-way travel time in seconds
        const auto  detection_points = _file_data->get_detection_point_per_beam_number();
        const float sampling_rate    = _file_data->get_raw_detection().get_sampling_rate();

        const auto& beam_numbers = selection.get_beam_numbers();
        auto twtt = xt::xtensor<float, 1>::from_shape({ beam_numbers.size() });

        for (size_t i = 0; i < beam_numbers.size(); ++i)
        {
            if (beam_numbers[i] < detection_points.size() && sampling_rate > 0.f &&
                std::isfinite(detection_points.unchecked(beam_numbers[i])))
                twtt.unchecked(i) = detection_points.unchecked(beam_numbers[i]) / sampling_rate;
            else
                twtt.unchecked(i) = std::numeric_limits<float>::quiet_NaN();
        }

        return twtt;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base1::__printer__(float_precision, superscript_exponents));

        return printer;
    }

  private:
    template<typename t_value>
    static xt::xtensor<t_value, 1> index_beams(const xt::xtensor<t_value, 1>& source,
                                               const std::vector<uint32_t>&   beam_numbers,
                                               t_value                        fill_value)
    {
        auto result = xt::xtensor<t_value, 1>::from_shape({ beam_numbers.size() });
        for (size_t i = 0; i < beam_numbers.size(); ++i)
            result.unchecked(i) =
                beam_numbers[i] < source.size() ? source.unchecked(beam_numbers[i]) : fill_value;
        return result;
    }
};

} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
