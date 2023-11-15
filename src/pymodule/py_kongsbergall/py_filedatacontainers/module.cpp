// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatacontainers {

namespace py = pybind11;

// -- submodule declarations --
void init_c_kongsbergalldatagramcontainer(py::module& m); // c_kongsbergalldatagramcontainer.cpp
void init_c_kongsbergallpingcontainer(py::module& m);     // c_kongsbergall_specialized_types.cpp

// -- create submodule --
void init_m_kongsbergallfiledatacontainers(pybind11::module& m)
{
    auto subm = m.def_submodule("filedatacontainers",
                                "KongsbergAll (kongsberg .all / .wcd) file data container classes");
    // kongsbergall classes
    init_c_kongsbergalldatagramcontainer(subm);
    init_c_kongsbergallpingcontainer(subm);
}

}
}
}
}
}
