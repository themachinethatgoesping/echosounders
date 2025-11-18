// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include <themachinethatgoesping/echosounders/kmall/datagrams/cposition.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kmall;
using namespace themachinethatgoesping::echosounders::kmall::datagrams;
#define TESTTAG "[kmall]"

TEST_CASE("CPosition should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = CPosition();

    std::string test_text = "testvar: testval\n";

    // set some variables
    // KMALLDatagram variables
    dat.set_datagram_version(1.2);
    dat.set_system_id(123);
    dat.set_echo_sounder_id(2040);
    dat.set_time_sec(1555977823);
    dat.set_time_nanosec(726999998);

    // KMALLSensorDatagram variables
    dat.set_bytes_content(KMALLSensorDatagram::__size);
    dat.set_sensor_system(10);
    dat.set_sensor_status(2);
    dat.set_padding(0);

    // CPosition variables
    dat.set_time_from_sensor_sec(1555977823);
    dat.set_time_from_sensor_nanosec(726999998);
    dat.set_pos_fix_quality_m(1.5f);
    dat.set_corrected_lat_deg(51.0543);
    dat.set_corrected_lon_deg(3.7174);
    dat.set_speed_over_ground_m_per_sec(2.3f);
    dat.set_course_over_ground_deg(123.4f);
    dat.set_ellipsoid_height_re_ref_point_m(5.6f);
    dat.set_pos_data_from_sensor(test_text); // this should modify all size related variables

    auto expected_hash = 5505373694808156800ULL;

    {
        INFO(fmt::format("orig: {}", dat.info_string()));
        CHECK(dat.binary_hash() == expected_hash);
    }

    // test inequality
    // REQUIRE(dat != CPosition());

    // test copy
    {
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("copy constructor: {}", CPosition(dat).info_string()));
        REQUIRE(dat == CPosition(dat));
    }

    // test binary
    {
        auto dat2 = CPosition(dat.from_binary(dat.to_binary()));
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("From binary: {}", dat2.info_string()));
        REQUIRE(dat == dat2);
        CHECK(dat2.binary_hash() == dat.binary_hash());
    }

    // test stream
    {
        std::stringstream buffer;
        dat.to_stream(buffer);
        auto dat2 = CPosition(dat.from_stream(buffer));
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("From stream: {}", dat2.info_string()));
        REQUIRE(dat == dat2);
        CHECK(dat2.binary_hash() == dat.binary_hash());
    }

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    INFO(fmt::format("orig: {}", dat.info_string()));

    //REQUIRE(false);
    //--- datagram concept ---
    REQUIRE(dat.get_bytes_content() == KMALLSensorDatagram::__size);
    REQUIRE(dat.get_sensor_system() == 10);
    REQUIRE(dat.get_sensor_status() == 2);
    REQUIRE(dat.get_padding() == 0);
    REQUIRE(dat.get_sensor_timestamp() == Catch::Approx(1555977823.7269999981)); // sensor timestamp
    REQUIRE(dat.get_pos_fix_quality_m() == Catch::Approx(1.5f));
    REQUIRE(dat.get_corrected_lat_deg() == Catch::Approx(51.0543));
    REQUIRE(dat.get_corrected_lon_deg() == Catch::Approx(3.7174));
    REQUIRE(dat.get_speed_over_ground_m_per_sec() == Catch::Approx(2.3f));
    REQUIRE(dat.get_course_over_ground_deg() == Catch::Approx(123.4f));
    REQUIRE(dat.get_ellipsoid_height_re_ref_point_m() == Catch::Approx(5.6f));

    // check pos data string
    REQUIRE(dat.get_pos_data_from_sensor().substr(0, test_text.size()) == test_text);

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KMALLDatagramIdentifier::C_POSITION);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));

    REQUIRE(dat.get_bytes_datagram() == dat.get_bytes_datagram_check());
    CHECK(dat.binary_hash() == expected_hash);
}
