# Remaining Header Files Needing Implementation Refactoring
*Continuing work from PRs #25 and #26*

Based on analysis of implementation content in header files, the following files
contain substantial function implementations that should be moved to .cpp files
to reduce compilation time and header bloat.

## High Priority Files (Score > 20) - 113 files

These files have the most substantial implementations and should be prioritized:

 1. **`pingtools/pingsampleselector.hpp`**
    - Score: 330.6
    - Total lines: 629
    - Complex function lines: 367
    - Stream implementation lines: 2
    - Printer implementation lines: 65

 2. **`kongsbergall/datagrams/runtimeparameters.hpp`**
    - Score: 271.9
    - Total lines: 1082
    - Complex function lines: 430
    - Stream implementation lines: 1
    - Printer implementation lines: 14

 3. **`kongsbergall/filedatainterfaces/kongsbergallconfigurationdatainterfaceperfile.hpp`**
    - Score: 250.7
    - Total lines: 602
    - Complex function lines: 305
    - Printer implementation lines: 45

 4. **`filetemplates/datatypes/calibration/watercolumncalibration.hpp`**
    - Score: 213.6
    - Total lines: 414
    - Complex function lines: 345
    - Stream implementation lines: 1
    - Printer implementation lines: 19

 5. **`filetemplates/datatypes/i_pingwatercolumn.hpp`**
    - Score: 206.1
    - Total lines: 864
    - Complex function lines: 276
    - Printer implementation lines: 19

 6. **`simradraw/filedatatypes/calibration/simradrawwatercolumncalibration.hpp`**
    - Score: 175.9
    - Total lines: 321
    - Complex function lines: 279
    - Stream implementation lines: 1
    - Printer implementation lines: 17

 7. **`filetemplates/datacontainers/datagramcontainer.hpp`**
    - Score: 162.0
    - Total lines: 363
    - Complex function lines: 166
    - Stream implementation lines: 1
    - Printer implementation lines: 35

 8. **`kongsbergall/datagrams/seabedimagedata.hpp`**
    - Score: 161.2
    - Total lines: 324
    - Complex function lines: 140
    - Stream implementation lines: 4
    - Printer implementation lines: 37

 9. **`filetemplates/datacontainers/pingcontainer.hpp`**
    - Score: 159.3
    - Total lines: 364
    - Complex function lines: 185
    - Printer implementation lines: 31

10. **`gsf/datagrams/gsfdatagram.hpp`**
    - Score: 156.5
    - Total lines: 236
    - Complex function lines: 140
    - Stream implementation lines: 3
    - Printer implementation lines: 39

11. **`kongsbergall/datagrams/kongsbergalldatagram.hpp`**
    - Score: 154.5
    - Total lines: 280
    - Complex function lines: 148
    - Stream implementation lines: 4
    - Printer implementation lines: 34

12. **`kongsbergall/kongsbergallfilehandler.hpp`**
    - Score: 153.0
    - Total lines: 483
    - Complex function lines: 223
    - Printer implementation lines: 18

13. **`simradraw/filedatainterfaces/simradrawconfigurationdatainterfaceperfile.hpp`**
    - Score: 150.2
    - Total lines: 256
    - Complex function lines: 144
    - Printer implementation lines: 38

14. **`pingtools/beamsampleselection.hpp`**
    - Score: 148.3
    - Total lines: 388
    - Complex function lines: 142
    - Stream implementation lines: 3
    - Printer implementation lines: 32

15. **`kongsbergall/datagrams/rawrangeandangle.hpp`**
    - Score: 148.2
    - Total lines: 350
    - Complex function lines: 143
    - Stream implementation lines: 4
    - Printer implementation lines: 30

16. **`filetemplates/i_inputfilehandler.hpp`**
    - Score: 146.2
    - Total lines: 469
    - Complex function lines: 227
    - Stream implementation lines: 1
    - Printer implementation lines: 11

17. **`kongsbergall/filedatatypes/kongsbergallpingfiledata.hpp`**
    - Score: 145.8
    - Total lines: 491
    - Complex function lines: 208
    - Stream implementation lines: 1
    - Printer implementation lines: 13

