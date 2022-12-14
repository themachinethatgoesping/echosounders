// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include "../../docstrings.hpp"
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "module.hpp"
#include "py_substructures/module.hpp"

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {

// -- submodule declarations --
void init_c_em3000datagram(pybind11::module& m);   // c_em3000datagram.cpp
void init_c_em3000unknown(pybind11::module& m);    // c_em3000unknown.cpp
void init_c_xyzdatagram(pybind11::module& m);      // c_xyzdatagram.cpp
void init_c_extradetections(pybind11::module& m);  // c_extradetections.cpp
void init_c_rawrangeandangle(pybind11::module& m); // c_rawrangeandangle.cpp

// -- create submodule --
void init_m_EM3000Datagrams(pybind11::module& m)
{
    // module description
    auto subm = m.def_submodule("datagrams", "Kongsberg EM3000 (.all/.wcd) EK80 datagram classes");

    // init submodules
    py_substructures::init_m_EM3000DatagramsSubstructures(subm);

    // em3000 classes
    init_c_em3000datagram(subm);
    init_c_em3000unknown(subm);
    init_c_xyzdatagram(subm);
    init_c_extradetections(subm);
    init_c_rawrangeandangle(subm);
}

}
}
}
}
}
