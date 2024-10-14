// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <themachinethatgoesping/echosounders/kongsbergall/types.hpp>
#include <themachinethatgoesping/echosounders/simradraw/types.hpp>

// note: this must be defined below the kongsbergall/simradraw includes otherwise
// datagram_identifier_to_string is unknown
#include <themachinethatgoesping/algorithms/amplitudecorrection/functions/rangecorrection.hpp>
#include <themachinethatgoesping/algorithms/amplitudecorrection/functions/wcicorrection.hpp>
#include <themachinethatgoesping/echosounders/filetemplates/datatypes/calibration/amplitudecalibration.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;
using namespace themachinethatgoesping::algorithms::amplitudecorrection::functions;
using namespace themachinethatgoesping::echosounders;
#define TESTTAG "[AmplitudeCalibration]"

TEST_CASE("AmplitudeCalibration support common functions", TESTTAG)
{
    auto obj  = AmplitudeCalibration();
    auto obj2 = AmplitudeCalibration(1.0f);

    // test hash
    CHECK(obj.binary_hash() == 3244421341483603138ULL);
    CHECK(obj2.binary_hash() == 17904910546364380078ULL);

    // test equality
    // test inequality
    CHECK(obj == obj);
    CHECK(obj2 == obj2);
    CHECK(obj != obj2);

    // test initialized
    // CHECK(obj.initialized() == false);
    // CHECK(obj2.initialized() == true);

    // test copy
    {
        INFO(obj.info_string());
        INFO(AmplitudeCalibration(obj).info_string());
        CHECK(obj == AmplitudeCalibration(obj));
    }

    // test binary
    CHECK(obj == AmplitudeCalibration(obj.from_binary(obj.to_binary())));

    // test stream
    std::stringstream buffer;
    obj.to_stream(buffer);
    CHECK(obj == AmplitudeCalibration(obj.from_stream(buffer)));

    // test print does not crash
    CHECK(obj.info_string().size() != 0);

    // test data access
    CHECK(obj2.get_system_offset() == 1.0f);
}

