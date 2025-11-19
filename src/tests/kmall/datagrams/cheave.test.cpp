// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <sstream>

#include <fmt/format.h>

#include <themachinethatgoesping/echosounders/kmall/datagrams/cheave.hpp>

using namespace std;
using namespace themachinethatgoesping::echosounders::kmall;
using namespace themachinethatgoesping::echosounders::kmall::datagrams;

#define TESTTAG "[kmall]"

TEST_CASE("CHeave should support common functions", TESTTAG)
{
    auto dat = CHeave();

    // Kongsberg header info
    dat.set_datagram_version(1.2);
    dat.set_system_id(65);
    dat.set_echo_sounder_id(2040);
    dat.set_time_sec(1555977823);
    dat.set_time_nanosec(726999998);

    // KMALLMultibeamDatagram content
    dat.set_bytes_content(KMALLMultibeamDatagram::__size_no_mpart);
    dat.set_ping_count(42);
    dat.set_rx_fans_per_ping(2);
    dat.set_rx_fan_index(1);
    dat.set_swaths_per_ping(3);
    dat.set_swath_along_position(0);
    dat.set_tx_transducer_ind(1);
    dat.set_rx_transducer_ind(0);
    dat.set_number_of_rx_transducers(2);
    dat.set_algorithm_type(5);

    // CHeave specific content
    dat.set_heave_m(0.65f);

    const uint32_t datagram_bytes = 256U;
    dat.set_bytes_datagram(datagram_bytes);
    dat.set_bytes_datagram_check(datagram_bytes);

    const auto expected_hash = 14135415538974149001ULL;
    CHECK(dat.binary_hash() == expected_hash);

    // copy semantics
    {
        INFO(fmt::format("copy constructor: {}", CHeave(dat).info_string()));
        REQUIRE(dat == CHeave(dat));
    }

    // binary roundtrip
    {
        auto dat2 = CHeave(dat.from_binary(dat.to_binary()));
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("From binary: {}", dat2.info_string()));
        REQUIRE(dat == dat2);
        CHECK(dat2.binary_hash() == dat.binary_hash());
    }

    // stream roundtrip
    {
        stringstream buffer;
        dat.to_stream(buffer);
        auto dat2 = CHeave(dat.from_stream(buffer));
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("From stream: {}", dat2.info_string()));
        REQUIRE(dat == dat2);
        CHECK(dat2.binary_hash() == dat.binary_hash());
    }

    // object printer should produce output
    REQUIRE(dat.info_string().size() != 0);

    INFO(fmt::format("orig: {}", dat.info_string()));

    // --- KMALLMultibeamDatagram expectations ---
    REQUIRE(dat.get_bytes_content() == KMALLMultibeamDatagram::__size_no_mpart);
    REQUIRE(dat.get_ping_count() == 42);
    REQUIRE(dat.get_rx_fans_per_ping() == 2);
    REQUIRE(dat.get_rx_fan_index() == 1);
    REQUIRE(dat.get_swaths_per_ping() == 3);
    REQUIRE(dat.get_swath_along_position() == 0);
    REQUIRE(dat.get_tx_transducer_ind() == 1);
    REQUIRE(dat.get_rx_transducer_ind() == 0);
    REQUIRE(dat.get_number_of_rx_transducers() == 2);
    REQUIRE(dat.get_algorithm_type() == 5);

    // --- CHeave content ---
    REQUIRE(dat.get_heave_m() == Catch::Approx(0.65f));

    // datagram type + integrity
    REQUIRE(dat.get_datagram_identifier() == t_KMALLDatagramIdentifier::C_HEAVE);
    REQUIRE(dat.get_bytes_datagram() == dat.get_bytes_datagram_check());
    REQUIRE(dat.get_bytes_datagram_check() == datagram_bytes);
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));

    CHECK(dat.binary_hash() == expected_hash);
}
