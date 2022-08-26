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


static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DataFileInfo = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DataFileInfo_file_path = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DataFileInfo_file_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_DataFileInfo_package_infos_all = R"doc(< all package headers)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFileIterator = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFileIterator_I_InputFileIterator = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFileIterator_file_paths = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFileIterator_getitem = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFileIterator_input_file_streams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFileIterator_len = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFileIterator_package_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_I_InputFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_I_InputFile_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_I_InputFile_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_I_InputFile_4 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_append_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_append_file_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_append_files = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_append_files_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_datagram_identifier_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_datagram_identifier_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_file_paths = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_input_file_streams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_number_of_packages = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_package_infos_all = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_package_infos_by_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_read_datagram_header = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_reset_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_scan_for_packages = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_sort_packages_by_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_I_InputFile_total_file_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_PackageInfo = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_PackageInfo_datagram_identifier = R"doc(< datagram type of this package)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_PackageInfo_file_nr = R"doc(< file number of this package)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_PackageInfo_file_pos = R"doc(< file position of this package)doc";

static const char *__doc_themachinethatgoesping_echosounders_fileinterfaces_PackageInfo_timestamp = R"doc(< timestamp (unixtime) of this package)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileRaw = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileRaw_datagram_identifier_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileRaw_datagram_identifier_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_FileRaw_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagram_type_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_DatagramType = R"doc(< Raw: Datagram type as)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_EK60_Datagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_HighDateTime = R"doc(< Raw: High part of Windows NT FILETIME (100ns ticks since 1601-01-01))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_Length = R"doc(< Raw: Length of the datagram in bytes)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_LowDateTime = R"doc(< Raw: Low part of Windows NT FILETIME (100ns ticks since 1601-01-01))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_get_datagram_identifier = R"doc(Ek60 datagram type (XML0, FIL1, NME0, MRU0, RAW3, ...))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_get_length =
R"doc(length of the datagram in bytes (excluding the length fields at the
beginning and end of the datagram))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_get_timestamp =
R"doc(unix timestamp in seconds since epoch (1970-01-01). Data is converted
to/from internal windows high/low timestamp representation.)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_serialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_set_datagram_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_set_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_set_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Datagram_skip = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Unknown = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Unknown_EK60_Unknown = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Unknown_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Unknown_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Unknown_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Unknown_raw_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_EK60_Unknown_serialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_ek60_datagram_type_from_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_peter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_EK60_DatagramType = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_EK60_DatagramType_FIL1 = R"doc(< Filter datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_EK60_DatagramType_MRU0 = R"doc(< Motion datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_EK60_DatagramType_NME0 = R"doc(< Unspecified (unknown) NMEA datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_EK60_DatagramType_RAW3 = R"doc(< Raw sample data datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_EK60_DatagramType_TAG0 = R"doc(< ???)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_EK60_DatagramType_XML0 = R"doc(< Unspecified (unknown) XML datagram)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif

