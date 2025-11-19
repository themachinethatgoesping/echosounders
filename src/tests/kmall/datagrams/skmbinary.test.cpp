// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <fmt/format.h>

#include <sstream>
#include <vector>

#include <themachinethatgoesping/echosounders/kmall/datagrams/skmbinary.hpp>

using namespace std;
using namespace themachinethatgoesping::echosounders::kmall;
using namespace themachinethatgoesping::echosounders::kmall::datagrams;

#define TESTTAG "[kmall]"

TEST_CASE("SKMBinary should support common functions", TESTTAG)
{
    SKMBinary dat;

    dat.set_datagram_version(1.2);
    dat.set_system_id(42);
    dat.set_echo_sounder_id(9001);
    dat.set_time_sec(1670000000);
    dat.set_time_nanosec(345678901);

    dat.set_sensor_system(3);
    dat.set_sensor_status(0b10101010);
    dat.set_sensor_format(SKMBinary::o_sensor_format("Sagem"));
    dat.set_number_of_bytes_per_sample(static_cast<uint16_t>(sizeof(SKMBinary::SKMSample)));
    dat.set_sensor_data_contents(0b1111111);

    vector<SKMBinary::SKMSample> samples(2);

    {
        auto& sample                    = samples[0];
        auto& binary                    = sample.km_binary;
        binary.datagram_identifier      = t_KMALLDatagramIdentifier::KM_BINARY;
        binary.bytes_content            = sizeof(SKMBinary::KMBinary);
        binary.dgm_version              = 5;
        binary.time_sec                 = 1670000000;
        binary.time_nanosec             = 111000000;
        binary.status                   = 0b11001100;
        binary.latitude_deg             = 63.123456;
        binary.longitude_deg            = 8.654321;
        binary.ellipsoid_height_m       = 3.5F;
        binary.roll_deg                 = 0.5F;
        binary.pitch_deg                = -0.25F;
        binary.heading_deg              = 123.0F;
        binary.heave_m                  = 0.45F;
        binary.roll_rate                = 0.01F;
        binary.pitch_rate               = -0.02F;
        binary.yaw_rate                 = 0.03F;
        binary.vel_north                = 2.5F;
        binary.vel_east                 = -0.4F;
        binary.vel_down                 = -0.2F;
        binary.latitude_error_m         = 0.12F;
        binary.longitude_error_m        = 0.18F;
        binary.ellipsoid_height_error_m = 0.25F;
        binary.roll_error_deg           = 0.05F;
        binary.pitch_error_deg          = 0.06F;
        binary.heading_error_deg        = 0.07F;
        binary.heave_error_m            = 0.08F;
        binary.north_acceleration       = 0.9F;
        binary.east_acceleration        = 0.4F;
        binary.down_acceleration        = -0.3F;

        auto& delayed           = sample.km_delayed_heave;
        delayed.time_sec        = 1670000000;
        delayed.time_nanosec    = 111000000;
        delayed.delayed_heave_m = 1.25F;
    }

    {
        auto& sample                    = samples[1];
        auto& binary                    = sample.km_binary;
        binary.datagram_identifier      = t_KMALLDatagramIdentifier::KM_BINARY;
        binary.bytes_content            = sizeof(SKMBinary::KMBinary);
        binary.dgm_version              = 6;
        binary.time_sec                 = 1670000001;
        binary.time_nanosec             = 222000000;
        binary.status                   = 0b00110011;
        binary.latitude_deg             = 64.0001;
        binary.longitude_deg            = 7.9999;
        binary.ellipsoid_height_m       = 2.25F;
        binary.roll_deg                 = -1.0F;
        binary.pitch_deg                = 0.75F;
        binary.heading_deg              = 45.0F;
        binary.heave_m                  = -0.5F;
        binary.roll_rate                = -0.03F;
        binary.pitch_rate               = 0.04F;
        binary.yaw_rate                 = -0.05F;
        binary.vel_north                = -1.5F;
        binary.vel_east                 = 0.8F;
        binary.vel_down                 = 0.2F;
        binary.latitude_error_m         = 0.2F;
        binary.longitude_error_m        = 0.15F;
        binary.ellipsoid_height_error_m = 0.3F;
        binary.roll_error_deg           = 0.04F;
        binary.pitch_error_deg          = 0.05F;
        binary.heading_error_deg        = 0.06F;
        binary.heave_error_m            = 0.09F;
        binary.north_acceleration       = -0.7F;
        binary.east_acceleration        = 0.2F;
        binary.down_acceleration        = 0.1F;

        auto& delayed           = sample.km_delayed_heave;
        delayed.time_sec        = 1670000001;
        delayed.time_nanosec    = 222000000;
        delayed.delayed_heave_m = -0.85F;
    }

    dat.set_sensor_data(samples);
    dat.set_number_of_samples(static_cast<uint16_t>(samples.size()));
    dat.set_bytes_datagram_check(KMALLDatagram::__size + dat.get_bytes_content());

    const auto expected_hash = 5674553155652528342ULL;
    CHECK(dat.binary_hash() == expected_hash);

    {
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("copy constructor: {}", SKMBinary(dat).info_string()));
        CHECK(dat == SKMBinary(dat));
    }

    {
        auto dat2 = SKMBinary(dat.from_binary(dat.to_binary()));
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("from binary: {}", dat2.info_string()));
        REQUIRE(dat == dat2);
        CHECK(dat2.binary_hash() == expected_hash);
    }

    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == SKMBinary(dat.from_stream(buffer)));

    REQUIRE_FALSE(dat.info_string().empty());

    const size_t expected_body_bytes =
        SKMBinary::__size + sizeof(uint32_t) + samples.size() * sizeof(SKMBinary::SKMSample);
    REQUIRE(dat.get_bytes_content() == expected_body_bytes);
    REQUIRE(dat.get_number_of_samples() == samples.size());
    REQUIRE(dat.get_sensor_format() == SKMBinary::t_sensor_format::Sagem);
    REQUIRE(dat.get_sensor_system() == 3);
    REQUIRE(dat.get_sensor_status() == 0b10101010);
    REQUIRE(dat.get_bytes_datagram() == dat.get_bytes_datagram_check());

    const auto& sensor_data = dat.get_sensor_data();
    REQUIRE(sensor_data.size() == samples.size());

    for (size_t i = 0; i < sensor_data.size(); ++i)
    {
        INFO(fmt::format("sample[{}]", i));
        const auto& original = samples[i];
        const auto& restored = sensor_data[i];

        CHECK(restored.km_binary.datagram_identifier == original.km_binary.datagram_identifier);
        CHECK(restored.km_binary.time_sec == original.km_binary.time_sec);
        CHECK(restored.km_binary.time_nanosec == original.km_binary.time_nanosec);
        CHECK(restored.km_binary.status == original.km_binary.status);
        CHECK(restored.km_binary.latitude_deg == Catch::Approx(original.km_binary.latitude_deg));
        CHECK(restored.km_binary.longitude_deg == Catch::Approx(original.km_binary.longitude_deg));
        CHECK(restored.km_binary.roll_deg == Catch::Approx(original.km_binary.roll_deg));
        CHECK(restored.km_binary.pitch_deg == Catch::Approx(original.km_binary.pitch_deg));
        CHECK(restored.km_binary.heading_deg == Catch::Approx(original.km_binary.heading_deg));
        CHECK(restored.km_binary.heave_m == Catch::Approx(original.km_binary.heave_m));
        CHECK(restored.km_binary.vel_north == Catch::Approx(original.km_binary.vel_north));
        CHECK(restored.km_binary.vel_east == Catch::Approx(original.km_binary.vel_east));
        CHECK(restored.km_binary.vel_down == Catch::Approx(original.km_binary.vel_down));

        CHECK(restored.km_delayed_heave.time_sec == original.km_delayed_heave.time_sec);
        CHECK(restored.km_delayed_heave.time_nanosec == original.km_delayed_heave.time_nanosec);
        CHECK(restored.km_delayed_heave.delayed_heave_m ==
              Catch::Approx(original.km_delayed_heave.delayed_heave_m));
    }

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KMALLDatagramIdentifier::S_KM_BINARY);
    CHECK(dat.binary_hash() == expected_hash);

    SECTION("status flag helpers should reflect bitfield state")
    {
        SKMBinary flags;
        flags.set_sensor_data_contents(0);

        auto expect_bits = [&](uint16_t value) {
            CHECK(flags.get_sensor_data_contents() == value);
        };

        CHECK_FALSE(flags.get_horizontal_position_and_velocity_active());
        CHECK_FALSE(flags.get_roll_and_pitch_active());
        CHECK_FALSE(flags.get_heading_active());
        CHECK_FALSE(flags.get_heave_active());
        CHECK_FALSE(flags.get_acceleration_active());
        CHECK_FALSE(flags.get_delayed_heave1_active());
        CHECK_FALSE(flags.get_delayed_heave2_active());

        flags.set_horizontal_position_and_velocity_active(true);
        CHECK(flags.get_horizontal_position_and_velocity_active());
        expect_bits(0b0000001);

        flags.set_roll_and_pitch_active(true);
        CHECK(flags.get_roll_and_pitch_active());
        expect_bits(0b0000011);

        flags.set_heading_active(true);
        CHECK(flags.get_heading_active());
        expect_bits(0b0000111);

        flags.set_heave_active(true);
        CHECK(flags.get_heave_active());
        expect_bits(0b0001111);

        flags.set_acceleration_active(true);
        CHECK(flags.get_acceleration_active());
        expect_bits(0b0011111);

        flags.set_delayed_heave1_active(true);
        CHECK(flags.get_delayed_heave1_active());
        expect_bits(0b0111111);

        flags.set_delayed_heave2_active(true);
        CHECK(flags.get_delayed_heave2_active());
        expect_bits(0b1111111);

        flags.set_heading_active(false);
        CHECK_FALSE(flags.get_heading_active());
        expect_bits(0b1111011);

        flags.set_delayed_heave2_active(false);
        CHECK_FALSE(flags.get_delayed_heave2_active());
        expect_bits(0b0111011);
    }

    CHECK(dat.binary_hash() == expected_hash);
}
