// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "extradetectionsextradetectionscontainer.hpp"

#include <fmt/core.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

const std::vector<ExtraDetectionsExtraDetections>&
ExtraDetectionsExtraDetectionsContainer::get_extra_detections() const
{
    return _extra_detections;
}

std::vector<ExtraDetectionsExtraDetections>&
ExtraDetectionsExtraDetectionsContainer::extra_detections()
{
    return _extra_detections;
}

void ExtraDetectionsExtraDetectionsContainer::set_extra_detections(
    const std::vector<ExtraDetectionsExtraDetections>& detections)
{
    _extra_detections = detections;
}

#define _ED_ED_GETTER(NAME, TYPE)                                                                  \
    xt::xtensor<TYPE, 1> ExtraDetectionsExtraDetectionsContainer::get_##NAME##_tensor(             \
        const std::vector<uint32_t>& indices) const                                                \
    {                                                                                              \
        return build_tensor<TYPE>(                                                                 \
            [](const ExtraDetectionsExtraDetections& d) { return d.get_##NAME(); }, indices);      \
    }

_ED_ED_GETTER(depth, float)
_ED_ED_GETTER(across, float)
_ED_ED_GETTER(along, float)
_ED_ED_GETTER(delta_latitude, float)
_ED_ED_GETTER(delta_longitude, float)
_ED_ED_GETTER(beam_crosstrack_angle, float)
_ED_ED_GETTER(applied_pointing_angle_correction, float)
_ED_ED_GETTER(two_way_travel_time, float)
_ED_ED_GETTER(applied_two_way_travel_time_corrections, float)
_ED_ED_GETTER(backscatter, int16_t)
_ED_ED_GETTER(beam_incidence_angle_adjustment, int8_t)
_ED_ED_GETTER(detection_info, uint8_t)
_ED_ED_GETTER(spare, uint16_t)
_ED_ED_GETTER(tx_sector_number, uint16_t)
_ED_ED_GETTER(detection_window_length, uint16_t)
_ED_ED_GETTER(quality_factor_old, uint16_t)
_ED_ED_GETTER(real_time_cleaning_info, uint16_t)
_ED_ED_GETTER(range_factor, uint16_t)
_ED_ED_GETTER(detection_class_number, uint16_t)
_ED_ED_GETTER(confidence_level, uint16_t)
_ED_ED_GETTER(qf_10, uint16_t)
_ED_ED_GETTER(water_column_beam_number, uint16_t)
_ED_ED_GETTER(beam_angle_across, float)
_ED_ED_GETTER(detected_range, uint16_t)
_ED_ED_GETTER(number_of_raw_amplitude_samples, uint16_t)
_ED_ED_GETTER(qf_threshold, double)
_ED_ED_GETTER(backscatter_in_db, double)

#undef _ED_ED_GETTER

xt::xtensor<uint8_t, 1> ExtraDetectionsExtraDetectionsContainer::get_detection_is_valid_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<uint8_t>(
        [](const ExtraDetectionsExtraDetections& d) {
            return static_cast<uint8_t>(d.get_detection_is_valid());
        },
        indices);
}

xt::xtensor<uint8_t, 1> ExtraDetectionsExtraDetectionsContainer::get_detection_type_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<uint8_t>(
        [](const ExtraDetectionsExtraDetections& d) {
            return static_cast<uint8_t>(d.get_detection_type());
        },
        indices);
}

xt::xtensor<uint8_t, 1>
ExtraDetectionsExtraDetectionsContainer::get_backscatter_is_compensated_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<uint8_t>(
        [](const ExtraDetectionsExtraDetections& d) {
            return static_cast<uint8_t>(d.get_backscatter_is_compensated());
        },
        indices);
}

size_t ExtraDetectionsExtraDetectionsContainer::get_number_of_extra_detections() const
{
    return _extra_detections.size();
}

tools::classhelper::ObjectPrinter ExtraDetectionsExtraDetectionsContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "ExtraDetectionsExtraDetectionsContainer", float_precision, superscript_exponents);

    printer.register_section("ExtraDetections (.extra_detections)");
    printer.register_value("extra_detections (vector)",
                           fmt::format("size={}", get_number_of_extra_detections()),
                           "detections");

    printer.register_container("depth", get_depth_tensor(), "m");
    printer.register_container("across", get_across_tensor(), "m");
    printer.register_container("along", get_along_tensor(), "m");
    printer.register_container("delta_latitude", get_delta_latitude_tensor(), "deg");
    printer.register_container("delta_longitude", get_delta_longitude_tensor(), "deg");
    printer.register_container(
        "beam_crosstrack_angle", get_beam_crosstrack_angle_tensor(), "deg");
    printer.register_container("applied_pointing_angle_correction",
                               get_applied_pointing_angle_correction_tensor(),
                               "deg");
    printer.register_container("two_way_travel_time", get_two_way_travel_time_tensor(), "s");
    printer.register_container("applied_two_way_travel_time_corrections",
                               get_applied_two_way_travel_time_corrections_tensor(),
                               "s");
    printer.register_container("backscatter", get_backscatter_tensor());
    printer.register_container("beam_incidence_angle_adjustment",
                               get_beam_incidence_angle_adjustment_tensor());
    printer.register_container("detection_info", get_detection_info_tensor());
    printer.register_container("spare", get_spare_tensor());
    printer.register_container("tx_sector_number", get_tx_sector_number_tensor());
    printer.register_container("detection_window_length",
                               get_detection_window_length_tensor());
    printer.register_container("quality_factor_old", get_quality_factor_old_tensor());
    printer.register_container("real_time_cleaning_info", get_real_time_cleaning_info_tensor());
    printer.register_container("range_factor", get_range_factor_tensor());
    printer.register_container("detection_class_number", get_detection_class_number_tensor());
    printer.register_container("confidence_level", get_confidence_level_tensor());
    printer.register_container("qf_10", get_qf_10_tensor());
    printer.register_container("water_column_beam_number",
                               get_water_column_beam_number_tensor());
    printer.register_container("beam_angle_across", get_beam_angle_across_tensor(), "deg");
    printer.register_container("detected_range", get_detected_range_tensor());
    printer.register_container("number_of_raw_amplitude_samples",
                               get_number_of_raw_amplitude_samples_tensor());

    printer.register_section("processed");
    printer.register_value("number_of_extra_detections", get_number_of_extra_detections());
    printer.register_container("qf_threshold", get_qf_threshold_tensor());
    printer.register_container("backscatter_in_db", get_backscatter_in_db_tensor(), "dB");
    printer.register_container("detection_is_valid", get_detection_is_valid_tensor());
    printer.register_container("detection_type", get_detection_type_tensor());
    printer.register_container("backscatter_is_compensated",
                               get_backscatter_is_compensated_tensor());

    return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
