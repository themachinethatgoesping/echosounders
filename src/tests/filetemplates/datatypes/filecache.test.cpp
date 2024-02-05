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

TEST_CASE("FileCache should support common functions", TESTTAG)
{
    std::string test_data_path =
        std::string(UNITTEST_DATA_DIR) + "/filetemplates/datatypes/filecache.test/";
    auto test_data_file_0       = test_data_path + "filecache.test.data.0";
    auto test_data_file_invalid = test_data_path + "filecache.test.data.invalid";
    auto test_data_file_invalid_file_name =
        test_data_path + "filecache.test.data.invalid_file_name";
    auto test_data_file_invalid_file_size =
        test_data_path + "filecache.test.data.invalid_file_size";
    auto test_data_file_wrongversion = test_data_path + "filecache.test.data.wrongversion";
    auto test_data_file_tmp          = test_data_path + "filecache.test.data.tmp";

    INFO("Test data path: " << test_data_path);
    // test if test_data/filecache.test.data0 exists
    REQUIRE(std::filesystem::exists(test_data_file_0));
    REQUIRE(std::filesystem::exists(test_data_file_invalid));
    REQUIRE(std::filesystem::exists(test_data_file_invalid_file_name));
    REQUIRE(std::filesystem::exists(test_data_file_invalid_file_size));
    REQUIRE(std::filesystem::exists(test_data_file_wrongversion));

    if (std::filesystem::exists(test_data_file_tmp))
    {
        std::filesystem::remove(test_data_file_tmp);
    }
    REQUIRE(!std::filesystem::exists(test_data_file_tmp)); // this file should not exist

    SECTION("should throw for empty class or wrong class")
    {
        REQUIRE_THROWS(FileCache(test_data_file_0, "test.wcd", 1000));
        REQUIRE_THROWS(FileCache(test_data_file_invalid, "test.wcd", 1000));
        REQUIRE_THROWS(FileCache(test_data_file_invalid_file_name, "test.wcd", 1000));
        REQUIRE_THROWS(FileCache(test_data_file_invalid_file_size, "test.wcd", 1000));
    }

    SECTION("wrong version should create empty file")
    {
        FileCache cache_data(test_data_file_wrongversion, "test_new_version.wcd", 1000);
        REQUIRE(cache_data.get_file_name() == "test_new_version.wcd");
    }

    SECTION("create a file")
    {
        FileCache     cache_data(test_data_file_tmp, "test.wcd", 1000);
        std::ofstream ofs(test_data_file_tmp);
        cache_data.header_to_stream(ofs);
        ofs.close();

        FileCache cache_data2(test_data_file_tmp, "test.wcd", 1000);
        REQUIRE(cache_data == cache_data2);
    }

    // // set some variables
    // dat.set_timestamp(123);
    // dat.set_heave(10);
    // dat.set_roll(12);
    // dat.set_pitch(13);
    // dat.set_heading(14);

    // auto dat2 = dat;
    // dat2.set_heading(15);

    // // test inequality
    // REQUIRE(dat != dat2);

    // // test empty equality (check e.g. nan compare problems)
    // REQUIRE(MRU0() == MRU0());

    // // test copy
    // REQUIRE(dat == MRU0(dat));

    // // test binary
    // REQUIRE(dat == MRU0(dat.from_binary(dat.to_binary())));

    // // test stream
    // std::stringstream buffer;
    // dat.to_stream(buffer);
    // REQUIRE(dat == MRU0(dat.from_stream(buffer)));

    // // test print does not crash
    // REQUIRE(dat.info_string().size() != 0);

    // // --- test data access ---
    // REQUIRE(dat.get_heave() == 10);
    // REQUIRE(dat.get_roll() == 12);
    // REQUIRE(dat.get_pitch() == 13);
    // REQUIRE(dat.get_heading() == 14);

    // //--- datagram concept ---

    // // datagram type
    // REQUIRE(dat.get_datagram_identifier() == t_SimradRawDatagramIdentifier::MRU0);
    // REQUIRE(dat.get_length() == 12 + 4 * sizeof(simradraw_float));
}
