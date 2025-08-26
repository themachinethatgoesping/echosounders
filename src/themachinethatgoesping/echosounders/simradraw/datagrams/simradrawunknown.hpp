// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawunknown.doc.hpp"

// std includes
#include <string>
#include <unordered_map>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



#include "../types.hpp"
#include "simradrawdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

class SimradRawUnknown : public SimradRawDatagram
{
    // ----- datagram content -----
    std::string _raw_content; ///< raw content of the datagram as byte string;

  private:
    // ----- private constructors -----
    explicit SimradRawUnknown(SimradRawDatagram header)
        : SimradRawDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    SimradRawUnknown()  = default;
    ~SimradRawUnknown() = default;

    // ----- accessors -----
    const std::string& get_raw_content() const { return _raw_content; }
    void set_raw_content(std::string raw_content) { _raw_content = std::move(raw_content); }

    // ----- operators -----
    bool operator==(const SimradRawUnknown& other) const = default;

    static SimradRawUnknown from_stream(std::istream& is, SimradRawDatagram header);
    static SimradRawUnknown from_stream(std::istream& is);
    static SimradRawUnknown from_stream(std::istream&              is,
                                     t_SimradRawDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(SimradRawUnknown)
};

} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
