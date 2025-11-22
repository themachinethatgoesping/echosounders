// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/skmbinary.doc.hpp"

// std includes
#include <bitset>
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
class SKMBinary : public KMALLDatagram
{
  public:
    static constexpr auto   DatagramIdentifier = t_KMALLDatagramIdentifier::S_KM_BINARY;
    static constexpr size_t __size             = 12; // size till _sensor_data

    enum class t_sensor_format : uint16_t
    {
        KM_binary_Sensor_Input = 1,
        EM_3000_data           = 2,
        Sagem                  = 3,
        Seapath_binary_11      = 4,
        Seapath_binary_23      = 5,
        Seapath_binary_26      = 6,
        POS_M_V_GRP_102_103    = 7
    };

    static constexpr std::array<t_sensor_format, 7> t_sensor_format_values = {
        t_sensor_format::KM_binary_Sensor_Input,
        t_sensor_format::EM_3000_data,
        t_sensor_format::Sagem,
        t_sensor_format::Seapath_binary_11,
        t_sensor_format::Seapath_binary_23,
        t_sensor_format::Seapath_binary_26,
        t_sensor_format::POS_M_V_GRP_102_103
    };

    static constexpr std::array<std::string_view, 7> t_sensor_format_names = {
        "KM_binary_Sensor_Input", "EM_3000_data",      "Sagem",
        "Seapath_binary_11",      "Seapath_binary_23", "Seapath_binary_26",
        "POS_M_V_GRP_102_103"
    };

    static constexpr std::array<std::string_view, 7> t_sensor_format_alt_names = {
        "KM binary Sensor Input", "EM 3000 data",      "Sagem ",
        "Seapath binary 11",      "Seapath binary 23", "Seapath binary 26",
        "POS M/V GRP 102/103"
    };

    using o_sensor_format =
        themachinethatgoesping::tools::classhelper::OptionFrozen<t_sensor_format,
                                                                 t_sensor_format_values.size(),
                                                                 t_sensor_format_values,
                                                                 t_sensor_format_names,
                                                                 t_sensor_format_alt_names>;

#pragma pack(push, 4) // force 4-byte alignment
    struct KMBinary
    {
        // header
        o_KMALLDatagramIdentifier datagram_identifier; // should always be #KMB
        uint16_t                  bytes_content;
        uint16_t                  dgm_version;
        uint32_t                  time_sec;
        uint32_t                  time_nanosec;
        uint32_t                  status;

        // position
        double latitude_deg;
        double longitude_deg;
        float  ellipsoid_height_m;

        // attitude
        float roll_deg;
        float pitch_deg;
        float heading_deg;
        float heave_m;

        // rates
        float roll_rate;
        float pitch_rate;
        float yaw_rate;

        // velocities
        float vel_north;
        float vel_east;
        float vel_down;

        // errors/quality (standard deviations)
        float latitude_error_m;
        float longitude_error_m;
        float ellipsoid_height_error_m;
        float roll_error_deg;
        float pitch_error_deg;
        float heading_error_deg;
        float heave_error_m;

        // accelerations
        float north_acceleration;
        float east_acceleration;
        float down_acceleration;

        // processed
        std::bitset<32> get_status_bits() const;
        void            set_status_bits(std::bitset<32> bits);

        bool get_horizontal_position_and_velocity_valid() const;
        bool get_roll_and_pitch_valid() const;
        bool get_heading_valid() const;
        bool get_heave_valid() const;
        bool get_acceleration_valid() const;
        bool get_delayed_heave1_valid() const;
        bool get_delayed_heave2_valid() const;

        bool get_horizontal_position_and_velocity_reduced_performance() const;
        bool get_roll_and_pitch_reduced_performance() const;
        bool get_heading_reduced_performance() const;
        bool get_heave_reduced_performance() const;
        bool get_acceleration_reduced_performance() const;
        bool get_delayed_heave1_reduced_performance() const;
        bool get_delayed_heave2_reduced_performance() const;

        void set_horizontal_position_and_velocity_valid(bool valid);
        void set_roll_and_pitch_valid(bool valid);
        void set_heading_valid(bool valid);
        void set_heave_valid(bool valid);
        void set_acceleration_valid(bool valid);
        void set_delayed_heave1_valid(bool valid);
        void set_delayed_heave2_valid(bool valid);

        void set_horizontal_position_and_velocity_reduced_performance(bool reduced_performance);
        void set_roll_and_pitch_reduced_performance(bool reduced_performance);
        void set_heading_reduced_performance(bool reduced_performance);
        void set_heave_reduced_performance(bool reduced_performance);
        void set_acceleration_reduced_performance(bool reduced_performance);
        void set_delayed_heave1_reduced_performance(bool reduced_performance);
        void set_delayed_heave2_reduced_performance(bool reduced_performance);

        bool operator==(const KMBinary& other) const = default;

        double      get_sensor_timestamp() const;
        std::string get_sensor_date_string(
            unsigned int       fractionalSecondsDigits = 2,
            const std::string& format                  = "%z__%d-%m-%Y__%H:%M:%S") const;

        tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                      bool         superscript_exponents) const;

        __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    };
#pragma pack(pop)

#pragma pack(push, 4) // force 4-byte alignment
    struct KMDelayedHeave
    {
        // header
        uint32_t time_sec;
        uint32_t time_nanosec;
        float    delayed_heave_m;

        bool operator==(const KMDelayedHeave& other) const = default;

        double      get_sensor_timestamp() const;
        std::string get_sensor_date_string(
            unsigned int       fractionalSecondsDigits = 2,
            const std::string& format                  = "%z__%d-%m-%Y__%H:%M:%S") const;

        tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                      bool         superscript_exponents) const;

        __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    };
#pragma pack(pop)

#pragma pack(push, 4) // force 4-byte alignment
    struct SKMSample
    {
        // header
        KMBinary       km_binary;
        KMDelayedHeave km_delayed_heave;

        bool operator==(const SKMSample& other) const = default;

        tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                      bool         superscript_exponents) const;

        __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    };
#pragma pack(pop)

  protected:
#pragma pack(push, 4) // force 4-byte alignment
    struct Content
    {
        uint16_t        bytes_content;
        uint8_t         sensor_system;
        uint8_t         sensor_status;
        o_sensor_format sensor_format;
        uint16_t        number_of_samples;
        uint16_t        number_of_bytes_per_sample;
        uint16_t        sensor_data_contents;

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    std::vector<SKMSample> _sensor_data;
    uint32_t _bytes_datagram_check; ///< Each datagram ends with the size of the datagram for
                                    ///< integrity check

  public:
    // ----- public constructors -----
    SKMBinary();
    ~SKMBinary() = default;

    // ----- convenient data access -----
    // Getters
    uint16_t        get_bytes_content() const { return _content.bytes_content; }
    uint8_t         get_sensor_system() const { return _content.sensor_system; }
    uint8_t         get_sensor_status() const { return _content.sensor_status; }
    o_sensor_format get_sensor_format() const { return _content.sensor_format; }
    uint16_t        get_number_of_samples() const { return _content.number_of_samples; }
    uint16_t get_number_of_bytes_per_sample() const { return _content.number_of_bytes_per_sample; }
    uint16_t get_sensor_data_contents() const { return _content.sensor_data_contents; }
    const std::vector<SKMSample>& get_sensor_data() const { return _sensor_data; }
    uint32_t                      get_bytes_datagram_check() const { return _bytes_datagram_check; }

    // Setters
    void set_bytes_content(uint16_t value) { _content.bytes_content = value; }
    void set_sensor_system(uint8_t value) { _content.sensor_system = value; }
    void set_sensor_status(uint8_t value) { _content.sensor_status = value; }
    void set_sensor_format(o_sensor_format value) { _content.sensor_format = value; }
    void set_number_of_samples(uint16_t value) { _content.number_of_samples = value; }
    void set_number_of_bytes_per_sample(uint16_t value)
    {
        _content.number_of_bytes_per_sample = value;
    }
    void set_sensor_data_contents(uint16_t value) { _content.sensor_data_contents = value; }
    void set_sensor_data(const std::vector<SKMSample>& data);
    void set_bytes_datagram_check(uint32_t val) { _bytes_datagram_check = val; }

    // ----- processed data access -----
    std::bitset<8> get_sensor_data_contents_bits() const;

    bool get_horizontal_position_and_velocity_active() const;
    bool get_roll_and_pitch_active() const;
    bool get_heading_active() const;
    bool get_heave_active() const;
    bool get_acceleration_active() const;
    bool get_delayed_heave1_active() const;
    bool get_delayed_heave2_active() const;

    void set_horizontal_position_and_velocity_active(bool active);
    void set_roll_and_pitch_active(bool active);
    void set_heading_active(bool active);
    void set_heave_active(bool active);
    void set_acceleration_active(bool active);
    void set_delayed_heave1_active(bool active);
    void set_delayed_heave2_active(bool active);

    // ----- operators -----
    bool operator==(const SKMBinary& other) const = default;

    //----- to/from stream functions -----
    static SKMBinary from_stream(std::istream& is, const KMALLDatagram& header);

    static SKMBinary from_stream(std::istream& is, o_KMALLDatagramIdentifier datagram_identifier);

    static SKMBinary from_stream(std::istream& is);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(SKMBinary)

  protected:
    explicit SKMBinary(const KMALLDatagram& header)
        : KMALLDatagram(header)
    {
    }
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping

extern template class themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::kmall::datagrams::SKMBinary::t_sensor_format,
    themachinethatgoesping::echosounders::kmall::datagrams::SKMBinary::t_sensor_format_values
        .size(),
    themachinethatgoesping::echosounders::kmall::datagrams::SKMBinary::t_sensor_format_values,
    themachinethatgoesping::echosounders::kmall::datagrams::SKMBinary::t_sensor_format_names,
    themachinethatgoesping::echosounders::kmall::datagrams::SKMBinary::t_sensor_format_alt_names>;