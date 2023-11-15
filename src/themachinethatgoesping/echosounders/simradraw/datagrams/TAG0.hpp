// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
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
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

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
    static TAG0 from_stream(std::istream& is, SimradRawDatagram header)
    {
        TAG0 datagram(std::move(header));
        datagram._text.resize(datagram.get_length() - 12);
        is.read(datagram._text.data(), datagram._text.size());

        // verify the datagram is read correctly by reading the length field at the end
        datagram._verify_datagram_end(is);

        return datagram;
    }

    static TAG0 from_stream(std::istream& is)
    {
        return from_stream(is, SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::TAG0));
    }

    static TAG0 from_stream(std::istream& is, t_SimradRawDatagramIdentifier type)
    {
        if (type != t_SimradRawDatagramIdentifier::TAG0)
            throw std::runtime_error("TAG0::from_stream: wrong datagram type");

        return from_stream(is, SimradRawDatagram::from_stream(is, t_SimradRawDatagramIdentifier::TAG0));
    }

    void to_stream(std::ostream& os)
    {
        _length        = simradraw_long(12 + _text.size());
        _datagram_type = simradraw_long(t_SimradRawDatagramIdentifier::TAG0);
        SimradRawDatagram::to_stream(os);
        os.write(_text.data(), _text.size());
        os.write(reinterpret_cast<const char*>(&_length), sizeof(simradraw_long));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("Annotation datagram", float_precision);

        printer.append(SimradRawDatagram::__printer__(float_precision));

        printer.register_section("Annotation data");
        printer.register_string("Text", _text);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(TAG0)
};

}
}
}
}