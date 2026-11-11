// SPDX-FileCopyrightText: 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <cmath>
#include <sstream>

#include <themachinethatgoesping/echosounders/s7k/types.hpp>

// note: this must be defined below the s7k includes otherwise
// datagram_identifier_to_string is unknown
#include <themachinethatgoesping/echosounders/s7k/filedatatypes/calibration/s7kwatercolumncalibration.hpp>

using namespace std;
using namespace themachinethatgoesping::pingprocessing::datatypes::calibration;
using namespace themachinethatgoesping::echosounders::s7k::filedatatypes::calibration;
using namespace themachinethatgoesping::echosounders;
#define TESTTAG "[S7KWaterColumnCalibration]"

TEST_CASE("S7KWaterColumnCalibration should support common functions", TESTTAG)
{
    using Catch::Approx;

    float sound_velocity           = 1499.33f;
    float effective_pulse_duration = 25e-6f;  // FM: 1 / bandwidth (e.g. 40 kHz)
    float system_gain_offset       = 241.52f; // power selection + gain selection
    float tvg_absorption_db_m      = 0.091f;
    float tvg_factor               = 22.0f;

    auto obj0 = AmplitudeCalibration(1.0f);

    // FM (chirp) calibration
    auto obj = S7KWaterColumnCalibration(sound_velocity,
                                         effective_pulse_duration,
                                         system_gain_offset,
                                         tvg_absorption_db_m,
                                         tvg_factor,
                                         true);
    auto obj2 = S7KWaterColumnCalibration();

    // test equality / inequality
    CHECK(obj == obj);
    CHECK(obj2 == obj2);
    CHECK(obj != obj2);

    // test data access
    CHECK(obj.get_sound_velocity() == Approx(sound_velocity));
    CHECK(obj.get_effective_pulse_duration() == Approx(effective_pulse_duration));
    CHECK(obj.get_system_gain_offset() == Approx(system_gain_offset));
    CHECK(obj.get_tvg_absorption_db_m() == Approx(tvg_absorption_db_m));
    CHECK(obj.get_tvg_factor() == Approx(tvg_factor));
    CHECK(obj.is_fm() == true);

    SECTION("CW vs FM pulse type")
    {
        // same numbers but CW: only the is_fm flag differs -> objects must differ
        auto obj_cw = S7KWaterColumnCalibration(sound_velocity,
                                                effective_pulse_duration,
                                                system_gain_offset,
                                                tvg_absorption_db_m,
                                                tvg_factor,
                                                false);
        CHECK(obj_cw.is_fm() == false);
        CHECK(obj_cw != obj);
    }

    SECTION("incomplete setup behavior")
    {
        // without an effective pulse duration the av (volume) calibration cannot be built
        auto obj_no_epd = S7KWaterColumnCalibration(
            sound_velocity, NAN, system_gain_offset, tvg_absorption_db_m, tvg_factor);
        CHECK(obj_no_epd.has_ap_calibration() == true);
        CHECK(obj_no_epd.has_power_calibration() == true);
        CHECK(obj_no_epd.has_av_calibration() == false);
    }

    SECTION("individual calibrations (power / ap / av)")
    {
        // power: raw amplitude minus the system gain offset (absorption 0, tvg 0 applied by base)
        CHECK(obj.get_power_calibration().get_system_offset() == Approx(-system_gain_offset));
        CHECK(obj.get_power_calibration().has_offset_per_beamangle() == false);
        CHECK(obj.get_power_calibration().has_offset_per_range() == false);

        // ap: same offset as power (absorption + tvg 40 applied by base)
        CHECK(obj.get_ap_calibration().get_system_offset() == Approx(-system_gain_offset));

        // av: additionally removes the volume-scattering sample-size correction 10 log10(c*tau/2)
        float av_sample_size_correction = effective_pulse_duration * sound_velocity * 0.5f;
        CHECK(obj.get_av_calibration().get_system_offset() ==
              Approx(-system_gain_offset - 10.f * std::log10(av_sample_size_correction)));
        CHECK(obj.has_av_calibration() == true);
    }

    // test copy
    CHECK(obj == S7KWaterColumnCalibration(obj));

    // test binary round-trip (preserves is_fm and the floats)
    CHECK(obj == S7KWaterColumnCalibration(obj.from_binary(obj.to_binary())));

    // test stream round-trip
    std::stringstream buffer;
    obj.to_stream(buffer);
    CHECK(obj == S7KWaterColumnCalibration(obj.from_stream(buffer)));

    // test print does not crash
    CHECK(obj.info_string().size() != 0);

    // modifying the base calibrations directly is not allowed
    REQUIRE_THROWS_AS(obj.set_power_calibration(obj0), std::runtime_error);
    REQUIRE_THROWS_AS(obj.set_ap_calibration(obj0), std::runtime_error);
    REQUIRE_THROWS_AS(obj.set_av_calibration(obj0), std::runtime_error);
}
