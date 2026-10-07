# SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

# --- Project ---
# Define project meta data
project(
  'themachinethatgoesping_echosounders',
  'cpp',
  license: 'MPL-2.0',

  version: '0.49.0',
  default_options: ['warning_level=0', 'buildtype=release', 'cpp_std=c++26'],
  meson_version: '>=1.8.1' #there is a problem with meson 1.8.0 so just use a higher version
)

projectnamespace = 'themachinethatgoesping'

# --- Windows / MSVC STL note (SIMD std::find in bind_vector) ---
# clang-cl and MSVC route std::find / std::count / std::remove (instantiated by
# nanobind's bind_vector for __contains__ / count / remove) through a manually
# vectorized (SIMD) implementation whenever the element type is "trivially
# equality comparable" (clang-cl assumes this for a defaulted operator==). That
# SIMD path only supports element sizes of 1, 2, 4 or 8 bytes, so a tightly
# packed, all-integer datagram substruct of another size (e.g. the 6-byte
# s7k FileHeaderDeviceInfo or 14-byte SnippetDataBeam) failed to compile with
# 'static assertion failed: unexpected size'.
#
# Fix: those two substructs give a *user-provided* (non-defaulted) operator==,
# which makes them not trivially-equality-comparable, so the scalar std::find is
# used instead. This is fine-grained (only the affected 2 substructs), keeps the
# exact on-disk byte layout, and does NOT disable the SIMD algorithms elsewhere.
# See the substruct headers and the tmtgp-echosounders-record-parsers skill.
#
# The project-wide escape hatch below (fall back to scalar for ALL element sizes)
# is therefore not needed; it is kept here only for reference.
# See https://github.com/microsoft/STL/issues/6294 and
# https://learn.microsoft.com/cpp/standard-library/vectorized-stl-algorithms
# if meson.get_compiler('cpp').get_argument_syntax() == 'msvc'
#   add_project_arguments('/D_USE_STD_VECTOR_ALGORITHMS=0', language: 'cpp')
# endif

# --- dependencies ---

# boost
boost_dep = dependency('boost', modules: 'iostreams', static: get_option('dynamic_boost').disabled())

# pugixml
pugixml_dep = subproject('pugixml', default_options: ['warning_level=0', 'default_library=static']).get_variable('pugixml_dep').as_system('system')

# themachinethatgoesping
# tools
tools_dep = dependency('themachinethatgoesping_tools', required: false)
if not tools_dep.found()
    tools_dep = subproject('tools', default_options: ['cpp_std=' + get_option('cpp_std')]).get_variable('tools_dep')
endif

# algorithms
algorithms_dep = dependency('themachinethatgoesping_algorithms', required: false)
if not algorithms_dep.found()
    algorithms_dep = subproject('algorithms', default_options: ['cpp_std=' + get_option('cpp_std')]).get_variable('algorithms_dep')
endif

# -- python modules --
if get_option('build_pythonmodule').enabled()
  pymod = import('python').find_installation(get_option('python_path'), pure: false)

  python3_dep = pymod.dependency()
  # nanobind: split mode uses a header-only frontend dependency + abi3 stable
  # ABI (the libnanobind backend lives in a separate 'nanobind_backend' module
  # imported at runtime); classic mode links libnanobind into the extension.
  # split_mode defaults to enabled only for the top-level themachinethatgoesping
  # package; standalone subproject builds default to classic (see meson_options).
  # See https://nanobind.readthedocs.io/en/latest/split_mode.html
  if get_option('split_mode').allowed()
    nanobind_subp = subproject('nanobind')
    nanobind_dep = nanobind_subp.get_variable('nanobind_frontend_dep')
    nanobind_limited_api = nanobind_subp.get_variable('nanobind_stable_abi')
  else
    nanobind_dep = dependency('nanobind',  version : '>=2.9.1')
    nanobind_limited_api = ''
  endif
  
  tools_nanobind_dep = dependency('themachinethatgoesping_tools_nanobind', required: false)

  if not tools_nanobind_dep.found()
      tools_nanobind_dep = subproject('tools').get_variable('tools_nanobind_dep')
  endif

  # set path where to install sources (pythonpath/site-packages/projectnamespace)
  message('python module install directory:', pymod.get_install_dir(subdir: projectnamespace))
endif

# navigation
navigation_dep = dependency('themachinethatgoesping_navigation', required: false)
if not navigation_dep.found()
    navigation_dep = subproject('navigation', default_options: ['cpp_std=' + get_option('cpp_std')]).get_variable('navigation_dep')
endif

#themachinethatgoesping meta info
meta_dep = dependency('themachinethatgoesping_meta', required: false)
if not meta_dep.found()
    meta_dep = subproject('meta').get_variable('meta_dep')
endif

# add src
subdir('src')
 
# add python files
subdir('python')
