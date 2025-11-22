// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <cmath>
#include <sstream>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mrzextradetclassinfo.hpp>
#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mrzpinginfo.hpp>
#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mrzrxinfo.hpp>
#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mrzsectorinfo.hpp>
#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mrzsoundings.hpp>
#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mrzsoundingscontainer.hpp>

using namespace themachinethatgoesping::echosounders::kmall::datagrams::substructs;

#define TESTTAG "[kmall]"

TEST_CASE("MRZPingInfo stores configured metadata", TESTTAG)
{
    MRZPingInfo info;
    info.set_ping_rate_hz(2.5F);
    info.set_beam_spacing(1);
    info.set_depth_mode(2);
    info.set_detection_mode(3);
    info.set_frequency_mode_hz(28000.0F);
    info.set_port_mean_coverage_deg(30.0F);
    info.set_starboard_mean_coverage_deg(32.0F);
    info.set_yaw_angle_deg(0.75F);
    info.set_heading_vessel_deg(112.5F);
    info.set_sound_speed_at_tx_depth_m_per_sec(1485.0F);
    info.set_latitude_deg(60.25);
    info.set_longitude_deg(5.75);

    CHECK(info.get_ping_rate_hz() == Catch::Approx(2.5F));
    CHECK(info.get_beam_spacing() == 1);
    CHECK(info.get_depth_mode() == 2);
    CHECK(info.get_detection_mode() == 3);
    CHECK(info.get_frequency_mode_hz() == Catch::Approx(28000.0F));
    CHECK(info.get_port_mean_coverage_deg() == Catch::Approx(30.0F));
    CHECK(info.get_starboard_mean_coverage_deg() == Catch::Approx(32.0F));
    CHECK(info.get_yaw_angle_deg() == Catch::Approx(0.75F));
    CHECK(info.get_heading_vessel_deg() == Catch::Approx(112.5F));
    CHECK(info.get_sound_speed_at_tx_depth_m_per_sec() == Catch::Approx(1485.0F));
    CHECK(info.get_latitude_deg() == Catch::Approx(60.25));
    CHECK(info.get_longitude_deg() == Catch::Approx(5.75));
}

TEST_CASE("MRZSectorInfo version 0 round-trip preserves fields", TESTTAG)
{
    MRZSectorInfo sector;
    sector.set_tx_sector_number(7);
    sector.set_tx_arrary_number(4);
    sector.set_tx_sub_array(1);
    sector.set_sector_transmit_delay_sec(0.002F);
    sector.set_tilt_angle_re_tx_deg(-20.5F);
    sector.set_tx_nominal_source_level_db(201.5F);
    sector.set_tx_focus_range_m(45.0F);
    sector.set_centre_frequency_hz(31000.0F);
    sector.set_signal_band_width_hz(420.0F);
    sector.set_total_signal_length_sec(0.012F);
    sector.set_pulse_shading(3);
    sector.set_signal_wave_form(4);

    std::stringstream buffer;
    sector.__write_version_0__(buffer);
    auto restored = MRZSectorInfo::__read_version_0__(buffer);

    //CHECK(restored == sector);
    CHECK(restored.get_tx_sector_number() == sector.get_tx_sector_number());
    CHECK(restored.get_tx_arrary_number() == sector.get_tx_arrary_number());
    CHECK(restored.get_tx_sub_array() == sector.get_tx_sub_array());
    CHECK(restored.get_sector_transmit_delay_sec() == Catch::Approx(sector.get_sector_transmit_delay_sec()));
    CHECK(restored.get_tilt_angle_re_tx_deg() == Catch::Approx(sector.get_tilt_angle_re_tx_deg()));
    CHECK(restored.get_tx_nominal_source_level_db() == Catch::Approx(sector.get_tx_nominal_source_level_db()));
    CHECK(restored.get_tx_focus_range_m() == Catch::Approx(sector.get_tx_focus_range_m()));
    CHECK(restored.get_centre_frequency_hz() == Catch::Approx(sector.get_centre_frequency_hz()));
    CHECK(restored.get_signal_band_width_hz() == Catch::Approx(sector.get_signal_band_width_hz()));
    CHECK(restored.get_total_signal_length_sec() == Catch::Approx(sector.get_total_signal_length_sec()));
    CHECK(restored.get_pulse_shading() == sector.get_pulse_shading());
    CHECK(restored.get_signal_wave_form() == sector.get_signal_wave_form());

    CHECK(std::isnan(restored.get_high_voltage_level_db()));
    CHECK(std::isnan(restored.get_sector_tracking_corr_db()));
    CHECK(std::isnan(restored.get_effective_signal_length_sec()));
}

