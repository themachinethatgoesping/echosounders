// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <themachinethatgoesping/echosounders/kongsbergall/types.hpp>
#include <themachinethatgoesping/echosounders/simradraw/types.hpp>

// note: this must be defined below the kongsbergall/simradraw includes otherwise
// datagram_identifier_to_string is unknown
#include <themachinethatgoesping/echosounders/filetemplates/datatypes/calibration/watercolumncalibration.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;
using namespace themachinethatgoesping::echosounders;
#define TESTTAG "[WaterColumnCalibration]"

TEST_CASE("DatagramInfoDatashould support common functions", TESTTAG)
{
    auto obj0 = AmplitudeCalibration(1.0f);

    auto obj  = WaterColumnCalibration();
    auto obj2 = WaterColumnCalibration(obj0, AmplitudeCalibration(), AmplitudeCalibration());

    // test hash
    CHECK(obj.binary_hash() == 3020528168303537014ULL);
    CHECK(obj2.binary_hash() == 4714633842598101940ULL);

    // test equality
    // test inequality
    CHECK(obj == obj);
    CHECK(obj2 == obj2);
    CHECK(obj != obj2);

    // test initialized
    // CHECK(obj.initialized() == false);
    // CHECK(obj2.initialized() == true);

    // test getters/setters
    CHECK(obj2.has_power_calibration() == true);
    CHECK(obj2.has_sp_calibration() == false);
    CHECK(obj2.has_sv_calibration() == false);

    obj2.set_sv_calibration(obj0);
    CHECK(obj2.has_power_calibration() == true);
    CHECK(obj2.has_sp_calibration() == false);
    CHECK(obj2.has_sv_calibration() == true);

    obj2.set_sp_calibration(obj0);
    CHECK(obj2.has_power_calibration() == true);
    CHECK(obj2.has_sp_calibration() == true);
    CHECK(obj2.has_sv_calibration() == true);

    // test copy
    {
        INFO(obj.info_string());
        INFO(WaterColumnCalibration(obj).info_string());
        CHECK(obj == WaterColumnCalibration(obj));
    }

    // test binary
    CHECK(obj == WaterColumnCalibration(obj.from_binary(obj.to_binary())));

    // test stream
    std::stringstream buffer;
    obj.to_stream(buffer);
    CHECK(obj == WaterColumnCalibration(obj.from_stream(buffer)));

    // test print does not crash
    CHECK(obj.info_string().size() != 0);

    // test data access
    CHECK(obj2.get_power_calibration().get_system_offset() == 1.0f);
    CHECK(obj2.get_sp_calibration().get_system_offset() == 1.0f);
    CHECK(obj2.get_sv_calibration().get_system_offset() == 1.0f);
}

