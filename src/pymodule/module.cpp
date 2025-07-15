// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>

#define FORCE_IMPORT_ARRAY // this is needed for xtensor-python but must only be included once

#include <xtensor-python/pytensor.hpp> // Numpy bindings

// larger submodules
#include "py_kongsbergall/module.hpp"
#include "py_filetemplates/module.hpp"
#include "py_pingtools/module.hpp"
#include "py_simradraw/module.hpp"

// declare modules
// void init_m_navtools(pybind11::module& m);                     // m_navtools.cpp
namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {

PYBIND11_MODULE(MODULE_NAME, m)
{
    xt::import_numpy(); // import numpy for xtensor (otherwise there will be weird segfaults)

    pybind11::add_ostream_redirect(m, "ostream_redirect");

    m.doc() =
        "Python module to read, write and process single- and multibeam echosounder data formats";
    m.attr("__version__") = MODULE_VERSION;

    // init_m_navtools(m);
    py_filetemplates::init_m_filetemplates(m);
    py_pingtools::init_m_pingtools(m);
    py_simradraw::init_m_simradraw(m);
    py_kongsbergall::init_m_kongsbergall(m);
}

}
}
}