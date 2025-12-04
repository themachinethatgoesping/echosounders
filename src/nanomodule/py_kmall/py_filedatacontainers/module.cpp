// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_filedatacontainers {

namespace nb = nanobind;

// -- submodule declarations --
void init_c_kmalldatagramcontainer(nanobind::module_& m); // c_kmalldatagramcontainer.cpp
void init_c_kmallpingcontainer(nanobind::module_& m); // c_kmallpingcontainer.cpp

// -- create submodule --
void init_m_kmallfiledatacontainers(nanobind::module_& m)
{
    auto subm = m.def_submodule("filedatacontainers",
                                "KMALL (kongsberg .kmall / .kmwcd) file data container classes");
    // kmall classes
    init_c_kmalldatagramcontainer(subm);
    init_c_kmallpingcontainer(subm);
}

}
}
}
}
}
