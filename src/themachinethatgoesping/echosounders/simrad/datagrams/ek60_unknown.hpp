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

struct EK60_Unknown : public EK60_Datagram
{
    std::string raw_content;

  public:
    EK60_Unknown()  = default;
    ~EK60_Unknown() = default;

    // ----- operators -----
    bool operator==(const EK60_Unknown& other) const { return EK60_Datagram::operator==(other); }
    bool operator!=(const EK60_Unknown& other) const { return !operator==(other); }

    // ----- bitsery -----
    friend bitsery::Access;
    template<typename S>
    void serialize(S& s)
    {
        using themachinethatgoesping::tools::bitsery_helpers::is_input;
        using themachinethatgoesping::tools::bitsery_helpers::NoSizeVector;

        //if (!is_input(s))
        {
            _Length = raw_content.size() + 12;
        }
        // serialize base class
        s.ext(*this, bitsery::ext::BaseClass<EK60_Datagram>{});

        //-12 bytes for _DatagramType, _LowDateTime and _HighDateTime
        if (_Length > 12)
            s.ext1b(raw_content, NoSizeVector<std::string>{ size_t(_Length - 12) });
            //s.ext(raw_content, NoSizeVector<std::string>{ size_t(_Length - 12) });
        else
            throw std::runtime_error("ERROR[EK60_Unknown::serialize]: _Length is too small");

        ek60_long length_check = _Length;
        s.value4b(length_check);

        //if (!is_input(s))
        {
            if (length_check != _Length)
            {
                throw std::runtime_error("length check failed");
            }
        }
    }

    static EK60_Unknown from_stream(std::istream& is, t_EK60_DatagramType datagram_identifier)
    {
        EK60_Unknown datagram;
        // header
        is.read(reinterpret_cast<char*>(&datagram._Length), 4 * sizeof(ek60_long));

        if (datagram.get_datagram_identifier() != datagram_identifier)
            throw std::runtime_error(fmt::format("EK60_Unknown: Datagram identifier mismatch!"));

        if (datagram._Length > 12)
            datagram.raw_content.resize(size_t(datagram._Length - 12));
        else
            throw std::runtime_error("ERROR[EK60_Unknown::from_stream]: _Length is too small");

        is.read(datagram.raw_content.data(), datagram.raw_content.size());
        // for (size_t i = 0; i < datagram.raw_content.size(); ++i)
        // {
        //     is.read(reinterpret_cast<char*>(&datagram.raw_content[i]), 1);
        // }

        
        // verify that we are at the end of the datagram by reading the enclosing length field
        // This should be the same as _Length if everything is ok
        ek60_long length;
        is.read(reinterpret_cast<char*>(&length), sizeof(length));

        // (the packages are encapsulated by length)
        // if the lengths do not match the packages was not read correctly
        if (!is || length != datagram._Length)
        {
            throw std::runtime_error("ERROR[EK60_Unknown]: length mismatch");
        }

        return datagram;
    }

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("EK60_Unknown", float_precision);

        printer.append(EK60_Datagram::__printer__(float_precision));

        return printer;
    }

    // ----- class helper macros -----
    __BITSERY_DEFAULT_TOFROM_BINARY_FUNCTIONS__(EK60_Unknown)
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace datagrams
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
