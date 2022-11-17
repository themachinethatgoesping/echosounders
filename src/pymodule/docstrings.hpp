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


static const char *__doc_themachinethatgoesping_echosounders_datagram_identifier_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_datagram_identifier_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DataFileInfo = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DataFileInfo_datagram_infos = R"doc(< all datagrams)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DataFileInfo_file_path = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DataFileInfo_file_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DatagramInfo = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DatagramInfo_DatagramInfo = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DatagramInfo_datagram_identifier = R"doc(< datagram type of this datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DatagramInfo_file_nr = R"doc(< file number of this datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DatagramInfo_file_pos =
R"doc(< file position of this datagram TODO: is this the < same for ifstream
and MappedFileStream?)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DatagramInfo_get_datagram_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DatagramInfo_get_file_nr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DatagramInfo_get_file_pos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DatagramInfo_get_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DatagramInfo_get_stream_and_seek = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DatagramInfo_get_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DatagramInfo_input_file_manager = R"doc(< input file manager)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DatagramInfo_timestamp = R"doc(< timestamp (unixtime) of this datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_AnnotationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_AnnotationDataInterface_I_AnnotationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_ConfigurationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_ConfigurationDataInterface_I_ConfigurationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_I_DatagramContainer = R"doc(Construct a new empty I_DatagramContainer object)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_I_DatagramContainer_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_add_datagram_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_add_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_at = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_break_by_time_diff = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_count_datagrams_per_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_find_datagram_types = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_get_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_get_sorted_by_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_operator_call = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_operator_call_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_operator_call_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_pyindexer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_reversed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_set_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramContainer_timeinfo =
R"doc(Compute some time statistics for the datagram_infos in the container
The is_sorted variable is interpreted as follos: - 1: the
datagram_infos are sorted by time (ascending) - 0: the datagram_infos
are not sorted by time - -1: the datagram_infos are sorted by time
(descending)

Returns:
    std::tuple<min_timestamp, max_timestamp, is_sorted()>)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_I_DatagramInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_add_datagram_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_add_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_datagram_identifier_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_datagram_identifier_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_datagram_infos_all = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_datagram_infos_by_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_datagrams_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_get_datagram_infos_all = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_get_datagram_infos_by_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_name =
R"doc(< name of the datagram container (useful for debugging derived
classes))doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_set_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_DatagramInterface_size_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_EnvironmentDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_EnvironmentDataInterface_I_EnvironmentDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_FileDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_FileDataInterface_I_FileDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_FileDataInterface_add_datagram_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_FileDataInterface_datagram_interface_per_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_FileDataInterface_datagram_interface_per_file_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_FileDataInterface_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_FileDataInterface_pyindexer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_I_InputFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_I_InputFile_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_I_InputFile_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_I_InputFile_4 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_I_InputFile_5 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_append_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_append_file_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_append_files = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_append_files_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_callback_scan_new_file_begin = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_callback_scan_new_file_end = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_callback_scan_packet = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_datagram_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_datagram_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_input_file_manager = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_reset_ifstream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_scan_fo_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_NavigationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_NavigationDataInterface_I_NavigationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_Ping = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_I_PingContainer = R"doc(Construct a new empty PingContainer object)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_add_ping = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_add_pings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_at = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_break_by_time_diff = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_count_pings_per_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_find_channel_ids = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_get_pings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_get_sorted_by_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_max_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_operator_call = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_operator_call_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_operator_call_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_pings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_pings_2 =
R"doc(Construct a new PingContainer object from a vector of pings

Parameter ``pings:``:
    vector of pings)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_pyindexer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_pyindexer_2 =
R"doc(Construct a new PingContainer object from a vector of pings

Parameter ``pings:``:
    vector of pings)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_reversed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_set_pings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingContainer_timeinfo =
R"doc(Compute some time statistics for the pings in the container The
is_sorted variable is interpreted as follos: - 1: the pings are sorted
by time (ascending) - 0: the pings are not sorted by time - -1: the
pings are sorted by time (descending)

Returns:
    std::tuple<min_timestamp, max_timestamp, is_sorted()>)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingDataInterface_I_PingDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingDataInterface_at = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingDataInterface_at_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingDataInterface_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_PingDataInterface_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_Ping_I_Ping = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_Ping_get_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_Ping_get_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_Ping_get_sv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_Ping_get_sv_stacked = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_Ping_load_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_Ping_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_Ping_not_implemented = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_Ping_not_implemented_not_implemented = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_Ping_release_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_InputFileManager = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_InputFileManager_InputFileManager = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_InputFileManager_active_file_nr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_InputFileManager_append_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_InputFileManager_file_paths = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_InputFileManager_get_active_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_InputFileManager_get_file_paths = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_InputFileManager_get_total_file_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_InputFileManager_input_file_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_InputFileManager_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_InputFileManager_total_file_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_MappedFileStream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_MappedFileStream_MappedFileStream = R"doc()doc";

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

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_channel_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_channel_parameters_per_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_configuration_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_configuration_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_environment_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_environment_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_get_navigation_interpolators = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_mru0_packets = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_navigation_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_navigation_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_navigation_interpolators = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_nme0_packets = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_otherdata_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_otherdata_interface_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_packet_buffer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_ping_container = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_ping_container_by_channel = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_ping_data_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_pings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_pings_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_pings_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_process_navigation = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileSimradRaw_process_navigation_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradAnnotationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradAnnotationDataInterface_SimradAnnotationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradConfigurationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradConfigurationDataInterface_SimradConfigurationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradDatagramInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradDatagramInterface_SimradDatagramInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradDatagramInterface_datagram_identifier_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradDatagramInterface_datagram_identifier_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradDatagram_type_from_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradEnvironmentDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradEnvironmentDataInterface_SimradEnvironmentDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_FIL1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_SimradFileData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_TAG0 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_XML0_Configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_XML0_Environment = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_XML0_InitialParameter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_XML0_Other = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_add_datagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_add_datagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_add_datagram_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_configuration_datagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_environment_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_fil1_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_file_path = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_initial_paramater_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_other_xml0_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradFileData_tag0_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradNavigationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradNavigationDataInterface_SimradNavigationDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradOtherDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradOtherDataInterface_SimradOtherDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingDataInterface_SimradPingDataInterface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingDataInterface_add_datagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingDataInterface_file_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingDataInterface_file_data_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingDataInterface_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingRawData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingRawData_SimradPingRawData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingRawData_add_parameter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingRawData_datagram_info_raw = R"doc(< this can be RAW3 (EK80) or RAW0 (EK60))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingRawData_file_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingRawData_get_parameter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingRawData_get_sample_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingRawData_load_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingRawData_ping_data =
R"doc(< when implementing EK60, this must become a variant type (RAW3 or
RAW0))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingRawData_ping_data_interface = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingRawData_ping_parameter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingRawData_read_sample_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPingRawData_release_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing_SimradPing = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing_file_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing_get_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing_get_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing_get_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing_get_sv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing_get_sv_stacked = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing_get_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing_load_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing_raw = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing_raw_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing_release_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradPing_timestamp = R"doc()doc";

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

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_FIL1_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

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

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_Heading = R"doc(< Heading in degrees, 0° north, 90° east)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_Heave = R"doc(< Heave in m, positive up)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_MRU0 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_MRU0_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_Pitch = R"doc(< Pitch in degrees, positive nose up)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_Roll = R"doc(< Roll in degrees, positive port up)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_MRU0_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

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

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_NME0_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

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

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_RAW3_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

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

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

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

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradUnknown_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

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

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_TAG0_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

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

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_XML0_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

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

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_xml_datagrams_XML_Parameter_Channel_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

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

