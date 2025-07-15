// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
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

#define TESTTAG "[simradraw]"

std::string xml1 =
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n<Environment Depth=\"200\" "
    "Acidity=\"8\" Salinity=\"20.9\" SoundSpeed=\"1473.3\" Temperature=\"10\" "
    "Latitude=\"44\" SoundVelocityProfile=\"1.000000;1473.300000;1000.000000;1473.300000\" "
    "SoundVelocitySource=\"Manual\" DropKeelOffset=\"0\" DropKeelOffsetIsManual=\"0\" "
    "WaterLevelDraft=\"0\" WaterLevelDraftIsManual=\"0\">\r\n  <Transducer "
    "TransducerName=\"Unknown\" SoundSpeed=\"1475\" />\r\n</Environment>";
std::string xml2 = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n<Parameter>\r\n  <Channel "
                   "ChannelID=\"WBT Mini 261197-15 ES38-7\" ChannelMode=\"0\" PulseForm=\"0\" "
                   "Frequency=\"38000\" PulseDuration=\"0.002048\" SampleInterval=\"5.2E-05\" "
                   "TransmitPower=\"1000\" Slope=\"0.5\" />\r\n</Parameter>\x00\x00\x00";

TEST_CASE("XML0 should support common functions", TESTTAG)
{
    // initialize class structure
    XML0 dat;

    // set some variables
    dat.set_timestamp(123);
    dat.set_xml_content(xml1);

    auto dat2 = dat;
    dat2.set_xml_content(xml2);

    // test inequality
    REQUIRE(dat != dat2);

    // test copy
    REQUIRE(dat == XML0(dat));

    // test binary
    REQUIRE(dat == XML0(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer, buffer2, buffer3;
    dat.to_stream(buffer);
    REQUIRE(dat == XML0(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(dat.get_xml_datagram_type() == "Environment");
    REQUIRE(dat2.get_xml_datagram_type() == "Parameter");

    // test get_datagram_type_from_stream()
    dat.to_stream(buffer2);
    REQUIRE(XML0::get_xml_datagram_type_from_stream(buffer2) == "Environment");
    dat2.to_stream(buffer3);
    REQUIRE(XML0::get_xml_datagram_type_from_stream(buffer3) == "Parameter");

    //--- datagram concept ---

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_SimradRawDatagramIdentifier::XML0);
    REQUIRE(dat.get_length() == 12 + int64_t(xml1.size()));
    REQUIRE(dat2.get_length() == 12 + int64_t(xml2.size()));
}
