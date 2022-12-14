/*
  This file contains docstrings for use in the Python bindings.
  Do not edit! They were automatically extracted by pybind11_mkdoc.
 */

#define __EXPAND(x)                                      x
#define __COUNT(_1, _2, _3, _4, _5, _6, _7, COUNT, ...)  COUNT
#define __VA_SIZE(...)                                   __EXPAND(__COUNT(__VA_ARGS__, 7, 6, 5, 4, 3, 2, 1))
#define __CAT1(a, b)                                     a ## b
#define __CAT2(a, b)                                     __CAT1(a, b)
#define __DOC1(n1)                                       __doc_##n1
#define __DOC2(n1, n2)                                   __doc_##n1##_##n2
#define __DOC3(n1, n2, n3)                               __doc_##n1##_##n2##_##n3
#define __DOC4(n1, n2, n3, n4)                           __doc_##n1##_##n2##_##n3##_##n4
#define __DOC5(n1, n2, n3, n4, n5)                       __doc_##n1##_##n2##_##n3##_##n4##_##n5
#define __DOC6(n1, n2, n3, n4, n5, n6)                   __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6
#define __DOC7(n1, n2, n3, n4, n5, n6, n7)               __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7
#define DOC(...)                                         __EXPAND(__EXPAND(__CAT2(__DOC, __VA_SIZE(__VA_ARGS__)))(__VA_ARGS__))

#if defined(__GNUG__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif


static const char *__doc_std_hash = R"doc()doc";

static const char *__doc_std_hash_operator_call = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_datagram_identifier_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_datagram_identifier_info_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_datagram_identifier_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_datagram_identifier_to_string_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_EM3000Datagram_type_from_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_FileEM3000 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_FileEM3000_FileEM3000 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_FileEM3000_FileEM3000_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_FileEM3000_FileEM3000_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_FileEM3000_FileEM3000_4 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_FileEM3000_callback_scan_new_file_begin = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_FileEM3000_callback_scan_new_file_end = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_FileEM3000_callback_scan_packet = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_FileEM3000_init_interfaces = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_FileEM3000_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagram_type_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000DatagramVariant = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000DatagramVariant_EM3000DatagramVariant = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000DatagramVariant_EM3000DatagramVariant_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000DatagramVariant_datagram_variant = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000DatagramVariant_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000DatagramVariant_operator_call =
R"doc(This is the visitor function that tries to convert the internal
variant to the specified type.

Template parameter ``t_ProgressBar``:
    $Parameter ``progress_bar``:

ProgressBar class that is derived from I_ProgressBar

Returns:
    I_ProgressBar&)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_EM3000Datagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_EM3000Datagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_bytes =
R"doc(< number of bytes in the datagram (not including the _bytes field
itself))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_datagram_identifier = R"doc(< EM3000 datagram identifier)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_date = R"doc(< year*1000 + month*100 + day(Example:Jun 27, 2020 = 20200627))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_get_bytes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_get_datagram_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_get_date = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_get_date_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_get_model_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_get_stx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_get_time_since_midnight = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_get_timestamp =
R"doc(convert the date and time_since_midnight field to a unix timestamp

Returns:
    unixtime as double)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_model_number = R"doc(< EM3000 model number (example: EM 3002 = 3002))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_set_bytes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_set_datagram_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_set_date = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_set_model_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_set_stx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_set_time_since_midnight = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_skip = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_stx = R"doc(< (start identifier))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_time_since_midnight = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Datagram_verify_datagram_end =
R"doc(verify the datagram is read correctly by reading the ETX (end
identifier) field and the checksum at the end of the datagram Note:
the checksum is not verified. (describes sum of bytes between STX and
ETX)

Parameter ``is``:
    istream. Must be at the end position of the datagram header. Pos
    will be incremented by 3 bytes (ETX and checksum).)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_EM3000Unknown = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_EM3000Unknown_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_get_raw_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_raw_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_set_raw_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_EM3000Unknown_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections =
R"doc(This datagram is used for the models EM 2040 and EM 2040C with Slim
Processing Unit.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_ExtraDetections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_ExtraDetections_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_datagram_counter = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_datagram_version_id = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_depth_of_reference_point = R"doc(< m)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_detection_classes = R"doc(< substructure 1)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_detection_classes_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_extra_detections = R"doc(< substructure 2)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_extra_detections_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_datagram_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_datagram_version_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_depth_of_reference_point = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_detection_classes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_extra_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_heading = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_heading_in_degrees =
R"doc(Get heading in degrees

Returns:
    _heading * 0.01?? (double))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_number_of_alarm_flags = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_number_of_bytes_per_class = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_number_of_bytes_per_detection = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_number_of_detection_classes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_number_of_extra_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_raw_amplitude_sample_rate = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_raw_amplitude_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_rx_transducer_index = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_sound_speed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_sound_speed_in_m_per_s =
R"doc(Get sound velocity in m/s

Returns:
    _sound_speed * 0.1 m/s (double))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_swath_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_swath_index = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_get_water_column_sample_rate = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_heading = R"doc(< 0.01??)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_number_of_alarm_flags = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_number_of_bytes_per_class = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_number_of_bytes_per_detection = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_number_of_detection_classes = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_number_of_extra_detections = R"doc(< Nd)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_ping_counter = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_raw_amplitude_sample_rate = R"doc(< (SIsr))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_raw_amplitude_samples = R"doc(< 0.01 dB)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_raw_amplitude_samples_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_rx_transducer_index = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_datagram_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_datagram_version_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_depth_of_reference_point = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_detection_classes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_extra_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_heading = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_number_of_alarm_flags = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_number_of_bytes_per_class = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_number_of_bytes_per_detection = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_number_of_detection_classes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_number_of_extra_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_raw_amplitude_sample_rate = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_raw_amplitude_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_rx_transducer_index = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_sound_speed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_swath_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_swath_index = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_set_water_column_sample_rate = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_sound_speed = R"doc(< dm/s)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_swath_counter = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_swath_index = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_system_serial_number = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_ExtraDetections_water_column_sample_rate = R"doc(< (WCsr))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle =
R"doc(This datagram is used for the models EM 2040, EM 2040C, EM 710, EM
122, EM 302 and ME70BO. All receiver beams are included, check
detection info and real time cleaning for beam status (note 4 and 5).)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_RawRangeAndAngle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_RawRangeAndAngle_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_beams_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_d_scale = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_d_scale = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_number_of_receiver_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_number_of_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_number_of_valid_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_sampling_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_sound_speed_at_transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_sound_speed_at_transducer_in_m_per_s =
R"doc(Get the sound speed at the transducerin meters per seconds

