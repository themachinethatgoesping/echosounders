# SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

# -- module name
module_name = 'echosounders'
        
# -- sources
sources = [
    'module.cpp',
    'simrad/module.cpp',
    'simrad/datagrams/module.cpp',
    'simrad/datagrams/c_ek60_datagram.cpp',
    'simrad/datagrams/c_ek60_unknown.cpp',
    'simrad/datagrams/c_ek80_MRU0.cpp',
    'simrad/datagrams/c_ek60_NME0.cpp',
    'simrad/datagrams/c_ek80_XML0.cpp',
    'simrad/datagrams/xml_datagrams/module.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_node.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_parameter_channel.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_pingsequence.cpp',
    'simrad/c_fileraw.cpp'
]

# define python module
py_navigation = pymod.extension_module(
    module_name,
    sources: sources,
    dependencies : [
        echosounders_dep,
        xtensor_python_dep,
        pybind11_dep,
        python3_dep,
        numpy_dep],
    link_language : 'cpp',
    override_options: [
    ],
    cpp_args : ['-DMODULE_NAME='+module_name, '-DMODULE_VERSION=' + '"' + meson.project_version() + '"'],
    install : true,
    install_dir : pythoninstallpath,
    install_tag : 'python-runtime'
)



        
