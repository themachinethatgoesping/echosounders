// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/em3000/datagrams/puidoutput.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::em3000::datagrams;
#define TESTTAG "[em3000]"

TEST_CASE("PUIDOutput should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = PUIDOutput();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_udp_port_no_1(123);
    dat.set_system_descriptor(100);
    REQUIRE_THROWS_AS(dat.set_pu_software_version("HALLO"), std::invalid_argument);
    dat.set_pu_software_version("There: 16 bytes!");

    // test inequality
    // REQUIRE(dat != PUIDOutput());

    // test copy
    REQUIRE(dat == PUIDOutput(dat));

    // test binary
    REQUIRE(dat == PUIDOutput(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == PUIDOutput(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    CHECK(dat.get_udp_port_no_1() == 123);
    CHECK(dat.get_system_descriptor() == 'd');
    CHECK(dat.get_pu_software_version() == "There: 16 bytes!");

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_EM3000DatagramIdentifier::PUIDOutput);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
