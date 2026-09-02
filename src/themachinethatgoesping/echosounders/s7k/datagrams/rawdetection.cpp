// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "rawdetection.hpp"

#include <algorithm>
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
    const size_t dfs = _content.data_field_size; // per-beam record size on disk (version dependent)

    auto& beams = _beams.beams();
    beams.resize(N);

    static constexpr float  nan         = std::numeric_limits<float>::quiet_NaN();
    static constexpr size_t struct_size = sizeof(substructs::RawDetectionBeam); // 34

    // read the whole per-beam block in a single bulk read, then interpret each beam record
    std::vector<char> buf(dfs * N);
    is.read(buf.data(), std::streamsize(dfs * N));

    for (size_t i = 0; i < N; ++i)
    {
        substructs::RawDetectionBeam beam;
        std::memcpy(&beam, buf.data() + i * dfs, std::min(dfs, struct_size));

        // trailing fields that are not present in this record version are filled with NaN
        if (dfs < 26)
            beam.set_signal_strength(nan);
        if (dfs < 30)
            beam.set_min_limit(nan);
        if (dfs < 34)
            beam.set_max_limit(nan);

        beams[i] = beam;
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

    const size_t            dfs         = _content.data_field_size;
    const auto&             beams       = _beams.get_beams();
    static constexpr size_t struct_size = sizeof(substructs::RawDetectionBeam);

    std::vector<char> buf(dfs, 0);
    for (const auto& beam : beams)
    {
        std::fill(buf.begin(), buf.end(), char(0));
        std::memcpy(buf.data(), &beam, std::min(dfs, struct_size));
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

    printer.register_section("beams");
    printer.append(_beams.__printer__(float_precision, superscript_exponents));

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
