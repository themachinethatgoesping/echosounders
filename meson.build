# SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

# --- Project ---
# Define project meta data
project(
  'themachinethatgoesping_echosounders',
  'cpp',
  license: 'MPL-2.0',

  version: '0.13.10',
  default_options: ['warning_level=2', 'buildtype=release', 'cpp_std=c++17'],
  meson_version: '>=1.0' #last meson version that was tested
)

projectnamespace = 'themachinethatgoesping'

# --- dependencies ---

# system
if meson.get_compiler('cpp').get_id() == 'clang'
  omp_dep = declare_dependency(
    compile_args: ['-Xpreprocessor', '-fopenmp', '-I/usr/local/opt/libomp/include', '-L/usr/local/opt/libomp/lib', '-lomp']
  )
else
  omp_dep = dependency('openmp')
endif

# boost
boost_dep = dependency('boost', modules: 'iostreams', static: true)

# pugixml
pugixml_dep = subproject('pugixml', default_options: 'default_library=static').get_variable('pugixml_dep')

# themachinethatgoesping
# tools
tools_dep = dependency('themachinethatgoesping_tools', required: false)
if not tools_dep.found()
    tools_dep = subproject('tools').get_variable('tools_dep')
endif

# -- python modules --
if get_option('build_pythonmodule').enabled()
  pymod = import('python').find_installation(get_option('python_path'))

  python3_dep = pymod.dependency()
  pybind11_dep = dependency('pybind11')
  
  tools_pybind_dep = dependency('themachinethatgoesping_tools_pybind', required: false)

  if not tools_pybind_dep.found()
      tools_pybind_dep = subproject('tools').get_variable('tools_pybind_dep')
  endif

  # set path where to install sources (pythonpath/site-packages/projectnamespace)
  pythoninstallpath = pymod.get_install_dir() + projectnamespace + '/'
  message('python module install directory:', pythoninstallpath)
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
