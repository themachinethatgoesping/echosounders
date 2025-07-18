// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

#include "../themachinethatgoesping/echosounders/simradraw/datagrams/FIL1.hpp"
#include <themachinethatgoesping/tools/helper/approx.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::echosounders::simradraw::datagrams::FIL1;

#define TESTTAG "[simradraw]"

TEST_CASE("FIL1 should support common functions", TESTTAG)
{
    // initialize class structure
    FIL1 dat;

    // set some variables
    dat.set_timestamp(123);
    dat.set_stage(10);
    dat.set_decimation_factor(3);
    dat.set_channel_id("channel1");
    auto coeff = xt::xtensor<simradraw_float, 2>({ { 1, 2, 3, 4 }, { 5, 6, 7, 8 } });
    dat.set_coefficients(coeff);

    auto dat2 = dat;
    dat2.set_channel_id("channel2");

    // test inequality
    REQUIRE(dat != dat2);
    REQUIRE(dat != FIL1());

    // test empty equality (check e.g. nan compare problems)
    REQUIRE(FIL1() == FIL1());

    // test copy
    REQUIRE(dat == FIL1(dat));
    REQUIRE(dat2 == FIL1(dat2));

    // test binary
    REQUIRE(dat == FIL1::from_binary(dat.to_binary()));
    REQUIRE(dat2 == FIL1::from_binary(dat2.to_binary()));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == FIL1(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    // --- test data access ---
    REQUIRE(dat.get_stage() == 10);
    REQUIRE(dat.get_channel_id().substr(0, 7) == "channel");
    REQUIRE(dat.get_decimation_factor() == 3);
    REQUIRE(dat.get_no_of_coefficients() == 4);
    REQUIRE(dat.get_coefficients().size() == 8);
    auto coeff2 = dat.get_coefficients();
    REQUIRE(themachinethatgoesping::tools::helper::approx_container(xt::flatten(coeff2),
                                                                    xt::flatten(coeff)));

    auto xcoeff = dat.get_coefficients();
    REQUIRE(xcoeff.shape()[0] == 2);
    REQUIRE(xcoeff.shape()[1] == 4);
    REQUIRE(xcoeff(0, 0) == 1);
    REQUIRE(xcoeff(0, 1) == 2);

    //--- datagram concept ---

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_SimradRawDatagramIdentifier::FIL1);
    REQUIRE(dat.get_length() ==
            simradraw_long(12 + 136 + dat.get_no_of_coefficients() * 2 * sizeof(simradraw_float)));
}
