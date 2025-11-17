// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "soundvelocitytransducer.hpp"

#include <fmt/format.h>

#include <bitset>
#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/algorithms/amplitudecorrection/functions/absorption.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

double SoundVelocityTransducer::SVTSample::get_sensor_timestamp() const
{
    return time_sec + time_nanosec * 1e-9;
}

std::string SoundVelocityTransducer::SVTSample::get_sensor_date_string(
    unsigned int       fractionalSecondsDigits,
    const std::string& format) const
{
    return tools::timeconv::unixtime_to_datestring(
        get_sensor_timestamp(), fractionalSecondsDigits, format);
}

tools::classhelper::ObjectPrinter SoundVelocityTransducer::SVTSample::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    auto printer =
        tools::classhelper::ObjectPrinter("SVTSample", float_precision, superscript_exponents);

    printer.register_value("time_sec", time_sec, "s");
    printer.register_value("time_nanosec", time_nanosec, "ns");
    printer.register_value("soundVelocity_m_per_sec", soundVelocity_m_per_sec, "m/s");
    printer.register_value("temp_c", temp_c, "°C");
    printer.register_value("pressure_pa", pressure_pa, "Pa");
    printer.register_value("salinity", salinity, "PSU");

    return printer;
}

SoundVelocityTransducer::SoundVelocityTransducer()
{
    _datagram_identifier = DatagramIdentifier;
}

SoundVelocityTransducer::SoundVelocityTransducer(const KMALLDatagram& header)
    : KMALLDatagram(header)
{
}

bool SoundVelocityTransducer::get_sound_velocity_active() const
{
    return std::bitset<16>(_content.sensor_status).test(0);
}

bool SoundVelocityTransducer::get_temperature_active() const
{
    return std::bitset<16>(_content.sensor_status).test(1);
}

bool SoundVelocityTransducer::get_pressure_active() const
{
    return std::bitset<16>(_content.sensor_status).test(3);
}

bool SoundVelocityTransducer::get_salinity_active() const
{
    return std::bitset<16>(_content.sensor_status).test(4);
}

void SoundVelocityTransducer::set_sound_velocity_active(bool active)
{
    std::bitset<16> status_bits(_content.sensor_status);
    status_bits.set(0, active);
    _content.sensor_status = static_cast<uint16_t>(status_bits.to_ulong());
}

void SoundVelocityTransducer::set_temperature_active(bool active)
{
    std::bitset<16> status_bits(_content.sensor_status);
    status_bits.set(1, active);
    _content.sensor_status = static_cast<uint16_t>(status_bits.to_ulong());
}

void SoundVelocityTransducer::set_pressure_active(bool active)
{
    std::bitset<16> status_bits(_content.sensor_status);
    status_bits.set(3, active);
    _content.sensor_status = static_cast<uint16_t>(status_bits.to_ulong());
}

void SoundVelocityTransducer::set_salinity_active(bool active)
{
    std::bitset<16> status_bits(_content.sensor_status);
    status_bits.set(4, active);
    _content.sensor_status = static_cast<uint16_t>(status_bits.to_ulong());
}

void SoundVelocityTransducer::set_sensor_data(const std::vector<SVTSample>& data)
{
    _sensor_data               = data;
    _content.number_of_samples = static_cast<uint16_t>(data.size());

    static constexpr size_t dbytes = __size + sizeof(uint32_t);
    _content.bytes_content         = dbytes + _sensor_data.size() * sizeof(SVTSample);
    set_bytes_datagram(KMALLDatagram::__size + _content.bytes_content);
    _bytes_datagram_check = get_bytes_datagram();
}

// ----- to/from stream functions -----
void SoundVelocityTransducer::__read__(std::istream& is)
{
    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&_content), __size);

    // read position data string
    _sensor_data.resize(get_number_of_samples()); // minus size of the previous fields
    is.read(reinterpret_cast<char*>(_sensor_data.data()), _sensor_data.size() * sizeof(SVTSample));
    is.read(reinterpret_cast<char*>(&(_bytes_datagram_check)), sizeof(_bytes_datagram_check));
}

SoundVelocityTransducer SoundVelocityTransducer::from_stream(std::istream&        is,
                                                             const KMALLDatagram& header)
{
    SoundVelocityTransducer datagram(header);
    datagram.__read__(is);

    return datagram;
}

SoundVelocityTransducer SoundVelocityTransducer::from_stream(
    std::istream&             is,
    o_KMALLDatagramIdentifier datagram_identifier)
{
    SoundVelocityTransducer datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__check_datagram_identifier__(datagram_identifier, DatagramIdentifier);
    datagram.__read__(is);
    return datagram;
}

