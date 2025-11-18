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

    auto timestamp = get_sensor_timestamp();
    if (std::isfinite(timestamp))
    {
        static const std::string format_date("%d/%m/%Y");
        static const std::string format_time("%H:%M:%S");
        using tools::timeconv::unixtime_to_datestring;
        auto date = unixtime_to_datestring(timestamp, 0, format_date);
        auto time = unixtime_to_datestring(timestamp, 3, format_time);

        printer.register_value("(p)sensor_timestamp", timestamp, "s");
        printer.register_string("(p)sensor_date", date, "MM/DD/YYYY");
        printer.register_string("(p)sensor_time", time, "HH:MM:SS");
    }

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

    auto timestamp = get_sensor_timestamp();
    if (std::isfinite(timestamp))
    {
        static const std::string format_date("%d/%m/%Y");
        static const std::string format_time("%H:%M:%S");
        using tools::timeconv::unixtime_to_datestring;
        auto date = unixtime_to_datestring(timestamp, 0, format_date);
        auto time = unixtime_to_datestring(timestamp, 3, format_time);

        printer.register_value("(p)sensor_timestamp", timestamp, "s");
        printer.register_string("(p)sensor_date", date, "MM/DD/YYYY");
        printer.register_string("(p)sensor_time", time, "HH:MM:SS");
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