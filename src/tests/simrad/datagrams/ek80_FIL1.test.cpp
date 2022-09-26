// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <filesystem>

#include <xtensor/xio.hpp>

#include "../themachinethatgoesping/echosounders/simrad/datagrams/ek80_FIL1.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::echosounders::simrad::datagrams::EK80_FIL1;

#define TESTTAG "[simrad]"

TEST_CASE("EK80_FIL1 should support common functions", TESTTAG)
{
    // initialize class structure
    EK80_FIL1 dat;

    // set some variables
    dat.set_timestamp(123);
    dat._Stage            = 10;
    dat._DecimationFactor = 3;
    dat._ChannelID        = "channel1";
    auto coeff            = xt::xtensor<ek60_float, 2>({ { 1, 2, 3, 4 }, { 5, 6, 7, 8 } });
    dat._Coefficients     = coeff;

    auto dat2       = dat;
    dat2._ChannelID = "channel2";

    // test inequality
    REQUIRE(dat != dat2);
    REQUIRE(dat != EK80_FIL1());

    // test empty equality (check e.g. nan compare problems)
    REQUIRE(EK80_FIL1() == EK80_FIL1());

    // test copy
    REQUIRE(dat == EK80_FIL1(dat));
    REQUIRE(dat2 == EK80_FIL1(dat2));

    // test binary
    REQUIRE(dat == EK80_FIL1::from_binary(dat.to_binary()));
    REQUIRE(dat2 == EK80_FIL1::from_binary(dat2.to_binary()));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == EK80_FIL1(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(dat.get_stage() == 10);
    REQUIRE(dat.get_channel_id().substr(0, 7) == "channel");
    REQUIRE(dat.get_decimation_factor() == 3);
    REQUIRE(dat.get_no_of_coefficients() == 4);
    REQUIRE(dat.get_coefficients().size() == 8);
    REQUIRE(themachinethatgoesping::tools::helper::approx_container(
        xt::flatten(dat._Coefficients), xt::flatten(coeff)));

    auto xcoeff = dat.get_coefficients();
    REQUIRE(xcoeff.shape()[0] == 2);
    REQUIRE(xcoeff.shape()[1] == 4);
    REQUIRE(xcoeff(0,0) == 1);
    REQUIRE(xcoeff(0,1) == 2);

    //--- datagram concept ---

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_EK60_DatagramType::FIL1);
    REQUIRE(dat.get_length() ==
            ek60_long(12 + 136 + dat._NoOfCoefficients * 2 * sizeof(ek60_float)));
}
