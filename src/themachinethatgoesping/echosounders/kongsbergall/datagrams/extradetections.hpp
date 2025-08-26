// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/extradetections.doc.hpp"

// std includes
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper/floatcompare.hpp>

#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

#include "substructures/extradetectionsdetectionclasses.hpp"
#include "substructures/extradetectionsextradetections.hpp"
#include "substructures/sampleamplitudesstructure.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief This datagram is used for the models EM 2040 and EM 2040C with Slim Processing Unit.
 */
class ExtraDetections : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KongsbergAllDatagramIdentifier::ExtraDetections;

  protected:
    uint16_t _ping_counter;                  ///<
    uint16_t _system_serial_number;          ///<
    uint16_t _datagram_counter;              ///<
    uint16_t _datagram_version_id;           ///<
    uint16_t _swath_counter;                 ///<
    uint16_t _swath_index;                   ///<
    uint16_t _heading;                       ///< 0.01°
    uint16_t _sound_speed;                   ///< dm/s
    float    _depth_of_reference_point;      ///< m
    float    _water_column_sample_rate;      ///< (WCsr)
    float    _raw_amplitude_sample_rate;     ///< (SIsr)
    uint16_t _rx_transducer_index;           ///<
    uint16_t _number_of_extra_detections;    ///< Nd
    uint16_t _number_of_detection_classes;   ///<
    uint16_t _number_of_bytes_per_class;     ///<
    uint16_t _number_of_alarm_flags;         ///<
    uint16_t _number_of_bytes_per_detection; ///<

    std::vector<substructures::ExtraDetectionsDetectionClasses>
        _detection_classes; ///< substructure 1
    std::vector<substructures::ExtraDetectionsExtraDetections>
        _extra_detections; ///< substructure 2

    substructures::SampleAmplitudesStructure<int16_t> _raw_amplitude_samples; ///< 0.1 dB

    uint8_t  _spare;
    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit ExtraDetections(KongsbergAllDatagram header)
        : KongsbergAllDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    ExtraDetections() { _datagram_identifier = t_KongsbergAllDatagramIdentifier::ExtraDetections; }
    ~ExtraDetections() = default;

    // ----- convenient data access -----
    uint16_t get_ping_counter() const { return _ping_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint16_t get_datagram_counter() const { return _datagram_counter; }
    uint16_t get_datagram_version_id() const { return _datagram_version_id; }
    uint16_t get_swath_counter() const { return _swath_counter; }
    uint16_t get_swath_index() const { return _swath_index; }
    uint16_t get_heading() const { return _heading; }
    uint16_t get_sound_speed() const { return _sound_speed; }
    float    get_depth_of_reference_point() const { return _depth_of_reference_point; }
    float    get_water_column_sample_rate() const { return _water_column_sample_rate; }
    float    get_raw_amplitude_sample_rate() const { return _raw_amplitude_sample_rate; }
    uint16_t get_rx_transducer_index() const { return _rx_transducer_index; }
    uint16_t get_number_of_extra_detections() const { return _number_of_extra_detections; }
    uint16_t get_number_of_detection_classes() const { return _number_of_detection_classes; }
    uint16_t get_number_of_bytes_per_class() const { return _number_of_bytes_per_class; }
    uint16_t get_number_of_alarm_flags() const { return _number_of_alarm_flags; }
    uint16_t get_number_of_bytes_per_detection() const { return _number_of_bytes_per_detection; }
    const std::vector<substructures::ExtraDetectionsDetectionClasses>& get_detection_classes() const
    {
        return _detection_classes;
    }
    const std::vector<substructures::ExtraDetectionsExtraDetections>& get_extra_detections() const
    {
        return _extra_detections;
    }
    const substructures::SampleAmplitudesStructure<int16_t>& get_raw_amplitude_samples() const
    {
        return _raw_amplitude_samples;
    }
    uint16_t get_spare() const { return _spare; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    void set_ping_counter(uint16_t ping_counter) { _ping_counter = ping_counter; }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_datagram_counter(uint16_t datagram_counter) { _datagram_counter = datagram_counter; }
    void set_datagram_version_id(uint16_t datagram_version_id)
    {
        _datagram_version_id = datagram_version_id;
    }
    void set_swath_counter(uint16_t swath_counter) { _swath_counter = swath_counter; }
    void set_swath_index(uint16_t swath_index) { _swath_index = swath_index; }
    void set_heading(uint16_t heading) { _heading = heading; }
    void set_sound_speed(uint16_t sound_speed) { _sound_speed = sound_speed; }
    void set_depth_of_reference_point(float depth_of_reference_point)
    {
        _depth_of_reference_point = depth_of_reference_point;
    }
    void set_water_column_sample_rate(float water_column_sample_rate)
    {
        _water_column_sample_rate = water_column_sample_rate;
    }
    void set_raw_amplitude_sample_rate(float raw_amplitude_sample_rate)
    {
        _raw_amplitude_sample_rate = raw_amplitude_sample_rate;
    }
    void set_rx_transducer_index(uint16_t rx_transducer_index)
    {
        _rx_transducer_index = rx_transducer_index;
    }
    void set_number_of_extra_detections(uint16_t number_of_extra_detections)
    {
        _number_of_extra_detections = number_of_extra_detections;
    }
    void set_number_of_detection_classes(uint16_t number_of_detection_classes)
    {
        _number_of_detection_classes = number_of_detection_classes;
    }
    void set_number_of_bytes_per_class(uint16_t number_of_bytes_per_class)
    {
        _number_of_bytes_per_class = number_of_bytes_per_class;
    }
    void set_number_of_alarm_flags(uint16_t number_of_alarm_flags)
    {
        _number_of_alarm_flags = number_of_alarm_flags;
    }
    void set_number_of_bytes_per_detection(uint16_t number_of_bytes_per_detection)
    {
        _number_of_bytes_per_detection = number_of_bytes_per_detection;
    }

    void set_detection_classes(
        const std::vector<substructures::ExtraDetectionsDetectionClasses>& detection_classes)
    {
        _detection_classes = detection_classes;
    }
    void set_extra_detections(
        const std::vector<substructures::ExtraDetectionsExtraDetections>& extra_detections)
    {
        _extra_detections = extra_detections;
    }
    void set_raw_amplitude_samples(
        const substructures::SampleAmplitudesStructure<int16_t>& raw_amplitude_samples)
    {
        _raw_amplitude_samples = raw_amplitude_samples;
    }
    void set_spare(uint16_t spare_bytes) { _spare = spare_bytes; }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // ----- datastrucuture access -----
    std::vector<substructures::ExtraDetectionsDetectionClasses>& detection_classes()
    {
        return _detection_classes;
    }
    std::vector<substructures::ExtraDetectionsExtraDetections>& extra_detections()
    {
        return _extra_detections;
    }
    substructures::SampleAmplitudesStructure<int16_t>& raw_amplitude_samples()
    {
        return _raw_amplitude_samples;
    }

    // ----- processed data access -----
    /**
     * @brief Get heading in degrees
     *
     * @return _heading * 0.01° (double)
     */
    double get_heading_in_degrees() const { return _heading * 0.01; }

    /**
     * @brief Get sound velocity in m/s
     *
     * @return _sound_speed * 0.1 m/s (double)
     */
    double get_sound_speed_in_m_per_s() const { return _sound_speed * 0.1; }

    // ----- operators -----
    bool operator==(const ExtraDetections& other) const;

    //----- to/from stream functions -----
    static ExtraDetections from_stream(std::istream& is, KongsbergAllDatagram header);
    static ExtraDetections from_stream(std::istream& is);
    static ExtraDetections from_stream(std::istream&                    is,
                                       t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, 
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(ExtraDetections)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