TEST_CASE("WaterColumnCalibration should wci corrections from wcicorrections.hpp", TESTTAG)
{
    using Catch::Approx;

    SECTION(
        "apply_beam_sample_correction and inplace_beam_sample_correction (applied to full array)")
    {

        using namespace themachinethatgoesping::algorithms::amplitudecorrection::functions;

        xt::xtensor<float, 2> wci               = xt::eval(xt::ones<float>({ 10, 20 }));
        xt::xtensor<float, 1> per_beam_offset   = xt::eval(xt::linspace<float>(-5.5, 10.5, 10));
        xt::xtensor<float, 1> per_sample_offset = xt::eval(xt::linspace<float>(-2.5, 35.2, 20));

        xt::xtensor<float, 1> beam_angles = xt::eval(xt::linspace<float>(-30, 30, 10));
        xt::xtensor<float, 1> ranges      = xt::eval(xt::linspace<float>(0.5, 30, 20));

        for (size_t mp_cores : { 1, 2 })
        {
            for (float system_offset : { 0, -12, 13 })
                for (std::optional<float> absorption :
                     std::vector<std::optional<float>>{ std::nullopt, 0.f, 0.0124f })
                    for (float tvg_absorption : { 0.f, 0.0234f })
                        for (float tvg_factor_applied : { 0, -19, 23 })
                        {
                            // create reference result
                            xt::xtensor<float, 1> range_varying_offset =
                                compute_cw_range_correction(
                                    ranges, -tvg_absorption, -tvg_factor_applied);
                            xt::xtensor<float, 2> result_power_ref =
                                xt::eval(apply_beam_sample_correction(
                                    xt::eval(wci + system_offset),
                                    per_beam_offset,
                                    xt::eval(per_sample_offset + range_varying_offset)));

                            range_varying_offset = compute_cw_range_correction(
                                ranges,
                                absorption.value_or(tvg_absorption) - tvg_absorption,
                                40 - tvg_factor_applied);
                            xt::xtensor<float, 2> result_ap_ref =
                                xt::eval(apply_beam_sample_correction(
                                    xt::eval(wci + system_offset * 1.23f),
                                    per_beam_offset,
                                    xt::eval(per_sample_offset + range_varying_offset)));

                            range_varying_offset = compute_cw_range_correction(
                                ranges,
                                absorption.value_or(tvg_absorption) - tvg_absorption,
                                20 - tvg_factor_applied);
                            xt::xtensor<float, 2> result_av_ref =
                                xt::eval(apply_beam_sample_correction(
                                    xt::eval(wci + system_offset * 2.34f),
                                    per_beam_offset,
                                    xt::eval(per_sample_offset + range_varying_offset)));

                            range_varying_offset = compute_cw_range_correction(
                                ranges,
                                absorption.value_or(tvg_absorption) - tvg_absorption,
                                40 - tvg_factor_applied);
                            xt::xtensor<float, 2> result_sp_ref =
                                xt::eval(apply_beam_sample_correction(
                                    xt::eval(wci + system_offset * 3.45f),
                                    per_beam_offset,
                                    xt::eval(per_sample_offset + range_varying_offset)));

                            range_varying_offset = compute_cw_range_correction(
                                ranges,
                                absorption.value_or(tvg_absorption) - tvg_absorption,
                                20 - tvg_factor_applied);
                            xt::xtensor<float, 2> result_sv_ref =
                                xt::eval(apply_beam_sample_correction(
                                    xt::eval(wci + system_offset * 4.56f),
                                    per_beam_offset,
                                    xt::eval(per_sample_offset + range_varying_offset)));

                            REQUIRE(result_power_ref.size() ==
                                    result_power_ref.shape(0) * result_power_ref.shape(1));
                            REQUIRE(result_ap_ref.size() ==
                                    result_ap_ref.shape(0) * result_ap_ref.shape(1));
                            REQUIRE(result_av_ref.size() ==
                                    result_av_ref.shape(0) * result_av_ref.shape(1));
                            REQUIRE(result_sp_ref.size() ==
                                    result_sp_ref.shape(0) * result_sp_ref.shape(1));
                            REQUIRE(result_sv_ref.size() ==
                                    result_sv_ref.shape(0) * result_sv_ref.shape(1));

                            std::map<std::string, xt::xtensor<float, 2>> results_power = {
                                { "reference", result_power_ref }
                            };
                            std::map<std::string, xt::xtensor<float, 2>> results_ap = {
                                { "reference", result_ap_ref }
                            };
                            std::map<std::string, xt::xtensor<float, 2>> results_av = {
                                { "reference", result_av_ref }
                            };
                            std::map<std::string, xt::xtensor<float, 2>> results_sp = {
                                { "reference", result_sp_ref }
                            };
                            std::map<std::string, xt::xtensor<float, 2>> results_sv = {
                                { "reference", result_sv_ref }
                            };

                            // create base amplitude calibration
                            auto cal_power = AmplitudeCalibration(system_offset);
                            auto cal_ap    = AmplitudeCalibration(system_offset * 1.23f);
                            auto cal_av    = AmplitudeCalibration(system_offset * 2.34f);
                            auto cal_sp    = AmplitudeCalibration(system_offset * 3.45f);
                            auto cal_sv    = AmplitudeCalibration(system_offset * 4.56f);

                            for (auto& cal : { &cal_power, &cal_ap, &cal_av, &cal_sp, &cal_sv })
                            {
                                cal->set_offset_per_beamangle(beam_angles, per_beam_offset);
                                cal->set_offset_per_range(ranges, per_sample_offset);
                            }

                            WaterColumnCalibration wcc(
                                cal_power, cal_ap, cal_av, tvg_absorption, tvg_factor_applied);
                            wcc.set_absorption_db_m(absorption);

                            REQUIRE_THROWS_AS(wcc.template apply_beam_sample_correction<
                                                  WaterColumnCalibration::t_calibration_type::sp>(
                                                  wci, beam_angles, ranges),
                                              std::runtime_error);
                            REQUIRE_THROWS_AS(wcc.template apply_beam_sample_correction<
                                                  WaterColumnCalibration::t_calibration_type::sv>(
                                                  wci, beam_angles, ranges),
                                              std::runtime_error);
                            wcc.set_sp_calibration(cal_sp);
                            wcc.set_sv_calibration(cal_sv);

                            // --- apply power correction ---
                            results_power["FULL-apply_power_calibration"] =
                                wcc.template apply_beam_sample_correction<
                                    WaterColumnCalibration::t_calibration_type::power>(
                                    wci, beam_angles, ranges, mp_cores);

                            // inplace
                            xt::xtensor<float, 2> result = wci;
                            wcc.template inplace_beam_sample_correction<
                                WaterColumnCalibration::t_calibration_type::power>(
                                result, beam_angles, ranges, std::nullopt, std::nullopt, mp_cores);
                            results_power["FULL-inplace_power_calibration"] = result;

                            // --- apply ap correction ---
                            results_ap["FULL-apply_ap_calibration"] =
                                wcc.template apply_beam_sample_correction<
                                    WaterColumnCalibration::t_calibration_type::ap>(
                                    wci, beam_angles, ranges, mp_cores);

                            // inplace
                            result = wci;
                            wcc.template inplace_beam_sample_correction<
                                WaterColumnCalibration::t_calibration_type::ap>(
                                result, beam_angles, ranges, std::nullopt, std::nullopt, mp_cores);
                            results_ap["FULL-inplace_ap_calibration"] = result;

                            // --- apply ap correction ---
                            results_av["FULL-apply_av_calibration"] =
                                wcc.template apply_beam_sample_correction<
                                    WaterColumnCalibration::t_calibration_type::av>(
                                    wci, beam_angles, ranges, mp_cores);

                            // inplace
                            result = wci;
                            wcc.template inplace_beam_sample_correction<
                                WaterColumnCalibration::t_calibration_type::av>(
                                result, beam_angles, ranges, std::nullopt, std::nullopt, mp_cores);
                            results_av["FULL-inplace_av_calibration"] = result;

                            // --- apply ap correction ---
                            results_sp["FULL-apply_sp_calibration"] =
                                wcc.template apply_beam_sample_correction<
                                    WaterColumnCalibration::t_calibration_type::sp>(
                                    wci, beam_angles, ranges, mp_cores);

                            // inplace
                            result = wci;
                            wcc.template inplace_beam_sample_correction<
                                WaterColumnCalibration::t_calibration_type::sp>(
                                result, beam_angles, ranges, std::nullopt, std::nullopt, mp_cores);
                            results_sp["FULL-inplace_sp_calibration"] = result;

                            // --- apply sv correction ---
                            results_sv["FULL-apply_sp_calibration"] =
                                wcc.template apply_beam_sample_correction<
                                    WaterColumnCalibration::t_calibration_type::sv>(
                                    wci, beam_angles, ranges, mp_cores);

                            // inplace
                            result = wci;
                            wcc.template inplace_beam_sample_correction<
                                WaterColumnCalibration::t_calibration_type::sv>(
                                result, beam_angles, ranges, std::nullopt, std::nullopt, mp_cores);
                            results_sv["FULL-inplace_sv_calibration"] = result;

                            for (const auto& results :
                                 { results_power, results_ap, results_av, results_sp, results_sv })
                            {
                                const auto& result_base = results.at("reference");

                                for (const auto& [key, result] : results)
                                {
                                    // INFO(fmt::format("key {}, system_offset: {}, mp_cores: {}, "
                                    //                  "absorption: {}, tvg_factor_applied: {}, "
                                    //                  "tvg_absorption: {}",
                                    //                  key,
                                    //                  system_offset,
                                    //                  mp_cores,
                                    //                  absorption.value_or(
                                    //                      std::numeric_limits<float>::quiet_NaN()),
                                    //                  tvg_factor_applied,
                                    //                  tvg_absorption));
                                    REQUIRE(result_base.shape() == result.shape());

                                    for (size_t i = 0; i < result_base.size(); i++)
                                    {
                                        // INFO(fmt::format("i: {} result_base: {}, result: {}",
                                        //                  i,
                                        //                  result_base.flat(i),
                                        //                  result.flat(i)));
                                        REQUIRE(std::fabs(result_base.flat(i) - result.flat(i)) <
                                                0.0001f);
                                    }
                                }
                            }
                        }
        }
    }

    SECTION("PARTIAL apply_beam_sample_correction and inplace_beam_sample_correction (applied "
            "section of the array)")
    {

        using namespace themachinethatgoesping::algorithms::amplitudecorrection::functions;

        xt::xtensor<float, 2> wci               = xt::eval(xt::ones<float>({ 10, 20 }));
        xt::xtensor<float, 1> per_beam_offset   = xt::eval(xt::linspace<float>(-5.5, 10.5, 10));
        xt::xtensor<float, 1> per_sample_offset = xt::eval(xt::linspace<float>(-2.5, 35.2, 20));

        xt::xtensor<float, 1> beam_angles = xt::eval(xt::linspace<float>(-30, 30, 10));
        xt::xtensor<float, 1> ranges      = xt::eval(xt::linspace<float>(0.5, 30, 20));

        for (size_t mp_cores : { 1,2})
        {
            for (float system_offset : { 0, -12, 13 })
                for (std::optional<float> absorption :
                     std::vector<std::optional<float>>{ std::nullopt, 0.f, 0.0124f })
                    for (float tvg_absorption : { 0.f, 0.0234f })
                        for (float tvg_factor_applied : { 0, -19, 23 })
                            for (std::optional<size_t> min_bn : std::vector<std::optional<size_t>>{
                                     std::nullopt, 0, 7, 10, 999999 })
                                for (std::optional<size_t> max_bn :
                                     std::vector<std::optional<size_t>>{
                                         std::nullopt, 0, 3, 10, 999999 })
                                {
                                    // create reference result
                                    xt::xtensor<float, 1> range_varying_offset =
                                        compute_cw_range_correction(
                                            ranges, -tvg_absorption, -tvg_factor_applied);
                                    xt::xtensor<float, 2> result_power_ref = wci;
                                    inplace_beam_sample_correction(
                                        result_power_ref,
                                        xt::eval(per_beam_offset + system_offset),
                                        xt::eval(per_sample_offset + range_varying_offset),
                                        min_bn,
                                        max_bn);

                                    range_varying_offset = compute_cw_range_correction(
                                        ranges,
                                        absorption.value_or(tvg_absorption) - tvg_absorption,
                                        40 - tvg_factor_applied);
                                    xt::xtensor<float, 2> result_ap_ref = wci;
                                    inplace_beam_sample_correction(
                                        result_ap_ref,
                                        xt::eval(per_beam_offset + system_offset * 1.23f),
                                        xt::eval(per_sample_offset + range_varying_offset),
                                        min_bn,
                                        max_bn);

                                    range_varying_offset = compute_cw_range_correction(
                                        ranges,
                                        absorption.value_or(tvg_absorption) - tvg_absorption,
                                        20 - tvg_factor_applied);
                                    xt::xtensor<float, 2> result_av_ref = wci;
                                    inplace_beam_sample_correction(
                                        result_av_ref,
                                        xt::eval(per_beam_offset + system_offset * 2.34f),
                                        xt::eval(per_sample_offset + range_varying_offset),
                                        min_bn,
                                        max_bn);

                                    range_varying_offset = compute_cw_range_correction(
                                        ranges,
                                        absorption.value_or(tvg_absorption) - tvg_absorption,
                                        40 - tvg_factor_applied);
                                    xt::xtensor<float, 2> result_sp_ref = wci;
                                    inplace_beam_sample_correction(
                                        result_sp_ref,
                                        xt::eval(per_beam_offset + system_offset * 3.45f),
                                        xt::eval(per_sample_offset + range_varying_offset),
                                        min_bn,
                                        max_bn);

                                    range_varying_offset = compute_cw_range_correction(
                                        ranges,
                                        absorption.value_or(tvg_absorption) - tvg_absorption,
                                        20 - tvg_factor_applied);
                                    xt::xtensor<float, 2> result_sv_ref = wci;
                                    inplace_beam_sample_correction(
                                        result_sv_ref,
                                        xt::eval(per_beam_offset + system_offset * 4.56f),
                                        xt::eval(per_sample_offset + range_varying_offset),
                                        min_bn,
                                        max_bn);

                                    REQUIRE(result_power_ref.size() ==
                                            result_power_ref.shape(0) * result_power_ref.shape(1));
                                    REQUIRE(result_ap_ref.size() ==
                                            result_ap_ref.shape(0) * result_ap_ref.shape(1));
                                    REQUIRE(result_av_ref.size() ==
                                            result_av_ref.shape(0) * result_av_ref.shape(1));
                                    REQUIRE(result_sp_ref.size() ==
                                            result_sp_ref.shape(0) * result_sp_ref.shape(1));
                                    REQUIRE(result_sv_ref.size() ==
                                            result_sv_ref.shape(0) * result_sv_ref.shape(1));

                                    std::map<std::string, xt::xtensor<float, 2>> results_power = {
                                        { "reference", result_power_ref }
                                    };
                                    std::map<std::string, xt::xtensor<float, 2>> results_ap = {
                                        { "reference", result_ap_ref }
                                    };
                                    std::map<std::string, xt::xtensor<float, 2>> results_av = {
                                        { "reference", result_av_ref }
                                    };
                                    std::map<std::string, xt::xtensor<float, 2>> results_sp = {
                                        { "reference", result_sp_ref }
                                    };
                                    std::map<std::string, xt::xtensor<float, 2>> results_sv = {
                                        { "reference", result_sv_ref }
                                    };

                                    // create base amplitude calibration
                                    auto cal_power = AmplitudeCalibration(system_offset);
                                    auto cal_ap    = AmplitudeCalibration(system_offset * 1.23f);
                                    auto cal_av    = AmplitudeCalibration(system_offset * 2.34f);
                                    auto cal_sp    = AmplitudeCalibration(system_offset * 3.45f);
                                    auto cal_sv    = AmplitudeCalibration(system_offset * 4.56f);

                                    for (auto& cal :
                                         { &cal_power, &cal_ap, &cal_av, &cal_sp, &cal_sv })
                                    {
                                        cal->set_offset_per_beamangle(beam_angles, per_beam_offset);
                                        cal->set_offset_per_range(ranges, per_sample_offset);
                                    }

                                    WaterColumnCalibration wcc(cal_power,
                                                               cal_ap,
                                                               cal_av,
                                                               tvg_absorption,
                                                               tvg_factor_applied);
                                    wcc.set_absorption_db_m(absorption);

                                    REQUIRE_THROWS_AS(
                                        wcc.template apply_beam_sample_correction<
                                            WaterColumnCalibration::t_calibration_type::sp>(
                                            wci, beam_angles, ranges),
                                        std::runtime_error);
                                    REQUIRE_THROWS_AS(
                                        wcc.template apply_beam_sample_correction<
                                            WaterColumnCalibration::t_calibration_type::sv>(
                                            wci, beam_angles, ranges),
                                        std::runtime_error);
                                    wcc.set_sp_calibration(cal_sp);
                                    wcc.set_sv_calibration(cal_sv);

                                    // --- apply power correction ---
                                    xt::xtensor<float, 2> result = wci;
                                    wcc.template inplace_beam_sample_correction<
                                        WaterColumnCalibration::t_calibration_type::power>(
                                        result, beam_angles, ranges, min_bn, max_bn, mp_cores);
                                    results_power["FULL-inplace_power_calibration"] = result;

                                    // --- apply ap correction ---
                                    result = wci;
                                    wcc.template inplace_beam_sample_correction<
                                        WaterColumnCalibration::t_calibration_type::ap>(
                                        result, beam_angles, ranges, min_bn, max_bn, mp_cores);
                                    results_ap["FULL-inplace_ap_calibration"] = result;

                                    // --- apply ap correction ---
                                    result = wci;
                                    wcc.template inplace_beam_sample_correction<
                                        WaterColumnCalibration::t_calibration_type::av>(
                                        result, beam_angles, ranges, min_bn, max_bn, mp_cores);
                                    results_av["FULL-inplace_av_calibration"] = result;

                                    // --- apply av correction ---
                                    result = wci;
                                    wcc.template inplace_beam_sample_correction<
                                        WaterColumnCalibration::t_calibration_type::sp>(
                                        result, beam_angles, ranges, min_bn, max_bn, mp_cores);
                                    results_sp["FULL-inplace_sp_calibration"] = result;

                                    // --- apply sv correction ---
                                    result = wci;
                                    wcc.template inplace_beam_sample_correction<
                                        WaterColumnCalibration::t_calibration_type::sv>(
                                        result, beam_angles, ranges, min_bn, max_bn, mp_cores);
                                    results_sv["FULL-inplace_sv_calibration"] = result;

                                    for (const auto& results : { results_power,
                                                                 results_ap,
                                                                 results_av,
                                                                 results_sp,
                                                                 results_sv })
                                    {
                                        const auto& result_base = results.at("reference");

                                        for (const auto& [key, result] : results)
                                        {
                                            // INFO(fmt::format(
                                            //     "key {}, system_offset: {}, mp_cores: {}, "
                                            //     "absorption: {}, tvg_factor_applied: {}, "
                                            //     "tvg_absorption: {}, min_bn: {}, max_bn: {}",
                                            //     key,
                                            //     system_offset,
                                            //     mp_cores,
                                            //     absorption.value_or(
                                            //         std::numeric_limits<float>::quiet_NaN()),
                                            //     tvg_factor_applied,
                                            //     tvg_absorption,
                                            //     min_bn.value_or(NAN),
                                            //     max_bn.value_or(NAN)));
                                            REQUIRE(result_base.shape() == result.shape());

                                            for (size_t i = 0; i < result_base.size(); i++)
                                            {
                                                // INFO(
                                                //     fmt::format("i: {} result_base: {}, result:
                                                //     {}",
                                                //                 i,
                                                //                 result_base.flat(i),
                                                //                 result.flat(i)));
                                                REQUIRE(std::fabs(result_base.flat(i) -
                                                                  result.flat(i)) < 0.0001f);
                                            }
                                        }
                                    }
                                }
        }
    }
}