// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kunknown.doc.hpp"

// std includes
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "s7kdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

/**
 * @brief A generic 7k datagram that stores the raw (unparsed) content of a record.
 *
 * This is used to represent any 7k record whose specific record type is not (yet) implemented.
 * It holds the DRF header (via the S7KDatagram base) and the raw bytes of the record content
 * (record type header + record data + optional data + checksum).
 */
class S7KUnknown : public S7KDatagram
{
    // ----- datagram content -----
    std::string _raw_content; ///< raw bytes of the record following the DRF header

  private:
    // ----- private constructors -----
    explicit S7KUnknown(S7KDatagram header)
        : S7KDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    S7KUnknown()           = default;
    ~S7KUnknown() override = default;

    // ----- convenient member access -----
    const std::string& get_raw_content() const { return _raw_content; }

    void set_raw_content(const std::string& value)
    {
        _raw_content = value;
        _size        = uint32_t(_raw_content.size() + __size);
    }

    // ----- operators -----
    bool operator==(const S7KUnknown& other) const = default;

    static S7KUnknown from_stream(std::istream& is, S7KDatagram header);

    static S7KUnknown from_stream(std::istream& is);

    static S7KUnknown from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(S7KUnknown)
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
