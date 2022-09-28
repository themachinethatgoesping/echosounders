// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

#include "../themachinethatgoesping/echosounders/simrad/datagrams/MRU0.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::echosounders::simrad::datagrams::MRU0;

#define TESTTAG "[simrad]"

TEST_CASE("MRU0 should support common functions", TESTTAG)
{
    // initialize class structure
    MRU0 dat;

    // set some variables
    dat.set_timestamp(123);
    dat._Heave   = 10;
    dat._Roll    = 12;
    dat._Pitch   = 13;
    dat._Heading = 14;

    auto dat2     = dat;
    dat2._Heading = 15;

    // test inequality
    REQUIRE(dat != dat2);

    // test empty equality (check e.g. nan compare problems)
    REQUIRE(MRU0() == MRU0());

    // test copy
    REQUIRE(dat == MRU0(dat));

    // test binary
    REQUIRE(dat == MRU0(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == MRU0(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(dat.get_heave() == 10);
    REQUIRE(dat.get_roll() == 12);
    REQUIRE(dat.get_pitch() == 13);
    REQUIRE(dat.get_heading() == 14);

    //--- datagram concept ---

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_SimradDatagramType::MRU0);
    REQUIRE(dat.get_length() == 12 + 4 * sizeof(simrad_float));
}
