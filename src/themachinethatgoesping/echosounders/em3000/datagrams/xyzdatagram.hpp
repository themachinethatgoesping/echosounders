// SPDX-FileCopyrightText: 2022 GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <string>
#include <unordered_map>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../em3000_types.hpp"
#include "em3000datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {

/**
 * @brief The beam data are given re the transmit transducer or sonar head depth and the horizontal
 * location (x,y) of the active positioning system's reference point. Heave, roll, pitch, sound
 * speed at the transducer depth and ray bending through the water column have been applied.
 *
 */
struct XYZBeam
{
    float    depth;                   ///< (Z) from transmit transducer in meter
    float    acrosstrack_distance;    ///< distance (y) in meter
    float    alongtrack_distance;     ///< distance (x) in meter
    uint16_t detection_window_length; ///< in samples
    uint8_t quality_factor; ///< 0-254 Scaled standard deviation (sd) of the range detection divided
                            ///< by the detected range (dr) (qf = 250*sd/sr)
    int8_t  beam_incidence_angle_adjustment; ///< (IBA) in 0.1 degree
    uint8_t detection_information; ///< Flag that indicates the type and validity of detection
    int8_t  realtime_cleaning_information; ///< Flag that indicates if the beam was flagged by real
                                           ///< time cleaning (negative values indicate that this
                                           ///< beam is flagged out)
    int16_t reflectivity;                  // Backscatter (BS) in 0.1 dB resolution

    // ----- processed member access -----
    // convert reflectivity to backscatter
    double get_backscatter() const { return (65536 - reflectivity) * 0.1; }

    // convert detection_information
    bool get_detection_is_valid() const { return (detection_information & 0x01) == 0x01; }

    enum class DetectionType : uint8_t
    {
        AmplitudeDetect        = 0b00000000,
        PhaseDetect            = 0b00000001,
        InvalidNormalDetection = 0b10000000, ///< Invalid: Normal detection
        Interpolated           = 0b10000001, ///< Invalid: Therefor interpolated or extrapolated
        Estimated              = 0b10000010, ///< Invalid: Therefor estimated
        Rejected               = 0b10000011, ///< Invalid: Therefor rejected
        NoDetection = 0b10000100, ///< Invalid: No detection data is available for this beam
        Invalid
    };
    DetectionType get_detection_type() const
    {
        return DetectionType(detection_information & 0b11110111);
    }

    bool get_backscatter_is_compensated() const
    {
        return (detection_information & 0b00001000) == 0b00001000;
    }

    double get_beam_incidence_angle_adjustment_in_degrees() const
    {
        return beam_incidence_angle_adjustment * 0.1;
    }

