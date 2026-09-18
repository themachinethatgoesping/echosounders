// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "snippetdatabeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

// ----- convenient member access -----
uint16_t SnippetDataBeam::get_beam_descriptor() const
{
    return _beam_descriptor;
}
uint32_t SnippetDataBeam::get_snippet_start() const
{
    return _snippet_start;
}
uint32_t SnippetDataBeam::get_detection_sample() const
{
    return _detection_sample;
}
uint32_t SnippetDataBeam::get_snippet_end() const
{
    return _snippet_end;
}

void SnippetDataBeam::set_beam_descriptor(uint16_t val)
{
    _beam_descriptor = val;
}
void SnippetDataBeam::set_snippet_start(uint32_t val)
{
    _snippet_start = val;
}
void SnippetDataBeam::set_detection_sample(uint32_t val)
{
    _detection_sample = val;
}
void SnippetDataBeam::set_snippet_end(uint32_t val)
{
    _snippet_end = val;
}

// ----- processed member access -----
uint32_t SnippetDataBeam::get_number_of_samples() const
{
    return _snippet_end - _snippet_start + 1;
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter SnippetDataBeam::__printer__(unsigned int float_precision,
                                                               bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "SnippetDataBeam", float_precision, superscript_exponents);

    printer.register_value("beam_descriptor", _beam_descriptor);
    printer.register_value("snippet_start", _snippet_start, "samples");
    printer.register_value("detection_sample", _detection_sample, "samples");
    printer.register_value("snippet_end", _snippet_end, "samples");
    printer.register_value("number_of_samples", get_number_of_samples(), "samples");

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
