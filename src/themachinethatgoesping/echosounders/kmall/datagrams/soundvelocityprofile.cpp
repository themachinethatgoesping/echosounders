// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "soundvelocityprofile.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/algorithms/amplitudecorrection/functions/absorption.hpp>
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

// ----- processed values -----
std::vector<float> SoundVelocityProfile::get_svp_depths() const
{
    std::vector<float> depths;
    depths.reserve(_sensor_data.size());
    for (const auto& point : _sensor_data)
    {
        depths.push_back(point.depth_m);
    }
    return depths;
}
std::vector<float> SoundVelocityProfile::get_svp_sound_velocities() const
{
    std::vector<float> sound_velocities;
    sound_velocities.reserve(_sensor_data.size());
    for (const auto& point : _sensor_data)
    {
        sound_velocities.push_back(point.soundVelocity_m_per_sec);
    }
    return sound_velocities;
}
std::vector<float> SoundVelocityProfile::get_svp_sound_velocities_computed() const
{
    std::vector<float> sound_velocities;
    sound_velocities.reserve(_sensor_data.size());
    for (const auto& point : _sensor_data)
    {
        // compute sound velocity using Mackenzie formula
        float c =
            algorithms::amplitudecorrection::functions::calc_sound_velocity(point.depth_m,
                                                                            point.temp_c,
                                                                            point.salinity,
                                                                            _content.latitude_deg,
                                                                            _content.longitude_deg);
        sound_velocities.push_back(c);
    }
    return sound_velocities;
}
std::vector<float> SoundVelocityProfile::get_svp_absorption_computed(float frequency,
                                                                     float ph) const
{
    std::vector<float> absorptions;
    absorptions.reserve(_sensor_data.size());
    for (const auto& point : _sensor_data)
    {
        float c =
            algorithms::amplitudecorrection::functions::calc_sound_velocity(point.depth_m,
                                                                            point.temp_c,
                                                                            point.salinity,
                                                                            _content.latitude_deg,
                                                                            _content.longitude_deg);

        // compute absorption using Francois-Garrison formula at 200 kHz
        float a = algorithms::amplitudecorrection::functions::calc_absorption_coefficient_db_m(
            frequency, c, point.temp_c, point.salinity, ph);
        absorptions.push_back(a);
    }
    return absorptions;
}

std::vector<float> SoundVelocityProfile::get_svp_salinities() const
{
    std::vector<float> salinities;
    salinities.reserve(_sensor_data.size());
    for (const auto& point : _sensor_data)
    {
        salinities.push_back(point.salinity);
    }
    return salinities;
}
std::vector<float> SoundVelocityProfile::get_svp_temperatures() const
{
    std::vector<float> temperatures;
    temperatures.reserve(_sensor_data.size());
    for (const auto& point : _sensor_data)
    {
        temperatures.push_back(point.temp_c);
    }
    return temperatures;
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
    printer.register_string("sensor_format",
                            _content.sensor_format.name(),
                            fmt::format("{}", fmt::join(_content.sensor_format.names(), ", ")));
    printer.register_value("svp_time_sec", _content.svp_time_sec, "s");
    printer.register_value("latitude_deg", _content.latitude_deg, "°");
    printer.register_value("longitude_deg", _content.longitude_deg, "°");
    printer.register_value("sensor_data",
                           fmt::format("vector<SVPPoint> with {} entries", _sensor_data.size()));
    printer.register_value("bytes_datagram_check", _bytes_datagram_check, "bytes");

    // --- processed ---
    const auto depth       = get_svp_depths();
    const auto vel         = get_svp_sound_velocities();
    const auto vel_comp    = get_svp_sound_velocities_computed();
    const auto salinity    = get_svp_salinities();
    const auto temperature = get_svp_temperatures();
    const auto absorption  = get_svp_absorption_computed(200e3);
    printer.register_section(
        "processed\n" +
        fmt::format("[depth (m), sound velocity (m/s), sound velocity [computed] (m/s), "
                    "salinity (PSU), temperature (°C), absorption at 200 kHz [computed] (dB/m)]"));
    for (size_t i = 0; i < depth.size(); ++i)
    {
        printer.register_string(
            fmt::format("sample [{}]", i),
            fmt::format(
                "{:8.2f} m, {:7.2f} m/s, {:7.2f} m/s, {:7.2f} psu, {:7.3f} °C, {:10.6f} dB/m",
                depth[i],
                vel[i],
                vel_comp[i],
                salinity[i],
                temperature[i],
                absorption[i]));
    }

    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping

template class themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityProfile::t_sensor_format,
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityProfile::
        t_sensor_format_values.size(),
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityProfile::
        t_sensor_format_values,
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityProfile::
        t_sensor_format_names,
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityProfile::
        t_sensor_format_alt_names>;