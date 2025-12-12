// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mrzsoundings.hpp"

#include <fmt/format.h>

#include <themachinethatgoesping/tools/helper/floatcompare.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

bool MRZSoundings::operator==(const MRZSoundings& other) const
{
    using themachinethatgoesping::tools::helper::float_equals;
    return _sounding_index == other._sounding_index &&
           _tx_sector_number == other._tx_sector_number &&
           _detection_type == other._detection_type &&
           _detection_method == other._detection_method &&
           _rejection_info_1 == other._rejection_info_1 &&
           _rejection_info_2 == other._rejection_info_2 &&
           _post_processing_info == other._post_processing_info &&
           _detection_class == other._detection_class &&
           _detection_confidence_level == other._detection_confidence_level &&
           _padding == other._padding && float_equals(_range_factor, other._range_factor) &&
           float_equals(_quality_factor, other._quality_factor) &&
           float_equals(_detection_uncertainty_ver_m, other._detection_uncertainty_ver_m) &&
           float_equals(_detection_uncertainty_hor_m, other._detection_uncertainty_hor_m) &&
           float_equals(_detection_window_length_sec, other._detection_window_length_sec) &&
           float_equals(_echo_length_sec, other._echo_length_sec) &&
           _wc_beam_number == other._wc_beam_number &&
           _wc_range_samples == other._wc_range_samples &&
           float_equals(_wc_nom_beam_angle_across_deg, other._wc_nom_beam_angle_across_deg) &&
           float_equals(_mean_abs_coeff_db_per_km, other._mean_abs_coeff_db_per_km) &&
           float_equals(_reflectivity_1_db, other._reflectivity_1_db) &&
           float_equals(_reflectivity_2_db, other._reflectivity_2_db) &&
           float_equals(_receiver_sensitivity_applied_db, other._receiver_sensitivity_applied_db) &&
           float_equals(_source_level_applied_db, other._source_level_applied_db) &&
           float_equals(_bs_calibration_db, other._bs_calibration_db) &&
           float_equals(_tvg_db, other._tvg_db) &&
           float_equals(_beam_angle_re_rx_deg, other._beam_angle_re_rx_deg) &&
           float_equals(_beam_angle_correction_deg, other._beam_angle_correction_deg) &&
           float_equals(_two_way_travel_time_sec, other._two_way_travel_time_sec) &&
           float_equals(_two_way_travel_time_correction_sec,
                        other._two_way_travel_time_correction_sec) &&
           float_equals(_delta_latitude_deg, other._delta_latitude_deg) &&
           float_equals(_delta_longitude_deg, other._delta_longitude_deg) &&
           float_equals(_z_re_ref_point_m, other._z_re_ref_point_m) &&
           float_equals(_y_re_ref_point_m, other._y_re_ref_point_m) &&
           float_equals(_x_re_ref_point_m, other._x_re_ref_point_m) &&
           float_equals(_beam_inc_angle_adj_deg, other._beam_inc_angle_adj_deg) &&
           _real_time_clean_info == other._real_time_clean_info &&
           _si_start_range_samples == other._si_start_range_samples &&
           _si_centre_sample == other._si_centre_sample && _si_num_samples == other._si_num_samples;
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter MRZSoundings::__printer__(unsigned int float_precision,
                                                            bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MRZSoundings", float_precision, superscript_exponents);

    printer.register_value("sounding_index", _sounding_index);
    printer.register_value("tx_sector_number", _tx_sector_number);

    printer.register_value("detection_type", _detection_type);
    printer.register_value("detection_method", _detection_method);
    printer.register_value("rejection_info_1", _rejection_info_1);
    printer.register_value("rejection_info_2", _rejection_info_2);
    printer.register_value("post_processing_info", _post_processing_info);
    printer.register_value("detection_class", _detection_class);
    printer.register_value("detection_confidence_level", _detection_confidence_level);
    printer.register_value("padding", _padding);

    printer.register_value("range_factor", _range_factor);
    printer.register_value("quality_factor", _quality_factor);
    printer.register_value("detection_uncertainty_ver_m", _detection_uncertainty_ver_m, "m");
    printer.register_value("detection_uncertainty_hor_m", _detection_uncertainty_hor_m, "m");
    printer.register_value("detection_window_length_sec", _detection_window_length_sec, "s");
    printer.register_value("echo_length_sec", _echo_length_sec, "s");

    printer.register_value("wc_beam_number", _wc_beam_number);
    printer.register_value("wc_range_samples", _wc_range_samples);
    printer.register_value("wc_nom_beam_angle_across_deg", _wc_nom_beam_angle_across_deg, "deg");

    printer.register_value("mean_abs_coeff_db_per_km", _mean_abs_coeff_db_per_km, "dB/km");
    printer.register_value("reflectivity_1_db", _reflectivity_1_db, "dB");
    printer.register_value("reflectivity_2_db", _reflectivity_2_db, "dB");
    printer.register_value(
        "receiver_sensitivity_applied_db", _receiver_sensitivity_applied_db, "dB");
    printer.register_value("source_level_applied_db", _source_level_applied_db, "dB");
    printer.register_value("bs_calibration_db", _bs_calibration_db, "dB");
    printer.register_value("tvg_db", _tvg_db, "dB");

    printer.register_value("beam_angle_re_rx_deg", _beam_angle_re_rx_deg, "deg");
    printer.register_value("beam_angle_correction_deg", _beam_angle_correction_deg, "deg");
    printer.register_value("two_way_travel_time_sec", _two_way_travel_time_sec, "s");
    printer.register_value(
        "two_way_travel_time_correction_sec", _two_way_travel_time_correction_sec, "s");

    printer.register_value("delta_latitude_deg", _delta_latitude_deg, "deg");
    printer.register_value("delta_longitude_deg", _delta_longitude_deg, "deg");
    printer.register_value("z_re_ref_point_m", _z_re_ref_point_m, "m");
    printer.register_value("y_re_ref_point_m", _y_re_ref_point_m, "m");
    printer.register_value("x_re_ref_point_m", _x_re_ref_point_m, "m");
    printer.register_value("beam_inc_angle_adj_deg", _beam_inc_angle_adj_deg, "deg");

    printer.register_value("real_time_clean_info", _real_time_clean_info);

    printer.register_value("si_start_range_samples", _si_start_range_samples);
    printer.register_value("si_centre_sample", _si_centre_sample);
    printer.register_value("si_num_samples", _si_num_samples);

    return printer;
}

}
}
}
}
}
