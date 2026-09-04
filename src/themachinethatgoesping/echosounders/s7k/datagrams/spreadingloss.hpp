// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/spreadingloss.doc.hpp"

// std includes
#include <cstdint>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "s7kdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

/**
 * @brief 7k record SpreadingLoss
 */
class SpreadingLoss : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::SpreadingLoss;

  protected:
#pragma pack(push, 1)
    struct Content
    {
        float _spreading_loss = 0.f; ///< spreading loss in dB (0-60)

        uint32_t _checksum =
            0; ///< record checksum (last 4 bytes; see S7KDatagram, debugging only)

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content);

  public:
    SpreadingLoss()
        : _content{}
    {
        set_datagram_identifier(DatagramIdentifier);
    }
    ~SpreadingLoss() = default;

    // ----- convenient member access -----
    float    get_spreading_loss() const { return _content._spreading_loss; }
    uint32_t get_checksum() const { return _content._checksum; }

    void set_spreading_loss(float val) { _content._spreading_loss = val; }
    void set_checksum(uint32_t val) { _content._checksum = val; }

    // ----- operators -----
    bool operator==(const SpreadingLoss& other) const = default;

    //----- to/from stream functions -----
    static SpreadingLoss from_stream(std::istream& is, S7KDatagram header);
    static SpreadingLoss from_stream(std::istream& is);
    static SpreadingLoss from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(SpreadingLoss)

  private:
    explicit SpreadingLoss(S7KDatagram header)
        : S7KDatagram(std::move(header))
    {
    }
    void __read__(std::istream& is)
    {
        is.read(reinterpret_cast<char*>(&_content), __content_size);
    }
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
