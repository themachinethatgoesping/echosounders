// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

#include "../themachinethatgoesping/echosounders/simradraw/datagrams/XML0.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::echosounders::simradraw::datagrams::XML0;
using themachinethatgoesping::echosounders::simradraw::datagrams::xml_datagrams::XML_Node;

#define TESTTAG "[simradraw]"

std::string xml_string =
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n<Environment Depth=\"200\" "
    "Acidity=\"8\" Salinity=\"20.9\" SoundSpeed=\"1473.3\" Temperature=\"10\" "
    "Latitude=\"44\" SoundVelocityProfile=\"1.000000;1473.300000;1000.000000;1473.300000\" "
    "SoundVelocitySource=\"Manual\" DropKeelOffset=\"0\" DropKeelOffsetIsManual=\"0\" "
    "WaterLevelDraft=\"0\" WaterLevelDraftIsManual=\"0\">\r\n  <Transducer "
    "TransducerName=\"Unknown\" SoundSpeed=\"1475\" />\r\n</Environment>";
std::string xml_string_2 =
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n<Parameter>\r\n  <Channel "
    "ChannelID=\"WBT Mini 261197-15 ES38-7\" ChannelMode=\"0\" PulseForm=\"0\" "
    "Frequency=\"38000\" PulseDuration=\"0.002048\" SampleInterval=\"5.2E-05\" "
    "TransmitPower=\"1000\" Slope=\"0.5\" />\r\n</Parameter>\x00\x00\x00";

TEST_CASE("XML_Node should support common functions", TESTTAG)
{
    // initialize class structure
    XML0 dat, dat2;
    dat.set_xml_content(xml_string);
    dat2.set_xml_content(xml_string_2);

    XML_Node xml1 = dat.raw();
    XML_Node xml2 = dat2.raw();

    // test inequality
    REQUIRE(xml1 != xml2);

    // test copy
    REQUIRE(xml1 == XML_Node(xml1));
    REQUIRE(xml2 == XML_Node(xml2));

    // test binary
    REQUIRE(xml1 == XML_Node(xml1.from_binary(xml1.to_binary())));
    REQUIRE(xml2 == XML_Node(xml2.from_binary(xml2.to_binary())));

    // test stream
    std::stringstream buffer;
    xml1.to_stream(buffer);
    REQUIRE(xml1 == XML_Node(xml1.from_stream(buffer)));

    // test print does not crash
    REQUIRE(xml1.info_string().size() != 0);
    REQUIRE(xml2.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(xml1.name() == "Environment");
    REQUIRE(xml1.attributes("Depth") == "200");
    REQUIRE(xml1.attributes("Acidity") == "8");
    REQUIRE(xml1.attributes("Salinity") == "20.9");
    REQUIRE(xml1.attributes("SoundSpeed") == "1473.3");
    REQUIRE(xml1.attributes("Temperature") == "10");
    REQUIRE(xml1.attributes("Latitude") == "44");
    REQUIRE(xml1.attributes("SoundVelocityProfile") ==
            "1.000000;1473.300000;1000.000000;1473.300000");
    REQUIRE(xml1.attributes("SoundVelocitySource") == "Manual");
    REQUIRE(xml1.attributes("DropKeelOffset") == "0");
    REQUIRE(xml1.attributes("DropKeelOffsetIsManual") == "0");
    REQUIRE(xml1.attributes("WaterLevelDraft") == "0");
    REQUIRE(xml1.attributes("WaterLevelDraftIsManual") == "0");
    REQUIRE(xml1.children("Transducer").size() == 1);
    REQUIRE(xml1.children("Transducer")[0].attributes("TransducerName") == "Unknown");
    REQUIRE(xml1.children("Transducer")[0].attributes("SoundSpeed") == "1475");

    REQUIRE(xml2.name() == "Parameter");
    REQUIRE(xml2.children("Channel").size() == 1);
    REQUIRE(xml2.children("Channel")[0].attributes("ChannelID") == "WBT Mini 261197-15 ES38-7");
    REQUIRE(xml2.children("Channel")[0].attributes("ChannelMode") == "0");
    REQUIRE(xml2.children("Channel")[0].attributes("PulseForm") == "0");
    REQUIRE(xml2.children("Channel")[0].attributes("Frequency") == "38000");
    REQUIRE(xml2.children("Channel")[0].attributes("PulseDuration") == "0.002048");
    REQUIRE(xml2.children("Channel")[0].attributes("SampleInterval") == "5.2E-05");
    REQUIRE(xml2.children("Channel")[0].attributes("TransmitPower") == "1000");
    REQUIRE(xml2.children("Channel")[0].attributes("Slope") == "0.5");
}