Returns:
    _sound_speed_at_transducer * 0.1 meters per seconds (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_number_of_receiver_beams = R"doc(< in Datagram nrx)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_number_of_transmit_sectors = R"doc(< ntx)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_number_of_valid_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_ping_counter = R"doc(< sequential number)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_sampling_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_d_scale = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_number_of_receiver_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_number_of_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_number_of_valid_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_sampling_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_sound_speed_at_transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_sound_speed_at_transducer = R"doc(< in 0.1 m/s)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_transmit_sectors_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram =
R"doc(This datagram is used for the models EM 2040, EM 2040C, EM 710, EM
122, EM 302 and ME70BO. All receiver beams are included, check
detection info and real time cleaning for beam status (note 4 and 5).)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_XYZDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_XYZDatagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_beams = R"doc(< beam detection information)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_beams_2 =
R"doc(structure access to beams (read/write)

Returns:
    std::vector<substructures::XYZDatagramBeam>&)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_heading_of_vessel = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_heading_of_vessel_in_degrees =
R"doc(Get the vessel heading in degrees

Returns:
    heading_of_vessel * 0.01 degrees (double))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_number_of_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_number_of_valid_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_sampling_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_scanning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_sound_speed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_sound_speed_in_m_per_s =
R"doc(Get the sound speed in meters per seconds

Returns:
    sound_speed * 0.1 meters per seconds (double))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_spare_byte = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_spare_bytes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_get_transmit_transducer_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_heading_of_vessel = R"doc(< (at TX time) in 0.01 degree)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_number_of_beams = R"doc(< in Datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_number_of_valid_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_ping_counter = R"doc(< 0-65535 ping number (in this file))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_sampling_frequency = R"doc(< in Hz)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_scanning_info = R"doc(< only used by em2040. 0 means scanning is not used.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_set_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_set_heading_of_vessel = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_set_number_of_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_set_number_of_valid_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_set_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_set_sampling_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_set_scanning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_set_sound_speed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_set_spare_byte = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_set_spare_bytes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_set_transmit_transducer_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_sound_speed = R"doc(< at transducer in dm/s)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_spare_byte = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_spare_bytes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_system_serial_number = R"doc(< 100 -)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_XYZDatagram_transmit_transducer_depth = R"doc(< in meter relative water level at time of ping)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses = R"doc(Extra Detections Detection Classes)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_ExtraDetectionsDetectionClasses = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_alarm_flag_1 =
R"doc(< 0: (no alarm) 1:Number of extra detections are above Alarm
threshold.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_alarm_threshold = R"doc(< number of extra det. required (1-99 0=off))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_bs_threshold = R"doc(< dB (-10 - 60))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_alarm_flag_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_alarm_threshold = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_bs_threshold = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_number_of_extra_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_qf_threshold =
R"doc(Get the ifremer QF threshold The Ifremer Quality factor is used to
estimate the relative depth error. QF threshold equal to 0.1 means a
0.1% depth error threshold. At 100 m depth this the depth error
threshold would be 10 cm. Valid range is 0.01 to 1 %.

Returns:
    qf_threshold_100 * 0.01 (double))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_qf_threshold_100 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_show_class = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_snr_threshold = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_start_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_stop_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_number_of_extra_detections = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_qf_threshold_100 = R"doc(< 100 * QF threshold (1-100))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_alarm_flag_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_alarm_threshold = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_bs_threshold = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_number_of_extra_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_qf_threshold_100 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_show_class = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_snr_threshold = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_start_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_stop_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_show_class = R"doc(< 0-1)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_snr_threshold = R"doc(< 5-15)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_start_depth = R"doc(< % of depth (0-300))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_stop_depth = R"doc(< % of depth (1-300))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections = R"doc(Extra Detections in the extra detections datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_ExtraDetectionsExtraDetections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_across = R"doc(< y in m)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_along = R"doc(< x in m)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_applied_pointing_angle_correction = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_applied_two_way_travel_time_corrections = R"doc(< seconds, f.ex. Doppler correction)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_backscatter = R"doc(< 0.1 dB)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_beam_angle_across = R"doc(< re vertical ??)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_beam_incidence_angle_adjustment = R"doc(< IBA in 0.1??)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_beam_pointing_angle = R"doc(< deg. re array)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_confidence_level = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_delta_latitude = R"doc(< ??)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_delta_longitude = R"doc(< ??)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_depth = R"doc(< z in m)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_detected_range = R"doc(< in (WCsr) samples)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_detection_class_number = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_detection_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_detection_window_length = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_across = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_along = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_applied_pointing_angle_correction = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_applied_two_way_travel_time_corrections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_backscatter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_backscatter_in_db =
R"doc(Get the backscatter in dB

Returns:
    _backscatter * 0.1 dB (double))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_backscatter_is_compensated =
R"doc(This function evaluates the detection information flag. If the 4th bit
is set to 1, the detection is compensated for beam incident angle. If
the 4th bit is set to 0, the detection is not compensated for beam
incident angle.

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_beam_angle_across = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_beam_incidence_angle_adjustment = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_beam_pointing_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_confidence_level = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_delta_latitude = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_delta_longitude = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_detected_range = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_detection_class_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_detection_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_detection_is_valid =
R"doc(This function evaluates the detection information flag. If the last
bit is set to 1, the detection is valid. If the last bit is set to 0,
the detection is invalid.

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_detection_type =
R"doc(This function evaluates the detection information flag. The first 3
bits indicate the type of detection.

Returns:
    t_DetectionType)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_detection_window_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_number_of_raw_amplitude_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_qf_10 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_qf_threshold =
R"doc(Get the ifremer QF threshold

Returns:
    qf_threshold_10 * 0.1 (double))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_quality_factor_old = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_range_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_real_time_cleaning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_two_way_travel_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_tx_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_get_water_column_beam_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_number_of_raw_amplitude_samples = R"doc(< NS)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_qf_10 = R"doc(< Ifremer Quality factor * 10)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_quality_factor_old = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_range_factor = R"doc(< in %)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_real_time_cleaning_info = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_across = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_along = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_applied_pointing_angle_correction = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_applied_two_way_travel_time_corrections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_backscatter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_beam_angle_across = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_beam_incidence_angle_adjustment = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_beam_pointing_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_confidence_level = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_delta_latitude = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_delta_longitude = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_detected_range = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_detection_class_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_detection_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_detection_window_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_number_of_raw_amplitude_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_qf_10 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_quality_factor_old = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_range_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_real_time_cleaning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_two_way_travel_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_tx_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_set_water_column_beam_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_two_way_travel_time = R"doc(< s)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_tx_sector_number = R"doc(< or TX array index)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsExtraDetections_water_column_beam_number = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam =
