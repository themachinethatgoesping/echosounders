// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "spositionerror.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

SPositionError::SPositionError()
{
    _datagram_identifier = DatagramIdentifier;
}

// ----- setters -----
void SPositionError::set_pos_error_data_from_sensor(std::string_view pos_data)
{
    static constexpr size_t dbytes = __size + KMALLSensorDatagram::__size + sizeof(uint32_t);

    auto bytes_content = dbytes + pos_data.size() * sizeof(char); // size of the string in bytes

    _pos_error_data_from_sensor.assign(pos_data.begin(), pos_data.end());

    // increase _bytes_content to 4 byte alignment
    if (bytes_content % 4 != 0)
    {
        bytes_content += 4 - (bytes_content % 4);
    }

    _pos_error_data_from_sensor.resize(bytes_content - dbytes, '\0'); // pad with null characters
    set_bytes_datagram(KMALLDatagram::__size + bytes_content);
    _bytes_datagram_check = get_bytes_datagram();
}

// ----- processed data access -----
double SPositionError::get_sensor_timestamp() const
{
    return _content.time_from_sensor_sec + _content.time_from_sensor_nanosec * 1e-9;
}

std::string SPositionError::get_sensor_date_string(unsigned int       fractionalSecondsDigits,
                                              const std::string& format) const
{
    return tools::timeconv::unixtime_to_datestring(
        get_timestamp(), fractionalSecondsDigits, format);
}

// ----- to/from stream functions -----
void SPositionError::__read__(std::istream& is)
{
    static constexpr size_t dbytes = __size + KMALLSensorDatagram::__size + sizeof(uint32_t);

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&_content), __size);

    // read position data string
    _pos_error_data_from_sensor.resize(compute_size_content() -
                                 dbytes); // minus size of the previous fields
    is.read(_pos_error_data_from_sensor.data(), _pos_error_data_from_sensor.size());
    is.read(reinterpret_cast<char*>(&(_bytes_datagram_check)), sizeof(_bytes_datagram_check));
}

SPositionError SPositionError::from_stream(std::istream& is, const KMALLDatagram& header)
{
    SPositionError datagram(header);
    datagram.__read_sensordatagram__(is);
    datagram.__read__(is);

    return datagram;
}

SPositionError SPositionError::from_stream(std::istream& is, o_KMALLDatagramIdentifier datagram_identifier)
{
    SPositionError datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__check_datagram_identifier__(datagram_identifier, DatagramIdentifier);
    datagram.__read_sensordatagram__(is);
    datagram.__read__(is);
    return datagram;
}

SPositionError SPositionError::from_stream(std::istream& is)
{
    SPositionError datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read_sensordatagram__(is);
    datagram.__read__(is);
    return datagram;
}

void SPositionError::to_stream(std::ostream& os) const
{
    KMALLDatagram::to_stream(os);
    KMALLSensorDatagram::to_stream(os);

    os.write(reinterpret_cast<const char*>(&_content), __size);
    os.write(reinterpret_cast<const char*>(_pos_error_data_from_sensor.data()),
             _pos_error_data_from_sensor.size() * sizeof(char));
    os.write(reinterpret_cast<const char*>(&_bytes_datagram_check), sizeof(_bytes_datagram_check));
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter SPositionError::__printer__(unsigned int float_precision,
                                                         bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("SPositionError", float_precision, superscript_exponents);

    printer.append(KMALLSensorDatagram::__printer__(float_precision, superscript_exponents));
    // printer.register_section("datagram content");
    //printer.register_value("content_size", __size, std::to_string(sizeof(Content)));
    printer.register_value("time_from_sensor_sec", _content.time_from_sensor_sec, "s");
    printer.register_value("time_from_sensor_nanosec", _content.time_from_sensor_nanosec, "ns");
    printer.register_value("range_input_rms", _content.range_input_rms, "rms");
    printer.register_value(
        "ellipse_semi_major_axis_error_m", _content.ellipse_semi_major_axis_error_m, "m");
    printer.register_value(
        "ellipse_semi_minor_axis_error_m", _content.ellipse_semi_minor_axis_error_m, "m");
    printer.register_value(
        "ellipse_erientation_error_deg", _content.ellipse_erientation_error_deg, "deg");
    printer.register_value("latitude_error_m", _content.latitude_error_m, "m");
    printer.register_value("longitude_error_m", _content.longitude_error_m, "m");
    printer.register_value("height_error_m", _content.height_error_m, "m");
    printer.register_string("pos_error_data_from_sensor", _pos_error_data_from_sensor);
    printer.register_value("bytes_datagram_check", _bytes_datagram_check, "bytes");

    printer.register_section("processed");
    // time processing (if time is provided)
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

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
