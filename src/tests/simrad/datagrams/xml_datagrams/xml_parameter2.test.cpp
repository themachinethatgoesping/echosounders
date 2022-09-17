// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University

// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/simrad/datagrams/ek80_XML0.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::echosounders::simrad::datagrams::EK80_XML0;
using themachinethatgoesping::echosounders::simrad::datagrams::xml_datagrams::XML_InitialParameter;

#define TESTTAG "[simrad]"

using Catch::Detail::Approx;

std::string xml_string =
    "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\n<InitialParameter>\n    <Channels>\n        "
    "<Channel PingId=\"ES\" ChannelID=\"WBT 400040-15 ES38-7_ES\" ChannelMode=\"0\" "
    "PulseForm=\"0\" Frequency=\"38000\" PulseDuration=\"0.000256\" SampleInterval=\"8e-06\" "
    "TransmitPower=\"2000\" Slope=\"0.411184\" SoundVelocity=\"1484.5\" />\n        <Channel "
    "PingId=\"ES\" ChannelID=\"WBT 400050-15 ES70-7C_ES\" ChannelMode=\"0\" PulseForm=\"0\" "
    "Frequency=\"70000\" PulseDuration=\"0.000256\" SampleInterval=\"1.2e-05\" "
    "TransmitPower=\"750\" Slope=\"0.111607\" SoundVelocity=\"1484.5\" />\n        <Channel "
    "PingId=\"ES\" ChannelID=\"WBT 400051-15 ES120-7C_ES\" ChannelMode=\"0\" PulseForm=\"0\" "
    "Frequency=\"120000\" PulseDuration=\"0.000256\" SampleInterval=\"1.2e-05\" "
    "TransmitPower=\"250\" Slope=\"0.0651042\" SoundVelocity=\"1484.5\" />\n        <Channel "
    "PingId=\"ES\" ChannelID=\"WBT 400052-15 ES200-7C_ES\" ChannelMode=\"0\" PulseForm=\"0\" "
    "Frequency=\"200000\" PulseDuration=\"0.000256\" SampleInterval=\"1.2e-05\" "
    "TransmitPower=\"150\" Slope=\"0.0390625\" SoundVelocity=\"1484.5\" />\n        <Channel "
    "PingId=\"ES\" ChannelID=\"WBT 400058-15 ES333-7C_ES\" ChannelMode=\"0\" PulseForm=\"0\" "
    "Frequency=\"333000\" PulseDuration=\"0.000256\" SampleInterval=\"8e-06\" TransmitPower=\"50\" "
    "Slope=\"0.023461\" SoundVelocity=\"1484.5\" />\n    </Channels>\n</InitialParameter>\x00";

