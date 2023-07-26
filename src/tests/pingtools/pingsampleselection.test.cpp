// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <themachinethatgoesping/echosounders/pingtools/pingsampleselection.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::pingtools;
#define TESTTAG "[filetemplates]"

TEST_CASE("PingSampleSelection should support common functions", TESTTAG)
{
    // initialize class structure
    auto obj = PingSampleSelection();

    // set some variables
    
    // test inequality
    //REQUIRE(obj != PingSampleSelection());

    // test copy
    REQUIRE(obj == PingSampleSelection(obj));

    // test binary
    REQUIRE(obj == PingSampleSelection(obj.from_binary(obj.to_binary())));

    // test stream
    std::stringstream buffer;
    obj.to_stream(buffer);
    REQUIRE(obj == PingSampleSelection(obj.from_stream(buffer)));

    // test print does not crash
    REQUIRE(obj.info_string().size() != 0);

    //--- Class concept ---
    //obj.clear();
    REQUIRE(obj == PingSampleSelection());
}
