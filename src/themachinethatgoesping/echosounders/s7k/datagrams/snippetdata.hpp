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
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content); // 46

    substructs::SnippetDataBeamContainer _beams;      ///< per-beam snippet descriptors
    substructs::SnippetDataAmplitudes    _amplitudes; ///< per-beam intensity samples

  public:
    SnippetData()  = default;
    ~SnippetData() = default;

    // ----- record type header access -----
    uint64_t get_serial_number() const { return _content.serial_number; }
    uint32_t get_ping_number() const { return _content.ping_number; }
    uint16_t get_multi_ping() const { return _content.multi_ping; }
    uint16_t get_number_beams() const { return _content.number_beams; }
    uint8_t  get_error_flag() const { return _content.error_flag; }
    uint8_t  get_control_flags() const { return _content.control_flags; }
    uint32_t get_flags() const { return _content.flags; }

    void set_serial_number(uint64_t val) { _content.serial_number = val; }
    void set_ping_number(uint32_t val) { _content.ping_number = val; }
    void set_multi_ping(uint16_t val) { _content.multi_ping = val; }
    void set_number_beams(uint16_t val) { _content.number_beams = val; }
    void set_error_flag(uint8_t val) { _content.error_flag = val; }
    void set_control_flags(uint8_t val) { _content.control_flags = val; }
    void set_flags(uint32_t val) { _content.flags = val; }

    /// true if the intensity samples are stored as 32-bit values (flags bit 0)
    bool get_samples_are_32bit() const { return (_content.flags & 0x1) != 0; }

    // ----- substructure access -----
    const substructs::SnippetDataBeamContainer& get_beams() const { return _beams; }
    substructs::SnippetDataBeamContainer&       beams() { return _beams; }
    void set_beams(const substructs::SnippetDataBeamContainer& beams) { _beams = beams; }

    const substructs::SnippetDataAmplitudes& get_amplitudes() const { return _amplitudes; }
    substructs::SnippetDataAmplitudes&       amplitudes() { return _amplitudes; }
    void set_amplitudes(const substructs::SnippetDataAmplitudes& amplitudes)
    {
        _amplitudes = amplitudes;
    }

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
    explicit SnippetData(S7KDatagram header)
        : S7KDatagram(std::move(header))
    {
    }
    void __read__(std::istream& is, bool skip_data = false);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
