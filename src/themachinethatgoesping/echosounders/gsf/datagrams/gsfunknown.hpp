// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/gsfunknown.doc.hpp"

// std includes
#include <string>
#include <unordered_map>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



#include "../types.hpp"
#include "gsfdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace gsf {
namespace datagrams {

class GSFUnknown : public GSFDatagram
{
    // ----- datagram content -----
    std::string _raw_content;

  private:
    // ----- private constructors -----
    explicit GSFUnknown(GSFDatagram header)
        : GSFDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    GSFUnknown()  = default;
    ~GSFUnknown() = default;

    // ----- convenient member access ---
    const std::string& get_raw_content() const { return _raw_content; }

    void set_raw_content(const std::string& value)
    {
        _raw_content  = value;
        _size_of_data = _raw_content.size();
        _checksum     = std::nullopt;
    }

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
    bool operator==(const GSFUnknown& other) const = default;

    static GSFUnknown from_stream(std::istream& is, GSFDatagram header)
    {
        GSFUnknown datagram(std::move(header));

        datagram._raw_content.resize(size_t(datagram._size_of_data));

        // verify the datagram is read correctly by reading the length field at the end
        is.read(datagram._raw_content.data(), datagram._raw_content.size());

        return datagram;
    }

    static GSFUnknown from_stream(std::istream& is)
    {
        return from_stream(is, GSFDatagram::from_stream(is));
    }

    static GSFUnknown from_stream(std::istream& is, t_GSFDatagramIdentifier datagram_identifier)
    {
        return from_stream(is, GSFDatagram::from_stream(is, datagram_identifier));
    }

    void to_stream(std::ostream& os)
    {
        GSFDatagram::to_stream(os);

        os.write(_raw_content.data(), _raw_content.size());
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "GSFUnknown", float_precision, superscript_exponents);

        printer.append(GSFDatagram::__printer__(float_precision, superscript_exponents));
        printer.register_section("datagram content");
        printer.register_value("raw data", _raw_content.size(), "bytes");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(GSFUnknown)
};

} // namespace datagrams
} // namespace gsf
} // namespace echosounders
} // namespace themachinethatgoesping