R"doc(The beam data are given re the transmit transducer or sonar head depth
and the horizontal location (x,y) of the active positioning system's
reference point. Heave, roll, pitch, sound speed at the transducer
depth and ray bending through the water column have been applied.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_RawRangeAndAngleBeam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_beam_pointing_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_d_corr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_detection_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_detection_window_length_in_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_backscatter_is_compensated =
R"doc(This function evaluates the detection information flag. If the 4th bit
is set to 1, the detection is compensated for beam incident angle. If
the 4th bit is set to 0, the detection is not compensated for beam
incident angle.

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_beam_pointing_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_beam_pointing_angle_in_degrees =
R"doc(Get the beam pointing angle in ??

Returns:
    _beam_pointing_angle * 0.01 (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_d_corr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_detection_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_detection_is_valid =
R"doc(This function evaluates the detection information flag. If the last
bit is set to 1, the detection is valid. If the last bit is set to 0,
the detection is invalid.

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_detection_type =
R"doc(This function evaluates the detection information flag. The first 3
bits indicate the type of detection.

Returns:
    t_DetectionType)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_detection_window_length_in_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_quality_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_realtime_cleaning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_reflectivity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_reflectivity_in_db =
R"doc(Get the reflectivity in db

Returns:
    _reflectivity * 0.1 (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_transmit_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_two_way_travel_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_quality_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_realtime_cleaning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_reflectivity = R"doc(< in 0.1 dB resolution)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_beam_pointing_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_d_corr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_detection_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_detection_window_length_in_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_quality_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_realtime_cleaning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_reflectivity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_transmit_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_two_way_travel_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_transmit_sector_number = R"doc(M relative RX array in 0.01??)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_two_way_travel_time = R"doc(< in s)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector =
R"doc(The beam data are given re the transmit transducer or sonar head depth
and the horizontal location (x,y) of the active positioning system's
reference point. Heave, roll, pitch, sound speed at the transducer
depth and ray bending through the water column have been applied.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_RawRangeAndAngleTransmitSector = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_centre_frequency = R"doc(< in Hz)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_focus_range = R"doc(< in 0.1m 0 = no focus applied)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_get_centre_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_get_focus_range = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_get_focus_range_in_m =
R"doc(Get the focus range in m

Returns:
    _focus_range * 0.1 (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_get_mean_absorption_coefficient = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_get_mean_absorption_coefficient_in_dB_per_m =
R"doc(Get the mean absorption coefficient in dB/m

Returns:
    _mean_absorption_coefficient * 10 (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_get_sector_transmit_delay = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_get_signal_bandwidth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_get_signal_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_get_signal_waveform_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_get_tilt_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_get_tilt_angle_in_degrees =
R"doc(Get the tilt angle in ??

Returns:
    _tilt_angle * 0.01 (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_get_transmit_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_mean_absorption_coefficient = R"doc(< in 0.01 dB/km)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_sector_transmit_delay = R"doc(< relative first TX pulse, in s)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_set_centre_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_set_focus_range = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_set_mean_absorption_coefficient = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_set_sector_transmit_delay = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_set_signal_bandwidth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_set_signal_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_set_signal_waveform_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_set_tilt_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_set_transmit_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_signal_bandwidth = R"doc(< in Hz)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_signal_length = R"doc(< in s)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_signal_waveform_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_tilt_angle = R"doc(< re TX array in 0.01??)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleTransmitSector_transmit_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam =
R"doc(The beam data are given re the transmit transducer or sonar head depth
and the horizontal location (x,y) of the active positioning system's
reference point. Heave, roll, pitch, sound speed at the transducer
depth and ray bending through the water column have been applied.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_XYZDatagramBeam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_acrosstrack_distance = R"doc(< distance (y) in meter)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_alongtrack_distance = R"doc(< distance (x) in meter)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_beam_incidence_angle_adjustment = R"doc(< (IBA) in 0.1 degree)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_depth = R"doc(< (Z) from transmit transducer in meter)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_detection_info = R"doc(< Flag that indicates the type and validity of detection)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_detection_window_length = R"doc(< in samples)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_get_acrosstrack_distance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_get_alongtrack_distance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_get_backscatter =
R"doc(convert reflectivity to backscatter (_reflectivity * 0.1 dB)

Returns:
    double)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_get_backscatter_is_compensated =
R"doc(This function evaluates the detection information flag. If the 4th bit
is set to 1, the detection is compensated for beam incident angle. If
the 4th bit is set to 0, the detection is not compensated for beam
incident angle.

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_get_beam_incidence_angle_adjustment = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_get_beam_incidence_angle_adjustment_in_degrees =
R"doc(Returns the beam incidence angle adjustment in degrees. (IBA * 0.1
degree)

Returns:
    double)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_get_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_get_detection_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_get_detection_is_valid =
R"doc(This function evaluates the detection information flag. If the last
bit is set to 1, the detection is valid. If the last bit is set to 0,
the detection is invalid.

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_get_detection_type =
R"doc(This function evaluates the detection information flag. The first 3
bits indicate the type of detection.

Returns:
    t_DetectionType)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_get_detection_window_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_get_quality_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_get_realtime_cleaning_information = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_get_reflectivity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_quality_factor =
R"doc(< 0-254 Scaled standard deviation (sd) of the range detection <
divided by the detected range (dr) (qf = 250*sd/sr))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_realtime_cleaning_information =
R"doc(< Flag that indicates if the beam was flagged by real < time cleaning
(negative values indicate that this < beam is flagged out))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_reflectivity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_set_acrosstrack_distance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_set_alongtrack_distance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_set_beam_incidence_angle_adjustment = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_set_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_set_detection_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_set_detection_window_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_set_quality_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_set_realtime_cleaning_information = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_XYZDatagramBeam_set_reflectivity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_detection_information_get_backscatter_is_compensated =
R"doc(This function evaluates the detection information flag. If the 4th bit
is set to 1, the detection is compensated for beam incident angle. If
the 4th bit is set to 0, the detection is not compensated for beam
incident angle.

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_detection_information_get_detection_is_valid =
R"doc(This function evaluates a detection information flag. If the most
significant bit is set to 0, the detection is valid. If the most
significant bit is set to 1, the detection is invalid.

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_detection_information_get_detection_type =
R"doc(This function evaluates the detection information flag. The first 3
bits indicate the type of detection.

