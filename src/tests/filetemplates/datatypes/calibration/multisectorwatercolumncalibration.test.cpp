// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <themachinethatgoesping/echosounders/kongsbergall/types.hpp>
#include <themachinethatgoesping/echosounders/simradraw/types.hpp>

// note: this must be defined below the kongsbergall/simradraw includes otherwise
// datagram_identifier_to_string is unknown
#include <themachinethatgoesping/echosounders/filetemplates/datatypes/calibration/multisectorwatercolumncalibration.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;
using namespace themachinethatgoesping::echosounders;
#define TESTTAG "[MultiSectorWaterColumnCalibration]"

TEST_CASE("MultiSectorWaterColumnCalibration support common functions", TESTTAG)
{
    auto obj = MultiSectorWaterColumnCalibration();
    auto obj2 =
        MultiSectorWaterColumnCalibration({ WaterColumnCalibration(), WaterColumnCalibration() });

    // test hash (should be stable if class is not changed)
    CHECK(obj.binary_hash() == 14374147212387527897ULL);
    CHECK(obj2.binary_hash() == 9020898908978856005ULL);

    // test equality
    // test inequality
    CHECK(obj == obj);
    CHECK(obj2 == obj2);
    CHECK(obj != obj2);

    // test initialized
    CHECK(obj.initialized() == false);
    CHECK(obj2.initialized() == true);

    // test getters/setters
    CHECK(obj2.get_number_of_sectors() == 2);
    CHECK(obj.get_number_of_sectors() == 0);

    // test copy
    {
        INFO(obj.info_string());
        INFO(MultiSectorWaterColumnCalibration(obj).info_string());
        CHECK(obj == MultiSectorWaterColumnCalibration(obj));
    }

    // test binary
    CHECK(obj == MultiSectorWaterColumnCalibration(obj.from_binary(obj.to_binary())));

    // test stream
    std::stringstream buffer;
    obj.to_stream(buffer);
    CHECK(obj == MultiSectorWaterColumnCalibration(obj.from_stream(buffer)));

    // test print does not crash
    CHECK(obj.info_string().size() != 0);
}

