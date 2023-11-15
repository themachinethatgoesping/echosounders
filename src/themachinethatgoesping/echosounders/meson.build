# SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

# -- library setup --
libname   = projectnamespace + '_echosounders'
headerdir = projectnamespace + '/echosounders'

# -- source files --
sources = [
]

headers = [
  'filetemplates/i_inputfilehandler.hpp',
  'filetemplates/datacontainers/datagramcontainer.hpp',
  'filetemplates/datatypes/i_ping.hpp',

  'pingtools/pingsampleselector.hpp',
  'pingtools/beamsampleselection.hpp',

  'simradrawfilehandler.hpp',
  'simradraw/types.hpp',
  'simradraw/datagrams.hpp',
  'simradraw/filedatatypes/simradrawping.hpp',
  'simradraw/datagrams/simradrawdatagram.hpp',
  'simradraw/datagrams/simradrawunknown.hpp',
  'simradraw/datagrams/FIL1.hpp',
  'simradraw/datagrams/MRU0.hpp',
  'simradraw/datagrams/NME0.hpp',
  'simradraw/datagrams/RAW3.hpp',
  'simradraw/datagrams/TAG0.hpp',
  'simradraw/datagrams/XML0.hpp',
  'simradraw/datagrams/raw3datatypes/t_raw3datatype.hpp',
  'simradraw/datagrams/raw3datatypes/i_raw3data.hpp',
  'simradraw/datagrams/raw3datatypes/raw3dataskipped.hpp',
  'simradraw/datagrams/raw3datatypes/raw3dataangle.hpp',
  'simradraw/datagrams/raw3datatypes/raw3datapower.hpp',
  'simradraw/datagrams/raw3datatypes/raw3datapowerandangle.hpp',
  'simradraw/datagrams/raw3datatypes/raw3datacomplexfloat32.hpp',
  'simradraw/datagrams/raw3datatypes/raw3datatypes.hpp',
  'simradraw/datagrams/xml_datagrams/helper.hpp',
  'simradraw/datagrams/xml_datagrams/xml_node.hpp',
  'simradraw/datagrams/xml_datagrams/xml_parameter_channel.hpp',
  'simradraw/datagrams/xml_datagrams/xml_parameter.hpp',
  'simradraw/datagrams/xml_datagrams/xml_initialparameter.hpp',
  'simradraw/datagrams/xml_datagrams/xml_pingsequence_ping.hpp',
  'simradraw/datagrams/xml_datagrams/xml_pingsequence.hpp',
  'simradraw/datagrams/xml_datagrams/xml_environment_transducer.hpp',
  'simradraw/datagrams/xml_datagrams/xml_environment.hpp',
  'simradraw/datagrams/xml_datagrams/xml_sensor.hpp',
  'simradraw/datagrams/xml_datagrams/xml_configuration_sensor_telegramvalue.hpp',
  'simradraw/datagrams/xml_datagrams/xml_configuration_sensor_telegram.hpp',
  'simradraw/datagrams/xml_datagrams/xml_configuration_sensor.hpp',
  'simradraw/datagrams/xml_datagrams/xml_configuration_transducer.hpp',
  'simradraw/datagrams/xml_datagrams/xmlconfigurationactivepingmode.hpp',
  'simradraw/datagrams/xml_datagrams/xml_configuration_transceiver_channel.hpp',
  'simradraw/datagrams/xml_datagrams/xml_configuration_transceiver_channel_frequencypar.hpp',
  'simradraw/datagrams/xml_datagrams/xmlconfigurationtransceiverchanneltransducer.hpp',
  'simradraw/datagrams/xml_datagrams/xml_configuration_transceiver.hpp',
  'simradraw/datagrams/xml_datagrams/xml_configuration.hpp',
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
                          navigation_dep,
                          algorithms_dep
                          ],
                          # cpp_pch : 'pch/pch.hpp',
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
                          navigation_dep,
                          algorithms_dep
                          ],
                          # cpp_pch : 'pch/pch.hpp',
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
    navigation_dep,
    algorithms_dep
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
