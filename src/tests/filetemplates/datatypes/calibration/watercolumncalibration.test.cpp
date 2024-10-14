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

        for (size_t mp_cores : { 1, 0, 4 })
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
                                xt::eval(apply_beam_sample_correction(xt::eval(wci + system_offset),
                                                                      per_beam_offset,
                                                                      xt::eval(per_sample_offset)));

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
                            auto cal_sv    = AmplitudeCalibration(system_offset * 4.45f);

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

                            // // --- apply system offset correction ---
                            // results_so["FULL-apply_system_offset"] =
                            //     cal.apply_beam_sample_correction(
                            //         wci, beam_angles, ranges, absorption, tvg_factor,
                            //         mp_cores);

                            // // inplace
                            // xt::xtensor<float, 2> result = wci;
                            // cal.inplace_beam_sample_correction(result,
                            //                                    beam_angles,
                            //                                    ranges,
                            //                                    absorption,
                            //                                    tvg_factor,
                            //                                    std::nullopt,
                            //                                    std::nullopt,
                            //                                    mp_cores);
                            // results_so["FULL-inplace_system_offset"] = result;

                            for (const auto& results :
                                 { results_power, results_ap, results_av, results_sp, results_sv })
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