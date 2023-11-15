// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/kongsbergall/datagrams/kongsbergallunknown.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using themachinethatgoesping::echosounders::kongsbergall::datagrams::KongsbergAllUnknown;

#define TESTTAG "[kongsbergall]"

TEST_CASE("KongsbergAllUnknown should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = KongsbergAllUnknown();

    // set some variables
    dat.set_bytes(100);
    dat.set_datagram_identifier(t_KongsbergAllDatagramIdentifier::WatercolumnDatagram);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);
    dat.set_raw_content("this is raw test data :-)");
    dat.set_etx(0x03);

    // test inequality
    REQUIRE(dat != KongsbergAllUnknown());

    // test copy
    REQUIRE(dat == KongsbergAllUnknown(dat));

    // test binary
    REQUIRE(dat == KongsbergAllUnknown(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == KongsbergAllUnknown(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(size_t(dat.get_bytes()) == 15 + dat.get_raw_content().size());
    // length
    REQUIRE(dat.get_bytes() == 40); /// the length was corrected when writing to binary
    dat.set_bytes(123);
    REQUIRE(dat.get_bytes() == 123);

    // datagram type
    dat.set_datagram_identifier(t_KongsbergAllDatagramIdentifier::RawRangeAndAngle);
    REQUIRE(dat.get_datagram_identifier() == t_KongsbergAllDatagramIdentifier::RawRangeAndAngle);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
