// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include <boost/functional/hash.hpp> // Include the Boost Hash library

#include "../themachinethatgoesping/echosounders/kongsbergall/datagrams/watercolumndatagram.hpp"
#include "../themachinethatgoesping/echosounders/kongsbergall/filedatatypes/_sub/systeminformation.hpp"
#include <themachinethatgoesping/echosounders/filetemplates/datatypes/cache_structures/packagecache.hpp>

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using themachinethatgoesping::echosounders::kongsbergall::filedatatypes::_sub::SystemInformation;
#define TESTTAG "[kongsbergall]"

datagrams::WatercolumnDatagram make_wcd()
{
    // initialize class structure
    auto dat             = datagrams::WatercolumnDatagram();
    auto transmit_sector = datagrams::substructures::WatercolumnDatagramTransmitSector();
    datagrams::substructures::WatercolumnDatagramBeam beam1, beam2;

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_sound_speed(201);
    dat.set_ping_counter(202);
    dat.set_system_serial_number(203);
    dat.set_sampling_frequency(204);
    dat.set_tx_time_heave(205);
    dat.set_tvg_function_applied(207);
    dat.set_tvg_offset_in_db(-50);

    transmit_sector.set_tilt_angle(101);
    transmit_sector.set_center_frequency(191);
    dat.set_transmit_sectors({ transmit_sector });

    beam1.set_beam_crosstrack_angle(101);
    beam1.set_transmit_sector_number(191);
    beam1.set_start_range_sample_number(4);
    beam1.set_number_of_samples(50);
    beam1.set_detected_range_in_samples(40);

    beam2.set_beam_crosstrack_angle(-20);
    beam2.set_transmit_sector_number(23);
    beam2.set_start_range_sample_number(4);
    beam2.set_number_of_samples(60);
    beam2.set_detected_range_in_samples(54);
    dat.set_beams({ beam1, beam2 });

    // check the required functions do not throw
    // CHECK(dat.get_beams().size() == 1);

    return dat;
}

datagrams::RawRangeAndAngle make_rra()
{
    // initialize class structure
    auto dat             = datagrams::RawRangeAndAngle();
    auto transmit_sector = datagrams::substructures::RawRangeAndAngleTransmitSector();
    auto beam            = datagrams::substructures::RawRangeAndAngleBeam();

    // set some variables
    dat.set_bytes(100);
    dat.set_model_number(710);
    dat.set_date(20190423);
    dat.set_time_since_midnight(223727);

    dat.set_sound_speed_at_transducer(201);
    dat.set_ping_counter(202);
    dat.set_system_serial_number(203);
    dat.set_sampling_frequency(204);
    dat.set_d_scale(205);

    transmit_sector.set_center_frequency(191);
    transmit_sector.set_signal_bandwidth(101);
    transmit_sector.set_mean_absorption_coefficient(101);
    transmit_sector.set_signal_length(121);
    transmit_sector.set_tilt_angle(191);
    transmit_sector.set_signal_waveform_identifier(1); // FM_UP_SWEEP
    dat.set_transmit_sectors({ transmit_sector });

    beam.set_quality_factor(101);
    beam.set_reflectivity(191);
    dat.set_beams({ beam });

    return dat;
}

TEST_CASE("SystemInformation should be initialized correctly from RawRangeAndAngle", TESTTAG)
{
    using namespace themachinethatgoesping::algorithms::signalprocessing::datastructures;
    using namespace themachinethatgoesping::algorithms::signalprocessing::types;

    SystemInformation dat(make_rra());

    using Catch::Approx;

    // using TxSignalParameters = std::variant<CWSignalParameters, FMSignalParameters,
    // GenericSignalParameters>;
    CHECK(dat.get_tx_signal_parameters().size() == 1);
    auto signal_parameters = std::get<FMSignalParameters>(dat.get_tx_signal_parameters()[0]);

    INFO(signal_parameters.info_string());
    CHECK(signal_parameters.center_frequency == Approx(191));
    CHECK(signal_parameters.bandwidth == Approx(101));
    CHECK(signal_parameters.effective_pulse_duration == Approx(121));
    CHECK(signal_parameters.get_tx_signal_type() == t_TxSignalType::FM_UP_SWEEP);

    // test inequality
    // REQUIRE(dat != SystemInformation());

    // test copy
    REQUIRE(dat == SystemInformation(dat));

    // test stream (with hash cache)
    std::unordered_map<size_t, std::string> hash_cache;
    std::stringstream                       buffer;

    dat.to_stream(buffer, hash_cache);
    REQUIRE(dat == SystemInformation(dat.from_stream(buffer, hash_cache)));
}

TEST_CASE("SystemInformation should be initialized correctly from WaterColumnDatagram", TESTTAG)
{
    using namespace themachinethatgoesping::algorithms::signalprocessing::datastructures;
    using namespace themachinethatgoesping::algorithms::signalprocessing::types;

    SystemInformation dat(make_wcd());

    using Catch::Approx;

    // using TxSignalParameters = std::variant<CWSignalParameters, FMSignalParameters,
    // GenericSignalParameters>;
    CHECK(dat.get_tx_signal_parameters().size() == 1);
    auto signal_parameters = std::get<GenericSignalParameters>(dat.get_tx_signal_parameters()[0]);

    INFO(signal_parameters.info_string());
    CHECK(signal_parameters.center_frequency == Approx(191));
    CHECK(std::isnan(signal_parameters.bandwidth));
    CHECK(std::isnan(signal_parameters.effective_pulse_duration));
    CHECK(signal_parameters.get_tx_signal_type() == t_TxSignalType::UNKNOWN);

    // test inequality
    // REQUIRE(dat != SystemInformation());

    // test copy
    REQUIRE(dat == SystemInformation(dat));

    // test stream (with hash cache)
    std::unordered_map<size_t, std::string> hash_cache;
    std::stringstream                       buffer;

    dat.to_stream(buffer, hash_cache);
    REQUIRE(dat == SystemInformation(dat.from_stream(buffer, hash_cache)));
}

TEST_CASE("SystemInformation should be convertible to PackageCache", TESTTAG)
{
    using themachinethatgoesping::echosounders::filetemplates::datatypes::cache_structures::
        PackageCache;

    // initialize class structure
    auto              wcd = make_wcd();
    auto              rra = make_rra();
    SystemInformation dat(wcd);
    SystemInformation dat2(rra);

    std::unordered_map<size_t, std::string> hash_cache;

    PackageCache<SystemInformation> package_cache(0, 0, std::make_unique<SystemInformation>(dat));
    PackageCache<SystemInformation> package_cache2(0, 0, std::make_unique<SystemInformation>(wcd));
    PackageCache<SystemInformation> package_cache3(0, 0, std::make_unique<SystemInformation>(dat2));

    // test basic access
    REQUIRE(dat == package_cache.get());
    REQUIRE(dat2 == package_cache3.get());
    REQUIRE(package_cache.get() == package_cache2.get());
    REQUIRE(package_cache.get() != package_cache3.get());

    // test to/from binary
    SECTION("PackageCache: to/from binary")
    {
        REQUIRE(package_cache ==
                package_cache.from_binary(package_cache.to_binary(hash_cache), hash_cache));
        REQUIRE(dat ==
                package_cache.from_binary(package_cache.to_binary(hash_cache), hash_cache).get());

        REQUIRE(package_cache3 ==
                package_cache3.from_binary(package_cache3.to_binary(hash_cache), hash_cache));
        REQUIRE(dat2 ==
                package_cache3.from_binary(package_cache3.to_binary(hash_cache), hash_cache).get());
    }
}