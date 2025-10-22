// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/watercolumndatagramtransmitsector.doc.hpp"

// std includes
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

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
    int16_t  get_tilt_angle() const;
    uint16_t get_center_frequency() const;
    uint8_t  get_transmit_sector_number() const;
    uint8_t  get_spare() const;

    // setters
    void set_tilt_angle(int16_t tilt_angle);
    void set_center_frequency(uint16_t center_frequency);
    void set_transmit_sector_number(uint8_t transmit_sector_number);
    void set_spare(uint8_t spare);

    // for hashing

    // ----- processed member access -----
    /**
     * @brief get the tilt angle in °
     *
     * @return _tilt_angle * 0.01° (float)
     */
    float get_tilt_angle_in_degrees() const;

    /**
     * @brief get the center frequency in Hz
     *
     * @return _center_frequency * 10 Hz (float)
     */
    float get_center_frequency_in_hz() const;

    // ----- operators -----
    bool operator==(const WatercolumnDatagramTransmitSector& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool          superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
