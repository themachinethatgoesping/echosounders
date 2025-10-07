// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatacontainers {

namespace nb = nanobind;

// -- submodule declarations --
void init_c_kongsbergalldatagramcontainer(nanobind::module_& m); // c_kongsbergalldatagramcontainer.cpp
void init_c_kongsbergallpingcontainer(nanobind::module_& m);     // c_kongsbergall_specialized_types.cpp

// -- create submodule --
void init_m_kongsbergallfiledatacontainers(nanobind::module_& m)
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