18. **`simradraw/filedatatypes/simradrawpingfiledata.hpp`**
    - Score: 143.0
    - Total lines: 385
    - Complex function lines: 174
    - Printer implementation lines: 23

19. **`kongsbergall/datagrams/substructures/extradetectionsextradetections.hpp`**
    - Score: 138.1
    - Total lines: 296
    - Complex function lines: 73
    - Printer implementation lines: 45

20. **`kongsbergall/filedatainterfaces/kongsbergallpingdatainterfaceperfile.hpp`**
    - Score: 137.3
    - Total lines: 422
    - Complex function lines: 217
    - Printer implementation lines: 13

21. **`kongsbergall/datagrams/xyzdatagram.hpp`**
    - Score: 134.1
    - Total lines: 299
    - Complex function lines: 121
    - Stream implementation lines: 4
    - Printer implementation lines: 29

22. **`kongsbergall/filedatatypes/kongsbergallpingwatercolumn.hpp`**
    - Score: 131.2
    - Total lines: 399
    - Complex function lines: 148
    - Printer implementation lines: 22

23. **`filetemplates/datatypes/calibration/amplitudecalibration.hpp`**
    - Score: 130.9
    - Total lines: 303
    - Complex function lines: 169
    - Stream implementation lines: 3
    - Printer implementation lines: 17

24. **`filetemplates/datainterfaces/i_filedatainterfaceperfile.hpp`**
    - Score: 129.5
    - Total lines: 328
    - Complex function lines: 127
    - Printer implementation lines: 30

25. **`simradraw/filedatainterfaces/simradrawpingdatainterfaceperfile.hpp`**
    - Score: 128.4
    - Total lines: 383
    - Complex function lines: 185
    - Stream implementation lines: 2
    - Printer implementation lines: 13

26. **`filetemplates/datatypes/i_pingcommon.hpp`**
    - Score: 128.1
    - Total lines: 516
    - Complex function lines: 189
    - Printer implementation lines: 12

27. **`kongsbergall/datagrams/soundspeedprofiledatagram.hpp`**
    - Score: 125.2
    - Total lines: 294
    - Complex function lines: 88
    - Stream implementation lines: 3
    - Printer implementation lines: 33

28. **`gsf/gsffilehandler.hpp`**
    - Score: 122.8
    - Total lines: 370
    - Complex function lines: 166
    - Printer implementation lines: 18

29. **`kongsbergall/datagrams/substructures/watercolumndatagrambeam.hpp`**
    - Score: 122.1
    - Total lines: 322
    - Complex function lines: 113
    - Stream implementation lines: 2
    - Printer implementation lines: 27

30. **`kongsbergall/datagrams/substructures/networkattitudevelocitydatagramattitude.hpp`**
    - Score: 121.5
    - Total lines: 177
    - Complex function lines: 139
    - Stream implementation lines: 2
    - Printer implementation lines: 24

31. **`kongsbergall/filedatainterfaces/kongsbergallnavigationdatainterfaceperfile.hpp`**
    - Score: 121.0
    - Total lines: 334
    - Complex function lines: 184
    - Printer implementation lines: 13

32. **`kongsbergall/filedatatypes/_sub/watercolumninformation.hpp`**
    - Score: 110.2
    - Total lines: 309
    - Complex function lines: 206
    - Stream implementation lines: 2

33. **`kongsbergall/datagrams/singlebeamechosounderdepth.hpp`**
    - Score: 109.7
    - Total lines: 218
    - Complex function lines: 66
    - Stream implementation lines: 4
    - Printer implementation lines: 31

34. **`filetemplates/datatypes/datagraminfo.hpp`**
    - Score: 107.0
    - Total lines: 253
    - Complex function lines: 131
    - Stream implementation lines: 6
    - Printer implementation lines: 12

35. **`filetemplates/datatypes/cache_structures/filepackagecache.hpp`**
    - Score: 104.6
    - Total lines: 278
    - Complex function lines: 122
    - Printer implementation lines: 19

