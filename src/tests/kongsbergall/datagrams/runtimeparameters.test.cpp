// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
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

    // frequency mode
    // model 710 -> fixed 85 kHz
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(85000.f));
    // model 120 / 122 -> fixed 12 kHz
    dat.set_model_number(120);
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(12000.f));
    dat.set_model_number(122);
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(12000.f));
    // model 300 / 302 -> fixed 31.5 kHz
    dat.set_model_number(300);
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(31500.f));
    dat.set_model_number(302);
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(31500.f));
    // model 1002 -> fixed 95 kHz
    dat.set_model_number(1002);
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(95000.f));
    // model 2000 -> fixed 200 kHz
    dat.set_model_number(2000);
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(200000.f));
    // model 3000 / 3002 -> fixed 300 kHz
    dat.set_model_number(3000);
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(300000.f));
    dat.set_model_number(3002);
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(300000.f));
    // model 2040 -> frequency encoded in mode bits 0-3
    dat.set_model_number(2040);
    dat.set_mode(0b00000000);
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(200000.f));
    dat.set_mode(0b00000001);
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(300000.f));
    dat.set_mode(0b00000010);
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(400000.f));
    // model 2045 (EM 2040C) -> frequency = (180 + 10 * mode[4:0]) kHz
    dat.set_model_number(2045);
    dat.set_mode(0b00000000); // 180 kHz
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(180000.f));
    dat.set_mode(0b00000001); // 190 kHz
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(190000.f));
    dat.set_mode(0b00010110); // 22 * 10 + 180 = 400 kHz
    CHECK(dat.get_frequency_mode_in_hertz() == Catch::Approx(400000.f));

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KongsbergAllDatagramIdentifier::RuntimeParameters);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
