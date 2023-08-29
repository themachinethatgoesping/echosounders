// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/em3000/datagrams/em3000unknown.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::em3000;
using themachinethatgoesping::echosounders::em3000::datagrams::EM3000Unknown;

#define TESTTAG "[em3000]"

TEST_CASE("EM3000Unknown should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = EM3000Unknown();

    // set some variables
    dat.set_bytes(100);
    dat.set_datagram_identifier(t_EM3000DatagramIdentifier::WatercolumnDatagram);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);
    dat.set_raw_content("this is raw test data :-)");
    dat.set_etx(0x03);

    // test inequality
    REQUIRE(dat != EM3000Unknown());

    // test copy
    REQUIRE(dat == EM3000Unknown(dat));

    // test binary
    REQUIRE(dat == EM3000Unknown(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == EM3000Unknown(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(size_t(dat.get_bytes()) == 15 + dat.get_raw_content().size());
    // length
    REQUIRE(dat.get_bytes() == 40); /// the length was corrected when writing to binary
    dat.set_bytes(123);
    REQUIRE(dat.get_bytes() == 123);

    // datagram type
    dat.set_datagram_identifier(t_EM3000DatagramIdentifier::RawRangeAndAngle);
    REQUIRE(dat.get_datagram_identifier() == t_EM3000DatagramIdentifier::RawRangeAndAngle);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
