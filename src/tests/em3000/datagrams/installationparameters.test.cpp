// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/em3000/datagrams/installationparameters.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::em3000::datagrams;
#define TESTTAG "[em3000]"

TEST_CASE("InstallationParameters should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = InstallationParameters();

    std::string installation_parameters = "WLZ=x.x,SMH=x.x,S0Z=x.x";

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);
    dat.set_installation_parameters(installation_parameters);
    dat.set_bytes(installation_parameters.size() + 21);

    dat.set_installation_parameters_counter(123);
    dat.set_system_serial_number(100);

    // test inequality
    // REQUIRE(dat != InstallationParameters());

    // test copy
    REQUIRE(dat == InstallationParameters(dat));

    // test binary
    REQUIRE(dat == InstallationParameters(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == InstallationParameters(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    CHECK(dat.get_bytes() == installation_parameters.size() + 21);
    CHECK(dat.get_installation_parameters_counter() == 123);
    CHECK(dat.get_system_serial_number() == 100);
    CHECK(dat.get_installation_parameters() == installation_parameters);

    // datagram type
    REQUIRE(dat.get_datagram_identifier() ==
            t_EM3000DatagramIdentifier::InstallationParametersStart);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}

TEST_CASE("InstallationParameters should support parse installation_parameters correctly", TESTTAG)
{
    // initialize class structure
    auto dat = InstallationParameters();

    std::string installation_parameters =
        "WLZ=-4.908,SMH=2004,STC=3,S1X=0.377,S1Y=0.008,S1Z=0.426,S1H=180.520,S1P=-1.680,S1R=-0.840,"
        "S1S=0,S2X=0.246,S2Y=-0.374,S2Z=0.301,S2H=0.320,S2P=3.210,S2R=35.610,S2S=1,S3X=0.235,S3Y=0."
        "387,S3Z=0.307,S3H=1.290,S3P=3.190,S3R=-34.180,S3S=1,GO1=0.00,GO2=0.00,TXS=214,R1S=2004,"
        "R2S=2031,TSV=1.07   Mar  8 2018 ,RSV=1.02   Nov 12 2012 ,BSV=1.11 18.02.20 ,PSV=2.6.1 "
        "210709,DSV=3.1.8 141125,DDS=4.60 140106,OSV=SIS "
        "4.3.2,DSX=0.000,DSY=0.000,DSZ=0.000,DSD=0,DSO=0.000000,DSF=1.000000,DSH=NI,P1M=0,P1T=1,"
        "P1Q=1,P1X=-7.887,P1Y=0.875,P1Z=-5.968,P1D=0.000,P1G=WGS84,P2M=0,P2T=0,P2Q=1,P2X=0.000,P2Y="
        "0.000,P2Z=0.000,P2D=0.000,P2G=WGS84,P3M=1,P3T=1,P3Q=1,P3X=-2.567,P3Y=-1.153,P3Z=-30.331,"
        "P3D=0.000,P3G=WGS84,P3S=1,MSX=0.000,MSY=0.000,MSZ=0.000,MRP=RP,MSD=0,MSR=-0.150,MSP=-0."
        "200,MSG=-0.230,NSX=-7.887,NSY=0.875,NSZ=-5.968,NRP=RP,NSD=0,NSR=0.000,NSP=0.000,NSG=0.000,"
        "MAS=1.000,GCG=0.000,APS=0,AHS=2,ARO=2,AHE=2,CLS=1,CLO=0,PPS=1,VSN=1,VSE=2,VSU=20241,VTE=2,"
        "VTU=20121,VSI=172.16.120.55,VSM=255.255.255.0,SID=TURBEAMS_20220318_W08,RFN=0001_20220318_"
        "114938_Belgica.all,";

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);
    dat.set_installation_parameters(installation_parameters);
    dat.set_bytes(installation_parameters.size() + 21);

    dat.set_installation_parameters_counter(123);
    dat.set_system_serial_number(100);

    // test parsing
    REQUIRE(dat == InstallationParameters(dat.from_binary(dat.to_binary())));

    using themachinethatgoesping::navigation::datastructures::PositionalOffsets;
    using themachinethatgoesping::tools::helper::approx;

    // test decoding sensor offsets
    SECTION("Attitude sensor 1")
    {
        CAPTURE(dat.get_attitude_sensor_offsets(1).info_string());
        CHECK(dat.get_attitude_sensor_offsets(1) ==
              PositionalOffsets("Attitude sensor 1", 0, 0, 0, -0.23, -0.2, -0.15));
    }
    SECTION("Attitude sensor 2")
    {
        CAPTURE(dat.get_attitude_sensor_offsets(2).info_string(3));
        CHECK(dat.get_attitude_sensor_offsets(2) ==
              PositionalOffsets("Attitude sensor 2", -7.887, 0.875, -5.968, 0., 0., 0.));
    }
    SECTION("Depth sensor")
    {
        CAPTURE(dat.get_depth_sensor_offsets().info_string(3));
        CHECK(dat.get_depth_sensor_offsets() ==
              PositionalOffsets("Depth sensor", 0, 0, 0, 0, 0, 0));
    }
    SECTION("Position system 1")
    {
        CAPTURE(dat.get_position_system_offsets(1).info_string(3));
        CHECK(dat.get_position_system_offsets(1) ==
              PositionalOffsets("Position system 1", -7.887, 0.875, -5.968, 0., 0., 0.));
    }
    SECTION("Position system 2")
    {
        CAPTURE(dat.get_position_system_offsets(2).info_string(3));
        CHECK(dat.get_position_system_offsets(2) ==
              PositionalOffsets("Position system 2", 0, 0, 0, 0, 0, 0));
    }
    SECTION("Position system 3")
    {
        CAPTURE(dat.get_position_system_offsets(3).info_string(3));
        CHECK(dat.get_position_system_offsets(3) ==
              PositionalOffsets("Position system 3", -2.567, -1.153, -30.331, 0., 0., 0.));
    }
    // SECTION("Transducer 0")
    // {
    //     CAPTURE(dat.get_transducer_offsets(0).info_string(3));
    //     CHECK(dat.get_transducer_offsets(0) ==
    //           PositionalOffsets("Transducer 0", -2.567, -1.153, -30.331, 0., 0., 0.));
    // }
    SECTION("Transducer 1")
    {
        CAPTURE(dat.get_transducer_offsets(1).info_string(3));
        CHECK(dat.get_transducer_offsets(1) ==
              PositionalOffsets("Transducer 1", 0.377, 0.008, 0.426, 180.52, -1.68, -0.84));
    }
    SECTION("Transducer 2")
    {
        CAPTURE(dat.get_transducer_offsets(2).info_string(3));
        CHECK(dat.get_transducer_offsets(2) ==
              PositionalOffsets("Transducer 2", 0.246, -0.374, 0.301, 0.32, 3.21, 35.61));
    }
    SECTION("Transducer 3")
    {
        CAPTURE(dat.get_transducer_offsets(3).info_string(3));
        CHECK(dat.get_transducer_offsets(3) ==
              PositionalOffsets("Transducer 3", 0.235, 0.387, 0.307, 1.29, 3.19, -34.18));
    }

    SECTION("Gyrocompass")
    {
        CAPTURE(dat.get_compass_offsets().info_string());
        CHECK(dat.get_compass_offsets() == PositionalOffsets("Gyrocompass", 0, 0, 0, 0, 0, 0));
    }

    SECTION("individual parameters")
    {
        CHECK(dat.get_water_line_vertical_location_in_meters() == -4.908f);
        CHECK(dat.get_system_main_head_serial_number() == 2004);
        CHECK(dat.get_tx_serial_number() == 214);
        // CHECK(dat.get_tx2_serial_number() == 2);
        CHECK(dat.get_rx1_serial_number() == 2004);
        CHECK(dat.get_rx2_serial_number() == 2031);
        CHECK(dat.get_system_transducer_configuration() == "Single TX + dual RX");
        CHECK(dat.get_tx_array_size() == "0.5°");
        CHECK(dat.get_rx_array_size() == "1°");
    }

    // SECTION("SensorConfiguration")
    // {
    //     auto sc = dat.get_sensor_configuration();
    //     CAPTURE(sc.info_string(3));
    //     CHECK(sc.get_target("TX") ==
    //           PositionalOffsets("TX", 0.377, 0.008, 0.426, 180.52, -1.68, -0.84));
    //     CHECK(sc.get_target("RX port") ==
    //           PositionalOffsets("RX port", 0.246, -0.374, 0.301, 0.32, 3.21, 35.61));
    //     CHECK(sc.get_target("RX starboard") ==
    //           PositionalOffsets("RX starboard", 0.235, 0.387, 0.307, 1.29, 3.19, -34.18));
    // }
}
