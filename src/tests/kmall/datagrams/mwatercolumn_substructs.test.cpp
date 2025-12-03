// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mwcrxbeamdata.hpp>
#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mwcrxbeamdatacontainer.hpp>
#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mwcrxinfo.hpp>
#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mwcsectorinfo.hpp>
#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mwctxinfo.hpp>

using namespace themachinethatgoesping::echosounders::kmall::datagrams::substructs;

#define TESTTAG "[kmall]"

namespace {

MWCRxBeamData make_beam(uint16_t idx, uint16_t sample_count)
{
    MWCRxBeamData beam;
    beam.set_beam_pointing_angle_re_vertical_deg(static_cast<int16_t>(-25 + 3 * idx));
    beam.set_start_range_sample_number(static_cast<uint16_t>(80 + idx));
    beam.set_detected_range_in_samples(static_cast<uint16_t>(160 + idx));
    beam.set_transmit_sector_number(idx % 2);
    beam.set_detected_range_in_samples_high_resolution(120.25F + static_cast<float>(idx));

    auto samples = xt::xtensor<int8_t, 1>::from_shape({ sample_count });
    for (size_t sample = 0; sample < sample_count; ++sample)
        samples(sample) = static_cast<int8_t>(5 * idx + static_cast<int>(sample));
    beam.set_sample_amplitudes_05dB(samples);
    return beam;
}

} // namespace

TEST_CASE("MWCTxInfo stores configured metadata", TESTTAG)
{
    MWCTxInfo info;
    info.set_bytes_content(sizeof(MWCTxInfo));
    info.set_number_of_tx_sectors(3);
    info.set_num_bytes_per_tx_sector(static_cast<uint16_t>(sizeof(MWCSectorInfo)));
    info.set_padding(-2);
    info.set_heave_m(0.35F);

    CHECK(info.get_bytes_content() == sizeof(MWCTxInfo));
    CHECK(info.get_number_of_tx_sectors() == 3);
    CHECK(info.get_num_bytes_per_tx_sector() == sizeof(MWCSectorInfo));
    CHECK(info.get_padding() == -2);
    CHECK(info.get_heave_m() == Catch::Approx(0.35F));
}

TEST_CASE("MWCSectorInfo captures transmit geometry", TESTTAG)
{
    MWCSectorInfo sector;
    sector.set_tilt_angle_re_tx_deg(-18.5F);
    sector.set_centre_frequency_hz(30500.0F);
    sector.set_tx_beam_width_along_deg(1.75F);
    sector.set_tx_sector_number(5);
    sector.set_padding(-1);

    CHECK(sector.get_tilt_angle_re_tx_deg() == Catch::Approx(-18.5F));
    CHECK(sector.get_centre_frequency_hz() == Catch::Approx(30500.0F));
    CHECK(sector.get_tx_beam_width_along_deg() == Catch::Approx(1.75F));
    CHECK(sector.get_tx_sector_number() == 5);
    CHECK(sector.get_padding() == -1);

    MWCSectorInfo copy = sector;
    CHECK(copy == sector);
}

TEST_CASE("MWCRxInfo reports beam sampling configuration", TESTTAG)
{
    MWCRxInfo info;
    info.set_bytes_content(sizeof(MWCRxInfo));
    info.set_number_of_beams(12);
    info.set_number_bytes_per_beam_entry(18);
    info.set_phase_flag(1);
    info.set_tvg_function_applied(2);
    info.set_tvg_offset_db(-4);
    info.set_sample_freq_hz(9500.0F);
    info.set_sound_velocity_m_per_sec(1492.0F);

    CHECK(info.get_bytes_content() == sizeof(MWCRxInfo));
    CHECK(info.get_number_of_beams() == 12);
    CHECK(info.get_number_bytes_per_beam_entry() == 18);
    CHECK(info.get_phase_flag() == 1);
    CHECK(info.get_tvg_function_applied() == 2);
    CHECK(info.get_tvg_offset_db() == -4);
    CHECK(info.get_sample_freq_hz() == Catch::Approx(9500.0F));
    CHECK(info.get_sound_velocity_m_per_sec() == Catch::Approx(1492.0F));
}

TEST_CASE("MWCRxBeamData converts amplitudes to dB", TESTTAG)
{
    MWCRxBeamData beam;
    beam.set_beam_pointing_angle_re_vertical_deg(-10);
    beam.set_start_range_sample_number(90);
    beam.set_detected_range_in_samples(150);
    beam.set_transmit_sector_number(0);
    beam.set_detected_range_in_samples_high_resolution(121.5F);

    auto samples = xt::xtensor<int8_t, 1>::from_shape({ 3 });
    samples(0)    = 2;
    samples(1)    = 4;
    samples(2)    = 6;
    beam.set_sample_amplitudes_05dB(samples);

    const auto db = beam.get_sample_amplitudes_in_db(1.0F);
    REQUIRE(db.size() == 3);
    CHECK(db(0) == Catch::Approx(0.0F));
    CHECK(db(1) == Catch::Approx(1.0F));
    CHECK(db(2) == Catch::Approx(2.0F));
}

TEST_CASE("MWCRxBeamDataContainer aggregates tensors", TESTTAG)
{
    MWCRxBeamDataContainer container;
    container.set_beams({ make_beam(0, 3), make_beam(1, 2) });

    CHECK(container.get_number_of_beams() == 2);
    CHECK(container.get_total_number_of_samples() == 5);

    const auto angles = container.get_beam_pointing_angle_re_vertical_deg_tensor();
    REQUIRE(angles.size() == 2);
    CHECK(angles(0) == Catch::Approx(-25.0F));
    CHECK(angles(1) == Catch::Approx(-22.0F));

    const auto samples = container.get_number_of_samples_tensor();
    CHECK(samples(0) == 3);
    CHECK(samples(1) == 2);

    const auto sectors = container.get_transmit_sector_number_tensor();
    CHECK(sectors(0) == 0);
    CHECK(sectors(1) == 1);
}
