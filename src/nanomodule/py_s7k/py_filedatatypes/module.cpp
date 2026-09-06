// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatatypes {

namespace nb = nanobind;

// -- submodule declarations --
void init_c_s7kpingfiledata(nanobind::module_& m);    // c_s7kpingfiledata.cpp
void init_c_s7kpingcommon(nanobind::module_& m);      // c_s7kpingcommon.cpp
void init_c_s7kpingbottom(nanobind::module_& m);      // c_s7kpingbottom.cpp
void init_c_s7kpingwatercolumn(nanobind::module_& m); // c_s7kpingwatercolumn.cpp
void init_c_s7kping(nanobind::module_& m);            // c_s7kping.cpp

// -- create submodule --
void init_m_s7kfiledatatypes(nanobind::module_& m)
{
    auto subm = m.def_submodule("filedatatypes", "Teledyne RESON .s7k (7k) file data types");

    init_c_s7kpingfiledata(subm);
    init_c_s7kpingcommon(subm);
    init_c_s7kpingbottom(subm);
    init_c_s7kpingwatercolumn(subm);
    init_c_s7kping(subm);
}

}
}
}
}
}
