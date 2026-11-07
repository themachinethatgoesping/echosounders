// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kpingwatercolumn.doc.hpp"

/* std includes */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>
#include <memory>
#include <numbers>
#include <type_traits>
#include <variant>
#include <vector>

#include <fmt/format.h>

// xtensor includes
#include <xtensor/containers/xtensor.hpp>
#include <xtensor/core/xmath.hpp>
#include <xtensor/views/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/algorithms/signalprocessing/datastructures.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include <themachinethatgoesping/pingprocessing/datatypes/i_pingwatercolumn.hpp>

#include "../datagrams.hpp"
#include "../types.hpp"

#include "s7kpingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {

/**
 * @brief Water column accessor of an s7k ping.
 *
 * The water-column amplitudes come from the 7042 CompressedWaterColumn record; the per-beam receive
 * angles and the detected bottom sample come from the 7027 RawDetection record; the sample interval
 * and sound velocity come from the 7000 SonarSettings record. This first version assumes a single
 * transmit sector and a contiguous beam numbering (water-column beam i == detection beam i).
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class S7KPingWatercolumn
    : public pingprocessing::datatypes::I_PingWatercolumn
    , public S7KPingCommon<t_ifstream>
{
  public:
    using t_base1 = pingprocessing::datatypes::I_PingWatercolumn;
    using t_base2 = S7KPingCommon<t_ifstream>;

    using t_base2::_file_data;
    using typename t_base2::t_rawdata;

  protected:
    std::string class_name() const override { return "S7KPingWatercolumn"; }

  public:
    S7KPingWatercolumn(std::shared_ptr<t_rawdata>                          file_data,
                       std::shared_ptr<pingprocessing::datatypes::PingInfo> ping_info = nullptr)
        : t_base1(std::move(ping_info))
        , t_base2(std::move(file_data))
    {
    }
    virtual ~S7KPingWatercolumn() = default;

    // un-hide the base no-argument convenience overloads (hidden by the selection overrides below)
    using t_base1::get_beam_alongtrack_angles;
    using t_base1::get_beam_crosstrack_angles_legacy;
    using t_base1::get_beam_numbers_per_tx_sector_legacy;
    using t_base1::get_bottom_range_samples;
    using t_base1::get_number_of_samples_per_beam;
    using t_base1::get_tx_sector_per_beam_legacy;

    // ----- feature checks -----
    bool has_amplitudes() const override { return _file_data->has_water_column(); }
    bool has_bottom_range_samples() const override { return _file_data->has_raw_detection(); }
    bool has_number_of_beams_legacy() const { return has_amplitudes(); }
    bool has_beam_crosstrack_angles_legacy() const override { return _file_data->has_raw_detection(); }

    bool has_number_of_tx_sectors_legacy() const { return has_amplitudes(); }
    bool has_tx_sector_per_beam_legacy() const { return has_amplitudes(); }
    bool has_beam_numbers_per_tx_sector_legacy() const { return has_amplitudes(); }

    bool has_watercolumn_calibration() const override
    {
        // a (uncalibrated) calibration can always be built from the ping when amplitudes exist
        return has_amplitudes() && get_number_of_tx_sectors_legacy() == 1;
    }
    bool has_multisectorwatercolumn_calibration() const override { return has_amplitudes(); }

    // ----- I_PingCommon interface -----
    void load(bool force = false) override
    {
        _file_data->load_wci(force);
        _file_data->load_detection(force);
        _file_data->load_sys(force);
        _file_data->init_watercolumn_calibration(force);
    }
    void release() override
    {
        _file_data->release_wci();
        _file_data->release_detection();
        _file_data->release_sys();
    }
    bool loaded() override
    {
        return _file_data->wci_loaded() && _file_data->has_watercolumn_calibration();
    }

    // ----- transmit sectors (single sector for now) -----
    size_t get_number_of_tx_sectors_legacy() const override { return 1; }

    bool has_tx_signal_parameters_legacy() const override { return _file_data->has_sonar_settings(); }

    std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>
    get_tx_signal_parameters_legacy() const override
    {
        if (_file_data->has_sonar_settings())
            return _file_data->get_sysinfos().get_tx_signal_parameters();
        return {};
    }

    xt::xtensor<size_t, 1> get_tx_sector_per_beam_legacy(
        const algorithms::pingtools::BeamSelection& selection) override
    {
        auto sectors = xt::xtensor<size_t, 1>::from_shape({ selection.get_number_of_beams() });
        sectors.fill(0);
        return sectors;
    }

    std::vector<std::vector<size_t>> get_beam_numbers_per_tx_sector_legacy(
        const algorithms::pingtools::BeamSelection& selection) override
    {
        std::vector<std::vector<size_t>> beam_numbers_per_tx_sector(1);
        for (size_t i = 0; i < selection.get_number_of_beams(); ++i)
            beam_numbers_per_tx_sector[0].push_back(i);
        return beam_numbers_per_tx_sector;
    }

    // ----- geometry -----
    uint32_t get_number_of_beams_legacy() const override
    {
        if (!has_amplitudes())
            return 0;
        return uint32_t(_file_data->get_wcinfos().get_number_of_beams());
    }

    xt::xtensor<float, 1> get_beam_crosstrack_angles_legacy(
        const algorithms::pingtools::BeamSelection& selection) override
    {
        // Receive steering angles from the raw detection record (degrees), one value per beam.
        // The 7027 rx_angle is in the s7k sonar frame (+starboard, beam 0 = port); the ping/kmall
        // crosstrack convention is +port, so negate. (MB-System negates rx_angle for the same
        // reason.) These are vessel-frame angles -> has_beam_crosstrack_angles_in_world_frame()
        // stays false so the raytracer/backtracer applies the roll.
        auto angles = index_beams(_file_data->get_rx_angle_in_degrees_per_beam_number(),
                                  selection.get_beam_numbers(),
                                  std::numeric_limits<float>::quiet_NaN());
        angles *= -1.f;
        return angles;
    }

    xt::xtensor<float, 1> get_beam_alongtrack_angles(
        const algorithms::pingtools::BeamSelection& selection) override
    {
        // s7k transmits along a single tilt angle; broadcast the transmit steering angle
        auto angles = xt::xtensor<float, 1>::from_shape({ selection.get_number_of_beams() });
        angles.fill(_file_data->get_detectioninfos().get_tx_angle_in_degrees());
        return angles;
    }

    xt::xtensor<uint32_t, 1> get_number_of_samples_per_beam(
        const algorithms::pingtools::BeamSelection& selection) override
    {
        return index_beams(_file_data->get_wcinfos().get_sample_counts(),
                           selection.get_beam_numbers(),
                           uint32_t(0));
    }

    xt::xtensor<uint32_t, 1> get_first_sample_offset_per_beam() override
    {
        // 7042 stores one first-sample index for the whole record
        auto offsets = xt::xtensor<uint32_t, 1>::from_shape({ get_number_of_beams_legacy() });
        offsets.fill(_file_data->get_wcinfos().get_first_sample());
        return offsets;
    }

    float get_sample_interval() override
    {
        float sample_rate = _file_data->get_wcinfos().get_sample_rate();
        return sample_rate > 0.f ? 1.f / sample_rate : std::numeric_limits<float>::quiet_NaN();
    }

    float get_sound_speed_at_transducer_legacy() override
    {
        if (_file_data->has_sonar_settings())
            return _file_data->get_sysinfos().get_sound_velocity();
        return std::numeric_limits<float>::quiet_NaN();
    }

    // ----- amplitudes / phase (s7k specific: raw native access) -----
    /**
     * @brief Water column amplitudes (magnitude) in their raw, unconverted values (uint32).
     *
     * The values are returned as stored on disk (widened to uint32; 16 bit records keep their
     * 0..65535 range). No dB conversion is applied - see get_amplitudes for dB. Missing
     * beams/samples are 0.
     */
    xt::xtensor<uint32_t, 2> get_raw_amplitudes()
    {
        return get_raw_amplitudes(get_beam_sample_selection_all());
    }
    xt::xtensor<uint32_t, 2> get_raw_amplitudes(const algorithms::pingtools::BeamSampleSelection& selection)
    {
        return assemble_beam_samples<uint32_t>(selection, extract_raw_magnitude);
    }

    /**
     * @brief Water column phase in its raw, unconverted int16 values (radians = value / 10430).
     *
     * All-zero if the record contains no phase. Missing beams/samples are 0.
     */
    xt::xtensor<int16_t, 2> get_raw_phase()
    {
        return get_raw_phase(get_beam_sample_selection_all());
    }
    xt::xtensor<int16_t, 2> get_raw_phase(const algorithms::pingtools::BeamSampleSelection& selection)
    {
        return assemble_beam_samples<int16_t>(selection, extract_raw_phase);
    }

    /**
     * @brief Water column phase in degrees (NaN for missing beams/samples, all-NaN if the record
     * contains no phase).
     */
    xt::xtensor<float, 2> get_phase() { return get_phase(get_beam_sample_selection_all()); }
    xt::xtensor<float, 2> get_phase(const algorithms::pingtools::BeamSampleSelection& selection)
    {
        // int16 phase value / 10430 = radians -> * this = degrees (deferred, vectorized)
        constexpr float deg_scale = 180.f / (std::numbers::pi_v<float> * 10430.f);
        auto            phase     = assemble_beam_samples<float>(selection, extract_raw_phase);
        return phase * deg_scale;
    }

    // ----- amplitudes (dB, deferred conversion) -----
    xt::xtensor<float, 2> get_amplitudes(const algorithms::pingtools::BeamSampleSelection& selection,
                                         [[maybe_unused]] int mp_cores = 1) override
    {
        // assemble the selected raw magnitudes as float (no conversion yet) ...
        auto amplitudes = assemble_beam_samples<float>(selection, extract_raw_magnitude);

        // ... then convert only the selected samples to dB (vectorized / xsimd-friendly)
        amplitudes = _file_data->get_wcinfos().convert_magnitude_to_db(std::move(amplitudes));

        // 20*log10(0) yields -inf for zero-magnitude samples; map non-finite values to -120 dB so
        // downstream min/max (color scaling, echograms) stay finite
        amplitudes = xt::where(
            xt::isfinite(amplitudes), amplitudes, -120);

        return amplitudes;
    }

    xt::xtensor<uint32_t, 1> get_bottom_range_samples(
        const algorithms::pingtools::BeamSelection& selection) override
    {
        // The 7027 detection_point is in the original (full-rate) sample domain, but the 7042
        // water-column samples use the compressed (downsampled) rate.  Divide by the
        // downsampling divisor to convert to the same sample-number domain as the WCI.
        const auto& detection_points = _file_data->get_detection_point_per_beam_number();
        const auto& beam_numbers     = selection.get_beam_numbers();
        const float divisor =
            float(std::max(uint8_t(1), _file_data->get_wcinfos().get_downsampling_divisor()));

        auto bottom_range_samples = xt::xtensor<uint32_t, 1>::from_shape({ beam_numbers.size() });
        for (size_t i = 0; i < beam_numbers.size(); ++i)
        {
            if (beam_numbers[i] < detection_points.size() &&
                std::isfinite(detection_points.unchecked(beam_numbers[i])))
                bottom_range_samples.unchecked(i) =
                    uint32_t(detection_points.unchecked(beam_numbers[i]) / divisor);
            else
                bottom_range_samples.unchecked(i) = 0;
        }

        return bottom_range_samples;
    }

    // ----- calibration -----
    const pingprocessing::datatypes::calibration::I_MultiSectorCalibration&
    get_multisectorwatercolumn_calibration() const override
    {
        _file_data->init_watercolumn_calibration(); // lazy: build the calibration on first access
        return _file_data->get_multisector_calibration();
    }

    const pingprocessing::datatypes::calibration::WaterColumnCalibration& get_watercolumn_calibration()
        const override
    {
        _file_data->init_watercolumn_calibration(); // lazy: build the calibration on first access
        return _file_data->get_watercolumn_calibration();
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
    // native-encoding sample extractors (used with assemble_beam_samples); each receives the beam's
    // samples as read from the file and returns the raw magnitude / phase
    static xt::xtensor<uint32_t, 1> extract_raw_magnitude(
        const datagrams::substructs::CompressedWaterColumnDataVariant& samples)
    {
        return std::visit([](const auto& data) { return data.get_raw_magnitude(); }, samples);
    }
    static xt::xtensor<int16_t, 1> extract_raw_phase(
        const datagrams::substructs::CompressedWaterColumnDataVariant& samples)
    {
        return std::visit([](const auto& data) { return data.get_raw_phase(); }, samples);
    }

    /**
     * @brief Assemble per-beam sample data into a [beams, samples] ensemble for a selection.
     *
     * For each selected beam only the selected sample range is read directly from the file (via the
     * stored per-beam file position) and copied into the output row (cast to t_out on assignment).
     * The water-column samples are therefore never held in memory - they are read on demand and
     * returned. Missing beams/samples are NaN (floating point) or 0 (integer).
     *
     * @tparam t_out output value type
     * @tparam t_sample_extractor callable (const CompressedWaterColumnDataVariant&) ->
     * xt::xtensor<...,1> returning the (already sub-ranged) magnitude or phase samples
     */
    template<typename t_out, typename t_sample_extractor>
    xt::xtensor<t_out, 2> assemble_beam_samples(const algorithms::pingtools::BeamSampleSelection& selection,
                                                t_sample_extractor&& extract_samples)
    {
        const auto&    wcinfos       = _file_data->get_wcinfos();
        const auto&    sample_counts = wcinfos.get_sample_counts();
        const uint32_t first_sample  = wcinfos.get_first_sample();
        const size_t   n_beams       = wcinfos.get_number_of_beams();

        auto& ifs =
            _file_data->get_ifs(t_S7KDatagramIdentifier::CompressedWaterColumnData);

        auto out = xt::xtensor<t_out, 2>::from_shape(
            { selection.get_number_of_beams(), selection.get_number_of_samples_ensemble() });
        if constexpr (std::is_floating_point_v<t_out>)
            out.fill(std::numeric_limits<t_out>::quiet_NaN());
        else
            out.fill(t_out(0));

        const size_t ensemble_offset = selection.get_first_sample_number_ensemble();

        size_t output_bn = 0;
        for (const auto& bn : selection.get_beam_numbers())
        {
            if (bn < n_beams)
            {
                auto rsr = selection.get_read_sample_range(
                    uint32_t(output_bn), first_sample, sample_counts.unchecked(bn));

                if (rsr.get_number_of_samples_to_read() > 0)
                {
                    // read only the requested sub-range of this beam's samples from the file
                    auto samples = extract_samples(wcinfos.read_beam_samples(
                        uint16_t(bn),
                        rsr.get_first_sample_to_read(),
                        rsr.get_number_of_samples_to_read(),
                        ifs));

                    xt::view(out,
                             output_bn,
                             xt::range(rsr.get_first_read_sample_offset() - ensemble_offset,
                                       rsr.get_last_read_sample_offset() + 1 - ensemble_offset)) =
                        samples;
                }
            }
            ++output_bn;
        }

        return out;
    }

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
