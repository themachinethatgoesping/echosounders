// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/kongsbergall/datagrams/extraparameters.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::kongsbergall::datagrams;
#define TESTTAG "[kongsbergall]"

TEST_CASE("ExtraParameters should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = ExtraParameters();

    std::string raw_content = "Its'e mee";

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);
    dat.set_raw_content(raw_content);
    dat.set_bytes(raw_content.size() + 22);

    dat.set_ping_counter(123);
    dat.set_system_serial_number(100);
    dat.set_content_identifier(ExtraParameters::t_ContentIdentifier::CalibTxt);

    // test inequality
    // REQUIRE(dat != ExtraParameters());

    // test copy
    REQUIRE(dat == ExtraParameters(dat));

    // test binary
    REQUIRE(dat == ExtraParameters(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == ExtraParameters(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    CHECK(dat.get_bytes() == raw_content.size() + 22);
    CHECK(dat.get_ping_counter() == 123);
    CHECK(dat.get_system_serial_number() == 100);
    CHECK(dat.get_raw_content() == raw_content);
    CHECK(dat.get_content_identifier() == ExtraParameters::t_ContentIdentifier::CalibTxt);

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KongsbergAllDatagramIdentifier::ExtraParameters);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
