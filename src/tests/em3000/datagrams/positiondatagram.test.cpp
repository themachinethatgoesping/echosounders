// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/em3000/datagrams/positiondatagram.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::em3000::datagrams;
#define TESTTAG "[em3000]"

TEST_CASE("PositionDatagram should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = PositionDatagram();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_position_counter(101);
    dat.set_latitude(234234);
    dat.set_longitude(456456);
    dat.set_position_fix_quality(102);
    dat.set_speed_of_vessel(103);
    dat.set_course_of_vessel(104);
    dat.set_heading_of_vessel(105);

    dat.set_input_datagram("input datagram");
    dat.set_size_of_input_datagram(14);

    // test inequality
    // REQUIRE(dat != PositionDatagram());

    // test copy
    REQUIRE(dat == PositionDatagram(dat));

    // test binary
    REQUIRE(dat == PositionDatagram(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == PositionDatagram(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    CHECK(dat.get_position_counter() == 101);
    CHECK(dat.get_latitude_in_degrees() == 0.0117117);
    CHECK(dat.get_longitude_in_degrees() == Catch::Approx(0.0456456));
    CHECK(dat.get_position_fix_quality_in_meters() == 1.02f);
    CHECK(dat.get_speed_of_vessel_in_meters_per_second() == 1.03f);
    CHECK(dat.get_course_of_vessel_in_degrees() == 1.04f);
    CHECK(dat.get_heading_of_vessel_in_degrees() == 1.05f);
    CHECK(dat.get_input_datagram() == "input datagram");

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_EM3000DatagramIdentifier::PositionDatagram);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}