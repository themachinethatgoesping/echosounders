// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "rawdetection.hpp"

#include <algorithm>
#include <limits>
#include <numbers>
#include <string>
#include <utility>

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

// ----- constructors -----
RawDetection::RawDetection()
    : _content{}
{
    set_datagram_identifier(DatagramIdentifier);
}

RawDetection::RawDetection(S7KDatagram header)
    : S7KDatagram(std::move(header))
{
}

// ----- convenient member access (record type header) -----
uint64_t RawDetection::get_serial_number() const
{
    return _content._serial_number;
}
uint32_t RawDetection::get_ping_number() const
{
    return _content._ping_number;
}
uint16_t RawDetection::get_multi_ping() const
{
    return _content._multi_ping;
}
uint32_t RawDetection::get_number_beams() const
{
    return _content._number_beams;
}
uint32_t RawDetection::get_data_field_size() const
{
    return _content._data_field_size;
}
uint8_t RawDetection::get_detection_algorithm() const
{
    return _content._detection_algorithm;
}
uint32_t RawDetection::get_flags() const
{
    return _content._flags;
}
float RawDetection::get_sampling_rate() const
{
    return _content._sampling_rate;
}
float RawDetection::get_tx_angle() const
{
    return _content._tx_angle;
}
float RawDetection::get_applied_roll() const
{
    return _content._applied_roll;
}
uint32_t RawDetection::get_checksum() const
{
    return _checksum;
}

void RawDetection::set_serial_number(uint64_t val)
{
    _content._serial_number = val;
}
void RawDetection::set_ping_number(uint32_t val)
{
    _content._ping_number = val;
}
void RawDetection::set_multi_ping(uint16_t val)
{
    _content._multi_ping = val;
}
void RawDetection::set_number_beams(uint32_t val)
{
    _content._number_beams = val;
}
void RawDetection::set_data_field_size(uint32_t val)
{
    _content._data_field_size = val;
}
void RawDetection::set_detection_algorithm(uint8_t val)
{
    _content._detection_algorithm = val;
}
void RawDetection::set_flags(uint32_t val)
{
    _content._flags = val;
}
void RawDetection::set_sampling_rate(float val)
{
    _content._sampling_rate = val;
}
void RawDetection::set_tx_angle(float val)
{
    _content._tx_angle = val;
}
void RawDetection::set_applied_roll(float val)
{
    _content._applied_roll = val;
}
void RawDetection::set_checksum(uint32_t val)
{
    _checksum = val;
}

// ----- processed data access -----
float RawDetection::get_tx_angle_in_degrees() const
{
    return _content._tx_angle * 180.f / float(std::numbers::pi);
}
float RawDetection::get_applied_roll_in_degrees() const
{
    return _content._applied_roll * 180.f / float(std::numbers::pi);
}

// ----- substructure access -----
const substructs::RawDetectionBeamContainer& RawDetection::get_beams() const
{
    return _beams;
}
substructs::RawDetectionBeamContainer& RawDetection::beams()
{
    return _beams;
}
void RawDetection::set_beams(const substructs::RawDetectionBeamContainer& beams)
{
    _beams = beams;
}

void RawDetection::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);

    const size_t N   = _content._number_beams;
    const size_t dfs = _content._data_field_size; // per-beam record size on disk (version dependent)

    auto& beams = _beams.beams();
    beams.resize(N);

    if (dfs == sizeof(substructs::RawDetectionBeam))
    {
        // full-width record: read every beam in one bulk read directly into the container (no copy)
        is.read(reinterpret_cast<char*>(beams.data()), std::streamsize(dfs * N));
    }
    else
    {
        // otherwise read each beam directly into its final position; trailing fields not present in
        // this (shorter) record version stay default-constructed and are set to NaN
        static constexpr float  nan         = std::numeric_limits<float>::quiet_NaN();
        static constexpr size_t struct_size = sizeof(substructs::RawDetectionBeam); // 34
        for (auto& beam : beams)
        {
            is.read(reinterpret_cast<char*>(&beam), std::streamsize(std::min(dfs, struct_size)));
            if (dfs > struct_size)
                is.seekg(std::streamoff(dfs - struct_size), std::ios::cur);
            if (dfs < 26)
                beam.set_signal_strength(nan);
            if (dfs < 30)
                beam.set_min_limit(nan);
            if (dfs < 34)
                beam.set_max_limit(nan);
        }
    }

    // read the trailing 4-byte checksum (stored for debugging only, not verified)
    is.read(reinterpret_cast<char*>(&_checksum), sizeof(_checksum));
}

RawDetection RawDetection::from_stream(std::istream& is, S7KDatagram header)
{
    RawDetection datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

RawDetection RawDetection::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

RawDetection RawDetection::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void RawDetection::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);

    const size_t            dfs         = _content._data_field_size;
    const auto&             beams       = _beams.get_beams();
    static constexpr size_t struct_size = sizeof(substructs::RawDetectionBeam);

    // full-width record: write every beam in one bulk write
    if (dfs == struct_size)
    {
        os.write(reinterpret_cast<const char*>(beams.data()), std::streamsize(dfs * beams.size()));
    }
    else
    {
        // shorter/longer record: write the first min(dfs, struct_size) bytes of each beam (+ pad)
        const std::streamsize head = std::streamsize(std::min(dfs, struct_size));
        std::string           pad;
        if (dfs > struct_size)
            pad.assign(dfs - struct_size, '\0');
        for (const auto& beam : beams)
        {
            os.write(reinterpret_cast<const char*>(&beam), head);
            if (!pad.empty())
                os.write(pad.data(), std::streamsize(pad.size()));
        }
    }

    os.write(reinterpret_cast<const char*>(&_checksum), sizeof(_checksum));
}

tools::classhelper::ObjectPrinter RawDetection::__printer__(unsigned int float_precision,
                                                            bool superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("RawDetection content");
    printer.register_value("serial_number", _content._serial_number);
    printer.register_value("ping_number", _content._ping_number);
    printer.register_value("multi_ping", _content._multi_ping);
    printer.register_value("number_beams", _content._number_beams);
    printer.register_value("data_field_size", _content._data_field_size, "bytes");
    printer.register_value("detection_algorithm", _content._detection_algorithm);
    printer.register_value("flags", fmt::format("0b{:032b}", _content._flags));
    printer.register_value("sampling_rate", _content._sampling_rate, "Hz");
    printer.register_value("tx_angle", _content._tx_angle, "rad");
    printer.register_value("applied_roll", _content._applied_roll, "rad");
    printer.register_value("checksum", _checksum);

    printer.register_section("processed");
    printer.register_value("tx_angle_in_degrees", get_tx_angle_in_degrees(), "°");
    printer.register_value("applied_roll_in_degrees", get_applied_roll_in_degrees(), "°");

    printer.register_section("beams");
    printer.append(_beams.__printer__(float_precision, superscript_exponents));

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
