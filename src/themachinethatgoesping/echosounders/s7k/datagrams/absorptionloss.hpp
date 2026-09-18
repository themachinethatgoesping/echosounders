// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/absorptionloss.doc.hpp"

// std includes
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "s7kdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

/**
 * @brief 7k record AbsorptionLoss
 */
class AbsorptionLoss : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::AbsorptionLoss;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        float _absorption_loss = 0.f; ///< absorption loss in dB/km

        uint32_t _checksum =
            0; ///< record checksum (last 4 bytes; see S7KDatagram, debugging only)

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content);

  public:
    AbsorptionLoss();
    ~AbsorptionLoss() = default;

    // ----- convenient member access -----
    float    get_absorption_loss() const;
    uint32_t get_checksum() const;

    void set_absorption_loss(float val);
    void set_checksum(uint32_t val);

    // ----- operators -----
    bool operator==(const AbsorptionLoss& other) const = default;

    //----- to/from stream functions -----
    static AbsorptionLoss from_stream(std::istream& is, S7KDatagram header);
    static AbsorptionLoss from_stream(std::istream& is);
    static AbsorptionLoss from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(AbsorptionLoss)

  private:
    explicit AbsorptionLoss(S7KDatagram header);
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
