//sourcehash: 7a062fffe078016783807a049a595ab651171198d4ce580c5a96864d16652ef0

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


static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput =
R"doc(The PU Status datagram is sent out every second if requested by the
host processor. It has two functions, to indicate that the system is
alive and receiving sensor data, and to give sensor data regularly for
a potential screen update.)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_PUIDOutput = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_PUIDOutput_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_bsp_software_date = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_byte_order_flag = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_bsp_software_date = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_byte_order_flag = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_cpu_configuration =
R"doc(Convert the system descriptor flag to a cpu configuration

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_has_bsp67B =
R"doc(Evaluate the system_descriptor flag to determine if the system is a
BSP67B system

This means it is not a CBMF system

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_has_cbmf =
R"doc(Evaluate the system_descriptor flag to determine if the system is a
CBMF system

This means it is not a BSP67B system

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_has_deep_water_sonar_head =
R"doc(Evaluate the system_descriptor flag to determine if the system has a
deep water sonar head

Returns:
    true (deep water sonar head)

Returns:
    false (shallow water sonar head)s)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_has_dual_head =
R"doc(Evaluate the system_descriptor flag to determine if the system is a
dual head system

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_has_dual_swath =
R"doc(Evaluate the system_descriptor flag to determine if the system is a
dual swath system

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_has_extra_detections_support =
R"doc(Evaluate the system_descriptor flag to determine if the system has
extra detections support

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_has_ptp_support =
R"doc(Evaluate the system_descriptor flag to determine if the system is a
PTP (IEEE 1588 clock sync) support

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_has_rs422_support =
R"doc(Evaluate the system_descriptor flag to determine if the system has
RS422 serial lines support

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_has_shallow_water_sonar_head =
R"doc(Evaluate the system_descriptor flag to determine if the system has a
shallow water sonar head

Returns:
    true (shallow water sonar head)

Returns:
    false (deep water sonar head))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_host_ip_address = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_host_ip_address_as_string =
R"doc(Get the host ip address as string

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_pu_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_rx_opening_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_sonar_transceiver_1_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_sonar_transceiver_2_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_system_descriptor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_tx_opening_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_udp_port_no_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_udp_port_no_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_udp_port_no_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_udp_port_no_4 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_which_em2040 =
R"doc(Evaluate the system_descriptor flag to determine the em2040 flag

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_which_em710 =
R"doc(Evaluate the system_descriptor flag to determine the EM710 flag

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_get_which_old_sounder =
R"doc(Evaluate the system_descriptor flag to determine the old sounder flag

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_host_ip_address = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_pu_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_rx_opening_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_bsp_software_date = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_byte_order_flag = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_host_ip_address = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_pu_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_rx_opening_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_sonar_transceiver_1_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_sonar_transceiver_2_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_system_descriptor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_tx_opening_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_udp_port_no_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_udp_port_no_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_udp_port_no_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_set_udp_port_no_4 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_sonar_transceiver_1_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_sonar_transceiver_2_software_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_system_descriptor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_tx_opening_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_udp_port_no_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_udp_port_no_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_udp_port_no_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PUIDOutput_udp_port_no_4 = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


