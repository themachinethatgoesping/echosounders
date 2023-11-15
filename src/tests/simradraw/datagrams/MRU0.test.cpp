// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

#include "../themachinethatgoesping/echosounders/simradraw/datagrams/MRU0.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::echosounders::simradraw::datagrams::MRU0;

#define TESTTAG "[simradraw]"

TEST_CASE("MRU0 should support common functions", TESTTAG)
{
    // initialize class structure
    MRU0 dat;

    // set some variables
    dat.set_timestamp(123);
    dat.set_heave(10);
    dat.set_roll(12);
    dat.set_pitch(13);
    dat.set_heading(14);

    auto dat2 = dat;
    dat2.set_heading(15);

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
    REQUIRE(dat.get_datagram_identifier() == t_SimradRawDatagramIdentifier::MRU0);
    REQUIRE(dat.get_length() == 12 + 4 * sizeof(simradraw_float));
}
