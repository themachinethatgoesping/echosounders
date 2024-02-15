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

    CHECK(boost::hash<_WCIInfos>{}(wcii) == 12556924169211648360ULL);

    wcii.set_sound_speed_at_transducer(1500.0f);
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 4186296658744051712ULL);

    wcii.set_tvg_function_applied(10);
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 2658501269602360885ULL);

    wcii.set_tvg_offset_in_db(30);
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 10184580719437389252ULL);

    wcii.set_sampling_interval(23450.0f);
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 5613236057941785062ULL);

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
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 8624836943021438614ULL);

    wcii.set_transmit_sectors({ ts2 });
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 10353319565812865839ULL);

    wcii.set_transmit_sectors({ ts1, ts2 });
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 10705745813686219581ULL);

    wcii.set_transmit_sectors({ ts2, ts1 });
    CHECK(boost::hash<_WCIInfos>{}(wcii) == 12469742676074783617ULL);

    // check to/from binary
    CHECK(wcii != _WCIInfos());
    CHECK(wcii == wcii.from_binary(wcii.to_binary()));
}
