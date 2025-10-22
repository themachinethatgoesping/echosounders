// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/attitudedatagramattitude.doc.hpp"

#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

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
class AttitudeDatagramAttitude
{
    uint16_t _time; ///< in_milliseconds_since_record_start
    uint16_t _sensor_status;
    int16_t  _roll;    ///< in 0.01°
    int16_t  _pitch;   ///< in 0.01°
    int16_t  _heave;   ///< in cm
    uint16_t _heading; ///< in 0.01°

  public:
    AttitudeDatagramAttitude()  = default;
    ~AttitudeDatagramAttitude() = default;

    // ----- convenient member access -----
    // getters
  float    get_time() const;
  uint16_t get_sensor_status() const;
  int16_t  get_roll() const;
  int16_t  get_pitch() const;
  int16_t  get_heave() const;
  uint16_t get_heading() const;

    // setters
  void set_time(uint16_t time);
  void set_sensor_status(uint16_t sensor_status);
  void set_roll(int16_t roll);
  void set_pitch(int16_t pitch);
  void set_heave(int16_t heave);
  void set_heading(uint16_t heading);

    // ----- processed member access -----
    /**
     * @brief Returns the time in seconds since record start.
     *
     * @return _time * 0.001f (float)
     */
  float get_time_in_seconds() const;

    /**
     * @brief Returns the roll in degrees.
     *
     * @return _roll * 0.01f (float)
     */
  float get_roll_in_degrees() const;

    /**
     * @brief Returns the pitch in degrees.
     *
     * @return _pitch * 0.01f (float)
     */
  float get_pitch_in_degrees() const;

    /**
     * @brief Returns the heave in meters.
     *
     * @return _heave * 0.01f (float)
     */
  float get_heave_in_meters() const;

    /**
     * @brief Returns the heading in degrees.
     *
     * @return _heading * 0.01f (float)
     */
  float get_heading_in_degrees() const;

    // ----- operators -----
    bool operator==(const AttitudeDatagramAttitude& other) const = default;

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
