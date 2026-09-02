// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/snippetdatabeam.doc.hpp"

// std includes
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Per-beam snippet descriptor (7028 SnippetData beam header).
 *
 * This is the fixed 14-byte beam header that precedes the intensity snippet of every beam. All
 * beam headers are stored as one contiguous block (see spec Table 76) and are therefore read as a
 * single bulk read. The actual intensity samples are decoded separately (SnippetDataAmplitudes).
 */
#pragma pack(push, 1)
class SnippetDataBeam
{
    uint16_t _beam_descriptor  = 0; ///< beam number
    uint32_t _snippet_start    = 0; ///< first sample of the snippet
    uint32_t _detection_sample = 0; ///< detection point sample
    uint32_t _snippet_end      = 0; ///< last sample of the snippet

  public:
    SnippetDataBeam()  = default;
    ~SnippetDataBeam() = default;

    // ----- convenient member access -----
    uint16_t get_beam_descriptor() const { return _beam_descriptor; }
    uint32_t get_snippet_start() const { return _snippet_start; }
    uint32_t get_detection_sample() const { return _detection_sample; }
    uint32_t get_snippet_end() const { return _snippet_end; }

    void set_beam_descriptor(uint16_t val) { _beam_descriptor = val; }
    void set_snippet_start(uint32_t val) { _snippet_start = val; }
    void set_detection_sample(uint32_t val) { _detection_sample = val; }
    void set_snippet_end(uint32_t val) { _snippet_end = val; }

    // ----- processed member access -----
    /// number of intensity samples in this beam's snippet (snippet_end - snippet_start + 1)
    uint32_t get_number_of_samples() const { return _snippet_end - _snippet_start + 1; }

    // ----- operators -----
    bool operator==(const SnippetDataBeam& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
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

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};
#pragma pack(pop)

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
