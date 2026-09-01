// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <cstring>
#include <sstream>
#include <string>

#include "../themachinethatgoesping/echosounders/s7k/datagrams/s7kdatagram.hpp"

using namespace std;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::s7k::datagrams;
#define TESTTAG "[s7k]"

namespace {
// build a raw 64-byte Data Record Frame (little-endian) with the given field values
std::string make_drf(uint32_t record_type,
                     uint32_t size,
                     uint16_t year,
                     uint16_t day,
                     float    seconds,
                     uint8_t  hours,
                     uint8_t  minutes,
                     uint32_t device_id)
{
    std::string buf(S7KDatagram::__size, '\0');
    auto        put16 = [&](size_t off, uint16_t v) { std::memcpy(&buf[off], &v, sizeof(v)); };
    auto        put32 = [&](size_t off, uint32_t v) { std::memcpy(&buf[off], &v, sizeof(v)); };
    auto        putf  = [&](size_t off, float v) { std::memcpy(&buf[off], &v, sizeof(v)); };

    put16(0, 5);                  // protocol version
    put16(2, 60);                 // offset (sync pattern -> RTH)
    put32(4, 0x0000FFFF);         // sync pattern
    put32(8, size);               // size
    put32(12, 0);                 // optional data offset
    put32(16, 0);                 // optional data identifier
    put16(20, year);              // 7KTIME year
    put16(22, day);               // 7KTIME day of year
    putf(24, seconds);            // 7KTIME seconds
    buf[28] = char(hours);        // 7KTIME hours
    buf[29] = char(minutes);      // 7KTIME minutes
    put16(30, 1);                 // record version
    put32(32, record_type);       // record type identifier
    put32(36, device_id);         // device identifier
    return buf;
}
}

TEST_CASE("S7KDatagram should parse the Data Record Frame byte layout", TESTTAG)
{
    // 2023-05-23 15:28:44 UTC (day of year 143), record 7027 (raw detection), size 200 bytes
    const std::string raw = make_drf(7027, 200, 2023, 143, 44.0f, 15, 28, 7000);

    std::stringstream is(raw, std::ios::binary | std::ios::in | std::ios::out);
    auto              dat = S7KDatagram::from_stream(is);

    // --- header fields ---
    REQUIRE(dat.get_protocol_version() == 5);
    REQUIRE(dat.get_offset() == 60);
    REQUIRE(dat.get_sync_pattern() == 0x0000FFFF);
    REQUIRE(dat.is_valid());
    REQUIRE(dat.get_size() == 200);
    REQUIRE(dat.get_year() == 2023);
    REQUIRE(dat.get_day() == 143);
    REQUIRE(dat.get_seconds() == Catch::Approx(44.0f));
    REQUIRE(dat.get_hours() == 15);
    REQUIRE(dat.get_minutes() == 28);
    REQUIRE(dat.get_record_version() == 1);
    REQUIRE(dat.get_record_type_identifier() == 7027);
    REQUIRE(dat.get_datagram_identifier() == t_S7KDatagramIdentifier::R7027_RawDetectionData);
    REQUIRE(dat.get_device_identifier() == 7000);

    // --- derived values ---
    REQUIRE(dat.compute_size_content() == 200 - S7KDatagram::__size);

    // --- timestamp: day of year 143 in 2023 is 23 May ---
    REQUIRE(std::isfinite(dat.get_timestamp()));
    REQUIRE(dat.get_date_string(0, "%d/%m/%Y %H:%M:%S") == "23/05/2023 15:28:44");
}

TEST_CASE("S7KDatagram should support common functions", TESTTAG)
{
    const std::string raw = make_drf(7000, 128, 2023, 143, 44.5f, 15, 28, 7000);
    std::stringstream is(raw, std::ios::binary | std::ios::in | std::ios::out);
    auto              dat = S7KDatagram::from_stream(is);

    // test copy
    REQUIRE(dat == S7KDatagram(dat));

    // test binary round trip
    REQUIRE(dat == S7KDatagram(dat.from_binary(dat.to_binary())));

    // test stream round trip
    std::stringstream buffer;
    dat.to_stream(buffer);
    REQUIRE(dat == S7KDatagram(dat.from_stream(buffer)));

    // test print does not crash
    REQUIRE(dat.info_string().size() != 0);
}
