// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/simrad/datagrams/ek60_datagram.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::echosounders::simrad::datagrams::EK60_Datagram;

#define TESTTAG "[simrad]"

TEST_CASE("EK60_Datagram should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = EK60_Datagram();

    // set some variables
    dat._Length       = 100;
    dat._DatagramType = ek60_long(t_EK60_DatagramType::XML0);
    dat._LowDateTime  = 1;
    dat._HighDateTime = 2;

    // test inequality
    REQUIRE(dat != EK60_Datagram());

    // test copy
    REQUIRE(dat == EK60_Datagram(dat));

    // test binary
    REQUIRE(dat == EK60_Datagram(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == EK60_Datagram(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    // length
    REQUIRE(dat.get_length() == 100);
    dat.set_length(123);
    REQUIRE(dat.get_length() == 123);

    // datagram type
    dat.set_datagram_identifier(t_EK60_DatagramType::RAW3);
    REQUIRE(dat.get_datagram_identifier() == t_EK60_DatagramType::RAW3);

    // timestamp (unixtime)
    dat.set_timestamp(123.123);
    REQUIRE(dat.get_timestamp() == Approx(123.123));
    REQUIRE(dat._HighDateTime == 27111903);
    REQUIRE(dat._LowDateTime == 513905712);
}
