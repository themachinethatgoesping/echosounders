// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/rawrangeandanglebeam.doc.hpp"

// std includes
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



#include "flag_detection_information.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

/**
 * @brief The beam data are given re the transmit transducer or sonar head depth and the horizontal
 * location (x,y) of the active positioning system's reference point. Heave, roll, pitch, sound
 * speed at the transducer depth and ray bending through the water column have been applied.
 *
 */
class RawRangeAndAngleBeam
{
    int16_t  _beam_crosstrack_angle; /// M relative RX array in 0.01°
    uint8_t  _transmit_sector_number;
    uint8_t  _detection_info;
    uint16_t _detection_window_length_in_samples;
    uint8_t  _quality_factor;
    int8_t   _d_corr;
    float    _two_way_travel_time; ///< in s
    int16_t  _reflectivity;        ///< in 0.1 dB resolution
    int8_t   _realtime_cleaning_info;
    uint8_t  _spare;

  public:
    RawRangeAndAngleBeam()  = default;
    ~RawRangeAndAngleBeam() = default;

    // ----- convenient member access -----
    // get
    int16_t  get_beam_crosstrack_angle() const;
    uint8_t  get_transmit_sector_number() const;
    uint8_t  get_detection_info() const;
    uint16_t get_detection_window_length_in_samples() const;
    uint8_t  get_quality_factor() const;
    int8_t   get_d_corr() const;
    float    get_two_way_travel_time() const;
    int16_t  get_reflectivity() const;
    int8_t   get_realtime_cleaning_info() const;
    uint8_t  get_spare() const;

    // set
    void set_beam_crosstrack_angle(int16_t beam_crosstrack_angle);
    void set_transmit_sector_number(uint8_t transmit_sector_number);
    void set_detection_info(uint8_t detection_info);
    void set_detection_window_length_in_samples(uint16_t detection_window_length_in_samples);
    void set_quality_factor(uint8_t quality_factor);
    void set_d_corr(int8_t d_corr);
    void set_two_way_travel_time(float two_way_travel_time);
    void set_reflectivity(int16_t reflectivity);
    void set_realtime_cleaning_info(int8_t realtime_cleaning_info);
    void set_spare(uint8_t spare);

    // ----- processed member access -----
    /**
     * @brief Get the beam crosstrack angle in °
     *
     * @return _beam_crosstrack_angle * 0.01 (float)
     */
    float get_beam_crosstrack_angle_in_degrees() const;

    /**
     * @brief Get the reflectivity in db
     *
     * @return _reflectivity * 0.1 (float)
     */
    float get_reflectivity_in_db() const;

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
    bool operator==(const RawRangeAndAngleBeam& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter
    __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
