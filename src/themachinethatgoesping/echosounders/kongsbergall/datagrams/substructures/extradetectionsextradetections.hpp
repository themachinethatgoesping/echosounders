// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/extradetectionsextradetections.doc.hpp"

// std includes
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/helper/floatcompare.hpp>

#include "../../types.hpp"
#include "flag_detection_information.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

/**
 * @brief Extra Detections in the extra detections datagram
 */
class ExtraDetectionsExtraDetections
{
    float    _depth;                                   ///< z in m
    float    _across;                                  ///< y in m
    float    _along;                                   ///< x in m
    float    _delta_latitude;                          ///< °
    float    _delta_longitude;                         ///< °
    float    _beam_crosstrack_angle;                   ///< deg. re array
    float    _applied_pointing_angle_correction;       ///<
    float    _two_way_travel_time;                     ///< s
    float    _applied_two_way_travel_time_corrections; ///< seconds, f.ex. Doppler correction
    int16_t  _backscatter;                             ///< 0.1 dB
    int8_t   _beam_incidence_angle_adjustment;         ///< IBA in 0.1°
    uint8_t  _detection_info;
    uint16_t _spare;
    uint16_t _tx_sector_number;                ///< or TX array index
    uint16_t _detection_window_length;         ///<
    uint16_t _quality_factor_old;              ///<
    uint16_t _real_time_cleaning_info;         ///<
    uint16_t _range_factor;                    ///< in %
    uint16_t _detection_class_number;          ///<
    uint16_t _confidence_level;                ///<
    uint16_t _qf_10;                           ///< Ifremer Quality factor * 10
    uint16_t _water_column_beam_number;        ///<
    float    _beam_angle_across;               ///< re vertical °
    uint16_t _detected_range;                  ///< in (WCsr) samples
    uint16_t _number_of_raw_amplitude_samples; ///< NS

  public:
    ExtraDetectionsExtraDetections()  = default;
    ~ExtraDetectionsExtraDetections() = default;

    // convenient member access
    float get_depth() const { return _depth; }
    float get_across() const { return _across; }
    float get_along() const { return _along; }
    float get_delta_latitude() const { return _delta_latitude; }
    float get_delta_longitude() const { return _delta_longitude; }
    float get_beam_crosstrack_angle() const { return _beam_crosstrack_angle; }
    float get_applied_pointing_angle_correction() const
    {
        return _applied_pointing_angle_correction;
    }
    float get_two_way_travel_time() const { return _two_way_travel_time; }
    float get_applied_two_way_travel_time_corrections() const
    {
        return _applied_two_way_travel_time_corrections;
    }
    int16_t get_backscatter() const { return _backscatter; }
    int8_t  get_beam_incidence_angle_adjustment() const { return _beam_incidence_angle_adjustment; }
    uint8_t get_detection_info() const { return _detection_info; }
    uint16_t get_spare() const { return _spare; }
    uint16_t get_tx_sector_number() const { return _tx_sector_number; }
    uint16_t get_detection_window_length() const { return _detection_window_length; }
    uint16_t get_quality_factor_old() const { return _quality_factor_old; }
    uint16_t get_real_time_cleaning_info() const { return _real_time_cleaning_info; }
    uint16_t get_range_factor() const { return _range_factor; }
    uint16_t get_detection_class_number() const { return _detection_class_number; }
    uint16_t get_confidence_level() const { return _confidence_level; }
    uint16_t get_qf_10() const { return _qf_10; }
    uint16_t get_water_column_beam_number() const { return _water_column_beam_number; }
    float    get_beam_angle_across() const { return _beam_angle_across; }
    uint16_t get_detected_range() const { return _detected_range; }
    uint16_t get_number_of_raw_amplitude_samples() const
    {
        return _number_of_raw_amplitude_samples;
    }

