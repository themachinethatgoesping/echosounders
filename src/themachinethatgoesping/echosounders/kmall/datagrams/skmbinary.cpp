// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "skmbinary.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/algorithms/amplitudecorrection/functions/absorption.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

// substructures - KMBinary
std::bitset<32> SKMBinary::KMBinary::get_status_bits() const
{
    return std::bitset<32>(status);
}
void SKMBinary::KMBinary::set_status_bits(std::bitset<32> bits)
{
    status = static_cast<uint32_t>(bits.to_ulong());
}

// Valid functions: status bits 0-6
bool SKMBinary::KMBinary::get_horizontal_position_and_velocity_valid() const
{
    return !get_status_bits().test(0);
}
bool SKMBinary::KMBinary::get_roll_and_pitch_valid() const
{
    return !get_status_bits().test(1);
}
bool SKMBinary::KMBinary::get_heading_valid() const
{
    return !get_status_bits().test(2);
}
bool SKMBinary::KMBinary::get_heave_valid() const
{
    return !get_status_bits().test(3);
}
bool SKMBinary::KMBinary::get_acceleration_valid() const
{
    return !get_status_bits().test(4);
}
bool SKMBinary::KMBinary::get_delayed_heave1_valid() const
{
    return !get_status_bits().test(5);
}
bool SKMBinary::KMBinary::get_delayed_heave2_valid() const
{
    return !get_status_bits().test(6);
}

// Reduced performance functions: status bits 16-22
bool SKMBinary::KMBinary::get_horizontal_position_and_velocity_reduced_performance() const
{
    return get_status_bits().test(16);
}
bool SKMBinary::KMBinary::get_roll_and_pitch_reduced_performance() const
{
    return get_status_bits().test(17);
}
bool SKMBinary::KMBinary::get_heading_reduced_performance() const
{
    return get_status_bits().test(18);
}
bool SKMBinary::KMBinary::get_heave_reduced_performance() const
{
    return get_status_bits().test(19);
}
bool SKMBinary::KMBinary::get_acceleration_reduced_performance() const
{
    return get_status_bits().test(20);
}
bool SKMBinary::KMBinary::get_delayed_heave1_reduced_performance() const
{
    return get_status_bits().test(21);
}
bool SKMBinary::KMBinary::get_delayed_heave2_reduced_performance() const
{
    return get_status_bits().test(22);
}

// Set valid bits
void SKMBinary::KMBinary::set_horizontal_position_and_velocity_valid(bool valid)
{
    auto bits = get_status_bits();
    bits.set(0, !valid);
    set_status_bits(bits);
}
void SKMBinary::KMBinary::set_roll_and_pitch_valid(bool valid)
{
    auto bits = get_status_bits();
    bits.set(1, !valid);
    set_status_bits(bits);
}
void SKMBinary::KMBinary::set_heading_valid(bool valid)
{
    auto bits = get_status_bits();
    bits.set(2, !valid);
    set_status_bits(bits);
}
void SKMBinary::KMBinary::set_heave_valid(bool valid)
{
    auto bits = get_status_bits();
    bits.set(3, !valid);
    set_status_bits(bits);
}
void SKMBinary::KMBinary::set_acceleration_valid(bool valid)
{
    auto bits = get_status_bits();
    bits.set(4, !valid);
    set_status_bits(bits);
}
void SKMBinary::KMBinary::set_delayed_heave1_valid(bool valid)
{
    auto bits = get_status_bits();
    bits.set(5, !valid);
    set_status_bits(bits);
}
void SKMBinary::KMBinary::set_delayed_heave2_valid(bool valid)
{
    auto bits = get_status_bits();
    bits.set(6, !valid);
    set_status_bits(bits);
}

// Set reduced performance bits
void SKMBinary::KMBinary::set_horizontal_position_and_velocity_reduced_performance(
    bool reduced_performance)
{
    auto bits = get_status_bits();
    bits.set(16, reduced_performance);
    set_status_bits(bits);
}
void SKMBinary::KMBinary::set_roll_and_pitch_reduced_performance(bool reduced_performance)
{
    auto bits = get_status_bits();
    bits.set(17, reduced_performance);
    set_status_bits(bits);
}
void SKMBinary::KMBinary::set_heading_reduced_performance(bool reduced_performance)
{
    auto bits = get_status_bits();
    bits.set(18, reduced_performance);
    set_status_bits(bits);
}
void SKMBinary::KMBinary::set_heave_reduced_performance(bool reduced_performance)
{
    auto bits = get_status_bits();
    bits.set(19, reduced_performance);
    set_status_bits(bits);
}
void SKMBinary::KMBinary::set_acceleration_reduced_performance(bool reduced_performance)
{
    auto bits = get_status_bits();
    bits.set(20, reduced_performance);
    set_status_bits(bits);
}
void SKMBinary::KMBinary::set_delayed_heave1_reduced_performance(bool reduced_performance)
{
    auto bits = get_status_bits();
    bits.set(21, reduced_performance);
    set_status_bits(bits);
}
void SKMBinary::KMBinary::set_delayed_heave2_reduced_performance(bool reduced_performance)
{
    auto bits = get_status_bits();
    bits.set(22, reduced_performance);
    set_status_bits(bits);
}

