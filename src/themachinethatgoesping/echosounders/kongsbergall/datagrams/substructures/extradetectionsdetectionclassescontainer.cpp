// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "extradetectionsdetectionclassescontainer.hpp"

#include <fmt/core.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

const std::vector<ExtraDetectionsDetectionClasses>&
ExtraDetectionsDetectionClassesContainer::get_detection_classes() const
{
    return _detection_classes;
}

std::vector<ExtraDetectionsDetectionClasses>&
ExtraDetectionsDetectionClassesContainer::detection_classes()
{
    return _detection_classes;
}

void ExtraDetectionsDetectionClassesContainer::set_detection_classes(
    const std::vector<ExtraDetectionsDetectionClasses>& classes)
{
    _detection_classes = classes;
}

#define _ED_DC_GETTER(NAME, TYPE)                                                                  \
    xt::xtensor<TYPE, 1> ExtraDetectionsDetectionClassesContainer::get_##NAME##_tensor(            \
        const std::vector<uint32_t>& indices) const                                                \
    {                                                                                              \
        return build_tensor<TYPE>(                                                                 \
            [](const ExtraDetectionsDetectionClasses& c) { return c.get_##NAME(); }, indices);     \
    }

_ED_DC_GETTER(start_depth, uint16_t)
_ED_DC_GETTER(stop_depth, uint16_t)
_ED_DC_GETTER(qf_threshold_100, uint16_t)
_ED_DC_GETTER(bs_threshold, int16_t)
_ED_DC_GETTER(snr_threshold, uint16_t)
_ED_DC_GETTER(alarm_threshold, uint16_t)
_ED_DC_GETTER(number_of_extra_detections, uint16_t)
_ED_DC_GETTER(alarm_flag_1, uint8_t)
_ED_DC_GETTER(qf_threshold, double)

#undef _ED_DC_GETTER

xt::xtensor<uint8_t, 1> ExtraDetectionsDetectionClassesContainer::get_show_class_tensor(
    const std::vector<uint32_t>& indices) const
{
    return build_tensor<uint8_t>(
        [](const ExtraDetectionsDetectionClasses& c) {
            return static_cast<uint8_t>(c.get_show_class());
        },
        indices);
}

size_t ExtraDetectionsDetectionClassesContainer::get_number_of_detection_classes() const
{
    return _detection_classes.size();
}

tools::classhelper::ObjectPrinter ExtraDetectionsDetectionClassesContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "ExtraDetectionsDetectionClassesContainer", float_precision, superscript_exponents);

    printer.register_section("DetectionClasses (.detection_classes)");
    printer.register_value("detection_classes (vector)",
                           fmt::format("size={}", get_number_of_detection_classes()),
                           "classes");

    printer.register_container("start_depth", get_start_depth_tensor());
    printer.register_container("stop_depth", get_stop_depth_tensor());
    printer.register_container("qf_threshold_100", get_qf_threshold_100_tensor());
    printer.register_container("bs_threshold", get_bs_threshold_tensor());
    printer.register_container("snr_threshold", get_snr_threshold_tensor());
    printer.register_container("alarm_threshold", get_alarm_threshold_tensor());
    printer.register_container("number_of_extra_detections",
                               get_number_of_extra_detections_tensor());
    printer.register_container("show_class", get_show_class_tensor());
    printer.register_container("alarm_flag_1", get_alarm_flag_1_tensor());

    printer.register_section("processed");
    printer.register_value("number_of_detection_classes", get_number_of_detection_classes());
    printer.register_container("qf_threshold", get_qf_threshold_tensor());

    return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
