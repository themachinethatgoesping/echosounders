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
#pragma pack(push, 1) // byte-packed on disk (7k spec); bulk read as one contiguous block
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
    uint16_t get_beam_descriptor() const;
    uint32_t get_snippet_start() const;
    uint32_t get_detection_sample() const;
    uint32_t get_snippet_end() const;

    void set_beam_descriptor(uint16_t val);
    void set_snippet_start(uint32_t val);
    void set_detection_sample(uint32_t val);
    void set_snippet_end(uint32_t val);

    // ----- processed member access -----
    /// number of intensity samples in this beam's snippet (snippet_end - snippet_start + 1)
    uint32_t get_number_of_samples() const;

    // ----- operators -----
    // NOTE: user-provided (NOT defaulted) on purpose. A defaulted operator== makes this tightly
    // packed, all-integer 14-byte struct "trivially equality comparable", which makes clang-cl /
    // MSVC route std::find/count/remove (instantiated by nanobind's bind_vector) through a SIMD
    // path that only supports element sizes 1/2/4/8 bytes and fails to compile ("unexpected
    // size") for 14 bytes. A user-provided operator== keeps the scalar path while preserving the
    // on-disk layout. See the s7k skill / meson.build note.
    bool operator==(const SnippetDataBeam& other) const
    {
        return _beam_descriptor == other._beam_descriptor &&
               _snippet_start == other._snippet_start &&
               _detection_sample == other._detection_sample && _snippet_end == other._snippet_end;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};
#pragma pack(pop)

static_assert(sizeof(SnippetDataBeam) == 14,
              "s7k SnippetDataBeam (7028 RD): must equal the 14-byte packed on-disk beam header");

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
