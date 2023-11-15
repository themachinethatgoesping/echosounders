// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/watercolumndatagramtransmitsector.doc.hpp"

// std includes
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../../types.hpp"

#include "flag_detection_information.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

/**
 * @brief
 *
 */
class WatercolumnDatagramTransmitSector
{
    int16_t  _tilt_angle;       ///< in 0.01°
    uint16_t _center_frequency; ///< in 10 Hz
    uint8_t  _transmit_sector_number;
    uint8_t  _spare;

  public:
    WatercolumnDatagramTransmitSector()  = default;
    ~WatercolumnDatagramTransmitSector() = default;

    // ----- convenient member access -----
    // getters
    int16_t  get_tilt_angle() const { return _tilt_angle; }
    uint16_t get_center_frequency() const { return _center_frequency; }
    uint8_t  get_transmit_sector_number() const { return _transmit_sector_number; }
    uint8_t  get_spare() const { return _spare; }

    // setters
    void set_tilt_angle(int16_t tilt_angle) { _tilt_angle = tilt_angle; }
    void set_center_frequency(uint16_t center_frequency) { _center_frequency = center_frequency; }
    void set_transmit_sector_number(uint8_t transmit_sector_number)
    {
        _transmit_sector_number = transmit_sector_number;
    }
    void set_spare(uint8_t spare) { _spare = spare; }

    // ----- processed member access -----
    /**
     * @brief get the tilt angle in °
     *
     * @return _tilt_angle * 0.01° (float)
     */
    float get_tilt_angle_in_degrees() const { return _tilt_angle * 0.01f; }

    /**
     * @brief get the center frequency in Hz
     *
     * @return _center_frequency * 10 Hz (float)
     */
    float get_center_frequency_in_hz() const { return _center_frequency * 10.f; }

    // ----- operators -----
    bool operator==(const WatercolumnDatagramTransmitSector& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("WatercolumnDatagramTransmitSector",
                                                  float_precision);

        // raw values
        printer.register_value("tilt_angle", _tilt_angle, "0.01°");
        printer.register_value("center_frequency", _center_frequency, "10 Hz");
        printer.register_value("transmit_sector_number", _transmit_sector_number);
        printer.register_value("spare", _spare);

        // processed values
        printer.register_section("processed");
        printer.register_value("tilt_angle", get_tilt_angle_in_degrees(), "°");
        printer.register_value("center_frequency", get_center_frequency_in_hz(), "Hz");

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
