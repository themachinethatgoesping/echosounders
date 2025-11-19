// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/cheave.doc.hpp"

// std includes
#include <cstdint>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "kmallmultibeamdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

/**
 * @brief Heave compatibility datagrams
 *
 * #CHE - Struct of compatibility heave sensor datagram.
 *
 * Used for backward compatibility with .all datagram format. Sent before #MWC (water column
 * datagram) datagram if compatibility mode is enabled. The multibeam datagram body is common with
 * the #MWC datagram.
 */
class CHeave : public KMALLMultibeamDatagram
{
    // delete unused functions
    // we derive from KMALLMultibeamDatagram, however #CHE does not have MPartition part
    // so this must be skipped
  private:
    // using KMALLMultibeamDatagram::__read_multibeamdatagram__;
    // using KMALLMultibeamDatagram::get_datagram_number;
    // using KMALLMultibeamDatagram::get_number_of_datagrams;
    // using KMALLMultibeamDatagram::set_datagram_number;
    // using KMALLMultibeamDatagram::set_number_of_datagrams;
    // using KMALLMultibeamDatagram::to_stream;
    // using KMALLMultibeamDatagram::__size;

  public:
    static constexpr auto DatagramIdentifier = t_KMALLDatagramIdentifier::C_HEAVE;

  protected:
    // 4-byte alignment can be a performance penalty for the doubles (they are packed unaligned now)
    // should not be a problem for this structure, the penalty would otherwise occur when reading
    // the memory and applying an extra copy to aligned memory on larger/compute intensive
    // structures this should be considered more carefully
#pragma pack(push, 4) // force 4-byte alignment
    struct Content
    {
        float heave_m; ///< in meters

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __size = 4; // size till _bytes_datagram_check

    uint32_t _bytes_datagram_check; ///< Each datagram ends with the size of the datagram for
                                    ///< integrity check

  public:
    // ----- public constructors -----
    CHeave();
    ~CHeave() = default;

    // ----- convenient data access -----
    float    get_heave_m() const { return _content.heave_m; }
    uint32_t get_bytes_datagram_check() const { return _bytes_datagram_check; }

    void set_heave_m(float val) { _content.heave_m = val; }
    void set_bytes_datagram_check(uint32_t val) { _bytes_datagram_check = val; }

    // ----- operators -----
    bool operator==(const CHeave& other) const = default;

    //----- to/from stream functions -----
    static CHeave from_stream(std::istream& is, const KMALLDatagram& header);

    static CHeave from_stream(std::istream& is, o_KMALLDatagramIdentifier datagram_identifier);

    static CHeave from_stream(std::istream& is);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(CHeave)

  private:
    explicit CHeave(const KMALLDatagram& header)
        : KMALLMultibeamDatagram(header)
    {
    }
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
