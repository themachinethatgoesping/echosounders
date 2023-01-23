// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include "../themachinethatgoesping/echosounders/em3000/datagrams/installationparameters.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::em3000;
using namespace themachinethatgoesping::echosounders::em3000::datagrams;
#define TESTTAG "[em3000]"

TEST_CASE("InstallationParameters should support common functions", TESTTAG)
{
    // initialize class structure
    auto dat = InstallationParameters();

    std::string installation_parameters = "WLZ=x.x,SMH=x.x,S0Z=x.x";

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);
    dat.set_installation_parameters(installation_parameters);
    dat.set_bytes(installation_parameters.size() + 21);

    dat.set_installation_parameters_counter(123);
    dat.set_system_serial_number(100);

    // test inequality
    // REQUIRE(dat != InstallationParameters());

    // test copy
    REQUIRE(dat == InstallationParameters(dat));

    // test binary
    REQUIRE(dat == InstallationParameters(dat.from_binary(dat.to_binary())));

    // test stream
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == InstallationParameters(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);

    //--- datagram concept ---
    CHECK(dat.get_bytes() == installation_parameters.size() + 21);
    CHECK(dat.get_installation_parameters_counter() == 123);
    CHECK(dat.get_system_serial_number() == 100);
    CHECK(dat.get_installation_parameters() == installation_parameters);

    // datagram type
    REQUIRE(dat.get_datagram_identifier() ==
            t_EM3000DatagramIdentifier::InstallationParametersStart);

    // timestamp (unixtime)
    REQUIRE(dat.get_timestamp() == Catch::Approx(1555977823.7269999981));
}