    void set_depth(float depth) { _depth = depth; }
    void set_across(float across) { _across = across; }
    void set_along(float along) { _along = along; }
    void set_delta_latitude(float delta_latitude) { _delta_latitude = delta_latitude; }
    void set_delta_longitude(float delta_longitude) { _delta_longitude = delta_longitude; }
    void set_beam_crosstrack_angle(float beam_crosstrack_angle)
    {
        _beam_crosstrack_angle = beam_crosstrack_angle;
    }
    void set_applied_pointing_angle_correction(float applied_pointing_angle_correction)
    {
        _applied_pointing_angle_correction = applied_pointing_angle_correction;
    }
    void set_two_way_travel_time(float two_way_travel_time)
    {
        _two_way_travel_time = two_way_travel_time;
    }
    void set_applied_two_way_travel_time_corrections(float applied_two_way_travel_time_corrections)
    {
        _applied_two_way_travel_time_corrections = applied_two_way_travel_time_corrections;
    }
    void set_backscatter(int16_t backscatter) { _backscatter = backscatter; }
    void set_beam_incidence_angle_adjustment(int8_t beam_incidence_angle_adjustment)
    {
        _beam_incidence_angle_adjustment = beam_incidence_angle_adjustment;
    }
    void set_detection_info(uint8_t detection_info) { _detection_info = detection_info; }
    void set_spare(uint16_t spare) { _spare = spare; }
    void set_tx_sector_number(uint16_t tx_sector_number) { _tx_sector_number = tx_sector_number; }
    void set_detection_window_length(uint16_t detection_window_length)
    {
        _detection_window_length = detection_window_length;
    }
    void set_quality_factor_old(uint16_t quality_factor_old)
    {
        _quality_factor_old = quality_factor_old;
    }
    void set_real_time_cleaning_info(uint16_t real_time_cleaning_info)
    {
        _real_time_cleaning_info = real_time_cleaning_info;
    }
    void set_range_factor(uint16_t range_factor) { _range_factor = range_factor; }
    void set_detection_class_number(uint16_t detection_class_number)
    {
        _detection_class_number = detection_class_number;
    }
    void set_confidence_level(uint16_t confidence_level) { _confidence_level = confidence_level; }
    void set_qf_10(uint16_t qf_10) { _qf_10 = qf_10; }
    void set_water_column_beam_number(uint16_t water_column_beam_number)
    {
        _water_column_beam_number = water_column_beam_number;
    }
    void set_beam_angle_across(float beam_angle_across) { _beam_angle_across = beam_angle_across; }
    void set_detected_range(uint16_t detected_range) { _detected_range = detected_range; }
    void set_number_of_raw_amplitude_samples(uint16_t raw_amplitude_samples)
    {
        _number_of_raw_amplitude_samples = raw_amplitude_samples;
    }

    // ----- processed member access -----
    /**
     * @brief Get the ifremer QF threshold
     *
     * @return qf_threshold_10 * 0.1 (double)
     */
    double get_qf_threshold() const { return _qf_10 * 0.1; }

    /**
     * @brief Get the backscatter in dB
     *
     * @return _backscatter * 0.1 dB (double)
     */
    double get_backscatter_in_db() const { return _backscatter * 0.1; }

    /**
     * @brief This function evaluates the detection information flag. If the last bit is set to 1,
     * the detection is valid. If the last bit is set to 0, the detection is invalid.
     *
     * @return true
     * @return false
     */
    bool get_detection_is_valid() const
    {
        return detection_information::get_detection_is_valid(_detection_info);
    }

    /**
     * @brief This function evaluates the detection information flag. The first 3 bits indicate the
     * type of detection.
     *
     * @return t_DetectionType
     */
    detection_information::t_DetectionType get_detection_type() const
    {
        return detection_information::get_detection_type(_detection_info);
    }

    /**
     * @brief This function evaluates the detection information flag. If the 4th bit is set to 1,
     * the detection is compensated for beam incident angle. If the 4th bit is set to 0, the
     * detection is not compensated for beam incident angle.
     *
     * @return true
     * @return false
     */
    bool get_backscatter_is_compensated() const
    {
        return detection_information::get_backscatter_is_compensated(_detection_info);
    }

    // ----- operators -----
    bool operator==(const ExtraDetectionsExtraDetections& other) const
    {
        return tools::helper::float_equals(_depth, other._depth) &&
               tools::helper::float_equals(_across, other._across) &&
               tools::helper::float_equals(_along, other._along) &&
               tools::helper::float_equals(_delta_latitude, other._delta_latitude) &&
               tools::helper::float_equals(_delta_longitude, other._delta_longitude) &&
               tools::helper::float_equals(_beam_crosstrack_angle, other._beam_crosstrack_angle) &&
               tools::helper::float_equals(_applied_pointing_angle_correction,
                                           other._applied_pointing_angle_correction) &&
               tools::helper::float_equals(_two_way_travel_time, other._two_way_travel_time) &&
               tools::helper::float_equals(_applied_two_way_travel_time_corrections,
                                           other._applied_two_way_travel_time_corrections) &&
               _backscatter == other._backscatter &&
               _beam_incidence_angle_adjustment == other._beam_incidence_angle_adjustment &&
               _detection_info == other._detection_info && _spare == other._spare &&
               _tx_sector_number == other._tx_sector_number &&
               _detection_window_length == other._detection_window_length &&
               _quality_factor_old == other._quality_factor_old &&
               _real_time_cleaning_info == other._real_time_cleaning_info &&
               _range_factor == other._range_factor &&
               _detection_class_number == other._detection_class_number &&
               _confidence_level == other._confidence_level && _qf_10 == other._qf_10 &&
               _water_column_beam_number == other._water_column_beam_number &&
               tools::helper::float_equals(_beam_angle_across, other._beam_angle_across) &&
               _detected_range == other._detected_range &&
               _number_of_raw_amplitude_samples == other._number_of_raw_amplitude_samples;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "ExtraDetectionsExtraDetections", float_precision, superscript_exponents);
        //
        printer.register_section("Content");
        printer.register_value("depth", _depth, "z in m");
        printer.register_value("across", _across, "y in m");
        printer.register_value("along", _along, "x in m");
        printer.register_value("delta_latitude", _delta_latitude, "°");
        printer.register_value("delta_longitude", _delta_longitude, "°");
        printer.register_value("beam_crosstrack_angle", _beam_crosstrack_angle, "deg. re array");
        printer.register_value("applied_pointing_angle_correction",
                               _applied_pointing_angle_correction);
        printer.register_value("two_way_travel_time", _two_way_travel_time, "s");
        printer.register_value("applied_two_way_travel_time_corrections",
                               _applied_two_way_travel_time_corrections);
        printer.register_value("backscatter", _backscatter, "0.1 dB");
        printer.register_value(
            "beam_incidence_angle_adjustment", _beam_incidence_angle_adjustment, "0.1°");
        printer.register_value("detection_info", _detection_info);
        printer.register_value("spare", _spare);
        printer.register_value("tx_sector_number", _tx_sector_number, "Or TX array index");
        printer.register_value("detection_window_length", _detection_window_length);
        printer.register_value("quality_factor_old", _quality_factor_old);
        printer.register_value("real_time_cleaning_info", _real_time_cleaning_info);
        printer.register_value("range_factor", _range_factor, "%");
        printer.register_value("detection_class_number", _detection_class_number);
        printer.register_value("qf_10", _qf_10);
        printer.register_value("water_column_beam_number", _water_column_beam_number);
        printer.register_value("beam_angle_across", _beam_angle_across, "re vertical °");
        printer.register_value("detected_range", _detected_range, "samples");
        printer.register_value("number_of_raw_amplitude_samples", _number_of_raw_amplitude_samples);

        // processed
        printer.register_section("Processed");
        printer.register_value("ifremer qf threshold", get_qf_threshold(), "0.01 - 1");
        printer.register_value("backscatter", get_backscatter_in_db(), "dB");
        printer.register_value("detection_is_valid", get_detection_is_valid());
        printer.register_enum("detection_type", get_detection_type());
        printer.register_value("backscatter_is_compensated", get_backscatter_is_compensated());

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
