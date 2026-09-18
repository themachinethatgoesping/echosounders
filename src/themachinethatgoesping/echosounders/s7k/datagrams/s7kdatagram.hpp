// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kdatagram.doc.hpp"

// std includes
#include <iostream>
#include <string>
#include <string_view>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

/**
 * @brief The Data Record Frame (DRF) is the header/wrapper that precedes every 7k record.
 *
 * This class implements the fixed 64-byte DRF header as defined in the "7k Data Format
 * Definition" specification (v3.12, April 2020), Table 5. All multibyte fields are stored in
 * little-endian byte order. A record consists of: DRF header + record type header (RTH) +
 * (optional) record data + (optional) optional data + checksum.
 */
class S7KDatagram
{
  public:
    using t_DatagramIdentifier = t_S7KDatagramIdentifier;
    using o_DatagramIdentifier = o_S7KDatagramIdentifier;

    static constexpr uint32_t SYNC_PATTERN = 0x0000FFFF; ///< 7k data record frame sync pattern
    static constexpr size_t   __size = 64; ///< size of the DRF header in bytes (sizeof is incorrect
                                           ///< due to virtual functions)

  protected:
    // ----- Data Record Frame fields (in file order, little-endian, naturally aligned) -----
    // The members are read as one contiguous 64-byte block, thus their declaration order and
    // (default-zero) natural alignment must exactly match the DRF byte layout.
    uint16_t _protocol_version = 0;         ///< offset 0: protocol version of this frame (e.g. 5)
    uint16_t _offset           = 0;         ///< offset 2: bytes from start of sync pattern to RTH
    uint32_t _sync_pattern     = 0;         ///< offset 4: 0x0000FFFF
    uint32_t _size             = 0;         ///< offset 8: total record size (version field to end
                                            ///< of checksum, including embedded data)
    uint32_t _optional_data_offset     = 0; ///< offset 12: byte offset to optional data (0 = none)
    uint32_t _optional_data_identifier = 0; ///< offset 16: identifier for the optional data field
    // 7KTIME (offset 20, u8 * 10)
    uint16_t _year    = 0;   ///< offset 20: UTC year (all four digits, e.g. 2023)
    uint16_t _day     = 0;   ///< offset 22: UTC day of year (1-366)
    float    _seconds = 0.f; ///< offset 24: UTC seconds (0.0 - 60.0)
    uint8_t  _hours   = 0;   ///< offset 28: UTC hours (0-23)
    uint8_t  _minutes = 0;   ///< offset 29: UTC minutes (0-59)
    // ----
    uint16_t             _record_version = 0; ///< offset 30: record version (currently 1)
    o_DatagramIdentifier _record_type_identifier =
        t_S7KDatagramIdentifier::unspecified; ///< offset 32: record type identifier
    uint32_t _device_identifier = 0;          ///< offset 36: device identifier
    uint16_t _reserved_1        = 0;          ///< offset 40: reserved
    uint16_t _system_enumerator = 0; ///< offset 42: enumerator differentiating devices with same id
    uint32_t _reserved_2        = 0; ///< offset 44: reserved
    uint16_t _flags = 0; ///< offset 48: bit field (bit 0: checksum valid, bit 15: recorded data)
    uint16_t _reserved_3                                  = 0; ///< offset 50: reserved
    uint32_t _reserved_4                                  = 0; ///< offset 52: reserved
    uint32_t _total_records_in_fragmented_data_record_set = 0; ///< offset 56: always 0 in files
    uint32_t _fragment_number                             = 0; ///< offset 60: always 0 in files

  public:
    S7KDatagram()                              = default;
    virtual ~S7KDatagram()                     = default;
    S7KDatagram(const S7KDatagram& other)      = default;
    S7KDatagram(S7KDatagram&& other)           = default;
    S7KDatagram& operator=(const S7KDatagram&) = default;
    S7KDatagram& operator=(S7KDatagram&&)      = default;

    /**
     * @brief Skip the data section of the datagram (position stream at the next DRF).
     * @param is Input stream, positioned directly after the DRF header.
     */
    void skip(std::istream& is) const;

    // ----- interface -----
    void                 set_datagram_identifier(o_DatagramIdentifier datagram_identifier);
    o_DatagramIdentifier get_datagram_identifier() const;

    /**
     * @brief Get the record timestamp as unix time (seconds since 1970-01-01 UTC).
     * @return Unix timestamp, or NaN if no time is available (all 7KTIME fields zero).
     */
    virtual double get_timestamp() const;

