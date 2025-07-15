// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "module.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_pingtools {

// -- submodule declarations --
void init_c_readsamplerange(pybind11::module& m);     // substructures/c_readsamplerange.cpp
void init_c_beamselection(pybind11::module& m);       // substructures/c_beamselection.cpp
void init_c_beamsampleselection(pybind11::module& m); // substructures/c_beamsampleselection.cpp
void init_c_pingsampleselector(pybind11::module& m);  // c_pingsampleselector.cpp

// -- create submodule --
void init_m_pingtools(py::module& m)
{
    // module description
    auto subm = m.def_submodule("pingtools", "Tools for working with ping objects.");

    // pingtool classes classes
    init_c_readsamplerange(subm);
    init_c_beamselection(subm);
    init_c_beamsampleselection(subm);
    init_c_pingsampleselector(subm);
}

}
}
}
}