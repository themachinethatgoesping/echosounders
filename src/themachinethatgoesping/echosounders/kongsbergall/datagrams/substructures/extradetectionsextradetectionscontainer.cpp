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
    printer.register_value("number_of_extra_detections", _extra_detections.size());
    return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
