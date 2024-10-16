// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <themachinethatgoesping/echosounders/simradraw/types.hpp>

// note: this must be defined below the simradraw/simradraw includes otherwise
// datagram_identifier_to_string is unknown
#include <themachinethatgoesping/echosounders/simradraw/filedatatypes/calibration/simradrawwatercolumncalibration.hpp>

std::string xml_string =
    "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\n<Configuration>\n    <Header "
    "Copyright=\"Copyright(c) Kongsberg Maritime AS, Norway\" ApplicationName=\"EK80\" "
    "Version=\"2.0.1.0\" FileFormatVersion=\"1.23\" TimeBias=\"0\" />\n    <ActivePingMode "
    "Mode=\"Direct\" />\n    <Transceivers MergeOperation=\"AddNodeTree\">\n        <Transceiver "
    "TransceiverName=\"WBT 400040\" IPAddress=\"157.237.15.105\" MarketSegment=\"Scientific\" "
    "SerialNumber=\"400040\" Impedance=\"5400\" Multiplexing=\"0\" RxSampleFrequency=\"1500000\" "
    "EthernetAddress=\"009072061aa8\" Version=\"[0] Ethernet: 00:90:72:06:1A:A8&#x0D;&#x0A;[1] "
    "Parts-list: WBT 371790/F&#x0D;&#x0A;[2] Product: WBT&#x0D;&#x0A;IP Address: "
    "157.237.15.105&#x0D;&#x0A;Subnet mask: 255.255.0.0&#x0D;&#x0A;Default gateway: "
    "157.237.15.1&#x0D;&#x0A;Serial number: 400040&#x0D;&#x0A;Embedded software: Rev. "
    "2.54&#x0D;&#x0A;FPGA TX firmware: Rev. 5&#x0D;&#x0A;FPGA RX firmware: Rev. 7&#x0D;&#x0A;CH1: "
    "520W CH2: 497W CH3: 490W CH4: 490W&#x0D;&#x0A;TRD1: Unable to detect "
    "transducer&#x0D;&#x0A;TRD2: Unable to detect transducer&#x0D;&#x0A;TRD3: Unable to detect "
    "transducer&#x0D;&#x0A;TRD4: Unable to detect transducer&#x0D;&#x0A;\" "
    "TransceiverSoftwareVersion=\"2.54\" TransceiverNumber=\"1\" TransceiverType=\"WBT\">\n        "
    "    <Channels>\n                <Channel ChannelID=\"WBT 400040-15 ES38-7_ES\" "
    "LogicalChannelID=\"WBT 400040-15 ES38-7\" ChannelIdShort=\"ES38-7 Serial No: 331 - Narrow\" "
    "MaxTxPowerTransceiver=\"2000\" HWChannelConfiguration=\"15\" "
    "PulseDuration=\"0.000256;0.000512;0.001024;0.002048;0.004096\" "
    "PulseDurationFM=\"0.000512;0.001024;0.002048;0.004096;0.008192\">\n                    "
    "<Transducer TransducerName=\"ES38-7\" ArticleNumber=\"321842\" SerialNumber=\"331\" "
    "Frequency=\"38000\" FrequencyMinimum=\"34000\" FrequencyMaximum=\"45000\" "
    "MaxTxPowerTransducer=\"2000\" Gain=\"25.5;25.5;25.5;25.5;25.5\" SaCorrection=\"0;0;0;0;0\" "
    "EquivalentBeamAngle=\"-20.7\" DirectivityDropAt2XBeamWidth=\"0\" "
    "AngleSensitivityAlongship=\"18\" AngleSensitivityAthwartship=\"18\" "
    "AngleOffsetAlongship=\"0\" AngleOffsetAthwartship=\"0\" BeamWidthAlongship=\"7\" "
    "BeamWidthAthwartship=\"7\" BeamType=\"65\">\n                        <FrequencyPar "
    "Frequency=\"34000\" Gain=\"26.24\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.9\" "
    "BeamWidthAthwartship=\"7.2\" AngleOffsetAlongship=\"-0.11\" AngleOffsetAthwartship=\"0.1\" "
    "/>\n                        <FrequencyPar Frequency=\"34099\" Gain=\"26.24\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.92\" BeamWidthAthwartship=\"7.46\" "
    "AngleOffsetAlongship=\"-0.01\" AngleOffsetAthwartship=\"0.09\" />\n                        "
    "<FrequencyPar Frequency=\"34198\" Gain=\"26.27\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.94\" BeamWidthAthwartship=\"7.73\" AngleOffsetAlongship=\"0.04\" "
    "AngleOffsetAthwartship=\"0.07\" />\n                        <FrequencyPar Frequency=\"34297\" "
    "Gain=\"26.3\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.95\" "
    "BeamWidthAthwartship=\"7.92\" AngleOffsetAlongship=\"0.07\" AngleOffsetAthwartship=\"0.05\" "
    "/>\n                        <FrequencyPar Frequency=\"34396\" Gain=\"26.31\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.93\" BeamWidthAthwartship=\"8.06\" "
    "AngleOffsetAlongship=\"0.09\" AngleOffsetAthwartship=\"0.03\" />\n                        "
    "<FrequencyPar Frequency=\"34495\" Gain=\"26.3\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.9\" BeamWidthAthwartship=\"8.18\" AngleOffsetAlongship=\"0.12\" "
    "AngleOffsetAthwartship=\"0.03\" />\n                        <FrequencyPar Frequency=\"34594\" "
    "Gain=\"26.29\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.91\" "
    "BeamWidthAthwartship=\"8.25\" AngleOffsetAlongship=\"0.15\" AngleOffsetAthwartship=\"0.03\" "
    "/>\n                        <FrequencyPar Frequency=\"34693\" Gain=\"26.27\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.93\" BeamWidthAthwartship=\"8.27\" "
    "AngleOffsetAlongship=\"0.18\" AngleOffsetAthwartship=\"0.03\" />\n                        "
    "<FrequencyPar Frequency=\"34792\" Gain=\"26.28\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.87\" BeamWidthAthwartship=\"8.3\" AngleOffsetAlongship=\"0.18\" "
    "AngleOffsetAthwartship=\"0.03\" />\n                        <FrequencyPar Frequency=\"34891\" "
    "Gain=\"26.3\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.85\" "
    "BeamWidthAthwartship=\"8.18\" AngleOffsetAlongship=\"0.18\" AngleOffsetAthwartship=\"0.03\" "
    "/>\n                        <FrequencyPar Frequency=\"34990\" Gain=\"26.38\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.8\" BeamWidthAthwartship=\"8.05\" "
    "AngleOffsetAlongship=\"0.16\" AngleOffsetAthwartship=\"0.04\" />\n                        "
    "<FrequencyPar Frequency=\"35090\" Gain=\"26.46\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.7\" BeamWidthAthwartship=\"7.91\" AngleOffsetAlongship=\"0.14\" "
    "AngleOffsetAthwartship=\"0.04\" />\n                        <FrequencyPar Frequency=\"35189\" "
    "Gain=\"26.58\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.66\" "
    "BeamWidthAthwartship=\"7.76\" AngleOffsetAlongship=\"0.12\" AngleOffsetAthwartship=\"0.05\" "
    "/>\n                        <FrequencyPar Frequency=\"35288\" Gain=\"26.68\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.63\" BeamWidthAthwartship=\"7.68\" "
    "AngleOffsetAlongship=\"0.11\" AngleOffsetAthwartship=\"0.05\" />\n                        "
    "<FrequencyPar Frequency=\"35387\" Gain=\"26.77\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.61\" BeamWidthAthwartship=\"7.59\" AngleOffsetAlongship=\"0.09\" "
    "AngleOffsetAthwartship=\"0.06\" />\n                        <FrequencyPar Frequency=\"35486\" "
    "Gain=\"26.85\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.58\" "
    "BeamWidthAthwartship=\"7.52\" AngleOffsetAlongship=\"0.08\" AngleOffsetAthwartship=\"0.06\" "
    "/>\n                        <FrequencyPar Frequency=\"35585\" Gain=\"26.89\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.56\" BeamWidthAthwartship=\"7.5\" "
    "AngleOffsetAlongship=\"0.07\" AngleOffsetAthwartship=\"0.06\" />\n                        "
    "<FrequencyPar Frequency=\"35684\" Gain=\"26.93\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.54\" BeamWidthAthwartship=\"7.48\" AngleOffsetAlongship=\"0.06\" "
    "AngleOffsetAthwartship=\"0.07\" />\n                        <FrequencyPar Frequency=\"35783\" "
    "Gain=\"26.95\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.52\" "
    "BeamWidthAthwartship=\"7.46\" AngleOffsetAlongship=\"0.05\" AngleOffsetAthwartship=\"0.07\" "
    "/>\n                        <FrequencyPar Frequency=\"35882\" Gain=\"26.97\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.5\" BeamWidthAthwartship=\"7.43\" "
    "AngleOffsetAlongship=\"0.05\" AngleOffsetAthwartship=\"0.07\" />\n                        "
    "<FrequencyPar Frequency=\"35981\" Gain=\"26.99\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.48\" BeamWidthAthwartship=\"7.39\" AngleOffsetAlongship=\"0.04\" "
    "AngleOffsetAthwartship=\"0.08\" />\n                        <FrequencyPar Frequency=\"36081\" "
    "Gain=\"27.01\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.44\" "
    "BeamWidthAthwartship=\"7.37\" AngleOffsetAlongship=\"0.04\" AngleOffsetAthwartship=\"0.08\" "
    "/>\n                        <FrequencyPar Frequency=\"36180\" Gain=\"27.06\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.42\" BeamWidthAthwartship=\"7.32\" "
    "AngleOffsetAlongship=\"0.04\" AngleOffsetAthwartship=\"0.08\" />\n                        "
    "<FrequencyPar Frequency=\"36279\" Gain=\"27.1\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.39\" BeamWidthAthwartship=\"7.26\" AngleOffsetAlongship=\"0.03\" "
    "AngleOffsetAthwartship=\"0.08\" />\n                        <FrequencyPar Frequency=\"36378\" "
    "Gain=\"27.15\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.36\" "
    "BeamWidthAthwartship=\"7.2\" AngleOffsetAlongship=\"0.03\" AngleOffsetAthwartship=\"0.09\" "
    "/>\n                        <FrequencyPar Frequency=\"36477\" Gain=\"27.21\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.33\" BeamWidthAthwartship=\"7.16\" "
    "AngleOffsetAlongship=\"0.01\" AngleOffsetAthwartship=\"0.09\" />\n                        "
    "<FrequencyPar Frequency=\"36576\" Gain=\"27.25\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.29\" BeamWidthAthwartship=\"7.11\" AngleOffsetAlongship=\"0\" "
    "AngleOffsetAthwartship=\"0.09\" />\n                        <FrequencyPar Frequency=\"36675\" "
    "Gain=\"27.29\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.26\" "
    "BeamWidthAthwartship=\"7.09\" AngleOffsetAlongship=\"-0.01\" AngleOffsetAthwartship=\"0.09\" "
    "/>\n                        <FrequencyPar Frequency=\"36774\" Gain=\"27.3\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.24\" BeamWidthAthwartship=\"7.08\" "
    "AngleOffsetAlongship=\"-0.02\" AngleOffsetAthwartship=\"0.09\" />\n                        "
    "<FrequencyPar Frequency=\"36873\" Gain=\"27.32\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.22\" BeamWidthAthwartship=\"7.05\" AngleOffsetAlongship=\"-0.02\" "
    "AngleOffsetAthwartship=\"0.09\" />\n                        <FrequencyPar Frequency=\"36972\" "
    "Gain=\"27.32\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.2\" "
    "BeamWidthAthwartship=\"7.07\" AngleOffsetAlongship=\"-0.02\" AngleOffsetAthwartship=\"0.09\" "
    "/>\n                        <FrequencyPar Frequency=\"37072\" Gain=\"27.3\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.2\" BeamWidthAthwartship=\"7.08\" "
    "AngleOffsetAlongship=\"-0.03\" AngleOffsetAthwartship=\"0.09\" />\n                        "
    "<FrequencyPar Frequency=\"37171\" Gain=\"27.28\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.19\" BeamWidthAthwartship=\"7.07\" AngleOffsetAlongship=\"-0.03\" "
    "AngleOffsetAthwartship=\"0.1\" />\n                        <FrequencyPar Frequency=\"37270\" "
    "Gain=\"27.27\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.16\" "
    "BeamWidthAthwartship=\"7.06\" AngleOffsetAlongship=\"-0.02\" AngleOffsetAthwartship=\"0.1\" "
    "/>\n                        <FrequencyPar Frequency=\"37369\" Gain=\"27.24\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.15\" BeamWidthAthwartship=\"7.04\" "
    "AngleOffsetAlongship=\"-0.02\" AngleOffsetAthwartship=\"0.11\" />\n                        "
    "<FrequencyPar Frequency=\"37468\" Gain=\"27.2\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.12\" BeamWidthAthwartship=\"7.01\" AngleOffsetAlongship=\"-0.01\" "
    "AngleOffsetAthwartship=\"0.11\" />\n                        <FrequencyPar Frequency=\"37567\" "
    "Gain=\"27.15\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.09\" "
    "BeamWidthAthwartship=\"6.99\" AngleOffsetAlongship=\"-0.01\" AngleOffsetAthwartship=\"0.12\" "
    "/>\n                        <FrequencyPar Frequency=\"37666\" Gain=\"27.09\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.06\" BeamWidthAthwartship=\"6.96\" "
    "AngleOffsetAlongship=\"0\" AngleOffsetAthwartship=\"0.11\" />\n                        "
    "<FrequencyPar Frequency=\"37765\" Gain=\"26.99\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.1\" BeamWidthAthwartship=\"6.94\" AngleOffsetAlongship=\"0.01\" "
    "AngleOffsetAthwartship=\"0.1\" />\n                        <FrequencyPar Frequency=\"37864\" "
    "Gain=\"26.88\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.07\" "
    "BeamWidthAthwartship=\"6.91\" AngleOffsetAlongship=\"0.02\" AngleOffsetAthwartship=\"0.09\" "
    "/>\n                        <FrequencyPar Frequency=\"37963\" Gain=\"26.77\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.04\" BeamWidthAthwartship=\"6.92\" "
    "AngleOffsetAlongship=\"0.03\" AngleOffsetAthwartship=\"0.08\" />\n                        "
    "<FrequencyPar Frequency=\"38063\" Gain=\"26.63\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.03\" BeamWidthAthwartship=\"6.92\" AngleOffsetAlongship=\"0.03\" "
    "AngleOffsetAthwartship=\"0.06\" />\n                        <FrequencyPar Frequency=\"38162\" "
    "Gain=\"26.49\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.02\" "
    "BeamWidthAthwartship=\"6.94\" AngleOffsetAlongship=\"0.04\" AngleOffsetAthwartship=\"0.04\" "
    "/>\n                        <FrequencyPar Frequency=\"38261\" Gain=\"26.38\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.05\" BeamWidthAthwartship=\"6.94\" "
    "AngleOffsetAlongship=\"0.04\" AngleOffsetAthwartship=\"0.01\" />\n                        "
    "<FrequencyPar Frequency=\"38360\" Gain=\"26.29\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.05\" BeamWidthAthwartship=\"6.96\" AngleOffsetAlongship=\"0.04\" "
    "AngleOffsetAthwartship=\"-0.01\" />\n                        <FrequencyPar "
    "Frequency=\"38459\" Gain=\"26.23\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.03\" "
    "BeamWidthAthwartship=\"7.02\" AngleOffsetAlongship=\"0.03\" AngleOffsetAthwartship=\"-0.01\" "
    "/>\n                        <FrequencyPar Frequency=\"38558\" Gain=\"26.21\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7\" BeamWidthAthwartship=\"7.01\" "
    "AngleOffsetAlongship=\"0.03\" AngleOffsetAthwartship=\"-0.02\" />\n                        "
    "<FrequencyPar Frequency=\"38657\" Gain=\"26.21\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.99\" BeamWidthAthwartship=\"7.01\" AngleOffsetAlongship=\"0.03\" "
    "AngleOffsetAthwartship=\"-0.01\" />\n                        <FrequencyPar "
    "Frequency=\"38756\" Gain=\"26.24\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.95\" "
    "BeamWidthAthwartship=\"7\" AngleOffsetAlongship=\"0.04\" AngleOffsetAthwartship=\"0.01\" />\n "
    "                       <FrequencyPar Frequency=\"38855\" Gain=\"26.28\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.91\" BeamWidthAthwartship=\"6.97\" "
    "AngleOffsetAlongship=\"0.04\" AngleOffsetAthwartship=\"0.02\" />\n                        "
    "<FrequencyPar Frequency=\"38954\" Gain=\"26.31\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.9\" BeamWidthAthwartship=\"6.94\" AngleOffsetAlongship=\"0.05\" "
    "AngleOffsetAthwartship=\"0.04\" />\n                        <FrequencyPar Frequency=\"39054\" "
    "Gain=\"26.33\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.87\" "
    "BeamWidthAthwartship=\"6.95\" AngleOffsetAlongship=\"0.05\" AngleOffsetAthwartship=\"0.06\" "
    "/>\n                        <FrequencyPar Frequency=\"39153\" Gain=\"26.35\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.85\" BeamWidthAthwartship=\"6.94\" "
    "AngleOffsetAlongship=\"0.06\" AngleOffsetAthwartship=\"0.08\" />\n                        "
    "<FrequencyPar Frequency=\"39252\" Gain=\"26.36\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.84\" BeamWidthAthwartship=\"6.95\" AngleOffsetAlongship=\"0.06\" "
    "AngleOffsetAthwartship=\"0.09\" />\n                        <FrequencyPar Frequency=\"39351\" "
    "Gain=\"26.38\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.85\" "
    "BeamWidthAthwartship=\"6.93\" AngleOffsetAlongship=\"0.07\" AngleOffsetAthwartship=\"0.1\" "
    "/>\n                        <FrequencyPar Frequency=\"39450\" Gain=\"26.4\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.85\" BeamWidthAthwartship=\"6.94\" "
    "AngleOffsetAlongship=\"0.06\" AngleOffsetAthwartship=\"0.1\" />\n                        "
    "<FrequencyPar Frequency=\"39549\" Gain=\"26.44\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.83\" BeamWidthAthwartship=\"6.95\" AngleOffsetAlongship=\"0.06\" "
    "AngleOffsetAthwartship=\"0.1\" />\n                        <FrequencyPar Frequency=\"39648\" "
    "Gain=\"26.51\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.81\" "
    "BeamWidthAthwartship=\"6.95\" AngleOffsetAlongship=\"0.06\" AngleOffsetAthwartship=\"0.1\" "
    "/>\n                        <FrequencyPar Frequency=\"39747\" Gain=\"26.6\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.87\" BeamWidthAthwartship=\"6.94\" "
    "AngleOffsetAlongship=\"0.06\" AngleOffsetAthwartship=\"0.09\" />\n                        "
    "<FrequencyPar Frequency=\"39846\" Gain=\"26.73\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.84\" BeamWidthAthwartship=\"6.89\" AngleOffsetAlongship=\"0.05\" "
    "AngleOffsetAthwartship=\"0.08\" />\n                        <FrequencyPar Frequency=\"39945\" "
    "Gain=\"26.88\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.8\" "
    "BeamWidthAthwartship=\"6.81\" AngleOffsetAlongship=\"0.05\" AngleOffsetAthwartship=\"0.07\" "
    "/>\n                        <FrequencyPar Frequency=\"40045\" Gain=\"27.02\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.75\" BeamWidthAthwartship=\"6.76\" "
    "AngleOffsetAlongship=\"0.05\" AngleOffsetAthwartship=\"0.06\" />\n                        "
    "<FrequencyPar Frequency=\"40144\" Gain=\"27.16\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.74\" BeamWidthAthwartship=\"6.67\" AngleOffsetAlongship=\"0.06\" "
    "AngleOffsetAthwartship=\"0.06\" />\n                        <FrequencyPar Frequency=\"40243\" "
    "Gain=\"27.28\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.68\" "
    "BeamWidthAthwartship=\"6.65\" AngleOffsetAlongship=\"0.05\" AngleOffsetAthwartship=\"0.05\" "
    "/>\n                        <FrequencyPar Frequency=\"40342\" Gain=\"27.39\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.64\" BeamWidthAthwartship=\"6.6\" "
    "AngleOffsetAlongship=\"0.05\" AngleOffsetAthwartship=\"0.05\" />\n                        "
    "<FrequencyPar Frequency=\"40441\" Gain=\"27.47\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.62\" BeamWidthAthwartship=\"6.56\" AngleOffsetAlongship=\"0.05\" "
    "AngleOffsetAthwartship=\"0.06\" />\n                        <FrequencyPar Frequency=\"40540\" "
    "Gain=\"27.55\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.58\" "
    "BeamWidthAthwartship=\"6.52\" AngleOffsetAlongship=\"0.04\" AngleOffsetAthwartship=\"0.07\" "
    "/>\n                        <FrequencyPar Frequency=\"40639\" Gain=\"27.6\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.56\" BeamWidthAthwartship=\"6.48\" "
    "AngleOffsetAlongship=\"0.04\" AngleOffsetAthwartship=\"0.07\" />\n                        "
    "<FrequencyPar Frequency=\"40738\" Gain=\"27.65\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.52\" BeamWidthAthwartship=\"6.46\" AngleOffsetAlongship=\"0.03\" "
    "AngleOffsetAthwartship=\"0.08\" />\n                        <FrequencyPar Frequency=\"40837\" "
    "Gain=\"27.69\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.48\" "
    "BeamWidthAthwartship=\"6.42\" AngleOffsetAlongship=\"0.02\" AngleOffsetAthwartship=\"0.09\" "
    "/>\n                        <FrequencyPar Frequency=\"40936\" Gain=\"27.73\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.46\" BeamWidthAthwartship=\"6.4\" "
    "AngleOffsetAlongship=\"0.02\" AngleOffsetAthwartship=\"0.1\" />\n                        "
    "<FrequencyPar Frequency=\"41036\" Gain=\"27.77\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.46\" BeamWidthAthwartship=\"6.38\" AngleOffsetAlongship=\"0.02\" "
    "AngleOffsetAthwartship=\"0.11\" />\n                        <FrequencyPar Frequency=\"41135\" "
    "Gain=\"27.81\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.44\" "
    "BeamWidthAthwartship=\"6.35\" AngleOffsetAlongship=\"0.02\" AngleOffsetAthwartship=\"0.12\" "
    "/>\n                        <FrequencyPar Frequency=\"41234\" Gain=\"27.85\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.43\" BeamWidthAthwartship=\"6.32\" "
    "AngleOffsetAlongship=\"0.02\" AngleOffsetAthwartship=\"0.12\" />\n                        "
    "<FrequencyPar Frequency=\"41333\" Gain=\"27.9\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.41\" BeamWidthAthwartship=\"6.31\" AngleOffsetAlongship=\"0.02\" "
    "AngleOffsetAthwartship=\"0.12\" />\n                        <FrequencyPar Frequency=\"41432\" "
    "Gain=\"27.95\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.4\" "
    "BeamWidthAthwartship=\"6.29\" AngleOffsetAlongship=\"0.02\" AngleOffsetAthwartship=\"0.11\" "
    "/>\n                        <FrequencyPar Frequency=\"41531\" Gain=\"28.01\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.38\" BeamWidthAthwartship=\"6.28\" "
    "AngleOffsetAlongship=\"0.02\" AngleOffsetAthwartship=\"0.11\" />\n                        "
    "<FrequencyPar Frequency=\"41630\" Gain=\"28.08\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.36\" BeamWidthAthwartship=\"6.26\" AngleOffsetAlongship=\"0.02\" "
    "AngleOffsetAthwartship=\"0.1\" />\n                        <FrequencyPar Frequency=\"41729\" "
    "Gain=\"28.14\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.34\" "
    "BeamWidthAthwartship=\"6.22\" AngleOffsetAlongship=\"0.02\" AngleOffsetAthwartship=\"0.1\" "
    "/>\n                        <FrequencyPar Frequency=\"41828\" Gain=\"28.21\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.33\" BeamWidthAthwartship=\"6.2\" "
    "AngleOffsetAlongship=\"0.02\" AngleOffsetAthwartship=\"0.1\" />\n                        "
    "<FrequencyPar Frequency=\"41927\" Gain=\"28.28\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.31\" BeamWidthAthwartship=\"6.21\" AngleOffsetAlongship=\"0.02\" "
    "AngleOffsetAthwartship=\"0.09\" />\n                        <FrequencyPar Frequency=\"42027\" "
    "Gain=\"28.36\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.28\" "
    "BeamWidthAthwartship=\"6.18\" AngleOffsetAlongship=\"0.01\" AngleOffsetAthwartship=\"0.09\" "
    "/>\n                        <FrequencyPar Frequency=\"42126\" Gain=\"28.43\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.27\" BeamWidthAthwartship=\"6.16\" "
    "AngleOffsetAlongship=\"0.01\" AngleOffsetAthwartship=\"0.08\" />\n                        "
    "<FrequencyPar Frequency=\"42225\" Gain=\"28.5\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.24\" BeamWidthAthwartship=\"6.14\" AngleOffsetAlongship=\"0.01\" "
    "AngleOffsetAthwartship=\"0.08\" />\n                        <FrequencyPar Frequency=\"42324\" "
    "Gain=\"28.56\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.24\" "
    "BeamWidthAthwartship=\"6.11\" AngleOffsetAlongship=\"0.01\" AngleOffsetAthwartship=\"0.08\" "
    "/>\n                        <FrequencyPar Frequency=\"42423\" Gain=\"28.61\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.21\" BeamWidthAthwartship=\"6.11\" "
    "AngleOffsetAlongship=\"0.01\" AngleOffsetAthwartship=\"0.08\" />\n                        "
    "<FrequencyPar Frequency=\"42522\" Gain=\"28.64\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.2\" BeamWidthAthwartship=\"6.1\" AngleOffsetAlongship=\"0.01\" "
    "AngleOffsetAthwartship=\"0.07\" />\n                        <FrequencyPar Frequency=\"42621\" "
    "Gain=\"28.65\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.18\" "
    "BeamWidthAthwartship=\"6.1\" AngleOffsetAlongship=\"0.01\" AngleOffsetAthwartship=\"0.07\" "
    "/>\n                        <FrequencyPar Frequency=\"42720\" Gain=\"28.65\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.18\" BeamWidthAthwartship=\"6.09\" "
    "AngleOffsetAlongship=\"0.02\" AngleOffsetAthwartship=\"0.06\" />\n                        "
    "<FrequencyPar Frequency=\"42819\" Gain=\"28.64\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.16\" BeamWidthAthwartship=\"6.08\" AngleOffsetAlongship=\"0.03\" "
    "AngleOffsetAthwartship=\"0.06\" />\n                        <FrequencyPar Frequency=\"42918\" "
    "Gain=\"28.62\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.17\" "
    "BeamWidthAthwartship=\"6.09\" AngleOffsetAlongship=\"0.03\" AngleOffsetAthwartship=\"0.06\" "
    "/>\n                        <FrequencyPar Frequency=\"43018\" Gain=\"28.61\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.17\" BeamWidthAthwartship=\"6.09\" "
    "AngleOffsetAlongship=\"0.04\" AngleOffsetAthwartship=\"0.06\" />\n                        "
    "<FrequencyPar Frequency=\"43117\" Gain=\"28.6\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.17\" BeamWidthAthwartship=\"6.09\" AngleOffsetAlongship=\"0.04\" "
    "AngleOffsetAthwartship=\"0.06\" />\n                        <FrequencyPar Frequency=\"43216\" "
    "Gain=\"28.58\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.15\" "
    "BeamWidthAthwartship=\"6.1\" AngleOffsetAlongship=\"0.04\" AngleOffsetAthwartship=\"0.07\" "
    "/>\n                        <FrequencyPar Frequency=\"43315\" Gain=\"28.57\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.15\" BeamWidthAthwartship=\"6.09\" "
    "AngleOffsetAlongship=\"0.05\" AngleOffsetAthwartship=\"0.06\" />\n                        "
    "<FrequencyPar Frequency=\"43414\" Gain=\"28.55\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.12\" BeamWidthAthwartship=\"6.08\" AngleOffsetAlongship=\"0.04\" "
    "AngleOffsetAthwartship=\"0.07\" />\n                        <FrequencyPar Frequency=\"43513\" "
    "Gain=\"28.52\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.1\" "
    "BeamWidthAthwartship=\"6.08\" AngleOffsetAlongship=\"0.05\" AngleOffsetAthwartship=\"0.07\" "
    "/>\n                        <FrequencyPar Frequency=\"43612\" Gain=\"28.48\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.08\" BeamWidthAthwartship=\"6.07\" "
    "AngleOffsetAlongship=\"0.05\" AngleOffsetAthwartship=\"0.06\" />\n                        "
    "<FrequencyPar Frequency=\"43711\" Gain=\"28.42\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.05\" BeamWidthAthwartship=\"6.07\" AngleOffsetAlongship=\"0.06\" "
    "AngleOffsetAthwartship=\"0.06\" />\n                        <FrequencyPar Frequency=\"43810\" "
    "Gain=\"28.35\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.02\" "
    "BeamWidthAthwartship=\"6.08\" AngleOffsetAlongship=\"0.08\" AngleOffsetAthwartship=\"0.05\" "
    "/>\n                        <FrequencyPar Frequency=\"43909\" Gain=\"28.29\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.02\" BeamWidthAthwartship=\"6.07\" "
    "AngleOffsetAlongship=\"0.1\" AngleOffsetAthwartship=\"0.04\" />\n                        "
    "<FrequencyPar Frequency=\"44009\" Gain=\"28.24\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6\" BeamWidthAthwartship=\"6.04\" AngleOffsetAlongship=\"0.11\" "
    "AngleOffsetAthwartship=\"0.04\" />\n                        <FrequencyPar Frequency=\"44108\" "
    "Gain=\"28.23\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.98\" "
    "BeamWidthAthwartship=\"6\" AngleOffsetAlongship=\"0.12\" AngleOffsetAthwartship=\"0.03\" />\n "
    "                       <FrequencyPar Frequency=\"44207\" Gain=\"28.25\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"5.93\" BeamWidthAthwartship=\"5.98\" "
    "AngleOffsetAlongship=\"0.12\" AngleOffsetAthwartship=\"0.02\" />\n                        "
    "<FrequencyPar Frequency=\"44306\" Gain=\"28.29\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.87\" BeamWidthAthwartship=\"5.94\" AngleOffsetAlongship=\"0.12\" "
    "AngleOffsetAthwartship=\"0.02\" />\n                        <FrequencyPar Frequency=\"44405\" "
    "Gain=\"28.35\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.82\" "
    "BeamWidthAthwartship=\"5.88\" AngleOffsetAlongship=\"0.11\" AngleOffsetAthwartship=\"0.02\" "
    "/>\n                        <FrequencyPar Frequency=\"44504\" Gain=\"28.42\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"5.76\" BeamWidthAthwartship=\"5.82\" "
    "AngleOffsetAlongship=\"0.1\" AngleOffsetAthwartship=\"0.01\" />\n                        "
    "<FrequencyPar Frequency=\"44603\" Gain=\"28.47\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.72\" BeamWidthAthwartship=\"5.71\" AngleOffsetAlongship=\"0.09\" "
    "AngleOffsetAthwartship=\"0.01\" />\n                        <FrequencyPar Frequency=\"44702\" "
    "Gain=\"28.5\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.65\" "
    "BeamWidthAthwartship=\"5.58\" AngleOffsetAlongship=\"0.07\" AngleOffsetAthwartship=\"0.03\" "
    "/>\n                        <FrequencyPar Frequency=\"44801\" Gain=\"28.52\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"5.53\" BeamWidthAthwartship=\"5.43\" "
    "AngleOffsetAlongship=\"0.07\" AngleOffsetAthwartship=\"0.03\" />\n                        "
    "<FrequencyPar Frequency=\"44900\" Gain=\"28.52\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.47\" BeamWidthAthwartship=\"5.27\" AngleOffsetAlongship=\"0.06\" "
    "AngleOffsetAthwartship=\"0.03\" />\n                        <FrequencyPar Frequency=\"45000\" "
    "Gain=\"28.53\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.37\" "
    "BeamWidthAthwartship=\"5.21\" AngleOffsetAlongship=\"0.05\" AngleOffsetAthwartship=\"0.02\" "
    "/>\n                    </Transducer>\n                </Channel>\n            </Channels>\n  "
    "      </Transceiver>\n        <Transceiver TransceiverName=\"WBT 400050\" "
    "IPAddress=\"157.237.15.104\" MarketSegment=\"Scientific\" SerialNumber=\"400050\" "
    "Impedance=\"5400\" Multiplexing=\"0\" RxSampleFrequency=\"1500000\" "
    "EthernetAddress=\"009072061ab2\" Version=\"[0] Ethernet: 00:90:72:06:1A:B2&#x0D;&#x0A;[1] "
    "Parts-list: WBT 371790/F&#x0D;&#x0A;[2] Product: WBT&#x0D;&#x0A;IP Address: "
    "157.237.15.104&#x0D;&#x0A;Subnet mask: 255.255.0.0&#x0D;&#x0A;Default gateway: "
    "157.237.15.1&#x0D;&#x0A;Serial number: 400050&#x0D;&#x0A;Embedded software: Rev. "
    "2.54&#x0D;&#x0A;FPGA TX firmware: Rev. 5&#x0D;&#x0A;FPGA RX firmware: Rev. 7&#x0D;&#x0A;CH1: "
    "509W CH2: 500W CH3: 489W CH4: 513W&#x0D;&#x0A;TRD1: Unable to detect "
    "transducer&#x0D;&#x0A;TRD2: Unable to detect transducer&#x0D;&#x0A;TRD3: Unable to detect "
    "transducer&#x0D;&#x0A;TRD4: Unable to detect transducer&#x0D;&#x0A;\" "
    "TransceiverSoftwareVersion=\"2.54\" TransceiverNumber=\"2\" TransceiverType=\"WBT\">\n        "
    "    <Channels>\n                <Channel ChannelID=\"WBT 400050-15 ES70-7C_ES\" "
    "LogicalChannelID=\"WBT 400050-15 ES70-7C\" ChannelIdShort=\"ES70-7C Serial No: 604\" "
    "MaxTxPowerTransceiver=\"2000\" HWChannelConfiguration=\"15\" "
    "PulseDuration=\"0.000128;0.000256;0.000512;0.001024;0.002048\" "
    "PulseDurationFM=\"0.000512;0.001024;0.002048;0.004096;0.008192\">\n                    "
    "<Transducer TransducerName=\"ES70-7C\" SerialNumber=\"604\" Frequency=\"70000\" "
    "FrequencyMinimum=\"45000\" FrequencyMaximum=\"90000\" MaxTxPowerTransducer=\"750\" "
    "Gain=\"27;27;27;27;27\" SaCorrection=\"0;0;0;0;0\" EquivalentBeamAngle=\"-20.7\" "
    "DirectivityDropAt2XBeamWidth=\"0\" AngleSensitivityAlongship=\"23\" "
    "AngleSensitivityAthwartship=\"23\" AngleOffsetAlongship=\"0\" AngleOffsetAthwartship=\"0\" "
    "BeamWidthAlongship=\"7\" BeamWidthAthwartship=\"7\" BeamType=\"1\">\n                        "
    "<FrequencyPar Frequency=\"45000\" Gain=\"23.27\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"9.03\" BeamWidthAthwartship=\"9.99\" AngleOffsetAlongship=\"-0.07\" "
    "AngleOffsetAthwartship=\"-0.19\" />\n                        <FrequencyPar "
    "Frequency=\"45495\" Gain=\"23.76\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"11.59\" "
    "BeamWidthAthwartship=\"9.66\" AngleOffsetAlongship=\"-0.34\" AngleOffsetAthwartship=\"-0.05\" "
    "/>\n                        <FrequencyPar Frequency=\"45990\" Gain=\"24.08\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"9.87\" BeamWidthAthwartship=\"10.62\" "
    "AngleOffsetAlongship=\"-0.22\" AngleOffsetAthwartship=\"-0.06\" />\n                        "
    "<FrequencyPar Frequency=\"46486\" Gain=\"24.4\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"9.9\" BeamWidthAthwartship=\"10.82\" AngleOffsetAlongship=\"-0.17\" "
    "AngleOffsetAthwartship=\"-0.41\" />\n                        <FrequencyPar "
    "Frequency=\"46981\" Gain=\"24.46\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"10.91\" "
    "BeamWidthAthwartship=\"10.77\" AngleOffsetAlongship=\"-0.22\" "
    "AngleOffsetAthwartship=\"-0.19\" />\n                        <FrequencyPar "
    "Frequency=\"47477\" Gain=\"24.52\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"10.4\" "
    "BeamWidthAthwartship=\"9.57\" AngleOffsetAlongship=\"-0.05\" AngleOffsetAthwartship=\"-0.07\" "
    "/>\n                        <FrequencyPar Frequency=\"47972\" Gain=\"24.4\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"10.04\" BeamWidthAthwartship=\"10.2\" "
    "AngleOffsetAlongship=\"-0.23\" AngleOffsetAthwartship=\"-0.2\" />\n                        "
    "<FrequencyPar Frequency=\"48468\" Gain=\"24.49\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"10.1\" BeamWidthAthwartship=\"8.76\" AngleOffsetAlongship=\"-0.06\" "
    "AngleOffsetAthwartship=\"-0.11\" />\n                        <FrequencyPar "
    "Frequency=\"48963\" Gain=\"24.38\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"9.9\" "
    "BeamWidthAthwartship=\"9.88\" AngleOffsetAlongship=\"-0.27\" AngleOffsetAthwartship=\"-0.24\" "
    "/>\n                        <FrequencyPar Frequency=\"49459\" Gain=\"24.29\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"10.24\" BeamWidthAthwartship=\"9.68\" "
    "AngleOffsetAlongship=\"-0.39\" AngleOffsetAthwartship=\"-0.02\" />\n                        "
    "<FrequencyPar Frequency=\"49954\" Gain=\"24.45\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"9.13\" BeamWidthAthwartship=\"8.77\" AngleOffsetAlongship=\"-0.34\" "
    "AngleOffsetAthwartship=\"0.09\" />\n                        <FrequencyPar Frequency=\"50450\" "
    "Gain=\"24.42\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"8.95\" "
    "BeamWidthAthwartship=\"8.61\" AngleOffsetAlongship=\"-0.15\" AngleOffsetAthwartship=\"-0.06\" "
    "/>\n                        <FrequencyPar Frequency=\"50945\" Gain=\"24.32\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"9\" BeamWidthAthwartship=\"9.72\" "
    "AngleOffsetAlongship=\"0.15\" AngleOffsetAthwartship=\"-0.13\" />\n                        "
    "<FrequencyPar Frequency=\"51441\" Gain=\"24.26\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"9.52\" BeamWidthAthwartship=\"9.54\" AngleOffsetAlongship=\"-0.19\" "
    "AngleOffsetAthwartship=\"-0.04\" />\n                        <FrequencyPar "
    "Frequency=\"51936\" Gain=\"24.46\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"8.41\" "
    "BeamWidthAthwartship=\"8.48\" AngleOffsetAlongship=\"-0.21\" AngleOffsetAthwartship=\"0.09\" "
    "/>\n                        <FrequencyPar Frequency=\"52432\" Gain=\"24.59\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"8.58\" BeamWidthAthwartship=\"8.22\" "
    "AngleOffsetAlongship=\"-0.01\" AngleOffsetAthwartship=\"-0.07\" />\n                        "
    "<FrequencyPar Frequency=\"52927\" Gain=\"24.48\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"8.6\" BeamWidthAthwartship=\"9.02\" AngleOffsetAlongship=\"-0.2\" "
    "AngleOffsetAthwartship=\"0.03\" />\n                        <FrequencyPar Frequency=\"53423\" "
    "Gain=\"24.72\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"8.66\" "
    "BeamWidthAthwartship=\"8.22\" AngleOffsetAlongship=\"-0.2\" AngleOffsetAthwartship=\"-0.09\" "
    "/>\n                        <FrequencyPar Frequency=\"53918\" Gain=\"24.74\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"8.64\" BeamWidthAthwartship=\"8.8\" "
    "AngleOffsetAlongship=\"-0.05\" AngleOffsetAthwartship=\"-0.15\" />\n                        "
    "<FrequencyPar Frequency=\"54414\" Gain=\"25.01\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.48\" BeamWidthAthwartship=\"7.99\" AngleOffsetAlongship=\"-0.06\" "
    "AngleOffsetAthwartship=\"-0.08\" />\n                        <FrequencyPar "
    "Frequency=\"54909\" Gain=\"25.07\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"8.67\" "
    "BeamWidthAthwartship=\"8.45\" AngleOffsetAlongship=\"-0.09\" AngleOffsetAthwartship=\"-0.16\" "
    "/>\n                        <FrequencyPar Frequency=\"55405\" Gain=\"25.2\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.96\" BeamWidthAthwartship=\"7.88\" "
    "AngleOffsetAlongship=\"-0.08\" AngleOffsetAthwartship=\"0.02\" />\n                        "
    "<FrequencyPar Frequency=\"55900\" Gain=\"25.35\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"8.18\" BeamWidthAthwartship=\"7.72\" AngleOffsetAlongship=\"-0.08\" "
    "AngleOffsetAthwartship=\"-0.11\" />\n                        <FrequencyPar "
    "Frequency=\"56396\" Gain=\"25.63\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.86\" "
    "BeamWidthAthwartship=\"7.55\" AngleOffsetAlongship=\"-0.18\" AngleOffsetAthwartship=\"-0.07\" "
    "/>\n                        <FrequencyPar Frequency=\"56891\" Gain=\"25.44\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"8.27\" BeamWidthAthwartship=\"7.96\" "
    "AngleOffsetAlongship=\"-0.12\" AngleOffsetAthwartship=\"-0.07\" />\n                        "
    "<FrequencyPar Frequency=\"57387\" Gain=\"25.6\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.67\" BeamWidthAthwartship=\"8.42\" AngleOffsetAlongship=\"-0.08\" "
    "AngleOffsetAthwartship=\"-0.03\" />\n                        <FrequencyPar "
    "Frequency=\"57882\" Gain=\"25.88\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.77\" "
    "BeamWidthAthwartship=\"7.6\" AngleOffsetAlongship=\"-0.07\" AngleOffsetAthwartship=\"-0.14\" "
    "/>\n                        <FrequencyPar Frequency=\"58378\" Gain=\"25.78\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"8.41\" BeamWidthAthwartship=\"7.86\" "
    "AngleOffsetAlongship=\"0.09\" AngleOffsetAthwartship=\"0.03\" />\n                        "
    "<FrequencyPar Frequency=\"58873\" Gain=\"25.92\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"8.12\" BeamWidthAthwartship=\"8.04\" AngleOffsetAlongship=\"0.02\" "
    "AngleOffsetAthwartship=\"-0.05\" />\n                        <FrequencyPar "
    "Frequency=\"59369\" Gain=\"26.12\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.48\" "
    "BeamWidthAthwartship=\"7.65\" AngleOffsetAlongship=\"-0.11\" AngleOffsetAthwartship=\"-0.15\" "
    "/>\n                        <FrequencyPar Frequency=\"59864\" Gain=\"26.26\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.44\" BeamWidthAthwartship=\"7.4\" "
    "AngleOffsetAlongship=\"-0.11\" AngleOffsetAthwartship=\"-0.06\" />\n                        "
    "<FrequencyPar Frequency=\"60360\" Gain=\"26.36\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.52\" BeamWidthAthwartship=\"7.72\" AngleOffsetAlongship=\"-0.15\" "
    "AngleOffsetAthwartship=\"-0.02\" />\n                        <FrequencyPar "
    "Frequency=\"60855\" Gain=\"26.44\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.84\" "
    "BeamWidthAthwartship=\"7.62\" AngleOffsetAlongship=\"0.01\" AngleOffsetAthwartship=\"-0.02\" "
    "/>\n                        <FrequencyPar Frequency=\"61351\" Gain=\"26.65\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.11\" BeamWidthAthwartship=\"7.11\" "
    "AngleOffsetAlongship=\"0\" AngleOffsetAthwartship=\"-0.08\" />\n                        "
    "<FrequencyPar Frequency=\"61846\" Gain=\"26.66\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.24\" BeamWidthAthwartship=\"7.31\" AngleOffsetAlongship=\"-0.15\" "
    "AngleOffsetAthwartship=\"-0.04\" />\n                        <FrequencyPar "
    "Frequency=\"62342\" Gain=\"26.78\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.42\" "
    "BeamWidthAthwartship=\"7.14\" AngleOffsetAlongship=\"-0.12\" AngleOffsetAthwartship=\"-0.05\" "
    "/>\n                        <FrequencyPar Frequency=\"62837\" Gain=\"26.84\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"7.11\" BeamWidthAthwartship=\"7.35\" "
    "AngleOffsetAlongship=\"-0.06\" AngleOffsetAthwartship=\"0.03\" />\n                        "
    "<FrequencyPar Frequency=\"63333\" Gain=\"26.91\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.25\" BeamWidthAthwartship=\"7.39\" AngleOffsetAlongship=\"-0.05\" "
    "AngleOffsetAthwartship=\"-0.04\" />\n                        <FrequencyPar "
    "Frequency=\"63828\" Gain=\"27.12\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.92\" "
    "BeamWidthAthwartship=\"6.82\" AngleOffsetAlongship=\"-0.04\" AngleOffsetAthwartship=\"-0.07\" "
    "/>\n                        <FrequencyPar Frequency=\"64324\" Gain=\"27.04\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.9\" BeamWidthAthwartship=\"7.15\" "
    "AngleOffsetAlongship=\"-0.05\" AngleOffsetAthwartship=\"-0.02\" />\n                        "
    "<FrequencyPar Frequency=\"64819\" Gain=\"27.11\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.94\" BeamWidthAthwartship=\"6.99\" AngleOffsetAlongship=\"-0.07\" "
    "AngleOffsetAthwartship=\"0.05\" />\n                        <FrequencyPar Frequency=\"65315\" "
    "Gain=\"27.22\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.89\" "
    "BeamWidthAthwartship=\"6.66\" AngleOffsetAlongship=\"-0.05\" AngleOffsetAthwartship=\"-0.02\" "
    "/>\n                        <FrequencyPar Frequency=\"65810\" Gain=\"27.22\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.91\" BeamWidthAthwartship=\"6.79\" "
    "AngleOffsetAlongship=\"-0.1\" AngleOffsetAthwartship=\"-0.11\" />\n                        "
    "<FrequencyPar Frequency=\"66306\" Gain=\"27.23\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.92\" BeamWidthAthwartship=\"6.6\" AngleOffsetAlongship=\"-0.03\" "
    "AngleOffsetAthwartship=\"-0.02\" />\n                        <FrequencyPar "
    "Frequency=\"66801\" Gain=\"27.2\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.72\" "
    "BeamWidthAthwartship=\"6.95\" AngleOffsetAlongship=\"0\" AngleOffsetAthwartship=\"0.04\" />\n "
    "                       <FrequencyPar Frequency=\"67297\" Gain=\"27.35\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.7\" BeamWidthAthwartship=\"6.53\" "
    "AngleOffsetAlongship=\"-0.04\" AngleOffsetAthwartship=\"0.01\" />\n                        "
    "<FrequencyPar Frequency=\"67792\" Gain=\"27.39\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.63\" BeamWidthAthwartship=\"6.7\" AngleOffsetAlongship=\"-0.02\" "
    "AngleOffsetAthwartship=\"0\" />\n                        <FrequencyPar Frequency=\"68288\" "
    "Gain=\"27.4\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.73\" "
    "BeamWidthAthwartship=\"6.87\" AngleOffsetAlongship=\"-0.05\" AngleOffsetAthwartship=\"0.03\" "
    "/>\n                        <FrequencyPar Frequency=\"68783\" Gain=\"27.53\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.62\" BeamWidthAthwartship=\"6.51\" "
    "AngleOffsetAlongship=\"0\" AngleOffsetAthwartship=\"-0.02\" />\n                        "
    "<FrequencyPar Frequency=\"69279\" Gain=\"27.66\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.57\" BeamWidthAthwartship=\"6.29\" AngleOffsetAlongship=\"-0.02\" "
    "AngleOffsetAthwartship=\"-0.05\" />\n                        <FrequencyPar "
    "Frequency=\"69774\" Gain=\"27.74\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.45\" "
    "BeamWidthAthwartship=\"6.21\" AngleOffsetAlongship=\"0\" AngleOffsetAthwartship=\"-0.08\" "
    "/>\n                        <FrequencyPar Frequency=\"70270\" Gain=\"27.68\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.39\" BeamWidthAthwartship=\"6.63\" "
    "AngleOffsetAlongship=\"-0.06\" AngleOffsetAthwartship=\"0\" />\n                        "
    "<FrequencyPar Frequency=\"70765\" Gain=\"27.72\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.24\" BeamWidthAthwartship=\"6.49\" AngleOffsetAlongship=\"-0.08\" "
    "AngleOffsetAthwartship=\"-0.02\" />\n                        <FrequencyPar "
    "Frequency=\"71261\" Gain=\"27.71\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.24\" "
    "BeamWidthAthwartship=\"6.17\" AngleOffsetAlongship=\"-0.05\" AngleOffsetAthwartship=\"-0.05\" "
    "/>\n                        <FrequencyPar Frequency=\"71756\" Gain=\"27.72\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.19\" BeamWidthAthwartship=\"6.32\" "
    "AngleOffsetAlongship=\"-0.06\" AngleOffsetAthwartship=\"-0.04\" />\n                        "
    "<FrequencyPar Frequency=\"72252\" Gain=\"27.7\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.25\" BeamWidthAthwartship=\"6.44\" AngleOffsetAlongship=\"-0.02\" "
    "AngleOffsetAthwartship=\"0\" />\n                        <FrequencyPar Frequency=\"72747\" "
    "Gain=\"27.72\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.26\" "
    "BeamWidthAthwartship=\"6.25\" AngleOffsetAlongship=\"-0.02\" AngleOffsetAthwartship=\"0.03\" "
    "/>\n                        <FrequencyPar Frequency=\"73243\" Gain=\"27.85\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"6.08\" BeamWidthAthwartship=\"5.96\" "
    "AngleOffsetAlongship=\"-0.02\" AngleOffsetAthwartship=\"-0.03\" />\n                        "
    "<FrequencyPar Frequency=\"73738\" Gain=\"27.91\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.89\" BeamWidthAthwartship=\"6.07\" AngleOffsetAlongship=\"-0.01\" "
    "AngleOffsetAthwartship=\"0\" />\n                        <FrequencyPar Frequency=\"74234\" "
    "Gain=\"28.02\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.85\" "
    "BeamWidthAthwartship=\"6.06\" AngleOffsetAlongship=\"-0.05\" AngleOffsetAthwartship=\"-0.03\" "
    "/>\n                        <FrequencyPar Frequency=\"74729\" Gain=\"28.08\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"5.83\" BeamWidthAthwartship=\"6.07\" "
    "AngleOffsetAlongship=\"-0.05\" AngleOffsetAthwartship=\"-0.05\" />\n                        "
    "<FrequencyPar Frequency=\"75225\" Gain=\"28.15\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.76\" BeamWidthAthwartship=\"6.16\" AngleOffsetAlongship=\"-0.03\" "
    "AngleOffsetAthwartship=\"-0.04\" />\n                        <FrequencyPar "
    "Frequency=\"75720\" Gain=\"28.2\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.81\" "
    "BeamWidthAthwartship=\"6.18\" AngleOffsetAlongship=\"-0.01\" AngleOffsetAthwartship=\"-0.09\" "
    "/>\n                        <FrequencyPar Frequency=\"76216\" Gain=\"28.25\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"5.72\" BeamWidthAthwartship=\"5.86\" "
    "AngleOffsetAlongship=\"-0.04\" AngleOffsetAthwartship=\"-0.04\" />\n                        "
    "<FrequencyPar Frequency=\"76711\" Gain=\"28.25\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.82\" BeamWidthAthwartship=\"5.75\" AngleOffsetAlongship=\"-0.04\" "
    "AngleOffsetAthwartship=\"-0.03\" />\n                        <FrequencyPar "
    "Frequency=\"77207\" Gain=\"28.29\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.78\" "
    "BeamWidthAthwartship=\"5.71\" AngleOffsetAlongship=\"0\" AngleOffsetAthwartship=\"-0.04\" "
    "/>\n                        <FrequencyPar Frequency=\"77702\" Gain=\"28.34\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"5.71\" BeamWidthAthwartship=\"5.74\" "
    "AngleOffsetAlongship=\"-0.04\" AngleOffsetAthwartship=\"-0.05\" />\n                        "
    "<FrequencyPar Frequency=\"78198\" Gain=\"28.39\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.59\" BeamWidthAthwartship=\"5.71\" AngleOffsetAlongship=\"-0.02\" "
    "AngleOffsetAthwartship=\"-0.08\" />\n                        <FrequencyPar "
    "Frequency=\"78693\" Gain=\"28.39\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.76\" "
    "BeamWidthAthwartship=\"5.79\" AngleOffsetAlongship=\"-0.01\" AngleOffsetAthwartship=\"-0.03\" "
    "/>\n                        <FrequencyPar Frequency=\"79189\" Gain=\"28.42\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"5.72\" BeamWidthAthwartship=\"5.79\" "
    "AngleOffsetAlongship=\"-0.04\" AngleOffsetAthwartship=\"-0.02\" />\n                        "
    "<FrequencyPar Frequency=\"79684\" Gain=\"28.55\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.71\" BeamWidthAthwartship=\"5.64\" AngleOffsetAlongship=\"-0.02\" "
    "AngleOffsetAthwartship=\"-0.01\" />\n                        <FrequencyPar "
    "Frequency=\"80180\" Gain=\"28.66\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.5\" "
    "BeamWidthAthwartship=\"5.69\" AngleOffsetAlongship=\"-0.08\" AngleOffsetAthwartship=\"-0.01\" "
    "/>\n                        <FrequencyPar Frequency=\"80675\" Gain=\"28.68\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"5.55\" BeamWidthAthwartship=\"5.73\" "
    "AngleOffsetAlongship=\"-0.09\" AngleOffsetAthwartship=\"-0.01\" />\n                        "
    "<FrequencyPar Frequency=\"81171\" Gain=\"28.76\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.48\" BeamWidthAthwartship=\"5.71\" AngleOffsetAlongship=\"-0.1\" "
    "AngleOffsetAthwartship=\"-0.01\" />\n                        <FrequencyPar "
    "Frequency=\"81666\" Gain=\"28.93\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.31\" "
    "BeamWidthAthwartship=\"5.44\" AngleOffsetAlongship=\"-0.1\" AngleOffsetAthwartship=\"-0.03\" "
    "/>\n                        <FrequencyPar Frequency=\"82162\" Gain=\"29.03\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"5.26\" BeamWidthAthwartship=\"5.43\" "
    "AngleOffsetAlongship=\"-0.09\" AngleOffsetAthwartship=\"-0.03\" />\n                        "
    "<FrequencyPar Frequency=\"82657\" Gain=\"29.1\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.27\" BeamWidthAthwartship=\"5.39\" AngleOffsetAlongship=\"-0.09\" "
    "AngleOffsetAthwartship=\"-0.01\" />\n                        <FrequencyPar "
    "Frequency=\"83153\" Gain=\"29.21\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.25\" "
    "BeamWidthAthwartship=\"5.33\" AngleOffsetAlongship=\"-0.07\" AngleOffsetAthwartship=\"-0.02\" "
    "/>\n                        <FrequencyPar Frequency=\"83648\" Gain=\"29.37\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"5.12\" BeamWidthAthwartship=\"5.24\" "
    "AngleOffsetAlongship=\"-0.08\" AngleOffsetAthwartship=\"0.01\" />\n                        "
    "<FrequencyPar Frequency=\"84144\" Gain=\"29.46\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.11\" BeamWidthAthwartship=\"5.18\" AngleOffsetAlongship=\"-0.07\" "
    "AngleOffsetAthwartship=\"-0.01\" />\n                        <FrequencyPar "
    "Frequency=\"84639\" Gain=\"29.57\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.05\" "
    "BeamWidthAthwartship=\"5.26\" AngleOffsetAlongship=\"-0.08\" AngleOffsetAthwartship=\"-0.03\" "
    "/>\n                        <FrequencyPar Frequency=\"85135\" Gain=\"29.67\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"5.1\" BeamWidthAthwartship=\"5.34\" "
    "AngleOffsetAlongship=\"-0.06\" AngleOffsetAthwartship=\"-0.04\" />\n                        "
    "<FrequencyPar Frequency=\"85630\" Gain=\"29.8\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.17\" BeamWidthAthwartship=\"5.22\" AngleOffsetAlongship=\"-0.05\" "
    "AngleOffsetAthwartship=\"0\" />\n                        <FrequencyPar Frequency=\"86126\" "
    "Gain=\"29.93\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.08\" "
    "BeamWidthAthwartship=\"5.17\" AngleOffsetAlongship=\"-0.04\" AngleOffsetAthwartship=\"-0.03\" "
    "/>\n                        <FrequencyPar Frequency=\"86621\" Gain=\"30.05\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"5.1\" BeamWidthAthwartship=\"5.17\" "
    "AngleOffsetAlongship=\"-0.05\" AngleOffsetAthwartship=\"-0.02\" />\n                        "
    "<FrequencyPar Frequency=\"87117\" Gain=\"30.11\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.05\" BeamWidthAthwartship=\"5.19\" AngleOffsetAlongship=\"-0.1\" "
    "AngleOffsetAthwartship=\"-0.03\" />\n                        <FrequencyPar "
    "Frequency=\"87612\" Gain=\"30.23\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"4.96\" "
    "BeamWidthAthwartship=\"5.06\" AngleOffsetAlongship=\"-0.07\" AngleOffsetAthwartship=\"-0.01\" "
    "/>\n                        <FrequencyPar Frequency=\"88108\" Gain=\"30.42\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"4.67\" BeamWidthAthwartship=\"5.03\" "
    "AngleOffsetAlongship=\"-0.12\" AngleOffsetAthwartship=\"0.05\" />\n                        "
    "<FrequencyPar Frequency=\"88603\" Gain=\"30.49\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"4.86\" BeamWidthAthwartship=\"5\" AngleOffsetAlongship=\"-0.11\" "
    "AngleOffsetAthwartship=\"0.01\" />\n                        <FrequencyPar Frequency=\"89099\" "
    "Gain=\"30.61\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"4.74\" "
    "BeamWidthAthwartship=\"4.82\" AngleOffsetAlongship=\"-0.15\" AngleOffsetAthwartship=\"0.04\" "
    "/>\n                        <FrequencyPar Frequency=\"89594\" Gain=\"30.68\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"4.75\" BeamWidthAthwartship=\"4.82\" "
    "AngleOffsetAlongship=\"-0.12\" AngleOffsetAthwartship=\"0.03\" />\n                        "
    "<FrequencyPar Frequency=\"90000\" Gain=\"30.72\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"4.73\" BeamWidthAthwartship=\"4.75\" AngleOffsetAlongship=\"-0.12\" "
    "AngleOffsetAthwartship=\"0.05\" />\n                    </Transducer>\n                "
    "</Channel>\n            </Channels>\n        </Transceiver>\n        <Transceiver "
    "TransceiverName=\"WBT 400051\" IPAddress=\"157.237.15.103\" MarketSegment=\"Scientific\" "
    "SerialNumber=\"400051\" Impedance=\"5400\" Multiplexing=\"0\" RxSampleFrequency=\"1500000\" "
    "EthernetAddress=\"009072061ab3\" Version=\"[0] Ethernet: 00:90:72:06:1A:B3&#x0D;&#x0A;[1] "
    "Parts-list: WBT 371790/F&#x0D;&#x0A;[2] Product: WBT&#x0D;&#x0A;IP Address: "
    "157.237.15.103&#x0D;&#x0A;Subnet mask: 255.255.0.0&#x0D;&#x0A;Default gateway: "
    "157.237.15.1&#x0D;&#x0A;Serial number: 400051&#x0D;&#x0A;Embedded software: Rev. "
    "2.54&#x0D;&#x0A;FPGA TX firmware: Rev. 5&#x0D;&#x0A;FPGA RX firmware: Rev. 7&#x0D;&#x0A;CH1: "
    "508W CH2: 503W CH3: 492W CH4: 499W&#x0D;&#x0A;TRD1: Unable to detect "
    "transducer&#x0D;&#x0A;TRD2: Unable to detect transducer&#x0D;&#x0A;TRD3: Unable to detect "
    "transducer&#x0D;&#x0A;TRD4: Unable to detect transducer&#x0D;&#x0A;\" "
    "TransceiverSoftwareVersion=\"2.54\" TransceiverNumber=\"3\" TransceiverType=\"WBT\">\n        "
    "    <Channels>\n                <Channel ChannelID=\"WBT 400051-15 ES120-7C_ES\" "
    "LogicalChannelID=\"WBT 400051-15 ES120-7C\" ChannelIdShort=\"ES120-7C Serial No: 1969\" "
    "MaxTxPowerTransceiver=\"2000\" HWChannelConfiguration=\"15\" "
    "PulseDuration=\"6.4e-05;0.000128;0.000256;0.000512;0.001024\" "
    "PulseDurationFM=\"0.000512;0.001024;0.002048;0.004096;0.008192\">\n                    "
    "<Transducer TransducerName=\"ES120-7C\" SerialNumber=\"1969\" Frequency=\"120000\" "
    "FrequencyMinimum=\"90000\" FrequencyMaximum=\"170000\" MaxTxPowerTransducer=\"250\" "
    "Gain=\"27;27;27;27;27\" SaCorrection=\"0;0;0;0;0\" EquivalentBeamAngle=\"-20.7\" "
    "DirectivityDropAt2XBeamWidth=\"0\" AngleSensitivityAlongship=\"23\" "
    "AngleSensitivityAthwartship=\"23\" AngleOffsetAlongship=\"0\" AngleOffsetAthwartship=\"0\" "
    "BeamWidthAlongship=\"7\" BeamWidthAthwartship=\"7\" BeamType=\"1\" />\n                "
    "</Channel>\n            </Channels>\n        </Transceiver>\n        <Transceiver "
    "TransceiverName=\"WBT 400052\" IPAddress=\"157.237.15.102\" MarketSegment=\"Scientific\" "
    "SerialNumber=\"400052\" Impedance=\"5400\" Multiplexing=\"0\" RxSampleFrequency=\"1500000\" "
    "EthernetAddress=\"009072061ab4\" Version=\"[0] Ethernet: 00:90:72:06:1A:B4&#x0D;&#x0A;[1] "
    "Parts-list: WBT 371790/F&#x0D;&#x0A;[2] Product: WBT&#x0D;&#x0A;IP Address: "
    "157.237.15.102&#x0D;&#x0A;Subnet mask: 255.255.0.0&#x0D;&#x0A;Default gateway: "
    "157.237.15.1&#x0D;&#x0A;Serial number: 400052&#x0D;&#x0A;Embedded software: Rev. "
    "2.54&#x0D;&#x0A;FPGA TX firmware: Rev. 5&#x0D;&#x0A;FPGA RX firmware: Rev. 7&#x0D;&#x0A;CH1: "
    "509W CH2: 510W CH3: 499W CH4: 504W&#x0D;&#x0A;TRD1: Unable to detect "
    "transducer&#x0D;&#x0A;TRD2: Unable to detect transducer&#x0D;&#x0A;TRD3: Unable to detect "
    "transducer&#x0D;&#x0A;TRD4: Unable to detect transducer&#x0D;&#x0A;\" "
    "TransceiverSoftwareVersion=\"2.54\" TransceiverNumber=\"4\" TransceiverType=\"WBT\">\n        "
    "    <Channels>\n                <Channel ChannelID=\"WBT 400052-15 ES200-7C_ES\" "
    "LogicalChannelID=\"WBT 400052-15 ES200-7C\" ChannelIdShort=\"ES200-7C Serial No: 798\" "
    "MaxTxPowerTransceiver=\"2000\" HWChannelConfiguration=\"15\" "
    "PulseDuration=\"6.4e-05;0.000128;0.000256;0.000512;0.001024\" "
    "PulseDurationFM=\"0.000512;0.001024;0.002048;0.004096;0.008192\">\n                    "
    "<Transducer TransducerName=\"ES200-7C\" SerialNumber=\"798\" Frequency=\"200000\" "
    "FrequencyMinimum=\"160000\" FrequencyMaximum=\"260000\" MaxTxPowerTransducer=\"150\" "
    "Gain=\"26;26;26;26;26\" SaCorrection=\"0;0;0;0;0\" EquivalentBeamAngle=\"-20.7\" "
    "DirectivityDropAt2XBeamWidth=\"0\" AngleSensitivityAlongship=\"23\" "
    "AngleSensitivityAthwartship=\"23\" AngleOffsetAlongship=\"0\" AngleOffsetAthwartship=\"0\" "
    "BeamWidthAlongship=\"7\" BeamWidthAthwartship=\"7\" BeamType=\"1\">\n                        "
    "<FrequencyPar Frequency=\"160000\" Gain=\"24.54\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"8.11\" BeamWidthAthwartship=\"8.07\" AngleOffsetAlongship=\"-0.14\" "
    "AngleOffsetAthwartship=\"-0.12\" />\n                        <FrequencyPar "
    "Frequency=\"161001\" Gain=\"24.7\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.92\" "
    "BeamWidthAthwartship=\"8\" AngleOffsetAlongship=\"-0.14\" AngleOffsetAthwartship=\"-0.11\" "
    "/>\n                        <FrequencyPar Frequency=\"162002\" Gain=\"24.86\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.79\" BeamWidthAthwartship=\"7.82\" "
    "AngleOffsetAlongship=\"-0.15\" AngleOffsetAthwartship=\"-0.17\" />\n                        "
    "<FrequencyPar Frequency=\"180020\" Gain=\"26.77\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.29\" BeamWidthAthwartship=\"7.28\" AngleOffsetAlongship=\"-0.31\" "
    "AngleOffsetAthwartship=\"-0.16\" />\n                        <FrequencyPar "
    "Frequency=\"181021\" Gain=\"26.79\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.27\" "
    "BeamWidthAthwartship=\"7.22\" AngleOffsetAlongship=\"-0.31\" AngleOffsetAthwartship=\"-0.17\" "
    "/>\n                        <FrequencyPar Frequency=\"182022\" Gain=\"26.87\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.16\" BeamWidthAthwartship=\"7.19\" "
    "AngleOffsetAlongship=\"-0.3\" AngleOffsetAthwartship=\"-0.17\" />\n                        "
    "<FrequencyPar Frequency=\"183023\" Gain=\"26.95\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.06\" BeamWidthAthwartship=\"7.13\" AngleOffsetAlongship=\"-0.31\" "
    "AngleOffsetAthwartship=\"-0.16\" />\n                        <FrequencyPar "
    "Frequency=\"184024\" Gain=\"27\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.05\" "
    "BeamWidthAthwartship=\"7.03\" AngleOffsetAlongship=\"-0.32\" AngleOffsetAthwartship=\"-0.16\" "
    "/>\n                        <FrequencyPar Frequency=\"185025\" Gain=\"26.96\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.03\" BeamWidthAthwartship=\"7.14\" "
    "AngleOffsetAlongship=\"-0.32\" AngleOffsetAthwartship=\"-0.15\" />\n                        "
    "<FrequencyPar Frequency=\"186026\" Gain=\"26.98\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.08\" BeamWidthAthwartship=\"7.06\" AngleOffsetAlongship=\"-0.32\" "
    "AngleOffsetAthwartship=\"-0.17\" />\n                        <FrequencyPar "
    "Frequency=\"187027\" Gain=\"27.06\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.99\" "
    "BeamWidthAthwartship=\"6.99\" AngleOffsetAlongship=\"-0.31\" AngleOffsetAthwartship=\"-0.17\" "
    "/>\n                        <FrequencyPar Frequency=\"188028\" Gain=\"27.07\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.96\" BeamWidthAthwartship=\"6.91\" "
    "AngleOffsetAlongship=\"-0.32\" AngleOffsetAthwartship=\"-0.16\" />\n                        "
    "<FrequencyPar Frequency=\"189029\" Gain=\"27.08\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.93\" BeamWidthAthwartship=\"6.91\" AngleOffsetAlongship=\"-0.32\" "
    "AngleOffsetAthwartship=\"-0.16\" />\n                        <FrequencyPar "
    "Frequency=\"190030\" Gain=\"27.15\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.79\" "
    "BeamWidthAthwartship=\"6.86\" AngleOffsetAlongship=\"-0.33\" AngleOffsetAthwartship=\"-0.15\" "
    "/>\n                        <FrequencyPar Frequency=\"191031\" Gain=\"27.23\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.75\" BeamWidthAthwartship=\"6.75\" "
    "AngleOffsetAlongship=\"-0.31\" AngleOffsetAthwartship=\"-0.15\" />\n                        "
    "<FrequencyPar Frequency=\"192032\" Gain=\"27.09\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.72\" BeamWidthAthwartship=\"6.75\" AngleOffsetAlongship=\"-0.32\" "
    "AngleOffsetAthwartship=\"-0.15\" />\n                        <FrequencyPar "
    "Frequency=\"193033\" Gain=\"27.12\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.7\" "
    "BeamWidthAthwartship=\"6.7\" AngleOffsetAlongship=\"-0.33\" AngleOffsetAthwartship=\"-0.15\" "
    "/>\n                        <FrequencyPar Frequency=\"194034\" Gain=\"27.54\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.79\" BeamWidthAthwartship=\"6.79\" "
    "AngleOffsetAlongship=\"-0.24\" AngleOffsetAthwartship=\"-0.24\" />\n                        "
    "<FrequencyPar Frequency=\"195035\" Gain=\"27.49\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.81\" BeamWidthAthwartship=\"6.79\" AngleOffsetAlongship=\"-0.23\" "
    "AngleOffsetAthwartship=\"-0.24\" />\n                        <FrequencyPar "
    "Frequency=\"196036\" Gain=\"27.56\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.7\" "
    "BeamWidthAthwartship=\"6.77\" AngleOffsetAlongship=\"-0.24\" AngleOffsetAthwartship=\"-0.24\" "
    "/>\n                        <FrequencyPar Frequency=\"197037\" Gain=\"27.66\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.66\" BeamWidthAthwartship=\"6.67\" "
    "AngleOffsetAlongship=\"-0.24\" AngleOffsetAthwartship=\"-0.24\" />\n                        "
    "<FrequencyPar Frequency=\"198038\" Gain=\"27.63\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.63\" BeamWidthAthwartship=\"6.58\" AngleOffsetAlongship=\"-0.24\" "
    "AngleOffsetAthwartship=\"-0.24\" />\n                        <FrequencyPar "
    "Frequency=\"199039\" Gain=\"27.73\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.54\" "
    "BeamWidthAthwartship=\"6.59\" AngleOffsetAlongship=\"-0.24\" AngleOffsetAthwartship=\"-0.24\" "
    "/>\n                        <FrequencyPar Frequency=\"200040\" Gain=\"27.76\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.53\" BeamWidthAthwartship=\"6.55\" "
    "AngleOffsetAlongship=\"-0.23\" AngleOffsetAthwartship=\"-0.24\" />\n                        "
    "<FrequencyPar Frequency=\"201041\" Gain=\"27.75\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.54\" BeamWidthAthwartship=\"6.58\" AngleOffsetAlongship=\"-0.23\" "
    "AngleOffsetAthwartship=\"-0.25\" />\n                        <FrequencyPar "
    "Frequency=\"202042\" Gain=\"27.82\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.49\" "
    "BeamWidthAthwartship=\"6.5\" AngleOffsetAlongship=\"-0.23\" AngleOffsetAthwartship=\"-0.25\" "
    "/>\n                        <FrequencyPar Frequency=\"203043\" Gain=\"27.82\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.4\" BeamWidthAthwartship=\"6.47\" "
    "AngleOffsetAlongship=\"-0.22\" AngleOffsetAthwartship=\"-0.24\" />\n                        "
    "<FrequencyPar Frequency=\"204044\" Gain=\"27.93\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.39\" BeamWidthAthwartship=\"6.48\" AngleOffsetAlongship=\"-0.23\" "
    "AngleOffsetAthwartship=\"-0.26\" />\n                        <FrequencyPar "
    "Frequency=\"230070\" Gain=\"28.08\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.78\" "
    "BeamWidthAthwartship=\"5.49\" AngleOffsetAlongship=\"-0.3\" AngleOffsetAthwartship=\"-0.28\" "
    "/>\n                        <FrequencyPar Frequency=\"231071\" Gain=\"28.1\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"5.74\" BeamWidthAthwartship=\"5.43\" "
    "AngleOffsetAlongship=\"-0.28\" AngleOffsetAthwartship=\"-0.29\" />\n                        "
    "<FrequencyPar Frequency=\"232072\" Gain=\"28.14\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.68\" BeamWidthAthwartship=\"5.4\" AngleOffsetAlongship=\"-0.3\" "
    "AngleOffsetAthwartship=\"-0.27\" />\n                        <FrequencyPar "
    "Frequency=\"233073\" Gain=\"28.24\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.63\" "
    "BeamWidthAthwartship=\"5.29\" AngleOffsetAlongship=\"-0.28\" AngleOffsetAthwartship=\"-0.28\" "
    "/>\n                        <FrequencyPar Frequency=\"234074\" Gain=\"28.29\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.58\" BeamWidthAthwartship=\"5.28\" "
    "AngleOffsetAlongship=\"-0.29\" AngleOffsetAthwartship=\"-0.27\" />\n                        "
    "<FrequencyPar Frequency=\"235075\" Gain=\"28.23\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.6\" BeamWidthAthwartship=\"5.29\" AngleOffsetAlongship=\"-0.29\" "
    "AngleOffsetAthwartship=\"-0.28\" />\n                        <FrequencyPar "
    "Frequency=\"236076\" Gain=\"28.24\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.6\" "
    "BeamWidthAthwartship=\"5.25\" AngleOffsetAlongship=\"-0.29\" AngleOffsetAthwartship=\"-0.26\" "
    "/>\n                        <FrequencyPar Frequency=\"237077\" Gain=\"28.36\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.48\" BeamWidthAthwartship=\"5.21\" "
    "AngleOffsetAlongship=\"-0.27\" AngleOffsetAthwartship=\"-0.28\" />\n                        "
    "<FrequencyPar Frequency=\"238078\" Gain=\"28.49\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.42\" BeamWidthAthwartship=\"5.18\" AngleOffsetAlongship=\"-0.28\" "
    "AngleOffsetAthwartship=\"-0.27\" />\n                        <FrequencyPar "
    "Frequency=\"239079\" Gain=\"28.47\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.37\" "
    "BeamWidthAthwartship=\"5.13\" AngleOffsetAlongship=\"-0.27\" AngleOffsetAthwartship=\"-0.27\" "
    "/>\n                        <FrequencyPar Frequency=\"250090\" Gain=\"30.29\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"4.84\" BeamWidthAthwartship=\"4.61\" "
    "AngleOffsetAlongship=\"-0.43\" AngleOffsetAthwartship=\"-0.17\" />\n                        "
    "<FrequencyPar Frequency=\"251091\" Gain=\"30.5\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"4.85\" BeamWidthAthwartship=\"4.63\" AngleOffsetAlongship=\"-0.42\" "
    "AngleOffsetAthwartship=\"-0.18\" />\n                        <FrequencyPar "
    "Frequency=\"252092\" Gain=\"30.66\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"4.83\" "
    "BeamWidthAthwartship=\"4.71\" AngleOffsetAlongship=\"-0.42\" AngleOffsetAthwartship=\"-0.17\" "
    "/>\n                        <FrequencyPar Frequency=\"253093\" Gain=\"30.86\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"4.83\" BeamWidthAthwartship=\"4.61\" "
    "AngleOffsetAlongship=\"-0.4\" AngleOffsetAthwartship=\"-0.2\" />\n                        "
    "<FrequencyPar Frequency=\"254094\" Gain=\"31.04\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"4.93\" BeamWidthAthwartship=\"4.6\" AngleOffsetAlongship=\"-0.43\" "
    "AngleOffsetAthwartship=\"-0.19\" />\n                        <FrequencyPar "
    "Frequency=\"255095\" Gain=\"31.29\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"4.78\" "
    "BeamWidthAthwartship=\"4.43\" AngleOffsetAlongship=\"-0.46\" AngleOffsetAthwartship=\"-0.21\" "
    "/>\n                        <FrequencyPar Frequency=\"256096\" Gain=\"31.4\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"4.75\" BeamWidthAthwartship=\"4.5\" "
    "AngleOffsetAlongship=\"-0.44\" AngleOffsetAthwartship=\"-0.2\" />\n                        "
    "<FrequencyPar Frequency=\"257097\" Gain=\"31.4\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"4.82\" BeamWidthAthwartship=\"4.47\" AngleOffsetAlongship=\"-0.47\" "
    "AngleOffsetAthwartship=\"-0.2\" />\n                        <FrequencyPar "
    "Frequency=\"258098\" Gain=\"31.32\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"4.8\" "
    "BeamWidthAthwartship=\"4.53\" AngleOffsetAlongship=\"-0.45\" AngleOffsetAthwartship=\"-0.23\" "
    "/>\n                        <FrequencyPar Frequency=\"259099\" Gain=\"31.16\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"4.82\" BeamWidthAthwartship=\"4.6\" "
    "AngleOffsetAlongship=\"-0.44\" AngleOffsetAthwartship=\"-0.24\" />\n                        "
    "<FrequencyPar Frequency=\"260000\" Gain=\"31.2\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"4.95\" BeamWidthAthwartship=\"4.76\" AngleOffsetAlongship=\"-0.47\" "
    "AngleOffsetAthwartship=\"-0.21\" />\n                        <FrequencyPar "
    "Frequency=\"170010\" Gain=\"26.1\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.55\" "
    "BeamWidthAthwartship=\"7.62\" AngleOffsetAlongship=\"-0.26\" AngleOffsetAthwartship=\"-0.18\" "
    "/>\n                        <FrequencyPar Frequency=\"171011\" Gain=\"26.24\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.55\" BeamWidthAthwartship=\"7.55\" "
    "AngleOffsetAlongship=\"-0.27\" AngleOffsetAthwartship=\"-0.18\" />\n                        "
    "<FrequencyPar Frequency=\"172012\" Gain=\"26.29\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.57\" BeamWidthAthwartship=\"7.53\" AngleOffsetAlongship=\"-0.28\" "
    "AngleOffsetAthwartship=\"-0.17\" />\n                        <FrequencyPar "
    "Frequency=\"173013\" Gain=\"26.34\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.46\" "
    "BeamWidthAthwartship=\"7.48\" AngleOffsetAlongship=\"-0.27\" AngleOffsetAthwartship=\"-0.18\" "
    "/>\n                        <FrequencyPar Frequency=\"174014\" Gain=\"26.42\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.48\" BeamWidthAthwartship=\"7.48\" "
    "AngleOffsetAlongship=\"-0.3\" AngleOffsetAthwartship=\"-0.18\" />\n                        "
    "<FrequencyPar Frequency=\"175015\" Gain=\"26.5\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.49\" BeamWidthAthwartship=\"7.52\" AngleOffsetAlongship=\"-0.29\" "
    "AngleOffsetAthwartship=\"-0.19\" />\n                        <FrequencyPar "
    "Frequency=\"176016\" Gain=\"26.61\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.5\" "
    "BeamWidthAthwartship=\"7.43\" AngleOffsetAlongship=\"-0.3\" AngleOffsetAthwartship=\"-0.18\" "
    "/>\n                        <FrequencyPar Frequency=\"177017\" Gain=\"26.68\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.42\" BeamWidthAthwartship=\"7.39\" "
    "AngleOffsetAlongship=\"-0.3\" AngleOffsetAthwartship=\"-0.16\" />\n                        "
    "<FrequencyPar Frequency=\"178018\" Gain=\"26.74\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"7.43\" BeamWidthAthwartship=\"7.37\" AngleOffsetAlongship=\"-0.32\" "
    "AngleOffsetAthwartship=\"-0.17\" />\n                        <FrequencyPar "
    "Frequency=\"179019\" Gain=\"26.73\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"7.38\" "
    "BeamWidthAthwartship=\"7.33\" AngleOffsetAlongship=\"-0.31\" AngleOffsetAthwartship=\"-0.18\" "
    "/>\n                        <FrequencyPar Frequency=\"206046\" Gain=\"28.02\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.08\" BeamWidthAthwartship=\"6.17\" "
    "AngleOffsetAlongship=\"-0.34\" AngleOffsetAthwartship=\"-0.16\" />\n                        "
    "<FrequencyPar Frequency=\"207047\" Gain=\"28.08\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"6.03\" BeamWidthAthwartship=\"6.09\" AngleOffsetAlongship=\"-0.33\" "
    "AngleOffsetAthwartship=\"-0.15\" />\n                        <FrequencyPar "
    "Frequency=\"208048\" Gain=\"28.13\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"6.02\" "
    "BeamWidthAthwartship=\"6.07\" AngleOffsetAlongship=\"-0.35\" AngleOffsetAthwartship=\"-0.15\" "
    "/>\n                        <FrequencyPar Frequency=\"209049\" Gain=\"28.2\" Impedance=\"75\" "
    "Phase=\"0\" BeamWidthAlongship=\"5.93\" BeamWidthAthwartship=\"5.99\" "
    "AngleOffsetAlongship=\"-0.35\" AngleOffsetAthwartship=\"-0.15\" />\n                        "
    "<FrequencyPar Frequency=\"210050\" Gain=\"28.18\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.93\" BeamWidthAthwartship=\"5.99\" AngleOffsetAlongship=\"-0.35\" "
    "AngleOffsetAthwartship=\"-0.16\" />\n                        <FrequencyPar "
    "Frequency=\"211051\" Gain=\"28.22\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.96\" "
    "BeamWidthAthwartship=\"5.97\" AngleOffsetAlongship=\"-0.36\" AngleOffsetAthwartship=\"-0.14\" "
    "/>\n                        <FrequencyPar Frequency=\"212052\" Gain=\"28.23\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.91\" BeamWidthAthwartship=\"5.94\" "
    "AngleOffsetAlongship=\"-0.37\" AngleOffsetAthwartship=\"-0.16\" />\n                        "
    "<FrequencyPar Frequency=\"213053\" Gain=\"28.28\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.89\" BeamWidthAthwartship=\"5.93\" AngleOffsetAlongship=\"-0.36\" "
    "AngleOffsetAthwartship=\"-0.18\" />\n                        <FrequencyPar "
    "Frequency=\"214054\" Gain=\"28.31\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.9\" "
    "BeamWidthAthwartship=\"5.93\" AngleOffsetAlongship=\"-0.37\" AngleOffsetAthwartship=\"-0.17\" "
    "/>\n                        <FrequencyPar Frequency=\"215055\" Gain=\"28.34\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.84\" BeamWidthAthwartship=\"5.77\" "
    "AngleOffsetAlongship=\"-0.37\" AngleOffsetAthwartship=\"-0.18\" />\n                        "
    "<FrequencyPar Frequency=\"216056\" Gain=\"28.37\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.93\" BeamWidthAthwartship=\"5.73\" AngleOffsetAlongship=\"-0.35\" "
    "AngleOffsetAthwartship=\"-0.16\" />\n                        <FrequencyPar "
    "Frequency=\"217057\" Gain=\"28.33\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.93\" "
    "BeamWidthAthwartship=\"5.75\" AngleOffsetAlongship=\"-0.37\" AngleOffsetAthwartship=\"-0.16\" "
    "/>\n                        <FrequencyPar Frequency=\"218058\" Gain=\"28.44\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.83\" BeamWidthAthwartship=\"5.64\" "
    "AngleOffsetAlongship=\"-0.36\" AngleOffsetAthwartship=\"-0.17\" />\n                        "
    "<FrequencyPar Frequency=\"219059\" Gain=\"28.44\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.85\" BeamWidthAthwartship=\"5.68\" AngleOffsetAlongship=\"-0.37\" "
    "AngleOffsetAthwartship=\"-0.18\" />\n                        <FrequencyPar "
    "Frequency=\"220060\" Gain=\"28.44\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.81\" "
    "BeamWidthAthwartship=\"5.65\" AngleOffsetAlongship=\"-0.39\" AngleOffsetAthwartship=\"-0.17\" "
    "/>\n                        <FrequencyPar Frequency=\"221061\" Gain=\"28.48\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.72\" BeamWidthAthwartship=\"5.6\" "
    "AngleOffsetAlongship=\"-0.38\" AngleOffsetAthwartship=\"-0.17\" />\n                        "
    "<FrequencyPar Frequency=\"222062\" Gain=\"28.48\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.73\" BeamWidthAthwartship=\"5.55\" AngleOffsetAlongship=\"-0.39\" "
    "AngleOffsetAthwartship=\"-0.17\" />\n                        <FrequencyPar "
    "Frequency=\"223063\" Gain=\"28.56\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.58\" "
    "BeamWidthAthwartship=\"5.53\" AngleOffsetAlongship=\"-0.36\" AngleOffsetAthwartship=\"-0.19\" "
    "/>\n                        <FrequencyPar Frequency=\"224064\" Gain=\"28.53\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"5.66\" BeamWidthAthwartship=\"5.53\" "
    "AngleOffsetAlongship=\"-0.37\" AngleOffsetAthwartship=\"-0.17\" />\n                        "
    "<FrequencyPar Frequency=\"225065\" Gain=\"28.47\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"5.65\" BeamWidthAthwartship=\"5.49\" AngleOffsetAlongship=\"-0.39\" "
    "AngleOffsetAthwartship=\"-0.16\" />\n                        <FrequencyPar "
    "Frequency=\"246086\" Gain=\"29.47\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"4.7\" "
    "BeamWidthAthwartship=\"4.68\" AngleOffsetAlongship=\"-0.44\" AngleOffsetAthwartship=\"-0.16\" "
    "/>\n                        <FrequencyPar Frequency=\"247087\" Gain=\"29.64\" "
    "Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"4.79\" BeamWidthAthwartship=\"4.74\" "
    "AngleOffsetAlongship=\"-0.44\" AngleOffsetAthwartship=\"-0.17\" />\n                        "
    "<FrequencyPar Frequency=\"248088\" Gain=\"29.85\" Impedance=\"75\" Phase=\"0\" "
    "BeamWidthAlongship=\"4.85\" BeamWidthAthwartship=\"4.58\" AngleOffsetAlongship=\"-0.44\" "
    "AngleOffsetAthwartship=\"-0.14\" />\n                        <FrequencyPar "
    "Frequency=\"249089\" Gain=\"30.1\" Impedance=\"75\" Phase=\"0\" BeamWidthAlongship=\"4.7\" "
    "BeamWidthAthwartship=\"4.48\" AngleOffsetAlongship=\"-0.42\" AngleOffsetAthwartship=\"-0.13\" "
    "/>\n                    </Transducer>\n                </Channel>\n            </Channels>\n  "
    "      </Transceiver>\n        <Transceiver TransceiverName=\"WBT 400058\" "
    "IPAddress=\"157.237.15.101\" MarketSegment=\"Scientific\" SerialNumber=\"400058\" "
    "Impedance=\"5400\" Multiplexing=\"0\" RxSampleFrequency=\"1500000\" "
    "EthernetAddress=\"009072061aba\" Version=\"[0] Ethernet: 00:90:72:06:1A:BA&#x0D;&#x0A;[1] "
    "Parts-list: WBT 371790/F&#x0D;&#x0A;[2] Product: WBT&#x0D;&#x0A;IP Address: "
    "157.237.15.101&#x0D;&#x0A;Subnet mask: 255.255.0.0&#x0D;&#x0A;Default gateway: "
    "157.237.15.1&#x0D;&#x0A;Serial number: 400058&#x0D;&#x0A;Embedded software: Rev. "
    "2.54&#x0D;&#x0A;FPGA TX firmware: Rev. 5&#x0D;&#x0A;FPGA RX firmware: Rev. 7&#x0D;&#x0A;CH1: "
    "517W CH2: 498W CH3: 485W CH4: 502W&#x0D;&#x0A;TRD1: Unable to detect "
    "transducer&#x0D;&#x0A;TRD2: Unable to detect transducer&#x0D;&#x0A;TRD3: Unable to detect "
    "transducer&#x0D;&#x0A;TRD4: Unable to detect transducer&#x0D;&#x0A;\" "
    "TransceiverSoftwareVersion=\"2.54\" TransceiverNumber=\"5\" TransceiverType=\"WBT\">\n        "
    "    <Channels>\n                <Channel ChannelID=\"WBT 400058-15 ES333-7C_ES\" "
    "LogicalChannelID=\"WBT 400058-15 ES333-7C\" ChannelIdShort=\"ES333-7C Serial No: 254\" "
    "MaxTxPowerTransceiver=\"2000\" HWChannelConfiguration=\"15\" "
    "PulseDuration=\"6.4e-05;0.000128;0.000256;0.000512;0.001024\" "
    "PulseDurationFM=\"0.000512;0.001024;0.002048;0.004096;0.008192\">\n                    "
    "<Transducer TransducerName=\"ES333-7C\" SerialNumber=\"254\" Frequency=\"333000\" "
    "FrequencyMinimum=\"280000\" FrequencyMaximum=\"450000\" MaxTxPowerTransducer=\"50\" "
    "Gain=\"25;25;25;25;23.71\" SaCorrection=\"0;0;0;0;-0.56\" EquivalentBeamAngle=\"-20.7\" "
    "DirectivityDropAt2XBeamWidth=\"0\" AngleSensitivityAlongship=\"23\" "
    "AngleSensitivityAthwartship=\"23\" AngleOffsetAlongship=\"-0.06\" "
    "AngleOffsetAthwartship=\"-0.06\" BeamWidthAlongship=\"5.7\" BeamWidthAthwartship=\"6.55\" "
    "BeamType=\"1\" />\n                </Channel>\n            </Channels>\n        "
    "</Transceiver>\n    </Transceivers>\n    <Transducers MergeOperation=\"AddNodeTree\">\n       "
    " <Transducer TransducerName=\"ES38-7\" TransducerSerialNumber=\"331\" "
    "TransducerCustomName=\"ES38-7 Serial No: 331 - Narrow\" TransducerMounting=\"DropKeel\" "
    "TransducerOffsetX=\"7.88\" TransducerOffsetY=\"1.09\" TransducerOffsetZ=\"5.87\" "
    "TransducerAlphaX=\"-0.5\" TransducerAlphaY=\"1.5\" TransducerAlphaZ=\"0.5\" />\n        "
    "<Transducer TransducerName=\"ES70-7C\" TransducerSerialNumber=\"604\" "
    "TransducerCustomName=\"ES70-7C Serial No: 604\" TransducerMounting=\"DropKeel\" "
    "TransducerOffsetX=\"8.22\" TransducerOffsetY=\"1.47\" TransducerOffsetZ=\"5.88\" "
    "TransducerAlphaX=\"0.6\" TransducerAlphaY=\"1\" TransducerAlphaZ=\"0\" />\n        "
    "<Transducer TransducerName=\"ES120-7C\" TransducerSerialNumber=\"1969\" "
    "TransducerCustomName=\"ES120-7C Serial No: 1969\" TransducerMounting=\"DropKeel\" "
    "TransducerOffsetX=\"8.27\" TransducerOffsetY=\"1.17\" TransducerOffsetZ=\"5.87\" "
    "TransducerAlphaX=\"-0.5\" TransducerAlphaY=\"0.9\" TransducerAlphaZ=\"0.2\" />\n        "
    "<Transducer TransducerName=\"ES200-7C\" TransducerSerialNumber=\"798\" "
    "TransducerCustomName=\"ES200-7C Serial No: 798\" TransducerMounting=\"DropKeel\" "
    "TransducerOffsetX=\"8.22\" TransducerOffsetY=\"0.94\" TransducerOffsetZ=\"5.88\" "
    "TransducerAlphaX=\"-1.2\" TransducerAlphaY=\"0.9\" TransducerAlphaZ=\"0.4\" />\n        "
    "<Transducer TransducerName=\"ES333-7C\" TransducerSerialNumber=\"254\" "
    "TransducerCustomName=\"ES333-7C Serial No: 254\" TransducerMounting=\"DropKeel\" "
    "TransducerOffsetX=\"8.43\" TransducerOffsetY=\"0.99\" TransducerOffsetZ=\"5.88\" "
    "TransducerAlphaX=\"-1.3\" TransducerAlphaY=\"0.3\" TransducerAlphaZ=\"-1\" />\n    "
    "</Transducers>\n    <ConfiguredSensors MergeOperation=\"AddNodeTree\">\n        <Sensor "
    "Name=\"GPS From Serial Port 2 Seapath 380-R3\" Type=\"GPS\" Port=\"Serial Port 2\" "
    "TalkerID=\"\" X=\"0\" Y=\"0\" Z=\"0\" AngleX=\"0\" AngleY=\"0\" AngleZ=\"0\" Unique=\"0\" "
    "Timeout=\"20\">\n            <Telegram Name=\"GGA from GPS From Serial Port 2 Seapath "
    "380-R3\" SensorType=\"GPS\" Type=\"GGA\" SubscriptionPath=\"GPS From Serial Port 2 Seapath "
    "380-R3@GPS.Global.Position\" Enabled=\"1\">\n                <Value Name=\"Latitude\" "
    "Priority=\"1\" />\n                <Value Name=\"Longitude\" Priority=\"1\" />\n            "
    "</Telegram>\n            <Telegram Name=\"VTG from GPS From Serial Port 2 Seapath 380-R3\" "
    "SensorType=\"GPS\" Type=\"VTG\" SubscriptionPath=\"GPS From Serial Port 2 Seapath "
    "380-R3@GPS.Ground\" Enabled=\"1\">\n                <Value Name=\"Course\" Priority=\"3\" "
    "/>\n                <Value Name=\"CourseNotUsedMagnetic\" Priority=\"1\" />\n                "
    "<Value Name=\"Speed\" Priority=\"1\" />\n            </Telegram>\n            <Telegram "
    "Name=\"ZDA from GPS From Serial Port 2 Seapath 380-R3\" SensorType=\"GPS\" Type=\"ZDA\" "
    "SubscriptionPath=\"GPS From Serial Port 2 Seapath 380-R3@GPS.TimeInfo\" Enabled=\"1\">\n      "
    "          <Value Name=\"TimeInfo\" Priority=\"1\" />\n            </Telegram>\n        "
    "</Sensor>\n        <Sensor Name=\"GPS From Serial Port 3 Veripos LD5 #1\" Type=\"GPS\" "
    "Port=\"Serial Port 3\" TalkerID=\"\" X=\"5.32\" Y=\"-2.02\" Z=\"-24.36\" AngleX=\"0\" "
    "AngleY=\"0\" AngleZ=\"0\" Unique=\"0\" Timeout=\"20\">\n            <Telegram Name=\"GGA from "
    "GPS From Serial Port 3 Veripos LD5 #1\" SensorType=\"GPS\" Type=\"GGA\" "
    "SubscriptionPath=\"GPS From Serial Port 3 Veripos LD5 #1@GPS.Global.Position\" "
    "Enabled=\"1\">\n                <Value Name=\"Latitude\" Priority=\"2\" />\n                "
    "<Value Name=\"Longitude\" Priority=\"2\" />\n            </Telegram>\n            <Telegram "
    "Name=\"VTG from GPS From Serial Port 3 Veripos LD5 #1\" SensorType=\"GPS\" Type=\"VTG\" "
    "SubscriptionPath=\"GPS From Serial Port 3 Veripos LD5 #1@GPS.Ground\" Enabled=\"1\">\n        "
    "        <Value Name=\"Course\" Priority=\"4\" />\n                <Value "
    "Name=\"CourseNotUsedMagnetic\" Priority=\"2\" />\n                <Value Name=\"Speed\" "
    "Priority=\"2\" />\n            </Telegram>\n            <Telegram Name=\"ZDA from GPS From "
    "Serial Port 3 Veripos LD5 #1\" SensorType=\"GPS\" Type=\"ZDA\" SubscriptionPath=\"GPS From "
    "Serial Port 3 Veripos LD5 #1@GPS.TimeInfo\" Enabled=\"1\">\n                <Value "
    "Name=\"TimeInfo\" Priority=\"2\" />\n            </Telegram>\n        </Sensor>\n        "
    "<Sensor Name=\"MotionBinary From Serial Port 4 Seapath 380-R3\" Type=\"MotionBinary\" "
    "Port=\"Serial Port 4\" TalkerID=\"\" X=\"0\" Y=\"0\" Z=\"0\" AngleX=\"0\" AngleY=\"0\" "
    "AngleZ=\"0\" Unique=\"0\" Timeout=\"20\">\n            <Telegram Name=\"MRU from MotionBinary "
    "From Serial Port 4 Seapath 380-R3\" SensorType=\"MotionBinary\" Type=\"MRU\" "
    "SubscriptionPath=\"MotionBinary From Serial Port 4 Seapath 380-R3@MotionBinary.MotionData\" "
    "Enabled=\"1\">\n                <Value Name=\"Roll\" Priority=\"1\" />\n                "
    "<Value Name=\"Pitch\" Priority=\"1\" />\n                <Value Name=\"Heading\" "
    "Priority=\"1\" />\n                <Value Name=\"Heave\" Priority=\"1\" />\n            "
    "</Telegram>\n        </Sensor>\n        <Sensor Name=\"MotionBinary From Serial Port 5 "
    "IMU-108 #1\" Type=\"MotionBinary\" Port=\"Serial Port 5\" TalkerID=\"\" X=\"0\" Y=\"0\" "
    "Z=\"0\" AngleX=\"0\" AngleY=\"0\" AngleZ=\"0\" Unique=\"0\" Timeout=\"20\">\n            "
    "<Telegram Name=\"MRU from MotionBinary From Serial Port 5 IMU-108 #1\" "
    "SensorType=\"MotionBinary\" Type=\"MRU\" SubscriptionPath=\"MotionBinary From Serial Port 5 "
    "IMU-108 #1@MotionBinary.MotionData\" Enabled=\"1\">\n                <Value Name=\"Roll\" "
    "Priority=\"2\" />\n                <Value Name=\"Pitch\" Priority=\"2\" />\n                "
    "<Value Name=\"Heading\" Priority=\"2\" />\n                <Value Name=\"Heave\" "
    "Priority=\"2\" />\n            </Telegram>\n        </Sensor>\n        <Sensor Name=\"ITI-FS "
    "From LAN Port 3 (FX In)\" Type=\"ITI-FS\" Port=\"Lan Port 3\" TalkerID=\"II\" X=\"0\" Y=\"0\" "
    "Z=\"0\" AngleX=\"0\" AngleY=\"0\" AngleZ=\"0\" Unique=\"0\" Timeout=\"20\">\n            "
    "<Telegram Name=\"ITI-FS Datagrams from ITI-FS From LAN Port 3 (FX In)\" SensorType=\"ITI-FS\" "
    "Type=\"ITI-FS Datagrams\" SubscriptionPath=\"ITI-FS From LAN Port 3 (FX In)@ITI-FS.ITI-FS\" "
    "Enabled=\"1\">\n                <Value Name=\"ITI-FS\" Priority=\"1\" />\n            "
    "</Telegram>\n        </Sensor>\n        <Sensor Name=\"PI50 From LAN Port 4 (PX In)\" "
    "Type=\"PI50\" Port=\"Lan Port 4\" TalkerID=\"\" X=\"0\" Y=\"0\" Z=\"0\" AngleX=\"0\" "
    "AngleY=\"0\" AngleZ=\"0\" Unique=\"0\" Timeout=\"20\">\n            <Telegram Name=\"PI50 "
    "Datagrams from PI50 From LAN Port 4 (PX In)\" SensorType=\"PI50\" Type=\"PI50 Datagrams\" "
    "SubscriptionPath=\"PI50 From LAN Port 4 (PX In)@PI50.PI50\" Enabled=\"1\">\n                "
    "<Value Name=\"PI50\" Priority=\"1\" />\n            </Telegram>\n        </Sensor>\n        "
    "<Sensor Name=\"Sound Speed From LAN Port 5 (SV SB DK In)\" Type=\"SoundVelocity\" Port=\"Lan "
    "Port 5\" TalkerID=\"\" X=\"0\" Y=\"0\" Z=\"0\" AngleX=\"0\" AngleY=\"0\" AngleZ=\"0\" "
    "Unique=\"0\" Timeout=\"20\">\n            <Telegram Name=\"AML from Sound Speed From LAN Port "
    "5 (SV SB DK In)\" SensorType=\"SoundVelocity\" Type=\"AML\" SubscriptionPath=\"Sound Speed "
    "From LAN Port 5 (SV SB DK In)@SoundVelocity.SoundVelocity\" Enabled=\"1\">\n                "
    "<Value Name=\"SoundVelocityTransducer\" Priority=\"1\" />\n            </Telegram>\n        "
    "</Sensor>\n    </ConfiguredSensors>\n</Configuration>\x00\x00\x00";

