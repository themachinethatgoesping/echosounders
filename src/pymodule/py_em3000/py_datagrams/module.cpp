// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include "../../docstrings.hpp"
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "module.hpp"

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {

// -- submodule declarations --
//void init_c_EM3000Datagram(pybind11::module& m); // c_EM3000Datagram.cpp

// -- create submodule --
void init_m_EM3000Datagrams(pybind11::module& m)
{
    // module description
    auto subm = m.def_submodule("datagrams", "Kongsberg EM3000 (.all/.wcd) EK80 datagram classes");

    // init submodules

    // em3000 classes
}

}
}
}
}
}
