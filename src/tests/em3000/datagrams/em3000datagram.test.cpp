// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/em3000/datagrams/em3000datagram.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::em3000;
using themachinethatgoesping::echosounders::em3000::datagrams::EM3000Datagram;

#define TESTTAG "[em3000]"

TEST_CASE("EM3000Datagram should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = EM3000Datagram();

    // set some variables
    dat.set_bytes(100);
    dat.set_datagram_identifier(t_EM3000DatagramIdentifier::WaterColumnDatagram);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    // test inequality
    REQUIRE(dat != EM3000Datagram());

    // test copy
    REQUIRE(dat == EM3000Datagram(dat));

    // test binary
    REQUIRE(dat == EM3000Datagram(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == EM3000Datagram(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    // length
    REQUIRE(dat.get_bytes() == 100);
    dat.set_bytes(123);
    REQUIRE(dat.get_bytes() == 123);

    // datagram type
    dat.set_datagram_identifier(t_EM3000DatagramIdentifier::RawRangeAndAngle);
    REQUIRE(dat.get_datagram_identifier() == t_EM3000DatagramIdentifier::RawRangeAndAngle);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
