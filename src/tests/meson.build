# SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

#---------- general test case header --------------

testcomponent = 'echosounders'

sources = [
    'tutorial.test.cpp',
    'simrad/datagrams/ek60_datagram.test.cpp',
    'simrad/datagrams/ek60_unknown.test.cpp',
    'simrad/datagrams/ek80_MRU0.test.cpp',
    'simrad/datagrams/ek80_TAG0.test.cpp',
    'simrad/datagrams/ek80_XML0.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_node.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_environment.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_initialparameter.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_parameter.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_sensor.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_pingsequence.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_configuration.test.cpp'
]

foreach source : sources
    testname = projectnamespace + '._' + testcomponent + '.' + source.split('.')[0] + '_.test'
    testname = testname.replace('/', '.')

    testexe = executable(testname,
            sources: [source, 'test_main.cpp'],
            dependencies : [catch2, echosounders_dep],
            link_language : 'cpp',
            override_options: [
            ],
            #install : true
            )

    test(testname,testexe)
endforeach








