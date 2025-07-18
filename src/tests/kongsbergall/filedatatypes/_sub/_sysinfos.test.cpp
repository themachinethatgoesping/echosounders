// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include <boost/functional/hash.hpp> // Include the Boost Hash library

#include "../themachinethatgoesping/echosounders/kongsbergall/filedatatypes/_sub/systeminformation.hpp"

// using namespace testing;
using namespace std;
using themachinethatgoesping::echosounders::kongsbergall::filedatatypes::_sub::_SYSInfos;
#define TESTTAG "[kongsbergall]"

TEST_CASE("_SYSInfos reproduce precomputed hashes", TESTTAG)
{
        _SYSInfos sysi;

        CHECK(boost::hash<_SYSInfos>{}(sysi) == 3244421341483603138);

        //sysi.sampling_frequency_in_hz = 23450.0f;
        //CHECK(boost::hash<_SYSInfos>{}(sysi) == 7559556605068632653ULL);

}
