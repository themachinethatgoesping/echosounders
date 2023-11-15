// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
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
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../simradraw_types.hpp"
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

    static SimradRawUnknown from_stream(std::istream& is, SimradRawDatagram header)
    {
        SimradRawUnknown datagram(std::move(header));

        if (datagram.get_length() > 12)
            datagram._raw_content.resize(size_t(datagram.get_length() - 12));
        else
            throw std::runtime_error("ERROR[SimradRawUnknown::from_stream]: _length is too small");

        is.read(datagram._raw_content.data(), datagram._raw_content.size());

        // verify the datagram is read correctly by reading the length field at the end
        datagram._verify_datagram_end(is);

        return datagram;
    }

    static SimradRawUnknown from_stream(std::istream& is)
    {
        return from_stream(is, SimradRawDatagram::from_stream(is));
    }

    static SimradRawUnknown from_stream(std::istream&              is,
                                     t_SimradRawDatagramIdentifier datagram_identifier)
    {
        return from_stream(is, SimradRawDatagram::from_stream(is, datagram_identifier));
    }

    void to_stream(std::ostream& os)
    {
        set_length(simradraw_long(12 + _raw_content.size()));
        SimradRawDatagram::to_stream(os);

        os.write(_raw_content.data(), _raw_content.size());
        os.write(reinterpret_cast<const char*>(&_length), sizeof(simradraw_long));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("SimradRawUnknown", float_precision);

        printer.append(SimradRawDatagram::__printer__(float_precision));

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(SimradRawUnknown)
};

} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
