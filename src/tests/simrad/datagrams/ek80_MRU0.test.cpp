// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/simrad/datagrams/ek80_MRU0.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::echosounders::simrad::datagrams::EK80_MRU0;

#define TESTTAG "[simrad]"

TEST_CASE("EK80_MRU0 should support common functions", TESTTAG)
{
    // initialize class structure
    EK80_MRU0 dat;

    // set some variables
    dat.set_timestamp(123);
    dat._Heave = 10;
    dat._Roll = 12;
    dat._Pitch = 13;
    dat._Heading = 14;

    // test inequality
    REQUIRE(dat != EK80_MRU0());

    // test copy
    REQUIRE(dat == EK80_MRU0(dat));

    // test binary
    REQUIRE(dat == EK80_MRU0(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == EK80_MRU0(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(dat.get_heave() == 10);
    REQUIRE(dat.get_roll() == 12);
    REQUIRE(dat.get_pitch() == 13);
    REQUIRE(dat.get_heading() == 14);

    //--- datagram concept ---

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_EK60_DatagramType::MRU0);
    REQUIRE(dat.get_length() == 12 + 4 *sizeof(ek60_float));

}