TEST_CASE( "xml_parameter2", TESTTAG )
{
    // initialize class structure
    EK80_XML0 dat, dat2;
    dat.set_xml_content(xml_string);

    XML_InitialParameter xml1  = std::get<XML_InitialParameter>(dat.decode());
    XML_InitialParameter xml2  = xml1;
    xml2.Channels[0].Frequency = 42000;

    // test inequality
    REQUIRE(xml1 != xml2);

    // test equality for empty structure (this catches e.g. NAN/INF compare issues)
    REQUIRE(XML_InitialParameter() == XML_InitialParameter());

    // test copy
    xml1.print(std::cerr);
    XML_InitialParameter(xml1).print(std::cerr);
    REQUIRE(xml1 == XML_InitialParameter(xml1));
    REQUIRE(xml2 == XML_InitialParameter(xml2));

    // test binary
    REQUIRE(xml1 == XML_InitialParameter::from_binary(xml1.to_binary()));
    REQUIRE(xml2 == XML_InitialParameter::from_binary(xml2.to_binary()));

    // test stream
    std::stringstream buffer;
    xml1.to_stream(buffer);
    REQUIRE(xml1 == XML_InitialParameter::from_stream(buffer));

    // test print does not crash
    REQUIRE(xml1.info_string().size() != 0);
    REQUIRE(xml2.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(xml1.Channels.size() == 5);
    REQUIRE(xml1.Channels[0].PingId == "ES");
    REQUIRE(xml1.Channels[0].ChannelID == "WBT 400040-15 ES38-7_ES");
    REQUIRE(xml1.Channels[0].ChannelMode == 0);
    REQUIRE(xml1.Channels[0].PulseForm == 0);
    REQUIRE(xml1.Channels[0].Frequency == 38000);
    REQUIRE(xml1.Channels[0].PulseDuration == Approx(0.000256));
    REQUIRE(xml1.Channels[0].SampleInterval == Approx(8e-06));
    REQUIRE(xml1.Channels[0].TransmitPower == 2000);
    REQUIRE(xml1.Channels[0].Slope == Approx(0.411184));
    REQUIRE(xml1.Channels[0].SoundVelocity == Approx(1484.5));

    REQUIRE(xml1.Channels[1].PingId == "ES");
    REQUIRE(xml1.Channels[1].ChannelID == "WBT 400050-15 ES70-7C_ES");
    REQUIRE(xml1.Channels[1].ChannelMode == 0);
    REQUIRE(xml1.Channels[1].PulseForm == 0);
    REQUIRE(xml1.Channels[1].Frequency == 70000);
    REQUIRE(xml1.Channels[1].PulseDuration == Approx(0.000256));
    REQUIRE(xml1.Channels[1].SampleInterval == Approx(1.2e-05));
    REQUIRE(xml1.Channels[1].TransmitPower == 750);
    REQUIRE(xml1.Channels[1].Slope == Approx(0.111607));
    REQUIRE(xml1.Channels[1].SoundVelocity == Approx(1484.5));

    REQUIRE(xml1.Channels[2].PingId == "ES");
    REQUIRE(xml1.Channels[2].ChannelID == "WBT 400051-15 ES120-7C_ES");
    REQUIRE(xml1.Channels[2].ChannelMode == 0);
    REQUIRE(xml1.Channels[2].PulseForm == 0);
    REQUIRE(xml1.Channels[2].Frequency == 120000);
    REQUIRE(xml1.Channels[2].PulseDuration == Approx(0.000256));
    REQUIRE(xml1.Channels[2].SampleInterval == Approx(1.2e-05));
    REQUIRE(xml1.Channels[2].TransmitPower == 250);
    REQUIRE(xml1.Channels[2].Slope == Approx(0.0651042));
    REQUIRE(xml1.Channels[2].SoundVelocity == Approx(1484.5));

    REQUIRE(xml1.Channels[3].PingId == "ES");
    REQUIRE(xml1.Channels[3].ChannelID == "WBT 400052-15 ES200-7C_ES");
    REQUIRE(xml1.Channels[3].ChannelMode == 0);
    REQUIRE(xml1.Channels[3].PulseForm == 0);
    REQUIRE(xml1.Channels[3].Frequency == 200000);
    REQUIRE(xml1.Channels[3].PulseDuration == Approx(0.000256));
    REQUIRE(xml1.Channels[3].SampleInterval == Approx(1.2e-05));
    REQUIRE(xml1.Channels[3].TransmitPower == 150);
    REQUIRE(xml1.Channels[3].Slope == Approx(0.0390625));
    REQUIRE(xml1.Channels[3].SoundVelocity == Approx(1484.5));

    REQUIRE(xml1.Channels[4].PingId == "ES");
    REQUIRE(xml1.Channels[4].ChannelID == "WBT 400058-15 ES333-7C_ES");
    REQUIRE(xml1.Channels[4].ChannelMode == 0);
    REQUIRE(xml1.Channels[4].PulseForm == 0);
    REQUIRE(xml1.Channels[4].Frequency == 333000);
    REQUIRE(xml1.Channels[4].PulseDuration == Approx(0.000256));
    REQUIRE(xml1.Channels[4].SampleInterval == Approx(8e-06));
    REQUIRE(xml1.Channels[4].TransmitPower == 50);
    REQUIRE(xml1.Channels[4].Slope == Approx(0.023461));
    REQUIRE(xml1.Channels[4].SoundVelocity == Approx(1484.5));

}