36. **`kongsbergall/filedatatypes/_sub/systeminformation.hpp`**
    - Score: 104.4
    - Total lines: 367
    - Complex function lines: 186
    - Stream implementation lines: 4

37. **`kongsbergall/filedatatypes/calibration/kongsbergallwatercolumncalibration.hpp`**
    - Score: 104.2
    - Total lines: 245
    - Complex function lines: 126
    - Stream implementation lines: 2
    - Printer implementation lines: 16

38. **`gsf/datagrams/headerdatagram.hpp`**
    - Score: 103.3
    - Total lines: 201
    - Complex function lines: 63
    - Stream implementation lines: 4
    - Printer implementation lines: 29

39. **`kongsbergall/datagrams/qualityfactordatagram.hpp`**
    - Score: 101.7
    - Total lines: 225
    - Complex function lines: 85
    - Stream implementation lines: 4
    - Printer implementation lines: 23

40. **`filetemplates/datainterfaces/i_datagraminterface.hpp`**
    - Score: 101.2
    - Total lines: 232
    - Complex function lines: 96
    - Printer implementation lines: 24

41. **`simradraw/datagrams/xml_datagrams/xml_parameter_channel.hpp`**
    - Score: 100.0
    - Total lines: 171
    - Complex function lines: 75
    - Stream implementation lines: 2
    - Printer implementation lines: 28

42. **`simradraw/simradrawfilehandler.hpp`**
    - Score: 99.9
    - Total lines: 339
    - Complex function lines: 129
    - Stream implementation lines: 1
    - Printer implementation lines: 14

43. **`filetemplates/datatypes/i_pingbottom.hpp`**
    - Score: 98.9
    - Total lines: 346
    - Complex function lines: 106
    - Printer implementation lines: 19

44. **`kongsbergall/datagrams/substructures/xyzdatagrambeam.hpp`**
    - Score: 94.4
    - Total lines: 200
    - Complex function lines: 59
    - Printer implementation lines: 30

45. **`kongsbergall/datagrams/substructures/attitudedatagramattitude.hpp`**
    - Score: 91.5
    - Total lines: 137
    - Complex function lines: 99
    - Printer implementation lines: 21

46. **`simradraw/filedatatypes/calibration/functions.hpp`**
    - Score: 89.5
    - Total lines: 357
    - Complex function lines: 172

47. **`filetemplates/datainterfaces/i_filedatainterface.hpp`**
    - Score: 86.7
    - Total lines: 271
    - Complex function lines: 85
    - Printer implementation lines: 18

48. **`kongsbergall/datagrams/substructures/seabedimagedatabeam.hpp`**
    - Score: 86.0
    - Total lines: 138
    - Complex function lines: 100
    - Printer implementation lines: 18

49. **`filetemplates/datainterfaces/i_navigationdatainterface.hpp`**
    - Score: 85.1
    - Total lines: 374
    - Complex function lines: 90
    - Printer implementation lines: 13

50. **`kongsbergall/datagrams/substructures/rawrangeandangletransmitsector.hpp`**
    - Score: 83.5
    - Total lines: 169
    - Complex function lines: 43
    - Printer implementation lines: 29

51. **`simradraw/filedatatypes/simradrawpingwatercolumn.hpp`**
    - Score: 82.6
    - Total lines: 241
    - Complex function lines: 60
    - Printer implementation lines: 22

52. **`kongsbergall/datagrams/surfacesoundspeeddatagram.hpp`**
    - Score: 79.6
    - Total lines: 233
    - Complex function lines: 55
    - Stream implementation lines: 3
    - Printer implementation lines: 19

53. **`kongsbergall/datagrams/depthorheightdatagram.hpp`**
    - Score: 79.1
    - Total lines: 191
    - Complex function lines: 60
    - Stream implementation lines: 4
    - Printer implementation lines: 18

54. **`kongsbergall/datagrams/headingdatagram.hpp`**
    - Score: 79.0
    - Total lines: 225
    - Complex function lines: 55
    - Stream implementation lines: 3
    - Printer implementation lines: 19

