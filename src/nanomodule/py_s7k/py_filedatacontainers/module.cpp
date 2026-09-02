// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatacontainers {

namespace nb = nanobind;

// -- submodule declarations --
void init_c_s7kdatagramcontainer(nanobind::module_& m); // c_s7kdatagramcontainer.cpp

// -- create submodule --
void init_m_s7kfiledatacontainers(nanobind::module_& m)
{
    auto subm = m.def_submodule("filedatacontainers",
                                "Teledyne RESON .s7k (7k) file data container classes");
    // s7k classes
    init_c_s7kdatagramcontainer(subm);
}

}
}
}
}
}
