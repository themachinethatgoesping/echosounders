// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/gsf/datagrams/gsfunknown.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::gsf;
using namespace themachinethatgoesping::echosounders::gsf::datagrams;
#define TESTTAG "[gsf]"

TEST_CASE("GSFUnknown should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = GSFUnknown();
    // data
    dat.set_record_identifier(std::string_view("SWATH_BATHYMETRY"));
    dat.set_raw_content(std::string(123, 'a'));

    // test inequality
    // REQUIRE(dat != GSFUnknown());

    // test copy
    REQUIRE(dat == GSFUnknown(dat));

    // test binary
    REQUIRE(dat == GSFUnknown(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == GSFUnknown(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_size_of_data() ==
        123); // this is of cause wrong because bytes was not adapted to the actual number of bytes

    REQUIRE(std::isnan(dat.get_timestamp()));

    // datagram type
    REQUIRE(dat.get_record_identifier() == "SWATH_BATHYMETRY");
}
