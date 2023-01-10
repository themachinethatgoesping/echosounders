// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/simrad/datagrams/simraddatagram.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::echosounders::simrad::datagrams::SimradDatagram;

#define TESTTAG "[simrad]"

TEST_CASE("SimradDatagram should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = SimradDatagram();

    // set some variables
    dat._Length       = 100;
    dat._DatagramType = simrad_long(t_SimradDatagramIdentifier::XML0);
    dat._LowDateTime  = 1;
    dat._HighDateTime = 2;

    // test inequality
    REQUIRE(dat != SimradDatagram());

    // test copy
    REQUIRE(dat == SimradDatagram(dat));

    // test binary
    REQUIRE(dat == SimradDatagram(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == SimradDatagram(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    // length
    REQUIRE(dat.get_length() == 100);
    dat.set_length(123);
    REQUIRE(dat.get_length() == 123);

    // datagram type
    dat.set_datagram_identifier(t_SimradDatagramIdentifier::RAW3);
    REQUIRE(dat.get_datagram_identifier() == t_SimradDatagramIdentifier::RAW3);

    // timestamp (unixtime)
    dat.set_timestamp(123.123);
    REQUIRE(dat.get_timestamp() == Catch::Approx(123.123));
    REQUIRE(dat._HighDateTime == 27111903);
    REQUIRE(dat._LowDateTime == 513905712);
}
