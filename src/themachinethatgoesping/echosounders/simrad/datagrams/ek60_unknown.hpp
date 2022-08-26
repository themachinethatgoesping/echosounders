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

#include "ek60_datagram.hpp"
#include "../ek60_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {

struct EK60_Unknown : public EK60_Datagram
{
    std::string raw_content;

  public:
    EK60_Unknown()          = default;
    ~EK60_Unknown() = default;

    // ----- operators -----
    bool operator==(const EK60_Unknown& other) const
    {
        return EK60_Datagram::operator==(other);
    }
    bool operator!=(const EK60_Unknown& other) const { return !operator==(other); }

    // ----- bitsery -----
    friend bitsery::Access;
    template<typename S>
    void serialize(S& s)
    {
        using themachinethatgoesping::tools::bitsery_helpers::is_input;
        using themachinethatgoesping::tools::bitsery_helpers::NoSizeVector;

        if (!is_input(s))
        {
            _Length = raw_content.size() + 12;
        }
        // serialize base class
        s.ext(*this, bitsery::ext::BaseClass<EK60_Datagram>{});

        //-12 bytes for _DatagramType, _LowDateTime and _HighDateTime
        s.ext1b(raw_content, NoSizeVector<std::string>{size_t(_Length - 12)}); 

        auto length_check = _Length;
        s.value4b(_Length);

        if (!is_input(s))
        {
            if (length_check != _Length)
            {
                throw std::runtime_error("length check failed");
            }
        }
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
