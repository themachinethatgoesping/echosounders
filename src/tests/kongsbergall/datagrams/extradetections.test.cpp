// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/kongsbergall/datagrams/extradetections.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::kongsbergall::datagrams;
#define TESTTAG "[kongsbergall]"

TEST_CASE("ExtraDetections should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat               = ExtraDetections();
    auto detection_classes = substructures::ExtraDetectionsDetectionClasses();
    auto extra_detections  = substructures::ExtraDetectionsExtraDetections();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_sound_speed(201);
    dat.set_ping_counter(202);
    dat.set_system_serial_number(203);
    dat.set_depth_of_reference_point(204);
    dat.set_water_column_sample_rate(20);
    dat.set_heading(205);
    dat.set_raw_amplitude_sample_rate(16);

    detection_classes.set_start_depth(101);
    detection_classes.set_qf_threshold_100(191);
    dat.set_detection_classes({ detection_classes });

    extra_detections.set_qf_10(101);
    extra_detections.set_two_way_travel_time(191);
    dat.set_extra_detections({ extra_detections });

    // test inequality
    // REQUIRE(dat != ExtraDetections());

    // test copy
    {
        INFO("--- COPY START ---");
        INFO(dat.info_string());
        INFO("---");
        INFO(ExtraDetections(dat).info_string());
        INFO("--- COPY END ---");
        REQUIRE(dat == ExtraDetections(dat));
    }

    // test binary
    REQUIRE(dat == ExtraDetections(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == ExtraDetections(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    REQUIRE(dat.get_sound_speed_in_m_per_s() == Catch::Approx(20.1));
    REQUIRE(dat.get_heading_in_degrees() == Catch::Approx(2.05));
    REQUIRE(dat.detection_classes()[0].get_start_depth() == Catch::Approx(101));
    REQUIRE(dat.detection_classes()[0].get_qf_threshold() == Catch::Approx(1.91));
    REQUIRE(dat.extra_detections()[0].get_qf_threshold() == Catch::Approx(10.1));
    REQUIRE(dat.extra_detections()[0].get_two_way_travel_time() == Catch::Approx(191));

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KongsbergAllDatagramIdentifier::ExtraDetections);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
