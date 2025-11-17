# SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
#
# SPDX-License-Identifier: CC0-1.0

#---------- general test case header --------------

# --- add unittest_data directory as define (UNITTEST_DATA_DIR) ---
test_data_dir = '-DUNITTEST_DATA_DIR="@0@"'.format(meson.current_source_dir() + '/unittest_data')

testcomponent = 'echosounders'

sources = [
  'tutorial.test.cpp',
  'kongsbergall/datagrams/attitudedatagram.test.cpp',
  'kongsbergall/datagrams/clockdatagram.test.cpp',
  'kongsbergall/datagrams/depthorheightdatagram.test.cpp',
  'kongsbergall/datagrams/extradetections.test.cpp',
  'kongsbergall/datagrams/extraparameters.test.cpp',
  'kongsbergall/datagrams/headingdatagram.test.cpp',
  'kongsbergall/datagrams/installationparameters.test.cpp',
  'kongsbergall/datagrams/kongsbergalldatagram.test.cpp',
  'kongsbergall/datagrams/kongsbergallunknown.test.cpp',
  'kongsbergall/datagrams/networkattitudevelocitydatagram.test.cpp',
  'kongsbergall/datagrams/positiondatagram.test.cpp',
  'kongsbergall/datagrams/puidoutput.test.cpp',
  'kongsbergall/datagrams/pustatusoutput.test.cpp',
  'kongsbergall/datagrams/qualityfactordatagram.test.cpp',
  'kongsbergall/datagrams/rawrangeandangle.test.cpp',
  'kongsbergall/datagrams/runtimeparameters.test.cpp',
  'kongsbergall/datagrams/seabedimagedata.test.cpp',
  'kongsbergall/datagrams/singlebeamechosounderdepth.test.cpp',
  'kongsbergall/datagrams/soundspeedprofiledatagram.test.cpp',
  'kongsbergall/datagrams/surfacesoundspeeddatagram.test.cpp',
  'kongsbergall/datagrams/watercolumndatagram.test.cpp',
  'kongsbergall/datagrams/xyzdatagram.test.cpp',
  'kongsbergall/filedatatypes/calibration/kongsbergallwatercolumncalibration.test.cpp',
  'kongsbergall/filedatatypes/_sub/_sysinfos.test.cpp',
  'kongsbergall/filedatatypes/_sub/_wciinfos.test.cpp',
  'kongsbergall/filedatatypes/_sub/systeminformation.test.cpp',
  'kongsbergall/filedatatypes/_sub/watercolumninformation.test.cpp',
  'simradraw/datagrams/FIL1.test.cpp',
  'simradraw/datagrams/MRU0.test.cpp',
  'simradraw/datagrams/NME0.test.cpp',
  'simradraw/datagrams/RAW3.test.cpp',
  'simradraw/datagrams/TAG0.test.cpp',
  'simradraw/datagrams/XML0.test.cpp',
  'simradraw/datagrams/simradrawdatagram.test.cpp',
  'simradraw/datagrams/simradrawunknown.test.cpp',
  'simradraw/datagrams/xml_datagrams/xml_configuration.test.cpp',
  'simradraw/datagrams/xml_datagrams/xml_environment.test.cpp',
  'simradraw/datagrams/xml_datagrams/xml_node.test.cpp',
  'simradraw/datagrams/xml_datagrams/xml_parameter.test.cpp',
  'simradraw/datagrams/xml_datagrams/xml_parameter2.test.cpp',
  'simradraw/datagrams/xml_datagrams/xml_parameter3.test.cpp',
  'simradraw/datagrams/xml_datagrams/xml_pingsequence.test.cpp',
  'simradraw/datagrams/xml_datagrams/xml_sensor.test.cpp',
  'simradraw/datatypes/packagecache/cache_raw3.test.cpp',
  'simradraw/datatypes/packagecache/cache_xml_parameter.test.cpp',
  'simradraw/datatypes/calibration/simradrawwatercolumncalibration.test.cpp',
  'simradraw/datatypes/sub/transceiverinformation.test.cpp',
  'kmall/datagrams/iinstallationparam.test.cpp',
  'kmall/datagrams/iopruntime.test.cpp',
  'kmall/datagrams/kmalldatagram.test.cpp',
  'kmall/datagrams/kmallunknown.test.cpp',
  'kmall/datagrams/sclock.test.cpp',
  'kmall/datagrams/sposition.test.cpp',
  'kmall/datagrams/spositionerror.test.cpp',
  'gsf/datagrams/gsfunknown.test.cpp',
  'filetemplates/datatypes/datagraminfodata.test.cpp',
  'filetemplates/datatypes/filecache.test.cpp',
  'filetemplates/datatypes/packagecache/cache_structpackage.test.cpp',
  'filetemplates/datatypes/calibration/amplitudecalibration.test.cpp',
  'filetemplates/datatypes/calibration/multisectorwatercolumncalibration.test.cpp',
  'filetemplates/datatypes/calibration/watercolumncalibration.test.cpp',
  'pingtools/beamsampleselection.test.cpp',
  'pingtools/beamselection.test.cpp',
  'pingtools/pingsampleselector.test.cpp',
  'pingtools/readsamplerange.test.cpp',
]

foreach source : sources
    testname = projectnamespace + '._' + testcomponent + '.' + source.split('.')[0] + '_.test'
    testname = testname.replace('/', '.')

    testexe = executable(testname,
            sources: [source],
            dependencies : [catch2, echosounders_dep, boost_dep],
            link_language : 'cpp',
            override_options: [
            ],
            #install : true
            #cpp_pch: '../pch/echosounders_testname.hpp',
            cpp_args: [test_data_dir]
            )

    test(testname,testexe)
endforeach








