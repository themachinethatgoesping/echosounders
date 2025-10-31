// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include <themachinethatgoesping/echosounders/kmall/datagrams/iopruntime.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kmall;
using namespace themachinethatgoesping::echosounders::kmall::datagrams;
#define TESTTAG "[kmall]"

TEST_CASE("IOpRuntime should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = IOpRuntime();

    std::string test_text = "testvar: testval\n";

    // set some variables
    dat.set_datagram_version(1.2);
    dat.set_system_id(123);
    dat.set_echo_sounder_id(2040);
    dat.set_time_sec(1555977823);
    dat.set_time_nanosec(726999998);
    dat.set_info(11);
    dat.set_status(12);
    dat.set_runtime_txt(test_text);
    CHECK(dat.binary_hash() == 3408683073847332355ULL);

    // test inequality
    // REQUIRE(dat != IOpRuntime());

    // test copy
    {
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("copy constructor: {}", IOpRuntime(dat).info_string()));
        CHECK(dat == IOpRuntime(dat));
    }

    // test binary
    {
        auto dat2 = IOpRuntime(dat.from_binary(dat.to_binary()));
        INFO(fmt::format("orig: {}", dat.info_string()));
        INFO(fmt::format("From binary: {}", dat2.info_string()));
        REQUIRE(dat == dat2);
        CHECK(dat2.binary_hash() == dat.binary_hash());
    }

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == IOpRuntime(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    REQUIRE(dat.get_bytes_content() == dat.compute_size_content());
    REQUIRE(dat.get_info() == 11);
    REQUIRE(dat.get_status() == 12);
    REQUIRE(dat.get_runtime_txt().substr(0, test_text.size()) == test_text);

    // datagram type
    REQUIRE(dat.get_datagram_identifier() == t_KMALLDatagramIdentifier::I_OP_RUNTIME);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));

    REQUIRE(dat.get_bytes_datagram() == dat.get_bytes_datagram_check());

    CHECK(dat.binary_hash() == 3408683073847332355ULL);
}
