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
  'fileinterfaces/i_inputfileiterator.hpp',
  'fileinterfaces/i_pinginterface.hpp',
  'fileinterfaces/i_pingiterator.hpp',
  'fileinterfaces/i_ping.hpp',
  'simrad/fileraw.hpp',
  'simrad/simrad_types.hpp',
  'simrad/simrad_datagrams.hpp',
  'simrad/simradping.hpp',
  'simrad/simradpinginterface.hpp',
  'simrad/simradpingiterator.hpp',
  'simrad/datagrams/simraddatagram.hpp',
  'simrad/datagrams/simradunknown.hpp',
  'simrad/datagrams/FIL1.hpp',
  'simrad/datagrams/MRU0.hpp',
  'simrad/datagrams/NME0.hpp',
  'simrad/datagrams/RAW3.hpp',
  'simrad/datagrams/TAG0.hpp',
  'simrad/datagrams/XML0.hpp',
  'simrad/datagrams/RAW3_datatypes/t_RAW3_datatype.hpp',
  'simrad/datagrams/RAW3_datatypes/i_RAW3_data.hpp',
  'simrad/datagrams/RAW3_datatypes/RAW3_dataskipped.hpp',
  'simrad/datagrams/RAW3_datatypes/RAW3_dataangle.hpp',
  'simrad/datagrams/RAW3_datatypes/RAW3_datapower.hpp',
  'simrad/datagrams/RAW3_datatypes/RAW3_datapowerandangle.hpp',
  'simrad/datagrams/RAW3_datatypes/RAW3_datacomplexfloat32.hpp',
  'simrad/datagrams/RAW3_datatypes/RAW3_datatypes.hpp',
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
  'simrad/datagrams/xml_datagrams/xml_configuration_activepingmode.hpp',
  'simrad/datagrams/xml_datagrams/xml_configuration_transceiver_channel.hpp',
  'simrad/datagrams/xml_datagrams/xml_configuration_transceiver_channel_frequencypar.hpp',
  'simrad/datagrams/xml_datagrams/xml_configuration_transceiver_channel_transducer.hpp',
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