55. **`pingtools/beamselection.hpp`**
    - Score: 78.9
    - Total lines: 136
    - Complex function lines: 61
    - Stream implementation lines: 1
    - Printer implementation lines: 23

56. **`kongsbergall/datagrams/extraparameters.hpp`**
    - Score: 78.3
    - Total lines: 195
    - Complex function lines: 68
    - Stream implementation lines: 4
    - Printer implementation lines: 16

57. **`simradraw/filedatatypes/sub/transceiverinformation.hpp`**
    - Score: 76.5
    - Total lines: 117
    - Complex function lines: 65
    - Stream implementation lines: 1
    - Printer implementation lines: 21

58. **`kongsbergall/datagrams/substructures/sampleamplitudesstructure.hpp`**
    - Score: 76.2
    - Total lines: 233
    - Complex function lines: 88
    - Stream implementation lines: 2
    - Printer implementation lines: 12

59. **`simradraw/datagrams/RAW3.hpp`**
    - Score: 75.5
    - Total lines: 198
    - Complex function lines: 151

60. **`simradraw/filedatatypes/simradrawping.hpp`**
    - Score: 74.2
    - Total lines: 198
    - Complex function lines: 78
    - Printer implementation lines: 16

61. **`kongsbergall/datagrams/substructures/rawrangeandanglebeam.hpp`**
    - Score: 73.2
    - Total lines: 188
    - Complex function lines: 27
    - Printer implementation lines: 27

62. **`filetemplates/datatypes/i_ping.hpp`**
    - Score: 70.2
    - Total lines: 297
    - Complex function lines: 70
    - Printer implementation lines: 12

63. **`kongsbergall/datagrams/attitudedatagram.hpp`**
    - Score: 69.5
    - Total lines: 178
    - Complex function lines: 139

64. **`simradraw/filedatainterfaces/simradrawnavigationdatainterfaceperfile.hpp`**
    - Score: 68.5
    - Total lines: 164
    - Complex function lines: 90
    - Printer implementation lines: 11

65. **`kongsbergall/filedatatypes/kongsbergallpingbottom.hpp`**
    - Score: 67.9
    - Total lines: 214
    - Complex function lines: 45
    - Printer implementation lines: 19

66. **`kongsbergall/datagrams/kongsbergallunknown.hpp`**
    - Score: 61.7
    - Total lines: 148
    - Complex function lines: 49
    - Stream implementation lines: 4
    - Printer implementation lines: 13

67. **`kongsbergall/datagrams/substructures/extradetectionsdetectionclasses.hpp`**
    - Score: 61.1
    - Total lines: 118
    - Complex function lines: 38
    - Printer implementation lines: 20

68. **`simradraw/datagrams/xml_datagrams/xml_environment.hpp`**
    - Score: 60.2
    - Total lines: 106
    - Complex function lines: 36
    - Stream implementation lines: 1
    - Printer implementation lines: 20

69. **`filetemplates/datainterfaces/i_configurationdatainterface.hpp`**
    - Score: 57.8
    - Total lines: 147
    - Complex function lines: 52
    - Printer implementation lines: 15

70. **`filetemplates/datainterfaces/i_pingdatainterface.hpp`**
    - Score: 57.6
    - Total lines: 233
    - Complex function lines: 53
    - Printer implementation lines: 12

71. **`kongsbergall/filedatatypes/kongsbergallping.hpp`**
    - Score: 56.6
    - Total lines: 138
    - Complex function lines: 37
    - Printer implementation lines: 18

72. **`gsf/datagrams/gsfunknown.hpp`**
    - Score: 54.5
    - Total lines: 133
    - Complex function lines: 39
    - Stream implementation lines: 4
    - Printer implementation lines: 12

73. **`filetemplates/datatypes/filecache.hpp`**
    - Score: 52.2
    - Total lines: 321
    - Complex function lines: 92
    - Stream implementation lines: 2

74. **`simradraw/filedatatypes/simradrawpingbottom.hpp`**
    - Score: 51.9
    - Total lines: 151
    - Complex function lines: 19
    - Printer implementation lines: 19

75. **`filetemplates/datatypes/cache_structures/filepackageindex.hpp`**
    - Score: 51.5
    - Total lines: 133
    - Complex function lines: 40
    - Stream implementation lines: 3
    - Printer implementation lines: 12

76. **`kongsbergall/datagrams/substructures/watercolumndatagramtransmitsector.hpp`**
    - Score: 47.0
    - Total lines: 110
    - Complex function lines: 18
    - Printer implementation lines: 18

77. **`filetemplates/datatypes/calibration/multisectorwatercolumncalibration.hpp`**
    - Score: 45.3
    - Total lines: 298
    - Complex function lines: 14
    - Stream implementation lines: 2
    - Printer implementation lines: 10

78. **`pingtools/readsamplerange.hpp`**
    - Score: 45.3
    - Total lines: 127
    - Complex function lines: 15
    - Stream implementation lines: 2
    - Printer implementation lines: 15

79. **`filetemplates/datainterfaces/i_environmentdatainterface.hpp`**
    - Score: 43.2
    - Total lines: 130
    - Complex function lines: 38
    - Printer implementation lines: 11

80. **`simradraw/datagrams/XML0.hpp`**
    - Score: 43.0
    - Total lines: 134
    - Complex function lines: 86

81. **`kongsbergall/filedatainterfaces/kongsbergalldatagramdatainterfaceperfile.hpp`**
    - Score: 41.5
    - Total lines: 76
    - Complex function lines: 39
    - Printer implementation lines: 11

82. **`kongsbergall/filedatainterfaces/kongsbergallotherfiledatainterfaceperfile.hpp`**
    - Score: 41.5
    - Total lines: 76
    - Complex function lines: 39
    - Printer implementation lines: 11

83. **`simradraw/filedatainterfaces/simradrawdatagramdatainterfaceperfile.hpp`**
    - Score: 41.5
    - Total lines: 74
    - Complex function lines: 39
    - Printer implementation lines: 11

84. **`simradraw/filedatainterfaces/simradrawotherfiledatainterfaceperfile.hpp`**
    - Score: 41.5
    - Total lines: 76
    - Complex function lines: 39
    - Printer implementation lines: 11

85. **`kongsbergall/filedatainterfaces/kongsbergallannotationdatainterfaceperfile.hpp`**
    - Score: 41.0
    - Total lines: 75
    - Complex function lines: 38
    - Printer implementation lines: 11

86. **`simradraw/filedatainterfaces/simradrawannotationdatainterfaceperfile.hpp`**
    - Score: 41.0
    - Total lines: 70
    - Complex function lines: 38
    - Printer implementation lines: 11

87. **`kongsbergall/datagrams.hpp`**
    - Score: 38.3
    - Total lines: 183
    - Complex function lines: 57
    - Stream implementation lines: 4

88. **`kongsbergall/types.hpp`**
    - Score: 36.1
    - Total lines: 155
    - Complex function lines: 71

89. **`filetemplates/datainterfaces/i_configurationdatainterfaceperfile.hpp`**
    - Score: 34.8
    - Total lines: 135
    - Complex function lines: 20
    - Printer implementation lines: 10

90. **`simradraw/datagrams/NME0.hpp`**
    - Score: 32.0
    - Total lines: 99
    - Complex function lines: 64

91. **`kongsbergall/kongsbergallamplitudeconverter.hpp`**
    - Score: 31.4
    - Total lines: 181
    - Complex function lines: 51

92. **`filetemplates/internal/inputfilemanager.hpp`**
    - Score: 31.2
    - Total lines: 172
    - Complex function lines: 57

93. **`simradraw/datagrams/FIL1.hpp`**
    - Score: 31.0
    - Total lines: 103
    - Complex function lines: 62

94. **`kongsbergall/filedatainterfaces/kongsbergallannotationdatainterface.hpp`**
    - Score: 30.0
    - Total lines: 70
    - Complex function lines: 32
    - Printer implementation lines: 7