TEST_CASE(
    "MultiSectorWaterColumnCalibration should apply calibration to multiple sectors correctly",
    TESTTAG)
{
    using Catch::Approx;

    SECTION("apply_beam_sample_correction and inplace_beam_sample_correction")
    {

        using namespace themachinethatgoesping::algorithms::amplitudecorrection::functions;

        xt::xtensor<float, 2>              wci = xt::eval(xt::ones<float>({ 10, 20 }));
        std::vector<xt::xtensor<float, 1>> per_beam_offsets =
            std::vector<xt::xtensor<float, 1>>{ xt::eval(xt::linspace<float>(-5.5, 20.5, 10)),
                                                xt::eval(xt::linspace<float>(-3.5, 0.5, 10)) };
        std::vector<xt::xtensor<float, 1>> per_sample_offsets =
            std::vector<xt::xtensor<float, 1>>{ xt::eval(xt::linspace<float>(-2.5, 35.2, 20)),
                                                xt::eval(xt::linspace<float>(-5.5, 45.2, 20)) };

        xt::xtensor<float, 1> beam_angles = xt::eval(xt::linspace<float>(-30, 30, 10));
        xt::xtensor<float, 1> ranges      = xt::eval(xt::linspace<float>(0.5, 30, 20));

        std::vector<std::vector<size_t>> beamnumbers =
            std::vector<std::vector<size_t>>{ { 0, 5 }, { 6, 19 } };
        std::vector<float> system_offsets = { -13, 11 };

        float                tvg_absorption     = 0.0234f;
        float                tvg_factor_applied = 30;
        std::optional<float> absorption         = 0.0124f;

        for (size_t mp_cores : { 1, 2 })
        {

            // create reference result
            xt::xtensor<float, 1> range_varying_offset =
                compute_cw_range_correction(ranges, -tvg_absorption, -tvg_factor_applied);
            xt::xtensor<float, 2> result_power_ref = wci;
            for (unsigned int sn = 0; sn < beamnumbers.size(); ++sn)
                inplace_beam_sample_correction(
                    result_power_ref,
                    xt::eval(per_beam_offsets.at(sn) + system_offsets.at(sn)),
                    xt::eval(per_sample_offsets.at(sn) + range_varying_offset),
                    beamnumbers.at(sn).at(0),
                    beamnumbers.at(sn).at(1));

            range_varying_offset =
                compute_cw_range_correction(ranges, -tvg_absorption, 40 - tvg_factor_applied);
            xt::xtensor<float, 2> result_rp_ref = wci;
            for (unsigned int sn = 0; sn < beamnumbers.size(); ++sn)
                inplace_beam_sample_correction(
                    result_rp_ref,
                    xt::eval(per_beam_offsets.at(sn) + system_offsets.at(sn)),
                    xt::eval(per_sample_offsets.at(sn) + range_varying_offset),
                    beamnumbers.at(sn).at(0),
                    beamnumbers.at(sn).at(1));

            range_varying_offset =
                compute_cw_range_correction(ranges, -tvg_absorption, 20 - tvg_factor_applied);
            xt::xtensor<float, 2> result_rv_ref = wci;
            for (unsigned int sn = 0; sn < beamnumbers.size(); ++sn)
                inplace_beam_sample_correction(
                    result_rv_ref,
                    xt::eval(per_beam_offsets.at(sn) + system_offsets.at(sn)),
                    xt::eval(per_sample_offsets.at(sn) + range_varying_offset),
                    beamnumbers.at(sn).at(0),
                    beamnumbers.at(sn).at(1));

            range_varying_offset =
                compute_cw_range_correction(ranges,
                                            absorption.value_or(tvg_absorption) - tvg_absorption,
                                            40 - tvg_factor_applied);
            xt::xtensor<float, 2> result_pp_ref = wci;
            for (unsigned int sn = 0; sn < beamnumbers.size(); ++sn)
                inplace_beam_sample_correction(
                    result_pp_ref,
                    xt::eval(per_beam_offsets.at(sn) + system_offsets.at(sn)),
                    xt::eval(per_sample_offsets.at(sn) + range_varying_offset),
                    beamnumbers.at(sn).at(0),
                    beamnumbers.at(sn).at(1));

            range_varying_offset =
                compute_cw_range_correction(ranges,
                                            absorption.value_or(tvg_absorption) - tvg_absorption,
                                            20 - tvg_factor_applied);
            xt::xtensor<float, 2> result_pv_ref = wci;
            for (unsigned int sn = 0; sn < beamnumbers.size(); ++sn)
                inplace_beam_sample_correction(
                    result_pv_ref,
                    xt::eval(per_beam_offsets.at(sn) + system_offsets.at(sn)),
                    xt::eval(per_sample_offsets.at(sn) + range_varying_offset),
                    beamnumbers.at(sn).at(0),
                    beamnumbers.at(sn).at(1));

            range_varying_offset =
                compute_cw_range_correction(ranges,
                                            absorption.value_or(tvg_absorption) - tvg_absorption,
                                            40 - tvg_factor_applied);
            xt::xtensor<float, 2> result_ap_ref = wci;
            for (unsigned int sn = 0; sn < beamnumbers.size(); ++sn)
                inplace_beam_sample_correction(
                    result_ap_ref,
                    xt::eval(per_beam_offsets.at(sn) + system_offsets.at(sn)),
                    xt::eval(per_sample_offsets.at(sn) + range_varying_offset),
                    beamnumbers.at(sn).at(0),
                    beamnumbers.at(sn).at(1));

            range_varying_offset =
                compute_cw_range_correction(ranges,
                                            absorption.value_or(tvg_absorption) - tvg_absorption,
                                            20 - tvg_factor_applied);
            xt::xtensor<float, 2> result_av_ref = wci;
            for (unsigned int sn = 0; sn < beamnumbers.size(); ++sn)
                inplace_beam_sample_correction(
                    result_av_ref,
                    xt::eval(per_beam_offsets.at(sn) + system_offsets.at(sn)),
                    xt::eval(per_sample_offsets.at(sn) + range_varying_offset),
                    beamnumbers.at(sn).at(0),
                    beamnumbers.at(sn).at(1));

            REQUIRE(result_power_ref.size() ==
                    result_power_ref.shape(0) * result_power_ref.shape(1));
            REQUIRE(result_ap_ref.size() == result_ap_ref.shape(0) * result_ap_ref.shape(1));
            REQUIRE(result_av_ref.size() == result_av_ref.shape(0) * result_av_ref.shape(1));

            std::map<std::string, xt::xtensor<float, 2>> results_power = { { "reference",
                                                                             result_power_ref } };
            std::map<std::string, xt::xtensor<float, 2>> results_rp    = { { "reference",
                                                                             result_rp_ref } };
            std::map<std::string, xt::xtensor<float, 2>> results_rv    = { { "reference",
                                                                             result_rv_ref } };
            std::map<std::string, xt::xtensor<float, 2>> results_pp    = { { "reference",
                                                                             result_pp_ref } };
            std::map<std::string, xt::xtensor<float, 2>> results_pv    = { { "reference",
                                                                             result_pv_ref } };
            std::map<std::string, xt::xtensor<float, 2>> results_ap    = { { "reference",
                                                                             result_ap_ref } };
            std::map<std::string, xt::xtensor<float, 2>> results_av    = { { "reference",
                                                                             result_av_ref } };

            // create two calibrations for two sectors
            auto cal_sector1 = AmplitudeCalibration(system_offsets.at(0));
            auto cal_sector2 = AmplitudeCalibration(system_offsets.at(1));

            cal_sector1.set_offset_per_beamangle(beam_angles, per_beam_offsets.at(0));
            cal_sector1.set_offset_per_range(ranges, per_sample_offsets.at(0));
            cal_sector2.set_offset_per_beamangle(beam_angles, per_beam_offsets.at(1));
            cal_sector2.set_offset_per_range(ranges, per_sample_offsets.at(1));

            WaterColumnCalibration wcc1(
                cal_sector1, cal_sector1, cal_sector1, tvg_absorption, tvg_factor_applied);
            WaterColumnCalibration wcc2(
                cal_sector2, cal_sector2, cal_sector2, tvg_absorption, tvg_factor_applied);
            wcc1.set_absorption_db_m(absorption);
            wcc2.set_absorption_db_m(absorption);

            MultiSectorWaterColumnCalibration mwcc({ wcc1, wcc2 });

            // --- apply power correction ---
            results_power["Apply_power_calibration"] = mwcc.template apply_beam_sample_correction<
                WaterColumnCalibration::t_calibration_type::power>(
                wci, beam_angles, ranges, beamnumbers, mp_cores);
            results_rp["Apply_rp_calibration"] = mwcc.template apply_beam_sample_correction<
                WaterColumnCalibration::t_calibration_type::rp>(
                wci, beam_angles, ranges, beamnumbers, mp_cores);
            results_rv["Apply_rv_calibration"] = mwcc.template apply_beam_sample_correction<
                WaterColumnCalibration::t_calibration_type::rv>(
                wci, beam_angles, ranges, beamnumbers, mp_cores);
            results_pp["Apply_pp_calibration"] = mwcc.template apply_beam_sample_correction<
                WaterColumnCalibration::t_calibration_type::pp>(
                wci, beam_angles, ranges, beamnumbers, mp_cores);
            results_pv["Apply_pv_calibration"] = mwcc.template apply_beam_sample_correction<
                WaterColumnCalibration::t_calibration_type::pv>(
                wci, beam_angles, ranges, beamnumbers, mp_cores);

            // inplace
            xt::xtensor<float, 2> result = wci;
            mwcc.template inplace_beam_sample_correction<
                WaterColumnCalibration::t_calibration_type::power>(
                result, beam_angles, ranges, beamnumbers, mp_cores);
            results_power["Inplace_power_calibration"] = result;

            result = wci;
            mwcc.template inplace_beam_sample_correction<
                WaterColumnCalibration::t_calibration_type::rp>(
                result, beam_angles, ranges, beamnumbers, mp_cores);
            results_rp["Inplace_rp_calibration"] = result;

            result = wci;
            mwcc.template inplace_beam_sample_correction<
                WaterColumnCalibration::t_calibration_type::rv>(
                result, beam_angles, ranges, beamnumbers, mp_cores);
            results_rv["Inplace_rv_calibration"] = result;

            result = wci;
            mwcc.template inplace_beam_sample_correction<
                WaterColumnCalibration::t_calibration_type::pp>(
                result, beam_angles, ranges, beamnumbers, mp_cores);
            results_pp["Inplace_pp_calibration"] = result;

            result = wci;
            mwcc.template inplace_beam_sample_correction<
                WaterColumnCalibration::t_calibration_type::pv>(
                result, beam_angles, ranges, beamnumbers, mp_cores);
            results_pv["Inplace_pv_calibration"] = result;

            // --- apply ap correction ---
            results_ap["Apply_ap_calibration"] = mwcc.template apply_beam_sample_correction<
                WaterColumnCalibration::t_calibration_type::ap>(
                wci, beam_angles, ranges, beamnumbers, mp_cores);

            // inplace
            result = wci;
            mwcc.template inplace_beam_sample_correction<
                WaterColumnCalibration::t_calibration_type::ap>(
                result, beam_angles, ranges, beamnumbers, mp_cores);
            results_ap["Inplace_ap_calibration"] = result;

            // --- apply ap correction ---
            results_av["Apply_av_calibration"] = mwcc.template apply_beam_sample_correction<
                WaterColumnCalibration::t_calibration_type::av>(
                wci, beam_angles, ranges, beamnumbers, mp_cores);

            // inplace
            result = wci;
            mwcc.template inplace_beam_sample_correction<
                WaterColumnCalibration::t_calibration_type::av>(
                result, beam_angles, ranges, beamnumbers, mp_cores);
            results_av["Inplace_av_calibration"] = result;

            for (const auto& results : { results_power,
                                         results_rp,
                                         results_rv,
                                         results_pp,
                                         results_pv,
                                         results_ap,
                                         results_av })
            {
                const auto& result_base = results.at("reference");

                for (const auto& [key, result] : results)
                {
                    // INFO(fmt::format("key {}, system_offsets: [{},{}], mp_cores: {}"
                    //                  "absorption: {}, tvg_factor_applied: {}, "
                    //                  "tvg_absorption: {}",
                    //                  key,
                    //                  system_offsets[0],
                    //                  system_offsets[1],
                    //                  mp_cores,
                    //                  absorption.value_or(std::numeric_limits<float>::quiet_NaN()),
                    //                  tvg_factor_applied,
                    //                  tvg_absorption));
                    REQUIRE(result_base.shape() == result.shape());

                    for (size_t i = 0; i < result_base.size(); i++)
                    {
                        // INFO(fmt::format("i: {} result_base: {}, result: {}",
                        //                  i,
                        //                  result_base.flat(i),
                        //                  result.flat(i)));
                        REQUIRE(std::fabs(result_base.flat(i) - result.flat(i)) < 0.0001f);
                    }
                }
            }
        }
    }
}