// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "snippetdataamplitudes.hpp"

#include <algorithm>
#include <cmath>
#include <istream>
#include <limits>
#include <stdexcept>

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

int64_t SnippetDataAmplitudes::get_sample_position() const
{
    if (!_skipped)
        throw std::runtime_error(
            "ERROR[SnippetDataAmplitudes::get_sample_position]: The sample position is only "
            "available if the data was skipped!");

    return _sample_position;
}

xt::xtensor<float, 1> SnippetDataAmplitudes::get_beam(size_t beam_index) const
{
    if (beam_index + 1 >= _beam_offsets.size())
        throw std::out_of_range(
            fmt::format("ERROR[SnippetDataAmplitudes::get_beam]: beam_index {} out of range (number "
                        "of beams: {})",
                        beam_index,
                        get_number_of_beams()));

    const size_t start = size_t(_beam_offsets.unchecked(beam_index));
    const size_t end   = size_t(_beam_offsets.unchecked(beam_index + 1));

    xt::xtensor<float, 1> out = xt::xtensor<float, 1>::from_shape({ end - start });
    std::visit(
        [&](const auto& flat) {
            if (flat.size() < end)
                throw std::runtime_error("ERROR[SnippetDataAmplitudes::get_beam]: samples are not "
                                         "loaded (skipped). Call read_samples() first.");
            for (size_t s = 0; s < end - start; ++s)
                out.unchecked(s) = static_cast<float>(flat.unchecked(start + s));
        },
        _samples);
    return out;
}

std::vector<xt::xtensor<float, 1>> SnippetDataAmplitudes::get_beams() const
{
    const size_t                       n = get_number_of_beams();
    std::vector<xt::xtensor<float, 1>> out(n);
    for (size_t b = 0; b < n; ++b)
        out[b] = get_beam(b);
    return out;
}

xt::xtensor<float, 1> SnippetDataAmplitudes::get_beam_in_db(size_t beam_index, float db_offset) const
{
    xt::xtensor<float, 1> amp     = get_beam(beam_index);
    const float           neg_inf = -std::numeric_limits<float>::infinity();
    for (size_t i = 0; i < amp.size(); ++i)
    {
        const float v   = amp.unchecked(i);
        amp.unchecked(i) = v > 0.f ? 20.f * std::log10(v) + db_offset : neg_inf;
    }
    return amp;
}

std::vector<xt::xtensor<float, 1>> SnippetDataAmplitudes::get_beams_in_db(float db_offset) const
{
    const size_t                       n = get_number_of_beams();
    std::vector<xt::xtensor<float, 1>> out(n);
    for (size_t b = 0; b < n; ++b)
        out[b] = get_beam_in_db(b, db_offset);
    return out;
}

void SnippetDataAmplitudes::read_samples(std::istream& is)
{
    if (!_skipped)
        return;

    is.seekg(_sample_position);
    const size_t total = get_total_number_of_samples();

    if (_samples_are_32bit)
    {
        xt::xtensor<uint32_t, 1> flat = xt::xtensor<uint32_t, 1>::from_shape({ total });
        is.read(reinterpret_cast<char*>(flat.data()), std::streamsize(total * sizeof(uint32_t)));
        _samples = std::move(flat);
    }
    else
    {
        xt::xtensor<uint16_t, 1> flat = xt::xtensor<uint16_t, 1>::from_shape({ total });
        is.read(reinterpret_cast<char*>(flat.data()), std::streamsize(total * sizeof(uint16_t)));
        _samples = std::move(flat);
    }

    _skipped = false;
}

namespace {
template<typename T>
bool tensor_equal(const T& a, const T& b)
{
    return a.size() == b.size() && std::equal(a.begin(), a.end(), b.begin());
}
} // namespace

bool SnippetDataAmplitudes::operator==(const SnippetDataAmplitudes& other) const
{
    if (_samples_are_32bit != other._samples_are_32bit || _skipped != other._skipped)
        return false;

    if (!tensor_equal(_beam_offsets, other._beam_offsets))
        return false;

    if (_samples.index() != other._samples.index())
        return false;

    bool equal = true;
    std::visit(
        [&](const auto& a) {
            using T  = std::decay_t<decltype(a)>;
            const T& b = std::get<T>(other._samples);
            equal      = tensor_equal(a, b);
        },
        _samples);
    return equal;
}

tools::classhelper::ObjectPrinter SnippetDataAmplitudes::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "SnippetDataAmplitudes", float_precision, superscript_exponents);

    printer.register_value("samples_are_32bit", _samples_are_32bit);
    printer.register_value("number_of_beams", get_number_of_beams());
    printer.register_value("total_number_of_samples", get_total_number_of_samples());
    printer.register_value("samples_are_skipped", _skipped);

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
