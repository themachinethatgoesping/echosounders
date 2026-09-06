// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/attitude.doc.hpp"

// std includes
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "s7kdatagram.hpp"
#include "substructs/attitudesamplecontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

/**
 * @brief 7k record Attitude: This record will be output at the input motion sensor rate.
 */
class Attitude : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::Attitude;

  protected:
    substructs::AttitudeSampleContainer _attitudes; ///< attitude attitudes

    uint32_t _checksum = 0; ///< record checksum (last 4 bytes; see S7KDatagram, debugging only)

  public:
    Attitude() { set_datagram_identifier(DatagramIdentifier); }
    ~Attitude() = default;

    // ----- record type header access -----
    uint8_t get_number_of_attitudes() const
    {
        return uint8_t(_attitudes.get_number_of_attitudes());
    }
    uint32_t get_checksum() const { return _checksum; }
    void     set_checksum(uint32_t val) { _checksum = val; }

    // ----- substructure access -----
    const substructs::AttitudeSampleContainer& get_attitudes() const { return _attitudes; }
    substructs::AttitudeSampleContainer&       attitudes() { return _attitudes; }
    void set_attitudes(const substructs::AttitudeSampleContainer& attitudes)
    {
        _attitudes = attitudes;
    }

    // ----- operators -----
    bool operator==(const Attitude& other) const = default;

    //----- to/from stream functions -----
    static Attitude from_stream(std::istream& is, S7KDatagram header);
    static Attitude from_stream(std::istream& is);
    static Attitude from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(Attitude)

  private:
    explicit Attitude(S7KDatagram header)
        : S7KDatagram(std::move(header))
    {
    }
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
