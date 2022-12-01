// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_filedatacontainers {

namespace py = pybind11;

// -- submodule declarations --
void init_c_simradpingcontainer(py::module& m);     // c_simrad_specialized_types.cpp
void init_c_simraddatagramcontainer(py::module& m); // c_simraddatagramcontainer.cpp

// -- create submodule --
void init_m_SimradFileDataContainers(pybind11::module& m)
{
    auto subm =
        m.def_submodule("filedatacontainers", "Simrad EK60 and EK80 file data container classes");
    // simrad classes
    init_c_simraddatagramcontainer(subm);
    init_c_simradpingcontainer(subm);
}

}
}
}
}
}
