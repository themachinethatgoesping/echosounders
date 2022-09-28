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
using themachinethatgoesping::echosounders::simrad::datagrams::xml_datagrams::XML_Parameter;

#define TESTTAG "[simrad]"

using Catch::Approx;

std::string xml_string =
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n<Parameter>\r\n  <Channel "
    "ChannelID=\"WBT Mini 261197-15 ES38-7\" ChannelMode=\"0\" PulseForm=\"0\" "
    "Frequency=\"38000\" PulseDuration=\"0.002048\" SampleInterval=\"5.2E-05\" "
    "TransmitPower=\"1000\" Slope=\"0.5\" />\r\n</Parameter>\x00\x00\x00";

TEST_CASE("XML_Parameter should support common functions", TESTTAG)
{
    // initialize class structure
    XML0 dat, dat2;
    dat.set_xml_content(xml_string);

    XML_Parameter xml1         = std::get<XML_Parameter>(dat.decode());
    XML_Parameter xml2         = xml1;
    xml2.Channels[0].Frequency = 42000;

    // test inequality
    REQUIRE(xml1 != xml2);

    // test equality for empty structure (this catches e.g. NAN/INF compare issues)
    REQUIRE(XML_Parameter() == XML_Parameter());

    // test copy
    xml1.print(std::cerr);
    XML_Parameter(xml1).print(std::cerr);
    REQUIRE(xml1 == XML_Parameter(xml1));
    REQUIRE(xml2 == XML_Parameter(xml2));

    // test binary
    REQUIRE(xml1 == XML_Parameter::from_binary(xml1.to_binary()));
    REQUIRE(xml2 == XML_Parameter::from_binary(xml2.to_binary()));

    // test stream
    std::stringstream buffer;
    xml1.to_stream(buffer);
    REQUIRE(xml1 == XML_Parameter::from_stream(buffer));

    // test print does not crash
    REQUIRE(xml1.info_string().size() != 0);
    REQUIRE(xml2.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(xml1.Channels.size() == 1);
    REQUIRE(xml1.Channels[0].ChannelID == "WBT Mini 261197-15 ES38-7");
    REQUIRE(xml1.Channels[0].ChannelMode == 0);
    REQUIRE(xml1.Channels[0].PulseForm == 0);
    REQUIRE(xml1.Channels[0].Frequency == 38000);
    REQUIRE(xml1.Channels[0].PulseDuration == Catch::Approx(0.002048));
    REQUIRE(xml1.Channels[0].SampleInterval == Catch::Approx(5.2E-05));
    REQUIRE(xml1.Channels[0].TransmitPower == 1000);
    REQUIRE(xml1.Channels[0].Slope == Catch::Approx(0.5));
}
