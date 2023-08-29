// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_filedatatypes {

namespace py = pybind11;

// -- submodule declarations --
void init_c_em3000pingrawdata(pybind11::module& m);     // c_em3000pingrawdata.cpp
void init_c_em3000pingcommon(pybind11::module& m);      // c_em3000pingbottom.cpp
void init_c_em3000pingbottom(pybind11::module& m);      // c_em3000pingbottom.cpp
void init_c_em3000pingwatercolumn(pybind11::module& m); // c_em3000pingwatercolumn.cpp
void init_c_em3000ping(pybind11::module& m);            // c_em3000ping.cpp

// -- create submodule --
void init_m_em3000filedatatypes(pybind11::module& m)
{
    auto subm = m.def_submodule("filetypes", "EM3000 EK60 and EK80 file data types");
    init_c_em3000pingrawdata(subm);
    init_c_em3000pingcommon(subm);
    init_c_em3000pingbottom(subm);
    init_c_em3000pingwatercolumn(subm);
    init_c_em3000ping(subm);
}

}
}
}
}
}