    /**
     * @brief Get the timestamp as a formatted date string.
     * @param fractionalSecondsDigits number of fractional-second digits
     * @param format date format string
     * @return Formatted date string.
     */
    std::string get_date_string(unsigned int       fractionalSecondsDigits = 2,
                                const std::string& format = "%z__%d-%m-%Y__%H:%M:%S") const;

    // ----- convenient member access -----
    uint16_t get_protocol_version() const;
    uint16_t get_offset() const;
    uint32_t get_sync_pattern() const;
    uint32_t get_size() const;
    uint32_t get_optional_data_offset() const;
    uint32_t get_optional_data_identifier() const;
    uint16_t get_year() const;
    uint16_t get_day() const;
    float    get_seconds() const;
    uint8_t  get_hours() const;
    uint8_t  get_minutes() const;
    uint16_t get_record_version() const;
    uint32_t get_record_type_identifier() const;
    uint32_t get_device_identifier() const;
    uint16_t get_system_enumerator() const;
    uint16_t get_flags() const;
    uint32_t get_total_records_in_fragmented_data_record_set() const;
    uint32_t get_fragment_number() const;

    void set_protocol_version(uint16_t v);
    void set_offset(uint16_t v);
    void set_sync_pattern(uint32_t v);
    void set_size(uint32_t v);
    void set_optional_data_offset(uint32_t v);
    void set_optional_data_identifier(uint32_t v);
    void set_year(uint16_t v);
    void set_day(uint16_t v);
    void set_seconds(float v);
    void set_hours(uint8_t v);
    void set_minutes(uint8_t v);
    void set_record_version(uint16_t v);
    void set_device_identifier(uint32_t v);
    void set_system_enumerator(uint16_t v);
    void set_flags(uint16_t v);

    // ----- processed -----
    /**
     * @brief Test if the flags field indicates a valid checksum (bit 0).
     * 
     */
    bool get_flag_checksum_is_valued() const;

    /**
     * @brief Test if the flags field indicates live or recorded data (bit 15).
     * 
     */
    bool get_flag_data_live_or_recorded() const;

    /**
     * @brief Test if the DRF sync pattern is valid.
     */
    bool drf_sync_pattern_is_valid() const;

    // ----- helper -----
    /**
     * @brief Number of bytes of the record following the DRF header (RTH + data + checksum).
     */
    size_t compute_size_content() const;

    // ----- checksum (debugging only) -----
    // Every 7k record ends with a 4-byte checksum (see 7k Data Format Definition, Table 5). The
    // checksum is the sum of all byte values (treated as unsigned) from the start of the record
    // (protocol version field) up to - but not including - the trailing 4-byte checksum field. It
    // is NOT verified or (re)computed while reading or writing; these helpers only exist to check a
    // stored checksum against the record content for debugging.

    /**
     * @brief Compute the 7k record checksum of a serialized datagram (debugging aid).
     *
     * Pass the full serialized record (e.g. the result of to_binary()). The last four bytes are
     * treated as the stored checksum and are excluded from the sum.
     *
     * @param buffer Serialized record bytes (DRF + RTH + data + checksum).
     * @return Computed 32-bit checksum (sum of all bytes except the trailing four).
     */
    static uint32_t compute_checksum(std::string_view buffer);

    /**
     * @brief Read the stored checksum (last four bytes) from a serialized record buffer.
     *
     * @param buffer Serialized record bytes (DRF + RTH + data + checksum).
     * @return The stored checksum, or 0 if the buffer is too small.
     */
    static uint32_t read_checksum(std::string_view buffer);

    /**
     * @brief Check whether the stored checksum of a serialized record matches its computed
     * checksum (debugging aid).
     *
     * @param buffer Serialized record bytes (DRF + RTH + data + checksum).
     * @return true if compute_checksum(buffer) == read_checksum(buffer).
     */
    static bool test_checksum_is_correct(std::string_view buffer);

    // ----- operators -----
    bool operator==(const S7KDatagram& other) const = default;

    static S7KDatagram from_stream(std::istream& is);

    static S7KDatagram from_stream(std::istream&              is,
                                   const o_DatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(S7KDatagram)

  protected:
    void        __s7kdatagram_read__(std::istream& is);
    static void __check_datagram_identifier__(const o_DatagramIdentifier actual,
                                              const o_DatagramIdentifier expected);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
