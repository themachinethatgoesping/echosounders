// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/kongsbergall/datagrams/surfacesoundspeeddatagram.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::kongsbergall::datagrams;
#define TESTTAG "[kongsbergall]"

TEST_CASE("SurfaceSoundSpeedDatagram should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = SurfaceSoundSpeedDatagram();

    auto times_and_sound_speeds =
        xt::empty<uint16_t>(xt::xtensor<uint16_t, 2>::shape_type({ 2, 2 }));
    times_and_sound_speeds(0, 0) = 1234;
    times_and_sound_speeds(0, 1) = 567;
    times_and_sound_speeds(1, 0) = 2345;
    times_and_sound_speeds(1, 1) = 678;

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);
    dat.set_times_and_sound_speeds(times_and_sound_speeds);
    dat.set_number_of_entries(2);

    dat.set_sound_speed_counter(123);
    dat.set_system_serial_number(100);

    // test inequality
    // REQUIRE(dat != SurfaceSoundSpeedDatagram());

    // test copy
    REQUIRE(dat == SurfaceSoundSpeedDatagram(dat));

    // test binary
    REQUIRE(dat == SurfaceSoundSpeedDatagram(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == SurfaceSoundSpeedDatagram(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    CHECK(dat.get_sound_speed_counter() == 123);
    CHECK(dat.get_system_serial_number() == 100);

    auto timestamps   = dat.get_sound_speed_timestamps();
    auto sound_speeds = dat.get_sound_speeds_in_meters_per_second();
    CHECK(timestamps(0) == 1.234 + dat.get_timestamp());
    CHECK(timestamps(1) == 2.345 + dat.get_timestamp());
    CHECK(sound_speeds(0) == 56.7f);
    CHECK(sound_speeds(1) == 67.8f);

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KongsbergAllDatagramIdentifier::SurfaceSoundSpeedDatagram);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
