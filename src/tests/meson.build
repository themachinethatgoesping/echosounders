# SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

#---------- general test case header --------------

testcomponent = 'echosounders'

sources = [
    'tutorial.test.cpp',
    'simrad/datagrams/simraddatagram.test.cpp',
    'simrad/datagrams/simradunknown.test.cpp',
    'simrad/datagrams/FIL1.test.cpp',
    'simrad/datagrams/MRU0.test.cpp',
    'simrad/datagrams/NME0.test.cpp',
    'simrad/datagrams/RAW3.test.cpp',
    'simrad/datagrams/TAG0.test.cpp',
    'simrad/datagrams/XML0.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_node.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_environment.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_parameter3.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_parameter2.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_parameter.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_sensor.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_pingsequence.test.cpp',
    'simrad/datagrams/xml_datagrams/xml_configuration.test.cpp',

    'em3000/datagrams/em3000datagram.test.cpp',
    'em3000/datagrams/em3000unknown.test.cpp',
    'em3000/datagrams/xyzdatagram.test.cpp',
    'em3000/datagrams/extradetections.test.cpp',
    'em3000/datagrams/rawrangeandangle.test.cpp',
    'em3000/datagrams/seabedimagedata.test.cpp',
    'em3000/datagrams/watercolumndatagram.test.cpp',
    'em3000/datagrams/qualityfactordatagram.test.cpp',
    'em3000/datagrams/attitudedatagram.test.cpp',
    'em3000/datagrams/networkattitudevelocitydatagram.test.cpp',
    'em3000/datagrams/clockdatagram.test.cpp',
    'em3000/datagrams/depthorheightdatagram.test.cpp',
    'em3000/datagrams/headingdatagram.test.cpp',
    'em3000/datagrams/positiondatagram.test.cpp',
    'em3000/datagrams/singlebeamechosounderdepth.test.cpp',
    'em3000/datagrams/surfacesoundspeeddatagram.test.cpp',
    'em3000/datagrams/soundspeedprofiledatagram.test.cpp',
    'em3000/datagrams/installationparameters.test.cpp',
    'em3000/datagrams/runtimeparameters.test.cpp',
    'em3000/datagrams/extraparameters.test.cpp',
    'em3000/datagrams/pustatusoutput.test.cpp',
    'em3000/datagrams/puidoutput.test.cpp',
]

foreach source : sources
    testname = projectnamespace + '._' + testcomponent + '.' + source.split('.')[0] + '_.test'
    testname = testname.replace('/', '.')

    testexe = executable(testname,
            sources: [source],
            dependencies : [catch2, echosounders_dep],
            link_language : 'cpp',
            override_options: [
            ],
            #install : true
            )

    test(testname,testexe)
endforeach








