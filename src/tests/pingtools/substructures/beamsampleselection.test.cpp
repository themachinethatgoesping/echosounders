// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <xtensor/xtensor.hpp>

#include <themachinethatgoesping/echosounders/pingtools/substructures/beamsampleselection.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::pingtools::substructures;
#define TESTTAG "[filetemplates]"

TEST_CASE("BeamSampleSelection should support common functions", TESTTAG)
{
    // initialize class structure
    auto obj = BeamSampleSelection(2);

    // add some beams
    obj.add_beam(0, 1, 10);
    obj.add_beam(1, 3, 11);
    obj.add_beam(2, 2, 10);
    obj.add_beam(4, 1, 9);

    // test variables
    REQUIRE(obj.get_sample_step_ensemble() == 2);
    REQUIRE(obj.get_first_sample_number_ensemble() == 1);
    REQUIRE(obj.get_last_sample_number_ensemble() == 11);
    REQUIRE(obj.get_number_of_beams() == 4);
    REQUIRE(obj.get_number_of_samples_ensemble() == 6);

    REQUIRE(obj.get_beam_numbers() == std::vector<uint16_t>{ 0, 1, 2, 4 });
    REQUIRE(obj.get_first_sample_number_per_beam() == std::vector<uint16_t>{ 1, 3, 2, 1 });
    REQUIRE(obj.get_last_sample_number_per_beam() == std::vector<uint16_t>{ 10, 11, 10, 9 });

    // test alternative intialization
    xt::xtensor<uint16_t, 1> start_range_sample_numbers{ 1, 3, 2 };
    xt::xtensor<uint16_t, 1> number_of_samples_per_beam{ 10, 9, 9 };
    auto last_sample_numbers = start_range_sample_numbers + number_of_samples_per_beam - 1;
    auto obj2                = BeamSampleSelection(
        std::vector<uint16_t>(start_range_sample_numbers.begin(), start_range_sample_numbers.end()),
        std::vector<uint16_t>(last_sample_numbers.begin(), last_sample_numbers.end()),
        3);

    // test variables alternative
    obj2.print(std::cerr);
    REQUIRE(obj2.get_sample_step_ensemble() == 3);
    REQUIRE(obj2.get_first_sample_number_ensemble() == 1);
    REQUIRE(obj2.get_last_sample_number_ensemble() == 11);
    REQUIRE(obj2.get_number_of_beams() == 3);
    REQUIRE(obj2.get_number_of_samples_ensemble() == 4);

    REQUIRE(obj2.get_beam_numbers() == std::vector<uint16_t>{ 0, 1, 2 });
    REQUIRE(obj2.get_first_sample_number_per_beam() == std::vector<uint16_t>{ 1, 3, 2 });
    REQUIRE(obj2.get_last_sample_number_per_beam() == std::vector<uint16_t>{ 10, 11, 10 });

    REQUIRE(obj != obj2);
    obj2.add_beam(4, 1, 9);
    obj2.set_sample_step_ensemble(2);
    obj.print(std::cerr);
    obj2.print(std::cerr);
    REQUIRE(obj == obj2);

    // test inequality
    REQUIRE(obj != BeamSampleSelection());

    // test copy
    REQUIRE(obj == BeamSampleSelection(obj));

    // test binary
    REQUIRE(obj == BeamSampleSelection(obj.from_binary(obj.to_binary())));

    // test stream
    std::stringstream buffer;
    obj.to_stream(buffer);
    REQUIRE(obj == BeamSampleSelection(obj.from_stream(buffer)));

    // test print does not crash
    REQUIRE(obj.info_string().size() != 0);

    //--- Class concept ---
}