double SKMBinary::KMBinary::get_sensor_timestamp() const
{
    return time_sec + time_nanosec * 1e-9;
}

std::string SKMBinary::KMBinary::get_sensor_date_string(unsigned int       fractionalSecondsDigits,
                                                        const std::string& format) const
{
    return tools::timeconv::unixtime_to_datestring(
        get_sensor_timestamp(), fractionalSecondsDigits, format);
}

tools::classhelper::ObjectPrinter SKMBinary::KMBinary::__printer__(unsigned int float_precision,
                                                                   bool superscript_exponents) const
{
    auto printer =
        tools::classhelper::ObjectPrinter("KMBinary", float_precision, superscript_exponents);

    printer.register_value(
        "datagram_identifier", datagram_identifier.alt_name(), datagram_identifier.name());
    printer.register_value("bytes_content", bytes_content, "bytes");
    printer.register_value("dgm_version", dgm_version);
    printer.register_value("time_sec", time_sec, "s");
    printer.register_value("time_nanosec", time_nanosec, "ns");
    printer.register_value("status", fmt::format("0b{:08b}", status));

    printer.register_value("latitude_deg", latitude_deg, "°");
    printer.register_value("longitude_deg", longitude_deg, "°");
    printer.register_value("ellipsoid_height_m", ellipsoid_height_m, "m");

    printer.register_value("roll_deg", roll_deg, "°");
    printer.register_value("pitch_deg", pitch_deg, "°");
    printer.register_value("heading_deg", heading_deg, "°");
    printer.register_value("heave_m", heave_m, "m");

    printer.register_value("roll_rate", roll_rate, "°/s");
    printer.register_value("pitch_rate", pitch_rate, "°/s");
    printer.register_value("yaw_rate", yaw_rate, "°/s");

    printer.register_value("vel_north", vel_north, "m/s");
    printer.register_value("vel_east", vel_east, "m/s");
    printer.register_value("vel_down", vel_down, "m/s");

    printer.register_value("latitude_error_m", latitude_error_m, "m");
    printer.register_value("longitude_error_m", longitude_error_m, "m");
    printer.register_value("ellipsoid_height_error_m", ellipsoid_height_error_m, "m");
    printer.register_value("roll_error_deg", roll_error_deg, "°");
    printer.register_value("pitch_error_deg", pitch_error_deg, "°");
    printer.register_value("heading_error_deg", heading_error_deg, "°");
    printer.register_value("heave_error_m", heave_error_m, "m");

    printer.register_value("north_acceleration", north_acceleration, "m/s²");
    printer.register_value("east_acceleration", east_acceleration, "m/s²");
    printer.register_value("down_acceleration", down_acceleration, "m/s²");

    printer.register_section("processed");

    auto timestamp = get_sensor_timestamp();
    if (std::isfinite(timestamp))
    {
        static const std::string format_date("%d/%m/%Y");
        static const std::string format_time("%H:%M:%S");
        using tools::timeconv::unixtime_to_datestring;
        auto date = unixtime_to_datestring(timestamp, 0, format_date);
        auto time = unixtime_to_datestring(timestamp, 3, format_time);

        printer.register_value("sensor_timestamp", timestamp, "s");
        printer.register_string("sensor_date", date, "MM/DD/YYYY");
        printer.register_string("sensor_time", time, "HH:MM:SS");
    }

    printer.register_value("horizontal_position_and_velocity_valid",
                           get_horizontal_position_and_velocity_valid());
    printer.register_value("roll_and_pitch_valid", get_roll_and_pitch_valid());
    printer.register_value("heading_valid", get_heading_valid());
    printer.register_value("heave_valid", get_heave_valid());
    printer.register_value("acceleration_valid", get_acceleration_valid());
    printer.register_value("delayed_heave1_valid", get_delayed_heave1_valid());
    printer.register_value("delayed_heave2_valid", get_delayed_heave2_valid());

    printer.register_value("horizontal_position_and_velocity_reduced_performance",
                           get_horizontal_position_and_velocity_reduced_performance());
    printer.register_value("roll_and_pitch_reduced_performance",
                           get_roll_and_pitch_reduced_performance());
    printer.register_value("heading_reduced_performance", get_heading_reduced_performance());
    printer.register_value("heave_reduced_performance", get_heave_reduced_performance());
    printer.register_value("acceleration_reduced_performance",
                           get_acceleration_reduced_performance());
    printer.register_value("delayed_heave1_reduced_performance",
                           get_delayed_heave1_reduced_performance());
    printer.register_value("delayed_heave2_reduced_performance",
                           get_delayed_heave2_reduced_performance());

    return printer;
}

