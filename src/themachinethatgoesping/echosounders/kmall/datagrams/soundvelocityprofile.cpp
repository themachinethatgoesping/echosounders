// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "soundvelocityprofile.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

SoundVelocityProfile::SoundVelocityProfile()
{
    _datagram_identifier = DatagramIdentifier;
}

void SoundVelocityProfile::set_sensor_data(const std::vector<SVPPoint>& data)
{
    _sensor_data               = data;
    _content.number_of_samples = static_cast<uint16_t>(data.size());

    static constexpr size_t dbytes = __size + sizeof(uint32_t);
    _content.bytes_content         = dbytes + _sensor_data.size() * sizeof(SVPPoint);
    set_bytes_datagram(KMALLDatagram::__size + _content.bytes_content);
    _bytes_datagram_check = get_bytes_datagram();
}

tools::classhelper::ObjectPrinter SoundVelocityProfile::SVPPoint::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    auto printer =
        tools::classhelper::ObjectPrinter("SVPPoint", float_precision, superscript_exponents);

    printer.register_value("depth_m", depth_m, "m");
    printer.register_value("soundVelocity_m_per_sec", soundVelocity_m_per_sec, "m/s");
    printer.register_value("padding", padding);
    printer.register_value("temp_c", temp_c, "°C");
    printer.register_value("salinity", salinity, "PSU");

    return printer;
}

// ----- to/from stream functions -----
void SoundVelocityProfile::__read__(std::istream& is)
{
    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&_content), __size);

    // read position data string
    _sensor_data.resize(get_number_of_samples()); // minus size of the previous fields
    is.read(reinterpret_cast<char*>(_sensor_data.data()), _sensor_data.size() * sizeof(SVPPoint));
    is.read(reinterpret_cast<char*>(&(_bytes_datagram_check)), sizeof(_bytes_datagram_check));
}

SoundVelocityProfile SoundVelocityProfile::from_stream(std::istream&        is,
                                                       const KMALLDatagram& header)
{
    SoundVelocityProfile datagram(header);
    datagram.__read__(is);

    return datagram;
}

SoundVelocityProfile SoundVelocityProfile::from_stream(
    std::istream&             is,
    o_KMALLDatagramIdentifier datagram_identifier)
{
    SoundVelocityProfile datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__check_datagram_identifier__(datagram_identifier, DatagramIdentifier);
    datagram.__read__(is);
    return datagram;
}

SoundVelocityProfile SoundVelocityProfile::from_stream(std::istream& is)
{
    SoundVelocityProfile datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read__(is);
    return datagram;
}

void SoundVelocityProfile::to_stream(std::ostream& os)
{
    KMALLDatagram::to_stream(os);

    os.write(reinterpret_cast<char*>(&_content), __size);
    os.write(reinterpret_cast<const char*>(_sensor_data.data()),
             _sensor_data.size() * sizeof(SVPPoint));
    os.write(reinterpret_cast<const char*>(&_bytes_datagram_check), sizeof(_bytes_datagram_check));
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter SoundVelocityProfile::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "SoundVelocityProfile", float_precision, superscript_exponents);

    printer.append(KMALLDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("bytes_content", _content.bytes_content);
    printer.register_value("number_of_samples", _content.number_of_samples);
    printer.register_value("sensor_format",
                           fmt::format("{:02X}{:02X}{:02X}{:02X}",
                                       _content.sensor_format[0],
                                       _content.sensor_format[1],
                                       _content.sensor_format[2],
                                       _content.sensor_format[3]));
    printer.register_value("svp_time_sec", _content.svp_time_sec, "s");
    printer.register_value("latitude_deg", _content.latitude_deg, "°");
    printer.register_value("longitude_deg", _content.longitude_deg, "°");
    printer.register_value("sensor_data",
                           fmt::format("vector<SVPPoint> with {} entries", _sensor_data.size()));
    printer.register_value("bytes_datagram_check", _bytes_datagram_check, "bytes");

    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
