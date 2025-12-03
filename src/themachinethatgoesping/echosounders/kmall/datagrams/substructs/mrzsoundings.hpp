// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mrzsoundings.doc.hpp"

// std includes
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

#pragma pack(push, 4) // force 4-byte alignment
class MRZSoundings
{
    uint16_t _sounding_index;
    uint8_t  _tx_sector_number;

    uint8_t _detection_type;
    uint8_t _detection_method;
    uint8_t _rejection_info_1;
    uint8_t _rejection_info_2;
    uint8_t _post_processing_info;
    uint8_t _detection_class;
    uint8_t _detection_confidence_level;
    uint16_t _padding;

    float _range_factor;
    float _quality_factor;
    float _detection_uncertainty_ver_m;
    float _detection_uncertainty_hor_m;
    float _detection_window_length_sec;
    float _echo_length_sec;

    uint16_t _wc_beam_number;
    uint16_t _wc_range_samples;
    float    _wc_nom_beam_angle_across_deg;

    float _mean_abs_coeff_db_per_km;
    float _reflectivity_1_db;
    float _reflectivity_2_db;
    float _receiver_sensitivity_applied_db;
    float _source_level_applied_db;
    float _bs_calibration_db;
    float _tvg_db;

    float _beam_angle_re_rx_deg;
    float _beam_angle_correction_deg;
    float _two_way_travel_time_sec;
    float _two_way_travel_time_correction_sec;

    float _delta_latitude_deg;
    float _delta_longitude_deg;
    float _z_re_ref_point_m;
    float _y_re_ref_point_m;
    float _x_re_ref_point_m;
    float _beam_inc_angle_adj_deg;

    uint16_t _real_time_clean_info;

    uint16_t _si_start_range_samples;
    uint16_t _si_centre_sample;
    uint16_t _si_num_samples;

  public:
    MRZSoundings()  = default;
    ~MRZSoundings() = default;

    uint16_t get_sounding_index() const { return _sounding_index; }
    uint8_t  get_tx_sector_number() const { return _tx_sector_number; }

    uint8_t  get_detection_type() const { return _detection_type; }
    uint8_t  get_detection_method() const { return _detection_method; }
    uint8_t  get_rejection_info_1() const { return _rejection_info_1; }
    uint8_t  get_rejection_info_2() const { return _rejection_info_2; }
    uint8_t  get_post_processing_info() const { return _post_processing_info; }
    uint8_t  get_detection_class() const { return _detection_class; }
    uint8_t  get_detection_confidence_level() const { return _detection_confidence_level; }
    uint16_t get_padding() const { return _padding; }

    float get_range_factor() const { return _range_factor; }
    float get_quality_factor() const { return _quality_factor; }
    float get_detection_uncertainty_ver_m() const { return _detection_uncertainty_ver_m; }
    float get_detection_uncertainty_hor_m() const { return _detection_uncertainty_hor_m; }
    float get_detection_window_length_sec() const { return _detection_window_length_sec; }
    float get_echo_length_sec() const { return _echo_length_sec; }

    uint16_t get_wc_beam_number() const { return _wc_beam_number; }
    uint16_t get_wc_range_samples() const { return _wc_range_samples; }
    float    get_wc_nom_beam_angle_across_deg() const { return _wc_nom_beam_angle_across_deg; }

    float get_mean_abs_coeff_db_per_km() const { return _mean_abs_coeff_db_per_km; }
    float get_reflectivity_1_db() const { return _reflectivity_1_db; }
    float get_reflectivity_2_db() const { return _reflectivity_2_db; }
    float get_receiver_sensitivity_applied_db() const { return _receiver_sensitivity_applied_db; }
    float get_source_level_applied_db() const { return _source_level_applied_db; }
    float get_bs_calibration_db() const { return _bs_calibration_db; }
    float get_tvg_db() const { return _tvg_db; }

    float get_beam_angle_re_rx_deg() const { return _beam_angle_re_rx_deg; }
    float get_beam_angle_correction_deg() const { return _beam_angle_correction_deg; }
    float get_two_way_travel_time_sec() const { return _two_way_travel_time_sec; }
    float get_two_way_travel_time_correction_sec() const
    {
        return _two_way_travel_time_correction_sec;
    }

