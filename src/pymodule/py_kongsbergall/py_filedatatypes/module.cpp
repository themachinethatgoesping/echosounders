// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatatypes {

namespace py = pybind11;

// -- submodule declarations --

namespace py_calibration {
void init_c_kongsbergallwatercolumncalibration(
    pybind11::module& m); // c_kongsbergallwatercolumncalibration.cpp
}

void init_c_kongsbergallfilepackageindex(pybind11::module& m); // c_kongsbergallfilepackageindex.cpp
void init_c_kongsbergallPingFileData(pybind11::module& m);     // c_kongsbergallpingfiledata.cpp
void init_c_kongsbergallpingcommon(pybind11::module& m);       // c_kongsbergallpingbottom.cpp
void init_c_kongsbergallpingbottom(pybind11::module& m);       // c_kongsbergallpingbottom.cpp
void init_c_kongsbergallpingwatercolumn(pybind11::module& m);  // c_kongsbergallpingwatercolumn.cpp
void init_c_kongsbergallping(pybind11::module& m);             // c_kongsbergallping.cpp

// -- create submodule --
void init_m_kongsbergallfiledatatypes(pybind11::module& m)
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
