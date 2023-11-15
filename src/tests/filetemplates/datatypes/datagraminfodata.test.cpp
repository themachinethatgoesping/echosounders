// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <xtensor/xtensor.hpp>

#include <themachinethatgoesping/echosounders/kongsbergall/types.hpp>
#include <themachinethatgoesping/echosounders/simradraw/types.hpp>

// note: this must be defined below the kongsbergall/simradraw includes otherwise
// datagram_identifier_to_string is unknown
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

    obj.set_extra_infos("test");

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

    // test extra infos
    obj2 = DatagramInfoData(obj.from_binary(obj.to_binary()));
    CHECK(obj2.get_extra_infos() == "test");
}

TEST_CASE("DatagramInfoDatashould support common functions", TESTTAG)
{
    SECTION("KongsbergAll")
    {
        // initialize class structure
        auto obj = DatagramInfoData<kongsbergall::t_KongsbergAllDatagramIdentifier>(
            1002, 1234567890.1234567890, kongsbergall::t_KongsbergAllDatagramIdentifier::AttitudeDatagram);

        // test common functions
        test(obj);
    }

    SECTION("SimradRaw")
    {
        // initialize class structure
        auto obj = DatagramInfoData<simradraw::t_SimradRawDatagramIdentifier>(
            1002, 1234567890.1234567890, simradraw::t_SimradRawDatagramIdentifier::RAW3);

        // test common functions
        test(obj);
    }
}
