// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/kongsbergall/datagrams/seabedimagedata.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::kongsbergall::datagrams;
#define TESTTAG "[kongsbergall]"

TEST_CASE("SeabedImageData should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat  = SeabedImageData();
    auto beam = substructures::SeabedImageDataBeam();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_ping_counter(202);
    dat.set_system_serial_number(203);
    dat.set_normal_incidence_backscatter(201);
    dat.set_tx_beamwidth_along(204);
    dat.set_tvg_law_crossover_angle(205);

    beam.set_sorting_direction(101);
    beam.set_centre_sample_number(191);
    dat.set_beams({ beam });

    // test inequality
    // REQUIRE(dat != SeabedImageData());

    // test copy
    REQUIRE(dat == SeabedImageData(dat));

    // test binary
    REQUIRE(dat == SeabedImageData(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == SeabedImageData(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    CHECK(dat.get_normal_incidence_backscatter_in_db() == Catch::Approx(2.01));
    CHECK(dat.get_tx_beamwidth_along_in_degrees() == Catch::Approx(20.4));
    CHECK(dat.get_tvg_law_crossover_angle_in_degrees() == Catch::Approx(20.5));
    CHECK(dat.beams()[0].get_sorting_direction() == Catch::Approx(101));
    CHECK(dat.beams()[0].get_centre_sample_number() == Catch::Approx(191));

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KongsbergAllDatagramIdentifier::SeabedImageData);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
