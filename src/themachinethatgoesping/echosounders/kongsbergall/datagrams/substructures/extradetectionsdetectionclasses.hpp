// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/extradetectionsdetectionclasses.doc.hpp"

// std includes
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

/**
 * @brief Extra Detections Detection Classes
 */
class ExtraDetectionsDetectionClasses
{
    uint16_t _start_depth;                ///< % of depth (0-300)
    uint16_t _stop_depth;                 ///< % of depth (1-300)
    uint16_t _qf_threshold_100;           ///< 100 * QF threshold (1-100)
    int16_t  _bs_threshold;               ///< dB (-10 - 60)
    uint16_t _snr_threshold;              ///< 5-15
    uint16_t _alarm_threshold;            ///< number of extra det. required (1-99 0=off)
    uint16_t _number_of_extra_detections; ///<
    bool     _show_class;                 ///< 0-1
    uint8_t
        _alarm_flag_1; ///< 0: (no alarm) 1:Number of extra detections are above Alarm threshold.

  public:
    ExtraDetectionsDetectionClasses()  = default;
    ~ExtraDetectionsDetectionClasses() = default;


    // convenient member access
    uint16_t get_start_depth() const { return _start_depth; }
    uint16_t get_stop_depth() const { return _stop_depth; }
    uint16_t get_qf_threshold_100() const { return _qf_threshold_100; }
    int16_t  get_bs_threshold() const { return _bs_threshold; }
    uint16_t get_snr_threshold() const { return _snr_threshold; }
    uint16_t get_alarm_threshold() const { return _alarm_threshold; }
    uint16_t get_number_of_extra_detections() const { return _number_of_extra_detections; }
    bool     get_show_class() const { return _show_class; }
    uint8_t  get_alarm_flag_1() const { return _alarm_flag_1; }

    void set_start_depth(uint16_t start_depth) { _start_depth = start_depth; }
    void set_stop_depth(uint16_t stop_depth) { _stop_depth = stop_depth; }
    void set_qf_threshold_100(uint16_t qf_threshold_100) { _qf_threshold_100 = qf_threshold_100; }
    void set_bs_threshold(int16_t bs_threshold) { _bs_threshold = bs_threshold; }
    void set_snr_threshold(uint16_t snr_threshold) { _snr_threshold = snr_threshold; }
    void set_alarm_threshold(uint16_t alarm_threshold) { _alarm_threshold = alarm_threshold; }
    void set_number_of_extra_detections(uint16_t number_of_extra_detections)
    {
        _number_of_extra_detections = number_of_extra_detections;
    }
    void set_show_class(bool show_class) { _show_class = show_class; }
    void set_alarm_flag_1(uint8_t alarm_flag_1) { _alarm_flag_1 = alarm_flag_1; }

    // ----- processed member access -----
    /**
     * @brief Get the ifremer QF threshold
     * The Ifremer Quality factor is used to estimate the relative depth error.
     * QF threshold equal to 0.1 means a 0.1% depth error threshold. At 100 m depth this
     * the depth error threshold would be 10 cm. Valid range is 0.01 to 1 %.
     *
     * @return qf_threshold_100 * 0.01 (double)
     */
    double get_qf_threshold() const { return _qf_threshold_100 * 0.01; }

    // ----- operators -----
    bool operator==(const ExtraDetectionsDetectionClasses& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("ExtraDetectionsDetectionClasses",
                                                  float_precision, superscript_exponents);

        printer.register_value("start_depth", _start_depth, "%");
        printer.register_value("stopt_depth", _stop_depth, "%");
        printer.register_value("qf_threshold_100", _qf_threshold_100, "1-100");
        printer.register_value("bs_threshold", _bs_threshold, "dB");
        printer.register_value("snr_threshold", _snr_threshold, "5-15");
        printer.register_value("alarm_threshold", _alarm_threshold);
        printer.register_value("number_of_extra_detections", _number_of_extra_detections);
        printer.register_value("show_class", _show_class);
        printer.register_value("alarm_flag_1", _alarm_flag_1);

        printer.register_section("Processed");
        printer.register_value("IFREMER QF Threshold", get_qf_threshold(), "0.01 - 1");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
