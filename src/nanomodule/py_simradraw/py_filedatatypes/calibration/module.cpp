// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {
namespace py_calibration {

namespace nb = nanobind;

// -- submodule declarations --
namespace py_functions {
void init_simradrawwatercolumncalibration_functions(nanobind::module_& m);
}

void init_c_simradrawwatercolumncalibration(
    nanobind::module_& m); // sub/c_simradrawwatercolumncalibration.cpp

// -- create submodule --
void init_m_simradrawfiledatatypescalibration(nanobind::module_& m)
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
