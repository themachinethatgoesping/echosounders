// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/em3000/datagrams/pustatusoutput.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::em3000::datagrams;
#define TESTTAG "[em3000]"

TEST_CASE("PUStatusOutput should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = PUStatusOutput();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_last_received_roll(123);
    dat.set_attitude_velocity_sensor_status(100);
    dat.set_yaw_stabilization_angle(101);

    // test inequality
    // REQUIRE(dat != PUStatusOutput());

    // test copy
    REQUIRE(dat == PUStatusOutput(dat));

    // test binary
    REQUIRE(dat == PUStatusOutput(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == PUStatusOutput(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    CHECK(dat.get_last_received_roll_in_degrees() == 1.23f);
    CHECK(dat.get_attitude_velocity_sensor_status() == 'd');
    CHECK(dat.get_yaw_stabilization_angle_in_degrees() == 1.01f);

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_EM3000DatagramIdentifier::PUStatusOutput);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
