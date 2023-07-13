// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>
#include "module.hpp"

namespace py = pybind11;

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_pingtools {

// -- submodule declarations --
void init_c_pingsampleselector(pybind11::module& m); // c_pingsampleselector.cpp

// -- create submodule --
void init_m_pingtools(py::module& m)
{
    // module description
    auto subm = m.def_submodule("pingtools", "Tools for working with ping objects.");

    // pingtool classes classes
    init_c_pingsampleselector(subm);
}

}
}
}
}