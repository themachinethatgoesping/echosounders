// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "snippetdata.hpp"

#include <variant>

#include <xtensor/containers/xtensor.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

void SnippetData::__read__(std::istream& is, bool skip_data)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);

    const size_t N     = _content.number_beams;
    auto&        beams = _beams.beams();
    beams.resize(N);

    // all beam headers are stored first as one contiguous block (see spec Table 76)
    is.read(reinterpret_cast<char*>(beams.data()),
            std::streamsize(N * sizeof(substructs::SnippetDataBeam)));

    // per-beam start offsets into the (contiguous) sample block
    xt::xtensor<uint64_t, 1> offsets = xt::xtensor<uint64_t, 1>::from_shape({ N + 1 });
    offsets.unchecked(0) = 0;
    for (size_t i = 0; i < N; ++i)
        offsets.unchecked(i + 1) = offsets.unchecked(i) + beams[i].get_number_of_samples();

    const bool   is32  = get_samples_are_32bit();
    const size_t total = size_t(offsets.unchecked(N));

    _amplitudes.set_samples_are_32bit(is32);
    _amplitudes.set_beam_offsets(offsets);

    const int64_t sample_position = int64_t(is.tellg());

    if (skip_data)
    {
        // remember the sample position so the samples can be read lazily later, then seek past them
        _amplitudes.set_skipped(sample_position);
        is.seekg(std::streamoff(total * (is32 ? sizeof(uint32_t) : sizeof(uint16_t))),
                 std::ios::cur);
        return;
    }

    // the intensity time series of all beams is stored as one contiguous block (16- or 32-bit)
    if (is32)
    {
        xt::xtensor<uint32_t, 1> flat = xt::xtensor<uint32_t, 1>::from_shape({ total });
        is.read(reinterpret_cast<char*>(flat.data()), std::streamsize(total * sizeof(uint32_t)));
        _amplitudes.set_samples(std::move(flat));
    }
    else
    {
        xt::xtensor<uint16_t, 1> flat = xt::xtensor<uint16_t, 1>::from_shape({ total });
        is.read(reinterpret_cast<char*>(flat.data()), std::streamsize(total * sizeof(uint16_t)));
        _amplitudes.set_samples(std::move(flat));
    }
}

SnippetData SnippetData::from_stream(std::istream& is, S7KDatagram header, bool skip_data)
{
    SnippetData datagram(std::move(header));
    datagram.__read__(is, skip_data);
    return datagram;
}

SnippetData SnippetData::from_stream(std::istream& is, bool skip_data)
{
    return from_stream(is, S7KDatagram::from_stream(is), skip_data);
}

SnippetData SnippetData::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier, bool skip_data)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier), skip_data);
}

void SnippetData::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);

    const auto& beams = _beams.get_beams();
    os.write(reinterpret_cast<const char*>(beams.data()),
             std::streamsize(beams.size() * sizeof(substructs::SnippetDataBeam)));

    std::visit(
        [&os](const auto& flat) {
            using value_type = typename std::decay_t<decltype(flat)>::value_type;
            os.write(reinterpret_cast<const char*>(flat.data()),
                     std::streamsize(flat.size() * sizeof(value_type)));
        },
        _amplitudes.get_samples());
}

tools::classhelper::ObjectPrinter SnippetData::__printer__(unsigned int float_precision,
                                                       bool         superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("SnippetData content");
    printer.register_value("serial_number", _content.serial_number);
    printer.register_value("ping_number", _content.ping_number);
    printer.register_value("multi_ping", _content.multi_ping);
    printer.register_value("number_beams", _content.number_beams);
    printer.register_value("error_flag", _content.error_flag);
    printer.register_value("control_flags", _content.control_flags);
    printer.register_value("flags", _content.flags);
    printer.register_value("samples_are_32bit", get_samples_are_32bit());

    printer.register_section("beams");
    printer.append(_beams.__printer__(float_precision, superscript_exponents));
    printer.register_section("amplitudes");
    printer.append(_amplitudes.__printer__(float_precision, superscript_exponents));

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
