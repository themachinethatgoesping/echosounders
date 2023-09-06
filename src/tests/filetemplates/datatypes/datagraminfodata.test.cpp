// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <xtensor/xtensor.hpp>

#include <themachinethatgoesping/echosounders/em3000/em3000_types.hpp>
#include <themachinethatgoesping/echosounders/simrad/simrad_types.hpp>

// note: this must be defined below the em3000/simrad includes otherwise datagram_identifier_to_string is unknown
#include <themachinethatgoesping/echosounders/filetemplates/datatypes/datagraminfo.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;
using namespace themachinethatgoesping::echosounders;
#define TESTTAG "[filetemplates]"

template<typename t_DatagramInfoData>
void test(t_DatagramInfoData& obj)
{
    auto obj2 = t_DatagramInfoData(
        obj.get_file_pos() + 10, obj.get_timestamp() - 12, obj.get_datagram_identifier());

    // test inequality
    CHECK(obj != obj2);

    // test copy
    CHECK(obj == DatagramInfoData(obj));

    // test binary
    CHECK(obj == DatagramInfoData(obj.from_binary(obj.to_binary())));

    // test stream
    std::stringstream buffer;
    obj.to_stream(buffer);
    CHECK(obj == DatagramInfoData(obj.from_stream(buffer)));

    // test print does not crash
    CHECK(obj.info_string().size() != 0);
}

TEST_CASE("DatagramInfoDatashould support common functions", TESTTAG)
{
    SECTION("EM3000")
    {
        // initialize class structure
        auto obj = DatagramInfoData<em3000::t_EM3000DatagramIdentifier>(
            1002, 1234567890.1234567890, em3000::t_EM3000DatagramIdentifier::AttitudeDatagram);

        // test common functions
        test(obj);
    }

    SECTION("Simrad")
    {
        // initialize class structure
        auto obj = DatagramInfoData<simrad::t_SimradDatagramIdentifier>(
            1002, 1234567890.1234567890, simrad::t_SimradDatagramIdentifier::RAW3);

        // test common functions
        test(obj);
    }
}