SoundVelocityTransducer SoundVelocityTransducer::from_stream(std::istream& is)
{
    SoundVelocityTransducer datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read__(is);
    return datagram;
}

void SoundVelocityTransducer::to_stream(std::ostream& os)
{
    KMALLDatagram::to_stream(os);

    os.write(reinterpret_cast<char*>(&_content), __size);
    os.write(reinterpret_cast<const char*>(_sensor_data.data()),
             _sensor_data.size() * sizeof(SVTSample));
    os.write(reinterpret_cast<const char*>(&_bytes_datagram_check), sizeof(_bytes_datagram_check));
}

// ----- processed values -----
std::vector<double> SoundVelocityTransducer::get_svt_timestamps() const
{
    std::vector<double> timestamps;
    timestamps.reserve(_sensor_data.size());
    for (const auto& point : _sensor_data)
    {
        timestamps.push_back(point.get_sensor_timestamp());
    }
    return timestamps;
}
std::vector<float> SoundVelocityTransducer::get_svt_pressures() const
{
    std::vector<float> pressures;
    pressures.reserve(_sensor_data.size());
    for (const auto& point : _sensor_data)
    {
        pressures.push_back(point.pressure_pa);
    }
    return pressures;
}
std::vector<float> SoundVelocityTransducer::get_svt_sound_velocities() const
{
    std::vector<float> sound_velocities;
    sound_velocities.reserve(_sensor_data.size());
    for (const auto& point : _sensor_data)
    {
        sound_velocities.push_back(point.soundVelocity_m_per_sec);
    }
    return sound_velocities;
}
std::vector<float> SoundVelocityTransducer::get_svt_salinities() const
{
    std::vector<float> salinities;
    salinities.reserve(_sensor_data.size());
    for (const auto& point : _sensor_data)
    {
        salinities.push_back(point.salinity);
    }
    return salinities;
}
std::vector<float> SoundVelocityTransducer::get_svt_temperatures() const
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

tools::classhelper::ObjectPrinter SoundVelocityTransducer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "SoundVelocityTransducer", float_precision, superscript_exponents);

    printer.append(KMALLDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("bytes_content", _content.bytes_content);
    printer.register_value("sensor_status", _content.sensor_status);
    printer.register_string(
        "sensor_input_format",
        _content.sensor_input_format.name(),
        fmt::format("{}", fmt::join(_content.sensor_input_format.names(), ", ")));
    printer.register_value("number_of_samples", _content.number_of_samples);
    printer.register_value("number_of_bytes_per_sample", _content.number_of_bytes_per_sample);
    printer.register_string("sensor_data_contents_bits",
                            fmt::format("{:08b}", _content.sensor_data_contents));
    printer.register_value("filter_time_sec", _content.filter_time_sec, "s");
    printer.register_value(
        "sound_velocity_offset_m_per_sec", _content.sound_velocity_offset_m_per_sec, "m/s");
    printer.register_value("sensor_data",
                           fmt::format("vector<SVTSample> with {} entries", _sensor_data.size()));
    printer.register_value("bytes_datagram_check", _bytes_datagram_check, "bytes");

    // --- processed ---
    const auto times       = get_svt_timestamps();
    const auto pressures   = get_svt_pressures();
    const auto vel         = get_svt_sound_velocities();
    const auto salinity    = get_svt_salinities();
    const auto temperature = get_svt_temperatures();
    printer.register_section("processed\n" +
                             fmt::format("[date time, sound velocity (m/s), salinity (psu), "
                                         "temperature (°C), pressure (Pa)]"));
    for (size_t i = 0; i < times.size(); ++i)
    {
        static const std::string format_date("%d/%m/%Y %H:%M:%S");
        using tools::timeconv::unixtime_to_datestring;
        auto date = unixtime_to_datestring(times[i], 2, format_date);

        printer.register_string(
            fmt::format("sample [{}]", i),
            fmt::format("{}, {:7.2f} m/s, {:7.2f} psu, {:7.3f} °C, {:10.2f} Pa",
                        date,
                        vel[i],
                        salinity[i],
                        temperature[i],
                        pressures[i]));
    }

    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping

template class themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityTransducer::
        t_sensor_format,
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityTransducer::
        t_sensor_format_values.size(),
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityTransducer::
        t_sensor_format_values,
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityTransducer::
        t_sensor_format_names,
    themachinethatgoesping::echosounders::kmall::datagrams::SoundVelocityTransducer::
        t_sensor_format_alt_names>;