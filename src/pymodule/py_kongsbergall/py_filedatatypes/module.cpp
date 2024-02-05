// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
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
void init_c_kongsbergallfileinfodata(pybind11::module& m);    // c_kongsbergallfileinfodata.cpp
void init_c_kongsbergallPingFileData(pybind11::module& m);     // c_kongsbergallpingfiledata.cpp
void init_c_kongsbergallpingcommon(pybind11::module& m);      // c_kongsbergallpingbottom.cpp
void init_c_kongsbergallpingbottom(pybind11::module& m);      // c_kongsbergallpingbottom.cpp
void init_c_kongsbergallpingwatercolumn(pybind11::module& m); // c_kongsbergallpingwatercolumn.cpp
void init_c_kongsbergallping(pybind11::module& m);            // c_kongsbergallping.cpp

// -- create submodule --
void init_m_kongsbergallfiledatatypes(pybind11::module& m)
{
    auto subm = m.def_submodule("filetypes", "KongsbergAll EK60 and EK80 file data types");

    init_c_kongsbergallfileinfodata(subm);
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
