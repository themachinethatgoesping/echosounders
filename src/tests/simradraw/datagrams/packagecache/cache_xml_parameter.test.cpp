// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

#include <themachinethatgoesping/echosounders/filetemplates/datatypes/packagecachebuffer.hpp>
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_parameter_channel.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;
using themachinethatgoesping::echosounders::simradraw::datagrams::xml_datagrams::
    XML_Parameter_Channel;

#define TESTTAG "[simradraw]"

using Catch::Approx;

TEST_CASE("XML_Parameter_Channel should be usable with PackageCacheBuffer", TESTTAG)
{
    // initialize class structure
    XML_Parameter_Channel channel;

    channel.ChannelID      = "WBT Mini 261197-15 ES38-7";
    channel.ChannelMode    = 0;
    channel.PulseForm      = 0;
    channel.Frequency      = 38000;
    channel.PulseDuration  = 0.002048;
    channel.SampleInterval = 5.2E-05;
    channel.TransmitPower  = 1000;
    channel.Slope          = 0.5;

    std::unordered_map<size_t, std::string> hash_cache;

    PackageCache<XML_Parameter_Channel> package_cache(0, 0, 0, channel);

    // test packagecachebuffer
    auto channel2 = channel;
    channel2.ChannelID      = "Different ID with funny number 1234567890";

    PackageCacheBuffer<XML_Parameter_Channel> package_cache_buffer("filepath1");

    package_cache_buffer.add_package(package_cache);
    package_cache_buffer.add_package(12, 2, 3, channel2);
    package_cache_buffer.add_package(22, 2, 3, channel);
    package_cache_buffer.add_package(24, 2, 3, channel2);

    SECTION("PackageCacheBuffer: test basic access")
    {
    INFO(channel.info_string());
    INFO(package_cache_buffer.get_package(0,0,0).info_string());
    INFO("--- channel 2 ---");
    INFO(channel2.info_string());
    INFO(package_cache_buffer.get_package(12,2,3).info_string());
    REQUIRE(channel == package_cache_buffer.get_package(0,0,0));
    REQUIRE(channel2 == package_cache_buffer.get_package(12,2,3));
    REQUIRE_THROWS(package_cache_buffer.get_package(1,2,3));

    REQUIRE(package_cache_buffer.get_package_buffer().size() == 4);
    REQUIRE(package_cache_buffer.get_hash_cache().size() == 2);
    }
}

TEST_CASE("XML_Parameter_Channel should be convertible to PackageCache", TESTTAG)
{
    // initialize class structure
    XML_Parameter_Channel channel;

    channel.ChannelID      = "WBT Mini 261197-15 ES38-7";
    channel.ChannelMode    = 0;
    channel.PulseForm      = 0;
    channel.Frequency      = 38000;
    channel.PulseDuration  = 0.002048;
    channel.SampleInterval = 5.2E-05;
    channel.TransmitPower  = 1000;
    channel.Slope          = 0.5;

    std::unordered_map<size_t, std::string> hash_cache;

    PackageCache<XML_Parameter_Channel> package_cache(0, 0, 0, channel);

    // test basic access
    REQUIRE(channel == package_cache.get());

    // test to/from binary
    SECTION("PackageCache: to/from binary")
    {
    INFO(channel.info_string());
    INFO(package_cache.from_binary(package_cache.to_binary(hash_cache), hash_cache).get().info_string());
    REQUIRE(channel == package_cache.from_binary(package_cache.to_binary(hash_cache), hash_cache).get());
    REQUIRE(package_cache == package_cache.from_binary(package_cache.to_binary(hash_cache), hash_cache));
    }

}

TEST_CASE("XML_Parameter_Channel should support common functions", TESTTAG)
{
    // initialize class structure
    XML_Parameter_Channel channel;

    channel.ChannelID      = "WBT Mini 261197-15 ES38-7";
    channel.ChannelMode    = 0;
    channel.PulseForm      = 0;
    channel.Frequency      = 38000;
    channel.PulseDuration  = 0.002048;
    channel.SampleInterval = 5.2E-05;
    channel.TransmitPower  = 1000;
    channel.Slope          = 0.5;

    // test inequality
    REQUIRE(channel != XML_Parameter_Channel());

    // test equality for empty structure (this catches e.g. NAN/INF compare issues)
    REQUIRE(XML_Parameter_Channel() == XML_Parameter_Channel());

    // test copy
    INFO(channel.info_string());
    INFO(XML_Parameter_Channel(channel).info_string());
    REQUIRE(channel == XML_Parameter_Channel(channel));

    // test binary
    REQUIRE(channel == XML_Parameter_Channel::from_binary(channel.to_binary()));

    // test stream
    std::stringstream buffer;
    channel.to_stream(buffer);
    REQUIRE(channel == XML_Parameter_Channel::from_stream(buffer));

    // test print does not crash
    REQUIRE(channel.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(channel.ChannelID == "WBT Mini 261197-15 ES38-7");
    REQUIRE(channel.ChannelMode == 0);
    REQUIRE(channel.PulseForm == 0);
    REQUIRE(channel.Frequency == 38000);
    REQUIRE(channel.PulseDuration == Catch::Approx(0.002048));
    REQUIRE(channel.SampleInterval == Catch::Approx(5.2E-05));
    REQUIRE(channel.TransmitPower == 1000);
    REQUIRE(channel.Slope == Catch::Approx(0.5));
}
