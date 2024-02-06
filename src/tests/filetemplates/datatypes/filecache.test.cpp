// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <xtensor/xtensor.hpp>

#include <themachinethatgoesping/echosounders/kongsbergall/datagrams.hpp>
#include <themachinethatgoesping/echosounders/kongsbergall/types.hpp>
#include <themachinethatgoesping/echosounders/simradraw/datagrams.hpp>
#include <themachinethatgoesping/echosounders/simradraw/types.hpp>

// note: this must be defined below the kongsbergall/simradraw includes otherwise
// datagram_identifier_to_string is unknown
#include <themachinethatgoesping/echosounders/filetemplates/datatypes/filecache.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;
using namespace themachinethatgoesping::echosounders;
#define TESTTAG "[filetemplates]"

std::string test_data_path =
    std::string(UNITTEST_DATA_DIR) + "/filetemplates/datatypes/filecache.test/";

auto test_data_file_0     = test_data_path + "filecache.test.data.0";     // empty file
auto test_data_file_valid = test_data_path + "filecache.test.data.valid"; // file with valid content
auto test_data_file_invalid =
    test_data_path + "filecache.test.data.invalid"; // file with random text
auto test_data_file_invalid_file_name =
    test_data_path +
    "filecache.test.data.invalid_file_name"; // file with wrong associated file name
auto test_data_file_invalid_file_size =
    test_data_path +
    "filecache.test.data.invalid_file_size"; // file with wrong associated file size
auto test_data_file_wrongversion =
    test_data_path + "filecache.test.data.wrongversion"; // file with wrong FileCache version
auto test_data_file_tmp =
    test_data_path + "filecache.test.data.tmp"; // temporary file that will be created

// static test datagram for testing the FileCache
auto get_test_datagram()
{
    simradraw::datagrams::MRU0 test_datagram;
    test_datagram.set_timestamp(123);
    test_datagram.set_heave(10);
    test_datagram.set_roll(12);
    test_datagram.set_pitch(13);
    test_datagram.set_heading(14);

    return test_datagram;
}


TEST_CASE("FileCache should be able to create files but not overwrite existing non-FileCache files",
          TESTTAG)
{
    auto test_datagram = get_test_datagram();

    INFO("Test data path: " << test_data_path);
    // test if test_data/filecache.test.data0 exists
    REQUIRE(std::filesystem::exists(test_data_file_0));
    REQUIRE(std::filesystem::exists(test_data_file_invalid));
    REQUIRE(std::filesystem::exists(test_data_file_invalid_file_name));
    REQUIRE(std::filesystem::exists(test_data_file_invalid_file_size));
    REQUIRE(std::filesystem::exists(test_data_file_wrongversion));
    REQUIRE(std::filesystem::exists(test_data_file_valid));

    if (std::filesystem::exists(test_data_file_tmp))
    {
        std::filesystem::remove(test_data_file_tmp);
    }
    REQUIRE(!std::filesystem::exists(test_data_file_tmp)); // this file should not exist

    SECTION("should throw for empty class or invalid class")
    {
        REQUIRE_THROWS(FileCache(test_data_file_0, "test.wcd", 1000));
        REQUIRE_THROWS(FileCache(test_data_file_invalid, "test.wcd", 1000));
        REQUIRE_THROWS(FileCache(test_data_file_invalid_file_name, "test.wcd", 1000));
        REQUIRE_THROWS(FileCache(test_data_file_invalid_file_size, "test.wcd", 1000));

        FileCache cache_data(test_data_file_valid, "test.wcd", 1000);
        REQUIRE_THROWS(cache_data.path_is_valid(test_data_file_0));
        REQUIRE_THROWS(cache_data.path_is_valid(test_data_file_invalid));
        REQUIRE(!cache_data.path_is_valid(test_data_file_invalid_file_name));
        REQUIRE(!cache_data.path_is_valid(test_data_file_invalid_file_size));

        REQUIRE_THROWS(cache_data.to_file(test_data_file_0, true));
        REQUIRE_THROWS(cache_data.to_file(test_data_file_invalid, true));

        // should not throw even though file is invalid
        cache_data.to_file(test_data_file_invalid_file_name, true);
        cache_data.to_file(test_data_file_invalid_file_size, true);
    }

    SECTION("wrong FileCache version should create a new empty file")
    {
        FileCache cache_data(test_data_file_wrongversion, "test_new_version.wcd", 1000);
        REQUIRE(cache_data.get_file_name() == "test_new_version.wcd");

        // path should be invalid, but overwrite should work
        REQUIRE(!cache_data.path_is_valid(test_data_file_wrongversion));
        cache_data.to_file(test_data_file_wrongversion, true);
    }

    SECTION("valid file should be read")
    {
        FileCache cache_data(test_data_file_valid, "test.wcd", 1000);
        REQUIRE(cache_data.get_file_name() == "test.wcd");
        REQUIRE(cache_data.get_file_size() == 1000);

        // path should be valid, overwrite should work
        REQUIRE(cache_data.path_is_valid(test_data_file_valid));
        cache_data.to_file(test_data_file_valid, true);
    }

    SECTION("create a temporary file, read and write it")
    {
        FileCache cache_data(test_data_file_tmp, "test.wcd", 1000);
        cache_data.add_to_cache("test_datagram", test_datagram);

        std::ofstream ofs(test_data_file_tmp, std::ios::binary);
        cache_data.to_stream(ofs);
        ofs.close();

        FileCache cache_data2(test_data_file_tmp, "test.wcd", 1000);
        REQUIRE(cache_data == cache_data2);
        REQUIRE(cache_data2.get_from_cache<decltype(test_datagram)>("test_datagram") ==
                test_datagram);

        // path should be valid, overwrite should work
        REQUIRE(cache_data.path_is_valid(test_data_file_tmp));
        cache_data.to_file(test_data_file_tmp, true);
    }
}

