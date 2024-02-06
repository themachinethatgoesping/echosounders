// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <xtensor/xtensor.hpp>

#include <themachinethatgoesping/echosounders/kongsbergall/types.hpp>
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

TEST_CASE("FileCache should be able to create files but not overwrite existing non-FileCache files",
          TESTTAG)
{

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
    }

    SECTION("wrong FileCache version should create a new empty file")
    {
        FileCache cache_data(test_data_file_wrongversion, "test_new_version.wcd", 1000);
        REQUIRE(cache_data.get_file_name() == "test_new_version.wcd");
    }

    SECTION("valid file should be read")
    {
        FileCache cache_data(test_data_file_valid, "test.wcd", 1000);
        REQUIRE(cache_data.get_file_name() == "test.wcd");
        REQUIRE(cache_data.get_file_size() == 1000);
    }

    SECTION("create a temporary file, read and write it")
    {
        FileCache     cache_data(test_data_file_tmp, "test.wcd", 1000);
        std::ofstream ofs(test_data_file_tmp);
        cache_data.header_to_stream(ofs);
        ofs.close();

        FileCache cache_data2(test_data_file_tmp, "test.wcd", 1000);
        REQUIRE(cache_data == cache_data2);
    }
}

TEST_CASE("FileCache should support common functions", TESTTAG)
{
    // read valid test file
    FileCache cache_data(test_data_file_valid, "test.wcd", 1000);

    // test print does not crash
    REQUIRE(cache_data.info_string().size() != 0);

    // // --- test data access ---
    REQUIRE(cache_data.get_file_name() == "test.wcd");
    REQUIRE(cache_data.get_file_size() == 1000);
}
