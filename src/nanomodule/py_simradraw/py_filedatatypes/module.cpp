// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

#include "calibration/module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {

namespace nb = nanobind;

// -- submodule declarations --
namespace py_cache_structures {
void init_c_simradrawfilepackageindex(nanobind::module_& m); // c_simradrawfilepackageindex.cpp
}

namespace py_sub {
void init_c_transceiverinformation(nanobind::module_& m); // sub/c_transceiverinformation.cpp
}
namespace py_calibration {
namespace py_functions {
void init_simradrawwatercolumncalibration_functions(nanobind::module_& m);
}

void init_c_simradrawwatercolumncalibration(
    nanobind::module_& m); // sub/c_simradrawwatercolumncalibration.cpp
}

void init_c_simradrawpingcommon(nanobind::module_& m);      // c_simradrawpingcommon.cpp
void init_c_simradrawping(nanobind::module_& m);            // c_simradrawping.cpp
void init_c_simradrawpingfiledata(nanobind::module_& m);    // c_simradrawpingfiledata.cpp
void init_c_simradrawpingbottom(nanobind::module_& m);      // c_simradrawpingbottom.cpp
void init_c_simradrawpingwatercolumn(nanobind::module_& m); // c_simradrawpingwatercolumn.cpp

// -- create submodule --
void init_m_simradrawfiledatatypes(nanobind::module_& m)
{
    auto subm = m.def_submodule("filedatatypes", "SimradRaw EK60 and EK80 file data types");
    py_cache_structures::init_c_simradrawfilepackageindex(subm);
    py_sub::init_c_transceiverinformation(subm);

    // -- create submodule for calibration --
    py_calibration::init_m_simradrawfiledatatypescalibration(subm);

    init_c_simradrawpingfiledata(subm);
    init_c_simradrawpingcommon(subm);
    init_c_simradrawpingbottom(subm);
    init_c_simradrawpingwatercolumn(subm);
    init_c_simradrawping(subm);
}

}
}
}
}
}
