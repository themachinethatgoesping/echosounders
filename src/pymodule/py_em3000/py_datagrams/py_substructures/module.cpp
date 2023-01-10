// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include "../../../docstrings.hpp"
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "module.hpp"

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {
namespace py_substructures {

// -- submodule declarations --
void init_c_xyzdatagrambeam(pybind11::module& m);    // c_xyzdatagrambeam.cpp
void init_enum_detectiontype(pybind11::module& m);  // enum_detectiontype.cpp

// -- create submodule --
void init_m_EM3000DatagramsSubstructures(pybind11::module& m)
{
    // module description
    auto subm = m.def_submodule("substructures", "Kongsberg EM3000 datagram substructures. These are substuctures of existing datagrams (repeated cycles, e.g. beams)");

    // init submodules

    // em3000 substructures
    init_enum_detectiontype(subm);
    init_c_xyzdatagrambeam(subm);
}

}
}
}
}
}
}
