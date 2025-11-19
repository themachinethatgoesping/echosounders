// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kmallmultibeamdatagram.doc.hpp"

// std includes
#include <cstdint>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "kmalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

/**
 * @brief Clock datagrams
 */
class KMALLMultibeamDatagram : public KMALLDatagram
{
  public:
    static constexpr auto   DatagramIdentifier = t_KMALLDatagramIdentifier::I_OP_RUNTIME;
    static constexpr size_t __size             = 4 * sizeof(uint16_t) + 8 * sizeof(uint8_t);
    static constexpr size_t __size_no_mpart    = 2 * sizeof(uint16_t) + 8 * sizeof(uint8_t);

  protected:
#pragma pack(push, 4) // force 4-byte alignment
    struct SCommon
    {
        // MPartition part (will be skipped if not used (#CHE datagram))
        uint16_t number_of_datagrams;
        uint16_t datagram_number;

        // Multibeam common part
        uint16_t bytes_content;            ///<  bytes of the datagram body (should be __size)
        uint16_t ping_count;               ///< Ping number incremented with each ping
        uint8_t  rx_fans_per_ping;         ///< Number of receive fans per ping
        uint8_t  rx_fan_index;             ///< Index of this receive fan
        uint8_t  swaths_per_ping;          ///< Number of swaths per ping
        uint8_t  swath_along_position;     ///< Swath along position (0 is aftmost swath)
        uint8_t  tx_transducer_ind;        ///< Transmitter used in this ping (0 is first)
        uint8_t  rx_transducer_ind;        ///< Receive used in this ping (0 is first)
        uint8_t  number_of_rx_transducers; ///< Number of receive transducers
        uint8_t  algorithm_type;           ///< Algorithm type used for this ping

        bool operator==(const SCommon& other) const = default;
    } _scommon;
#pragma pack(pop)

  public:
    // ----- public constructors -----
    KMALLMultibeamDatagram()  = default;
    ~KMALLMultibeamDatagram() = default;

    // ----- convenient data access -----
    // Getters
    uint16_t get_number_of_datagrams() const { return _scommon.number_of_datagrams; }
    uint16_t get_datagram_number() const { return _scommon.datagram_number; }

    uint16_t get_bytes_content() const { return _scommon.bytes_content; }
    uint16_t get_ping_count() const { return _scommon.ping_count; }
    uint8_t  get_rx_fans_per_ping() const { return _scommon.rx_fans_per_ping; }
    uint8_t  get_rx_fan_index() const { return _scommon.rx_fan_index; }
    uint8_t  get_swaths_per_ping() const { return _scommon.swaths_per_ping; }
    uint8_t  get_swath_along_position() const { return _scommon.swath_along_position; }
    uint8_t  get_tx_transducer_ind() const { return _scommon.tx_transducer_ind; }
    uint8_t  get_rx_transducer_ind() const { return _scommon.rx_transducer_ind; }
    uint8_t  get_number_of_rx_transducers() const { return _scommon.number_of_rx_transducers; }
    uint8_t  get_algorithm_type() const { return _scommon.algorithm_type; }

    // Setters
    void set_number_of_datagrams(uint16_t value) { _scommon.number_of_datagrams = value; }
    void set_datagram_number(uint16_t value) { _scommon.datagram_number = value; }

    void set_bytes_content(uint16_t value) { _scommon.bytes_content = value; }
    void set_ping_count(uint16_t value) { _scommon.ping_count = value; }
    void set_rx_fans_per_ping(uint8_t value) { _scommon.rx_fans_per_ping = value; }
    void set_rx_fan_index(uint8_t value) { _scommon.rx_fan_index = value; }
    void set_swaths_per_ping(uint8_t value) { _scommon.swaths_per_ping = value; }
    void set_swath_along_position(uint8_t value) { _scommon.swath_along_position = value; }
    void set_tx_transducer_ind(uint8_t value) { _scommon.tx_transducer_ind = value; }
    void set_rx_transducer_ind(uint8_t value) { _scommon.rx_transducer_ind = value; }
    void set_number_of_rx_transducers(uint8_t value) { _scommon.number_of_rx_transducers = value; }
    void set_algorithm_type(uint8_t value) { _scommon.algorithm_type = value; }

    // ----- processed data access -----

    // ----- operators -----
    bool operator==(const KMALLMultibeamDatagram& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents,
                                                  bool         mpart = true) const;

  protected:
    explicit KMALLMultibeamDatagram(const KMALLDatagram& header)
        : KMALLDatagram(header)
    {
    }
    inline void __read_multibeamdatagram__(std::istream& is)
    {
        is.read(reinterpret_cast<char*>(&_scommon), sizeof(SCommon));
    }
    inline void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&_scommon), sizeof(SCommon));
    }
    inline void __read_multibeamdatagram_no_mpart__(std::istream& is)
    {
        is.read(reinterpret_cast<char*>(&_scommon.bytes_content), __size_no_mpart);
    }
    inline void to_stream_no_mpart(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&_scommon.bytes_content), __size_no_mpart);
    }
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
