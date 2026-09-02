//sourcehash: fc0a7a69c5ce17668afe9bafafe4a20fb0233ec15fdf4b8edeb6adda76d635b9

/*
  This file contains docstrings for use in the Python bindings.
  Do not edit! They were automatically extracted by pybind11_mkdoc.

  This is a modified version which allows for more than 8 arguments and includes def-guard
 */

#pragma once

#ifndef __DOCSTRINGS_HPP__
#define __DOCSTRINGS_HPP__

#define MKD_EXPAND(x)                                      x
#define MKD_COUNT(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, COUNT, ...)  COUNT
#define MKD_VA_SIZE(...)                                   MKD_EXPAND(MKD_COUNT(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))
#define MKD_CAT1(a, b)                                     a ## b
#define MKD_CAT2(a, b)                                     MKD_CAT1(a, b)
#define MKD_DOC1(n1)                                       mkd_doc_##n1
#define MKD_DOC2(n1, n2)                                   mkd_doc_##n1##_##n2
#define MKD_DOC3(n1, n2, n3)                               mkd_doc_##n1##_##n2##_##n3
#define MKD_DOC4(n1, n2, n3, n4)                           mkd_doc_##n1##_##n2##_##n3##_##n4
#define MKD_DOC5(n1, n2, n3, n4, n5)                       mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5
#define MKD_DOC6(n1, n2, n3, n4, n5, n6)                   mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6
#define MKD_DOC7(n1, n2, n3, n4, n5, n6, n7)               mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7
#define MKD_DOC8(n1, n2, n3, n4, n5, n6, n7, n8)           mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8
#define MKD_DOC9(n1, n2, n3, n4, n5, n6, n7, n8, n9)       mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8##_##n9
#define MKD_DOC10(n1, n2, n3, n4, n5, n6, n7, n8, n9, n10) mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8##_##n9##_##n10
#define DOC(...)                                           MKD_EXPAND(MKD_EXPAND(MKD_CAT2(MKD_DOC, MKD_VA_SIZE(__VA_ARGS__)))(__VA_ARGS__))

#if defined(__GNUG__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#endif // __DOCSTRINGS_HPP__
#if defined(__GNUG__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram =
R"doc(The Data Record Frame (DRF) is the header/wrapper that precedes every
7k record.

This class implements the fixed 64-byte DRF header as defined in the
"7k Data Format Definition" specification (v3.12, April 2020), Table
5. All multibyte fields are stored in little-endian byte order. A
record consists of: DRF header + record type header (RTH) + (optional)
record data + (optional) optional data + checksum.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_S7KDatagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_S7KDatagram_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_S7KDatagram_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_compute_size_content =
R"doc(Number of bytes of the record following the DRF header (RTH + data +
checksum).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_day = R"doc(offset 22: UTC day of year (1-366))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_device_identifier = R"doc(offset 36: device identifier)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_flags = R"doc(offset 48: bit field (bit 0: checksum valid, bit 15: recorded data))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_fragment_number = R"doc(offset 60: always 0 in files)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_checksum_valid = R"doc(Test if the flags field indicates a valid checksum (bit 0).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_datagram_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_date_string =
R"doc(Get the timestamp as a formatted date string.
Args:
    fractionalSecondsDigits: number of fractional-second digits
    format: date format string

Returns:
    Formatted date string.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_day = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_device_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_fragment_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_hours = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_minutes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_offset = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_optional_data_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_optional_data_offset = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_protocol_version = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_record_type_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_record_version = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_seconds = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_size = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_sync_pattern = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_system_enumerator = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_timestamp =
R"doc(Get the record timestamp as unix time (seconds since 1970-01-01 UTC).
Returns:
    Unix timestamp, or NaN if no time is available (all 7KTIME fields
    zero).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_total_records_in_fragmented_data_record_set = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_get_year = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_hours = R"doc(offset 28: UTC hours (0-23))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_is_valid = R"doc(Test if the DRF sync pattern is valid.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_minutes = R"doc(offset 29: UTC minutes (0-59))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_offset = R"doc(offset 2: bytes from start of sync pattern to RTH)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_operator_assign = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_operator_assign_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_optional_data_identifier = R"doc(offset 16: identifier for the optional data field)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_optional_data_offset = R"doc(offset 12: byte offset to optional data (0 = none))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_protocol_version = R"doc(offset 0: protocol version of this frame (e.g. 5))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_record_type_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_record_version = R"doc(offset 30: record version (currently 1))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_reserved_1 = R"doc(offset 40: reserved)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_reserved_2 = R"doc(offset 44: reserved)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_reserved_3 = R"doc(offset 50: reserved)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_reserved_4 = R"doc(offset 52: reserved)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_seconds = R"doc(offset 24: UTC seconds (0.0 - 60.0))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_datagram_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_day = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_device_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_hours = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_minutes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_offset = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_optional_data_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_optional_data_offset = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_protocol_version = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_record_version = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_seconds = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_size = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_sync_pattern = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_system_enumerator = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_set_year = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_size =
R"doc(offset 8: total record size (version field to end of checksum,
including embedded data))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_skip =
R"doc(Skip the data section of the datagram (position stream at the next
DRF).
Args:
    is: Input stream, positioned directly after the DRF header.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_sync_pattern = R"doc(offset 4: 0x0000FFFF)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_system_enumerator = R"doc(offset 42: enumerator differentiating devices with same id)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_total_records_in_fragmented_data_record_set = R"doc(offset 56: always 0 in files)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_S7KDatagram_year = R"doc(offset 20: UTC year (all four digits, e.g. 2023))doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


