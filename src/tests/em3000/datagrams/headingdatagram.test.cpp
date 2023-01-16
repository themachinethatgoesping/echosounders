// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/em3000/datagrams/headingdatagram.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::em3000::datagrams;
#define TESTTAG "[em3000]"

TEST_CASE("HeadingDatagram should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = HeadingDatagram();

    auto times_headings  = xt::empty<uint16_t>(xt::xtensor<uint16_t, 2>::shape_type({ 2, 2 }));
    times_headings(0, 0) = 1234;
    times_headings(0, 1) = 567;
    times_headings(1, 0) = 2345;
    times_headings(1, 1) = 678;

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);
    dat.set_times_headings(times_headings);
    dat.set_number_of_entries(2);

    dat.set_heading_counter(123);
    dat.set_system_serial_number(100);

    // test inequality
    // REQUIRE(dat != HeadingDatagram());

    // test copy
    REQUIRE(dat == HeadingDatagram(dat));

    // test binary
    REQUIRE(dat == HeadingDatagram(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == HeadingDatagram(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(
        dat.get_bytes() ==
        100); // this is of cause wrong because bytes was not adapted to the actual number of bytes
    CHECK(dat.get_heading_counter() == 123);
    CHECK(dat.get_system_serial_number() == 100);

    auto timestamps = dat.get_heading_timestamps();
    auto headings   = dat.get_headings_in_degrees();
    CHECK(timestamps(0) == 1.234 + dat.get_timestamp());
    CHECK(timestamps(1) == 2.345 + dat.get_timestamp());
    CHECK(headings(0) == 5.67f);
    CHECK(headings(1) == 6.78f);

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_EM3000DatagramIdentifier::HeadingDatagram);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
