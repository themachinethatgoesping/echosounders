// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/soundvelocitytransducer.doc.hpp"

// std includes
#include <cstdint>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/option_frozen.hpp>

#include "../types.hpp"
#include "kmalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

/**
 * @brief Clock datagrams
 */
class SoundVelocityTransducer : public KMALLDatagram
{
  public:
    static constexpr auto DatagramIdentifier =
        t_KMALLDatagramIdentifier::S_SOUND_VELOCITY_TRANSDUCER;
    static constexpr size_t __size = 20; // size till _sensor_data

    enum class t_sensor_format : uint16_t
    {
        AML_NMEA         = 1,
        AML_SV           = 2,
        AML_SVT          = 3,
        AML_SVP          = 4,
        Micro_SV         = 5,
        Micro_SVT        = 6,
        Micro_SVP        = 7,
        Valeport_MiniSVS = 8,
        KSSIS_80         = 9,
        KSSIS_43         = 10,
        XDR_S            = 11,
        Valeport_NMEA    = 12,
    };

    static constexpr std::array<t_sensor_format, 12> t_sensor_format_values = {
        t_sensor_format::AML_NMEA,  t_sensor_format::AML_SV,
        t_sensor_format::AML_SVT,   t_sensor_format::AML_SVP,
        t_sensor_format::Micro_SV,  t_sensor_format::Micro_SVT,
        t_sensor_format::Micro_SVP, t_sensor_format::Valeport_MiniSVS,
        t_sensor_format::KSSIS_80,  t_sensor_format::KSSIS_43,
        t_sensor_format::XDR_S,     t_sensor_format::Valeport_NMEA,
    };

    static constexpr std::array<std::string_view, 12> t_sensor_format_names = {
        "AML_NMEA",  "AML_SV",           "AML_SVT",  "AML_SVP",  "Micro_SV", "Micro_SVT",
        "Micro_SVP", "Valeport_MiniSVS", "KSSIS_80", "KSSIS_43", "XDR_S",    "Valeport_NMEA",
    };

    static constexpr std::array<std::string_view, 12> t_sensor_format_alt_names = {
        "AML NMEA",  "AML SV",           "AML SVT",  "AML SVP",  "Micro SV", "Micro SVT",
        "Micro SVP", "Valeport MiniSVS", "KSSIS 80", "KSSIS 43", "XDR S",    "Valeport NMEA",
    };

    using o_sensor_format =
        themachinethatgoesping::tools::classhelper::OptionFrozen<t_sensor_format,
                                                                 t_sensor_format_values.size(),
                                                                 t_sensor_format_values,
                                                                 t_sensor_format_names,
                                                                 t_sensor_format_alt_names>;

#pragma pack(push, 4) // force 4-byte alignment
    struct SVTSample
    {
        uint32_t time_sec;
        uint32_t time_nanosec;
        float    soundVelocity_m_per_sec;
        float    temp_c;
        float    pressure_pa;
        float    salinity;

        bool operator==(const SVTSample& other) const = default;

        double      get_sensor_timestamp() const;
        std::string get_sensor_date_string(
            unsigned int       fractionalSecondsDigits = 2,
            const std::string& format                  = "%z__%d-%m-%Y__%H:%M:%S") const;

        tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                      bool         superscript_exponents) const;
    };
#pragma pack(pop)

  protected:
#pragma pack(push, 4) // force 4-byte alignment
    struct Content
    {
        uint16_t        bytes_content;
        uint16_t        sensor_status;
        o_sensor_format sensor_input_format;
        uint16_t        number_of_samples;
        uint16_t        number_of_bytes_per_sample;
        uint16_t        sensor_data_contents;
        float           filter_time_sec;
        float           sound_velocity_offset_m_per_sec;

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    std::vector<SVTSample> _sensor_data;
    uint32_t _bytes_datagram_check; ///< Each datagram ends with the size of the datagram for
                                    ///< integrity check

  public:
    // ----- public constructors -----
    SoundVelocityTransducer();
    ~SoundVelocityTransducer() = default;

    // ----- convenient data access -----
    // Getters
    uint16_t        get_bytes_content() const { return _content.bytes_content; }
    uint16_t        get_sensor_status() const { return _content.sensor_status; }
    o_sensor_format get_sensor_input_format() const { return _content.sensor_input_format; }
    uint16_t        get_number_of_samples() const { return _content.number_of_samples; }
    uint16_t get_number_of_bytes_per_sample() const { return _content.number_of_bytes_per_sample; }
    uint16_t get_sensor_data_contents() const { return _content.sensor_data_contents; }
    float    get_filter_time_sec() const { return _content.filter_time_sec; }
    float    get_sound_velocity_offset_m_per_sec() const
    {
        return _content.sound_velocity_offset_m_per_sec;
    }

    const std::vector<SVTSample>& get_sensor_data() const { return _sensor_data; }
    uint32_t                      get_bytes_datagram_check() const { return _bytes_datagram_check; }

    // Setters
    void set_bytes_content(uint16_t value) { _content.bytes_content = value; }
    void set_sensor_status(uint16_t value) { _content.sensor_status = value; }
    void set_sensor_input_format(o_sensor_format value) { _content.sensor_input_format = value; }
    void set_number_of_samples(uint16_t value) { _content.number_of_samples = value; }
    void set_number_of_bytes_per_sample(uint16_t value)
    {
        _content.number_of_bytes_per_sample = value;
    }
    void set_sensor_data_contents(uint16_t value) { _content.sensor_data_contents = value; }
    void set_filter_time_sec(float value) { _content.filter_time_sec = value; }
    void set_sound_velocity_offset_m_per_sec(float value)
    {
        _content.sound_velocity_offset_m_per_sec = value;
    }
    void set_sensor_data(const std::vector<SVTSample>& data);
    void set_bytes_datagram_check(uint32_t val) { _bytes_datagram_check = val; }

    // ----- processed data access -----
    bool get_sound_velocity_active() const;
    bool get_temperature_active() const;
    bool get_pressure_active() const;
    bool get_salinity_active() const;

    void set_sound_velocity_active(bool active);
    void set_temperature_active(bool active);
    void set_pressure_active(bool active);
    void set_salinity_active(bool active);

    std::vector<double> get_svt_timestamps() const;
    std::vector<float>  get_svt_sound_velocities() const;
    std::vector<float>  get_svt_temperatures() const;
    std::vector<float>  get_svt_pressures() const;
    std::vector<float>  get_svt_salinities() const;

    // ----- operators -----
    bool operator==(const SoundVelocityTransducer& other) const = default;

    //----- to/from stream functions -----
    static SoundVelocityTransducer from_stream(std::istream& is, const KMALLDatagram& header);

    static SoundVelocityTransducer from_stream(std::istream&             is,
                                               o_KMALLDatagramIdentifier datagram_identifier);

    static SoundVelocityTransducer from_stream(std::istream& is);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(SoundVelocityTransducer)

  protected:
    explicit SoundVelocityTransducer(const KMALLDatagram& header);
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping

extern template class themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityTransducer::
        t_sensor_format,
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityTransducer::
        t_sensor_format_values.size(),
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityTransducer::
        t_sensor_format_values,
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityTransducer::
        t_sensor_format_names,
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityTransducer::
        t_sensor_format_alt_names>;