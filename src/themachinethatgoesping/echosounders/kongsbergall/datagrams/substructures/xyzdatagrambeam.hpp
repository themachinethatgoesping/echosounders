// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/xyzdatagrambeam.doc.hpp"

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
 * @brief The beam data are given re the transmit transducer or sonar head depth and the horizontal
 * location (x,y) of the active positioning system's reference point. Heave, roll, pitch, sound
 * speed at the transducer depth and ray bending through the water column have been applied.
 *
 */
class XYZDatagramBeam
{
    float    _depth;                   ///< (Z) from transmit transducer in meter
    float    _acrosstrack_distance;    ///< distance (y) in meter
    float    _alongtrack_distance;     ///< distance (x) in meter
    uint16_t _detection_window_length; ///< in samples
    uint8_t  _quality_factor; ///< 0-254 Scaled standard deviation (sd) of the range detection
                              ///< divided by the detected range (dr) (qf = 250*sd/sr)
    int8_t  _beam_incidence_angle_adjustment; ///< (IBA) in 0.1 degree
    uint8_t _detection_info; ///< Flag that indicates the type and validity of detection
    int8_t  _realtime_cleaning_information; ///< Flag that indicates if the beam was flagged by real
                                            ///< time cleaning (negative values indicate that this
                                            ///< beam is flagged out)
    int16_t _reflectivity;                  // Backscatter (BS) in 0.1 dB resolution

  public:
    XYZDatagramBeam()  = default;
    ~XYZDatagramBeam() = default;

    // convenient member access
    float    get_depth() const;
    float    get_acrosstrack_distance() const;
    float    get_alongtrack_distance() const;
    uint16_t get_detection_window_length() const;
    uint8_t  get_quality_factor() const;
    int8_t  get_beam_incidence_angle_adjustment() const;
    uint8_t get_detection_info() const;
    int8_t  get_realtime_cleaning_information() const;
    int16_t get_reflectivity() const;

    void set_depth(float depth);
    void set_acrosstrack_distance(float acrosstrack_distance);
    void set_alongtrack_distance(float alongtrack_distance);
    void set_detection_window_length(uint16_t detection_window_length);
    void set_quality_factor(uint8_t quality_factor);
    void set_beam_incidence_angle_adjustment(double beam_incidence_angle_adjustment);
    void set_detection_info(uint8_t detection_info);
    void set_realtime_cleaning_information(int8_t realtime_cleaning_information);
    void set_reflectivity(int16_t reflectivity);

    // ----- processed member access -----
    /**
     * @brief convert reflectivity to backscatter
     * (_reflectivity * 0.1 dB)
     *
     * @return double
     */
    double get_backscatter() const;

    /**
     * @brief Returns the beam incidence angle adjustment in degrees. (IBA * 0.1 degree)
     *
     * @return double
     */
    double get_beam_incidence_angle_adjustment_in_degrees() const;

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
    bool operator==(const XYZDatagramBeam& other) const;
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
