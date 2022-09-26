// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/simrad/datagrams/ek60_unknown.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::echosounders::simrad::datagrams::EK60_Unknown;

#define TESTTAG "[simrad]"

TEST_CASE("EK60_Unknown should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = EK60_Unknown();

    dat.raw_content = "this is raw test data :-)";

    // set some variables
    dat._Length       = 12 + dat.raw_content.size();
    dat._DatagramType = ek60_long(t_EK60_DatagramType::XML0);
    dat._LowDateTime  = 1;
    dat._HighDateTime = 2;

    // test inequality
    REQUIRE(dat != EK60_Unknown());

    // test copy
    REQUIRE(dat == EK60_Unknown(dat));

    // test binary
    REQUIRE(dat == EK60_Unknown(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == EK60_Unknown(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    // length
    REQUIRE(size_t(dat.get_length()) == 12 + dat.raw_content.size());

    // datagram type
    dat.set_datagram_identifier(t_EK60_DatagramType::RAW3);
    REQUIRE(dat.get_datagram_identifier() == t_EK60_DatagramType::RAW3);

    // timestamp (unixtime)
    dat.set_timestamp(123.123);
    REQUIRE(dat.get_timestamp() == Catch::Approx(123.123));
    REQUIRE(dat._HighDateTime == 27111903);
    REQUIRE(dat._LowDateTime == 513905712);
}
