// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {

namespace py = pybind11;

// -- submodule declarations --
void init_c_simradrawfileinfodata(pybind11::module& m); // c_simradrawfileinfodata.cpp
void init_c_simradrawping(pybind11::module& m);         // c_simradrawping.cpp
void init_c_simradrawpingrawdata(pybind11::module& m);  // c_simradrawpingrawdata.cpp

// -- create submodule --
void init_m_simradrawfiledatatypes(pybind11::module& m)
{
    auto subm = m.def_submodule("filetypes", "SimradRaw EK60 and EK80 file data types");
    init_c_simradrawfileinfodata(subm);
    init_c_simradrawpingrawdata(subm);
    init_c_simradrawping(subm);
}

}
}
}
}
}