Returns:
    t_DetectionType)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_detection_information_t_DetectionType =
R"doc(The detection_info flag (uint8_t) is used in XYZDatagramBeam and
ExtraDectionsExtraDetections to indicate the type of detection.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_detection_information_t_DetectionType_AmplitudeDetect = R"doc(< Valid, amplitude detection was used)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_detection_information_t_DetectionType_Estimated = R"doc(< Invalid: Therefor estimated)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_detection_information_t_DetectionType_Interpolated = R"doc(< Invalid: Therefor interpolated or extrapolated)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_detection_information_t_DetectionType_Invalid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_detection_information_t_DetectionType_InvalidNormalDetection = R"doc(< Invalid: Normal detection)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_detection_information_t_DetectionType_NoDetection = R"doc(< Invalid: No detection data is available for this beam)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_detection_information_t_DetectionType_PhaseDetect = R"doc(< Valid, phase detection was used)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_detection_information_t_DetectionType_Rejected = R"doc(< Invalid: Therefor rejected)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_filedatainterfaces_EM3000DatagramInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_filedatainterfaces_EM3000DatagramInterface_EM3000DatagramInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_filedatainterfaces_EM3000DatagramInterface_datagram_identifier_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_filedatainterfaces_EM3000DatagramInterface_datagram_identifier_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_AttitudeDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_ClockDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_CombinedWaterColumnDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_DepthOrHeightDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_ExtraDetections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_ExtraParameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_HeadingDatagram = R"doc(< TODO: implement!)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_InstallationParameterStart = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_InstallationParameterStop = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_NetworkAttitudeVelocityDatagram = R"doc(< TODO: implement!)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_PUIDOutput = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_PositionDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_PuStatusOutput = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_QualityFactorDatagram = R"doc(< TODO: implement!)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_RawRangeAndAngle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_RuntimeParameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_SeabedImageData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_SingleBeamEchoSounderDepth = R"doc(< TODO: implement!)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_SoundSpeedProfileDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_SurfaceSoundSpeedDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_WaterColumnDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_XYZDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_unspecified = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_FileInfos = R"doc(struct for storing the file infos (returned by scan_for_datagrams))doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_FileInfos_datagram_infos = R"doc(< all datagrams)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_FileInfos_file_path = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_FileInfos_file_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_I_InputFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_I_InputFile_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_I_InputFile_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_I_InputFile_4 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_I_InputFile_5 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_append_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_append_file_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_append_files = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_append_files_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_callback_scan_new_file_begin = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_callback_scan_new_file_end = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_callback_scan_packet = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_datagram_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_datagram_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_init_interfaces = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_init_interfaces_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_input_file_manager = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_reset_ifstream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_I_InputFile_scan_for_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_DatagramContainer = R"doc(Construct a new empty DatagramContainer object)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_DatagramContainer_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_add_datagram_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_add_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_at = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_break_by_time_diff = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_count_datagrams_per_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_find_datagram_types = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_get_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_get_sorted_by_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_operator_call = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_operator_call_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_operator_call_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_pyindexer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_reversed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_set_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_timeinfo =
R"doc(Compute some time statistics for the datagram_infos in the container
The is_sorted variable is interpreted as follos: - 1: the
datagram_infos are sorted by time (ascending) - 0: the datagram_infos
are not sorted by time - -1: the datagram_infos are sorted by time
(descending)

Returns:
    std::tuple<min_timestamp, max_timestamp, is_sorted()>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_PingContainer = R"doc(Construct a new empty PingContainer object)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_add_ping = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_add_pings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_at = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_break_by_time_diff = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_count_pings_per_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_find_channel_ids = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_get_pings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_get_sorted_by_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_max_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_operator_call = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_operator_call_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_operator_call_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_pings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_pings_2 =
R"doc(Construct a new PingContainer object from a vector of pings

Parameter ``pings:``:
    vector of pings)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_pyindexer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_pyindexer_2 =
R"doc(Construct a new PingContainer object from a vector of pings

Parameter ``pings:``:
    vector of pings)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_reversed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_set_pings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_timeinfo =
R"doc(Compute some time statistics for the pings in the container The
is_sorted variable is interpreted as follos: - 1: the pings are sorted
by time (ascending) - 0: the pings are not sorted by time - -1: the
pings are sorted by time (descending)

Returns:
    std::tuple<min_timestamp, max_timestamp, is_sorted()>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_AnnotationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_AnnotationDataInterface_I_AnnotationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_AnnotationDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_AnnotationDataInterface_PerFile_I_AnnotationDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_AnnotationDataInterface_PerFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_AnnotationDataInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_I_ConfigurationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_PerFile_I_ConfigurationDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_PerFile_deinitialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_PerFile_get_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_PerFile_init_from_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_PerFile_initialized = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_PerFile_initialized_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_PerFile_initialized_sensor_configuration_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_PerFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_PerFile_read_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_PerFile_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_PerFile_set_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_get_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_I_DatagramInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_add_datagram_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_add_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_datagram_identifier_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_datagram_identifier_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_datagram_infos_all = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_datagram_infos_by_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_datagrams_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_empty = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_empty_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_get_datagram_infos_all = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_get_datagram_infos_by_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_get_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_name =
R"doc(< name of the datagram container (useful for debugging derived
classes))doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_set_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_DatagramInterface_size_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_I_EnvironmentDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_PerFile_I_EnvironmentDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_PerFile_I_EnvironmentDataInterface_PerFile_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_PerFile_configuration_data_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_PerFile_configuration_data_interface_const = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_PerFile_navigation_data_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_PerFile_navigation_data_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_PerFile_navigation_data_interface_const = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_PerFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_add_file_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_configuration_data_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_configuration_data_interface_const = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_navigation_data_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_navigation_data_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_navigation_data_interface_const = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_EnvironmentDataInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_I_FileDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_PerFile_I_FileDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_PerFile_deinitialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_PerFile_get_file_nr =
R"doc(Get the file nr This function assumes that the file nr is the same for
all datagrams in the file

Returns:
    size_t)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_PerFile_get_file_path =
