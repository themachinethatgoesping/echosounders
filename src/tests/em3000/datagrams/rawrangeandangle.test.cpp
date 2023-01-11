// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/em3000/datagrams/rawrangeandangle.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::em3000::datagrams;
#define TESTTAG "[em3000]"

TEST_CASE("RawRangeAndAngle should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat             = RawRangeAndAngle();
    auto transmit_sector = substructures::RawRangeAndAngleTransmitSector();
    auto beam            = substructures::RawRangeAndAngleBeam();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_sound_speed_at_transducer(201);
    dat.set_ping_counter(202);
    dat.set_system_serial_number(203);
    dat.set_sampling_frequency(204);
    dat.set_d_scale(205);

    transmit_sector.set_mean_absorption_coefficient(101);
    transmit_sector.set_tilt_angle(191);
    dat.set_transmit_sectors({ transmit_sector });

    beam.set_quality_factor(101);
    beam.set_reflectivity(191);
    dat.set_beams({ beam });

    // test inequality
    // REQUIRE(dat != RawRangeAndAngle());

    // test copy
    REQUIRE(dat == RawRangeAndAngle(dat));

    // test binary
    REQUIRE(dat == RawRangeAndAngle(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == RawRangeAndAngle(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    CHECK(dat.get_sound_speed_at_transducer_in_m_per_s() == Catch::Approx(20.1));
    CHECK(dat.get_sampling_frequency() == Catch::Approx(204.f));
    CHECK(dat.transmit_sectors()[0].get_mean_absorption_coefficient_in_dB_per_m() == Catch::Approx(1010.f));
    CHECK(dat.transmit_sectors()[0].get_tilt_angle_in_degrees() == Catch::Approx(1.91));
    CHECK(dat.beams()[0].get_quality_factor() == Catch::Approx(101));
    CHECK(dat.beams()[0].get_reflectivity_in_db() == Catch::Approx(19.1f));

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_EM3000DatagramIdentifier::RawRangeAndAngle);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