    // ----- operators -----
    bool operator==(const XYZBeam& other) const
    {
        return depth == other.depth && acrosstrack_distance == other.acrosstrack_distance &&
               alongtrack_distance == other.alongtrack_distance &&
               detection_window_length == other.detection_window_length &&
               quality_factor == other.quality_factor &&
               beam_incidence_angle_adjustment == other.beam_incidence_angle_adjustment &&
               detection_information == other.detection_information &&
               realtime_cleaning_information == other.realtime_cleaning_information &&
               reflectivity == other.reflectivity;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("XYZBeam", float_precision);

        printer.register_value("depth", depth, "-z in m");
        printer.register_value("acrosstrack_distance", acrosstrack_distance, "y in m");
        printer.register_value("alongtrack_distance", alongtrack_distance, "x in m");
        printer.register_value("detection_window_length", detection_window_length, "in samples");
        printer.register_value("quality_factor", quality_factor);
        printer.register_value(
            "beam_incidence_angle_adjustment", beam_incidence_angle_adjustment, "0.1°");
        printer.register_value("beam_incidence_angle_adjustment",
                               get_beam_incidence_angle_adjustment_in_degrees(),
                               "°");
        printer.register_value("detection_information", detection_information);
        printer.register_value("detection_is_valid", get_detection_is_valid());
        printer.register_enum("detection_type", get_detection_type());
        printer.register_value("backscatter_is_compensated", get_backscatter_is_compensated());
        printer.register_value("realtime_cleaning_information", realtime_cleaning_information);
        printer.register_value("reflectivity", reflectivity, "0.1 dB");
        printer.register_value("reflectivity", get_backscatter(), "dB");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

/**
 * @brief This datagram is used for the models EM 2040, EM 2040C, EM 710, EM 122, EM
302 and ME70BO. All receiver beams are included, check detection info and real time
cleaning for beam status (note 4 and 5).
 */
class XYZDatagram : public EM3000Datagram
{
  protected:
    uint16_t _ping_counter;              ///< 0-65535 ping number (in this file)
    uint16_t _system_serial_number;      ///< 100 -
    uint16_t _heading_of_vessel;         ///< (at TX time) in 0.01 degree
    uint16_t _sound_speed;               ///< at transducer in dm/s
    float    _transmit_transducer_depth; ///< in meter relative water level at time of ping
    uint16_t _number_of_beams;           ///< in Datagram
    uint16_t _number_of_valid_detections;
    float    _sampling_frequency; ///< in Hz
    uint8_t  _scanning_info;      ///< only used by em2040. 0 means scanning is not used.
    std::array<uint8_t, 3> _spare_bytes;
    std::vector<XYZBeam>   _beams; ///< beam detection information
    uint8_t                _spare_byte;
    uint8_t                _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t               _checksum;

  private:
    // ----- private constructors -----
    explicit XYZDatagram(EM3000Datagram header)
        : EM3000Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    XYZDatagram() { _datagram_identifier = t_EM3000DatagramIdentifier::XYZDatagram; }
    ~XYZDatagram() = default;

    // ----- convenient data access -----
    uint16_t get_ping_counter() const { return _ping_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint16_t get_heading_of_vessel() const { return _heading_of_vessel; }
    uint16_t get_sound_speed() const { return _sound_speed; }
    float    get_transmit_transducer_depth() const { return _transmit_transducer_depth; }
    uint16_t get_number_of_beams() const { return _number_of_beams; }
    uint16_t get_number_of_valid_detections() const { return _number_of_valid_detections; }
    float    get_sampling_frequency() const { return _sampling_frequency; }
    uint8_t  get_scanning_info() const { return _scanning_info; }
    const std::array<uint8_t, 3>& get_spare_bytes() const { return _spare_bytes; }
    const std::vector<XYZBeam>&   get_beams() const { return _beams; }
    uint8_t                       get_spare_byte() const { return _spare_byte; }
    uint8_t                       get_etc() const { return _etx; }
    uint16_t                      get_checksum() const { return _checksum; }

    /**
     * @brief structure access to beams
     *
     * @return std::vector<XYZBeam>&
     */
    std::vector<XYZBeam>& beams() { return _beams; }

    void set_ping_counter(uint16_t ping_counter) { _ping_counter = ping_counter; }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_heading_of_vessel(uint16_t heading_of_vessel)
    {
        _heading_of_vessel = heading_of_vessel;
    }
    void set_sound_speed(uint16_t sound_speed) { _sound_speed = sound_speed; }
    void set_transmit_transducer_depth(float transmit_transducer_depth)
    {
        _transmit_transducer_depth = transmit_transducer_depth;
    }
    void set_number_of_beams(uint16_t number_of_beams) { _number_of_beams = number_of_beams; }
    void set_number_of_valid_detections(uint16_t number_of_valid_detections)
    {
        _number_of_valid_detections = number_of_valid_detections;
    }
    void set_sampling_frequency(float sampling_frequency)
    {
        _sampling_frequency = sampling_frequency;
    }
    void set_scanning_info(uint8_t scanning_info) { _scanning_info = scanning_info; }
    void set_spare_bytes(std::array<uint8_t, 3> spare_bytes) { _spare_bytes = spare_bytes; }
    void set_beams(std::vector<XYZBeam> beams) { _beams = beams; }
    void set_spare_byte(uint8_t spare_byte) { _spare_byte = spare_byte; }
    void set_etc(uint8_t etc) { _etx = etc; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // ----- processed data access -----
    double get_heading_of_vessel_in_degrees() const { return _heading_of_vessel * 0.01; }
    double get_sound_speed_in_meters_per_second() const { return _sound_speed * 0.1; }

    // ----- operators -----
    bool operator==(const XYZDatagram& other) const
    {
        return _ping_counter == other._ping_counter &&
               _system_serial_number == other._system_serial_number &&
               _heading_of_vessel == other._heading_of_vessel &&
               _sound_speed == other._sound_speed &&
               _transmit_transducer_depth == other._transmit_transducer_depth &&
               _number_of_beams == other._number_of_beams &&
               _number_of_valid_detections == other._number_of_valid_detections &&
               _sampling_frequency == other._sampling_frequency &&
               _scanning_info == other._scanning_info && _spare_bytes == other._spare_bytes &&
               _beams == other._beams && _spare_byte == other._spare_byte && _etx == other._etx &&
               _checksum == other._checksum;
    }
    bool operator!=(const XYZDatagram& other) const { return !operator==(other); }

    static XYZDatagram from_stream(std::istream& is, EM3000Datagram header)
    {
        XYZDatagram datagram(std::move(header));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 24 * sizeof(uint8_t));

        // read the beams
        datagram._beams.resize(datagram._number_of_beams);
        is.read(reinterpret_cast<char*>(datagram._beams.data()),
                datagram._number_of_beams * sizeof(XYZBeam));

        // read the rest of the datagram
        is.read(reinterpret_cast<char*>(&(datagram._spare_byte)), 4 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(
                fmt::format("XYZDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static XYZDatagram from_stream(std::istream& is)
    {
        return from_stream(is, EM3000Datagram::from_stream(is));
    }

    static XYZDatagram from_stream(std::istream& is, t_EM3000DatagramIdentifier datagram_identifier)
    {
        return from_stream(is, std::move(EM3000Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os)
    {
        EM3000Datagram::to_stream(os);
        _number_of_beams = _beams.size();

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_ping_counter)), 24 * sizeof(uint8_t));

        // write the beams
        os.write(reinterpret_cast<const char*>(_beams.data()), _number_of_beams * sizeof(XYZBeam));

        // write the rest of the datagram
        os.write(reinterpret_cast<const char*>(&(_spare_byte)), 4 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("XYZDatagram", float_precision);

        printer.append(EM3000Datagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("ping_counter", _ping_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("heading_of_vessel", _heading_of_vessel, "0.01° steps");
        printer.register_value("heading_of_vessel", get_heading_of_vessel_in_degrees(), "°");
        printer.register_value("sound_speed", _sound_speed, "0.1 m/s steps");
        printer.register_value("sound_speed", get_sound_speed_in_meters_per_second(), "m/s");
        printer.register_value("transmit_transducer_depth", _transmit_transducer_depth, "m");
        printer.register_value("number_of_beams", _number_of_beams);
        printer.register_value("number_of_valid_detections", _number_of_valid_detections);
        printer.register_value("sampling_frequency", _sampling_frequency, "Hz");
        printer.register_value("scanning_info", _scanning_info);
        printer.register_value("beams", _beams.size(), "structures");

        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(XYZDatagram)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
