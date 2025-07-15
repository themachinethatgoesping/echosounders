// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/kongsbergall/datagrams/clockdatagram.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::kongsbergall::datagrams;
#define TESTTAG "[kongsbergall]"

TEST_CASE("ClockDatagram should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = ClockDatagram();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_date_external(20190423);
    dat.set_time_since_midnight_external(333727);

    // test inequality
    // REQUIRE(dat != ClockDatagram());

    // test copy
    {
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("copy constructor: {}", ClockDatagram(dat).info_string()));
        REQUIRE(dat == ClockDatagram(dat));
    }

    // test binary
    {
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("copy constructor: {}", ClockDatagram(dat).info_string()));
        REQUIRE(dat == ClockDatagram(dat.from_binary(dat.to_binary())));
    }

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == ClockDatagram(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    REQUIRE(dat.get_timestamp_external() == 1555977933.7269999981);
    REQUIRE(dat.get_timestamp_offset() == Catch::Approx(110.0));

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KongsbergAllDatagramIdentifier::ClockDatagram);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
