// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
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
void init_c_i_pingcommon(pybind11::module& m);      // py_datatypes/i_pingcommon.cpp
void init_c_i_pingfiledata(pybind11::module& m);    // py_datatypes/i_pingfiledata.cpp
void init_c_i_ping(pybind11::module& m);            // py_datatypes/i_ping.cpp
void init_c_i_pingbottom(pybind11::module& m);      // py_datatypes/i_pingbottom.cpp
void init_c_i_pingwatercolumn(pybind11::module& m); // py_datatypes/i_pingwatercolumn.cpp
void init_c_filecache(pybind11::module& m);         // py_datatypes/c_filecache.cpp
namespace py_cache_structures {
void init_c_filepackagecache(
    pybind11::module& m); // py_datatypes/py_cache_structures/init_c_filepackagecache.cpp
}
namespace py_calibration {
void init_c_amplitudecalibration(
    pybind11::module& m); // py_datatypes/py_calibration/init_c_amplitudecalibration.cpp
void init_c_watercolumncalibration(
    pybind11::module& m); // py_datatypes/py_calibration/init_c_watercolumncalibration.cpp
void init_c_multisectorwatercolumncalibration(
    pybind11::module&
        m); // py_datatypes/py_calibration/init_c_multisectorwatercolumncalibration.cpp
}
}

// -- create submodule --
void init_m_filetemplates(py::module& m)
{
    // module description
    auto subm =
        m.def_submodule("filetemplates", "Trampoline classes for abstract file template classes");

    // pingtool classes classes
    py_datatypes::py_calibration::init_c_amplitudecalibration(subm);
    py_datatypes::py_calibration::init_c_watercolumncalibration(subm);
    py_datatypes::py_calibration::init_c_multisectorwatercolumncalibration(subm);
    py_datatypes::init_c_i_pingcommon(subm);
    py_datatypes::init_c_i_pingfiledata(subm);
    py_datatypes::init_c_i_pingbottom(subm);
    py_datatypes::init_c_i_pingwatercolumn(subm);
    py_datatypes::init_c_i_ping(subm);
    py_datatypes::py_cache_structures::init_c_filepackagecache(subm);
    py_datatypes::init_c_filecache(subm);
}

}
}
}
}