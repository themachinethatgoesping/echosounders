// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/xyzdatagrambeam.doc.hpp"

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
    float    get_depth() const { return _depth; }
    float    get_acrosstrack_distance() const { return _acrosstrack_distance; }
    float    get_alongtrack_distance() const { return _alongtrack_distance; }
    uint16_t get_detection_window_length() const { return _detection_window_length; }
    uint8_t  get_quality_factor() const { return _quality_factor; }
    int8_t  get_beam_incidence_angle_adjustment() const { return _beam_incidence_angle_adjustment; }
    uint8_t get_detection_info() const { return _detection_info; }
    int8_t  get_realtime_cleaning_information() const { return _realtime_cleaning_information; }
    int16_t get_reflectivity() const { return _reflectivity; }

    void set_depth(float depth) { _depth = depth; }
    void set_acrosstrack_distance(float acrosstrack_distance)
    {
        _acrosstrack_distance = acrosstrack_distance;
    }
    void set_alongtrack_distance(float alongtrack_distance)
    {
        _alongtrack_distance = alongtrack_distance;
    }
    void set_detection_window_length(uint16_t detection_window_length)
    {
        _detection_window_length = detection_window_length;
    }
    void set_quality_factor(uint8_t quality_factor) { _quality_factor = quality_factor; }
    void set_beam_incidence_angle_adjustment(double beam_incidence_angle_adjustment)
    {
        _beam_incidence_angle_adjustment = beam_incidence_angle_adjustment;
    }
    void set_detection_info(uint8_t detection_info) { _detection_info = detection_info; }
    void set_realtime_cleaning_information(int8_t realtime_cleaning_information)
    {
        _realtime_cleaning_information = realtime_cleaning_information;
    }
    void set_reflectivity(int16_t reflectivity) { _reflectivity = reflectivity; }

    // ----- processed member access -----
    /**
     * @brief convert reflectivity to backscatter
     * (_reflectivity * 0.1 dB)
     *
     * @return double
     */
    double get_backscatter() const { return _reflectivity * 0.1; }

    /**
     * @brief Returns the beam incidence angle adjustment in degrees. (IBA * 0.1 degree)
     *
     * @return double
     */
    double get_beam_incidence_angle_adjustment_in_degrees() const
    {
        return _beam_incidence_angle_adjustment * 0.1;
    }

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
    bool operator==(const XYZDatagramBeam& other) const
    {
        return tools::helper::float_equals(_depth, other._depth) &&
               tools::helper::float_equals(_acrosstrack_distance, other._acrosstrack_distance) &&
               tools::helper::float_equals(_alongtrack_distance, other._alongtrack_distance) &&
               _detection_window_length == other._detection_window_length &&
               _quality_factor == other._quality_factor &&
               _beam_incidence_angle_adjustment == other._beam_incidence_angle_adjustment &&
               _detection_info == other._detection_info &&
               _realtime_cleaning_information == other._realtime_cleaning_information &&
               _reflectivity == other._reflectivity;
    }
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "XYZDatagramBeam", float_precision, superscript_exponents);

        // raw values
        printer.register_value("depth", _depth, "-z in m");
        printer.register_value("acrosstrack_distance", _acrosstrack_distance, "y in m");
        printer.register_value("alongtrack_distance", _alongtrack_distance, "x in m");
        printer.register_value("detection_window_length", _detection_window_length, "in samples");
        printer.register_value("quality_factor", _quality_factor);
        printer.register_value(
            "beam_incidence_angle_adjustment", _beam_incidence_angle_adjustment, "0.1°");
        printer.register_string("detection_info", fmt::format("0x{:08b}", _detection_info));
        printer.register_value("realtime_cleaning_information", _realtime_cleaning_information);
        printer.register_value("reflectivity", _reflectivity, "0.1 dB");

        // processed values
        printer.register_section("processed");
        printer.register_value("beam_incidence_angle_adjustment",
                               get_beam_incidence_angle_adjustment_in_degrees(),
                               "°");
        printer.register_value("detection_is_valid", get_detection_is_valid());
        printer.register_enum("detection_type", get_detection_type());
        printer.register_value("backscatter_is_compensated", get_backscatter_is_compensated());
        printer.register_value("reflectivity", get_backscatter(), "dB");

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
