// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include <fmt/format.h>

#include <themachinethatgoesping/echosounders/kmall/datagrams/ssoundvelocitytransducer.hpp>

using namespace std;
using namespace themachinethatgoesping::echosounders::kmall;
using namespace themachinethatgoesping::echosounders::kmall::datagrams;
#define TESTTAG "[kmall]"

TEST_CASE("SSoundVelocityTransducer should support common functions", TESTTAG)
{
    auto dat = SSoundVelocityTransducer();

    dat.set_datagram_version(1.1);
    dat.set_system_id(65);
    dat.set_echo_sounder_id(4096);
    dat.set_time_sec(1660000000);
    dat.set_time_nanosec(123456789);

    dat.set_sensor_status(0);
    dat.set_sensor_input_format(SSoundVelocityTransducer::o_sensor_format("AML_SV"));
    dat.set_number_of_bytes_per_sample(
        static_cast<uint16_t>(sizeof(SSoundVelocityTransducer::SVTSample)));
    dat.set_sensor_data_contents(0b1111);
    dat.set_filter_time_sec(0.5f);
    dat.set_sound_velocity_offset_m_per_sec(0.2f);

    std::vector<SSoundVelocityTransducer::SVTSample> samples = {
        { 1660000000, 111000000, 1490.0f, 4.1f, 101325.0f, 34.0f },
        { 1660000001, 222000000, 1493.0f, 4.0f, 101400.0f, 34.1f },
        { 1660000002, 333000000, 1496.0f, 3.9f, 101450.0f, 34.2f },
    };

    dat.set_sensor_data(samples);
    dat.set_number_of_samples(static_cast<uint16_t>(samples.size()));
    dat.set_bytes_datagram_check(KMALLDatagram::__size + dat.get_bytes_content());

    dat.set_sound_velocity_active(true);
    dat.set_temperature_active(true);
    dat.set_salinity_active(true);
    dat.set_pressure_active(false);

    auto expected_hash = 10173265093942083915ULL;
    CHECK(dat.binary_hash() == expected_hash);

    {
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("copy constructor: {}", SSoundVelocityTransducer(dat).info_string()));
        CHECK(dat == SSoundVelocityTransducer(dat));
    }

    {
        auto dat2 = SSoundVelocityTransducer(dat.from_binary(dat.to_binary()));
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("From binary: {}", dat2.info_string()));
        REQUIRE(dat == dat2);
        CHECK(dat2.binary_hash() == dat.binary_hash());
    }

    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == SSoundVelocityTransducer(dat.from_stream(buffer)));

    REQUIRE(dat.info_string().size() != 0);

    size_t expected_body_bytes = SSoundVelocityTransducer::__size + sizeof(uint32_t) +
                                 samples.size() * sizeof(SSoundVelocityTransducer::SVTSample);
    REQUIRE(dat.get_bytes_content() == expected_body_bytes);
    REQUIRE(dat.get_number_of_samples() == samples.size());
    REQUIRE(dat.get_sensor_input_format() == SSoundVelocityTransducer::t_sensor_format::AML_SV);
    REQUIRE(dat.get_filter_time_sec() == Catch::Approx(0.5f));
    REQUIRE(dat.get_sound_velocity_offset_m_per_sec() == Catch::Approx(0.2f));

    REQUIRE(dat.get_sound_velocity_active());
    REQUIRE(dat.get_temperature_active());
    REQUIRE_FALSE(dat.get_pressure_active());
    REQUIRE(dat.get_salinity_active());

    const auto& sensor_data = dat.get_sensor_data();
    REQUIRE(sensor_data.size() == samples.size());
    for (size_t i = 0; i < sensor_data.size(); ++i)
    {
        CHECK(sensor_data[i].time_sec == samples[i].time_sec);
        CHECK(sensor_data[i].time_nanosec == samples[i].time_nanosec);
        CHECK(sensor_data[i].soundVelocity_m_per_sec ==
              Catch::Approx(samples[i].soundVelocity_m_per_sec));
        CHECK(sensor_data[i].temp_c == Catch::Approx(samples[i].temp_c));
        CHECK(sensor_data[i].pressure_pa == Catch::Approx(samples[i].pressure_pa));
        CHECK(sensor_data[i].salinity == Catch::Approx(samples[i].salinity));
    }

    const auto timestamps   = dat.get_svt_timestamps();
    const auto velocities   = dat.get_svt_sound_velocities();
    const auto temperatures = dat.get_svt_temperatures();
    const auto pressures    = dat.get_svt_pressures();
    const auto salinities   = dat.get_svt_salinities();

    REQUIRE(timestamps.size() == samples.size());
    REQUIRE(velocities.size() == samples.size());
    REQUIRE(temperatures.size() == samples.size());
    REQUIRE(pressures.size() == samples.size());
    REQUIRE(salinities.size() == samples.size());

    for (size_t i = 0; i < samples.size(); ++i)
    {
        CHECK(timestamps[i] == Catch::Approx(samples[i].time_sec + samples[i].time_nanosec * 1e-9));
        CHECK(velocities[i] == Catch::Approx(samples[i].soundVelocity_m_per_sec));
        CHECK(temperatures[i] == Catch::Approx(samples[i].temp_c));
        CHECK(pressures[i] == Catch::Approx(samples[i].pressure_pa));
        CHECK(salinities[i] == Catch::Approx(samples[i].salinity));
    }

    REQUIRE(dat.get_datagram_identifier() ==
            t_KMALLDatagramIdentifier::S_SOUND_VELOCITY_TRANSDUCER);

    SECTION("timestamp check")
    {
        INFO(dat.info_string());
        REQUIRE(dat.get_timestamp() == Catch::Approx(1660000000.123456716));
    }

    REQUIRE(dat.get_bytes_datagram() == dat.get_bytes_datagram_check());
    CHECK(dat.binary_hash() == expected_hash);
}
