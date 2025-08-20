// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {
namespace py_calibration {

namespace py = pybind11;

// -- submodule declarations --
namespace py_functions {
void init_simradrawwatercolumncalibration_functions(pybind11::module& m);
}

void init_c_simradrawwatercolumncalibration(
    pybind11::module& m); // sub/c_simradrawwatercolumncalibration.cpp

// -- create submodule --
void init_m_simradrawfiledatatypescalibration(pybind11::module& m)
{
    auto subm = m.def_submodule("calibration", "SimradRaw EK60 and EK80 calibration structures and functions");

    py_functions::init_simradrawwatercolumncalibration_functions(subm);
    init_c_simradrawwatercolumncalibration(subm);
}

}
}
}
}
}
}
