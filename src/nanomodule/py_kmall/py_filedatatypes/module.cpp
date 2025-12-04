// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_filedatatypes {

namespace nb = nanobind;

// -- submodule declarations --

namespace py_calibration {
void init_c_kmallwatercolumncalibration(
    nanobind::module_& m); // c_kmallwatercolumncalibration.cpp
}

void init_c_kmallfilepackageindex(nanobind::module_& m); // c_kmallfilepackageindex.cpp
void init_c_kmallPingFileData(nanobind::module_& m);     // c_kmallpingfiledata.cpp
void init_c_kmallpingcommon(nanobind::module_& m);       // c_kmallpingbottom.cpp
void init_c_kmallpingbottom(nanobind::module_& m);       // c_kmallpingbottom.cpp
void init_c_kmallpingwatercolumn(nanobind::module_& m);  // c_kmallpingwatercolumn.cpp
void init_c_kmallping(nanobind::module_& m);             // c_kmallping.cpp

// -- create submodule --
void init_m_kmallfiledatatypes(nanobind::module_& m)
{
    auto subm = m.def_submodule("filetypes", "KMALL EK60 and EK80 file data types");

    py_calibration::init_c_kmallwatercolumncalibration(subm);
    init_c_kmallfilepackageindex(subm);
    init_c_kmallPingFileData(subm);
    init_c_kmallpingcommon(subm);
    init_c_kmallpingbottom(subm);
    init_c_kmallpingwatercolumn(subm);
    init_c_kmallping(subm);
}

}
}
}
}
}