// substructures - KMDelayedHeave
double SKMBinary::KMDelayedHeave::get_sensor_timestamp() const
{
    return time_sec + time_nanosec * 1e-9;
}

std::string SKMBinary::KMDelayedHeave::get_sensor_date_string(unsigned int fractionalSecondsDigits,
                                                              const std::string& format) const
{
    return tools::timeconv::unixtime_to_datestring(
        get_sensor_timestamp(), fractionalSecondsDigits, format);
}

tools::classhelper::ObjectPrinter SKMBinary::KMDelayedHeave::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    auto printer =
        tools::classhelper::ObjectPrinter("KMDelayedHeave", float_precision, superscript_exponents);

    printer.register_value("delayed_heave_m", delayed_heave_m, "m");
    printer.register_value("time_sec", time_sec, "s");
    printer.register_value("time_nanosec", time_nanosec, "ns");

    printer.register_section("processed");
    auto timestamp = get_sensor_timestamp();
    if (std::isfinite(timestamp))
    {
        static const std::string format_date("%d/%m/%Y");
        static const std::string format_time("%H:%M:%S");
        using tools::timeconv::unixtime_to_datestring;
        auto date = unixtime_to_datestring(timestamp, 0, format_date);
        auto time = unixtime_to_datestring(timestamp, 3, format_time);

        printer.register_value("sensor_timestamp", timestamp, "s");
        printer.register_string("sensor_date", date, "MM/DD/YYYY");
        printer.register_string("sensor_time", time, "HH:MM:SS");
    }

    return printer;
}

// substructures - SKMSample
tools::classhelper::ObjectPrinter SKMBinary::SKMSample::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    auto printer =
        tools::classhelper::ObjectPrinter("SKMSample", float_precision, superscript_exponents);

    printer.register_section("KM Binary");
    printer.append(km_binary.__printer__(float_precision, superscript_exponents));

    printer.register_section("KM Delayed Heave");
    printer.append(km_delayed_heave.__printer__(float_precision, superscript_exponents));

    return printer;
}

SKMBinary::SKMBinary()
{
    _datagram_identifier = DatagramIdentifier;
}

void SKMBinary::set_sensor_data(const std::vector<SKMSample>& data)
{
    _sensor_data               = data;
    _content.number_of_samples = static_cast<uint16_t>(data.size());

    static constexpr size_t dbytes = __size + sizeof(uint32_t);
    _content.bytes_content         = dbytes + _sensor_data.size() * sizeof(SKMSample);
    set_bytes_datagram(KMALLDatagram::__size + _content.bytes_content);
    _bytes_datagram_check = get_bytes_datagram();
}

// ----- to/from stream functions -----
void SKMBinary::__read__(std::istream& is)
{
    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&_content), __size);

    // read position data string
    _sensor_data.resize(get_number_of_samples()); // minus size of the previous fields
    is.read(reinterpret_cast<char*>(_sensor_data.data()), _sensor_data.size() * sizeof(SKMSample));
    is.read(reinterpret_cast<char*>(&(_bytes_datagram_check)), sizeof(_bytes_datagram_check));
}

SKMBinary SKMBinary::from_stream(std::istream& is, const KMALLDatagram& header)
{
    SKMBinary datagram(header);
    datagram.__read__(is);

    return datagram;
}

SKMBinary SKMBinary::from_stream(std::istream& is, o_KMALLDatagramIdentifier datagram_identifier)
{
    SKMBinary datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__check_datagram_identifier__(datagram_identifier, DatagramIdentifier);
    datagram.__read__(is);
    return datagram;
}

SKMBinary SKMBinary::from_stream(std::istream& is)
{
    SKMBinary datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read__(is);
    return datagram;
}

void SKMBinary::to_stream(std::ostream& os)
{
    KMALLDatagram::to_stream(os);

    os.write(reinterpret_cast<char*>(&_content), __size);
    os.write(reinterpret_cast<const char*>(_sensor_data.data()),
             _sensor_data.size() * sizeof(SKMSample));
    os.write(reinterpret_cast<const char*>(&_bytes_datagram_check), sizeof(_bytes_datagram_check));
}

// ----- processed values -----
// Each corresponds to bytes 0-6 in sensor_data_contents

