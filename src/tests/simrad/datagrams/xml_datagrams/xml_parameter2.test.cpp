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


}