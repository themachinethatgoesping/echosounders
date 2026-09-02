// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/snippet.doc.hpp"

// std includes
#include <cstdint>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "s7kdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

/**
 * @brief 7k record SnippetData: water-column intensity snippets around each beam detection.
 *
 * The record holds, per beam, a short intensity time series (snippet) around the bottom detection.
 * The intensity samples are 16- or 32-bit depending on bit 0 of the flags field.
 */
class Snippet : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::SnippetData;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        uint64_t serial_number; ///< sonar serial number
        uint32_t ping_number;   ///< sequential ping number
        uint16_t multi_ping;    ///< 0 = single ping, else multi-ping sequence number
        uint16_t number_beams;  ///< number of detection points (beams)
        uint8_t  error_flag;    ///< 0 = ok, 6 = bottom detection failed, else error
        uint8_t  control_flags; ///< snippet window control flags
        uint32_t flags;         ///< flags bit field (bit 0: 0 = 16-bit, 1 = 32-bit snippets)
        uint32_t reserved[6];   ///< reserved

        bool operator==(const Content& other) const = default;
    } _content;

    struct BeamHeader
    {
        uint16_t beam_descriptor;  ///< beam number
        uint32_t snippet_start;    ///< first sample of the snippet
        uint32_t detection_sample; ///< detection point sample
        uint32_t snippet_end;      ///< last sample of the snippet
    };
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content); // 46

    // per-beam meta data (length = number_beams)
    xt::xtensor<uint16_t, 1> _beam_descriptor;
    xt::xtensor<uint32_t, 1> _snippet_start;
    xt::xtensor<uint32_t, 1> _detection_sample;
    xt::xtensor<uint32_t, 1> _snippet_end;

    // per-beam intensity snippet (one array per beam)
    std::vector<xt::xtensor<uint32_t, 1>> _amplitudes;

  public:
    Snippet()  = default;
    ~Snippet() = default;

    // ----- record type header access -----
    uint64_t get_serial_number() const { return _content.serial_number; }
    uint32_t get_ping_number() const { return _content.ping_number; }
    uint16_t get_multi_ping() const { return _content.multi_ping; }
    uint16_t get_number_beams() const { return _content.number_beams; }
    uint8_t  get_error_flag() const { return _content.error_flag; }
    uint8_t  get_control_flags() const { return _content.control_flags; }
    uint32_t get_flags() const { return _content.flags; }

    /// true if the intensity samples are stored as 32-bit values (flags bit 0)
    bool get_samples_are_32bit() const { return (_content.flags & 0x1) != 0; }

    // ----- per-beam data access -----
    const xt::xtensor<uint16_t, 1>& get_beam_descriptor() const { return _beam_descriptor; }
    const xt::xtensor<uint32_t, 1>& get_snippet_start() const { return _snippet_start; }
    const xt::xtensor<uint32_t, 1>& get_detection_sample() const { return _detection_sample; }
    const xt::xtensor<uint32_t, 1>& get_snippet_end() const { return _snippet_end; }

    /// intensity snippet arrays (one per beam)
    const std::vector<xt::xtensor<uint32_t, 1>>& get_amplitudes() const { return _amplitudes; }
    /// intensity snippet of a single beam
    const xt::xtensor<uint32_t, 1>& get_beam_amplitudes(size_t beam_index) const
    {
        return _amplitudes.at(beam_index);
    }

    // ----- operators -----
    bool operator==(const Snippet& other) const = default;

    //----- to/from stream functions -----
    static Snippet from_stream(std::istream& is, S7KDatagram header, bool skip_data = false);
    static Snippet from_stream(std::istream& is, bool skip_data = false);
    static Snippet from_stream(std::istream&           is,
                               o_S7KDatagramIdentifier datagram_identifier,
                               bool                    skip_data = false);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(Snippet)

  private:
    explicit Snippet(S7KDatagram header)
        : S7KDatagram(std::move(header))
    {
    }
    void __read__(std::istream& is, bool skip_data = false);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