95. **`kongsbergall/filedatainterfaces/kongsbergalldatagramdatainterface.hpp`**
    - Score: 30.0
    - Total lines: 73
    - Complex function lines: 32
    - Printer implementation lines: 7

96. **`kongsbergall/filedatainterfaces/kongsbergallotherfiledatainterface.hpp`**
    - Score: 30.0
    - Total lines: 73
    - Complex function lines: 32
    - Printer implementation lines: 7

97. **`simradraw/filedatainterfaces/simradrawdatagramdatainterface.hpp`**
    - Score: 30.0
    - Total lines: 73
    - Complex function lines: 32
    - Printer implementation lines: 7

98. **`simradraw/filedatainterfaces/simradrawotherfiledatainterface.hpp`**
    - Score: 30.0
    - Total lines: 70
    - Complex function lines: 32
    - Printer implementation lines: 7

99. **`simradraw/datagrams/MRU0.hpp`**
    - Score: 29.5
    - Total lines: 92
    - Complex function lines: 59

100. **`simradraw/filedatainterfaces/simradrawannotationdatainterface.hpp`**
    - Score: 29.5
    - Total lines: 69
    - Complex function lines: 31
    - Printer implementation lines: 7

101. **`filetemplates/datainterfaces/i_annotationdatainterface.hpp`**
    - Score: 29.4
    - Total lines: 68
    - Complex function lines: 14
    - Printer implementation lines: 11

102. **`kongsbergall/filedatainterfaces/kongsbergallenvironmentdatainterfaceperfile.hpp`**
    - Score: 29.0
    - Total lines: 78
    - Complex function lines: 11
    - Printer implementation lines: 11

103. **`simradraw/filedatainterfaces/simradrawenvironmentdatainterfaceperfile.hpp`**
    - Score: 29.0
    - Total lines: 79
    - Complex function lines: 11
    - Printer implementation lines: 11

104. **`filetemplates/datainterfaces/i_pingdatainterfaceperfile.hpp`**
    - Score: 27.5
    - Total lines: 146
    - Printer implementation lines: 10

105. **`simradraw/datagrams/xml_datagrams/xml_configuration_sensor_telegram.hpp`**
    - Score: 27.5
    - Total lines: 89
    - Complex function lines: 51
    - Stream implementation lines: 1

106. **`filetemplates/datainterfaces/i_annotationdatainterfaceperfile.hpp`**
    - Score: 26.9
    - Total lines: 63
    - Complex function lines: 13
    - Printer implementation lines: 10

107. **`simradraw/datagrams/TAG0.hpp`**
    - Score: 26.5
    - Total lines: 88
    - Complex function lines: 53

108. **`filetemplates/datainterfaces/i_environmentdatainterfaceperfile.hpp`**
    - Score: 25.0
    - Total lines: 114
    - Printer implementation lines: 10

109. **`filetemplates/datainterfaces/i_navigationdatainterfaceperfile.hpp`**
    - Score: 24.2
    - Total lines: 104
    - Printer implementation lines: 10

110. **`simradraw/datagrams/xml_datagrams/xml_configuration_sensor_telegramvalue.hpp`**
    - Score: 21.5
    - Total lines: 76
    - Complex function lines: 43

111. **`filetemplates/datatypes/cache_structures/packagecache.hpp`**
    - Score: 21.4
    - Total lines: 141
    - Complex function lines: 22
    - Stream implementation lines: 3

112. **`simradraw/datagrams.hpp`**
    - Score: 20.8
    - Total lines: 114
    - Complex function lines: 22
    - Stream implementation lines: 4

113. **`kongsbergall/filedatainterfaces/kongsbergallnavigationdatainterface.hpp`**
    - Score: 20.5
    - Total lines: 65
    - Complex function lines: 12
    - Printer implementation lines: 7

## Medium Priority Files (Score 10-20) - 18 files