R"doc(Get the file name This function assumes that the file name is the same
for all datagrams in the file

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_PerFile_init_from_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_PerFile_initialized = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_PerFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_add_datagram_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_add_file_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_deinitialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_get_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_init_from_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_init_from_file_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_initialized = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_interface_per_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_per_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_per_file_const = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_pyindexer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_I_NavigationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_PerFile_I_NavigationDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_PerFile_I_NavigationDataInterface_PerFile_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_PerFile_configuration_data_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_PerFile_configuration_data_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_PerFile_configuration_data_interface_const = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_PerFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_PerFile_read_navigation_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_add_file_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_channel_ids = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_configuration_data_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_configuration_data_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_configuration_data_interface_const = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_deinitialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_get_geolocation = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_get_navigation_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_get_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_init_from_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_initialized = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_initialized_navigation_interpolator = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_initialized_navigation_interpolator_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_navigation_interpolator = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_set_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_I_PingDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_PerFile_I_PingDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_PerFile_I_PingDataInterface_PerFile_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_PerFile_configuration_data_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_PerFile_configuration_data_interface_const = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_PerFile_environment_data_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_PerFile_environment_data_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_PerFile_environment_data_interface_const = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_PerFile_init_from_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_PerFile_navigation_data_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_PerFile_navigation_data_interface_Const = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_PerFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_PerFile_read_pings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_add_file_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_channel_ids = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_configuration_data_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_configuration_data_interface_const = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_environment_data_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_environment_data_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_environment_data_interface_const = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_get_pings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_get_pings_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_init_from_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_navigation_data_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_navigation_data_interface_const = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_ping_container = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_ping_container_by_channel = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datastreams_MappedFileStream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datastreams_MappedFileStream_MappedFileStream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_DatagramInfo = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_datagram_identifier = R"doc(< datagram type of this datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_file_nr = R"doc(< file number of this datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_file_pos =
R"doc(< file position of this datagram TODO: is this the < same for ifstream
and MappedFileStream?)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_datagram_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_file_nr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_file_path = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_file_pos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_stream_and_seek = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_input_file_manager = R"doc(< input file manager)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_read_datagram_from_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_timestamp = R"doc(< timestamp (unixtime) of this datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_I_Ping =
R"doc(the transducer). If not set manually, this variable is set by calling
file.I_navigation.get_geolocation(ping.get_channel_id(),
ping.get_timestamp()).)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_channel_id = R"doc(< channel id of the transducer)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_feature_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_geolocation =
R"doc(< Geolocation of the transducer (object that hold lat,lon and attitude
of)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_angle =
R"doc(Compute the launch angle of the (sinle) target within each sample. If
you see this comment, this function was not implemented for the
current ping type.

Returns:
    xt::xtensor<float, 2>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_file_nr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_file_path = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_geolocation = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_sv =
R"doc(Compute volume backscattering. If you see this comment, this function
was not implemented for the current ping type.

Parameter ``dB``:
    Output Sv in dB if true, or linear if false (default).

Returns:
    xt::xtensor<float, 2>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_sv_stacked =
R"doc(Compute stacked volume backscattering (sum over all beams). If you see
this comment, this function was not implemented for the current ping
type.

Parameter ``dB``:
    Output Sv in dB if true, or linear if false (default).

Returns:
    xt::xtensor<float, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_has_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_has_sv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_load_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_not_implemented = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_not_implemented_not_implemented = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_release_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_set_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_set_geolocation = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_set_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_timestamp = R"doc(< Unix timestamp in seconds (saved in UTC0))doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_helper_DeduplicateBuffer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_helper_DeduplicateBuffer_DeduplicateBuffer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_helper_DeduplicateBuffer_add = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_helper_DeduplicateBuffer_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_helper_DeduplicateBuffer_get = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_helper_DeduplicateBuffer_get_all = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_helper_DeduplicateBuffer_last_datagram_per_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_internal_InputFileManager = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_internal_InputFileManager_InputFileManager = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_internal_InputFileManager_active_file_nr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_internal_InputFileManager_append_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_internal_InputFileManager_file_paths = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_internal_InputFileManager_get_active_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_internal_InputFileManager_get_file_path = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_internal_InputFileManager_get_file_paths = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_internal_InputFileManager_get_total_file_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_internal_InputFileManager_input_file_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_internal_InputFileManager_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_internal_InputFileManager_total_file_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_FileSimradRaw = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_FileSimradRaw_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_FileSimradRaw_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_FileSimradRaw_4 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_annotation_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_annotation_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_callback_scan_new_file_begin = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_callback_scan_new_file_end = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_callback_scan_packet = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_channel_ids = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_configuration_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_configuration_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_environment_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_environment_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_init_interfaces = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_navigation_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_navigation_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_otherdata_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_otherdata_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_ping_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_ping_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_pings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_pings_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_pings_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradDatagram_type_from_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagram_type_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagram_type_to_string_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1 =
