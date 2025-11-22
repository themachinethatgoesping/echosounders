// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <array>
#include <cstdint>
#include <sstream>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/kmalldatagram.hpp>
#include <themachinethatgoesping/echosounders/kmall/datagrams/kmallmultibeamdatagram.hpp>
#include <themachinethatgoesping/echosounders/kmall/datagrams/mrangeanddepth.hpp>

using namespace std;
using namespace themachinethatgoesping::echosounders::kmall;
using namespace themachinethatgoesping::echosounders::kmall::datagrams;
using namespace themachinethatgoesping::echosounders::kmall::datagrams::substructs;

#define TESTTAG "[kmall]"

namespace {
constexpr uint16_t kNumSectors         = 2;
constexpr uint16_t kNumMainSoundings   = 3;
constexpr uint16_t kNumExtraSoundings  = 1;
constexpr uint16_t kNumExtraClasses    = 2;
constexpr size_t   kTotalSoundings     = kNumMainSoundings + kNumExtraSoundings;

inline constexpr array<uint16_t, kTotalSoundings> kSeabedSampleCounts = { 2, 3, 1, 2 };
inline constexpr array<int16_t, 8>                kSeabedSampleValues = { 100, 110, 105, 120, 95, 90, 80, 70 };

MRZPingInfo make_ping_info()
{
    MRZPingInfo info;
    info.set_bytes_content(sizeof(MRZPingInfo));
    info.set_ping_rate_hz(1.25F);
    info.set_beam_spacing(1);
    info.set_depth_mode(2);
    info.set_sub_depth_mode(3);
    info.set_detection_mode(4);
    info.set_pulse_form(5);
    info.set_fixed_gain_control(6);
    info.set_frequency_mode_hz(30000.0F);
    info.set_frequency_range_low_Limit_hz(28000.0F);
    info.set_frequency_range_high_Limit_hz(32000.0F);
    info.set_max_total_tx_pulse_length_sec(0.02F);
    info.set_max_eff_tx_pulse_length_sec(0.015F);
    info.set_max_eff_tx_band_width_hz(500.0F);
    info.set_abs_coeff_db_per_km(0.3F);
    info.set_port_sector_edge_deg(-65.0F);
    info.set_starboard_sector_edge_deg(65.0F);
    info.set_port_mean_coverage_deg(35.0F);
    info.set_starboard_mean_coverage_deg(35.0F);
    info.set_port_mean_coverage_m(120);
    info.set_starboard_mean_coverage_m(125);
    info.set_mode_and_stabilisation(7);
    info.set_runtime_filter_1(8);
    info.set_runtime_filter_2(9);
    info.set_pipe_tracking_status(10);
    info.set_tx_array_size_used_deg(1.5F);
    info.set_rx_array_size_used_deg(1.4F);
    info.set_tx_power_db(210.0F);
    info.set_sl_ramp_up_time_remaining(11);
    info.set_yaw_angle_deg(0.5F);
    info.set_number_of_tx_sectors(kNumSectors);
    info.set_number_of_bytes_per_tx_Sector(static_cast<uint16_t>(sizeof(MRZSectorInfo)));
    info.set_heading_vessel_deg(123.0F);
    info.set_sound_speed_at_tx_depth_m_per_sec(1490.5F);
    info.set_tx_transducer_depth_m(3.75F);
    info.set_z_water_level_re_ref_point_m(1.2F);
    info.set_x_kmall_to_all_m(0.4F);
    info.set_y_kmall_to_all_m(-0.35F);
    info.set_lat_long_info(1);
    info.set_position_sensor_status(2);
    info.set_attitude_sensor_status(3);
    info.set_latitude_deg(63.123456);
    info.set_longitude_deg(8.654321);
    info.set_ellipsoid_height_re_ref_point_m(4.2F);
    info.set_bs_correction_offset_db(-1.25F);
    info.set_lamberts_law_applied(1);
    info.set_ice_window(0);
    info.set_active_modes(0x1234);
    return info;
}

vector<MRZSectorInfo> make_tx_sectors()
{
    vector<MRZSectorInfo> sectors;
    sectors.reserve(kNumSectors);
    for (uint8_t idx = 0; idx < kNumSectors; ++idx)
    {
        MRZSectorInfo sector;
        sector.set_tx_sector_number(idx);
        sector.set_tx_arrary_number(idx + 1);
        sector.set_tx_sub_array(idx % 2);
        sector.set_sector_transmit_delay_sec(0.001F * (idx + 1));
        sector.set_tilt_angle_re_tx_deg(-25.0F + 5.0F * idx);
        sector.set_tx_nominal_source_level_db(200.0F + idx);
        sector.set_tx_focus_range_m(50.0F + 2.0F * idx);
        sector.set_centre_frequency_hz(30000.0F + 500.0F * idx);
        sector.set_signal_band_width_hz(400.0F + 20.0F * idx);
        sector.set_total_signal_length_sec(0.01F + 0.001F * idx);
        sector.set_pulse_shading(2 + idx);
        sector.set_signal_wave_form(3 + idx);
        sector.set_high_voltage_level_db(3.0F + idx);
        sector.set_sector_tracking_corr_db(0.1F * (idx + 1));
        sector.set_effective_signal_length_sec(0.009F + 0.0005F * idx);
        sectors.push_back(sector);
    }
    return sectors;
}

MRZRxInfo make_rx_info()
{
    MRZRxInfo info;
    info.set_bytes_content(sizeof(MRZRxInfo));
    info.set_number_of_soundings_max_main(kNumMainSoundings);
    info.set_number_of_soundings_valid_main(kNumMainSoundings);
    info.set_number_of_bytes_per_sounding(static_cast<uint16_t>(sizeof(MRZSoundings)));
    info.set_wc_sample_rate(7000.0F);
    info.set_seabed_image_sample_rate(2000.0F);
    info.set_bs_normal_db(-2.5F);
    info.set_bs_oblique_db(-5.0F);
    info.set_extra_detection_alarm_flag(0x55AA);
    info.set_number_of_extra_detections(kNumExtraSoundings);
    info.set_number_of_extra_detection_classes(kNumExtraClasses);
    info.set_number_of_bytes_per_class(static_cast<uint16_t>(sizeof(MRZExtraDetClassInfo)));
    return info;
}

vector<MRZExtraDetClassInfo> make_extra_classes()
{
    vector<MRZExtraDetClassInfo> extras;
    extras.reserve(kNumExtraClasses);
    for (uint16_t i = 0; i < kNumExtraClasses; ++i)
    {
        MRZExtraDetClassInfo cls;
        cls.set_num_extra_det_in_class(static_cast<uint16_t>(5 + i));
        cls.set_padding(static_cast<int8_t>(i));
        cls.set_alarm_flag(static_cast<uint8_t>(1 + i));
        extras.push_back(cls);
    }
    return extras;
}

vector<MRZSoundings> make_soundings()
{
    vector<MRZSoundings> soundings;
    soundings.reserve(kTotalSoundings);
    for (size_t i = 0; i < kTotalSoundings; ++i)
    {
        MRZSoundings sounding;
        sounding.set_sounding_index(static_cast<uint16_t>(100 + i));
        sounding.set_tx_sector_number(static_cast<uint8_t>(i % kNumSectors));
        sounding.set_detection_type(static_cast<uint8_t>(10 + i));
        sounding.set_detection_method(static_cast<uint8_t>(20 + i));
        sounding.set_rejection_info_1(static_cast<uint8_t>(30 + i));
        sounding.set_rejection_info_2(static_cast<uint8_t>(40 + i));
        sounding.set_post_processing_info(static_cast<uint8_t>(50 + i));
        sounding.set_detection_class(static_cast<uint8_t>(60 + i));
        sounding.set_detection_confidence_level(static_cast<uint8_t>(70 + i));
        sounding.set_padding(static_cast<uint16_t>(i));

        const float base = 0.5F + 0.25F * static_cast<float>(i);
        sounding.set_range_factor(base);
        sounding.set_quality_factor(base + 0.1F);
        sounding.set_detection_uncertainty_ver_m(0.01F * (i + 1));
        sounding.set_detection_uncertainty_hor_m(0.02F * (i + 1));
        sounding.set_detection_window_length_sec(0.003F * (i + 1));
        sounding.set_echo_length_sec(0.004F * (i + 1));
        sounding.set_wc_beam_number(static_cast<uint16_t>(200 + i));
        sounding.set_wc_range_samples(static_cast<uint16_t>(300 + 2 * i));
        sounding.set_wc_nom_beam_angle_across_deg(-30.0F + 2.5F * static_cast<float>(i));

        sounding.set_mean_abs_coeff_db_per_km(0.3F + 0.05F * static_cast<float>(i));
        sounding.set_reflectivity_1_db(-10.0F + static_cast<float>(i));
        sounding.set_reflectivity_2_db(-8.0F + static_cast<float>(i));
        sounding.set_receiver_sensitivity_applied_db(-30.0F + static_cast<float>(i));
        sounding.set_source_level_applied_db(210.0F + static_cast<float>(i));
        sounding.set_bs_calibration_db(-1.0F + 0.1F * static_cast<float>(i));
        sounding.set_tvg_db(10.0F + 0.2F * static_cast<float>(i));
        sounding.set_beam_angle_re_rx_deg(-40.0F + 3.0F * static_cast<float>(i));
        sounding.set_beam_angle_correction_deg(1.0F + 0.5F * static_cast<float>(i));
        sounding.set_two_way_travel_time_sec(0.05F + 0.01F * static_cast<float>(i));
        sounding.set_two_way_travel_time_correction_sec(0.001F * static_cast<float>(i));

        sounding.set_delta_latitude_deg(0.0001F * static_cast<float>(i + 1));
        sounding.set_delta_longitude_deg(-0.0001F * static_cast<float>(i + 1));
        sounding.set_z_re_ref_point_m(-1.0F * static_cast<float>(i));
        sounding.set_y_re_ref_point_m(0.5F * static_cast<float>(i));
        sounding.set_x_re_ref_point_m(1.5F * static_cast<float>(i));
        sounding.set_beam_inc_angle_adj_deg(2.0F + static_cast<float>(i));

        sounding.set_real_time_clean_info(static_cast<uint16_t>(i * 10));
        sounding.set_si_start_range_samples(static_cast<uint16_t>(100 + i));
        sounding.set_si_centre_sample(static_cast<uint16_t>(110 + i));
        sounding.set_si_num_samples(kSeabedSampleCounts[i]);

        soundings.push_back(sounding);
    }
    return soundings;
}

xt::xtensor<int16_t, 1> make_seabed_samples()
{
    auto tensor = xt::xtensor<int16_t, 1>::from_shape({ kSeabedSampleValues.size() });
    for (size_t i = 0; i < kSeabedSampleValues.size(); ++i)
    {
        tensor(i) = kSeabedSampleValues[i];
    }
    return tensor;
}

uint32_t compute_total_datagram_size(size_t num_sectors,
                                     size_t num_classes,
                                     size_t num_soundings,
                                     size_t num_seabed_samples)
{
    const auto ping_bytes      = sizeof(MRZPingInfo);
    const auto sector_bytes    = num_sectors * sizeof(MRZSectorInfo);
    const auto rx_bytes        = sizeof(MRZRxInfo);
    const auto class_bytes     = num_classes * sizeof(MRZExtraDetClassInfo);
    const auto sounding_bytes  = num_soundings * sizeof(MRZSoundings);
    const auto seabed_bytes    = num_seabed_samples * sizeof(int16_t);
    const auto trailer_bytes   = sizeof(uint32_t);
    const auto body_bytes      = KMALLMultibeamDatagram::__size + ping_bytes + sector_bytes +
                                 rx_bytes + class_bytes + sounding_bytes + seabed_bytes +
                                 trailer_bytes;
    return static_cast<uint32_t>(KMALLDatagram::__size + body_bytes);
}

MRangeAndDepth make_datagram()
{
    MRangeAndDepth dat;
    dat.set_datagram_version(3);
    dat.set_system_id(42);
    dat.set_echo_sounder_id(2040);
    dat.set_time_sec(1670001000);
    dat.set_time_nanosec(987654321);

    dat.set_number_of_datagrams(1);
    dat.set_datagram_number(1);
    dat.set_ping_count(12);
    dat.set_rx_fans_per_ping(1);
    dat.set_rx_fan_index(0);
    dat.set_swaths_per_ping(1);
    dat.set_swath_along_position(0);
    dat.set_tx_transducer_ind(0);
    dat.set_rx_transducer_ind(0);
    dat.set_number_of_rx_transducers(1);
    dat.set_algorithm_type(2);

    auto ping_info      = make_ping_info();
    auto sectors        = make_tx_sectors();
    auto rx_info        = make_rx_info();
    auto extra_classes  = make_extra_classes();
    auto soundings      = make_soundings();
    auto seabed_samples = make_seabed_samples();

    dat.set_ping_info(ping_info);
    dat.set_tx_sectors(sectors);
    dat.set_rx_info(rx_info);
    dat.set_extra_det_class_info(extra_classes);

    MRZSoundingsContainer container;
    container.set_soundings(soundings);
    dat.set_soundings(container);
    dat.set_seabed_image_samples_dezi_db(seabed_samples);

    const auto total_size = compute_total_datagram_size(
        sectors.size(), extra_classes.size(), soundings.size(), seabed_samples.size());
    dat.set_bytes_datagram(total_size);

    return dat;
}

} // namespace

