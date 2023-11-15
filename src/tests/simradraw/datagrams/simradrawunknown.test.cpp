// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/simradraw/datagrams/simradrawunknown.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::echosounders::simradraw::datagrams::SimradRawUnknown;

#define TESTTAG "[simradraw]"

TEST_CASE("SimradRawUnknown should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = SimradRawUnknown();

    dat.set_raw_content("this is raw test data :-)");

    // set some variables
    dat.set_length(simradraw_long(12 + dat.get_raw_content().size()));
    dat.set_datagram_type(simradraw_long(t_SimradRawDatagramIdentifier::XML0));
    dat.set_low_date_time(1);
    dat.set_high_date_time(2);

    // test inequality
    REQUIRE(dat != SimradRawUnknown());

    // test copy
    REQUIRE(dat == SimradRawUnknown(dat));

    // test binary
    REQUIRE(dat == SimradRawUnknown(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == SimradRawUnknown(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    // length
    REQUIRE(size_t(dat.get_length()) == 12 + dat.get_raw_content().size());

    // datagram type
    dat.set_datagram_identifier(t_SimradRawDatagramIdentifier::RAW3);
    REQUIRE(dat.get_datagram_identifier() == t_SimradRawDatagramIdentifier::RAW3);

    // timestamp (unixtime)
    dat.set_timestamp(123.123);
    REQUIRE(dat.get_timestamp() == Catch::Approx(123.123));
    REQUIRE(dat.get_high_date_time() == 27111903);
    REQUIRE(dat.get_low_date_time() == 513905712);
}
