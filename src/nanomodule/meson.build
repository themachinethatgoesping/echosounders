# SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

# -- module name
module_name = 'echosounders_nanopy'
        
# -- sources
sources = [
  'module.cpp',
  'py_filetemplates/module.cpp',
  'py_filetemplates/py_datatypes/c_filecache.cpp',
  'py_filetemplates/py_datatypes/c_i_ping.cpp',
  'py_filetemplates/py_datatypes/c_i_pingbottom.cpp',
  'py_filetemplates/py_datatypes/c_i_pingcommon.cpp',
  'py_filetemplates/py_datatypes/c_i_pingfiledata.cpp',
  'py_filetemplates/py_datatypes/c_i_pingwatercolumn.cpp',
  'py_filetemplates/py_datatypes/py_cache_structures/c_filepackagecache.cpp',
  'py_filetemplates/py_datatypes/py_calibration/c_amplitudecalibration.cpp',
  'py_filetemplates/py_datatypes/py_calibration/c_multisectorwatercolumncalibration.cpp',
  'py_filetemplates/py_datatypes/py_calibration/c_watercolumncalibration.cpp',
  'py_gsf/c_gsffilehandler.cpp',
  'py_gsf/module.cpp',
  'py_pingtools/c_beamsampleselection.cpp',
  'py_pingtools/c_beamselection.cpp',
  'py_pingtools/c_pingsampleselector.cpp',
  'py_pingtools/c_readsamplerange.cpp',
  'py_pingtools/module.cpp',
]

# define python module
py_navigation = pymod.extension_module(
    module_name,
    sources: sources,
    dependencies : [
        echosounders_dep,
        tools_nanobind_dep,
        nanobind_dep,
        python3_dep],
    link_language : 'cpp',
    # cpp_pch : 'pch/pch.hpp',
    override_options: [
    ],
    cpp_args : ['-DMODULE_NAME='+module_name, '-DMODULE_VERSION=' + '"' + meson.project_version() + '"'],
    install : true,
    subdir : projectnamespace,
    install_tag : 'python-runtime',
    override_options: ['unity=off']
)



        
