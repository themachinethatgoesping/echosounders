//sourcehash: cb869681f900cbe0945044d258e1e6c34d9a4dd6b24bd3bc90b2fb1dfc194b5b

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


static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters =
R"doc(This datagram is an ASCII datagram except for the header which is
formatted as in all other output datagrams. The datagram is issued as
a start datagram when logging is switched on and as a stop datagram
when logging is turned off, i.e. at the start and end of a survey
line. It may also be sent to a remote port as an information datagram.
It is usually followed by a sound speed profile datagram. In the
datagram all ASCII fields start with a unique three character
identifier followed by “=”. This should be used when searching for a
specific field as the position of a field within the datagram is not
guaranteed. The number or character part following is in a variable
format with a minus sign and decimal point if needed, and with “,” as
the field delimiter. The format may at any time later be expanded with
the addition of new fields at any place in the datagram.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_InstallationParameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_InstallationParameters_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_get_installation_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_get_installation_parameters_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_get_installation_parameters_parsed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_get_secondary_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_installation_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_installation_parameters_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_installation_parameters_counter = R"doc(< Sequential Number)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_parsed_installation_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_reparse_installation_parameters =
R"doc(parse the installation parameters string into a map This happens when
the datagram is read from a file, but must be called manually when the
installation parameters string is changed manually.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_secondary_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_set_installation_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_set_installation_parameters_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_set_secondary_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_InstallationParameters_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif

