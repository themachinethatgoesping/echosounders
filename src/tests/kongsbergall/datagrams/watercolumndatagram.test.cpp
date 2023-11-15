// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/kongsbergall/datagrams/watercolumndatagram.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::kongsbergall::datagrams;
#define TESTTAG "[kongsbergall]"

TEST_CASE("WatercolumnDatagram should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat             = WatercolumnDatagram();
    auto transmit_sector = substructures::WatercolumnDatagramTransmitSector();
    auto beam            = substructures::WatercolumnDatagramBeam();

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

    beam.set_beam_crosstrack_angle(101);
    beam.set_transmit_sector_number(191);
    dat.set_beams({ beam });

    // test inequality
    // REQUIRE(dat != WatercolumnDatagram());

    // test copy
    REQUIRE(dat == WatercolumnDatagram(dat));

    // test binary
    REQUIRE(dat == WatercolumnDatagram(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == WatercolumnDatagram(dat.from_stream(buffer)));

    // test data skipping
    auto dat_skipped = dat;
    for (unsigned int b = 0; b < dat_skipped.beams().size(); b++)
    {
        dat_skipped.beams()[b].set_samples({});
    }
    buffer.clear();
    dat.to_stream(buffer);
    REQUIRE(dat == WatercolumnDatagram(dat.from_stream(buffer, false)));
    dat.to_stream(buffer);
    REQUIRE(dat_skipped == WatercolumnDatagram(dat.from_stream(buffer, true)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    CHECK(dat.get_sampling_frequency_in_hz() == Catch::Approx(2.04f));
    CHECK(dat.get_tx_time_heave_in_m() == Catch::Approx(2.05));
    CHECK(dat.transmit_sectors()[0].get_tilt_angle_in_degrees() == Catch::Approx(1.01f));
    CHECK(dat.transmit_sectors()[0].get_center_frequency_in_hz() == Catch::Approx(1910.f));
    CHECK(dat.beams()[0].get_beam_crosstrack_angle_in_degrees() == Catch::Approx(1.01));
    CHECK(dat.beams()[0].get_transmit_sector_number() == Catch::Approx(191));

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KongsbergAllDatagramIdentifier::WatercolumnDatagram);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