R"doc(Filter binary datagram (FIL1) This datagram contains filter
coefficients used by the EK80 to filter the received signal.)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_ChannelID = R"doc(< Channel identification (size is always 128))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_Coefficients = R"doc(< Filter coefficients, ...))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_DecimationFactor = R"doc(< Filter decimation factor)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_FIL1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_FIL1_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_NoOfCoefficients = R"doc(< Number of complex filter coefficients)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_Spare_1 = R"doc(< For future expansions)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_Spare_2 = R"doc(< For future expansions)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_Stage = R"doc(< Filter stage number)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_get_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_get_coefficients = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_get_decimation_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_get_no_of_coefficients = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_get_spare_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_get_spare_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_get_stage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_set_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_set_coefficients = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_set_decimation_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_set_no_of_coefficients = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_set_spare_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_set_spare_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_set_stage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0 =
R"doc(Motion binary datagram (MRU0) This datagram contains heave, roll,
pitch and heading as float values. Conveniently, these values can be
used directly in themachinethatgoesping navigation processing because
they are defined in the default coordinate system / value range.)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_Heading = R"doc(< Heading in degrees, 0?? north, 90?? east)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_Heave = R"doc(< Heave in m, positive up)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_MRU0 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_MRU0_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_Pitch = R"doc(< Pitch in degrees, positive nose up)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_Roll = R"doc(< Roll in degrees, positive port up)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_get_heading = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_get_heave = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_get_pitch = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_get_roll = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_set_heading = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_set_heave = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_set_pitch = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_set_roll = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0 =
R"doc(NMEA text datagram (NME0) This datagram contains NMEA sentences
received by the EK60/EK80 transceiver.)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_NME0 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_NME0_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_decode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_get_field = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_get_field_as_double = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_get_field_as_int = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_get_sender_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_get_sentence = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_get_sentence_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_get_sentence_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_nmea_base = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_parse_fields = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3 =
R"doc(Sample binary datagram (RAW3) This datagram contains the sample data
for each ping. The exact datatype and size depends on the Datatype
field!)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_ChannelID = R"doc(< Channel identification (size is always 128))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_Count = R"doc(< Number of samples in the datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_Datatype = R"doc(< Datatype)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_NumberOfComplexSamples =
R"doc(< Number of transducer samples per sample (used when < Datatype is
complex))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_Offset = R"doc(< First sample number in the datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_RAW3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_RAW3_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_SampleData = R"doc(< Sample data)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_Spare_1 = R"doc(< Spare 1)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_Spare_2 = R"doc(< Spare 2)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataAngle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataAngle_RAW3_DataAngle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataAngle_RAW3_DataAngle_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataAngle_angle = R"doc(< Sample data)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataAngle_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataAngle_get_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataAngle_has_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataAngle_has_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataAngle_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataAngle_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataAngle_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataAngle_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataComplexFloat32 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataComplexFloat32_RAW3_DataComplexFloat32 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataComplexFloat32_RAW3_DataComplexFloat32_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataComplexFloat32_complex_samples = R"doc(< Sample data)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataComplexFloat32_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataComplexFloat32_get_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataComplexFloat32_get_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataComplexFloat32_has_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataComplexFloat32_has_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataComplexFloat32_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataComplexFloat32_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataComplexFloat32_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataComplexFloat32_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPower = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPowerAndAngle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPowerAndAngle_RAW3_DataPowerAndAngle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPowerAndAngle_RAW3_DataPowerAndAngle_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPowerAndAngle_angle = R"doc(< [along, athwart] 180/128 electrical degrees)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPowerAndAngle_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPowerAndAngle_get_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPowerAndAngle_get_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPowerAndAngle_has_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPowerAndAngle_has_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPowerAndAngle_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPowerAndAngle_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPowerAndAngle_power = R"doc(< Sample data)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPowerAndAngle_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPowerAndAngle_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPower_RAW3_DataPower = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPower_RAW3_DataPower_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPower_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPower_get_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPower_has_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPower_has_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPower_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPower_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPower_power = R"doc(< Sample data)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPower_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataPower_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataSkipped = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataSkipped_RAW3_DataSkipped = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataSkipped_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataSkipped_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataSkipped_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataSkipped_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataSkipped_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_RAW3_DataType_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_i_RAW3_Data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_i_RAW3_Data_get_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_i_RAW3_Data_get_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_i_RAW3_Data_get_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_i_RAW3_Data_has_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_i_RAW3_Data_has_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_i_RAW3_Data_i_RAW3_Data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_i_RAW3_Data_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_t_RAW3_DataType = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_t_RAW3_DataType_Angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_t_RAW3_DataType_ComplexFloat16 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_t_RAW3_DataType_ComplexFloat32 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_t_RAW3_DataType_Power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_datatypes_t_RAW3_DataType_PowerAndAngle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_get_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_get_channel_id_stripped = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_get_count = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_get_data_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_get_number_of_complex_samples =
R"doc(Get the number of complex samples. This corresponds to the number of
transducer elements. This field is only valid for complex data types.

Returns:
    simrad_short)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_get_offset = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_get_sample_data =
R"doc(Get the sample data. The sample data is stored in a variant of xtensor
containers. The exact type depends on the data type.

Returns:
    RAW3_datatypes::RAW3_DataVariant)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_get_spare_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_get_spare_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_read_sample_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_read_skipped_sample_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_sample_data =
R"doc(Get the sample data. The sample data is stored in a variant of xtensor
containers. The exact type depends on the data type.

Returns:
    RAW3_datatypes::RAW3_DataVariant)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_set_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_set_count = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_set_data_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_set_number_of_complex_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_set_offset = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_set_sample_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagramVariant = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagramVariant_SimradDatagramVariant = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagramVariant_SimradDatagramVariant_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagramVariant_datagram_variant = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagramVariant_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagramVariant_operator_call =
R"doc(This is the visitor function that tries to convert the internal
variant to the specified type.

Template parameter ``t_ProgressBar``:
    $Parameter ``progress_bar``:

ProgressBar class that is derived from I_ProgressBar

Returns:
    I_ProgressBar&)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_DatagramType = R"doc(< Raw: Datagram type as)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_HighDateTime = R"doc(< Raw: High part of Windows NT FILETIME (100ns ticks since 1601-01-01))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_Length = R"doc(< Raw: Length of the datagram in bytes)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_LowDateTime = R"doc(< Raw: Low part of Windows NT FILETIME (100ns ticks since 1601-01-01))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_SimradDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_SimradDatagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_get_datagram_identifier = R"doc(Ek60 datagram type (XML0, FIL1, NME0, MRU0, RAW3, ...))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_get_date_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_get_length =
R"doc(length of the datagram in bytes (excluding the length fields at the
beginning and end of the datagram))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_get_timestamp =
R"doc(unix timestamp in seconds since epoch (1970-01-01). Data is converted
to/from internal windows high/low timestamp representation.)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_set_datagram_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_set_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_set_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_skip = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_verify_datagram_end =
R"doc(verify the datagram is read correctly by reading the length field at
the end

Parameter ``is``:
    istream. Must be at the end position of the datagram. Pos will be
    incremented by 4 bytes (simrad_long).)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradUnknown = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradUnknown_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradUnknown_SimradUnknown = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradUnknown_SimradUnknown_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradUnknown_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradUnknown_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradUnknown_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradUnknown_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradUnknown_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradUnknown_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradUnknown_raw_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradUnknown_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0 =
