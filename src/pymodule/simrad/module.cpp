// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/tools/pybind11_helpers/enumhelpers.hpp>

#include "../docstrings.hpp"
#include "module.hpp"

// datagram submodules
#include "datagrams/module.hpp"

namespace py = pybind11;

#include <pybind11/pybind11.h>

// -- submodule declarations --
void init_c_fileraw(pybind11::module& m); // c_fileraw.cpp

// -- create submodule --
void init_m_simrad(pybind11::module& m)
{
    // module description
    auto subm = m.def_submodule(
        "simrad", "Classes related to Simrad EK60 and EK80 data files");

    // // small classes
    // pybind11::enum_<t_extr_mode>(
    //     m_vectorinterpolators,
    //     "t_extr_mode",
    //     DOC(themachinethatgoesping, tools, vectorinterpolators, t_extr_mode))
    //     .value("extrapolate", t_extr_mode::extrapolate)
    //     .value("nearest", t_extr_mode::nearest)
    //     .value("fail", t_extr_mode::fail)
    //     .export_values()
    //     //pybind enum helpers
    //     __PYENUM_FROM_STRING__(t_extr_mode)
    //     //end
    //     ;
    //
    // py::implicitly_convertible<std::string, t_extr_mode>();

    // datagrams
    init_m_simrad_datagrams(subm);

    // simrad classes
    init_c_fileraw(subm);
}
