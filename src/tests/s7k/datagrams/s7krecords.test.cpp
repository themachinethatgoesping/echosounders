// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <xtensor/containers/xtensor.hpp>

#include "../themachinethatgoesping/echosounders/s7k/datagrams/attitude.hpp"
#include "../themachinethatgoesping/echosounders/s7k/datagrams/beamgeometry.hpp"
#include "../themachinethatgoesping/echosounders/s7k/datagrams/compressedwatercolumn.hpp"
#include "../themachinethatgoesping/echosounders/s7k/datagrams/heading.hpp"
#include "../themachinethatgoesping/echosounders/s7k/datagrams/position.hpp"
#include "../themachinethatgoesping/echosounders/s7k/datagrams/rawdetection.hpp"
#include "../themachinethatgoesping/echosounders/s7k/datagrams/snippetdata.hpp"
#include "../themachinethatgoesping/echosounders/s7k/datagrams/sonarsettings.hpp"

using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::s7k::datagrams;
#define TESTTAG "[s7k]"

TEST_CASE("SonarSettings should support common functions and round trips", TESTTAG)
{
    auto dat = SonarSettings();
    dat.set_ping_number(32343);
    dat.set_frequency(400000.f);
    dat.set_sample_rate(78125.f);
    dat.set_sound_velocity(1501.6f);
    dat.set_serial_number(185);

    // record type identifier is set by the default constructor
    REQUIRE(dat.get_datagram_identifier() == t_S7KDatagramIdentifier::SonarSettings);

    // field access
    REQUIRE(dat.get_ping_number() == 32343);
    REQUIRE(dat.get_frequency() == Catch::Approx(400000.f));

    // copy
    REQUIRE(dat == SonarSettings(dat));
    // binary round trip
    REQUIRE(dat == SonarSettings(dat.from_binary(dat.to_binary())));
    // stream round trip
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == SonarSettings(dat.from_stream(buffer)));

    // print does not crash
    REQUIRE(dat.info_string().size() != 0);
}

TEST_CASE("Heading and Position should round trip", TESTTAG)
{
    auto hd = Heading();
    hd.set_heading(0.45f);
    REQUIRE(hd.get_heading() == Catch::Approx(0.45f));
    REQUIRE(hd == Heading(hd.from_binary(hd.to_binary())));

    auto pos = Position();
    pos.set_latitude_northing(0.894);
    pos.set_longitude_easting(0.051);
    pos.set_height(45.7);
    REQUIRE(pos.get_latitude_northing() == Catch::Approx(0.894));
    REQUIRE(pos == Position(pos.from_binary(pos.to_binary())));
    REQUIRE(pos.info_string().size() != 0);
}

TEST_CASE("RawDetection should round trip via the beam container", TESTTAG)
{
    RawDetection dat;
    dat.set_ping_number(42);
    dat.set_number_beams(2);
    dat.set_data_field_size(34); // full record (all fields present -> no NaN)
    dat.set_sampling_rate(78125.f);

    auto& beams = dat.beams().beams();
    beams.resize(2);
    for (uint16_t i = 0; i < 2; ++i)
    {
        beams[i].set_beam_descriptor(i);
        beams[i].set_detection_point(100.f + i);
        beams[i].set_rx_angle(0.1f * i);
        beams[i].set_flags(i);
        beams[i].set_quality(3);
        beams[i].set_uncertainty(0.01f);
        beams[i].set_signal_strength(10.f + i);
        beams[i].set_min_limit(1.f);
        beams[i].set_max_limit(200.f);
    }

    REQUIRE(dat.beams().get_number_of_beams() == 2);
    REQUIRE(dat.beams().get_detection_point_tensor()(1) == Catch::Approx(101.f));

    // binary round trip
    REQUIRE(dat == RawDetection(dat.from_binary(dat.to_binary())));
    // stream round trip
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == RawDetection(dat.from_stream(buffer)));
    REQUIRE(dat.info_string().size() != 0);
}

TEST_CASE("Attitude should round trip via the sample container", TESTTAG)
{
    Attitude dat;
    auto&    samples = dat.samples().samples();
    samples.resize(3);
    for (uint16_t i = 0; i < 3; ++i)
    {
        samples[i].set_delta_time(i * 10);
        samples[i].set_roll(0.1f * i);
        samples[i].set_pitch(0.2f * i);
        samples[i].set_heave(0.3f * i);
        samples[i].set_heading(0.4f * i);
    }

    REQUIRE(dat.get_number_of_samples() == 3);
    REQUIRE(dat.samples().get_roll_tensor()(2) == Catch::Approx(0.2f));

    REQUIRE(dat == Attitude(dat.from_binary(dat.to_binary())));
    REQUIRE(dat.info_string().size() != 0);
}

