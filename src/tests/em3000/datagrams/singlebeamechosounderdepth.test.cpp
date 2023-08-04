// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/em3000/datagrams/singlebeamechosounderdepth.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::em3000::datagrams;
#define TESTTAG "[em3000]"

TEST_CASE("SingleBeamEchoSounderDepth should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = SingleBeamEchoSounderDepth();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_input_date(20200423);
    dat.set_input_time_since_midnight(323727);
    dat.set_echo_sounder_depth(123);

    // test inequality
    // REQUIRE(dat != SingleBeamEchoSounderDepth());

    // test copy
    {
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("copy constructor: {}", SingleBeamEchoSounderDepth(dat).info_string()));
        REQUIRE(dat == SingleBeamEchoSounderDepth(dat));
    }

    // test binary
    REQUIRE(dat == SingleBeamEchoSounderDepth(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == SingleBeamEchoSounderDepth(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    REQUIRE(dat.get_echo_sounder_depth_in_meters() == Catch::Approx(1.23));

    // datagram type
    REQUIRE(dat.get_datagram_identifier() ==
            t_EM3000DatagramIdentifier::SingleBeamEchoSounderDepth);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
    REQUIRE(dat.get_input_timestamp() == Catch::Approx(1587600323.7269999981));
}
