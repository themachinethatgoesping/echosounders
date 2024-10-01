// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallunknown.doc.hpp"

// std includes
#include <string>
#include <unordered_map>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

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
    explicit KongsbergAllUnknown(KongsbergAllDatagram header)
        : KongsbergAllDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    KongsbergAllUnknown()  = default;
    ~KongsbergAllUnknown() = default;

    // ----- convenient member access ---
    const std::string& get_raw_content() const { return _raw_content; }
    uint8_t            get_etx() const { return _etx; }
    uint16_t           get_checksum() const { return _checksum; }

    void set_raw_content(const std::string& value) { _raw_content = value; }
    void set_etx(uint8_t value) { _etx = value; }
    void set_checksum(uint16_t value) { _checksum = value; }

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

    static KongsbergAllUnknown from_stream(std::istream& is, KongsbergAllDatagram header)
    {
        KongsbergAllUnknown datagram(std::move(header));

        if (datagram._bytes > 15)
            datagram._raw_content.resize(size_t(datagram._bytes - 15));
        else
            throw std::runtime_error("ERROR[KongsbergAllUnknown::from_stream]: _bytes is too small");

        // verify the datagram is read correctly by reading the length field at the end
        // datagram._verify_datagram_end(is);
        is.read(datagram._raw_content.data(), datagram._raw_content.size());
        is.read(reinterpret_cast<char*>(&(datagram._etx)), 3 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "KongsbergAllUnknown: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static KongsbergAllUnknown from_stream(std::istream& is)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is));
    }

    static KongsbergAllUnknown from_stream(std::istream&              is,
                                     t_KongsbergAllDatagramIdentifier datagram_identifier)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
    }

    void to_stream(std::ostream& os)
    {
        _bytes = uint32_t(15 + _raw_content.size());
        KongsbergAllDatagram::to_stream(os);

        os.write(_raw_content.data(), _raw_content.size());
        os.write(reinterpret_cast<char*>(&_etx), 3 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("KongsbergAllUnknown", float_precision, superscript_exponents);

        printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
        printer.register_section("datagram content");
        printer.register_value("raw data", _raw_content.size(), "bytes");
        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        // printer.register_value("checksum", _checksum, verify_checksum() ? "valid" : "invalid");
        printer.register_value("checksum", _checksum);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(KongsbergAllUnknown)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
