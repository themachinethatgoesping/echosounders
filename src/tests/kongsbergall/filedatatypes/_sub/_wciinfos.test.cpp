// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include <boost/functional/hash.hpp> // Include the Boost Hash library

#include "../themachinethatgoesping/echosounders/kongsbergall/filedatatypes/_sub/watercolumninformation.hpp"

// using namespace testing;
using namespace std;
using themachinethatgoesping::echosounders::kongsbergall::filedatatypes::_sub::_WCIInfos;
#define TESTTAG "[kongsbergall]"

TEST_CASE("_WCIInfos reproduce precomputed hashes", TESTTAG)
{
        _WCIInfos wcii;

        CHECK(boost::hash<_WCIInfos>{}(wcii) == 5377294635745409996ULL);

        wcii.sound_speed_at_transducer = 1500.0f;
        CHECK(boost::hash<_WCIInfos>{}(wcii) == 11906803725422541395ULL);

        wcii.tvg_function_applied = 10;
        CHECK(boost::hash<_WCIInfos>{}(wcii) == 10793065508294209563ULL);

        wcii.tvg_offset_in_db = 30;
        CHECK(boost::hash<_WCIInfos>{}(wcii) == 17999953697931353017ULL);

        wcii.sampling_interval = 23450.0f;
        CHECK(boost::hash<_WCIInfos>{}(wcii) == 12384024258331840569ULL);

        themachinethatgoesping::echosounders::kongsbergall::datagrams::substructures::WatercolumnDatagramTransmitSector ts1,ts2;
        ts1.set_tilt_angle(10);
        ts1.set_center_frequency(11);
        ts1.set_transmit_sector_number(12);
        ts1.set_spare(13);

        ts2.set_tilt_angle(24);
        ts2.set_center_frequency(12);
        ts2.set_transmit_sector_number(25);
        ts2.set_spare(2);

        wcii.transmit_sectors.push_back(ts1);
        CHECK(boost::hash<_WCIInfos>{}(wcii) == 5612708217887030279ULL);

        wcii.transmit_sectors.push_back(ts2);
        CHECK(boost::hash<_WCIInfos>{}(wcii) == 4939658469529714773ULL);
}
