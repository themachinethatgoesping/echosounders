// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include <themachinethatgoesping/echosounders/kmall/datagrams/kmalldatagram.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kmall;
using themachinethatgoesping::echosounders::kmall::datagrams::KMALLDatagram;

#define TESTTAG "[kmall]"

TEST_CASE("KMALLDatagram should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = KMALLDatagram();

    // set some variables
    dat.set_bytes_datagram(100);
    dat.set_datagram_identifier(t_KMALLDatagramIdentifier::M_WATER_COLUMN);
    dat.set_datagram_version(1.2);
    dat.set_system_id(123);
    dat.set_echo_sounder_id(2040);
    dat.set_time_sec(1555977823);
    dat.set_time_nanosec(726999998);
    CHECK(dat.binary_hash() == 5054962465029876691ULL);

    // test inequality
    REQUIRE(dat != KMALLDatagram());

    // test copy
    REQUIRE(dat == KMALLDatagram(dat));

    // test binary
    {
        auto dat2 = KMALLDatagram(dat.from_binary(dat.to_binary()));
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("From binary: {}", dat2.info_string()));
        REQUIRE(dat == dat2);
        CHECK(dat2.binary_hash() == dat.binary_hash());
    }

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == KMALLDatagram(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    // length
    REQUIRE(dat.get_bytes_datagram() == 100);
    dat.set_bytes_datagram(123);
    REQUIRE(dat.get_bytes_datagram() == 123);

    // datagram type
    dat.set_datagram_identifier(t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH);
    REQUIRE(dat.get_datagram_identifier() == t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
    CHECK(dat.binary_hash() == 402442181642183149ULL);
}
