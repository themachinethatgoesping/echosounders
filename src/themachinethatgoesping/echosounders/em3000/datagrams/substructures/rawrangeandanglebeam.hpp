// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/rawrangeandanglebeam.doc.hpp"

// std includes
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../../em3000_types.hpp"

#include "flag_detection_information.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
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
    int16_t  _beam_pointing_angle; /// M relative RX array in 0.01°
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
    int16_t  get_beam_pointing_angle() const { return _beam_pointing_angle; }
    uint8_t  get_transmit_sector_number() const { return _transmit_sector_number; }
    uint8_t  get_detection_info() const { return _detection_info; }
    uint16_t get_detection_window_length_in_samples() const
    {
        return _detection_window_length_in_samples;
    }
    uint8_t get_quality_factor() const { return _quality_factor; }
    int8_t  get_d_corr() const { return _d_corr; }
    float   get_two_way_travel_time() const { return _two_way_travel_time; }
    int16_t get_reflectivity() const { return _reflectivity; }
    int8_t  get_realtime_cleaning_info() const { return _realtime_cleaning_info; }
    uint8_t get_spare() const { return _spare; }

    // set
    void set_beam_pointing_angle(int16_t beam_pointing_angle)
    {
        _beam_pointing_angle = beam_pointing_angle;
    }
    void set_transmit_sector_number(uint8_t transmit_sector_number)
    {
        _transmit_sector_number = transmit_sector_number;
    }
    void set_detection_info(uint8_t detection_info) { _detection_info = detection_info; }
    void set_detection_window_length_in_samples(uint16_t detection_window_length_in_samples)
    {
        _detection_window_length_in_samples = detection_window_length_in_samples;
    }
    void set_quality_factor(uint8_t quality_factor) { _quality_factor = quality_factor; }
    void set_d_corr(int8_t d_corr) { _d_corr = d_corr; }
    void set_two_way_travel_time(float two_way_travel_time)
    {
        _two_way_travel_time = two_way_travel_time;
    }
    void set_reflectivity(int16_t reflectivity) { _reflectivity = reflectivity; }
    void set_realtime_cleaning_info(int8_t realtime_cleaning_info)
    {
        _realtime_cleaning_info = realtime_cleaning_info;
    }
    void set_spare(uint8_t spare) { _spare = spare; }

    // ----- processed member access -----
    /**
     * @brief Get the beam pointing angle in °
     *
     * @return _beam_pointing_angle * 0.01 (float)
     */
    float get_beam_pointing_angle_in_degrees() const { return _beam_pointing_angle * 0.01; }

    /**
     * @brief Get the reflectivity in db
     *
     * @return _reflectivity * 0.1 (float)
     */
    float get_reflectivity_in_db() const { return _reflectivity * 0.1; }

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
    bool operator==(const RawRangeAndAngleBeam& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("RawRangeAndAngleBeam", float_precision);

        // raw values
        printer.register_value("_beam_pointing_angle", _beam_pointing_angle, "0.01°");
        printer.register_value("_transmit_sector_number", _transmit_sector_number);
        printer.register_string("_detection_info", fmt::format("0b{:08b}", _detection_info));
        printer.register_value("_detection_window_length_in_samples",
                               _detection_window_length_in_samples);
        printer.register_value("_quality_factor", _quality_factor);
        printer.register_value("_d_corr", _d_corr);
        printer.register_value("_two_way_travel_time", _two_way_travel_time, "s");
        printer.register_value("_reflectivity", _reflectivity, "0.1 dB");
        printer.register_value("_realtime_cleaning_info", _realtime_cleaning_info);
        printer.register_value("_spare", _spare);

        // processed values
        printer.register_section("processed");
        printer.register_value("beam_pointing_angle", get_beam_pointing_angle_in_degrees(), "°");
        printer.register_value("reflectivity", get_reflectivity_in_db(), "dB");
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
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
