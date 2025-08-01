// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

#include <themachinethatgoesping/echosounders/filetemplates/datatypes/cache_structures/filepackagecache.hpp>
#include <themachinethatgoesping/echosounders/simradraw/datagrams/RAW3.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;
using themachinethatgoesping::echosounders::simradraw::datagrams::RAW3;
using namespace themachinethatgoesping::echosounders::simradraw::datagrams::raw3datatypes;

#define TESTTAG "[simradraw]"

using Catch::Approx;

// TEST_CASE("RAW3 should be usable with FilePackageCache", TESTTAG)
// {
//     // this is tested enough in cache_xml_parameter.test.cpp
// }

TEST_CASE("RAW3 should be convertible to PackageCache", TESTTAG)
{
    RAW3 dat;

    // set some variables
    dat.set_timestamp(123);
    dat.set_channel_id("channel1");

    dat.set_number_of_complex_samples(3);
    dat.set_offset(1);
    dat.set_count(20);

    auto type = t_RAW3DataType::ComplexFloat32;
    dat.set_data_type(type);

    dat.set_sample_data(RAW3DataSkipped());

    auto dat2 = dat;
    dat2.set_channel_id("channel2");

    std::unordered_map<size_t, std::string> hash_cache;

    cache_structures::PackageCache<RAW3> package_cache(0, 0, std::make_unique<RAW3>(dat));

    // test basic access
    REQUIRE(dat == package_cache.get());

    // test to/from binary
    SECTION("PackageCache: to/from binary")
    {
        REQUIRE(dat ==
                package_cache.from_binary(package_cache.to_binary(hash_cache), hash_cache).get());
        REQUIRE(package_cache ==
                package_cache.from_binary(package_cache.to_binary(hash_cache), hash_cache));
    }
}

TEST_CASE("RAW3 should support common functions", TESTTAG)
{
    // initialize class structure
    RAW3 dat;

    // set some variables
    dat.set_timestamp(123);
    dat.set_channel_id("channel1");

    dat.set_number_of_complex_samples(3);
    dat.set_offset(1);
    dat.set_count(20);

    auto type = t_RAW3DataType::ComplexFloat32;
    dat.set_data_type(type);

    auto data = xt::xtensor<simradraw_float, 3>::from_shape(
        { unsigned(dat.get_count()), dat.get_number_of_complex_samples(), 2 });
    data.fill(1.0);
    dat.set_sample_data(RAW3DataComplexFloat32(data));

    auto dat2 = dat;
    dat2.set_channel_id("channel2");

    // test inequality
    REQUIRE(dat != dat2);
    REQUIRE(dat != RAW3());

    // test empty equality (check e.g. nan compare problems)
    REQUIRE(RAW3() == RAW3());

    // test copy
    {
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("copy constructor: {}", RAW3(dat).info_string()));
        REQUIRE(dat == RAW3(dat));
    }
    {
        INFO(fmt::format("orig: {}", dat2.info_string()));
        INFO(fmt::format("copy constructor: {}", RAW3(dat2).info_string()));
        REQUIRE(dat2 == RAW3(dat2));
    }

    REQUIRE(dat == RAW3::from_binary(dat.to_binary()));
    REQUIRE(dat2 == RAW3::from_binary(dat2.to_binary()));

    // test stream
    std::stringstream buffer1, buffer2;
    dat.to_stream(buffer1);
    REQUIRE(dat == RAW3(dat.from_stream(buffer1)));

    // test reading header only
    dat.to_stream(buffer2);
    auto dat3 = RAW3::from_stream(buffer2, true);
    if (!std::holds_alternative<RAW3DataSkipped>(dat.get_sample_data()))
        REQUIRE(dat3 != dat);

    dat3.set_sample_data(dat.get_sample_data());
    REQUIRE(dat3 == dat);

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(std::string(dat.get_channel_id().substr(0, 7)) == "channel");
    REQUIRE(dat.get_data_type() == type);
    REQUIRE(dat.get_offset() == 1);
    // dat.print(std::cerr);

    // test binary
    REQUIRE(dat.get_datagram_identifier() == t_SimradRawDatagramIdentifier::RAW3);
    REQUIRE(dat.get_length() ==
            simradraw_long(12 + 140 +
                           dat.get_count() * get_raw3datatype_size(dat.get_data_type()) *
                               dat.get_number_of_complex_samples()));
}
