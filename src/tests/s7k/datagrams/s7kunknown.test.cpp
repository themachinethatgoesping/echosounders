// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <cmath>
#include <sstream>

#include "../themachinethatgoesping/echosounders/s7k/datagrams/s7kunknown.hpp"

using namespace std;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::s7k::datagrams;
#define TESTTAG "[s7k]"

TEST_CASE("S7KUnknown should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = S7KUnknown();
    // data
    dat.set_raw_content(std::string(123, 'a'));

    // test copy
    REQUIRE(dat == S7KUnknown(dat));

    // test binary
    REQUIRE(dat == S7KUnknown(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == S7KUnknown(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    // the raw content is stored as-is, and the size field is updated to include the DRF header
    REQUIRE(dat.get_raw_content().size() == 123);
    REQUIRE(dat.compute_size_content() == 123);

    // a default constructed datagram has no valid time
    REQUIRE(std::isnan(dat.get_timestamp()));
}