R"doc(Motion binary datagram (TAG0) This datagram contains heave, roll,
pitch and heading as float values. Conveniently, these values can be
used directly in themachinethatgoesping navigation processing because
they are defined in the default coordinate system / value range.)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_TAG0 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_TAG0_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_TAG0_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_Text = R"doc(< _Text annotation string (e.g. interesting fish shoal in echogram))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_get_text = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_set_text = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0 =
R"doc(Motion binary datagram (XML0) This datagram contains heave, roll,
pitch and heading as float values. Conveniently, these values can be
used directly in themachinethatgoesping navigation processing because
they are defined in the default coordinate system / value range.)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_XML0 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_XML0_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_decode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_get_xml_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_get_xml_datagram_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_parse_xml = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_raw = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_set_xml_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_test_xml = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_xml_content = R"doc(< raw xml string)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_ChannelConfiguration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_ChannelConfiguration_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_channel = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_get_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_get_channel_struct = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_get_sensor_offsets = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_get_transceiver_struct = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_get_transducer_offsets_struct = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_sensor_offsets = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_transceiver = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_ChannelConfiguration_transducer_offsets = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode_2 = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode_Mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode_XML_Configuration_ActivePingMode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode_XML_Configuration_ActivePingMode_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ActivePingMode_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ApplicationName = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ChannelConfigurations = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_ConfiguredSensors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Copyright = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_FileFormatVersion = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_SensorConfigurations = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_AngleX = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_AngleY = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_AngleZ = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Port = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TalkerID = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue_Name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue_Priority = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue_XML_Configuration_Sensor_TelegramValue = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue_XML_Configuration_Sensor_TelegramValue_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_TelegramValue_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_Enabled = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_Name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_SensorType = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_SubscriptionPath = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_Type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_Values = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_XML_Configuration_Sensor_Telegram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_XML_Configuration_Sensor_Telegram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegram_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Telegrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Timeout = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Unique = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_X = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_XML_Configuration_Sensor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_XML_Configuration_Sensor_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Y = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_Z = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_get_sensor_offsets =
R"doc(Return the sensor offsets as
navigation::datastructures::PositionalOffsets structure

Returns:
    navigation::datastructures::PositionalOffsets)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Sensor_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_TimeBias = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_ChannelID = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_ChannelIdShort = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_ChannelNumber = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_AngleOffsetAlongship = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_AngleOffsetAthwartship = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_BeamWidthAlongship = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_BeamWidthAthwartship = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_Frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_Gain = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_Impedance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_Phase = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_XML_Configuration_Transceiver_Channel_FrequencyPar = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_XML_Configuration_Transceiver_Channel_FrequencyPar_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_FrequencyPar_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_HWChannelConfiguration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_LogicalChannelID = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_MaxTxPowerTransceiver = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_PulseDuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_PulseDurationFM = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_PulseLength = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_SampleInterval = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_2 = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_AngleOffsetAlongship = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_AngleOffsetAthwartship = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_AngleSensitivityAlongship = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_AngleSensitivityAthwartship = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_ArticleNumber = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_BeamType = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_BeamWidthAlongship = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_BeamWidthAthwartship = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_DirectivityDropAt2XBeamWidth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_EquivalentBeamAngle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_Frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_FrequencyMaximum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_FrequencyMinimum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_FrequencyPars = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_Gain = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_MaxTxPowerTransducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_SaCorrection = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_SerialNumber = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_TransducerName = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_XML_Configuration_Transceiver_Channel_Transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_XML_Configuration_Transceiver_Channel_Transducer_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_Transducer_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_XML_Configuration_Transceiver_Channel = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_XML_Configuration_Transceiver_Channel_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channel_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Channels = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_EthernetAddress = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_IPAddress = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Impedance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_MarketSegment = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Multiplexing = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_RxSampleFrequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_SerialNumber = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_TransceiverName = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_TransceiverNumber = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_TransceiverSoftwareVersion = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_TransceiverType = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_Version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_XML_Configuration_Transceiver = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_XML_Configuration_Transceiver_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceiver_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transceivers = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_HeadingQuickCalibration = R"doc(< Seems to be used seldomly?)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_TransducerAlphaX = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_TransducerAlphaY = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_TransducerAlphaZ = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_TransducerCustomName = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_TransducerMounting = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_TransducerName = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_TransducerOffsetX = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_TransducerOffsetY = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_TransducerOffsetZ = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_TransducerOrientation = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_TransducerSerialNumber = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_XML_Configuration_Transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_XML_Configuration_Transducer_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_get_sensor_offsets =
R"doc(Return the offsets as navigation::datastructures::PositionalOffsets
structure

Returns:
    navigation::datastructures::PositionalOffsets)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducer_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Transducers = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_Version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_XML_Configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_XML_Configuration_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_get_prioritized_sensor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_get_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_get_sensors_sorted_by_priority = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_get_transceiver = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_get_transceiver_channel = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_get_transceiver_channels = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_get_transceivers = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_initialize_channelconfigurations = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_initialize_sensorconfigurations = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Configuration_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Acidity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_DropKeelOffset = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_DropKeelOffsetIsManual = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Latitude = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Salinity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_SoundSpeed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_SoundVelocityProfile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_SoundVelocitySource = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Temperature = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_TowedBodyDepth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_TowedBodyDepthIsManual = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer_SoundSpeed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer_TransducerName = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer_XML_Environment_Transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer_XML_Environment_Transducer_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducer_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_Transducers = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_WaterLevelDraft = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_WaterLevelDraftIsManual = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_XML_Environment = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_XML_Environment_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Environment_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_InitialParameter = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_InitialParameter_Channels = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_InitialParameter_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_InitialParameter_XML_InitialParameter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_InitialParameter_XML_InitialParameter_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_InitialParameter_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_InitialParameter_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_InitialParameter_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_InitialParameter_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_InitialParameter_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_InitialParameter_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_InitialParameter_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_InitialParameter_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_InitialParameter_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_XML_Node = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_XML_Node_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_attributes_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_attributes_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_children_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_children_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_first_child = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_name_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_name_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Node_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_BandWidth = R"doc(< TODO: when is this one used)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_ChannelID = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_ChannelMode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_Frequency = R"doc(< used for cv ( PulseForm == 0))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_FrequencyEnd = R"doc(< used used for chirp pulse (PulseForm > 0))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_FrequencyStart = R"doc(< used used for chirp pulse (PulseForm > 0))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_PingId = R"doc(< this is used in the InitialParameter datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_PulseDuration = R"doc(< used used for chirp pulse (PulseForm > 0))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_PulseForm = R"doc(< 0 means cw, ?1 means chirp?)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_PulseLength = R"doc(< used for cv ( PulseForm == 0))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NO_HASH = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_SampleInterval = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_Slope = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_SoundVelocity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_TransducerDepth = R"doc(< when is this one used? only old format?)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_TransmitPower = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_XML_Parameter_Channel = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_XML_Parameter_Channel_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_initialize_channel_structure = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_operator_lt = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_slow_hash = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channels = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_XML_Parameter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_XML_Parameter_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Ping = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Ping_ChannelID = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Ping_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Ping_XML_PingSequence_Ping = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Ping_XML_PingSequence_Ping_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Ping_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Ping_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Ping_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Ping_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Ping_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Ping_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Ping_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Ping_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Ping_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_Pings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_XML_PingSequence = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_XML_PingSequence_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_PingSequence_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor = R"doc(XML base datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_IsManual = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_ManualValue = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_Type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_XML_Sensor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_XML_Sensor_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_initialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_parsed_completely = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_unknown_attributes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Sensor_unknown_children = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_get_walker = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_get_walker_a = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_get_walker_b = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_get_walker_for_each = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_objectprint_walker = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_objectprint_walker_for_each = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_objectprint_walker_objectprint_walker = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_objectprint_walker_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_objectprint_walker_root_nodes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_print_walker = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_print_walker_for_each = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_t_BeamType = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_t_BeamType_BeamTypeRef = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_t_BeamType_BeamTypeRefB = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_t_BeamType_BeamTypeSingle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_t_BeamType_BeamTypeSplit = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_t_BeamType_BeamTypeSplit2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_t_BeamType_BeamTypeSplit3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_t_BeamType_BeamTypeSplit3C = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_t_BeamType_BeamTypeSplit3CN = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_t_BeamType_BeamTypeSplit3CW = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradAnnotationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradAnnotationDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradAnnotationDataInterface_PerFile_SimradAnnotationDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradAnnotationDataInterface_PerFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradAnnotationDataInterface_SimradAnnotationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradAnnotationDataInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradConfigurationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradConfigurationDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradConfigurationDataInterface_PerFile_SimradConfigurationDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradConfigurationDataInterface_PerFile_get_attitude_sources =
R"doc(Return all attitude sources registered in the configuration datagram
(sorted by priority)

Returns:
    std::vector<XML_Configuration_Sensor>)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradConfigurationDataInterface_PerFile_get_configuration_datagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradConfigurationDataInterface_PerFile_get_depth_sources =
