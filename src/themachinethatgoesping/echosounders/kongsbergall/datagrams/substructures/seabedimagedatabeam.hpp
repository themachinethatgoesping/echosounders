// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/seabedimagedatabeam.doc.hpp"

// std includes
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>


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
class SeabedImageDataBeam
{
    int8_t   _sorting_direction;
    uint8_t  _detection_info;
    uint16_t _number_of_samples; ///< per beam
    uint16_t _centre_sample_number;

  public:
    SeabedImageDataBeam()  = default;
    ~SeabedImageDataBeam() = default;

    // ----- convenient member access -----
    // get
    uint16_t get_sorting_direction() const { return _sorting_direction; }
    uint8_t  get_detection_info() const { return _detection_info; }
    uint16_t get_number_of_samples() const { return _number_of_samples; }
    uint16_t get_centre_sample_number() const { return _centre_sample_number; }

    // set
    void set_sorting_direction(const uint16_t& sorting_direction)
    {
        _sorting_direction = sorting_direction;
    }
    void set_detection_info(const uint8_t& detection_info) { _detection_info = detection_info; }
    void set_number_of_samples(const uint16_t& number_of_samples)
    {
        _number_of_samples = number_of_samples;
    }
    void set_centre_sample_number(const uint16_t& centre_sample_number)
    {
        _centre_sample_number = centre_sample_number;
    }

    // ----- processed member access -----
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
    bool operator==(const SeabedImageDataBeam& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("SeabedImageDataBeam", float_precision, superscript_exponents);

        // raw values
        printer.register_value("sorting_direction", _sorting_direction);
        printer.register_value("detection_info", _detection_info);
        printer.register_value("number_of_samples", _number_of_samples, "per beam");
        printer.register_value("centre_sample_number", _centre_sample_number);

        // processed values
        printer.register_section("processed");
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
