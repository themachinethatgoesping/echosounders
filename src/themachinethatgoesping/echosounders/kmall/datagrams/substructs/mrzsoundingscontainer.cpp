// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mrzsoundingscontainer.hpp"

#include <limits>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

const std::vector<MRZSoundings>& MRZSoundingsContainer::get_soundings() const
{
    return _soundings;
}

std::vector<MRZSoundings>& MRZSoundingsContainer::soundings()
{
    return _soundings;
}

void MRZSoundingsContainer::set_soundings(const std::vector<MRZSoundings>& soundings)
{
    _soundings = soundings;
}

xt::xtensor<uint16_t, 1> MRZSoundingsContainer::get_sounding_index_tensor() const
{
    return build_tensor<uint16_t>(
        [](const MRZSoundings& sounding) { return sounding.get_sounding_index(); });
}

xt::xtensor<uint8_t, 1> MRZSoundingsContainer::get_tx_sector_number_tensor() const
{
    return build_tensor<uint8_t>(
        [](const MRZSoundings& sounding) { return sounding.get_tx_sector_number(); });
}

xt::xtensor<uint8_t, 1> MRZSoundingsContainer::get_detection_type_tensor() const
{
    return build_tensor<uint8_t>(
        [](const MRZSoundings& sounding) { return sounding.get_detection_type(); });
}

xt::xtensor<uint8_t, 1> MRZSoundingsContainer::get_detection_method_tensor() const
{
    return build_tensor<uint8_t>(
        [](const MRZSoundings& sounding) { return sounding.get_detection_method(); });
}

xt::xtensor<uint8_t, 1> MRZSoundingsContainer::get_rejection_info_1_tensor() const
{
    return build_tensor<uint8_t>(
        [](const MRZSoundings& sounding) { return sounding.get_rejection_info_1(); });
}

xt::xtensor<uint8_t, 1> MRZSoundingsContainer::get_rejection_info_2_tensor() const
{
    return build_tensor<uint8_t>(
        [](const MRZSoundings& sounding) { return sounding.get_rejection_info_2(); });
}

xt::xtensor<uint8_t, 1> MRZSoundingsContainer::get_post_processing_info_tensor() const
{
    return build_tensor<uint8_t>(
        [](const MRZSoundings& sounding) { return sounding.get_post_processing_info(); });
}

xt::xtensor<uint8_t, 1> MRZSoundingsContainer::get_detection_class_tensor() const
{
    return build_tensor<uint8_t>(
        [](const MRZSoundings& sounding) { return sounding.get_detection_class(); });
}

xt::xtensor<uint8_t, 1> MRZSoundingsContainer::get_detection_confidence_level_tensor() const
{
    return build_tensor<uint8_t>(
        [](const MRZSoundings& sounding) { return sounding.get_detection_confidence_level(); });
}

