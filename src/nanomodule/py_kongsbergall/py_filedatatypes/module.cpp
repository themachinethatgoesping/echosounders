// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatatypes {

namespace nb = nanobind;

// -- submodule declarations --

namespace py_calibration {
void init_c_kongsbergallwatercolumncalibration(
    nanobind::module_& m); // c_kongsbergallwatercolumncalibration.cpp
}

void init_c_kongsbergallfilepackageindex(nanobind::module_& m); // c_kongsbergallfilepackageindex.cpp
void init_c_kongsbergallPingFileData(nanobind::module_& m);     // c_kongsbergallpingfiledata.cpp
void init_c_kongsbergallpingcommon(nanobind::module_& m);       // c_kongsbergallpingbottom.cpp
void init_c_kongsbergallpingbottom(nanobind::module_& m);       // c_kongsbergallpingbottom.cpp
void init_c_kongsbergallpingwatercolumn(nanobind::module_& m);  // c_kongsbergallpingwatercolumn.cpp
void init_c_kongsbergallping(nanobind::module_& m);             // c_kongsbergallping.cpp

// -- create submodule --
void init_m_kongsbergallfiledatatypes(nanobind::module_& m)
{
    auto subm = m.def_submodule("filetypes", "KongsbergAll EK60 and EK80 file data types");

    py_calibration::init_c_kongsbergallwatercolumncalibration(subm);
    init_c_kongsbergallfilepackageindex(subm);
    init_c_kongsbergallPingFileData(subm);
    init_c_kongsbergallpingcommon(subm);
    init_c_kongsbergallpingbottom(subm);
    init_c_kongsbergallpingwatercolumn(subm);
    init_c_kongsbergallping(subm);
}

}
}
}
}
}
