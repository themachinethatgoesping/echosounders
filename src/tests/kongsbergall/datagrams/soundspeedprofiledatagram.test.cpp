// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/kongsbergall/datagrams/soundspeedprofiledatagram.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::kongsbergall::datagrams;
#define TESTTAG "[kongsbergall]"

TEST_CASE("SoundSpeedProfileDatagram should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = SoundSpeedProfileDatagram();

    auto depths_and_sound_speeds =
        xt::empty<uint16_t>(xt::xtensor<uint16_t, 2>::shape_type({ 2, 2 }));
    depths_and_sound_speeds(0, 0) = 1234;
    depths_and_sound_speeds(0, 1) = 567;
    depths_and_sound_speeds(1, 0) = 2345;
    depths_and_sound_speeds(1, 1) = 678;

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);
    dat.set_depths_and_sound_speeds(depths_and_sound_speeds);
    dat.set_number_of_entries(2);
    dat.set_profile_date(20200423);
    dat.set_profile_time_since_midnight(323727);
    dat.set_depth_resolution(456);

    dat.set_profile_counter(123);
    dat.set_system_serial_number(100);

    // test inequality
    // REQUIRE(dat != SoundSpeedProfileDatagram());

    // test copy
    REQUIRE(dat == SoundSpeedProfileDatagram(dat));

    // test binary
    REQUIRE(dat == SoundSpeedProfileDatagram(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == SoundSpeedProfileDatagram(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    CHECK(dat.get_profile_counter() == 123);
    CHECK(dat.get_system_serial_number() == 100);
    CHECK(dat.get_depth_resolution_in_meters() == 4.56f);

    auto depths       = dat.get_depths_in_meters();
    auto sound_speeds = dat.get_sound_speeds_in_meters_per_second();
    CHECK(depths(0) == 12.34);
    CHECK(depths(1) == 23.45);
    CHECK(sound_speeds(0) == 56.7f);
    CHECK(sound_speeds(1) == 67.8f);

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KongsbergAllDatagramIdentifier::SoundSpeedProfileDatagram);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
    REQUIRE(dat.get_profile_timestamp() == Catch::Approx(1587600323.7269999981));
}
