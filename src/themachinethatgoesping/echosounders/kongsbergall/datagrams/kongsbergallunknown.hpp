// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallunknown.doc.hpp"

// std includes
#include <cstdint>
#include <iosfwd>
#include <string>
#include <unordered_map>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

class KongsbergAllUnknown : public KongsbergAllDatagram
{
    // ----- datagram content -----
    std::string _raw_content;

    uint8_t  _etx      = 0x03; // (end identifier)
    uint16_t _checksum = 0;

  private:
    // ----- private constructors -----
    explicit KongsbergAllUnknown(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    KongsbergAllUnknown()  = default;
    ~KongsbergAllUnknown() = default;

    // ----- convenient member access ---
    const std::string& get_raw_content() const;
    uint8_t            get_etx() const;
    uint16_t           get_checksum() const;

    void set_raw_content(const std::string& value);
    void set_etx(uint8_t value);
    void set_checksum(uint16_t value);

    // ----- verify checksum -----
    // TODO: how is this computed?
    // uint16_t compute_checksum() const
    // {
    //     // sum over all bytes except the checksum bytes
    //     uint16_t sum          = 0;
    //     uint8_t* header_bytes = (uint8_t*)&_datagram_identifier;

    //     // bytewise sum over bytes of the header (after stx)
    //     for (size_t i = 0; i < 11; ++i)
    //         sum += uint8_t(header_bytes[i]);

    //     // bytewise sum over raw content
    //     for (size_t i = 0; i < _raw_content.size(); ++i)
    //         sum += uint8_t(_raw_content[i]);

    //     return sum;
    // }

    // bool verify_checksum() const { return _checksum == compute_checksum(); }

    // ----- operators -----
    bool operator==(const KongsbergAllUnknown& other) const = default;

    static KongsbergAllUnknown from_stream(std::istream& is, KongsbergAllDatagram header);

    static KongsbergAllUnknown from_stream(std::istream& is);

    static KongsbergAllUnknown from_stream(std::istream&              is,
                                           t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(KongsbergAllUnknown)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