TEST_CASE("BeamGeometry should round trip via the beam container", TESTTAG)
{
    BeamGeometry dat;
    dat.set_serial_number(185);
    dat.set_number_beams(3);

    xt::xtensor<float, 1> a = { 0.1f, 0.2f, 0.3f };
    dat.set_beam_vertical_angle(a);
    dat.set_beam_horizontal_angle(a);
    dat.set_beamwidth_vertical(a);
    dat.set_beamwidth_horizontal(a);
    dat.set_has_tx_delay(false);

    // _size must be consistent (used to detect the optional tx_delay array)
    dat.set_size(64 + 12 + 4 * 3 * sizeof(float));

    REQUIRE(dat.get_number_beams() == 3);
    REQUIRE(dat.get_beam_vertical_angle()(1) == Catch::Approx(0.2f));

    REQUIRE(dat == BeamGeometry(dat.from_binary(dat.to_binary())));
    REQUIRE(dat.info_string().size() != 0);
}

TEST_CASE("SnippetData should round trip via the beam + amplitude containers", TESTTAG)
{
    SnippetData dat;
    dat.set_ping_number(7);
    dat.set_number_beams(2);
    dat.set_flags(0); // bit 0 = 0 -> 16-bit samples

    auto& beams = dat.beams().beams();
    beams.resize(2);
    beams[0].set_beam_descriptor(0);
    beams[0].set_snippet_start(0);
    beams[0].set_detection_sample(1);
    beams[0].set_snippet_end(2); // 3 samples
    beams[1].set_beam_descriptor(1);
    beams[1].set_snippet_start(5);
    beams[1].set_detection_sample(7);
    beams[1].set_snippet_end(9); // 5 samples

    xt::xtensor<uint16_t, 1> flat    = { 10, 20, 30, 40, 50, 60, 70, 80 };
    xt::xtensor<uint64_t, 1> offsets = { 0, 3, 8 };
    dat.amplitudes().set_beam_offsets(offsets);
    dat.amplitudes().set_samples(flat);

    REQUIRE(dat.beams().get_number_of_samples_tensor()(1) == 5);
    REQUIRE(dat.amplitudes().get_number_of_beams() == 2);
    REQUIRE(dat.amplitudes().get_beam(1)(0) == Catch::Approx(40.f));

    REQUIRE(dat == SnippetData(dat.from_binary(dat.to_binary())));
    REQUIRE(dat.info_string().size() != 0);
}

TEST_CASE("CompressedWaterColumn should decode and round trip", TESTTAG)
{
    // one beam, 16-bit magnitude, no phase
    std::string raw;
    auto        put16 = [&raw](uint16_t v) {
        raw.push_back(char(v & 0xFF));
        raw.push_back(char((v >> 8) & 0xFF));
    };
    put16(100);
    put16(200);
    put16(300);
    put16(400);

    CompressedWaterColumn dat;
    dat.set_ping_number(11);
    dat.set_number_beams(1);
    dat.set_flags(CompressedWaterColumn::FLAG_MAGNITUDE_ONLY); // no phase, 16-bit magnitude
    dat.set_size(64 + 44 + 2 + 4 + 4 * 2);                     // DRF + content + (beam_number + count + samples)

    // record-wide sample encoding lives on the container
    dat.beams().set_magnitude_bytes(2);
    dat.beams().set_has_phase(false);

    auto& beams = dat.beams().beams();
    beams.resize(1);
    auto& b = beams[0];
    b.set_beam_number(7);
    b.set_sample_count(4);
    b.set_raw_samples(raw);

    // decode on demand (via the container, which knows the encoding)
    auto mag = dat.beams().get_magnitude(0);
    REQUIRE(mag.size() == 4);
    REQUIRE(mag(0) == Catch::Approx(100.f));
    REQUIRE(mag(3) == Catch::Approx(400.f));
    REQUIRE(dat.beams().get_phase(0).size() == 0);

    REQUIRE(dat.beams().get_total_number_of_samples() == 4);
    REQUIRE(dat.beams().get_magnitude(0)(2) == Catch::Approx(300.f));

    // binary round trip
    REQUIRE(dat == CompressedWaterColumn(dat.from_binary(dat.to_binary())));
    REQUIRE(dat.info_string().size() != 0);
}
