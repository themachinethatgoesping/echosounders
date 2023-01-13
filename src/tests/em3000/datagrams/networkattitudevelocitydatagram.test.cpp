// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/em3000/datagrams/networkattitudevelocitydatagram.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::em3000::datagrams;
#define TESTTAG "[em3000]"

TEST_CASE("NetworkAttitudeVelocityDatagram should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat      = NetworkAttitudeVelocityDatagram();
    auto attitude = substructures::NetworkAttitudeVelocityDatagramAttitude();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_network_attitude_counter(202);
    dat.set_system_serial_number(203);

    attitude.set_time(101);
    attitude.set_pitch(191);
    dat.set_attitudes({ attitude });

    // test inequality
    // REQUIRE(dat != NetworkAttitudeVelocityDatagram());

    // test copy
    REQUIRE(dat == NetworkAttitudeVelocityDatagram(dat));

    dat.print(std::cerr);
    dat.from_binary(dat.to_binary());
    return;

    // test binary
    REQUIRE(dat == NetworkAttitudeVelocityDatagram(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == NetworkAttitudeVelocityDatagram(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    REQUIRE(dat.get_network_attitude_counter() == Catch::Approx(202));
    REQUIRE(dat.get_system_serial_number() == Catch::Approx(203));
    REQUIRE(dat.attitudes()[0].get_time_in_seconds() == Catch::Approx(0.101));
    REQUIRE(dat.attitudes()[0].get_pitch_in_degrees() == Catch::Approx(1.91));

    // datagram type
    REQUIRE(dat.get_datagram_identifier() ==
            t_EM3000DatagramIdentifier::NetworkAttitudeVelocityDatagram);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
