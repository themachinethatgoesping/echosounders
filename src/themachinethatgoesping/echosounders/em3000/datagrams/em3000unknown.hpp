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
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../em3000_types.hpp"
#include "em3000datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {

struct EM3000Unknown : public EM3000Datagram
{
    // ----- datagram content -----
    std::string raw_content;

  private:
    // ----- private constructors -----
    explicit EM3000Unknown(EM3000Datagram header)
        : EM3000Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    EM3000Unknown()  = default;
    ~EM3000Unknown() = default;

    // ----- operators -----
    bool operator==(const EM3000Unknown& other) const
    {
        return EM3000Datagram::operator==(other) && raw_content == other.raw_content;
    }
    bool operator!=(const EM3000Unknown& other) const { return !operator==(other); }

    static EM3000Unknown from_stream(std::istream& is, EM3000Datagram header)
    {
        EM3000Unknown datagram(std::move(header));

        if (datagram._Length > 12)
            datagram.raw_content.resize(size_t(datagram._Length - 12));
        else
            throw std::runtime_error("ERROR[EM3000Unknown::from_stream]: _Length is too small");

        is.read(datagram.raw_content.data(), datagram.raw_content.size());

        // verify the datagram is read correctly by reading the length field at the end
        datagram._verify_datagram_end(is);

        return datagram;
    }

    static EM3000Unknown from_stream(std::istream& is)
    {
        return from_stream(is, EM3000Datagram::from_stream(is));
    }

    static EM3000Unknown from_stream(std::istream&              is,
                                     t_EM3000DatagramIdentifier datagram_identifier)
    {
        return from_stream(is, std::move(EM3000Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os)
    {
        _Length = em3000_long(12 + raw_content.size());
        EM3000Datagram::to_stream(os);

        os.write(raw_content.data(), raw_content.size());
        os.write(reinterpret_cast<const char*>(&_Length), sizeof(em3000_long));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("EM3000Unknown", float_precision);

        printer.append(EM3000Datagram::__printer__(float_precision));

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(EM3000Unknown)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
