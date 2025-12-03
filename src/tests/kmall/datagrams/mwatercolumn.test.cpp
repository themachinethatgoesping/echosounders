// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <array>
#include <cstdint>
#include <cstring>
#include <sstream>
#include <type_traits>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/kmallmultibeamdatagram.hpp>
#include <themachinethatgoesping/echosounders/kmall/datagrams/mwatercolumn.hpp>

using namespace std;
using namespace themachinethatgoesping::echosounders::kmall;
using namespace themachinethatgoesping::echosounders::kmall::datagrams;
using namespace themachinethatgoesping::echosounders::kmall::datagrams::substructs;

#define TESTTAG "[kmall]"

namespace {
constexpr uint16_t kNumSectors = 2;
constexpr uint16_t kNumBeams   = 3;
constexpr array<uint16_t, kNumBeams> kSampleCounts = { 4, 3, 2 };

template <typename T>
T make_zeroed()
{
    static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable");
    T value;
    std::memset(&value, 0, sizeof(T));
    return value;
}

MWCTxInfo make_tx_info()
{
    auto info = make_zeroed<MWCTxInfo>();
    info.set_bytes_content(sizeof(MWCTxInfo));
    info.set_number_of_tx_sectors(kNumSectors);
    info.set_num_bytes_per_tx_sector(static_cast<uint16_t>(sizeof(MWCSectorInfo)));
    info.set_padding(-1);
    info.set_heave_m(0.25F);
    return info;
}

vector<MWCSectorInfo> make_tx_sectors()
{
    vector<MWCSectorInfo> sectors;
    sectors.reserve(kNumSectors);
    for (uint16_t idx = 0; idx < kNumSectors; ++idx)
    {
        auto sector = make_zeroed<MWCSectorInfo>();
        sector.set_tilt_angle_re_tx_deg(-20.0F + 2.5F * static_cast<float>(idx));
        sector.set_centre_frequency_hz(30000.0F + 250.0F * static_cast<float>(idx));
        sector.set_tx_beam_width_along_deg(1.5F + 0.1F * static_cast<float>(idx));
        sector.set_tx_sector_number(idx);
        sector.set_padding(static_cast<int16_t>(idx));
        sectors.push_back(sector);
    }
    return sectors;
}

MWCRxInfo make_rx_info()
{
    auto info = make_zeroed<MWCRxInfo>();
    info.set_bytes_content(sizeof(MWCRxInfo));
    info.set_number_of_beams(kNumBeams);
    info.set_number_bytes_per_beam_entry(16);
    info.set_phase_flag(1);
    info.set_tvg_function_applied(2);
    info.set_tvg_offset_db(-3);
    info.set_sample_freq_hz(10000.0F);
    info.set_sound_velocity_m_per_sec(1495.0F);
    return info;
}

MWCRxBeamData make_beam(uint16_t idx)
{
    MWCRxBeamData beam;
    beam.set_sample_are_skipped(0);
    beam.set_beam_pointing_angle_re_vertical_deg(static_cast<int16_t>(-30 + 5 * idx));
    beam.set_start_range_sample_number(static_cast<uint16_t>(100 + idx));
    beam.set_detected_range_in_samples(static_cast<uint16_t>(200 + idx));
    beam.set_transmit_sector_number(static_cast<uint16_t>(idx % kNumSectors));
    beam.set_detected_range_in_samples_high_resolution(150.5F + static_cast<float>(idx));

    auto samples = xt::xtensor<int8_t, 1>::from_shape({ kSampleCounts[idx] });
    for (size_t sample = 0; sample < kSampleCounts[idx]; ++sample)
        samples(sample) = static_cast<int8_t>(10 * idx + static_cast<int>(sample));

    beam.set_sample_amplitudes_05dB(samples);
    return beam;
}

MWCRxBeamDataContainer make_beam_container()
{
    MWCRxBeamDataContainer container;
    vector<MWCRxBeamData>  beams;
    beams.reserve(kNumBeams);
    for (uint16_t idx = 0; idx < kNumBeams; ++idx)
        beams.push_back(make_beam(idx));
    container.set_beams(beams);
    return container;
}

uint32_t compute_total_datagram_size(size_t num_sectors, const MWCRxBeamDataContainer& beams)
{
    const auto tx_bytes = sizeof(MWCTxInfo) + num_sectors * sizeof(MWCSectorInfo);
    const auto rx_bytes = sizeof(MWCRxInfo);

    size_t beam_bytes = 0;
    for (const auto& beam : beams.get_beams())
        beam_bytes += 16 + beam.get_number_of_samples();

    const auto body_bytes = KMALLMultibeamDatagram::__size + tx_bytes + rx_bytes + beam_bytes;
    return static_cast<uint32_t>(KMALLDatagram::__size + body_bytes);
}

MWaterColumn make_datagram()
{
    MWaterColumn dat;
    dat.set_datagram_version(2);
    dat.set_system_id(11);
    dat.set_echo_sounder_id(2040);
    dat.set_time_sec(1'680'001'234);
    dat.set_time_nanosec(345'678'901);

    dat.set_number_of_datagrams(1);
    dat.set_datagram_number(1);
    dat.set_ping_count(42);
    dat.set_rx_fans_per_ping(1);
    dat.set_rx_fan_index(0);
    dat.set_swaths_per_ping(1);
    dat.set_swath_along_position(0);
    dat.set_tx_transducer_ind(0);
    dat.set_rx_transducer_ind(0);
    dat.set_number_of_rx_transducers(1);
    dat.set_algorithm_type(3);

    auto tx_info   = make_tx_info();
    auto sectors   = make_tx_sectors();
    auto rx_info   = make_rx_info();
    auto beam_data = make_beam_container();

    dat.set_tx_info(tx_info);
    dat.set_tx_sectors(sectors);
    dat.set_rx_info(rx_info);
    dat.set_beam_data(beam_data);

    const auto total_bytes = compute_total_datagram_size(sectors.size(), dat.get_beam_data());
    dat.set_bytes_datagram(total_bytes);
    dat.set_bytes_content(static_cast<uint16_t>(total_bytes - KMALLDatagram::__size));
    dat.set_bytes_datagram_check(total_bytes);

    return dat;
}

} // namespace

TEST_CASE("MWaterColumn serializes and exposes beam metadata", TESTTAG)
{
    const auto dat = make_datagram();
    const auto dat2 = make_datagram();

    REQUIRE(dat == dat2);
    REQUIRE(dat.binary_hash() == dat2.binary_hash());

    const auto expected_hash = 6535527905040477869ULL;
    CHECK(dat.binary_hash() == expected_hash);

    {
        auto copy = MWaterColumn(dat);
        CHECK(copy == dat);
    }

    {
        auto from_binary = MWaterColumn(dat.from_binary(dat.to_binary()));
        CHECK(from_binary == dat);
    }

    {
        stringstream buffer;
        dat.to_stream(buffer);
        auto from_stream = MWaterColumn(MWaterColumn::from_stream(buffer));
        CHECK(from_stream == dat);
    }

    const auto& sectors = dat.get_tx_sectors();
    REQUIRE(sectors.size() == kNumSectors);
    CHECK(sectors.front().get_tilt_angle_re_tx_deg() == Catch::Approx(-20.0F));

    const auto& beams = dat.get_beam_data().get_beams();
    REQUIRE(beams.size() == kNumBeams);
    CHECK(dat.get_beam_data().get_total_number_of_samples() == 9);

    const auto angles = dat.get_beam_data().get_beam_pointing_angle_re_vertical_deg_tensor();
    REQUIRE(angles.size() == kNumBeams);
    for (size_t idx = 0; idx < angles.size(); ++idx)
        CHECK(angles(idx) == Catch::Approx(static_cast<float>(-30 + 5 * static_cast<int>(idx))));

    const auto start_samples = dat.get_beam_data().get_start_range_sample_number_tensor();
    for (size_t idx = 0; idx < start_samples.size(); ++idx)
        CHECK(start_samples(idx) == static_cast<uint16_t>(100 + idx));

    const auto& rx_info = dat.get_rx_info();
    CHECK(rx_info.get_number_of_beams() == kNumBeams);
    CHECK(rx_info.get_sample_freq_hz() == Catch::Approx(10000.0F));

    CHECK(dat.binary_hash() == expected_hash);
}

TEST_CASE("MWaterColumn supports skip_data reads", TESTTAG)
{
    const auto dat = make_datagram();

    auto dat_skipped = dat;
    for (auto& beam : dat_skipped.beam_data().beams())
        beam.set_sample_are_skipped(0);

    {
        stringstream buffer;
        dat.to_stream(buffer);
        auto parsed = MWaterColumn(MWaterColumn::from_stream(buffer, false));
        CHECK(parsed == dat);
    }

    {
        stringstream buffer;
        dat.to_stream(buffer);
        auto parsed = MWaterColumn(MWaterColumn::from_stream(buffer, true));
        CHECK(parsed == dat_skipped);
        for (const auto& beam : parsed.get_beam_data().get_beams())
            CHECK(beam.get_samples_are_skipped());
    }
}