TEST_CASE("MRZRxInfo reports sounding statistics", TESTTAG)
{
    MRZRxInfo info;
    info.set_bytes_content(sizeof(MRZRxInfo));
    info.set_number_of_soundings_max_main(400);
    info.set_number_of_soundings_valid_main(398);
    info.set_number_of_bytes_per_sounding(256);
    info.set_wc_sample_rate(6500.0F);
    info.set_seabed_image_sample_rate(1800.0F);
    info.set_bs_normal_db(-3.0F);
    info.set_bs_oblique_db(-6.0F);
    info.set_extra_detection_alarm_flag(0xAA55);
    info.set_number_of_extra_detections(5);
    info.set_number_of_extra_detection_classes(3);
    info.set_number_of_bytes_per_class(24);

    CHECK(info.get_bytes_content() == sizeof(MRZRxInfo));
    CHECK(info.get_number_of_soundings_max_main() == 400);
    CHECK(info.get_number_of_soundings_valid_main() == 398);
    CHECK(info.get_number_of_extra_detections() == 5);
    CHECK(info.get_number_of_extra_detection_classes() == 3);
    CHECK(info.get_number_of_bytes_per_class() == 24);
    CHECK(info.get_wc_sample_rate() == Catch::Approx(6500.0F));
    CHECK(info.get_seabed_image_sample_rate() == Catch::Approx(1800.0F));
}

TEST_CASE("MRZExtraDetClassInfo exposes alarm flag", TESTTAG)
{
    MRZExtraDetClassInfo cls;
    cls.set_num_extra_det_in_class(9);
    cls.set_padding(-2);
    cls.set_alarm_flag(7);

    CHECK(cls.get_num_extra_det_in_class() == 9);
    CHECK(cls.get_padding() == -2);
    CHECK(cls.get_alarm_flag() == 7);

    MRZExtraDetClassInfo copy = cls;
    CHECK(copy == cls);
}

TEST_CASE("MRZSoundingsContainer aggregates tensors", TESTTAG)
{
    MRZSoundings s1;
    s1.set_sounding_index(10);
    s1.set_tx_sector_number(1);
    s1.set_range_factor(0.6F);
    s1.set_quality_factor(0.7F);
    s1.set_wc_beam_number(210);
    s1.set_si_num_samples(3);
    s1.set_si_start_range_samples(90);
    s1.set_si_centre_sample(95);

    MRZSoundings s2;
    s2.set_sounding_index(11);
    s2.set_tx_sector_number(0);
    s2.set_range_factor(0.8F);
    s2.set_quality_factor(0.9F);
    s2.set_wc_beam_number(212);
    s2.set_si_num_samples(2);
    s2.set_si_start_range_samples(92);
    s2.set_si_centre_sample(97);

    MRZSoundingsContainer container;
    container.set_soundings({ s1, s2 });

    CHECK(container.get_number_of_soundings() == 2);
    CHECK(container.get_number_of_seabed_image_samples() == 5);

    auto sounding_indices = container.get_sounding_index_tensor();
    REQUIRE(sounding_indices.size() == 2);
    CHECK(sounding_indices(0) == 10);
    CHECK(sounding_indices(1) == 11);

    auto tx_indices = container.get_tx_sector_number_tensor();
    CHECK(tx_indices(0) == 1);
    CHECK(tx_indices(1) == 0);

    auto range_factors = container.get_range_factor_tensor();
    CHECK(range_factors(0) == Catch::Approx(0.6F));
    CHECK(range_factors(1) == Catch::Approx(0.8F));

    auto seabed_index_tensor = container.get_seabed_image_sounding_index_tensor();
    REQUIRE(seabed_index_tensor.size() == 5);
    CHECK(seabed_index_tensor(0) == 0);
    CHECK(seabed_index_tensor(1) == 0);
    CHECK(seabed_index_tensor(2) == 0);
    CHECK(seabed_index_tensor(3) == 1);
    CHECK(seabed_index_tensor(4) == 1);
}
