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
 * @brief 7k record Attitude: a set of attitude samples (roll, pitch, heave, heading) with a
 * time offset relative to the record timestamp. Used by modern systems (e.g. R2Sonic) instead of
 * separate 1012/1013 records.
 */
class Attitude : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::Attitude;

  protected:
    substructs::AttitudeSampleContainer _samples; ///< attitude samples

  public:
    Attitude()  = default;
    ~Attitude() = default;

    // ----- record type header access -----
    uint8_t get_number_of_samples() const { return uint8_t(_samples.get_number_of_samples()); }

    // ----- substructure access -----
    const substructs::AttitudeSampleContainer& get_samples() const { return _samples; }
    substructs::AttitudeSampleContainer&        samples() { return _samples; }
    void set_samples(const substructs::AttitudeSampleContainer& samples) { _samples = samples; }

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