TEST_CASE("MRangeAndDepth should serialize and deserialize without loss", TESTTAG)
{
    const auto dat = make_datagram();

    const auto expected_hash = dat.binary_hash();
    REQUIRE(expected_hash != 0);
    CHECK(dat.binary_hash() == expected_hash);

    {
        auto copy = MRangeAndDepth(dat);
        CHECK(copy == dat);
    }

    {
        auto from_binary = MRangeAndDepth(dat.from_binary(dat.to_binary()));
        CHECK(from_binary == dat);
    }

    {
        stringstream buffer;
        dat.to_stream(buffer);
        auto from_stream = MRangeAndDepth(MRangeAndDepth::from_stream(buffer));
        CHECK(from_stream == dat);
    }

    CHECK(dat.get_tx_sectors().size() == kNumSectors);
    CHECK(dat.get_soundings().get_soundings().size() == kTotalSoundings);
    CHECK(dat.get_extra_det_class_info().size() == kNumExtraClasses);

    const auto seabed_dezi = dat.get_seabed_image_samples_dezi_db();
    const auto seabed_db   = dat.get_seabed_image_samples_db();
    REQUIRE(seabed_db.size() == seabed_dezi.size());
    REQUIRE(seabed_db.size() == kSeabedSampleValues.size());
    CHECK(seabed_dezi.size() == dat.get_soundings().get_number_of_seabed_image_samples());

    for (size_t i = 0; i < seabed_db.size(); ++i)
    {
        CHECK(seabed_db[i] == Catch::Approx(static_cast<float>(seabed_dezi[i]) * 0.1F));
    }

    const auto& rx_info = dat.get_rx_info();
    CHECK(rx_info.get_number_of_soundings_max_main() == kNumMainSoundings);
    CHECK(rx_info.get_number_of_extra_detections() == kNumExtraSoundings);
    CHECK(rx_info.get_number_of_extra_detection_classes() == kNumExtraClasses);

    const auto& ping_info = dat.get_ping_info();
    CHECK(ping_info.get_number_of_tx_sectors() == kNumSectors);
    CHECK(ping_info.get_latitude_deg() == Catch::Approx(63.123456));
    CHECK(ping_info.get_longitude_deg() == Catch::Approx(8.654321));

    const auto& container = dat.get_soundings();
    CHECK(container.get_number_of_soundings() == kTotalSoundings);
    CHECK(container.get_number_of_seabed_image_samples() == seabed_dezi.size());

    const auto seabed_index_tensor = container.get_seabed_image_sounding_index_tensor();
    REQUIRE(seabed_index_tensor.size() == seabed_dezi.size());

    size_t offset = 0;
    for (size_t sounding_idx = 0; sounding_idx < kTotalSoundings; ++sounding_idx)
    {
        for (uint16_t sample = 0; sample < kSeabedSampleCounts[sounding_idx]; ++sample)
        {
            CHECK(seabed_index_tensor(offset + sample) == sounding_idx);
        }
        offset += kSeabedSampleCounts[sounding_idx];
    }
}

TEST_CASE("MRangeAndDepth exposes soundings metadata", TESTTAG)
{
    const auto dat     = make_datagram();
    const auto& sounds = dat.get_soundings().get_soundings();
    REQUIRE(sounds.size() == kTotalSoundings);

    for (size_t idx = 0; idx < sounds.size(); ++idx)
    {
        const auto& sounding = sounds[idx];
        CHECK(sounding.get_sounding_index() == static_cast<uint16_t>(100 + idx));
        CHECK(sounding.get_tx_sector_number() == static_cast<uint8_t>(idx % kNumSectors));
        CHECK(sounding.get_si_num_samples() == kSeabedSampleCounts[idx]);
        CHECK(sounding.get_wc_beam_number() == static_cast<uint16_t>(200 + idx));
    }
}