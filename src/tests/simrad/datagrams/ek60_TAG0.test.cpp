// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/simrad/datagrams/ek60_TAG0.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::echosounders::simrad::datagrams::EK60_TAG0;

#define TESTTAG "[simrad]"

TEST_CASE("EK60_TAG0 should support common functions", TESTTAG)
{
    // initialize class structure
    EK60_TAG0 dat("Hello");

    // set some variables
    dat.set_timestamp(123);

    auto dat2 = dat;
    dat2.set_text("Bye");

    // test inequality
    REQUIRE(dat != dat2);

    // test empty equality (check e.g. nan compare problems)
    REQUIRE(EK60_TAG0() == EK60_TAG0());

    // test copy
    REQUIRE(dat == EK60_TAG0(dat));
    REQUIRE(dat2 == EK60_TAG0(dat2));

    // test binary
    REQUIRE(dat == EK60_TAG0::from_binary(dat.to_binary()));
    REQUIRE(dat2 == EK60_TAG0::from_binary(dat2.to_binary()));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == EK60_TAG0::from_stream(buffer));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);
    REQUIRE(dat2.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(dat.get_text() == "Hello");
    REQUIRE(dat2.get_text() == "Bye");

    //--- datagram concept ---

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_EK60_DatagramType::TAG0);
    REQUIRE(dat.get_length() == 12 + 5);
    REQUIRE(dat2.get_length() == 12 + 3);
}
