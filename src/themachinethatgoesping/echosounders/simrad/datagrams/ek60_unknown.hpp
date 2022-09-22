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
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelpers/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../ek60_types.hpp"
#include "ek60_datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {

struct EK60_Unknown : public EK60_Datagram
{
    // ----- datagram content -----
    std::string raw_content;

  private:
    // ----- private constructors -----
    explicit EK60_Unknown(EK60_Datagram header)
        : EK60_Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    EK60_Unknown()  = default;
    ~EK60_Unknown() = default;

    // ----- operators -----
    bool operator==(const EK60_Unknown& other) const
    {
        return EK60_Datagram::operator==(other) && raw_content == other.raw_content;
    }
    bool operator!=(const EK60_Unknown& other) const { return !operator==(other); }

    static EK60_Unknown from_stream(std::istream& is, EK60_Datagram header)
    {
        EK60_Unknown datagram(std::move(header));

        if (datagram._Length > 12)
            datagram.raw_content.resize(size_t(datagram._Length - 12));
        else
            throw std::runtime_error("ERROR[EK60_Unknown::from_stream]: _Length is too small");

        is.read(datagram.raw_content.data(), datagram.raw_content.size());

        // verify the datagram is read correctly by reading the length field at the end
        datagram._verify_datagram_end(is);

        return datagram;
    }

    static EK60_Unknown from_stream(std::istream& is)
    {
        return from_stream(is, EK60_Datagram::from_stream(is));
    }

    static EK60_Unknown from_stream(std::istream& is, t_EK60_DatagramType datagram_identifier)
    {
        return from_stream(is, std::move(EK60_Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os)
    {
        _Length = 12 + raw_content.size();
        EK60_Datagram::to_stream(os);

        os.write(raw_content.data(), raw_content.size());
        os.write(reinterpret_cast<const char*>(&_Length), sizeof(ek60_long));
    }

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("EK60_Unknown", float_precision);

        printer.append(EK60_Datagram::__printer__(float_precision));

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(EK60_Unknown)
};

} // namespace datagrams
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
