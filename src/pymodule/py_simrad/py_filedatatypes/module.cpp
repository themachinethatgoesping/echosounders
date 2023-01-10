// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_filedatatypes {

namespace py = pybind11;

// -- submodule declarations --
void init_c_SimradPing(pybind11::module& m); // c_SimradPing.cpp

// -- create submodule --
void init_m_SimradFileDataTypes(pybind11::module& m)
{
    auto subm = m.def_submodule("filetypes", "Simrad EK60 and EK80 file data types");
    init_c_SimradPing(subm);
}

}
}
}
}
}