xt::xtensor<uint16_t, 1> MRZSoundingsContainer::get_padding_tensor() const
{
    return build_tensor<uint16_t>(
        [](const MRZSoundings& sounding) { return sounding.get_padding(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_range_factor_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_range_factor(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_quality_factor_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_quality_factor(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_detection_uncertainty_ver_m_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_detection_uncertainty_ver_m(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_detection_uncertainty_hor_m_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_detection_uncertainty_hor_m(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_detection_window_length_sec_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_detection_window_length_sec(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_echo_length_sec_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_echo_length_sec(); });
}

xt::xtensor<uint16_t, 1> MRZSoundingsContainer::get_wc_beam_number_tensor() const
{
    return build_tensor<uint16_t>(
        [](const MRZSoundings& sounding) { return sounding.get_wc_beam_number(); });
}

xt::xtensor<uint16_t, 1> MRZSoundingsContainer::get_wc_range_samples_tensor() const
{
    return build_tensor<uint16_t>(
        [](const MRZSoundings& sounding) { return sounding.get_wc_range_samples(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_wc_nom_beam_angle_across_deg_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_wc_nom_beam_angle_across_deg(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_mean_abs_coeff_db_per_km_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_mean_abs_coeff_db_per_km(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_reflectivity_1_db_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_reflectivity_1_db(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_reflectivity_2_db_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_reflectivity_2_db(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_receiver_sensitivity_applied_db_tensor() const
{
    return build_tensor<float>([](const MRZSoundings& sounding) {
        return sounding.get_receiver_sensitivity_applied_db();
    });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_source_level_applied_db_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_source_level_applied_db(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_bs_calibration_db_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_bs_calibration_db(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_tvg_db_tensor() const
{
    return build_tensor<float>([](const MRZSoundings& sounding) { return sounding.get_tvg_db(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_beam_angle_re_rx_deg_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_beam_angle_re_rx_deg(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_beam_angle_correction_deg_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_beam_angle_correction_deg(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_two_way_travel_time_sec_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_two_way_travel_time_sec(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_two_way_travel_time_correction_sec_tensor() const
{
    return build_tensor<float>([](const MRZSoundings& sounding) {
        return sounding.get_two_way_travel_time_correction_sec();
    });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_delta_latitude_deg_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_delta_latitude_deg(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_delta_longitude_deg_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_delta_longitude_deg(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_z_re_ref_point_m_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_z_re_ref_point_m(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_y_re_ref_point_m_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_y_re_ref_point_m(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_x_re_ref_point_m_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_x_re_ref_point_m(); });
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_beam_inc_angle_adj_deg_tensor() const
{
    return build_tensor<float>(
        [](const MRZSoundings& sounding) { return sounding.get_beam_inc_angle_adj_deg(); });
}

xt::xtensor<uint16_t, 1> MRZSoundingsContainer::get_real_time_clean_info_tensor() const
{
    return build_tensor<uint16_t>(
        [](const MRZSoundings& sounding) { return sounding.get_real_time_clean_info(); });
}

xt::xtensor<uint16_t, 1> MRZSoundingsContainer::get_si_start_range_samples_tensor() const
{
    return build_tensor<uint16_t>(
        [](const MRZSoundings& sounding) { return sounding.get_si_start_range_samples(); });
}

xt::xtensor<uint16_t, 1> MRZSoundingsContainer::get_si_centre_sample_tensor() const
{
    return build_tensor<uint16_t>(
        [](const MRZSoundings& sounding) { return sounding.get_si_centre_sample(); });
}

xt::xtensor<uint16_t, 1> MRZSoundingsContainer::get_si_num_samples_tensor() const
{
    return build_tensor<uint16_t>(
        [](const MRZSoundings& sounding) { return sounding.get_si_num_samples(); });
}

// ----- processed -----
size_t MRZSoundingsContainer::get_number_of_soundings() const
{
    return _soundings.size();
}
size_t MRZSoundingsContainer::get_number_of_seabed_image_samples() const
{
    size_t total_samples = 0;

    for (const auto& sounding : _soundings)
        total_samples += sounding.get_si_num_samples();

    return total_samples;
}

xt::xtensor<uint16_t, 1> MRZSoundingsContainer::get_seabed_image_sounding_index_tensor() const
{
    xt::xtensor<uint16_t, 1> beam_numbers;
    beam_numbers.resize({ get_number_of_seabed_image_samples() });

    size_t index = 0;
    for (size_t i = 0; i < _soundings.size(); ++i)
    {
        const size_t num_samples = _soundings[i].get_si_num_samples();

        xt::view(beam_numbers, xt::range(index, index + num_samples)) = i;
        index += num_samples;
    }

    return beam_numbers;
}

xt::xtensor<float, 1> MRZSoundingsContainer::get_mean_absorption_db_per_m_per_sector(
    size_t number_of_tx_sectors) const
{
    // Result tensor for mean absorption per sector (in dB/m)
    auto mean_absorption = xt::xtensor<float, 1>::from_shape({ number_of_tx_sectors });
    mean_absorption.fill(0.0f);

    // Count soundings per sector for averaging
    auto counts = std::vector<size_t>(number_of_tx_sectors, 0);

    // Accumulate absorption values per sector
    // Note: soundings store absorption in dB/km, we need to convert to dB/m
    for (const auto& sounding : _soundings)
    {
        const auto sector = sounding.get_tx_sector_number();
        if (sector < number_of_tx_sectors)
        {
            // Convert from dB/km to dB/m (divide by 1000)
            mean_absorption.unchecked(sector) += sounding.get_mean_abs_coeff_db_per_km();
            ++counts[sector];
        }
    }

    // Compute mean for each sector
    for (size_t i = 0; i < number_of_tx_sectors; ++i)
    {
        if (counts[i] > 0)
        {
            float tmp = 0.001f / static_cast<float>(counts[i]);
            mean_absorption.unchecked(i) *= tmp;
        }
        else
        {
            mean_absorption.unchecked(i) = std::numeric_limits<float>::quiet_NaN();
        }
    }

    return mean_absorption;
}

tools::classhelper::ObjectPrinter MRZSoundingsContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MRZSoundingsContainer", float_precision, superscript_exponents);

    printer.register_section("Soundings (.soundings)");
    printer.register_value(
        "soundings (vector)", fmt::format("size={}", get_soundings().size()), "soundings");

    printer.register_container("sounding_index", get_sounding_index_tensor());
    printer.register_container("tx_sector_number", get_tx_sector_number_tensor());
    printer.register_container("detection_type", get_detection_type_tensor());
    printer.register_container("detection_method", get_detection_method_tensor());
    printer.register_container("rejection_info_1", get_rejection_info_1_tensor());
    printer.register_container("rejection_info_2", get_rejection_info_2_tensor());
    printer.register_container("post_processing_info", get_post_processing_info_tensor());
    printer.register_container("detection_class", get_detection_class_tensor());
    printer.register_container("detection_confidence_level",
                               get_detection_confidence_level_tensor());
    printer.register_container("padding", get_padding_tensor());
    printer.register_container("range_factor", get_range_factor_tensor());
    printer.register_container("quality_factor", get_quality_factor_tensor());
    printer.register_container(
        "detection_uncertainty_ver_m", get_detection_uncertainty_ver_m_tensor(), "m");
    printer.register_container(
        "detection_uncertainty_hor_m", get_detection_uncertainty_hor_m_tensor(), "m");
    printer.register_container(
        "detection_window_length_sec", get_detection_window_length_sec_tensor(), "s");
    printer.register_container("echo_length_sec", get_echo_length_sec_tensor(), "s");
    printer.register_container("wc_beam_number", get_wc_beam_number_tensor());
    printer.register_container("wc_range_samples", get_wc_range_samples_tensor());
    printer.register_container(
        "wc_nom_beam_angle_across_deg", get_wc_nom_beam_angle_across_deg_tensor(), "deg");
    printer.register_container(
        "mean_abs_coeff_db_per_km", get_mean_abs_coeff_db_per_km_tensor(), "dB/km");
    printer.register_container("reflectivity_1_db", get_reflectivity_1_db_tensor(), "dB");
    printer.register_container("reflectivity_2_db", get_reflectivity_2_db_tensor(), "dB");
    printer.register_container(
        "receiver_sensitivity_applied_db", get_receiver_sensitivity_applied_db_tensor(), "dB");
    printer.register_container(
        "source_level_applied_db", get_source_level_applied_db_tensor(), "dB");
    printer.register_container("bs_calibration_db", get_bs_calibration_db_tensor(), "dB");
    printer.register_container("tvg_db", get_tvg_db_tensor(), "dB");
    printer.register_container("beam_angle_re_rx_deg", get_beam_angle_re_rx_deg_tensor(), "deg");
    printer.register_container(
        "beam_angle_correction_deg", get_beam_angle_correction_deg_tensor(), "deg");
    printer.register_container(
        "two_way_travel_time_sec", get_two_way_travel_time_sec_tensor(), "s");
    printer.register_container(
        "two_way_travel_time_correction_sec", get_two_way_travel_time_correction_sec_tensor(), "s");
    printer.register_container("delta_latitude_deg", get_delta_latitude_deg_tensor(), "deg");
    printer.register_container("delta_longitude_deg", get_delta_longitude_deg_tensor(), "deg");
    printer.register_container("z_re_ref_point_m", get_z_re_ref_point_m_tensor(), "m");
    printer.register_container("y_re_ref_point_m", get_y_re_ref_point_m_tensor(), "m");
    printer.register_container("x_re_ref_point_m", get_x_re_ref_point_m_tensor(), "m");
    printer.register_container(
        "beam_inc_angle_adj_deg", get_beam_inc_angle_adj_deg_tensor(), "deg");
    printer.register_container("real_time_clean_info", get_real_time_clean_info_tensor());
    printer.register_container("si_start_range_samples", get_si_start_range_samples_tensor());
    printer.register_container("si_centre_sample", get_si_centre_sample_tensor());
    printer.register_container("si_num_samples", get_si_num_samples_tensor());

    printer.register_section("processed");
    printer.register_value("number_of_soundings", get_number_of_soundings());
    printer.register_value("number_of_seabed_image_samples", get_number_of_seabed_image_samples());
    printer.register_container("get_seabed_image_sounding_index_tensor",
                               get_seabed_image_sounding_index_tensor());

    return printer;
}
}
}
}
}
}
