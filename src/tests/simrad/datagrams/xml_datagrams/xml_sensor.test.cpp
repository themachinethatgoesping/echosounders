// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

#include "../themachinethatgoesping/echosounders/simrad/datagrams/XML0.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::echosounders::simrad::datagrams::XML0;
using themachinethatgoesping::echosounders::simrad::datagrams::xml_datagrams::XML_Sensor;

#define TESTTAG "[simrad]"

using Catch::Approx;

std::string xml_string = "'<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n<Sensor "
                         "Type=\"CableLength\" ManualValue=\"0\" IsManual=\"0\" />\x00\x00'";

TEST_CASE("XML_Sensor should support common functions", TESTTAG)
{
    // initialize class structure
    XML0 dat, dat2;
    dat.set_xml_content(xml_string);

    XML_Sensor xml1  = std::get<XML_Sensor>(dat.decode());
    XML_Sensor xml2  = xml1;
    xml2.ManualValue = 1;

    // test inequality
    REQUIRE(xml1 != xml2);

    // test equality for empty structure (this catches e.g. NAN/INF compare issues)
    REQUIRE(XML_Sensor() == XML_Sensor());

    // test copy
    xml1.print(std::cerr);
    XML_Sensor(xml1).print(std::cerr);
    REQUIRE(xml1 == XML_Sensor(xml1));
    REQUIRE(xml2 == XML_Sensor(xml2));

    // test binary
    REQUIRE(xml1 == XML_Sensor::from_binary(xml1.to_binary()));
    REQUIRE(xml2 == XML_Sensor::from_binary(xml2.to_binary()));

    // test stream
    std::stringstream buffer;
    xml1.to_stream(buffer);
    REQUIRE(xml1 == XML_Sensor::from_stream(buffer));

    // test print does not crash
    REQUIRE(xml1.info_string().size() != 0);
    REQUIRE(xml2.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(xml1.Type == "CableLength");
    REQUIRE(xml1.ManualValue == 0);
    REQUIRE(xml1.IsManual == false);
}
