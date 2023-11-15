// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatacontainers {

namespace py = pybind11;

// -- submodule declarations --
void init_c_simradrawpingcontainer(py::module& m);     // c_simradraw_specialized_types.cpp
void init_c_simradrawdatagramcontainer(py::module& m); // c_simradrawdatagramcontainer.cpp

// -- create submodule --
void init_m_simradrawfiledatacontainers(pybind11::module& m)
{
    auto subm =
        m.def_submodule("filedatacontainers", "SimradRaw EK60 and EK80 file data container classes");
    // simradraw classes
    init_c_simradrawdatagramcontainer(subm);
    init_c_simradrawpingcontainer(subm);
}

}
}
}
}
}
