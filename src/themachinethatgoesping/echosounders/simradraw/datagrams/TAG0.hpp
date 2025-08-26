// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/TAG0.doc.hpp"

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

/**
 * @brief Motion binary datagram (TAG0)
 * This datagram contains heave, roll, pitch and heading as float values.
 * Conveniently, these values can be used directly in themachinethatgoesping navigation processing
 * because they are defined in the default coordinate system / value range.
 *
 */
class TAG0 : public SimradRawDatagram
{
    // ----- datagram content -----
    std::string _text; ///< _text annotation string (e.g. interesting fish shoal in echogram)

  private:
    // ----- public constructors -----
    explicit TAG0(SimradRawDatagram header)
        : SimradRawDatagram(std::move(header))
    {
    }

  public:
    // ----- constructors -----
    TAG0()
        : SimradRawDatagram(12, simradraw_long(t_SimradRawDatagramIdentifier::TAG0))
    {
    }
    TAG0(std::string text_anotation)
        : SimradRawDatagram(simradraw_long(12 + text_anotation.size()),
                         simradraw_long(t_SimradRawDatagramIdentifier::TAG0))
        , _text(std::move(text_anotation))
    {
    }
    ~TAG0() = default;

    // ----- operators -----
    bool operator==(const TAG0& other) const = default;

    // ----- getter setter -----
    const std::string& get_text() const { return _text; }
    void               set_text(std::string text) { _text = std::move(text); }

    // ----- file I/O -----
    static TAG0 from_stream(std::istream& is, SimradRawDatagram header);
    static TAG0 from_stream(std::istream& is);
    static TAG0 from_stream(std::istream& is, t_SimradRawDatagramIdentifier type);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(TAG0)
};

}
}
}
}