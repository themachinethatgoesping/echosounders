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

    // test hash
    CHECK(obj.binary_hash() == 3244421341483603138ULL);
    CHECK(obj2.binary_hash() == 8376124999220038186ULL);

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
