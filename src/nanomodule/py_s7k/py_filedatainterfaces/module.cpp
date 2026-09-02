// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatainterfaces {

namespace nb = nanobind;

// -- submodule declarations --
void init_c_s7kdatagraminterface(nanobind::module_& m); // c_s7kdatagraminterface.cpp

// -- create submodule --
void init_m_s7kfiledatainterfaces(nanobind::module_& m)
{
    auto subm = m.def_submodule("filedatainterfaces",
                                "Teledyne RESON .s7k (7k) file data interface classes");

    init_c_s7kdatagraminterface(subm);
}

}
}
}
}
}
