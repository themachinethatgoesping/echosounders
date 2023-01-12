// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/em3000/datagrams/watercolumndatagram.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::em3000::datagrams;
#define TESTTAG "[em3000]"

TEST_CASE("WaterColumnDatagram should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat             = WaterColumnDatagram();
    auto transmit_sector = substructures::WaterColumnDatagramTransmitSector();
    auto beam            = substructures::WaterColumnDatagramBeam();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_sound_speed(201);
    dat.set_ping_counter(202);
    dat.set_system_serial_number(203);
    dat.set_sampling_frequency(204);
    dat.set_tx_time_heave(205);

    transmit_sector.set_tilt_angle(101);
    transmit_sector.set_center_frequency(191);
    dat.set_transmit_sectors({ transmit_sector });

    beam.set_beam_pointing_angle(101);
    beam.set_transmit_sector_number(191);
    dat.set_beams({ beam });

    // test inequality
    // REQUIRE(dat != WaterColumnDatagram());

    // test copy
    REQUIRE(dat == WaterColumnDatagram(dat));

    // test binary
    REQUIRE(dat == WaterColumnDatagram(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == WaterColumnDatagram(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    CHECK(dat.get_sampling_frequency_in_hz() == Catch::Approx(20.1));
    CHECK(dat.get_tx_time_heave_in_m() == Catch::Approx(2.05));
    CHECK(dat.transmit_sectors()[0].get_tilt_angle_in_degrees() == Catch::Approx(101));
    CHECK(dat.transmit_sectors()[0].get_center_frequency_in_hz() == Catch::Approx(1.91));
    CHECK(dat.beams()[0].get_beam_pointing_angle_in_degrees() == Catch::Approx(10.1));
    CHECK(dat.beams()[0].get_transmit_sector_number() == Catch::Approx(191));

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_EM3000DatagramIdentifier::WaterColumnDatagram);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
