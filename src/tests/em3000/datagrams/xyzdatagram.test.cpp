// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/em3000/datagrams/xyzdatagram.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::em3000::datagrams;
#define TESTTAG "[em3000]"

TEST_CASE("XYZDatagram should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat  = XYZDatagram();
    auto beam = substructures::XYZDatagramBeam();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_sound_speed(201);
    dat.set_ping_counter(202);
    dat.set_system_serial_number(203);
    dat.set_transmit_transducer_depth(204);
    dat.set_heading_of_vessel(205);

    beam.set_beam_incidence_angle_adjustment(101);
    beam.set_reflectivity(191);
    dat.set_beams({ beam });

    // test inequality
    // REQUIRE(dat != XYZDatagram());

    // test copy
    REQUIRE(dat == XYZDatagram(dat));

    // test binary
    REQUIRE(dat == XYZDatagram(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == XYZDatagram(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    REQUIRE(dat.get_sound_speed_in_meters_per_seconds() == Catch::Approx(20.1));
    REQUIRE(dat.get_heading_of_vessel_in_degrees() == Catch::Approx(2.05));
    REQUIRE(beam.get_beam_incidence_angle_adjustment_in_degrees() == Catch::Approx(10.1));
    REQUIRE(beam.get_backscatter() == Catch::Approx(19.1));
    REQUIRE(dat.beams()[0].get_beam_incidence_angle_adjustment_in_degrees() == Catch::Approx(10.1));
    REQUIRE(dat.beams()[0].get_backscatter() == Catch::Approx(19.1));

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_EM3000DatagramIdentifier::XYZDatagram);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