TEST_CASE("FileCache should support common functions", TESTTAG)
{
    auto test_datagram = get_test_datagram();

    // read valid test file
    FileCache dat(test_data_file_valid, "test.wcd", 1000);
    FileCache dat2(test_data_file_valid, "test.wcd", 1000);

    // test equality
    REQUIRE(dat == dat2);
    dat2.add_to_cache("test_datagram", test_datagram);
    REQUIRE(dat != dat2);

    // test copy
    REQUIRE(dat == FileCache(dat));
    REQUIRE(dat2 == FileCache(dat2));

    // test binary
    REQUIRE(dat == FileCache(dat.from_binary(dat.to_binary())));
    REQUIRE(dat2 == FileCache(dat2.from_binary(dat2.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == FileCache(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);
    REQUIRE(dat2.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE_THROWS(dat.get_from_cache<decltype(test_datagram)>("test_datagram"));
    REQUIRE(dat2.get_from_cache<decltype(test_datagram)>("test_datagram") == test_datagram);

    // // --- test data access ---
    REQUIRE(dat.get_file_name() == "test.wcd");
    REQUIRE(dat2.get_file_name() == "test.wcd");
    REQUIRE(dat.get_file_size() == 1000);
    REQUIRE(dat2.get_file_size() == 1000);
}

TEST_CASE("FileCache should support partial loading", TESTTAG)
{
    auto test_datagram = get_test_datagram();
    auto test_datagram2 = get_test_datagram();
    test_datagram2.set_timestamp(1234);

    // read valid test file
    FileCache dat1(test_data_file_valid, "test.wcd", 1000);

    // add datagram info to cache
    dat1.add_to_cache("test_datagram", test_datagram);
    dat1.add_to_cache("test_datagram2", test_datagram2);

    // test copy and binary equality
    REQUIRE(dat1 == FileCache(dat1));
    REQUIRE(dat1 == FileCache(dat1.from_binary(dat1.to_binary())));

    // delete temporary file if it exists
    if (std::filesystem::exists(test_data_file_tmp))
    {
        std::filesystem::remove(test_data_file_tmp);
    }

    // write to temporary file
    dat1.to_file(test_data_file_tmp);

    FileCache dat2(test_data_file_tmp, "test.wcd", 1000);
    REQUIRE(dat1 == dat2);

}
