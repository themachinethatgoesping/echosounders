// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/kongsbergall/datagrams/puidoutput.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::kongsbergall::datagrams;
#define TESTTAG "[kongsbergall]"

TEST_CASE("PUIDOutput should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = PUIDOutput();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_udp_port_no_1(123);
    dat.set_system_descriptor(100);
    REQUIRE_THROWS_AS(dat.set_pu_software_version("HALLO"), std::invalid_argument);
    dat.set_pu_software_version("There: 16 bytes!");

    // test inequality
    // REQUIRE(dat != PUIDOutput());

    // test copy
    REQUIRE(dat == PUIDOutput(dat));

    // test binary
    REQUIRE(dat == PUIDOutput(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == PUIDOutput(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    CHECK(dat.get_udp_port_no_1() == 123);
    CHECK(dat.get_system_descriptor() == 'd');
    CHECK(dat.get_pu_software_version() == "There: 16 bytes!");

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KongsbergAllDatagramIdentifier::PUIDOutput);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}

TEST_CASE("PUIDOutput should evaluate system descriptor flag correctly", TESTTAG)
{
    // initialize class structure
    auto dat = PUIDOutput();

    // check zero
    dat.set_system_descriptor(0);
    CHECK(dat.get_has_dual_head() == false);
    CHECK(dat.get_has_dual_swath() == false);
    CHECK(dat.get_has_bsp67B() == true);
    CHECK(dat.get_has_cbmf() == false);
    CHECK(dat.get_has_ptp_support() == false);
    CHECK(dat.get_has_shallow_water_sonar_head() == false);
    CHECK(dat.get_has_deep_water_sonar_head() == true);
    CHECK(dat.get_has_extra_detections_support() == false);
    CHECK(dat.get_has_rs422_support() == false);

    // check dual head
    dat.set_system_descriptor(1);
    CHECK(dat.get_has_dual_head() == true);
    CHECK(dat.get_has_dual_swath() == false);
    CHECK(dat.get_has_bsp67B() == true);
    CHECK(dat.get_has_cbmf() == false);
    CHECK(dat.get_has_ptp_support() == false);
    CHECK(dat.get_has_shallow_water_sonar_head() == false);
    CHECK(dat.get_has_extra_detections_support() == false);
    CHECK(dat.get_has_rs422_support() == false);

    // check dual rx
    dat.set_system_descriptor(0b10);
    CHECK(dat.get_has_dual_head() == false);
    CHECK(dat.get_has_dual_swath() == true);
    dat.set_system_descriptor(0b11);
    CHECK(dat.get_has_dual_head() == true);
    CHECK(dat.get_has_dual_swath() == true);

    // check BSP 67B
    dat.set_system_descriptor(0b100);
    CHECK(dat.get_has_dual_head() == false);
    CHECK(dat.get_has_dual_swath() == false);
    CHECK(dat.get_has_bsp67B() == false);
    CHECK(dat.get_has_cbmf() == true);

    // check ptp support
    dat.set_system_descriptor(0b1000);
    CHECK(dat.get_has_dual_head() == false);
    CHECK(dat.get_has_dual_swath() == false);
    CHECK(dat.get_has_bsp67B() == true);
    CHECK(dat.get_has_cbmf() == false);
    CHECK(dat.get_has_ptp_support() == true);

    // rest flags
    dat.set_system_descriptor(0b10000);
    CHECK(dat.get_has_shallow_water_sonar_head() == true);
    CHECK(dat.get_has_deep_water_sonar_head() == false);
    dat.set_system_descriptor(0b100000);
    CHECK(dat.get_has_extra_detections_support() == true);
    dat.set_system_descriptor(0b1000000);
    CHECK(dat.get_has_rs422_support() == true);

    // check all flags
    dat.set_system_descriptor(0b1010101);
    CHECK(dat.get_has_dual_head() == true);
    CHECK(dat.get_has_dual_swath() == false);
    CHECK(dat.get_has_bsp67B() == false);
    CHECK(dat.get_has_cbmf() == true);
    CHECK(dat.get_has_ptp_support() == false);
    CHECK(dat.get_has_shallow_water_sonar_head() == true);
    CHECK(dat.get_has_deep_water_sonar_head() == false);
    CHECK(dat.get_has_extra_detections_support() == false);
    CHECK(dat.get_has_rs422_support() == true);

    // check cpu configuration
    dat.set_system_descriptor(0x03000000);
    CHECK(dat.get_cpu_configuration() == "Kontron");
    dat.set_system_descriptor(0x07000000);
    CHECK(dat.get_cpu_configuration() == "Concurrent Technologies PP 833");

    // check em2040 flag
    dat.set_system_descriptor(0b110000000);
    CHECK(dat.get_which_em2040() == "EM 2040P");
    dat.set_system_descriptor(0b010000000);
    CHECK(dat.get_which_em2040() == "EM 2040 Dual TX (2*TX and 2*RX)");

    // check em710 flag
    dat.set_system_descriptor(0b00110000000);
    CHECK(dat.get_which_em710() == "EM 710");
    dat.set_system_descriptor(0b01010000000);
    CHECK(dat.get_which_em710() == "EM 710–MK2");

    // check old echosounder flag
    dat.set_system_descriptor(0x01);
    CHECK(dat.get_which_old_sounder() == "EM 1002S");
    dat.set_system_descriptor(0x08);
    CHECK(dat.get_which_old_sounder() == "EM 3001");
    dat.set_system_descriptor(0x109);
    CHECK(dat.get_which_old_sounder() == "EM 3002 Rx gain not available");
}