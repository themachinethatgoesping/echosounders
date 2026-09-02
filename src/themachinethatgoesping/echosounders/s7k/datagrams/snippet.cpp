// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "snippet.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

void Snippet::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);

    const size_t N = _content.number_beams;
    _beam_descriptor.resize({ N });
    _snippet_start.resize({ N });
    _detection_sample.resize({ N });
    _snippet_end.resize({ N });

    // all beam headers are stored first (see spec Table 76)
    BeamHeader bh;
    for (size_t i = 0; i < N; ++i)
    {
        is.read(reinterpret_cast<char*>(&bh), sizeof(BeamHeader));
        _beam_descriptor.unchecked(i)  = bh.beam_descriptor;
        _snippet_start.unchecked(i)    = bh.snippet_start;
        _detection_sample.unchecked(i) = bh.detection_sample;
        _snippet_end.unchecked(i)      = bh.snippet_end;
    }

    // then the intensity time series of each beam (16- or 32-bit)
    const bool is32 = get_samples_are_32bit();
    _amplitudes.resize(N);
    for (size_t i = 0; i < N; ++i)
    {
        const size_t nsamples = _snippet_end.unchecked(i) - _snippet_start.unchecked(i) + 1;
        _amplitudes[i].resize({ nsamples });

        if (is32)
        {
            is.read(reinterpret_cast<char*>(_amplitudes[i].data()),
                    std::streamsize(nsamples * sizeof(uint32_t)));
        }
        else
        {
            for (size_t s = 0; s < nsamples; ++s)
            {
                uint16_t v;
                is.read(reinterpret_cast<char*>(&v), sizeof(v));
                _amplitudes[i].unchecked(s) = v;
            }
        }
    }
}

Snippet Snippet::from_stream(std::istream& is, S7KDatagram header)
{
    Snippet datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

Snippet Snippet::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

Snippet Snippet::from_stream(std::istream& is, t_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void Snippet::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);

    const size_t N = _content.number_beams;
    BeamHeader   bh;
    for (size_t i = 0; i < N; ++i)
    {
        bh.beam_descriptor  = _beam_descriptor.unchecked(i);
        bh.snippet_start    = _snippet_start.unchecked(i);
        bh.detection_sample = _detection_sample.unchecked(i);
        bh.snippet_end      = _snippet_end.unchecked(i);
        os.write(reinterpret_cast<const char*>(&bh), sizeof(BeamHeader));
    }

    const bool is32 = get_samples_are_32bit();
    for (size_t i = 0; i < N; ++i)
    {
        const auto& amp = _amplitudes[i];
        if (is32)
        {
            os.write(reinterpret_cast<const char*>(amp.data()),
                     std::streamsize(amp.size() * sizeof(uint32_t)));
        }
        else
        {
            for (size_t s = 0; s < amp.size(); ++s)
            {
                uint16_t v = uint16_t(amp.unchecked(s));
                os.write(reinterpret_cast<const char*>(&v), sizeof(v));
            }
        }
    }
}

tools::classhelper::ObjectPrinter Snippet::__printer__(unsigned int float_precision,
                                                       bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("Snippet", float_precision, superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("Snippet content");
    printer.register_value("serial_number", _content.serial_number);
    printer.register_value("ping_number", _content.ping_number);
    printer.register_value("multi_ping", _content.multi_ping);
    printer.register_value("number_beams", _content.number_beams);
    printer.register_value("error_flag", _content.error_flag);
    printer.register_value("control_flags", _content.control_flags);
    printer.register_value("flags", _content.flags);
    printer.register_value("samples_are_32bit", get_samples_are_32bit());

    printer.register_section("per-beam snippets");
    printer.register_container("beam_descriptor", _beam_descriptor);
    printer.register_container("snippet_start", _snippet_start, "samples");
    printer.register_container("detection_sample", _detection_sample, "samples");
    printer.register_container("snippet_end", _snippet_end, "samples");
    printer.register_value("number of snippet arrays", _amplitudes.size());

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
