//sourcehash: 08528c8236055e415e74bcb4883c34afaa2a1fb65b4d1cc242d7481430b602ab

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllEnvironmentDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllEnvironmentDataInterfacePerFile_KongsbergAllEnvironmentDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllEnvironmentDataInterfacePerFile_KongsbergAllEnvironmentDataInterfacePerFile_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllEnvironmentDataInterfacePerFile_get_sound_speed_profile =
R"doc(Return the SoundVelocityProfile (raytracers2) flyweight matching the
latest profile with timestamp <= ping_time. Same selection logic as
``get_soundspeed_profile``; depths are absolute (m below sea surface).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllEnvironmentDataInterfacePerFile_get_sound_speed_profile_datagram =
R"doc(Same as ``get_soundspeed_profile``; explicit "datagram" naming for
users who also want the converted ``SoundVelocityProfile``
(raytracers2) form.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllEnvironmentDataInterfacePerFile_get_soundspeed_profile =
R"doc(Return the latest SoundSpeedProfileDatagram with profile timestamp <=
ping_time.

If all known profiles are newer than ping_time, the first (oldest)
profile is returned. Throws if no profile is available for this file.

Args:
    ping_time: Ping timestamp (unix seconds).
    last_index: Stateful search hint (per ping stream) to avoid re-
                scanning.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllEnvironmentDataInterfacePerFile_has_soundspeed_profiles =
R"doc(Check whether at least one SoundSpeedProfileDatagram is available for
this file.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllEnvironmentDataInterfacePerFile_init_soundspeed_profiles =
R"doc(Read all SoundSpeedProfileDatagrams registered for this file and cache
them sorted by their profile timestamp.

This function is automatically called by get_soundspeed_profile.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllEnvironmentDataInterfacePerFile_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllEnvironmentDataInterfacePerFile_sound_speed_profiles =
R"doc(SoundVelocityProfile (raytracers2) flyweights, parallel to
_soundspeed_profiles.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllEnvironmentDataInterfacePerFile_soundspeed_profile_timestamps =
R"doc(Cached profile timestamps for fast binary search (avoid flyweight
dereference))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllEnvironmentDataInterfacePerFile_soundspeed_profiles =
R"doc(Sound speed profile datagrams found in this file, sorted by profile
timestamp)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllEnvironmentDataInterfacePerFile_soundspeed_profiles_initialized = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


