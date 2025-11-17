// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/soundvelocityprofile.doc.hpp"

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
class SoundVelocityProfile : public KMALLDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KMALLDatagramIdentifier::S_SOUND_VELOCITY_PROFILE;
    static constexpr size_t __size           = 28; // size till _sensor_data

    enum class t_sensor_format : uint32_t
    {
        sound_velocity_profile = std::bit_cast<uint32_t>("S00"),
        ctd_profile            = std::bit_cast<uint32_t>("S01"),
    };

    static constexpr std::array<t_sensor_format, 2> t_sensor_format_values = {
        t_sensor_format::sound_velocity_profile,
        t_sensor_format::ctd_profile,
    };

    static constexpr std::array<std::string_view, 2> t_sensor_format_names = {
        "sound_velocity_profile",
        "ctd_profile",
    };

    static constexpr std::array<std::string_view, 2> t_sensor_format_alt_names = {
        "S00",
        "S01",
    };

    using o_sensor_format =
        themachinethatgoesping::tools::classhelper::OptionFrozen<t_sensor_format,
                                                                 t_sensor_format_values.size(),
                                                                 t_sensor_format_values,
                                                                 t_sensor_format_names,
                                                                 t_sensor_format_alt_names>;

#pragma pack(push, 4) // force 4-byte alignment
    struct SVPPoint
    {
        float    depth_m;
        float    soundVelocity_m_per_sec;
        uint32_t padding;
        float    temp_c;
        float    salinity;

        bool operator==(const SVPPoint& other) const = default;

        tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                      bool         superscript_exponents) const;
    };
#pragma pack(pop)

  protected:
#pragma pack(push, 4) // force 4-byte alignment
    struct Content
    {
        uint16_t        bytes_content;
        uint16_t        number_of_samples;
        o_sensor_format sensor_format;
        uint32_t        svp_time_sec;
        double          latitude_deg;
        double          longitude_deg;

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    std::vector<SVPPoint> _sensor_data;
    uint32_t _bytes_datagram_check; ///< Each datagram ends with the size of the datagram for
                                    ///< integrity check

  public:
    // ----- public constructors -----
    SoundVelocityProfile();
    ~SoundVelocityProfile() = default;

    // ----- convenient data access -----
    // Getters
    uint16_t        get_bytes_content() const { return _content.bytes_content; }
    uint16_t        get_number_of_samples() const { return _content.number_of_samples; }
    o_sensor_format get_sensor_format() const { return _content.sensor_format; }
    uint32_t        get_svp_time_sec() const { return _content.svp_time_sec; }
    double          get_latitude_deg() const { return _content.latitude_deg; }
    double          get_longitude_deg() const { return _content.longitude_deg; }
    const std::vector<SVPPoint>& get_sensor_data() const { return _sensor_data; }
    uint32_t                     get_bytes_datagram_check() const { return _bytes_datagram_check; }

    // Setters
    void set_bytes_content(uint16_t value) { _content.bytes_content = value; }
    void set_number_of_samples(uint16_t value) { _content.number_of_samples = value; }
    void set_sensor_format(o_sensor_format value) { _content.sensor_format = value; }
    void set_svp_time_sec(uint32_t value) { _content.svp_time_sec = value; }
    void set_latitude_deg(double value) { _content.latitude_deg = value; }
    void set_longitude_deg(double value) { _content.longitude_deg = value; }
    void set_sensor_data(const std::vector<SVPPoint>& data);
    void set_bytes_datagram_check(uint32_t val) { _bytes_datagram_check = val; }

    // ----- processed data access -----
    std::vector<float> get_svp_depths() const;
    std::vector<float> get_svp_sound_velocities() const;
    std::vector<float> get_svp_sound_velocities_computed() const;
    std::vector<float> get_svp_absorption_computed(float frequency, float ph = 8) const;
    std::vector<float> get_svp_salinities() const;
    std::vector<float> get_svp_temperatures() const;

    // ----- operators -----
    bool operator==(const SoundVelocityProfile& other) const = default;

    //----- to/from stream functions -----
    static SoundVelocityProfile from_stream(std::istream& is, const KMALLDatagram& header);

    static SoundVelocityProfile from_stream(std::istream&             is,
                                            o_KMALLDatagramIdentifier datagram_identifier);

    static SoundVelocityProfile from_stream(std::istream& is);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(SoundVelocityProfile)

  protected:
    explicit SoundVelocityProfile(const KMALLDatagram& header)
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
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityProfile::t_sensor_format,
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityProfile::
        t_sensor_format_values.size(),
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityProfile::
        t_sensor_format_values,
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityProfile::
        t_sensor_format_names,
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityProfile::
        t_sensor_format_alt_names>;