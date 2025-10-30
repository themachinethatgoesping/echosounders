// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kmallunknown.doc.hpp"

// std includes
#include <string>
#include <unordered_map>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "kmalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

class KMALLUnknown : public KMALLDatagram
{
    // ----- datagram content -----
    std::string _raw_content;

  private:
    // ----- private constructors -----
    explicit KMALLUnknown(KMALLDatagram header)
        : KMALLDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    KMALLUnknown()  = default;
    ~KMALLUnknown() = default;

    // ----- convenient member access ---
    const std::string& get_raw_content() const { return _raw_content; }

    void set_raw_content(const std::string& value);

    // ----- verify checksum -----

    // ----- operators -----
    bool operator==(const KMALLUnknown& other) const = default;

    static KMALLUnknown from_stream(std::istream& is, KMALLDatagram header);

    static KMALLUnknown from_stream(std::istream& is);

    static KMALLUnknown from_stream(std::istream&             is,
                                    o_KMALLDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(KMALLUnknown)
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
