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


TEST_CASE("EK60_Datagram static functions", TESTTAG)
{
    SECTION("DatagramTypeAsString should be reversible")
    {
        REQUIRE(datagram_type_to_string(datagram_type_from_string("XML0")) == "XML0");
        REQUIRE(datagram_type_to_string(datagram_type_from_string("FIL1")) == "FIL1");
    }
}