std::bitset<8> SKMBinary::get_sensor_data_contents_bits() const
{
    return std::bitset<8>(_content.sensor_data_contents);
}

bool SKMBinary::get_horizontal_position_and_velocity_active() const
{
    return get_sensor_data_contents_bits().test(0);
}
bool SKMBinary::get_roll_and_pitch_active() const
{
    return get_sensor_data_contents_bits().test(1);
}
bool SKMBinary::get_heading_active() const
{
    return get_sensor_data_contents_bits().test(2);
}
bool SKMBinary::get_heave_active() const
{
    return get_sensor_data_contents_bits().test(3);
}
bool SKMBinary::get_acceleration_active() const
{
    return get_sensor_data_contents_bits().test(4);
}
bool SKMBinary::get_delayed_heave1_active() const
{
    return get_sensor_data_contents_bits().test(5);
}
bool SKMBinary::get_delayed_heave2_active() const
{
    return get_sensor_data_contents_bits().test(6);
}

void SKMBinary::set_horizontal_position_and_velocity_active(bool active)
{
    std::bitset<8> bits(_content.sensor_data_contents);
    bits.set(0, active);
    _content.sensor_data_contents = static_cast<uint8_t>(bits.to_ulong());
}
void SKMBinary::set_roll_and_pitch_active(bool active)
{
    std::bitset<8> bits(_content.sensor_data_contents);
    bits.set(1, active);
    _content.sensor_data_contents = static_cast<uint8_t>(bits.to_ulong());
}
void SKMBinary::set_heading_active(bool active)
{
    std::bitset<8> bits(_content.sensor_data_contents);
    bits.set(2, active);
    _content.sensor_data_contents = static_cast<uint8_t>(bits.to_ulong());
}
void SKMBinary::set_heave_active(bool active)
{
    std::bitset<8> bits(_content.sensor_data_contents);
    bits.set(3, active);
    _content.sensor_data_contents = static_cast<uint8_t>(bits.to_ulong());
}
void SKMBinary::set_acceleration_active(bool active)
{
    std::bitset<8> bits(_content.sensor_data_contents);
    bits.set(4, active);
    _content.sensor_data_contents = static_cast<uint8_t>(bits.to_ulong());
}
void SKMBinary::set_delayed_heave1_active(bool active)
{
    std::bitset<8> bits(_content.sensor_data_contents);
    bits.set(5, active);
    _content.sensor_data_contents = static_cast<uint8_t>(bits.to_ulong());
}
void SKMBinary::set_delayed_heave2_active(bool active)
{
    std::bitset<8> bits(_content.sensor_data_contents);
    bits.set(6, active);
    _content.sensor_data_contents = static_cast<uint8_t>(bits.to_ulong());
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter SKMBinary::__printer__(unsigned int float_precision,
                                                         bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("SKMBinary", float_precision, superscript_exponents);

    printer.append(KMALLDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("bytes_content", _content.bytes_content);
    printer.register_value("sensor_system", _content.sensor_system);
    printer.register_value("sensor_status", _content.sensor_status);
    printer.register_string("sensor_format",
                            _content.sensor_format.name(),
                            fmt::format("{}", fmt::join(_content.sensor_format.names(), ", ")));
    printer.register_value("number_of_samples", _content.number_of_samples);
    printer.register_value("number_of_bytes_per_sample", _content.number_of_bytes_per_sample);
    printer.register_value("sensor_data_contents", _content.sensor_data_contents);
    printer.register_value("sensor_data",
                           fmt::format("vector<SKMSample> with {} entries", _sensor_data.size()));
    printer.register_value("bytes_datagram_check", _bytes_datagram_check, "bytes");

    // --- processed ---
    printer.register_section("processed");
    printer.register_value("horizontal_position_and_velocity_active",
                           get_horizontal_position_and_velocity_active());
    printer.register_value("roll_and_pitch_active", get_roll_and_pitch_active());
    printer.register_value("heading_active", get_heading_active());
    printer.register_value("heave_active", get_heave_active());
    printer.register_value("acceleration_active", get_acceleration_active());
    printer.register_value("delayed_heave1_active", get_delayed_heave1_active());
    printer.register_value("delayed_heave2_active", get_delayed_heave2_active());

    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping

template class themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::kmall::datagrams::SKMBinary::t_sensor_format,
    themachinethatgoesping::echosounders::kmall::datagrams::SKMBinary::t_sensor_format_values
        .size(),
    themachinethatgoesping::echosounders::kmall::datagrams::SKMBinary::t_sensor_format_values,
    themachinethatgoesping::echosounders::kmall::datagrams::SKMBinary::t_sensor_format_names,
    themachinethatgoesping::echosounders::kmall::datagrams::SKMBinary::t_sensor_format_alt_names>;