// using namespace testing;
using namespace std;
using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;
using namespace themachinethatgoesping::echosounders::simradraw::filedatatypes::calibration;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace themachinethatgoesping::echosounders;
#define TESTTAG "[SimradRawWaterColumnCalibration]"

TEST_CASE("SimradRawWaterColumnCalibration should support common functions", TESTTAG)
{
    using Catch::Approx;

    // read transceiver information
    datagrams::XML0 dat;
    dat.set_xml_content(xml_string);
    auto xml_configuration = std::get<datagrams::xml_datagrams::XML_Configuration>(dat.decode());
    // read transceiver and transceiver channel
    auto transceiver = xml_configuration.get_transceiver("WBT 400058-15 ES333-7C_ES");
    auto transceiver_channel =
        xml_configuration.get_transceiver_channel("WBT 400058-15 ES333-7C_ES");
    // setup fake packages
    filedatatypes::_sub::TransceiverInformation tr_infos(transceiver, transceiver_channel);

    float transducer_gain_db       = 25.0f;          // take from xml datagram at pulse index 1
    float sa_correction_db         = 0.0f;           // take from xml datagram
    float equivalent_beam_angle_db = -20.700000763f; // take from xml datagram
    float frequency_nominal_hz     = 333000.0f;      // take from xml datagram

    float reference_depth_m = 20.0f;
    float temperature_c     = 10.0f;
    float salinity_psu      = 30.0f;
    float latitude          = 42.f;

    float frequency_hz               = 350000.0f;
    float transmit_power_w           = 5000.0f;
    float pulse_duration_s           = 0.000128f; // should be pulse index 1 for ES333 transducer
    float slope                      = 0.5f;
    float effective_pulse_duration_s = pulse_duration_s * slope;

    size_t n_complex_samples = 4;
    float  impedance_factor  = tr_infos.get_impedance_factor();

    datagrams::xml_datagrams::XML_Environment environment;
    environment.Depth       = reference_depth_m;
    environment.Temperature = temperature_c;
    environment.Salinity    = salinity_psu;
    environment.Latitude    = latitude;

    datagrams::xml_datagrams::XML_Parameter_Channel parameters;
    parameters.Frequency     = frequency_hz;
    parameters.TransmitPower = transmit_power_w;
    parameters.Slope         = slope;
    parameters.PulseDuration = pulse_duration_s;
    parameters.PulseForm     = 0; // CW

    auto cal0      = SimradRawWaterColumnCalibration();
    auto cal_power = SimradRawWaterColumnCalibration(environment, parameters, tr_infos, 0);
    auto cal_cmplx =
        SimradRawWaterColumnCalibration(environment, parameters, tr_infos, n_complex_samples);

    SECTION("SimradRawWaterColumnCalibration should support common functions")
    {
        // test hash (should be stable if class is not changed)
        CHECK(cal0.binary_hash() == 18195875943434653442ULL);
        CHECK(cal_power.binary_hash() == 16598773257346738920ULL);
        CHECK(cal_cmplx.binary_hash() == 7487456784068775051ULL);

        // test equality
        CHECK(cal0 == cal0);
        CHECK(cal_power == cal_power);
        CHECK(cal_cmplx == cal_cmplx);
        CHECK(cal0 != cal_power);
        CHECK(cal0 != cal_cmplx);
        CHECK(cal_power != cal_cmplx);

        //    test initialized
        CHECK(cal0.initialized() == false);
        CHECK(cal_power.initialized() == true);
        CHECK(cal_cmplx.initialized() == true);

        // test copy
        {
            CHECK(cal0 == SimradRawWaterColumnCalibration(cal0));
            CHECK(cal_power == SimradRawWaterColumnCalibration(cal_power));
            CHECK(cal_cmplx == SimradRawWaterColumnCalibration(cal_cmplx));
        }

        // test binary
        CHECK(cal0 == SimradRawWaterColumnCalibration(cal0.from_binary(cal0.to_binary())));
        CHECK(cal_power ==
              SimradRawWaterColumnCalibration(cal_power.from_binary(cal_power.to_binary())));
        CHECK(cal_cmplx ==
              SimradRawWaterColumnCalibration(cal_cmplx.from_binary(cal_cmplx.to_binary())));

        // test stream
        std::stringstream buffer;
        cal0.to_stream(buffer);
        cal_power.to_stream(buffer);
        cal_cmplx.to_stream(buffer);
        CHECK(cal0 == SimradRawWaterColumnCalibration(cal0.from_stream(buffer)));
        CHECK(cal_power == SimradRawWaterColumnCalibration(cal_power.from_stream(buffer)));
        CHECK(cal_cmplx == SimradRawWaterColumnCalibration(cal_cmplx.from_stream(buffer)));

        // test print does not crash
        CHECK(cal0.info_string().size() != 0);
        CHECK(cal_power.info_string().size() != 0);
        CHECK(cal_cmplx.info_string().size() != 0);
    }

    SECTION("SimradRawWaterColumnCalibration should support data access")
    {
        // test data access
        CHECK(cal_power.get_transducer_gain_db() == Approx(transducer_gain_db));
        CHECK(cal_cmplx.get_transducer_gain_db() == Approx(transducer_gain_db));
        CHECK(cal_power.get_sa_correction_db() == Approx(sa_correction_db));
        CHECK(cal_cmplx.get_sa_correction_db() == Approx(sa_correction_db));
        CHECK(cal_power.get_equivalent_beam_angle_db() == Approx(equivalent_beam_angle_db));
        CHECK(cal_cmplx.get_equivalent_beam_angle_db() == Approx(equivalent_beam_angle_db));
        CHECK(cal_power.get_frequency_nominal_hz() == Approx(frequency_nominal_hz));
        CHECK(cal_cmplx.get_frequency_nominal_hz() == Approx(frequency_nominal_hz));

        CHECK(cal_power.get_reference_depth_m() == Approx(reference_depth_m));
        CHECK(cal_cmplx.get_reference_depth_m() == Approx(reference_depth_m));
        CHECK(cal_power.get_temperature_c() == Approx(temperature_c));
        CHECK(cal_cmplx.get_temperature_c() == Approx(temperature_c));
        CHECK(cal_power.get_salinity_psu() == Approx(salinity_psu));
        CHECK(cal_cmplx.get_salinity_psu() == Approx(salinity_psu));

        CHECK(cal_power.get_frequency_hz() == Approx(frequency_hz));
        CHECK(cal_cmplx.get_frequency_hz() == Approx(frequency_hz));
        CHECK(cal_power.get_transmit_power_w() == Approx(transmit_power_w));
        CHECK(cal_cmplx.get_transmit_power_w() == Approx(transmit_power_w));
        CHECK(cal_power.get_effective_pulse_duration_s() == Approx(effective_pulse_duration_s));
        CHECK(cal_cmplx.get_effective_pulse_duration_s() == Approx(effective_pulse_duration_s));

        // computed values
        CHECK(cal_power.get_sound_velocity_m_s() == Approx(1484.040527344f));
        CHECK(cal_cmplx.get_sound_velocity_m_s() == Approx(1484.040527344f));
        CHECK(cal_power.get_absorption_db_m() == Approx(0.077657893f));
        CHECK(cal_cmplx.get_absorption_db_m() == Approx(0.077657893f));
        CHECK(cal_power.get_wavelength_m() ==
              Approx(cal_power.get_sound_velocity_m_s() / frequency_hz));
        CHECK(cal_cmplx.get_wavelength_m() ==
              Approx(cal_power.get_sound_velocity_m_s() / frequency_hz));
        CHECK(cal_power.get_corr_transducer_gain_db() ==
              Approx(transducer_gain_db + 20 * log10(frequency_hz / frequency_nominal_hz)));
        CHECK(cal_cmplx.get_corr_transducer_gain_db() ==
              Approx(transducer_gain_db + 20 * log10(frequency_hz / frequency_nominal_hz)));
        CHECK(cal_power.get_corr_equivalent_beam_angle_db() ==
              Approx(equivalent_beam_angle_db + 20 * log10(frequency_hz / frequency_nominal_hz)));
        CHECK(cal_cmplx.get_corr_equivalent_beam_angle_db() ==
              Approx(equivalent_beam_angle_db + 20 * log10(frequency_hz / frequency_nominal_hz)));

        CHECK(cal_power.get_n_complex_samples() == 0);
        CHECK(cal_cmplx.get_n_complex_samples() == n_complex_samples);
        CHECK(cal_power.get_power_conversion_factor_db() == std::nullopt);
        CHECK(cal_cmplx.get_power_conversion_factor_db().value() == Approx(-33.682f));

        CHECK(cal_power.get_rounded_latitude_deg() == latitude);
        CHECK(cal_cmplx.get_rounded_latitude_deg() == latitude);
        CHECK(cal_power.get_rounded_longitude_deg() == std::nullopt);
        CHECK(cal_cmplx.get_rounded_longitude_deg() == std::nullopt);
    }

    SECTION("SimradRawWaterColumnCalibration should setup callibration correctly")
    {
        // water column calibration
        CHECK(cal_power.get_tvg_absorption_db_m() == 0.0f);
        CHECK(cal_cmplx.get_tvg_absorption_db_m() == 0.0f);
        CHECK(cal_power.get_tvg_factor() == 0.0f);
        CHECK(cal_cmplx.get_tvg_factor() == 0.0f);
        CHECK(cal_power.get_absorption_to_apply().value_or(0.f) ==
              Approx(cal_power.get_absorption_db_m()));
        CHECK(cal_cmplx.get_absorption_to_apply().value_or(0.f) ==
              Approx(cal_cmplx.get_absorption_db_m()));
        CHECK(cal_power.get_tvg_factor_to_apply(0) == std::nullopt);
        CHECK(cal_power.get_tvg_factor_to_apply(20) == Approx(20.f));
        CHECK(cal_cmplx.get_tvg_factor_to_apply(40) == Approx(40.f));

        CHECK(cal_cmplx.get_power_calibration().get_system_offset() ==
              Approx(cal_cmplx.get_power_conversion_factor_db().value()));

        // compute expected calibration offsets
        float sound_velocity                  = cal_power.get_sound_velocity_m_s();
        float wavelength                      = cal_power.get_wavelength_m();
        float corrected_transducer_gain       = cal_power.get_corr_transducer_gain_db();
        float corrected_equivalent_beam_angle = cal_power.get_corr_equivalent_beam_angle_db();
        float sp_factor =
            -10 * std::log10(transmit_power_w * wavelength * wavelength / (16 * M_PIf * M_PIf)) -
            2 * corrected_transducer_gain;
        float sv_factor = -10 * std::log10(sound_velocity * effective_pulse_duration_s / 2) -
                          corrected_equivalent_beam_angle - 2 * sa_correction_db;

        CHECK(cal_power.get_power_calibration().get_system_offset() == 0.f);
        CHECK(cal_power.get_ap_calibration().get_system_offset() == Approx(0.f + sp_factor));
        CHECK(cal_power.get_av_calibration().get_system_offset() ==
              Approx(0.f + sp_factor + sv_factor));

        float power_offset = cal_cmplx.get_power_conversion_factor_db().value();
        CHECK(cal_cmplx.get_power_calibration().get_system_offset() == Approx(power_offset));
        CHECK(cal_cmplx.get_ap_calibration().get_system_offset() ==
              Approx(power_offset + sp_factor));
        CHECK(cal_cmplx.get_av_calibration().get_system_offset() ==
              Approx(power_offset + sp_factor + sv_factor));
    }

    SECTION("SimradRawWaterColumnCalibration should support initialization from individual values")
    {
        // --- test creation using individual parameters ---
        auto cal_power2 = cal0;
        cal_power2.set_power_calibration_parameters(0, std::nullopt, false);
        cal_power2.set_transducer_parameters(transducer_gain_db,
                                             sa_correction_db,
                                             equivalent_beam_angle_db,
                                             frequency_nominal_hz,
                                             false);
        cal_power2.set_environment_parameters(
            reference_depth_m, temperature_c, salinity_psu, false);
        cal_power2.set_runtime_parameters(
            frequency_hz, transmit_power_w, effective_pulse_duration_s, false);
        cal_power2.set_optional_parameters(latitude, std::nullopt, false);
        cal_power2.setup_simrad_calibration();
        INFO(cal_power.info_string());
        INFO("----");
        INFO(cal_power2.info_string());
        CHECK(cal_power == cal_power2);

        auto cal_cmplx2 = cal_power2;
        cal_cmplx2.set_power_calibration_parameters(n_complex_samples, impedance_factor, false);
        cal_cmplx2.setup_simrad_calibration();
        CHECK(cal_cmplx == cal_cmplx2);
    }
}
