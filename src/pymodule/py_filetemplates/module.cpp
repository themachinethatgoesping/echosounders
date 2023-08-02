// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "module.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {

// -- submodule declarations --
namespace py_datatypes {
void init_trampoline_i_ping(pybind11::module& m); // py_datatypes/i_ping.cpp
}

// -- create submodule --
void init_m_filetemplates(py::module& m)
{
    // module description
    auto subm =
        m.def_submodule("filetemplates", "Trampoline classes for abstract file template classes");

    // pingtool classes classes
    py_datatypes::init_trampoline_i_ping(subm);
}

}
}
}
}