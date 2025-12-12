// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mrzsoundingscontainer.doc.hpp"

/* generated doc strings */
#include ".docstrings/mrzsoundingscontainer.doc.hpp"

#include <cstddef>
#include <cstdint>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include "mrzsoundings.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

class MRZSoundingsContainer
{
  public:
    MRZSoundingsContainer()  = default;
    ~MRZSoundingsContainer() = default;

    const std::vector<MRZSoundings>& get_soundings() const;
    std::vector<MRZSoundings>&       soundings();
    void                             set_soundings(const std::vector<MRZSoundings>& soundings);

    xt::xtensor<uint16_t, 1> get_sounding_index_tensor() const;
    xt::xtensor<uint8_t, 1>  get_tx_sector_number_tensor() const;

    xt::xtensor<uint8_t, 1>  get_detection_type_tensor() const;
    xt::xtensor<uint8_t, 1>  get_detection_method_tensor() const;
    xt::xtensor<uint8_t, 1>  get_rejection_info_1_tensor() const;
    xt::xtensor<uint8_t, 1>  get_rejection_info_2_tensor() const;
    xt::xtensor<uint8_t, 1>  get_post_processing_info_tensor() const;
    xt::xtensor<uint8_t, 1>  get_detection_class_tensor() const;
    xt::xtensor<uint8_t, 1>  get_detection_confidence_level_tensor() const;
    xt::xtensor<uint16_t, 1> get_padding_tensor() const;

    xt::xtensor<float, 1> get_range_factor_tensor() const;
    xt::xtensor<float, 1> get_quality_factor_tensor() const;
    xt::xtensor<float, 1> get_detection_uncertainty_ver_m_tensor() const;
    xt::xtensor<float, 1> get_detection_uncertainty_hor_m_tensor() const;
    xt::xtensor<float, 1> get_detection_window_length_sec_tensor() const;
    xt::xtensor<float, 1> get_echo_length_sec_tensor() const;

    xt::xtensor<uint16_t, 1> get_wc_beam_number_tensor() const;
    xt::xtensor<uint16_t, 1> get_wc_range_samples_tensor() const;
    xt::xtensor<float, 1>    get_wc_nom_beam_angle_across_deg_tensor() const;

    xt::xtensor<float, 1> get_mean_abs_coeff_db_per_km_tensor() const;
    xt::xtensor<float, 1> get_reflectivity_1_db_tensor() const;
    xt::xtensor<float, 1> get_reflectivity_2_db_tensor() const;
    xt::xtensor<float, 1> get_receiver_sensitivity_applied_db_tensor() const;
    xt::xtensor<float, 1> get_source_level_applied_db_tensor() const;
    xt::xtensor<float, 1> get_bs_calibration_db_tensor() const;
    xt::xtensor<float, 1> get_tvg_db_tensor() const;

    xt::xtensor<float, 1> get_beam_angle_re_rx_deg_tensor() const;
    xt::xtensor<float, 1> get_beam_angle_correction_deg_tensor() const;
    xt::xtensor<float, 1> get_two_way_travel_time_sec_tensor() const;
    xt::xtensor<float, 1> get_two_way_travel_time_correction_sec_tensor() const;

    xt::xtensor<float, 1> get_delta_latitude_deg_tensor() const;
    xt::xtensor<float, 1> get_delta_longitude_deg_tensor() const;
    xt::xtensor<float, 1> get_z_re_ref_point_m_tensor() const;
    xt::xtensor<float, 1> get_y_re_ref_point_m_tensor() const;
    xt::xtensor<float, 1> get_x_re_ref_point_m_tensor() const;
    xt::xtensor<float, 1> get_beam_inc_angle_adj_deg_tensor() const;

    xt::xtensor<uint16_t, 1> get_real_time_clean_info_tensor() const;

    xt::xtensor<uint16_t, 1> get_si_start_range_samples_tensor() const;
    xt::xtensor<uint16_t, 1> get_si_centre_sample_tensor() const;
    xt::xtensor<uint16_t, 1> get_si_num_samples_tensor() const;

    // --- processed ---
    size_t get_number_of_soundings() const;
    size_t get_number_of_seabed_image_samples() const;
    xt::xtensor<uint16_t, 1> get_seabed_image_sounding_index_tensor() const;

    /**
     * @brief Compute the mean absorption coefficient per transmit sector.
     *
     * This function computes the mean of the absorption coefficients (dB/m) for all
     * soundings belonging to each transmit sector.
     *
     * @param number_of_tx_sectors The number of transmit sectors in the ping
     * @return xt::xtensor<float, 1> Mean absorption coefficient in dB/m for each sector
     */
    xt::xtensor<float, 1> get_mean_absorption_db_per_m_per_sector(size_t number_of_tx_sectors) const;

    bool operator==(const MRZSoundingsContainer& other) const = default;

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    std::vector<MRZSoundings> _soundings;

    template<typename ValueType, typename Getter>
    xt::xtensor<ValueType, 1> build_tensor(Getter&& getter) const
    {
        auto tensor = xt::xtensor<ValueType, 1>::from_shape({ _soundings.size() });
        for (std::size_t idx = 0; idx < _soundings.size(); ++idx)
        {
            tensor.unchecked(idx) = static_cast<ValueType>(getter(_soundings[idx]));
        }
        return tensor;
    }
};

} // namespace substructs
} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
