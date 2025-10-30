// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include <themachinethatgoesping/echosounders/kmall/datagrams/kmallunknown.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kmall;
using themachinethatgoesping::echosounders::kmall::datagrams::KMALLUnknown;
using themachinethatgoesping::echosounders::kmall::datagrams::KMALLDatagram;

#define TESTTAG "[kmall]"

TEST_CASE("KMALLUnknown should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = KMALLUnknown();

    // set some variables
    dat.set_dgm_type(t_KMALLDatagramIdentifier::M_WATER_COLUMN);
    dat.set_dgm_version(1.2);
    dat.set_system_id(123);
    dat.set_echo_sounder_id(2040);
    dat.set_time_sec(1555977823);
    dat.set_time_nanosec(726999998);

    dat.set_raw_content("Test data content");

    // test inequality
    REQUIRE(dat != KMALLUnknown());

    // test copy
    REQUIRE(dat == KMALLUnknown(dat));

    // test binary
    REQUIRE(dat == KMALLUnknown(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == KMALLUnknown(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    // length is corrected when call set_raw_content
    REQUIRE(size_t(dat.get_num_bytes_dgm()) == sizeof(KMALLDatagram) + dat.get_raw_content().size());

    // datagram type
    dat.set_datagram_identifier(t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH);
    REQUIRE(dat.get_datagram_identifier() == t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
