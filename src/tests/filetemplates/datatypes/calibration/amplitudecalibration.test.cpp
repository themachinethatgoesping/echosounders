// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <themachinethatgoesping/echosounders/kongsbergall/types.hpp>
#include <themachinethatgoesping/echosounders/simradraw/types.hpp>

// note: this must be defined below the kongsbergall/simradraw includes otherwise
// datagram_identifier_to_string is unknown
#include <themachinethatgoesping/echosounders/filetemplates/datatypes/calibration/amplitudecalibration.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;
using namespace themachinethatgoesping::echosounders;
#define TESTTAG "[AmplitudeCalibration]"

TEST_CASE("DatagramInfoDatashould support common functions", TESTTAG)
{
    auto obj  = AmplitudeCalibration();
    auto obj2 = AmplitudeCalibration(1.0f);

    // test hash
    CHECK(obj.cached_hash() == 3244421341483603138ULL);
    CHECK(obj2.cached_hash() == 17904910546364380078ULL);
    CHECK(obj.binary_hash() == 3244421341483603138ULL);
    CHECK(obj2.binary_hash() == 17904910546364380078ULL);

    // test equality
    // test inequality
    CHECK(obj == obj);
    CHECK(obj2 == obj2);
    CHECK(obj != obj2);

    // test initialized
    CHECK(obj.initialized() == false);
    CHECK(obj2.initialized() == true);

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