114. `simradraw/filedatatypes/simradrawpingcommon.hpp` (Score: 19.8, 91 lines)
115. `filetemplates/datatypes/cache_structures/structpackage.hpp` (Score: 19.6, 129 lines)
116. `simradraw/filedatainterfaces/simradrawdatagraminterface.hpp` (Score: 19.4, 97 lines)
117. `simradraw/datagrams/simradrawdatagram.hpp` (Score: 19.3, 129 lines)
118. `gsf/datagrams.hpp` (Score: 16.8, 101 lines)
119. `simradraw/filedatainterfaces/simradrawnavigationdatainterface.hpp` (Score: 16.8, 79 lines)
120. `kongsbergall/filedatainterfaces/kongsbergallenvironmentdatainterface.hpp` (Score: 15.5, 63 lines)
121. `kongsbergall/filedatainterfaces/kongsbergallpingdatainterface.hpp` (Score: 15.5, 63 lines)
122. `simradraw/filedatainterfaces/simradrawenvironmentdatainterface.hpp` (Score: 15.5, 64 lines)
123. `simradraw/filedatainterfaces/simradrawpingdatainterface.hpp` (Score: 15.5, 64 lines)
124. `kongsbergall/filedatainterfaces/kongsbergallconfigurationdatainterface.hpp` (Score: 15.4, 61 lines)
125. `simradraw/filedatainterfaces/simradrawconfigurationdatainterface.hpp` (Score: 15.4, 61 lines)
126. `simradraw/datagrams/xml_datagrams/xml_node.hpp` (Score: 15.0, 81 lines)
127. `kongsbergall/filedatatypes/_sub/_wciinfos.hpp` (Score: 14.8, 98 lines)
128. `kongsbergall/filedatatypes/kongsbergallpingcommon.hpp` (Score: 14.0, 80 lines)
129. `filetemplates/datatypes/i_pingfiledata.hpp` (Score: 13.5, 171 lines)
130. `simradraw/datagrams/raw3datatypes/raw3datacomplexfloat32.hpp` (Score: 11.4, 97 lines)
131. `kongsbergall/datagrams/clockdatagram.hpp` (Score: 10.8, 130 lines)

## Lower Priority Files (Score 5-10) - 8 files

132. `simradraw/datagrams/xml_datagrams/xml_configuration_sensor.hpp` (Score: 9.6, 102 lines)
133. `simradraw/datagrams/raw3datatypes/t_raw3datatype.hpp` (Score: 9.0, 64 lines)
134. `kongsbergall/datagrams/substructures/flag_detection_information.hpp` (Score: 8.7, 88 lines)
135. `filetemplates/datatypes/cache_structures/fileinfos.hpp` (Score: 8.5, 76 lines)
136. `kongsbergall/filedatainterfaces/kongsbergalldatagraminterface.hpp` (Score: 8.4, 78 lines)
137. `kongsbergall/filedatatypes/_sub/_sysinfos.hpp` (Score: 8.0, 66 lines)
138. `simradraw/types.hpp` (Score: 7.7, 121 lines)
139. `simradraw/datagrams/xml_datagrams/helper.hpp` (Score: 6.9, 76 lines)

## Summary Statistics

- **Total header files analyzed**: 172
- **Files already processed in PRs #25/#26**: 7
- **Remaining candidates identified**: 139
- **High priority files**: 113
- **Medium priority files**: 18
- **Lower priority files**: 8

## Recommended Approach for Future PRs

1. **Focus on High Priority files first** - these have the most impact
2. **Start with `__printer__` function implementations** - typically 20-80 lines each
3. **Move `to_stream` and `from_stream` implementations** - often 10-50 lines each
4. **Move complex business logic functions** - varies widely in size
5. **Keep simple getters and template implementations in headers**
6. **Process 3-5 files per PR** to keep changes manageable

## Pattern from Previous PRs

PR #25 and #26 successfully moved **~912 lines** from 8 header files to .cpp files:
- **PR #25**: 3 files, ~415 lines moved
- **PR #26**: 5 files, ~497 lines moved

This same pattern can be applied to the remaining candidates above.
