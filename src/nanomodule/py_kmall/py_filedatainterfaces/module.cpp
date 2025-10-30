// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_filedatainterfaces {

namespace nb = nanobind;

// -- submodule declarations --
void init_c_KMALLDatagramInterface(nanobind::module_& m); // c_kmalldatagraminterface.cpp


// -- create submodule --
void init_m_kmallfiledatainterfaces(nanobind::module_& m)
{
    auto subm = m.def_submodule("filedatainterfaces",
                                "KMALL (kongsberg .kmall/.kmwcd) file data interface classes");

    init_c_KMALLDatagramInterface(subm);
}

}
}
}
}
}
