// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
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

TEST_CASE("_WCIInfos should reproduce precomputed hashes", TESTTAG)
{
    _WCIInfos wcii;

    CHECK(boost::hash<_WCIInfos>{}(wcii) == 12556924169211648360ULL);

    wcii.set_sound_speed_at_transducer(1500.0f);
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 4186296658744051712ULL);

    wcii.set_tvg_function_applied(10);
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 14284873358352962582ULL);

    wcii.set_tvg_offset_in_db(30);
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 13329930931179456403ULL);

    wcii.set_sampling_interval(23450.0f);
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 6374874473246290892ULL);

    themachinethatgoesping::echosounders::kongsbergall::datagrams::substructures::
        WatercolumnDatagramTransmitSector ts1,
        ts2;
    ts1.set_tilt_angle(10);
    ts1.set_center_frequency(11);
    ts1.set_transmit_sector_number(12);
    ts1.set_spare(13);

    ts2.set_tilt_angle(24);
    ts2.set_center_frequency(12);
    ts2.set_transmit_sector_number(25);
    ts2.set_spare(2);

    wcii.set_transmit_sectors({ ts1 });
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 12534907140759658321ULL);

    wcii.set_transmit_sectors({ ts2 });
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 14924703663744133009ULL);

    wcii.set_transmit_sectors({ ts1, ts2 });
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 10946409940158895488ULL);

    wcii.set_transmit_sectors({ ts2, ts1 });
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 10720570688257217148ULL);

    CHECK(wcii.get_sound_speed_at_transducer() == 1500.0f);
    CHECK(wcii.get_sampling_interval() == 23450.0f);
    CHECK(wcii.get_tvg_function_applied() == 10);
    CHECK(wcii.get_tvg_offset_in_db() == 30);
    CHECK(wcii.get_number_of_transmit_sectors() == 2);
    CHECK(wcii.get_transmit_sectors().size() == 2);
    CHECK(wcii.get_transmit_sectors()[0] == ts2);
    CHECK(wcii.get_transmit_sectors()[1] == ts1);

    // check to/from binary
    CHECK(wcii != _WCIInfos());

    auto wcii2 = wcii;
    CHECK(wcii == wcii2);

    auto wcii3 = wcii.from_binary(wcii.to_binary());
    CHECK(wcii.get_sound_speed_at_transducer() == 1500.0f);
    CHECK(wcii.get_sampling_interval() == 23450.0f);
    CHECK(wcii.get_tvg_function_applied() == 10);
    CHECK(wcii.get_tvg_offset_in_db() == 30);
    CHECK(wcii.get_number_of_transmit_sectors() == 2);
    CHECK(wcii.get_transmit_sectors().size() == 2);
    CHECK(wcii.get_transmit_sectors()[0] == ts2);
    CHECK(wcii.get_transmit_sectors()[1] == ts1);

    CHECK(wcii == wcii3);
    CHECK(wcii == wcii.from_binary(wcii.to_binary()));
}
