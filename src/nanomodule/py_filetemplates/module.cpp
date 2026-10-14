// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "module.hpp"
#include <nanobind/nanobind.h>

namespace nb = nanobind;

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {

// -- submodule declarations --
namespace py_datatypes {
void init_c_filecache(nb::module_& m);         // py_datatypes/c_filecache.cpp
namespace py_cache_structures {
void init_c_filepackagecache(
    nb::module_& m); // py_datatypes/py_cache_structures/init_c_filepackagecache.cpp
}
}

// -- create submodule --
void init_m_filetemplates(nb::module_& m)
{
    // module description
    auto subm =
        m.def_submodule("filetemplates", "Trampoline classes for abstract file template classes");

    // the ping interfaces and calibration classes now live in
    // themachinethatgoesping.pingprocessing.datatypes (imported before this module)
    py_datatypes::py_cache_structures::init_c_filepackagecache(subm);
    py_datatypes::init_c_filecache(subm);
}

}
}
}
}