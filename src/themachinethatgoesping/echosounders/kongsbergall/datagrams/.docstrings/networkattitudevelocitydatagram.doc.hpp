//sourcehash: 70d8ba635ee95745efae5e3c97119b51befe0015e498b7f2947a1e93da0b07de

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


static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram =
R"doc(Network attitude velocity datagram 110. This datagram is currently not
used in the processing because the Attitude datagram already contains
all necessary information.)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_NetworkAttitudeVelocityDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_NetworkAttitudeVelocityDatagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_attitudes = R"doc(< N x Attitude data)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_attitudes_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_attitude_velocity_sensor_number =
R"doc(Get the number of attitude sensor from the sensor system descriptor
field. If this field is xx10 xxxx – attitude velocity sensor 1 (UDP5)
xx11 xxxx – attitude velocity sensor 2 (UDP6)

Returns:
    1 or 2)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_attitudes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_function_is_used =
R"doc(Evaluate if the function is used. -1 : function is not used

Returns:
    bool)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_heading_sensor_is_active =
R"doc(Evaluate if the heading sensor is active using sensor system
descriptor field. 0bxxxxxxx1 : heading is active 0bxxxxxxx1 : heading
is inactive

Returns:
    bool)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_heave_sensor_is_active =
R"doc(Evaluate if the heave sensor is active using sensor system descriptor
field. 0bxxxx1xxx : heave is active 0bxxxx0xxx : heave is inactive

Returns:
    bool)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_network_attitude_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_number_of_entries = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_pitch_sensor_is_active =
R"doc(Evaluate if the pitch sensor is active using sensor system descriptor
field. 0bxxxxx1xx : pitch is active 0bxxxxx0xx : pitch is inactive

Returns:
    bool)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_roll_sensor_is_active =
R"doc(Evaluate if the roll sensor is active using sensor system descriptor
field. 0bxxxxxx1x : roll is active 0bxxxxxx0x : roll is inactive

Returns:
    bool)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_sensor_system_descriptor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_spare_align = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_get_velocity_sensor_is_active =
R"doc(Evaluate if the velocity sensor is active using sensor system
descriptor field. 0bxxxxxxx1 : velocity is active 0bxxxxxxx1 :
velocity is inactive

The exact meaning of this field is currently not clear to us. If this
field is set to false, the attitude data seems to be exactly the same
as in the attitude datagram. If it is set to true, the attitude data
will be a little bit different.

Returns:
    bool)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_network_attitude_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_number_of_entries = R"doc(< N)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_sensor_system_descriptor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_set_attitudes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_set_network_attitude_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_set_number_of_entries = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_set_sensor_system_descriptor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_set_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_set_spare_align = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_spare_align = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_NetworkAttitudeVelocityDatagram_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


