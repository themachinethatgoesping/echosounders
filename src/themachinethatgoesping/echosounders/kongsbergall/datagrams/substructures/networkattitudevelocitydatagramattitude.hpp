// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/networkattitudevelocitydatagramattitude.doc.hpp"

// std includes
#include <cstdint>
#include <iosfwd>
#include <string>

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
class NetworkAttitudeVelocityDatagramAttitude
{
    uint16_t    _time;                              ///< in_milliseconds_since_record_start
    int16_t     _roll;                              ///< in 0.01°
    int16_t     _pitch;                             ///< in 0.01°
    int16_t     _heave;                             ///< in cm
    uint16_t    _heading;                           ///< in 0.01°
    uint8_t     _number_of_bytes_in_input_datagram; ///< Nx
    std::string _input_datagram;                    ///< as received from the network

  public:
    NetworkAttitudeVelocityDatagramAttitude()  = default;
    ~NetworkAttitudeVelocityDatagramAttitude() = default;

    // ----- convenient member access -----
    // getters
    float    get_time() const;
    int16_t  get_roll() const;
    int16_t  get_pitch() const;
    int16_t  get_heave() const;
    uint16_t get_heading() const;
    uint16_t get_number_of_bytes_in_input_datagram() const;
    const std::string& get_input_datagram() const;

    // setters
    void set_time(uint16_t time);
    void set_roll(int16_t roll);
    void set_pitch(int16_t pitch);
    void set_heave(int16_t heave);
    void set_heading(uint16_t heading);
    void set_number_of_bytes_in_input_datagram(uint8_t number_of_bytes_in_input_datagram);
    void set_input_datagram(const std::string& input_datagram);

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
    bool operator==(const NetworkAttitudeVelocityDatagramAttitude& other) const = default;

    //----- to/from stream functions -----
    static NetworkAttitudeVelocityDatagramAttitude from_stream(std::istream& is);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter
    __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(NetworkAttitudeVelocityDatagramAttitude)
};

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
