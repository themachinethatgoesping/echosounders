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

    // std::vector<std::vector<int16_t>> _raw_amplitude_samples;
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
    bool operator==(const ExtraDetections& other) const
    {
        return KongsbergAllDatagram::operator==(other) && _ping_counter == other._ping_counter &&
               _system_serial_number == other._system_serial_number &&
               _datagram_counter == other._datagram_counter &&
               _datagram_version_id == other._datagram_version_id &&
               _swath_counter == other._swath_counter && _swath_index == other._swath_index &&
               _heading == other._heading && _sound_speed == other._sound_speed &&
               tools::helper::float_equals(_depth_of_reference_point,
                                           other._depth_of_reference_point) &&
               tools::helper::float_equals(_water_column_sample_rate,
                                           other._water_column_sample_rate) &&
               tools::helper::float_equals(_raw_amplitude_sample_rate,
                                           other._raw_amplitude_sample_rate) &&
               _rx_transducer_index == other._rx_transducer_index &&
               _number_of_extra_detections == other._number_of_extra_detections &&
               _number_of_detection_classes == other._number_of_detection_classes &&
               _number_of_bytes_per_class == other._number_of_bytes_per_class &&
               _number_of_alarm_flags == other._number_of_alarm_flags &&
               _number_of_bytes_per_detection == other._number_of_bytes_per_detection &&
               _detection_classes == other._detection_classes &&
               _extra_detections == other._extra_detections &&
               _raw_amplitude_samples == other._raw_amplitude_samples && _spare == other._spare &&
               _etx == other._etx && _checksum == other._checksum;
    }

    //----- to/from stream functions -----
    static ExtraDetections from_stream(std::istream& is, KongsbergAllDatagram header)
    {
        ExtraDetections datagram(std::move(header));

        // auto pos = is.tellg();

        if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::ExtraDetections)
            throw std::runtime_error(
                fmt::format("ExtraDetections: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                            uint8_t(t_KongsbergAllDatagramIdentifier::ExtraDetections),
                            uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 40 * sizeof(uint8_t));

        // read detection classes
        datagram._detection_classes.resize(datagram._number_of_detection_classes);
        is.read(reinterpret_cast<char*>(datagram._detection_classes.data()),
                datagram._number_of_detection_classes *
                    sizeof(substructures::ExtraDetectionsDetectionClasses));

        // read extra detections
        datagram._extra_detections.resize(datagram._number_of_extra_detections);
        is.read(reinterpret_cast<char*>(datagram._extra_detections.data()),
                datagram._number_of_extra_detections *
                    sizeof(substructures::ExtraDetectionsExtraDetections));

        // read raw amplitude samples
        uint16_t              total_samples = 0;
        std::vector<uint16_t> samples_per_beam;
        std::vector<uint16_t> start_index_per_beam;
        samples_per_beam.reserve(datagram._number_of_extra_detections);

        for (const auto& beam : datagram._extra_detections)
        {
            start_index_per_beam.push_back(total_samples);
            samples_per_beam.push_back(beam.get_number_of_raw_amplitude_samples());
            total_samples += samples_per_beam.back();
        }

        datagram._raw_amplitude_samples =
            substructures::SampleAmplitudesStructure<int16_t>::from_stream(
                is, total_samples, std::move(start_index_per_beam), std::move(samples_per_beam));

        // read the rest of the datagram
        // is.read(reinterpret_cast<char*>(&(datagram._spare)), 5 * sizeof(uint8_t));
        is.read(reinterpret_cast<char*>(&(datagram._spare)), 4 * sizeof(uint8_t));

        // TODO: fix reading raw_amplitudes
        // if (datagram._etx != 0x03)
        // {
        //     auto pos_is = is.tellg();
        //     auto pos_should = pos + signed(datagram.get_bytes()) - 15;
        //     throw std::runtime_error(fmt::format(
        //         "ExtraDetections: end identifier is not 0x03, but 0x{:x}"
        //         "Position is {} bytes to far", datagram._etx, pos_is - pos_should));
        // }

        return datagram;
    }

    static ExtraDetections from_stream(std::istream& is)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is));
    }

    static ExtraDetections from_stream(std::istream&                    is,
                                       t_KongsbergAllDatagramIdentifier datagram_identifier)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
    }

    void to_stream(std::ostream& os)
    {
        KongsbergAllDatagram::to_stream(os);
        _number_of_detection_classes = _detection_classes.size();
        _number_of_extra_detections  = _extra_detections.size();
        //_raw_amplitude_samples.resize(_number_of_extra_detections);

        // for (unsigned int i = 0; i < _number_of_extra_detections; ++i)
        //     _raw_amplitude_samples[i].resize(
        //         _extra_detections[i].get_number_of_raw_amplitude_samples() * 2 + 1);

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_ping_counter)), 40 * sizeof(uint8_t));

        // write the detection classes
        os.write(reinterpret_cast<const char*>(_detection_classes.data()),
                 _number_of_detection_classes *
                     sizeof(substructures::ExtraDetectionsDetectionClasses));

        // write the extra detections
        os.write(reinterpret_cast<const char*>(_extra_detections.data()),
                 _number_of_extra_detections *
                     sizeof(substructures::ExtraDetectionsExtraDetections));

        // write the raw amplitude samples
        _raw_amplitude_samples.to_stream(os);
        // for (unsigned int i = 0; i < _number_of_extra_detections; ++i)
        //     os.write(reinterpret_cast<const char*>(_raw_amplitude_samples[i].data()),
        //              _raw_amplitude_samples[i].size() * sizeof(uint16_t));

        // write the rest of the datagram
        os.write(reinterpret_cast<const char*>(&(_spare)), 4 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("ExtraDetections", float_precision, superscript_exponents);

        printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
        printer.register_section("datagram content");
        printer.register_value("ping_counter", _ping_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("datagram_counter", _datagram_counter);
        printer.register_value("datagram_version_id", _datagram_version_id);
        printer.register_value("swath_counter", _swath_counter);
        printer.register_value("swath_index", _swath_index);
        printer.register_value("heading", _heading, "0.01° steps");
        printer.register_value("sound_speed", _sound_speed, "0.1 m/s steps");
        printer.register_value("depth_of_reference_point", _depth_of_reference_point, "m");
        printer.register_value("water_column_sample_rate", _water_column_sample_rate, "(WCsr)");
        printer.register_value("raw_amplitude_sample_rate", _raw_amplitude_sample_rate, "(SIsr)");
        printer.register_value("rx_transducer_index", _rx_transducer_index);
        printer.register_value("number_of_extra_detections", _number_of_extra_detections);
        printer.register_value("number_of_detection_classes", _number_of_detection_classes);
        printer.register_value("number_of_bytes_per_class", _number_of_bytes_per_class);
        printer.register_value("number_of_alarm_flags", _number_of_alarm_flags);
        printer.register_value("number_of_bytes_per_detection", _number_of_bytes_per_detection);
        printer.register_string("spare_bytes", fmt::format("0x{:02x}", _spare));
        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        printer.register_section("processed");
        printer.register_value("heading", get_heading_in_degrees(), "°");
        printer.register_value("sound_speed", get_sound_speed_in_m_per_s(), "m/s");

        printer.register_section("substructures");
        printer.register_value(
            "detection_classes", _detection_classes.size(), "ExtraDetectionsDetectionClasses");
        printer.register_value(
            "extra_detections", _extra_detections.size(), "ExtraDetectionsExtraDetections");
        printer.register_value(
            "raw_amplitude_samples", _raw_amplitude_samples.size(), "SampleAmplitudesStructure");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(ExtraDetections)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
