// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_all.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/simrad/datagrams/ek80_XML0.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::echosounders::simrad::datagrams::EK80_XML0;
using themachinethatgoesping::echosounders::simrad::datagrams::xml_datagrams::XML_PingSequence;

#define TESTTAG "[simrad]"

using Catch::Approx;

std::string xml_string = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\n<PingSequence>\n    <Ping "
                         "ChannelID=\"WBT 400058-15 ES333-7C_ES\" />\n</PingSequence>\x00\x00\x00";

TEST_CASE("XML_PingSequence should support common functions", TESTTAG)
{
    // initialize class structure
    EK80_XML0 dat, dat2;
    dat.set_xml_content(xml_string);

    XML_PingSequence xml1   = std::get<XML_PingSequence>(dat.decode());
    XML_PingSequence xml2   = xml1;
    xml2.Pings[0].ChannelID = "Different channel id :)";

    // test inequality
    REQUIRE(xml1 != xml2);

    // test equality for empty structure (this catches e.g. NAN/INF compare issues)
    REQUIRE(XML_PingSequence() == XML_PingSequence());

    // test copy
    xml1.print(std::cerr);
    XML_PingSequence(xml1).print(std::cerr);
    REQUIRE(xml1 == XML_PingSequence(xml1));
    REQUIRE(xml2 == XML_PingSequence(xml2));

    // test binary
    REQUIRE(xml1 == XML_PingSequence::from_binary(xml1.to_binary()));
    REQUIRE(xml2 == XML_PingSequence::from_binary(xml2.to_binary()));

    // test stream
    std::stringstream buffer;
    xml1.to_stream(buffer);
    REQUIRE(xml1 == XML_PingSequence::from_stream(buffer));

    // test print does not crash
    REQUIRE(xml1.info_string().size() != 0);
    REQUIRE(xml2.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(xml1.Pings.size() == 1);
    REQUIRE(xml1.Pings[0].ChannelID == "WBT 400058-15 ES333-7C_ES");
}
