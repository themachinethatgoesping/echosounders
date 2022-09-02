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

// bitsery includes
#include <bitsery/ext/inheritance.h>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelpers/bitsery.hpp>
#include <themachinethatgoesping/tools/classhelpers/bitsery_helpers/nosizevector.hpp>
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../ek60_types.hpp"
#include "ek60_datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {

// Binary Datagram: MRU0
struct EK80_MRU0 : public EK60_Datagram
{
    // ----- datagram content -----
    ek60_float _Heave; // unit?
    ek60_float _Roll; // unit?
    ek60_float _Pitch; // unit?
    ek60_float _Heading; // unit?

  private:
    // ----- public constructors -----
    explicit EK80_MRU0(EK60_Datagram&& header)
        : EK60_Datagram(std::move(header))
    {
    }

  public:
    // ----- constructors -----
    EK80_MRU0()
    {
        _Length       = 12 + 4 * sizeof(ek60_float);
        _DatagramType = ek60_long(t_EK60_DatagramType::MRU0);
    }
    ~EK80_MRU0() = default;

    // ----- operators -----
    bool operator==(const EK80_MRU0& other) const
    {
        return EK60_Datagram::operator==(other) && _Heave == other._Heave && _Roll == other._Roll &&
               _Pitch == other._Pitch && _Heading == other._Heading;
    }
    bool operator!=(const EK80_MRU0& other) const { return !operator==(other); }

    // ----- file I/O -----
    static EK80_MRU0 from_stream(std::istream& is, EK60_Datagram&& header)
    {
        EK80_MRU0 datagram(std::move(header));
        is.read(reinterpret_cast<char*>(&datagram._Heave), 4 * sizeof(ek60_float));
        return datagram;
    }

    static EK80_MRU0 from_stream(std::istream& is)
    {
        return from_stream(is,
                           std::move(EK60_Datagram::from_stream(is, t_EK60_DatagramType::MRU0)));
    }

    static EK80_MRU0 from_stream(std::istream& is, t_EK60_DatagramType type)
    {
        if (type != t_EK60_DatagramType::MRU0)
            throw std::runtime_error("EK80_MRU0::from_stream: wrong datagram type");

        return from_stream(is, std::move(EK60_Datagram::from_stream(is, t_EK60_DatagramType::MRU0)));
    }

    void to_stream(std::ostream& os)
    {
        _Length       = 12 + 4 * sizeof(ek60_float);
        _DatagramType = ek60_long(t_EK60_DatagramType::MRU0);
        EK60_Datagram::to_stream(os);
        os.write(reinterpret_cast<const char*>(&_Heave), 4 * sizeof(ek60_float));
    }

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("Motion binary datagram", float_precision);

        printer.append(EK60_Datagram::__printer__(float_precision));

        printer.register_section("Data");
        printer.register_value("Heave", _Heave, "m");
        printer.register_value("Roll", _Roll, "°");
        printer.register_value("Pitch", _Pitch, "°");
        printer.register_value("Heading", _Heading, "°");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(EK80_MRU0)
};

}
}
}
}