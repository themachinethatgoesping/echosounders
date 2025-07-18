# SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

# --- Project ---
# Define project meta data
project(
  'themachinethatgoesping_echosounders',
  'cpp',
  license: 'MPL-2.0',

  version: '0.45.3',
  default_options: ['warning_level=2', 'buildtype=release', 'cpp_std=c++20'],
  meson_version: '>=1.8.1' #there is a problem with meson 1.8.0 so just use a higher version
)

projectnamespace = 'themachinethatgoesping'

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
  pybind11_dep = dependency('pybind11')
  
  tools_pybind_dep = dependency('themachinethatgoesping_tools_pybind', required: false)

  if not tools_pybind_dep.found()
      tools_pybind_dep = subproject('tools').get_variable('tools_pybind_dep')
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
