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
  'filetemplates/i_inputfile.hpp',
  'filetemplates/datacontainers/datagramcontainer.hpp',
  'filetemplates/datatypes/i_ping.hpp',

  'pingtools/pingsampleselector.hpp',
  'pingtools/pingsampleselection.hpp',
  'pingtools/substructures/beamsampleselection.hpp',

  'simrad/filesimradraw.hpp',
  'simrad/simrad_types.hpp',
  'simrad/simrad_datagrams.hpp',
  'simrad/filedatatypes/simradping.hpp',
  'simrad/datagrams/simraddatagram.hpp',
  'simrad/datagrams/simradunknown.hpp',
  'simrad/datagrams/FIL1.hpp',
  'simrad/datagrams/MRU0.hpp',
  'simrad/datagrams/NME0.hpp',
  'simrad/datagrams/RAW3.hpp',
  'simrad/datagrams/TAG0.hpp',
  'simrad/datagrams/XML0.hpp',
  'simrad/datagrams/raw3datatypes/t_raw3datatype.hpp',
  'simrad/datagrams/raw3datatypes/i_raw3data.hpp',
  'simrad/datagrams/raw3datatypes/raw3dataskipped.hpp',
  'simrad/datagrams/raw3datatypes/raw3dataangle.hpp',
  'simrad/datagrams/raw3datatypes/raw3datapower.hpp',
  'simrad/datagrams/raw3datatypes/raw3datapowerandangle.hpp',
  'simrad/datagrams/raw3datatypes/raw3datacomplexfloat32.hpp',
  'simrad/datagrams/raw3datatypes/raw3datatypes.hpp',
  'simrad/datagrams/xml_datagrams/helper.hpp',
  'simrad/datagrams/xml_datagrams/xml_node.hpp',
  'simrad/datagrams/xml_datagrams/xml_parameter_channel.hpp',
  'simrad/datagrams/xml_datagrams/xml_parameter.hpp',
  'simrad/datagrams/xml_datagrams/xml_initialparameter.hpp',
  'simrad/datagrams/xml_datagrams/xml_pingsequence_ping.hpp',
  'simrad/datagrams/xml_datagrams/xml_pingsequence.hpp',
  'simrad/datagrams/xml_datagrams/xml_environment_transducer.hpp',
  'simrad/datagrams/xml_datagrams/xml_environment.hpp',
  'simrad/datagrams/xml_datagrams/xml_sensor.hpp',
  'simrad/datagrams/xml_datagrams/xml_configuration_sensor_telegramvalue.hpp',
  'simrad/datagrams/xml_datagrams/xml_configuration_sensor_telegram.hpp',
  'simrad/datagrams/xml_datagrams/xml_configuration_sensor.hpp',
  'simrad/datagrams/xml_datagrams/xml_configuration_transducer.hpp',
  'simrad/datagrams/xml_datagrams/xmlconfigurationactivepingmode.hpp',
  'simrad/datagrams/xml_datagrams/xml_configuration_transceiver_channel.hpp',
  'simrad/datagrams/xml_datagrams/xml_configuration_transceiver_channel_frequencypar.hpp',
  'simrad/datagrams/xml_datagrams/xmlconfigurationtransceiverchanneltransducer.hpp',
  'simrad/datagrams/xml_datagrams/xml_configuration_transceiver.hpp',
  'simrad/datagrams/xml_datagrams/xml_configuration.hpp',
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
