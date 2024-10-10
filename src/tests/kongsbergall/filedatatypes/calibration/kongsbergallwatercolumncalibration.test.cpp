// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
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

TEST_CASE("DatagramInfoDatashould support common functions", TESTTAG)
{
    auto obj0 = AmplitudeCalibration(1.0f);

    auto obj  = KongsbergAllWaterColumnCalibration(1, 2, 3, 4, 5);
    auto obj2 = KongsbergAllWaterColumnCalibration();

    // test hash
    CHECK(obj.binary_hash() == 4706969008052593086ULL);
    CHECK(obj2.binary_hash() == 9419732169616963099ULL);

    // test equality
    // test inequality
    CHECK(obj == obj);
    CHECK(obj2 == obj2);
    CHECK(obj != obj2);

    // test initialized
    // CHECK(obj.initialized() == true);
    // CHECK(obj2.initialized() == false);

    // test kongsberg default calibration
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

    // test data access
    CHECK(obj.get_power_calibration().get_system_offset() == -3.0f);
    CHECK(obj.get_sv_calibration().get_system_offset() == 1.0f);

}
