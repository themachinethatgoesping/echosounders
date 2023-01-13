// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/networkattitudevelocitydatagramattitude.doc.hpp"

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
    float    get_time() const { return _time; }
    int16_t  get_roll() const { return _roll; }
    int16_t  get_pitch() const { return _pitch; }
    int16_t  get_heave() const { return _heave; }
    uint16_t get_heading() const { return _heading; }
    uint16_t get_number_of_bytes_in_input_datagram() const
    {
        return _number_of_bytes_in_input_datagram;
    }
    const std::string& get_input_datagram() const { return _input_datagram; }

    // setters
    void set_time(uint16_t time) { _time = time; }
    void set_roll(int16_t roll) { _roll = roll; }
    void set_pitch(int16_t pitch) { _pitch = pitch; }
    void set_heave(int16_t heave) { _heave = heave; }
    void set_heading(uint16_t heading) { _heading = heading; }
    void set_number_of_bytes_in_input_datagram(uint8_t number_of_bytes_in_input_datagram)
    {
        _number_of_bytes_in_input_datagram = number_of_bytes_in_input_datagram;
    }
    void set_input_datagram(const std::string& input_datagram) { _input_datagram = input_datagram; }

    // ----- processed member access -----
    /**
     * @brief Returns the time in seconds since record start.
     *
     * @return _time * 0.001f (float)
     */
    float get_time_in_seconds() const { return _time * 0.001f; }

    /**
     * @brief Returns the roll in degrees.
     *
     * @return _roll * 0.01f (float)
     */
    float get_roll_in_degrees() const { return _roll * 0.01f; }

    /**
     * @brief Returns the pitch in degrees.
     *
     * @return _pitch * 0.01f (float)
     */
    float get_pitch_in_degrees() const { return _pitch * 0.01f; }

    /**
     * @brief Returns the heave in meters.
     *
     * @return _heave * 0.01f (float)
     */
    float get_heave_in_meters() const { return _heave * 0.01f; }

    /**
     * @brief Returns the heading in degrees.
     *
     * @return _heading * 0.01f (float)
     */
    float get_heading_in_degrees() const { return _heading * 0.01f; }

    // ----- operators -----
    bool operator==(const NetworkAttitudeVelocityDatagramAttitude& other) const
    {
        return _time == other._time && _roll == other._roll && _pitch == other._pitch &&
               _heave == other._heave && _heading == other._heading &&
               _number_of_bytes_in_input_datagram == other._number_of_bytes_in_input_datagram &&
               _input_datagram == other._input_datagram;
    }
    bool operator!=(const NetworkAttitudeVelocityDatagramAttitude& other) const
    {
        return !(*this == other);
    }

    //----- to/from stream functions -----
    static NetworkAttitudeVelocityDatagramAttitude from_stream(std::istream& is)
    {
        // init the sample amplitudes structure with the correct size
        NetworkAttitudeVelocityDatagramAttitude data;

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(data._time)), 11 * sizeof(uint8_t));

        data._input_datagram.resize(data._number_of_bytes_in_input_datagram);
        is.read(reinterpret_cast<char*>(data._input_datagram.data()),
                data._input_datagram.size() * sizeof(char));

        return data;
    }

    void to_stream(std::ostream& os)
    {
        _number_of_bytes_in_input_datagram = _input_datagram.size();

        // read first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_time)), 11 * sizeof(uint8_t));

        os.write(reinterpret_cast<const char*>(_input_datagram.data()),
                 _input_datagram.size() * sizeof(char));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("NetworkAttitudeVelocityDatagramAttitude",
                                                  float_precision);

        // raw values
        printer.register_value("time", _time, "ms");
        printer.register_value("roll", _roll, "0.01°");
        printer.register_value("pitch", _pitch, "0.01°");
        printer.register_value("heave", _heave, "cm°");
        printer.register_value("heading", _heading, "0.01°");
        printer.register_value("number_of_bytes_in_input_datagram",
                               _number_of_bytes_in_input_datagram);
        printer.register_string("input_datagram", _input_datagram);

        // processed values
        printer.register_section("processed");
        printer.register_value("roll", get_roll_in_degrees(), "°");
        printer.register_value("pitch", get_pitch_in_degrees(), "°");
        printer.register_value("heave", get_heave_in_meters(), "m");
        printer.register_value("heading", get_heading_in_degrees(), "°");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(NetworkAttitudeVelocityDatagramAttitude)
};

} // namespace substructures
} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
