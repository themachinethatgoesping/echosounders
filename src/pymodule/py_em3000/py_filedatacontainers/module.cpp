// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_filedatacontainers {

namespace py = pybind11;

// -- submodule declarations --
// void init_c_em3000pingcontainer(py::module& m);     // c_em3000_specialized_types.cpp
void init_c_em3000datagramcontainer(py::module& m); // c_em3000datagramcontainer.cpp

// -- create submodule --
void init_m_EM3000FileDataContainers(pybind11::module& m)
{
    auto subm = m.def_submodule("filedatacontainers",
                                "EM3000 (kongsberg .all / .wcd) file data container classes");
    // em3000 classes
    init_c_em3000datagramcontainer(subm);
    // init_c_em3000pingcontainer(subm);
}

}
}
}
}
}
