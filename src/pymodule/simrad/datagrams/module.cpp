// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include "../../docstrings.hpp"
#include <themachinethatgoesping/tools/pybind11_helpers/enumhelpers.hpp>

#include "module.hpp"

namespace py = pybind11;

#include <pybind11/pybind11.h>

// -- submodule declarations --
void init_c_ek60_datagram(pybind11::module& m); // init_c_ek60_datagram.cpp

// -- create submodule --
void init_m_simrad_datagrams(pybind11::module& m)
{
    // module description
    auto subm = m.def_submodule("datagrams", "Simrad EK60 and EK80 datagram classes");

    // simrad classes
    init_c_ek60_datagram(subm);
}
