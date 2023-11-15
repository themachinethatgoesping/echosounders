// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

#include <xtensor/xio.hpp>

#include "../themachinethatgoesping/echosounders/simradraw/datagrams/RAW3.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simradraw;
using themachinethatgoesping::echosounders::simradraw::datagrams::RAW3;
// using
// themachinethatgoesping::echosounders::simradraw::datagrams::raw3datatypes::get_raw3datatype_size;
// using themachinethatgoesping::echosounders::simradraw::datagrams::raw3datatypes::t_RAW3DataType;
using namespace themachinethatgoesping::echosounders::simradraw::datagrams::raw3datatypes;

#define TESTTAG "[simradraw]"

TEST_CASE("RAW3 should support common functions", TESTTAG)
{
    // initialize class structure
    RAW3 dat;

    // set some variables
    dat.set_timestamp(123);
    dat.set_channel_id("channel1");
    std::vector<t_RAW3DataType> types = { t_RAW3DataType::Power,
                                          t_RAW3DataType::Angle,
                                          t_RAW3DataType::PowerAndAngle,
                                          t_RAW3DataType::ComplexFloat32,
                                          t_RAW3DataType::ComplexFloat16 };

    dat.set_number_of_complex_samples(3);
    dat.set_offset(1);
    dat.set_count(20);

    for (const auto type : types)
    {
        dat.set_data_type(type);
        std::cerr << "Type: " << magic_enum::enum_name(type) << std::endl;

        switch (type)
        {
            case t_RAW3DataType::ComplexFloat32:
                dat.set_sample_data(RAW3DataComplexFloat32(xt::xtensor<simradraw_float, 3>::from_shape(
                    { unsigned(dat.get_count()), dat.get_number_of_complex_samples(), 2 })));
                break;
            case t_RAW3DataType::PowerAndAngle:
                dat.set_sample_data(RAW3DataPowerAndAngle(
                    xt::xtensor<simradraw_short, 1>::from_shape({ unsigned(dat.get_count()) }),
                    xt::xtensor<int8_t, 2>::from_shape({ unsigned(dat.get_count()), 2 })));
                break;
            case t_RAW3DataType::Power:
                dat.set_sample_data(RAW3DataPower(
                    xt::xtensor<simradraw_short, 1>::from_shape({ unsigned(dat.get_count()) })));
                break;
            case t_RAW3DataType::Angle:
                dat.set_sample_data(RAW3DataAngle(
                    xt::xtensor<int8_t, 2>::from_shape({ unsigned(dat.get_count()), 2 })));
                break;
            default:
                std::cerr << fmt::format("WARNING: RAW3 data type [{}] not yet implemented!",
                                         magic_enum::enum_name(dat.get_data_type()))
                          << std::endl;
                dat.set_sample_data(RAW3DataSkipped());
                break;
        }

        auto dat2 = dat;
        dat2.set_channel_id("channel2");

        // test inequality
        REQUIRE(dat != dat2);
        REQUIRE(dat != RAW3());

        // test empty equality (check e.g. nan compare problems)
        REQUIRE(RAW3() == RAW3());

        // test copy
        {
            INFO(fmt::format("orig: {}", dat.info_string()));
            INFO(fmt::format("copy constructor: {}", RAW3(dat).info_string()));
            REQUIRE(dat == RAW3(dat));
        }
        {
            INFO(fmt::format("orig: {}", dat2.info_string()));
            INFO(fmt::format("copy constructor: {}", RAW3(dat2).info_string()));
            REQUIRE(dat2 == RAW3(dat2));
        }

        // dat.print(std::cerr);

        // test binary
        if (type == t_RAW3DataType::ComplexFloat32)
        {
            std::cerr << "-----" << std::endl;
            std::cerr << "dat" << std::endl;
            std::cerr << "-----" << std::endl;
            dat.print(std::cerr);
            std::cerr << "-----" << std::endl;
            std::cerr << "bin" << std::endl;
            std::cerr << "-----" << std::endl;
            RAW3::from_binary(dat.to_binary()).print(std::cerr);
            std::cerr << "-----" << std::endl;
        }
        REQUIRE(dat == RAW3::from_binary(dat.to_binary()));
        REQUIRE(dat2 == RAW3::from_binary(dat2.to_binary()));

        // test stream
        std::stringstream buffer1, buffer2;
        dat.to_stream(buffer1);
        REQUIRE(dat == RAW3(dat.from_stream(buffer1)));

        // test reading header only
        dat.to_stream(buffer2);
        auto dat3 = RAW3::from_stream(buffer2, true);
        if (!std::holds_alternative<RAW3DataSkipped>(dat.get_sample_data()))
            REQUIRE(dat3 != dat);

        dat3.set_sample_data(dat.get_sample_data());
        REQUIRE(dat3 == dat);

        // test print does not crash
        REQUIRE(dat.info_string().size() != 0);

        // --- test data access ---
        REQUIRE(std::string(dat.get_channel_id().substr(0, 7)) == "channel");
        REQUIRE(dat.get_data_type() == type);
        REQUIRE(dat.get_offset() == 1);
        REQUIRE(dat.get_count() == 20);

        // REQUIRE(themachinethatgoesping::tools::helper::approx_container_complex(dat.get_coefficients(),
        // xt::xtensor<simradraw_complex_float>({1, 2, 3, 4})));

        //--- datagram concept ---
        REQUIRE(dat.get_datagram_identifier() == t_SimradRawDatagramIdentifier::RAW3);
        REQUIRE(dat.get_length() ==
                simradraw_long(12 + 140 +
                            dat.get_count() * get_raw3datatype_size(dat.get_data_type()) *
                                dat.get_number_of_complex_samples()));
    }
}
