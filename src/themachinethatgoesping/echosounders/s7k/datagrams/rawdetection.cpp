// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "rawdetection.hpp"

#include <cmath>
#include <cstring>
#include <limits>
#include <vector>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

void RawDetection::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);

    const size_t N   = _content.number_beams;
    const size_t dfs = _content.data_field_size; // per-beam record size (26, 34, ... version dep.)
    _beam_descriptor.resize({ N });
    _detection_point.resize({ N });
    _rx_angle.resize({ N });
    _beam_flags.resize({ N });
    _quality.resize({ N });
    _uncertainty.resize({ N });
    _signal_strength.resize({ N });
    _min_limit.resize({ N });
    _max_limit.resize({ N });

    static constexpr float nan = std::numeric_limits<float>::quiet_NaN();

    // the per-beam record is read via its declared size (data_field_size); trailing fields that
    // are not present in older versions are filled with NaN
    std::vector<char> buf(dfs);
    for (size_t i = 0; i < N; ++i)
    {
        is.read(buf.data(), std::streamsize(dfs));

        auto u16 = [&](size_t off) { uint16_t v; std::memcpy(&v, buf.data() + off, 2); return v; };
        auto u32 = [&](size_t off) { uint32_t v; std::memcpy(&v, buf.data() + off, 4); return v; };
        auto f32 = [&](size_t off) { float v;    std::memcpy(&v, buf.data() + off, 4); return v; };

        _beam_descriptor.unchecked(i) = u16(0);
        _detection_point.unchecked(i) = f32(2);
        _rx_angle.unchecked(i)        = f32(6);
        _beam_flags.unchecked(i)      = u32(10);
        _quality.unchecked(i)         = u32(14);
        _uncertainty.unchecked(i)     = f32(18);
        _signal_strength.unchecked(i) = dfs >= 26 ? f32(22) : nan;
        _min_limit.unchecked(i)       = dfs >= 30 ? f32(26) : nan;
        _max_limit.unchecked(i)       = dfs >= 34 ? f32(30) : nan;
    }
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

    const size_t      dfs = _content.data_field_size;
    std::vector<char> buf(dfs, 0);
    for (size_t i = 0; i < _content.number_beams; ++i)
    {
        auto pu16 = [&](size_t off, uint16_t v) { std::memcpy(buf.data() + off, &v, 2); };
        auto pu32 = [&](size_t off, uint32_t v) { std::memcpy(buf.data() + off, &v, 4); };
        auto pf32 = [&](size_t off, float v) { std::memcpy(buf.data() + off, &v, 4); };

        pu16(0, _beam_descriptor.unchecked(i));
        pf32(2, _detection_point.unchecked(i));
        pf32(6, _rx_angle.unchecked(i));
        pu32(10, _beam_flags.unchecked(i));
        pu32(14, _quality.unchecked(i));
        pf32(18, _uncertainty.unchecked(i));
        if (dfs >= 26)
            pf32(22, _signal_strength.unchecked(i));
        if (dfs >= 30)
            pf32(26, _min_limit.unchecked(i));
        if (dfs >= 34)
            pf32(30, _max_limit.unchecked(i));

        os.write(buf.data(), std::streamsize(dfs));
    }
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
    printer.register_value("serial_number", _content.serial_number);
    printer.register_value("ping_number", _content.ping_number);
    printer.register_value("multi_ping", _content.multi_ping);
    printer.register_value("number_beams", _content.number_beams);
    printer.register_value("data_field_size", _content.data_field_size, "bytes");
    printer.register_value("detection_algorithm", _content.detection_algorithm);
    printer.register_value("flags", _content.flags);
    printer.register_value("sampling_rate", _content.sampling_rate, "Hz");
    printer.register_value("tx_angle", _content.tx_angle, "rad");
    printer.register_value("applied_roll", _content.applied_roll, "rad");

    printer.register_section("per-beam detections");
    printer.register_container("beam_descriptor", _beam_descriptor);
    printer.register_container("detection_point", _detection_point, "samples");
    printer.register_container("rx_angle", _rx_angle, "rad");
    printer.register_container("quality", _quality);
    printer.register_container("signal_strength", _signal_strength);

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
