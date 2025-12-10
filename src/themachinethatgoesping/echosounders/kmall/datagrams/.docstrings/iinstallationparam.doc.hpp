//sourcehash: bdbd62e595659e1591c62f9c489f70ed1620ca06a46c94f01fc5df176e628d48

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam = R"doc(Clock datagrams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_IInstallationParam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_bytes_content = R"doc(bytes of the datagram body)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_bytes_datagram_check = R"doc(Each datagram ends with the size of the datagram for integrity check)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_decode_install_txt =
R"doc(Decode an install_txt string into a key-value map (static version)

Args:
    install_txt: The installation parameter text to decode

Returns:
    std::map<std::string, std::string> Map of parameter names to
        values)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_active_attitude_sensor_number =
R"doc(Get the active attitude sensor number (1-4)

Reads the U=ACTIVE field from ATTI_n entries

Returns:
    uint8_t Attitude sensor number (1-4), or 0 if none active)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_active_position_system_number =
R"doc(Get the active position system number (1-4)

Reads the U=ACTIVE field from POSI_n entries

Returns:
    uint8_t Position system number (1-4), or 0 if none active)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_attitude_sensor_offsets =
R"doc(Get the attitude sensor offsets for a given sensor number

Parses ATTI_1, ATTI_2, ATTI_3, or ATTI_4 entries

Args:
    sensor_number: Sensor number (1-4)

Returns:
    navigation::datastructures::PositionalOffsets)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_available_transducer_keys =
R"doc(Get a list of available transducer keys present in the installation
parameters

Checks for TRAI_HD1, TRAI_TX1, TRAI_TX2, TRAI_RX1, TRAI_RX2

Returns:
    std::vector<std::string> List of available transducer keys)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_bytes_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_bytes_datagram_check = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_depth_sensor_offsets =
R"doc(Get the depth sensor offsets

Parses DPHI entry

Returns:
    navigation::datastructures::PositionalOffsets)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_info = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_install_txt = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_install_txt_decoded =
R"doc(Decode the install_txt string into a key-value map

This function parses the KMALL installation parameter text format. The
format contains comma-separated fields with different separators for
different field types (e.g., ':' for OSCV, '_' for PU, '=' for SN).

Returns:
    std::map<std::string, std::string> Map of parameter names to
        values)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_install_txt_key_info =
R"doc(Get human-readable explanation for an install_txt key

Args:
    key: The key to look up (e.g., "OSCV", "EMXV", "PU")

Returns:
    std::string Human-readable explanation, or "Unknown key" if not
        found)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_install_txt_key_infos =
R"doc(Get all known install_txt key explanations

Returns:
    const std::map<std::string, std::string>& Map of keys to their
    explanations)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_position_system_offsets =
R"doc(Get the position system offsets for a given position system number

Parses POSI_1, POSI_2, POSI_3, or POSI_4 entries

Args:
    position_system_number: Position system number (1-4)

Returns:
    navigation::datastructures::PositionalOffsets)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_pu_serial_number =
R"doc(Get the PU serial number (SN field)

Returns:
    int PU serial number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_status = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_system_name =
R"doc(Get the system name (EMXV field)

Returns:
    std::string System name (e.g., "EM2040P"))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_transducer_offsets =
R"doc(Get the transducer offsets for a given transducer

Parses TRAI_TX1, TRAI_TX2, TRAI_RX1, TRAI_RX2, or TRAI_HD1 entries

Args:
    transducer_key: Key like "TRAI_HD1", "TRAI_TX1", etc.

Returns:
    navigation::datastructures::PositionalOffsets)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_get_water_line_vertical_location_in_meters =
R"doc(Get the waterline offset (SWLZ from EMXI)

Returns:
    float Waterline offset in meters)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_has_transducer_key =
R"doc(Check if a specific transducer key is present

Args:
    key: Transducer key (e.g., "TRAI_HD1", "TRAI_TX1")

Returns:
    bool True if the key is present)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_info = R"doc(Information. For future use.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_install_txt = R"doc(Runtime parameters as text format.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_parse_sensor_string =
R"doc(Parse a semicolon-separated sensor string into key-value pairs

For example: "X=0.000;Y=0.000;Z=0.000;R=0.000;P=0.000;H=0.000"

Args:
    sensor_string: The sensor string to parse

Returns:
    std::map<std::string, std::string> Map of parameter names to
        values)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_set_info = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_set_install_txt = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_set_status = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_status = R"doc(Status. For future use.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_IInstallationParam_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


