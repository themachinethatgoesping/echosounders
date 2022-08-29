# SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

# --- Project ---
# Define project meta data
project(
  'themachinethatgoesping_echosounders',
  'cpp',
  license: 'MPL-2.0',

  version: '0.3.0',
  default_options: ['warning_level=3', 'buildtype=release', 'cpp_std=c++17'],
  meson_version: '>=0.63' #0.63 added preserve_path for install headers option
)

projectnamespace = 'themachinethatgoesping'

# --- dependencies ---

# system
if meson.get_compiler('cpp').get_id() == 'clang'
  omp_dep = declare_dependency(
    compile_args: ['-Xpreprocessor', '-fopenmp']
  )
else
  omp_dep = dependency('openmp')
endif

# boost
boost_dep = dependency('boost', modules: 'iostreams', static: true)

# pugixml
pugixml_dep = dependency('pugixml', required: false)
if not pugixml_dep.found()
    pugixml_dep = subproject('pugixml').get_variable('pugixml_dep')
endif

# xtensor_python
xtensor_python_dep = dependency('xtensor-python', required: false)
if not xtensor_python_dep.found()
    xtensor_python_dep = subproject('xtensor-python').get_variable('xtensor_python_dep')
endif

# themachinethatgoesping
# tools
tools_dep = dependency('themachinethatgoesping_tools', required: false)
if not tools_dep.found()
    tools_dep = subproject('tools').get_variable('tools_dep')
endif

# navigation
navigation_dep = dependency('themachinethatgoesping_navigation', required: false)
if not navigation_dep.found()
    navigation_dep = subproject('navigation').get_variable('navigation_dep')
endif

#themachinethatgoesping meta info
meta_dep = dependency('themachinethatgoesping_meta', required: false)
if not meta_dep.found()
    meta_dep = subproject('meta').get_variable('meta_dep')
endif

# add src
subdir('src')
 
# add python files
#subdir('python')