    float get_delta_latitude_deg() const { return _delta_latitude_deg; }
    float get_delta_longitude_deg() const { return _delta_longitude_deg; }
    float get_z_re_ref_point_m() const { return _z_re_ref_point_m; }
    float get_y_re_ref_point_m() const { return _y_re_ref_point_m; }
    float get_x_re_ref_point_m() const { return _x_re_ref_point_m; }
    float get_beam_inc_angle_adj_deg() const { return _beam_inc_angle_adj_deg; }

    uint16_t get_real_time_clean_info() const { return _real_time_clean_info; }

    uint16_t get_si_start_range_samples() const { return _si_start_range_samples; }
    uint16_t get_si_centre_sample() const { return _si_centre_sample; }
    uint16_t get_si_num_samples() const { return _si_num_samples; }

    void set_sounding_index(uint16_t val) { _sounding_index = val; }
    void set_tx_sector_number(uint8_t val) { _tx_sector_number = val; }

    void set_detection_type(uint8_t val) { _detection_type = val; }
    void set_detection_method(uint8_t val) { _detection_method = val; }
    void set_rejection_info_1(uint8_t val) { _rejection_info_1 = val; }
    void set_rejection_info_2(uint8_t val) { _rejection_info_2 = val; }
    void set_post_processing_info(uint8_t val) { _post_processing_info = val; }
    void set_detection_class(uint8_t val) { _detection_class = val; }
    void set_detection_confidence_level(uint8_t val) { _detection_confidence_level = val; }
    void set_padding(uint16_t val) { _padding = val; }

    void set_range_factor(float val) { _range_factor = val; }
    void set_quality_factor(float val) { _quality_factor = val; }
    void set_detection_uncertainty_ver_m(float val) { _detection_uncertainty_ver_m = val; }
    void set_detection_uncertainty_hor_m(float val) { _detection_uncertainty_hor_m = val; }
    void set_detection_window_length_sec(float val) { _detection_window_length_sec = val; }
    void set_echo_length_sec(float val) { _echo_length_sec = val; }

    void set_wc_beam_number(uint16_t val) { _wc_beam_number = val; }
    void set_wc_range_samples(uint16_t val) { _wc_range_samples = val; }
    void set_wc_nom_beam_angle_across_deg(float val) { _wc_nom_beam_angle_across_deg = val; }

    void set_mean_abs_coeff_db_per_km(float val) { _mean_abs_coeff_db_per_km = val; }
    void set_reflectivity_1_db(float val) { _reflectivity_1_db = val; }
    void set_reflectivity_2_db(float val) { _reflectivity_2_db = val; }
    void set_receiver_sensitivity_applied_db(float val)
    {
        _receiver_sensitivity_applied_db = val;
    }
    void set_source_level_applied_db(float val) { _source_level_applied_db = val; }
    void set_bs_calibration_db(float val) { _bs_calibration_db = val; }
    void set_tvg_db(float val) { _tvg_db = val; }

    void set_beam_angle_re_rx_deg(float val) { _beam_angle_re_rx_deg = val; }
    void set_beam_angle_correction_deg(float val) { _beam_angle_correction_deg = val; }
    void set_two_way_travel_time_sec(float val) { _two_way_travel_time_sec = val; }
    void set_two_way_travel_time_correction_sec(float val)
    {
        _two_way_travel_time_correction_sec = val;
    }

    void set_delta_latitude_deg(float val) { _delta_latitude_deg = val; }
    void set_delta_longitude_deg(float val) { _delta_longitude_deg = val; }
    void set_z_re_ref_point_m(float val) { _z_re_ref_point_m = val; }
    void set_y_re_ref_point_m(float val) { _y_re_ref_point_m = val; }
    void set_x_re_ref_point_m(float val) { _x_re_ref_point_m = val; }
    void set_beam_inc_angle_adj_deg(float val) { _beam_inc_angle_adj_deg = val; }

    void set_real_time_clean_info(uint16_t val) { _real_time_clean_info = val; }

    void set_si_start_range_samples(uint16_t val) { _si_start_range_samples = val; }
    void set_si_centre_sample(uint16_t val) { _si_centre_sample = val; }
    void set_si_num_samples(uint16_t val) { _si_num_samples = val; }

    bool operator==(const MRZSoundings& other) const;

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};
#pragma pack(pop)

} // namespace substructs
} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping

