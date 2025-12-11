// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include <themachinethatgoesping/echosounders/kmall/datagrams/iinstallationparam.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kmall;
using namespace themachinethatgoesping::echosounders::kmall::datagrams;
#define TESTTAG "[kmall]"

TEST_CASE("IInstallationParam should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = IInstallationParam();

    std::string test_text =
        "OSCV:Empty,EMXV:EM2042,\nPU_0,\nSN=25002,\nIP=157.237.20.40:0xffff0000,\nUDP=1997,\nTYPE="
        "CON_TECH_PP_B84_64BIT_CPU,\nVERSIONS:,\nCPU:6.0.0R3 2024-11-07,\nVXW:7-23.03 SMP 64-bit "
        "Sep 10 2024,\nFILTER:1.1.0 241105,\nCBMF:1.03 24.03.5 ,\nTX:1.02   Aug 14 2024 "
        ",\nRX:3.2.3 "
        "2024-10-31,\nVERSIONS-END,\nSERIALno:\nTX:5001;0.7deg,\nRX:5003,\nSERIALno-END,\nDCL:2.0."
        "2 2022-04-28,\nKMALL:Rev J 2023-09-15,\nSYSTEM:EM 2042 - Single Tx single "
        "Rx,TRAI_TX1:N=5001;X=-0.512;Y=-0.055;Z=1.714;R=0.017;P=0.430;H=178.080;S=0.7;IPX=0.0000;"
        "IPY=-0.04887;IPZ=-0.01156;ICX=0.00000;ICY=0.00650;ICZ=-0.00560;ISX=0.00000;ISY=0.04887;"
        "ISZ=-0.01156,TRAI_RX1:N=5003;V=110-0062678;W=EM "
        "2042-MRU-60_SV;X=-0.270;Y=0.055;Z=1.700;R=-0.017;P=-0.430;H=358.080;G=0.00;IX=-0.01000;IY="
        "0.00000;IZ=-0.00600,POSI_1:X=0.000;Y=0.000;Z=0.000;D=0.000;G=WGS84;T=Datagram;C=On;F=GGA;"
        "Q=Off;I=Net port "
        "1;U=ACTIVE,POSI_2:U=NOT_SET,POSI_3:U=NOT_SET,ATTI_1:X=0.000;Y=0.000;Z=0.000;R=0.000;P=0."
        "000;H=0.000;D=0.000;M=Rotation;F=KM Binary;I=Net port "
        "2;U=ACTIVE,ATTI_2:U=NOT_SET,S=CLK;A=On rising edge;I=Net port "
        "1;Q=OK,DPHI:U=NOT_SET,SVPI:F=AML NMEA;I=Integrated probe;U=ACTIVE,EMXI:SWLZ=0.670,\n\x00";

    // set some variables
    dat.set_datagram_version(1.2);
    dat.set_system_id(123);
    dat.set_echo_sounder_id(2040);
    dat.set_time_sec(1555977823);
    dat.set_time_nanosec(726999998);
    dat.set_info(11);
    dat.set_status(12);
    dat.set_install_txt(test_text);
    CHECK(dat.binary_hash() == 7356458248918231941ULL);

    // test inequality
    // REQUIRE(dat != IInstallationParam());

    // test copy
    {
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("copy constructor: {}", IInstallationParam(dat).info_string()));
        REQUIRE(dat == IInstallationParam(dat));
    }

    // test binary
    {
        auto dat2 = IInstallationParam(dat.from_binary(dat.to_binary()));
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("From binary: {}", dat2.info_string()));
        REQUIRE(dat == dat2);
        CHECK(dat2.binary_hash() == dat.binary_hash());
    }

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == IInstallationParam(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(dat.get_bytes_content() == dat.compute_size_content());
    REQUIRE(dat.get_info() == 11);
    REQUIRE(dat.get_status() == 12);
    REQUIRE(dat.get_install_txt().substr(0, test_text.size()) == test_text);

    REQUIRE(dat.get_system_transducer_configuration() ==
            t_KMALLSystemTransducerConfiguration::SingleTxSingleRx);
    REQUIRE(dat.is_dual_rx() == false);

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KMALLDatagramIdentifier::I_INSTALLATION_PARAM);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));

    REQUIRE(dat.get_bytes_datagram() == dat.get_bytes_datagram_check());
    CHECK(dat.binary_hash() == 7356458248918231941ULL);
}
