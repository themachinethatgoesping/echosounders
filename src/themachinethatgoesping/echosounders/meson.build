# SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

# -- library setup --
libname   = projectnamespace + '_echosounders'
headerdir = projectnamespace + '/echosounders'

# -- source files --
sources = [
]

headers = [
  'fileinterfaces/i_inputfile.hpp',
  'simrad/fileraw.hpp',
  'simrad/ek60_types.hpp',
  'simrad/datagrams/ek60_datagram.hpp'
]

# -- targets --
# for now force static linking on windows
if build_machine.system() != 'linux'
  echosounders_lib = static_library(libname,sources,
                        dependencies : [
                          boost_dep, 
                          omp_dep,
                          pugixml_dep,
                          tools_dep,
                          navigation_dep
                          ],
                        override_options: [
                          'b_lundef=false'
                      ],
                        install : true, 
                        install_tag : 'library'
                        )
else  
  echosounders_lib = library(libname,sources,
                        dependencies : [
                          boost_dep, 
                          omp_dep,
                          pugixml_dep,
                          tools_dep,
                          navigation_dep
                          ],
                        override_options: [
                          'b_lundef=false'
                      ],
                        install : true, 
                        install_tag : 'library'
                        )
endif
                      

# -- internal dependency --
echosounders_dep = declare_dependency(
  dependencies : [
    boost_dep,
    omp_dep,
    pugixml_dep,
    tools_dep,
    navigation_dep
  ],
  link_with : [echosounders_lib],
  include_directories : ['../../']
  )


# -- installation setup --

# install headers
if headers != ['']
    install_headers(headers, subdir: headerdir+'/', preserve_path: true)
endif

# create pkgconfig file
pkg = import('pkgconfig')
pkg.generate(echosounders_lib,
             description : 'Library for reading, writing and processing single- and multibeam echsounder data formats.',
             url : 'https://github.com/themachinethatgoesping/echosounders')
