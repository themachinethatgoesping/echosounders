// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/snippetdata.doc.hpp"

// std includes
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "s7kdatagram.hpp"
#include "substructs/snippetdataamplitudes.hpp"
#include "substructs/snippetdatabeamcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

/**
 * @brief 7k record SnippetData (7028): water-column intensity snippets around each beam detection.
 *
 * The record holds, per beam, a short intensity time series (snippet) around the bottom detection.
 * The per-beam descriptors are stored in a SnippetDataBeamContainer (read as one bulk block), the
 * intensity samples in a SnippetDataAmplitudes container (16- or 32-bit depending on bit 0 of the
 * flags field, read as one bulk block). Array/dB conversions are computed on demand.
 */
class SnippetData : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::SnippetData;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        uint64_t _serial_number = 0; ///< sonar serial number
        uint32_t _ping_number   = 0; ///< sequential ping number
        uint16_t _multi_ping    = 0; ///< 0 = single ping, else multi-ping sequence number
        uint16_t _number_beams  = 0; ///< number of detection points (beams)
        uint8_t  _error_flag    = 0; ///< 0 = ok, 6 = bottom detection failed, else error
        uint8_t  _control_flags = 0; ///< snippet window control flags
        uint32_t _flags         = 0; ///< flags bit field (bit 0: 0 = 16-bit, 1 = 32-bit snippets)
        uint32_t _reserved[6]   = {}; ///< reserved

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content); // 46

    substructs::SnippetDataBeamContainer _beams;      ///< per-beam snippet descriptors
    substructs::SnippetDataAmplitudes    _amplitudes; ///< per-beam intensity samples

    uint32_t _checksum = 0; ///< record checksum (last 4 bytes; see S7KDatagram, debugging only)

  public:
    SnippetData();
    ~SnippetData() = default;

    // ----- record type header access -----
    uint64_t get_serial_number() const;
    uint32_t get_ping_number() const;
    uint16_t get_multi_ping() const;
    uint16_t get_number_beams() const;
    uint8_t  get_error_flag() const;
    uint8_t  get_control_flags() const;
    uint32_t get_flags() const;
    uint32_t get_checksum() const;

    void set_serial_number(uint64_t val);
    void set_ping_number(uint32_t val);
    void set_multi_ping(uint16_t val);
    void set_number_beams(uint16_t val);
    void set_error_flag(uint8_t val);
    void set_control_flags(uint8_t val);
    void set_flags(uint32_t val);
    void set_checksum(uint32_t val);

    /// true if the intensity samples are stored as 32-bit values (flags bit 0)
    bool get_samples_are_32bit() const;

    // ----- substructure access -----
    const substructs::SnippetDataBeamContainer& get_beams() const;
    substructs::SnippetDataBeamContainer&       beams();
    void set_beams(const substructs::SnippetDataBeamContainer& beams);

    const substructs::SnippetDataAmplitudes& get_amplitudes() const;
    substructs::SnippetDataAmplitudes&       amplitudes();
    void set_amplitudes(const substructs::SnippetDataAmplitudes& amplitudes);

    // ----- operators -----
    bool operator==(const SnippetData& other) const = default;

    //----- to/from stream functions -----
    static SnippetData from_stream(std::istream& is, S7KDatagram header, bool skip_data = false);
    static SnippetData from_stream(std::istream& is, bool skip_data = false);
    static SnippetData from_stream(std::istream&           is,
                                   o_S7KDatagramIdentifier datagram_identifier,
                                   bool                    skip_data = false);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(SnippetData)

  private:
    explicit SnippetData(S7KDatagram header);
    void __read__(std::istream& is, bool skip_data = false);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
