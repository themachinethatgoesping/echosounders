// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

#include "../themachinethatgoesping/echosounders/simradraw/datagrams/TAG0.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::echosounders::simradraw::datagrams::TAG0;

#define TESTTAG "[simradraw]"

TEST_CASE("TAG0 should support common functions", TESTTAG)
{
    // initialize class structure
    TAG0 dat("Hello");

    // set some variables
    dat.set_timestamp(123);

    auto dat2 = dat;
    dat2.set_text("Bye");

    // test inequality
    REQUIRE(dat != dat2);

    // test empty equality (check e.g. nan compare problems)
    REQUIRE(TAG0() == TAG0());

    // test copy
    REQUIRE(dat == TAG0(dat));
    REQUIRE(dat2 == TAG0(dat2));

    // test binary
    REQUIRE(dat == TAG0::from_binary(dat.to_binary()));
    REQUIRE(dat2 == TAG0::from_binary(dat2.to_binary()));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == TAG0::from_stream(buffer));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);
    REQUIRE(dat2.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(dat.get_text() == "Hello");
    REQUIRE(dat2.get_text() == "Bye");

    //--- datagram concept ---

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_SimradRawDatagramIdentifier::TAG0);
    REQUIRE(dat.get_length() == 12 + 5);
    REQUIRE(dat2.get_length() == 12 + 3);
}
