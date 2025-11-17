// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include <themachinethatgoesping/echosounders/kmall/datagrams/spositionerror.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kmall;
using namespace themachinethatgoesping::echosounders::kmall::datagrams;
#define TESTTAG "[kmall]"

TEST_CASE("SPositionError should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = SPositionError();

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

    // SPositionError variables
    dat.set_time_from_sensor_sec(1555977823);
    dat.set_time_from_sensor_nanosec(726999998);
    dat.set_range_input_rms(0.42f);
    dat.set_ellipse_semi_major_axis_error_m(1.2f);
    dat.set_ellipse_semi_minor_axis_error_m(0.8f);
    dat.set_ellipse_erientation_error_deg(5.5f);
    dat.set_latitude_error_m(0.15f);
    dat.set_longitude_error_m(0.22f);
    dat.set_height_error_m(0.33f);
    dat.set_pos_error_data_from_sensor(test_text); // this should modify all size related variables

    {
        INFO(fmt::format("orig: {}", dat.info_string()));
        CHECK(dat.binary_hash() == 14487886261973624592ULL);
    }

    // test inequality
    // REQUIRE(dat != SPosition());

    // test copy
    {
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("copy constructor: {}", SPositionError(dat).info_string()));
        REQUIRE(dat == SPositionError(dat));
    }

    // test binary
    {
        auto dat2 = SPositionError(dat.from_binary(dat.to_binary()));
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("From binary: {}", dat2.info_string()));
        REQUIRE(dat == dat2);
        CHECK(dat2.binary_hash() == dat.binary_hash());
    }

    // test stream
    {
        std::stringstream buffer;
        dat.to_stream(buffer);
        auto dat2 = SPositionError(dat.from_stream(buffer));
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
    REQUIRE(dat.get_range_input_rms() == Catch::Approx(0.42f));
    REQUIRE(dat.get_ellipse_semi_major_axis_error_m() == Catch::Approx(1.2f));
    REQUIRE(dat.get_ellipse_semi_minor_axis_error_m() == Catch::Approx(0.8f));
    REQUIRE(dat.get_ellipse_erientation_error_deg() == Catch::Approx(5.5f));
    REQUIRE(dat.get_latitude_error_m() == Catch::Approx(0.15f));
    REQUIRE(dat.get_longitude_error_m() == Catch::Approx(0.22f));
    REQUIRE(dat.get_height_error_m() == Catch::Approx(0.33f));

    // check pos data string
    REQUIRE(dat.get_pos_error_data_from_sensor().substr(0, test_text.size()) == test_text);

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KMALLDatagramIdentifier::S_POSITION_ERROR);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));

    REQUIRE(dat.get_bytes_datagram() == dat.get_bytes_datagram_check());
    CHECK(dat.binary_hash() == 14487886261973624592ULL);
}
