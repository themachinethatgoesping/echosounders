// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <themachinethatgoesping/echosounders/pingtools/pingsampleselector.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::pingtools;
#define TESTTAG "[filetemplates]"

TEST_CASE("PingSampleselector should support common functions", TESTTAG)
{
    // initialize class structure
    auto obj = PingSampleSelector();

    // set some variables
    obj.select_transducer_ids({ "a", "b", "c" });
    obj.select_ignored_transducer_ids({ "d", "e", "f" });
    REQUIRE(obj.get_transducer_ids() == std::set<std::string>({ "a", "b", "c" }));
    REQUIRE(obj.get_ignored_transducer_ids() == std::set<std::string>({ "d", "e", "f" }));
    obj.clear_transducer_ids();
    REQUIRE(obj.get_transducer_ids() == std::nullopt);
    obj.clear_ignored_transducer_ids();
    REQUIRE(obj.get_ignored_transducer_ids() == std::nullopt);

    obj.select_beam_range_by_numbers(1, -1, 1);
    REQUIRE(obj.get_min_beam_number() == 1);
    REQUIRE(obj.get_max_beam_number() == -1);
    REQUIRE(obj.get_beam_step() == 1);

    obj.select_sample_range_by_numbers(-2, 2, -2);
    REQUIRE(obj.get_min_sample_number() == -2);
    REQUIRE(obj.get_max_sample_number() == 2);
    REQUIRE(obj.get_sample_step() == -2);

    obj.select_beam_range_by_angles(-3.3, 4.4, 10);
    REQUIRE(obj.get_min_beam_angle() == Catch::Approx(-3.3));
    REQUIRE(obj.get_max_beam_angle() == Catch::Approx(4.4));
    REQUIRE(obj.get_beam_step() == 10);

    obj.select_sample_range_by_ranges(4.3, -5.4, 20);
    REQUIRE(obj.get_min_sample_range() == Catch::Approx(4.3));
    REQUIRE(obj.get_max_sample_range() == Catch::Approx(-5.4));
    REQUIRE(obj.get_sample_step() == 20);

    obj.set_sample_step(12);
    REQUIRE(obj.get_sample_step() == 12);
    obj.set_beam_step(13);
    REQUIRE(obj.get_beam_step() == 13);

    // test inequality
    REQUIRE(obj != PingSampleSelector());

    // test copy
    REQUIRE(obj == PingSampleSelector(obj));

    // test binary
    REQUIRE(obj == PingSampleSelector(obj.from_binary(obj.to_binary())));

    // test stream
    std::stringstream buffer;
    obj.to_stream(buffer);
    REQUIRE(obj == PingSampleSelector(obj.from_stream(buffer)));

    // test print does not crash
    REQUIRE(obj.info_string().size() != 0);

    //--- Class concept ---
    obj.clear();
    REQUIRE(obj == PingSampleSelector());
}
