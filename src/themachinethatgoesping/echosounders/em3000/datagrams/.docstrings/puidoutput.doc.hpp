//sourcehash: bd5e191e118b8083fc7e40e35f409f684922d1c474bf67b5893901e854b448ff

/*
  This file contains docstrings for use in the Python bindings.
  Do not edit! They were automatically extracted by pybind11_mkdoc.

  This is a modified version which allows for more than 8 arguments and includes def-guard
 */

#pragma once

#ifndef __DOCSTRINGS_HPP__

#define __EXPAND(x)                                                  x
#define __COUNT(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, COUNT, ...) COUNT
#define __VA_SIZE(...)                                               __EXPAND(__COUNT(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))
#define __CAT1(a, b)                                                 a##b
#define __CAT2(a, b)                                                 __CAT1(a, b)
#define __DOC1(n1)                                                   __doc_##n1
#define __DOC2(n1, n2)                                               __doc_##n1##_##n2
#define __DOC3(n1, n2, n3)                                           __doc_##n1##_##n2##_##n3
#define __DOC4(n1, n2, n3, n4)                                       __doc_##n1##_##n2##_##n3##_##n4
#define __DOC5(n1, n2, n3, n4, n5)                                   __doc_##n1##_##n2##_##n3##_##n4##_##n5
#define __DOC6(n1, n2, n3, n4, n5, n6)                               __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6
#define __DOC7(n1, n2, n3, n4, n5, n6, n7)                           __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7
#define __DOC8(n1, n2, n3, n4, n5, n6, n7, n8)                                                     \
    __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8
#define __DOC9(n1, n2, n3, n4, n5, n6, n7, n8, n9)                                                 \
    __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8##_##n9
#define __DOC10(n1, n2, n3, n4, n5, n6, n7, n8, n9, n10)                                           \
    __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8##_##n9##_##n10
#define DOC(...) __EXPAND(__EXPAND(__CAT2(__DOC, __VA_SIZE(__VA_ARGS__)))(__VA_ARGS__))

#endif // NEW_DOC_HEADER_HPP
#if defined(__GNUG__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif


static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput =
R"doc(The PU Status datagram is sent out every second if requested by the
host processor. It has two functions, to indicate that the system is
alive and receiving sensor data, and to give sensor data regularly for
a potential screen update.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_PUIDOutput = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_PUIDOutput_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_bsp_software_date = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_byte_order_flag = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_bsp_software_date = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_byte_order_flag = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_host_ip_address = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_pu_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_rx_opening_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_sonar_transceiver_1_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_sonar_transceiver_2_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_system_descriptor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_tx_opening_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_udp_port_no_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_udp_port_no_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_udp_port_no_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_get_udp_port_no_4 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_host_ip_address = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_pu_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_rx_opening_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_bsp_software_date = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_byte_order_flag = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_host_ip_address = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_pu_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_rx_opening_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_sonar_transceiver_1_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_sonar_transceiver_2_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_system_descriptor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_tx_opening_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_udp_port_no_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_udp_port_no_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_udp_port_no_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_set_udp_port_no_4 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_sonar_transceiver_1_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_sonar_transceiver_2_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_system_descriptor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_tx_opening_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_udp_port_no_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_udp_port_no_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_udp_port_no_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUIDOutput_udp_port_no_4 = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


