// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <string>
#include <unordered_map>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../ek60_types.hpp"
#include "ek60_datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {

/**
 * @brief Motion binary datagram (TAG0)
 * This datagram contains heave, roll, pitch and heading as float values.
 * Conveniently, these values can be used directly in themachinethatgoesping navigation processing
 * because they are defined in the default coordinate system / value range.
 *
 */
struct EK80_TAG0 : public EK60_Datagram
{
    // ----- datagram content -----
    std::string _Text; ///< _Text annotation string (e.g. interesting fish shoal in echogram)

  private:
    // ----- public constructors -----
    explicit EK80_TAG0(EK60_Datagram header)
        : EK60_Datagram(std::move(header))
    {
    }

  public:
    // ----- constructors -----
    EK80_TAG0()
        : EK60_Datagram(12, ek60_long(t_EK60_DatagramType::TAG0))
    {
    }
    EK80_TAG0(std::string text_anotation)
        : EK60_Datagram(12 + text_anotation.size(), ek60_long(t_EK60_DatagramType::TAG0))
        , _Text(std::move(text_anotation))
    {
    }
    ~EK80_TAG0() = default;

    // ----- operators -----
    bool operator==(const EK80_TAG0& other) const
    {
        return EK60_Datagram::operator==(other) && _Text == other._Text;
    }
    bool operator!=(const EK80_TAG0& other) const { return !operator==(other); }

    // ----- getter setter -----
    const std::string& get_text() const { return _Text; }
    void               set_text(std::string text) { _Text = std::move(text); }

    // ----- file I/O -----
    static EK80_TAG0 from_stream(std::istream& is, EK60_Datagram header)
    {
        EK80_TAG0 datagram(std::move(header));
        datagram._Text.resize(datagram._Length - 12);
        is.read(datagram._Text.data(), datagram._Text.size());

        // verify the datagram is read correctly by reading the length field at the end
        datagram._verify_datagram_end(is);

        return datagram;
    }

    static EK80_TAG0 from_stream(std::istream& is)
    {
        return from_stream(is, EK60_Datagram::from_stream(is, t_EK60_DatagramType::TAG0));
    }

    static EK80_TAG0 from_stream(std::istream& is, t_EK60_DatagramType type)
    {
        if (type != t_EK60_DatagramType::TAG0)
            throw std::runtime_error("EK80_TAG0::from_stream: wrong datagram type");

        return from_stream(is, EK60_Datagram::from_stream(is, t_EK60_DatagramType::TAG0));
    }

    void to_stream(std::ostream& os)
    {
        _Length       = 12 + _Text.size();
        _DatagramType = ek60_long(t_EK60_DatagramType::TAG0);
        EK60_Datagram::to_stream(os);
        os.write( _Text.data(), _Text.size());
        os.write(reinterpret_cast<const char*>(&_Length), sizeof(ek60_long));
    }

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("Annotation datagram", float_precision);

        printer.append(EK60_Datagram::__printer__(float_precision));

        printer.register_section("Annotation data");
        printer.register_string("Text", _Text);

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(EK80_TAG0)
};

}
}
}
}