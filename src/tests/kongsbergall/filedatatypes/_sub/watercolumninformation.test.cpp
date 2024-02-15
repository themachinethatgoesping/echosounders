// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include <boost/functional/hash.hpp> // Include the Boost Hash library

#include "../themachinethatgoesping/echosounders/kongsbergall/datagrams/watercolumndatagram.hpp"
#include "../themachinethatgoesping/echosounders/kongsbergall/filedatatypes/_sub/watercolumninformation.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using themachinethatgoesping::echosounders::kongsbergall::filedatatypes::_sub::
    WaterColumnInformation;
#define TESTTAG "[kongsbergall]"

datagrams::WatercolumnDatagram make_wcd()
{
    // initialize class structure
    auto dat             = datagrams::WatercolumnDatagram();
    auto transmit_sector = datagrams::substructures::WatercolumnDatagramTransmitSector();
    auto beam            = datagrams::substructures::WatercolumnDatagramBeam();

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

    // check the required functions do not throw
    //CHECK(dat.get_beams().size() == 1);

    return dat;
}

TEST_CASE("WaterColumnInformation reproduce precomputed hashes", TESTTAG)
{
    WaterColumnInformation WCI(make_wcd());

    // CHECK(WCI.get_beam_crosstrack_angles().size() == 1);
    // CHECK(WCI.get_beam_crosstrack_angles()[0] == 101);

    // CHECK(WCI.get_start_range_sample_numbers().size() == 1);
    // CHECK(WCI.get_start_range_sample_numbers()[0] == 101);

    // CHECK(WCI.get_number_of_samples_per_beam().size() == 1);
    // CHECK(WCI.get_number_of_samples_per_beam()[0] == 101);

    // CHECK(WCI.get_detected_range_in_samples().size() == 1);
    // CHECK(WCI.get_detected_range_in_samples()[0] == 101);

    // CHECK(WCI.get_transmit_sector_numbers().size() == 1);
    // CHECK(WCI.get_transmit_sector_numbers()[0] == 101);

    // CHECK(WCI.get_sample_positions().size() == 1);
    // CHECK(WCI.get_sample_positions()[0] == 101);

    // CHECK(WCI.get_tvg_factor_applied() == 1);
    // CHECK(WCI.get_tvg_offset_in_db() == 1);
    // CHECK(WCI.get_sample_interval() == 1);

    // auto tr = WCI.get_transmit_sectors();
    // CHECK(tr.size() == 1);
    // CHECK(tr[0].get_tilt_angle() == 101);
    // CHECK(tr[0].get_center_frequency() == 191);
}
