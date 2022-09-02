// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>

// larger submodules
#include "simrad/module.hpp"

// declare modules
//void init_m_navtools(pybind11::module& m);                     // m_navtools.cpp
namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {

PYBIND11_MODULE(MODULE_NAME, m)
{
    pybind11::add_ostream_redirect(m, "ostream_redirect");

    m.doc() = "Python module to read, write and process single- and multibeam echosounder data formats";
    m.attr("__version__") = MODULE_VERSION;

    //init_m_navtools(m);
    py_simrad::init_m_simrad(m);
}

}
}
}