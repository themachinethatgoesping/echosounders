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
    'simrad/datagrams/c_simraddatagram.cpp',
    'simrad/datagrams/c_simradunknown.cpp',
    'simrad/datagrams/c_MRU0.cpp',
    'simrad/datagrams/c_TAG0.cpp',
    'simrad/datagrams/c_NME0.cpp',
    'simrad/datagrams/c_XML0.cpp',
    'simrad/datagrams/c_FIL1.cpp',
    'simrad/datagrams/c_RAW3.cpp',
    'simrad/datagrams/xml_datagrams/module.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_node.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_parameter_channel.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_parameter.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_initialparameter.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_pingsequence_ping.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_pingsequence.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_environment_transducer.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_environment.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_sensor.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_configuration_sensor_telegramvalue.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_configuration_sensor_telegram.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_configuration_sensor.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_configuration_transducer.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_configuration_activepingmode.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_configuration_transceiver_channel_frequencypar.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_configuration_transceiver_channel_transducer.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_configuration_transceiver_channel.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_configuration_transceiver.cpp',
    'simrad/datagrams/xml_datagrams/c_xml_configuration.cpp',
    'simrad/datagrams/xml_datagrams/c_channelconfiguration.cpp',
    'simrad/datagrams/RAW3_datatypes/module.cpp',
    'simrad/datagrams/RAW3_datatypes/c_i_RAW3_data.cpp',
    'simrad/datagrams/RAW3_datatypes/c_RAW3_datacomplexfloat32.cpp',
    'simrad/datagrams/RAW3_datatypes/c_RAW3_datapowerandangle.cpp',
    'simrad/datagrams/RAW3_datatypes/c_RAW3_datapower.cpp',
    'simrad/datagrams/RAW3_datatypes/c_RAW3_dataangle.cpp',
    'simrad/datagrams/RAW3_datatypes/c_RAW3_dataskipped.cpp',
    'simrad/c_fileraw.cpp',
    'simrad/c_simradping.cpp',
    'simrad/c_simradfiledata.cpp',
    'simrad/c_simradnavigationdatainterface.cpp',
    'simrad/c_file_test_functions.cpp',
]

# define python module
py_navigation = pymod.extension_module(
    module_name,
    sources: sources,
    dependencies : [
        echosounders_dep,
        tools_pybind_dep,
        pybind11_dep,
        python3_dep],
    link_language : 'cpp',
    override_options: [
    ],
    cpp_args : ['-DMODULE_NAME='+module_name, '-DMODULE_VERSION=' + '"' + meson.project_version() + '"'],
    install : true,
    install_dir : pythoninstallpath,
    install_tag : 'python-runtime'
)



        
