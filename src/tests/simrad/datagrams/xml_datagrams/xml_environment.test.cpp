// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/simrad/datagrams/ek80_XML0.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::echosounders::simrad::datagrams::EK80_XML0;
using themachinethatgoesping::echosounders::simrad::datagrams::xml_datagrams::XML_Environment;

#define TESTTAG "[simrad]"

using Catch::Detail::Approx;

std::string xml_string =
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n<Environment Depth=\"200\" "
    "Acidity=\"8\" Salinity=\"20.9\" SoundSpeed=\"1473.3\" Temperature=\"10\" "
    "Latitude=\"44\" SoundVelocityProfile=\"1.000000;1473.300000;1000.000000;1473.300000\" "
    "SoundVelocitySource=\"Manual\" DropKeelOffset=\"0\" DropKeelOffsetIsManual=\"0\" "
    "WaterLevelDraft=\"0\" WaterLevelDraftIsManual=\"0\">\r\n  <Transducer "
    "TransducerName=\"Unknown\" SoundSpeed=\"1475\" />\r\n</Environment>";

TEST_CASE("XML_Environment should support common functions", TESTTAG)
{
    // initialize class structure
    EK80_XML0 dat, dat2;
    dat.set_xml_content(xml_string);

    XML_Environment xml1 = std::get<XML_Environment>(dat.decode());
    XML_Environment xml2 = xml1;
    xml2.SoundSpeed = 1500;

    // test inequality
    REQUIRE(xml1 != xml2);

    // test equality for empty structure (this catches e.g. NAN/INF compare issues)
    REQUIRE(XML_Environment() == XML_Environment());

    // test copy
    xml1.print(std::cerr);
    XML_Environment(xml1).print(std::cerr);
    REQUIRE(xml1 == XML_Environment(xml1));
    REQUIRE(xml2 == XML_Environment(xml2));

    // test binary
    REQUIRE(xml1 == XML_Environment::from_binary(xml1.to_binary()));
    REQUIRE(xml2 == XML_Environment::from_binary(xml2.to_binary()));

    // test stream
    std::stringstream buffer;
    xml1.to_stream(buffer);
    REQUIRE(xml1 == XML_Environment::from_stream(buffer));

    // test print does not crash
    REQUIRE(xml1.info_string().size() != 0);
    REQUIRE(xml2.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(xml1.Depth == 200);
    REQUIRE(xml1.Acidity == 8);
    REQUIRE(xml1.Salinity == Approx(20.9));
    REQUIRE(xml1.SoundSpeed == Approx(1473.3));
    REQUIRE(xml1.Temperature == 10);
    REQUIRE(xml1.Latitude == 44);
    REQUIRE(xml1.SoundVelocityProfile.size() == 4);
    REQUIRE(xml1.SoundVelocityProfile[0] == Approx(1.0));
    REQUIRE(xml1.SoundVelocityProfile[1] == Approx(1473.3));
    REQUIRE(xml1.SoundVelocityProfile[2] == Approx(1000.0));
    REQUIRE(xml1.SoundVelocityProfile[3] == Approx(1473.3));
    REQUIRE(xml1.SoundVelocitySource == "Manual");
    REQUIRE(xml1.DropKeelOffset == 0);
    REQUIRE(xml1.DropKeelOffsetIsManual == 0);
    REQUIRE(xml1.WaterLevelDraft == 0);
    REQUIRE(xml1.WaterLevelDraftIsManual == 0);
    REQUIRE(xml1.Transducer.TransducerName == "Unknown");
    REQUIRE(xml1.Transducer.SoundSpeed == 1475);

}