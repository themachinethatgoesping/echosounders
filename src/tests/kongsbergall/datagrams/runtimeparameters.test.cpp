// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/kongsbergall/datagrams/runtimeparameters.hpp"
#include <themachinethatgoesping/echosounders/filetemplates/datatypes/cache_structures/filepackagecache.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::kongsbergall::datagrams;
#define TESTTAG "[kongsbergall]"

TEST_CASE("RuntimeParameters should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = RuntimeParameters();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_absorption_coefficient(123);
    dat.set_mode(100);
    dat.set_receive_bandwidth_50hz(101);

    // test inequality
    // REQUIRE(dat != RuntimeParameters());

    // test copy
    REQUIRE(dat == RuntimeParameters(dat));

    // test binary
    REQUIRE(dat == RuntimeParameters(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == RuntimeParameters(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    CHECK(dat.get_absorption_coefficient_in_db_per_meter() == Catch::Approx(0.00123f));
    CHECK(dat.get_mode() == 'd');
    CHECK(dat.get_receive_bandwidth_in_hertz() == 5050.f);

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KongsbergAllDatagramIdentifier::RuntimeParameters);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}

TEST_CASE("RuntimeParameters should be convertible to PackageCache", TESTTAG)
{
    using themachinethatgoesping::echosounders::filetemplates::datatypes::cache_structures::
        PackageCache;

    // initialize class structure
    auto dat = RuntimeParameters();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_absorption_coefficient(123);
    dat.set_mode(100);
    dat.set_receive_bandwidth_50hz(101);

    std::unordered_map<size_t, std::string> hash_cache;

    PackageCache<RuntimeParameters> package_cache(0, 0, std::make_unique<RuntimeParameters>(dat));

    // test basic access
    REQUIRE(dat == package_cache.get());

    // test to/from binary
    SECTION("PackageCache: to/from binary")
    {
        INFO(dat.info_string());
        INFO(package_cache.from_binary(package_cache.to_binary(hash_cache), hash_cache)
                 .get()
                 .info_string());
        REQUIRE(dat ==
                package_cache.from_binary(package_cache.to_binary(hash_cache), hash_cache).get());
        REQUIRE(package_cache ==
                package_cache.from_binary(package_cache.to_binary(hash_cache), hash_cache));
    }
}
