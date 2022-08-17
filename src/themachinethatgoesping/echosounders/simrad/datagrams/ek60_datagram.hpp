// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelpers/bitsery.hpp>
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>

#include "../ek60_types.hpp"
//#include "../misc/DateTime.h"
//#include "DSMToolsLib/HelperFunctions.h"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {

struct EK60_Datagram
{
    ek60_long _Length;       ///< Raw: Length of the datagram in bytes
    ek60_long _DatagramType; ///< Raw: Datagram type as
    ek60_long _LowDateTime; ///< Raw: Low part of Windows NT FILETIME (100ns ticks since 1601-01-01)
    ek60_long
        _HighDateTime; ///< Raw: High part of Windows NT FILETIME (100ns ticks since 1601-01-01)

  public:
    EK60_Datagram()          = default;
    virtual ~EK60_Datagram() = default;

    void skip(std::istream& is) const
    {
        // _Length is the length the datagram that is enclosed by _Length
        const static ek60_long tmp = sizeof(ek60_long)*3;

        is.seekg(_Length - tmp, std::ios::cur);

        // verify that we are at the end of the datagram
        ek60_long length;
        is.read(reinterpret_cast<char*>(&length), sizeof(length));
        
        // (the packages are encapsulated by length)
        // if the lengths do not match the packages was not read correctly
        if (length != _Length)
        {
            throw std::runtime_error("ERROR[EK60_Datagram::skip]: length mismatch");
        }
    }

    ek60_long get_datagram_type() const
    {
        return _DatagramType;
    }

    static std::string DatagramTypeAsString(const ek60_long& value)
	{
		std::string valueAsString;
        valueAsString.resize(sizeof(value));
        memcpy(&valueAsString[0], &value, sizeof(value));

		return valueAsString;
	}

    static ek60_long StringToDatagramType(const std::string& value)
    {
        ek60_long valueAsLong;
        memcpy(&valueAsLong, &value[0], sizeof(valueAsLong));
        return valueAsLong;
    }

    // ----- operators -----
    bool operator==(const EK60_Datagram& other) const
    {
        return _Length == other._Length && _DatagramType == other._DatagramType &&
               _LowDateTime == other._LowDateTime && _HighDateTime == other._HighDateTime;
    }
    bool operator!=(const EK60_Datagram& other) const { return !operator==(other); }

    // ----- bitsery -----
    friend bitsery::Access;
    template<typename S>
    void serialize(S& s)
    {
        s.value4b(_Length);
        s.value4b(_DatagramType);
        s.value4b(_LowDateTime);
        s.value4b(_HighDateTime);
    }

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("Ek60_Datagram", float_precision);

        printer.register_value("Length", _Length, "bytes");
        //printer.register_value("_DatagramType", _DatagramType, "raw value");
        printer.register_string("DatagramType", DatagramTypeAsString(_DatagramType));
        printer.register_value("DatagramType1", _DatagramType, "raw value");
        printer.register_value("DatagramType2", StringToDatagramType(DatagramTypeAsString(_DatagramType)), "raw value");
        printer.register_value("_LowDateTime", _LowDateTime, "raw value");
        printer.register_value("_HighDateTime", _HighDateTime, "raw value");

        return printer;
    }


    // ----- class helper macros -----
    __BITSERY_DEFAULT_TOFROM_BINARY_FUNCTIONS__(EK60_Datagram)
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace datagrams
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
