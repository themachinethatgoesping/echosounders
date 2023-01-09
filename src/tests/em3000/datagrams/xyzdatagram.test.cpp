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
using themachinethatgoesping::echosounders::em3000::datagrams::XYZDatagram;
using themachinethatgoesping::echosounders::em3000::datagrams::XYZBeam;

#define TESTTAG "[em3000]"

TEST_CASE("XYZDatagram should support common functions", TESTTAG)
{
      // initialize class structure
    auto dat = XYZDatagram();
    auto beam = XYZBeam();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);
    
    dat.set_sound_speed(201);

    beam.beam_incidence_angle_adjustment = 101;
    dat.set_beams({beam});

    // test inequality
    REQUIRE(dat != XYZDatagram());

    // test copy
    REQUIRE(dat == XYZDatagram(dat));

    // test binary
    dat.print(std::cerr);
    std::cerr << "--- new ---" << std::endl;
    XYZDatagram(dat.from_binary(dat.to_binary())).print(std::cerr);
    REQUIRE(dat == XYZDatagram(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == XYZDatagram(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(dat.get_bytes() == 100); // this is of cause wrong because bytes was not adapted to the actual number of bytes

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_EM3000DatagramIdentifier::XYZDatagram);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));

}
