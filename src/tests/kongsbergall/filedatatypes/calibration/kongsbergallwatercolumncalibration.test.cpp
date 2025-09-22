// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <themachinethatgoesping/echosounders/kongsbergall/types.hpp>
#include <themachinethatgoesping/echosounders/simradraw/types.hpp>

// note: this must be defined below the kongsbergall/simradraw includes otherwise
// datagram_identifier_to_string is unknown
#include <themachinethatgoesping/echosounders/kongsbergall/filedatatypes/calibration/kongsbergallwatercolumncalibration.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;
using namespace themachinethatgoesping::echosounders::kongsbergall::filedatatypes::calibration;
using namespace themachinethatgoesping::echosounders;
#define TESTTAG "[KongsbergAllWaterColumnCalibration]"

TEST_CASE("KongsbergAllWaterColumnCalibration should support common functions", TESTTAG)
{
    using Catch::Approx;

    float sound_velocity           = 1456.0f;
    float effective_pulse_duration = 0.75e-3;
    float system_gain_offset       = 23.0f;
    float tvg_absorption_db_m      = 0.023f;
    float tvg_factor               = 10.6f;
    float new_absorption_db_m      = tvg_absorption_db_m - 0.01f;

    auto obj0 = AmplitudeCalibration(1.0f);

    auto obj  = KongsbergAllWaterColumnCalibration(sound_velocity,
                                                  effective_pulse_duration,
                                                  system_gain_offset,
                                                  tvg_absorption_db_m,
                                                  tvg_factor);
    auto obj2 = KongsbergAllWaterColumnCalibration();

    // test hash (should be stable if class is not changed)
    CHECK(obj.binary_hash() == 6483505769134307231ULL);
    CHECK(obj2.binary_hash() == 770061992534893794ULL);

    // test equality
    // test inequality
    CHECK(obj == obj);
    CHECK(obj2 == obj2);
    CHECK(obj != obj2);

    SECTION("test incomplete setup behavior")
    {

        auto obj_no_epd = KongsbergAllWaterColumnCalibration(
            sound_velocity, NAN, system_gain_offset, tvg_absorption_db_m, tvg_factor);

        auto obj_no_absorption = KongsbergAllWaterColumnCalibration(sound_velocity,
                                                                    effective_pulse_duration,
                                                                    system_gain_offset,
                                                                    0.f,
                                                                    tvg_factor);
        // if the effective pulse duration is not supplied, the AV calibration will not be set
        CHECK(obj_no_epd.has_valid_absorption_db_m() == true);
        CHECK(obj_no_epd.has_ap_calibration() == true);
        CHECK(obj_no_epd.has_av_calibration() == false);
        CHECK(obj_no_epd.has_power_calibration() == true);
        CHECK(obj_no_epd.has_sp_calibration() == false);
        CHECK(obj_no_epd.has_sv_calibration() == false);

        // of tvg_absorption is 0, and no additional absorption is supplied, the absorption is set
        // invalid
        CHECK(obj_no_absorption.has_valid_absorption_db_m() == false);
        CHECK(obj_no_absorption.has_ap_calibration() == true);
        CHECK(obj_no_absorption.has_av_calibration() == true);
        CHECK(obj_no_absorption.has_power_calibration() == true);
        CHECK(obj_no_absorption.has_sp_calibration() == false);
        CHECK(obj_no_absorption.has_sv_calibration() == false);

        // even 0 absorption is valid, if it was explicitly set
        obj_no_absorption.set_absorption_db_m(0);
        CHECK(obj_no_absorption.has_valid_absorption_db_m() == true);
        obj_no_absorption.set_absorption_db_m(NAN);
        CHECK(obj_no_absorption.has_valid_absorption_db_m() == false);
    }

    // test initialized
    // CHECK(obj.initialized() == true);
    // CHECK(obj2.initialized() == false);

    // test kongsberg default calibration
    CHECK(obj2.has_valid_absorption_db_m() == false);
    CHECK(obj.has_valid_absorption_db_m() == true);
    CHECK(obj.has_ap_calibration() == true);
    CHECK(obj.has_av_calibration() == true);
    CHECK(obj.has_power_calibration() == true);
    CHECK(obj.has_sp_calibration() == false);
    CHECK(obj.has_sv_calibration() == false);
    obj.set_sv_calibration(obj0);
    CHECK(obj.has_sv_calibration() == true);

    // test getters/setters
    CHECK(obj2.has_power_calibration() == false);
    CHECK(obj2.has_sp_calibration() == false);
    CHECK(obj2.has_sv_calibration() == false);

    obj2.set_sv_calibration(obj0);
    CHECK(obj2.has_power_calibration() == false);
    CHECK(obj2.has_sp_calibration() == false);
    CHECK(obj2.has_sv_calibration() == true);

    obj2.set_sp_calibration(obj0);
    CHECK(obj2.has_power_calibration() == false);
    CHECK(obj2.has_sp_calibration() == true);
    CHECK(obj2.has_sv_calibration() == true);

    // test copy
    {
        INFO(obj.info_string());
        INFO(KongsbergAllWaterColumnCalibration(obj).info_string());
        CHECK(obj == KongsbergAllWaterColumnCalibration(obj));
    }

    // test binary
    CHECK(obj == KongsbergAllWaterColumnCalibration(obj.from_binary(obj.to_binary())));

    // test stream
    std::stringstream buffer;
    obj.to_stream(buffer);
    CHECK(obj == KongsbergAllWaterColumnCalibration(obj.from_stream(buffer)));

    // test print does not crash
    CHECK(obj.info_string().size() != 0);

    // test modifying calibrations
    REQUIRE_THROWS_AS(obj.set_power_calibration(obj0), std::runtime_error);
    REQUIRE_THROWS_AS(obj.set_ap_calibration(obj0), std::runtime_error);
    REQUIRE_THROWS_AS(obj.set_av_calibration(obj0), std::runtime_error);
    REQUIRE_NOTHROW(obj.set_sp_calibration(obj0));
    REQUIRE_NOTHROW(obj.set_sv_calibration(obj0));

    // test data access

    CHECK(obj.get_sound_velocity() == Approx(sound_velocity));
    CHECK(obj.get_effective_pulse_duration() == Approx(effective_pulse_duration));
    CHECK(obj.get_system_gain_offset() == Approx(system_gain_offset));
    CHECK(obj.get_tvg_absorption_db_m() == Approx(tvg_absorption_db_m));
    CHECK(obj.get_tvg_factor() == Approx(tvg_factor));

    // test absorption to apply
    CHECK(obj.get_absorption_to_apply() ==
          std::nullopt); // tvg_absorption not changed, nothing to do
    CHECK(obj.get_absorption_to_apply(tvg_absorption_db_m) ==
          std::nullopt); // tvg_absorption not changed, nothing to do
    CHECK(obj.get_absorption_to_apply(0) == Approx(-tvg_absorption_db_m)); // force absorption 0
    CHECK(obj.get_absorption_to_apply(new_absorption_db_m) ==
          Approx(new_absorption_db_m - tvg_absorption_db_m)); // force new absorption
    obj.set_absorption_db_m(new_absorption_db_m);
    CHECK(obj.get_absorption_to_apply() ==
          Approx(new_absorption_db_m -
                 tvg_absorption_db_m)); // tvg_absorption changed apply diff to old absorption

    // test tvg factor to apply
    CHECK(obj.get_tvg_factor_to_apply(tvg_factor) ==
          std::nullopt); // tvg_factor same as the one already applied
    CHECK(obj.get_tvg_factor_to_apply(20) == 20 - tvg_factor); // apply difference

    // test individual calibrations
    // Power calibration
    // power is the raw amplitude data with the system gain offset substracted
    // Absorption 0 and tvg 0 will be applied by WaterColumnCalibration base
    CHECK(obj.get_power_calibration().get_system_offset() ==
          -system_gain_offset); // C = -system_gain_offset
    CHECK(obj.get_power_calibration().has_offset_per_beamangle() == false);
    CHECK(obj.get_power_calibration().has_offset_per_range() == false);

    // Ap calibration
    // Ap is the raw amplitude data with the system gain offset substracted
    // Specified absorption and tvg 40 will be applied by WaterColumnCalibration base
    CHECK(obj.get_ap_calibration().get_system_offset() ==
          -system_gain_offset); // C = -system_gain_offset
    CHECK(obj.get_ap_calibration().has_offset_per_beamangle() == false);
    CHECK(obj.get_ap_calibration().has_offset_per_range() == false);

    // Av calibration
    // Av is the raw amplitude data with the system gain offset and sample volume correction
    // substracted Specified absorption and tvg 20 will be applied by WaterColumnCalibration base
    // Only range correction is applied, the solid beam angle seams to have been applied by the
    // system already
    float av_sample_size_correction = effective_pulse_duration * sound_velocity * 0.5f;
    CHECK(obj.get_av_calibration().get_system_offset() ==
          -system_gain_offset - std::log10(av_sample_size_correction)); // C = -system_gain_offset
    CHECK(obj.get_av_calibration().has_offset_per_beamangle() == false);
    CHECK(obj.get_av_calibration().has_offset_per_range() == false);
}
