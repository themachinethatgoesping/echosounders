# SPDX-FileCopyrightText: 2025 Peter Urban
#
# SPDX-License-Identifier: CC0-1.0 (only this file, not the whole project)

# Meson wrapper for GSFlib 'Generic Sensor Format' library from Leidos
# 'https://www.leidos.com/products/ocean-marine'

# --- Project ---
# Define project meta data
project(
  'GSF',
  ['c'], #language is c on linux/mac and cpp on windows
  license: 'LGPL-2.1',

  version: 'v3.11',
  default_options: ['warning_level=0', 'buildtype=release'],
  meson_version: '>=1.7.0' #latest tested version
)

project_name = 'GSF'
description = 'Meson wrapper for GSFlib "Generic Sensor Format" library from Leidos'
url = 'https://www.leidos.com/products/ocean-marine'

# --- dependencies ---
# libm (math library)
# Required is set to false because libm is only necessary and available if
# it is not already included in the compiler (e.g. gcc/linux)
cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required: false)

#only needed on windows
wsock32_dep = cc.find_library('wsock32', required : false)

# --- compile options ---
c_compile_args = [
  '-Wall',
  '-D_STRICT_ANSI',
  '-D_LARGEFILE64_SOURCE',
]
cpp_compile_args = [
]

# Force compile language to be c++ on windows (cl and clang-cl) (or if force-cpp option is enabled)
link_language = 'c'

# --- sources ---
program_sources = []

library_sources = [
  'gsf.c',
  'gsf_info.c',
  'gsf_indx.c',
  'gsf_geo.c',
  'gsf_enc.c',
  'gsf_dec.c',
  'gsf_compress.c',
]

export_headers = [
    'gsf.h',
    #'gsf_indx.h',
    #'gsf_ft.h',
    #'gsf_enc.h',
    #'gsf_dec.h',
    ]

# --- define library and dependencies ---
gsflib_lib = library(
  project_name,
  library_sources,
  c_args: c_compile_args,
  cpp_args: cpp_compile_args,
  dependencies: [m_dep, wsock32_dep],
  link_language: link_language,
  install: true,
)

gsflib_dep = declare_dependency(
  dependencies: [m_dep],
  link_with: [gsflib_lib],
  include_directories: include_directories('.'),
)

# --- Installation ---
# install headers
install_headers(export_headers)

# pkgconfig file
pkg = import('pkgconfig')
pkg.generate(
  description: description,
  url: url,
  version: meson.project_version(),
  name: project_name,
  libraries: gsflib_lib,
)

# --- define tests ---
# gsflib_exe = executable(
#   'gsw_check',
#   sources: [program_sources],
#   dependencies: [gsflib_dep],
#   c_args: c_compile_args,
#   cpp_args: cpp_compile_args,
#   link_language: link_language,
# )

# test('run_gsw_check', gsflib_exe)