// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/extradetectionsextradetections.doc.hpp"

// std includes
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

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
    float get_depth() const;
    float get_across() const;
    float get_along() const;
    float get_delta_latitude() const;
    float get_delta_longitude() const;
    float get_beam_crosstrack_angle() const;
    float get_applied_pointing_angle_correction() const;
    float get_two_way_travel_time() const;
    float get_applied_two_way_travel_time_corrections() const;
    int16_t get_backscatter() const;
    int8_t get_beam_incidence_angle_adjustment() const;
    uint8_t get_detection_info() const;
    uint16_t get_spare() const;
    uint16_t get_tx_sector_number() const;
    uint16_t get_detection_window_length() const;
    uint16_t get_quality_factor_old() const;
    uint16_t get_real_time_cleaning_info() const;
    uint16_t get_range_factor() const;
    uint16_t get_detection_class_number() const;
    uint16_t get_confidence_level() const;
    uint16_t get_qf_10() const;
    uint16_t get_water_column_beam_number() const;
    float    get_beam_angle_across() const;
    uint16_t get_detected_range() const;
    uint16_t get_number_of_raw_amplitude_samples() const;

    void set_depth(float depth);
    void set_across(float across);
    void set_along(float along);
    void set_delta_latitude(float delta_latitude);
    void set_delta_longitude(float delta_longitude);
    void set_beam_crosstrack_angle(float beam_crosstrack_angle);
    void set_applied_pointing_angle_correction(float applied_pointing_angle_correction);
    void set_two_way_travel_time(float two_way_travel_time);
    void set_applied_two_way_travel_time_corrections(float applied_two_way_travel_time_corrections);
    void set_backscatter(int16_t backscatter);
    void set_beam_incidence_angle_adjustment(int8_t beam_incidence_angle_adjustment);
    void set_detection_info(uint8_t detection_info);
    void set_spare(uint16_t spare);
    void set_tx_sector_number(uint16_t tx_sector_number);
    void set_detection_window_length(uint16_t detection_window_length);
    void set_quality_factor_old(uint16_t quality_factor_old);
    void set_real_time_cleaning_info(uint16_t real_time_cleaning_info);
    void set_range_factor(uint16_t range_factor);
    void set_detection_class_number(uint16_t detection_class_number);
    void set_confidence_level(uint16_t confidence_level);
    void set_qf_10(uint16_t qf_10);
    void set_water_column_beam_number(uint16_t water_column_beam_number);
    void set_beam_angle_across(float beam_angle_across);
    void set_detected_range(uint16_t detected_range);
    void set_number_of_raw_amplitude_samples(uint16_t raw_amplitude_samples);

    // ----- processed member access -----
    /**
     * @brief Get the ifremer QF threshold
     *
     * @return qf_threshold_10 * 0.1 (double)
     */
    double get_qf_threshold() const;

    /**
     * @brief Get the backscatter in dB
     *
     * @return _backscatter * 0.1 dB (double)
     */
    double get_backscatter_in_db() const;

    /**
     * @brief This function evaluates the detection information flag. If the last bit is set to 1,
     * the detection is valid. If the last bit is set to 0, the detection is invalid.
     *
     * @return true
     * @return false
     */
    bool get_detection_is_valid() const;

    /**
     * @brief This function evaluates the detection information flag. The first 3 bits indicate the
     * type of detection.
     *
     * @return t_DetectionType
     */
    detection_information::o_DetectionType get_detection_type() const;

    /**
     * @brief This function evaluates the detection information flag. If the 4th bit is set to 1,
     * the detection is compensated for beam incident angle. If the 4th bit is set to 0, the
     * detection is not compensated for beam incident angle.
     *
     * @return true
     * @return false
     */
    bool get_backscatter_is_compensated() const;

    // ----- operators -----
    bool operator==(const ExtraDetectionsExtraDetections& other) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
