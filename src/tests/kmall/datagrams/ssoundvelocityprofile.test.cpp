// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include <themachinethatgoesping/echosounders/kmall/datagrams/ssoundvelocityprofile.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kmall;
using namespace themachinethatgoesping::echosounders::kmall::datagrams;
#define TESTTAG "[kmall]"

TEST_CASE("SSoundVelocityProfile should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = SSoundVelocityProfile();

    // set some variables
    dat.set_datagram_version(1.2);
    dat.set_system_id(123);
    dat.set_echo_sounder_id(2040);
    dat.set_time_sec(1555977823);
    dat.set_time_nanosec(726999998);

    dat.set_bytes_content(SSoundVelocityProfile::__size +
                          3 * sizeof(SSoundVelocityProfile::SVPPoint));
    dat.set_number_of_samples(3);
    dat.set_sensor_format(SSoundVelocityProfile::o_sensor_format("sound_velocity_profile"));
    dat.set_svp_time_sec(1555977823);
    dat.set_latitude_deg(51.0543);
    dat.set_longitude_deg(3.7174);

    std::vector<SSoundVelocityProfile::SVPPoint> svp_points = {
        { 10.0f, 1492.0f, 0u, 4.1f, 34.0f },
        { 20.0f, 1498.0f, 0u, 4.0f, 34.1f },
        { 30.0f, 1502.0f, 0u, 3.9f, 34.2f },
    };
    dat.set_sensor_data(svp_points);
    dat.set_bytes_datagram_check(KMALLDatagram::__size + dat.get_bytes_content());

    CHECK(dat.binary_hash() == 17463323894861655923ULL);

    // test inequality
    // REQUIRE(dat != IOpRuntime());

    // test copy
    {
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("copy constructor: {}", SSoundVelocityProfile(dat).info_string()));
        CHECK(dat == SSoundVelocityProfile(dat));
    }

    // test binary
    {
        auto dat2 = SSoundVelocityProfile(dat.from_binary(dat.to_binary()));
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("From binary: {}", dat2.info_string()));
        REQUIRE(dat == dat2);
        CHECK(dat2.binary_hash() == dat.binary_hash());
    }

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == SSoundVelocityProfile(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    static constexpr size_t expected_body_bytes = SSoundVelocityProfile::__size + sizeof(uint32_t) +
                                                  3 * sizeof(SSoundVelocityProfile::SVPPoint);
    REQUIRE(dat.get_bytes_content() == expected_body_bytes);
    REQUIRE(dat.get_number_of_samples() == 3);
    auto sensor_format = dat.get_sensor_format();
    REQUIRE(sensor_format == SSoundVelocityProfile::t_sensor_format::sound_velocity_profile);
    REQUIRE(dat.get_latitude_deg() == Catch::Approx(51.0543));
    REQUIRE(dat.get_longitude_deg() == Catch::Approx(3.7174));

    const auto& sensor_data = dat.get_sensor_data();
    REQUIRE(sensor_data.size() == svp_points.size());
    for (size_t i = 0; i < sensor_data.size(); ++i)
    {
        CHECK(sensor_data[i].depth_m == Catch::Approx(svp_points[i].depth_m));
        CHECK(sensor_data[i].soundVelocity_m_per_sec ==
              Catch::Approx(svp_points[i].soundVelocity_m_per_sec));
        CHECK(sensor_data[i].temp_c == Catch::Approx(svp_points[i].temp_c));
        CHECK(sensor_data[i].salinity == Catch::Approx(svp_points[i].salinity));
    }

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KMALLDatagramIdentifier::S_SOUND_VELOCITY_PROFILE);

    // timestamp (unixtime)
    SECTION("timestamp check")
    {
        INFO(dat.info_string());
        REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
    }

    REQUIRE(dat.get_bytes_datagram() == dat.get_bytes_datagram_check());

    CHECK(dat.binary_hash() == 17463323894861655923ULL);
}
