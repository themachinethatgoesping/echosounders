// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch.hpp>

#include <filesystem>

#include <xtensor/xio.hpp>

#include "../themachinethatgoesping/echosounders/simrad/datagrams/ek80_RAW3.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::echosounders::simrad::datagrams::EK80_RAW3;
// using
// themachinethatgoesping::echosounders::simrad::datagrams::RAW3_datatypes::RAW3_DataType_size;
// using themachinethatgoesping::echosounders::simrad::datagrams::RAW3_datatypes::t_RAW3_DataType;
using namespace themachinethatgoesping::echosounders::simrad::datagrams::RAW3_datatypes;

#define TESTTAG "[simrad]"

TEST_CASE("EK80_RAW3 should support common functions", TESTTAG)
{
    // initialize class structure
    EK80_RAW3 dat;

    // set some variables
    dat.set_timestamp(123);
    dat.set_channel_id("channel1");
    std::vector<t_RAW3_DataType> types = { t_RAW3_DataType::Power,
                                           t_RAW3_DataType::Angle,
                                           t_RAW3_DataType::PowerAndAngle,
                                           t_RAW3_DataType::ComplexFloat32,
                                           t_RAW3_DataType::ComplexFloat16 };

    dat._NumberOfComplexSamples = 3;
    dat._Offset                 = 1;
    dat._Count                  = 20;

    for (const auto type : types)
    {
        dat._Datatype = type;
        std::cerr << "Type: " << magic_enum::enum_name(type) << std::endl;

        switch (type)
        {
            case t_RAW3_DataType::ComplexFloat32:
                dat._SampleData = RAW3_DataComplexFloat32(xt::xtensor<ek60_float, 3>::from_shape(
                    { unsigned(dat._Count), dat.get_number_of_complex_samples(), 2 }));
                break;
            case t_RAW3_DataType::PowerAndAngle:
                dat._SampleData = RAW3_DataPowerAndAngle(
                    xt::xtensor<ek60_short, 2>::from_shape({ unsigned(dat._Count), 2 }));
                break;
            case t_RAW3_DataType::Power:
                dat._SampleData = RAW3_DataPower(
                    xt::xtensor<ek60_short, 1>::from_shape({ unsigned(dat._Count) }));
                break;
            case t_RAW3_DataType::Angle:
                dat._SampleData = RAW3_DataAngle(
                    xt::xtensor<uint8_t, 2>::from_shape({ unsigned(dat._Count), 2 }));
                break;
            default:
                std::cerr << fmt::format("WARNING: RAW3 data type [{}] not yet implemented!",
                                         magic_enum::enum_name(dat._Datatype))
                          << std::endl;
                dat._SampleData = RAW3_DataSkipped();
                break;
        }

        auto dat2 = dat;
        dat2.set_channel_id("channel2");

        // test inequality
        REQUIRE(dat != dat2);
        REQUIRE(dat != EK80_RAW3());

        // test empty equality (check e.g. nan compare problems)
        REQUIRE(EK80_RAW3() == EK80_RAW3());

        // test copy
        REQUIRE(dat == EK80_RAW3(dat));
        REQUIRE(dat2 == EK80_RAW3(dat2));

        // dat.print(std::cerr);

        // test binary
        if (type == t_RAW3_DataType::ComplexFloat32)
        {
            std::cerr << "-----" << std::endl;
            std::cerr << "dat" << std::endl;
            std::cerr << "-----" << std::endl;
            dat.print(std::cerr);
            std::cerr << "-----" << std::endl;
            std::cerr << "bin" << std::endl;
            std::cerr << "-----" << std::endl;
            EK80_RAW3::from_binary(dat.to_binary()).print(std::cerr);
            std::cerr << "-----" << std::endl;
        }
        REQUIRE(dat == EK80_RAW3::from_binary(dat.to_binary()));
        REQUIRE(dat2 == EK80_RAW3::from_binary(dat2.to_binary()));

        // test stream
        std::stringstream buffer;
        dat.to_stream(buffer);
        REQUIRE(dat == EK80_RAW3(dat.from_stream(buffer)));

        // test print does not crash
        REQUIRE(dat.info_string().size() != 0);

        // --- test data access ---
        REQUIRE(dat.get_channel_id().substr(0, 7) == "channel");
        REQUIRE(dat.get_data_type() == type);
        REQUIRE(dat.get_offset() == 1);
        REQUIRE(dat.get_count() == 20);

        // REQUIRE(themachinethatgoesping::tools::helper::approx_container_complex(dat.get_coefficients(),
        // xt::xtensor<ek60_complex_float>({1, 2, 3, 4})));

        //--- datagram concept ---
        REQUIRE(dat.get_datagram_identifier() == t_EK60_DatagramType::RAW3);
        REQUIRE(dat.get_length() == ek60_long(12 + 140 +
                                              dat._Count * RAW3_DataType_size(dat.get_data_type()) *
                                                  dat.get_number_of_complex_samples()));
    }
}
