// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "../themachinethatgoesping/echosounders/s7k/datagrams/heading.hpp"
#include "../themachinethatgoesping/echosounders/s7k/datagrams/position.hpp"
#include "../themachinethatgoesping/echosounders/s7k/datagrams/sonarsettings.hpp"

using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::s7k::datagrams;
#define TESTTAG "[s7k]"

TEST_CASE("SonarSettings should support common functions and round trips", TESTTAG)
{
    auto dat = SonarSettings();
    dat.set_ping_number(32343);
    dat.set_frequency(400000.f);
    dat.set_sample_rate(78125.f);
    dat.set_sound_velocity(1501.6f);
    dat.set_serial_number(185);

    // record type identifier is set by the default constructor
    REQUIRE(dat.get_datagram_identifier() == t_S7KDatagramIdentifier::SonarSettings);

    // field access
    REQUIRE(dat.get_ping_number() == 32343);
    REQUIRE(dat.get_frequency() == Catch::Approx(400000.f));

    // copy
    REQUIRE(dat == SonarSettings(dat));
    // binary round trip
    REQUIRE(dat == SonarSettings(dat.from_binary(dat.to_binary())));
    // stream round trip
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == SonarSettings(dat.from_stream(buffer)));

    // print does not crash
    REQUIRE(dat.info_string().size() != 0);
}

TEST_CASE("Heading and Position should round trip", TESTTAG)
{
    auto hd = Heading();
    hd.set_heading(0.45f);
    REQUIRE(hd.get_heading() == Catch::Approx(0.45f));
    REQUIRE(hd == Heading(hd.from_binary(hd.to_binary())));

    auto pos = Position();
    pos.set_latitude_northing(0.894);
    pos.set_longitude_easting(0.051);
    pos.set_height(45.7);
    REQUIRE(pos.get_latitude_northing() == Catch::Approx(0.894));
    REQUIRE(pos == Position(pos.from_binary(pos.to_binary())));
    REQUIRE(pos.info_string().size() != 0);
}