TEST_CASE("AmplitudeCalibration should wci corrections from wcicorrections.hpp", TESTTAG)
{
    using Catch::Approx;

    SECTION(
        "apply_beam_sample_correction and inplace_beam_sample_correction (applied to full array)")
    {
        for (float absorption : { 0.f, 0.0124f })
            for (float tvg_factor : { 0.f, -12.f, 22.f })
            {

                xt::xtensor<float, 2> wci = xt::eval(xt::ones<float>({ 10, 20 }));
                xt::xtensor<float, 1> per_beam_offset =
                    xt::eval(xt::linspace<float>(-5.5, 10.5, 10));
                auto                  per_beam_offset_0 = xt::zeros_like(per_beam_offset);
                xt::xtensor<float, 1> per_sample_offset =
                    xt::eval(xt::linspace<float>(-2.5, 35.2, 20));
                auto per_sample_offset_0 = xt::zeros_like(per_sample_offset);

                xt::xtensor<float, 1> beam_angles = xt::eval(xt::linspace<float>(-30, 30, 10));
                xt::xtensor<float, 1> ranges      = xt::eval(xt::linspace<float>(0.5, 30, 20));

                xt::xtensor<float, 1> range_varying_offset =
                    compute_cw_range_correction(ranges, absorption, tvg_factor);

                for (size_t mp_cores : { 1, 0, 4 })
                {
                    for (float system_offset : { 0, -12, 13 })
                    {
                        // create reference result
                        xt::xtensor<float, 2> result_so_ref = xt::eval(apply_beam_sample_correction(
                            xt::eval(wci + system_offset),
                            per_beam_offset_0,
                            xt::eval(per_sample_offset_0 + range_varying_offset)));

                        xt::xtensor<float, 2> result_bs_ref = xt::eval(apply_beam_sample_correction(
                            xt::eval(wci + system_offset),
                            per_beam_offset,
                            xt::eval(per_sample_offset + range_varying_offset)));

                        xt::xtensor<float, 2> result_b_ref = xt::eval(apply_beam_sample_correction(
                            xt::eval(wci + system_offset),
                            per_beam_offset,
                            xt::eval(per_sample_offset_0 + range_varying_offset)));

                        xt::xtensor<float, 2> result_s_ref = xt::eval(apply_beam_sample_correction(
                            xt::eval(wci + system_offset),
                            per_beam_offset_0,
                            xt::eval(per_sample_offset + range_varying_offset)));

                        REQUIRE(result_so_ref.size() ==
                                result_so_ref.shape(0) * result_so_ref.shape(1));
                        REQUIRE(result_bs_ref.size() ==
                                result_bs_ref.shape(0) * result_bs_ref.shape(1));
                        REQUIRE(result_b_ref.size() ==
                                result_b_ref.shape(0) * result_b_ref.shape(1));
                        REQUIRE(result_s_ref.size() ==
                                result_s_ref.shape(0) * result_s_ref.shape(1));

                        std::map<std::string, xt::xtensor<float, 2>> results_bs = {
                            { "reference", result_bs_ref }
                        };
                        std::map<std::string, xt::xtensor<float, 2>> results_b = {
                            { "reference", result_b_ref }
                        };
                        std::map<std::string, xt::xtensor<float, 2>> results_s = {
                            { "reference", result_s_ref }
                        };
                        std::map<std::string, xt::xtensor<float, 2>> results_so = {
                            { "reference", result_so_ref }
                        };

                        // create base amplitude calibration
                        // cal.set_offset_per_beamangle(per_beam_offset);
                        // cal.set_offset_per_range(per_sample_offset);

                        // --- apply system offset correction ---
                        auto cal = AmplitudeCalibration(system_offset);
                        results_so["FULL-apply_system_offset"] =
                            xt::eval(cal.apply_beam_sample_correction(
                                wci, beam_angles, ranges, absorption, tvg_factor, mp_cores));

                        // inplace
                        xt::xtensor<float, 2> result = wci;
                        cal.inplace_beam_sample_correction(result,
                                                           beam_angles,
                                                           ranges,
                                                           absorption,
                                                           tvg_factor,
                                                           std::nullopt,
                                                           std::nullopt,
                                                           mp_cores);
                        results_so["FULL-inplace_system_offset"] = result;

                        // --- apply sample offset correction ---
                        cal = AmplitudeCalibration(system_offset);
                        cal.set_offset_per_range(ranges, per_sample_offset);
                        results_s["FULL-apply_sample_correction"] =
                            xt::eval(cal.apply_beam_sample_correction(
                                wci, beam_angles, ranges, absorption, tvg_factor, mp_cores));

                        // inplace
                        result = wci;
                        cal.inplace_beam_sample_correction(result,
                                                           beam_angles,
                                                           ranges,
                                                           absorption,
                                                           tvg_factor,
                                                           std::nullopt,
                                                           std::nullopt,
                                                           mp_cores);
                        results_s["FULL-inplace_sample_correction"] = result;

                        // --- apply beam offset correction ---
                        cal = AmplitudeCalibration(system_offset);
                        cal.set_offset_per_beamangle(beam_angles, per_beam_offset);
                        results_b["FULL-apply_beam_correction"] =
                            xt::eval(cal.apply_beam_sample_correction(
                                wci, beam_angles, ranges, absorption, tvg_factor, mp_cores));

                        // inplace
                        result = wci;
                        cal.inplace_beam_sample_correction(result,
                                                           beam_angles,
                                                           ranges,
                                                           absorption,
                                                           tvg_factor,
                                                           std::nullopt,
                                                           std::nullopt,
                                                           mp_cores);
                        results_b["FULL-inplace_beam_correction"] = result;

                        // --- apply beam sample offset correction ---
                        cal = AmplitudeCalibration(system_offset);
                        cal.set_offset_per_beamangle(beam_angles, per_beam_offset);
                        cal.set_offset_per_range(ranges, per_sample_offset);
                        results_bs["FULL-apply_beam_sample_correction"] =
                            xt::eval(cal.apply_beam_sample_correction(
                                wci, beam_angles, ranges, absorption, tvg_factor, mp_cores));

                        // inplace
                        result = wci;
                        cal.inplace_beam_sample_correction(result,
                                                           beam_angles,
                                                           ranges,
                                                           absorption,
                                                           tvg_factor,
                                                           std::nullopt,
                                                           std::nullopt,
                                                           mp_cores);
                        results_bs["FULL-inplace_beam_sample_correction"] = result;

                        for (const auto& results : { results_bs, results_b, results_s, results_so })
                        {
                            const auto& result_base = results.at("reference");

                            for (const auto& [key, result] : results)
                            {
                                // INFO(fmt::format("key {}, system_offset: {}, mp_cores: {}, "
                                //                  "absorption: {}, tvg_factor: {}",
                                //                  key,
                                //                  system_offset,
                                //                  mp_cores,
                                //                  absorption,
                                //                  tvg_factor));
                                REQUIRE(result_base.shape() == result.shape());

                                for (size_t i = 0; i < result_base.size(); i++)
                                {
                                    // INFO(fmt::format("i: {}", i));
                                    REQUIRE(std::fabs(result_base.flat(i) - result.flat(i)) <
                                            0.0001f);
                                }
                            }
                        }
                    }
                }
            }
    }

    SECTION("PARTIAL apply_beam_sample_correction and inplace_beam_sample_correction (applied to "
            "array section)")
    {
        for (float absorption : { 0.f, 0.0124f })
            for (float tvg_factor : { 0.f, -12.f, 22.f })
            {

                xt::xtensor<float, 2> wci = xt::eval(xt::ones<float>({ 10, 20 }));
                xt::xtensor<float, 1> per_beam_offset =
                    xt::eval(xt::linspace<float>(-5.5, 10.5, 10));
                auto                  per_beam_offset_0 = xt::zeros_like(per_beam_offset);
                xt::xtensor<float, 1> per_sample_offset =
                    xt::eval(xt::linspace<float>(-2.5, 35.2, 20));
                auto per_sample_offset_0 = xt::zeros_like(per_sample_offset);

                xt::xtensor<float, 1> beam_angles = xt::eval(xt::linspace<float>(-30, 30, 10));
                xt::xtensor<float, 1> ranges      = xt::eval(xt::linspace<float>(0.5, 30, 20));

                xt::xtensor<float, 1> range_varying_offset =
                    compute_cw_range_correction(ranges, absorption, tvg_factor);

                for (size_t mp_cores : { 1, 0, 4 })
                    for (float system_offset : { 0, -12, 13 })
                        for (std::optional<size_t> min_bn :
                             std::vector<std::optional<size_t>>{ std::nullopt, 0, 7, 10, 999999 })
                            for (std::optional<size_t> max_bn : std::vector<std::optional<size_t>>{
                                     std::nullopt, 0, 3, 10, 999999 })
                            {
                                // create reference result
                                xt::xtensor<float, 2> result_so_ref = wci;
                                inplace_beam_sample_correction(
                                    result_so_ref,
                                    xt::eval(per_beam_offset_0 + system_offset),
                                    xt::eval(per_sample_offset_0 + range_varying_offset),
                                    min_bn,
                                    max_bn);

                                xt::xtensor<float, 2> result_bs_ref = wci;
                                inplace_beam_sample_correction(
                                    result_bs_ref,
                                    xt::eval(per_beam_offset + system_offset),
                                    xt::eval(per_sample_offset + range_varying_offset),
                                    min_bn,
                                    max_bn);

                                xt::xtensor<float, 2> result_b_ref = wci;
                                inplace_beam_sample_correction(
                                    result_b_ref,
                                    xt::eval(per_beam_offset + system_offset),
                                    xt::eval(per_sample_offset_0 + range_varying_offset),
                                    min_bn,
                                    max_bn);

                                xt::xtensor<float, 2> result_s_ref = wci;
                                inplace_beam_sample_correction(
                                    result_s_ref,
                                    xt::eval(per_beam_offset_0 + system_offset),
                                    xt::eval(per_sample_offset + range_varying_offset),
                                    min_bn,
                                    max_bn);

                                REQUIRE(result_so_ref.size() ==
                                        result_so_ref.shape(0) * result_so_ref.shape(1));
                                REQUIRE(result_bs_ref.size() ==
                                        result_bs_ref.shape(0) * result_bs_ref.shape(1));
                                REQUIRE(result_b_ref.size() ==
                                        result_b_ref.shape(0) * result_b_ref.shape(1));
                                REQUIRE(result_s_ref.size() ==
                                        result_s_ref.shape(0) * result_s_ref.shape(1));

                                std::map<std::string, xt::xtensor<float, 2>> results_bs = {
                                    { "reference", result_bs_ref }
                                };
                                std::map<std::string, xt::xtensor<float, 2>> results_b = {
                                    { "reference", result_b_ref }
                                };
                                std::map<std::string, xt::xtensor<float, 2>> results_s = {
                                    { "reference", result_s_ref }
                                };
                                std::map<std::string, xt::xtensor<float, 2>> results_so = {
                                    { "reference", result_so_ref }
                                };

                                // create base amplitude calibration
                                std::string name = fmt::format("PARTIAL(");
                                if (min_bn.has_value())
                                    name += fmt::format("min_bn: {}", min_bn.value());
                                if (max_bn.has_value())
                                    name += fmt::format("max_bn: {}", max_bn.value());
                                name += ")";

                                // --- apply system offset correction ---
                                auto                  cal    = AmplitudeCalibration(system_offset);
                                xt::xtensor<float, 2> result = wci;
                                cal.inplace_beam_sample_correction(result,
                                                                   beam_angles,
                                                                   ranges,
                                                                   absorption,
                                                                   tvg_factor,
                                                                   min_bn,
                                                                   max_bn,
                                                                   mp_cores);
                                results_so[name + "-inplace_system_offset"] = result;

                                // --- apply sample offset correction ---
                                cal = AmplitudeCalibration(system_offset);
                                cal.set_offset_per_range(ranges, per_sample_offset);
                                result = wci;
                                cal.inplace_beam_sample_correction(result,
                                                                   beam_angles,
                                                                   ranges,
                                                                   absorption,
                                                                   tvg_factor,
                                                                   min_bn,
                                                                   max_bn,
                                                                   mp_cores);
                                results_s[name + "-inplace_sample_correction"] = result;

                                // --- apply beam offset correction ---
                                cal = AmplitudeCalibration(system_offset);
                                cal.set_offset_per_beamangle(beam_angles, per_beam_offset);
                                result = wci;
                                cal.inplace_beam_sample_correction(result,
                                                                   beam_angles,
                                                                   ranges,
                                                                   absorption,
                                                                   tvg_factor,
                                                                   min_bn,
                                                                   max_bn,
                                                                   mp_cores);
                                results_b[name + "-inplace_beam_correction"] = result;

                                // --- apply beam sample offset correction ---
                                cal = AmplitudeCalibration(system_offset);
                                cal.set_offset_per_beamangle(beam_angles, per_beam_offset);
                                cal.set_offset_per_range(ranges, per_sample_offset);
                                result = wci;
                                cal.inplace_beam_sample_correction(result,
                                                                   beam_angles,
                                                                   ranges,
                                                                   absorption,
                                                                   tvg_factor,
                                                                   min_bn,
                                                                   max_bn,
                                                                   mp_cores);
                                results_bs[name + "-inplace_beam_sample_correction"] = result;

                                for (const auto& results :
                                     { results_bs, results_b, results_s, results_so })
                                {
                                    const auto& result_base = results.at("reference");

                                    for (const auto& [key, result] : results)
                                    {
                                        // INFO(fmt::format("key {}, system_offset: {}, mp_cores:
                                        // {}, "
                                        //                  "absorption: {}, tvg_factor: {}",
                                        //                  key,
                                        //                  system_offset,
                                        //                  mp_cores,
                                        //                  absorption,
                                        //                  tvg_factor));
                                        REQUIRE(result_base.shape() == result.shape());

                                        for (size_t i = 0; i < result_base.size(); i++)
                                        {
                                            // INFO(fmt::format("i: {} ref: {} result: {}",
                                            //                  i,
                                            //                  result_base.flat(i),
                                            //                  result.flat(i)));
                                            REQUIRE(std::fabs(result_base.flat(i) -
                                                              result.flat(i)) < 0.0001f);
                                        }
                                    }
                                }
                            }
            }
    }
}