R"doc(Return all depth sources registered in the configuration datagram
(sorted by priority)

Returns:
    std::vector<XML_Configuration_Sensor>)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradConfigurationDataInterface_PerFile_get_heading_sources =
R"doc(Return all heading sources registered in the configuration datagram
(sorted by priority)

Returns:
    std::vector<XML_Configuration_Sensor>)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradConfigurationDataInterface_PerFile_get_position_sources =
R"doc(Return all position sources registered in the configuration datagram
(sorted by priority)

Returns:
    std::vector<XML_Configuration_Sensor>)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradConfigurationDataInterface_PerFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradConfigurationDataInterface_PerFile_read_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradConfigurationDataInterface_SimradConfigurationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradConfigurationDataInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradDatagramInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradDatagramInterface_SimradDatagramInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradDatagramInterface_datagram_identifier_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradDatagramInterface_datagram_identifier_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradEnvironmentDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradEnvironmentDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradEnvironmentDataInterface_PerFile_SimradEnvironmentDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradEnvironmentDataInterface_PerFile_SimradEnvironmentDataInterface_PerFile_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradEnvironmentDataInterface_PerFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradEnvironmentDataInterface_SimradEnvironmentDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradEnvironmentDataInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_PerFile_SimradNavigationDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_PerFile_SimradNavigationDataInterface_PerFile_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_PerFile_get_max_gga_quality = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_PerFile_get_min_gga_quality = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_PerFile_max_gga_quality = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_PerFile_min_gga_quality = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_PerFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_PerFile_read_navigation_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_PerFile_set_max_gga_quality = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_PerFile_set_min_gga_quality = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_SimradNavigationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_set_max_gga_quality = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradNavigationDataInterface_set_min_gga_quality = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradOtherDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradOtherDataInterface_SimradOtherDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradOtherDataInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradOtherFileDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradOtherFileDataInterface_PerFile_SimradOtherFileDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradOtherFileDataInterface_PerFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradPingDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradPingDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradPingDataInterface_PerFile_SimradPingDataInterface_PerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradPingDataInterface_PerFile_SimradPingDataInterface_PerFile_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradPingDataInterface_PerFile_channel_parameter_buffer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradPingDataInterface_PerFile_get_deduplicated_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradPingDataInterface_PerFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradPingDataInterface_PerFile_read_pings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradPingDataInterface_SimradPingDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatainterfaces_SimradPingDataInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPing = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData_SimradPingRawData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData_add_parameter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData_datagram_info_raw_data = R"doc(< this can be RAW3 (EK80) or RAW0 (EK60))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData_get_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData_get_parameter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData_get_sample_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData_has_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData_has_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData_load_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData_ping_data =
R"doc(< when implementing EK60, this must become a variant type (RAW3 or
RAW0))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData_ping_parameter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData_read_sample_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPingRawData_release_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPing_SimradPing = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPing_get_angle =
R"doc(Returns the single target detection launch angle for each sample.

This function calls: ping.raw_data.get_sample_data().get_angle()

Throws:
    exception-object if angle data is not available for the specific
    datagram type

Returns:
    xt::xtensor<float, 2>)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPing_get_file_nr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPing_get_file_path = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPing_get_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPing_get_sv =
R"doc(Compute volume backscattering strength (Sv) from raw data.

This function calls: ping.raw_data.get_sample_data().get_power(dB)

For single beam systems, this function returns the same value as
get_sv_stacked (since there is only one beam to stack) However, the
return type is a 2D matrix with one column, to be consistent with the
multibeam case.

Throws:
    exception-object if power data is not available for the specific
    datagram type

Parameter ``dB``:
    Output Sv in dB if true, or linear if false (default).

Returns:
    xt::xtensor<float, 2>)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPing_get_sv_stacked =
R"doc(Compute volume backscattering strength (Sv) from raw data.

This function calls: ping.raw_data.get_sample_data().get_power(dB)

For single beam systems, this function returns the same value as
get_sv (since there is only one beam to stack) However, the return
type is a 1D vector opposed to a one-column 2D matrix returned by
get_sv

Throws:
    exception-object if power data is not available for the specific
    datagram type

Parameter ``dB``:
    Output Sv in dB if true, or linear if false (default).

Returns:
    xt::xtensor<float, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPing_has_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPing_has_sv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPing_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPing_raw_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_filedatatypes_SimradPing_raw_data_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_SimradDatagramIdentifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_SimradDatagramIdentifier_FIL1 = R"doc(< Filter datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_SimradDatagramIdentifier_MRU0 = R"doc(< Motion datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_SimradDatagramIdentifier_NME0 = R"doc(< Unspecified (unknown) NMEA datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_SimradDatagramIdentifier_RAW3 = R"doc(< Raw sample data datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_SimradDatagramIdentifier_TAG0 = R"doc(< ???)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_SimradDatagramIdentifier_XML0 = R"doc(< Unspecified (unknown) XML datagram)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif

