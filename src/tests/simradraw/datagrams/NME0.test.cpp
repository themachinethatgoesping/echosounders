// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

#include "../themachinethatgoesping/echosounders/simradraw/datagrams/NME0.hpp"

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::simradraw;
using Catch::Approx;
using themachinethatgoesping::echosounders::simradraw::datagrams::NME0;

#define TESTTAG "[simradraw]"

std::string sentence1 =
    "$GPGGA,112619.00,4410.8232,N,03035.6000,E,2,19,0.6,65.2,M,0.0,M,4.0,0525\x00";
std::string sentence2 = "$GPZDA,193715.00,17,03,2022,, ";

TEST_CASE("NME0 should support common functions", TESTTAG)
{
    // initialize class structure
    NME0 dat1, dat2;

    // set some variables
    dat1.set_timestamp(123);
    dat1.set_nmea_base(sentence1);
    dat2.set_nmea_base(sentence2);

    // test inequality
    REQUIRE(dat1 != dat2);

    // test copy
    REQUIRE(dat1 == NME0(dat1));
    REQUIRE(dat2 == NME0(dat2));

    // test binary
    REQUIRE(dat1 == NME0(dat1.from_binary(dat1.to_binary())));
    REQUIRE(dat2 == NME0(dat2.from_binary(dat2.to_binary())));

    // test stream
    std::stringstream buffer;
    dat1.to_stream(buffer);
    REQUIRE(dat1 == NME0(dat1.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat1.info_string().size() != 0);
    REQUIRE(dat2.info_string().size() != 0);

    // ----- test data access -----
    using namespace themachinethatgoesping::navigation::nmea_0183;

    // first sentence (GGA)
    auto gga = std::get<NMEA_GGA>(dat1.decode());
    REQUIRE(std::string(gga.get_sentence()) == sentence1);
    REQUIRE(std::string(gga.get_sentence_type()) == "GGA");
    REQUIRE(std::string(gga.get_sentence_id()) == "GPGGA");
    REQUIRE(std::string(gga.get_sender_id()) == "GP");

    // REQUIRE(gga.get_utc_time_string() == "112619.00");
    REQUIRE(gga.get_latitude() == Approx(44.180386666666664));
    REQUIRE(gga.get_longitude() == Approx(30.593333333333334));
    REQUIRE(gga.get_quality() == 2);
    REQUIRE(std::string(gga.get_quality_explained()) == "DGPS fix");
    REQUIRE(gga.get_number_of_satellites() == 19);
    REQUIRE(gga.get_horizontal_dilution_of_precision() == Approx(0.6));
    REQUIRE(gga.get_altitude() == Approx(65.2));
    REQUIRE(gga.get_geoidal_separation() == Approx(0.0));
    REQUIRE(gga.get_age_of_differential_gps_data() == Approx(4.00));
    REQUIRE(gga.get_differential_reference_station_id() == 525);

    // second sentence (ZDA)
    auto zda = std::get<NMEA_ZDA>(dat2.decode());
    REQUIRE(std::string(zda.get_sentence()) == sentence2);
    REQUIRE(std::string(zda.get_sentence_type()) == "ZDA");
    REQUIRE(std::string(zda.get_sentence_id()) == "GPZDA");
    REQUIRE(std::string(zda.get_sender_id()) == "GP");
    REQUIRE(zda.get_day() == 17);
    REQUIRE(zda.get_month() == 3);
    REQUIRE(zda.get_year() == 2022);
    REQUIRE(zda.get_utc_time_string() == "193715.00");
    REQUIRE(zda.get_local_zone_minutes() == 0);
    REQUIRE(zda.get_local_zone_hours() == 0);

    //--- datagram concept ---

    // datagram type
    REQUIRE(dat1.get_datagram_identifier() == t_SimradRawDatagramIdentifier::NME0);
    REQUIRE(dat2.get_datagram_identifier() == t_SimradRawDatagramIdentifier::NME0);
    REQUIRE(dat1.get_length() == 12 + int64_t(sentence1.size()));
    REQUIRE(dat2.get_length() == 12 + int64_t(sentence2.size()));
}
