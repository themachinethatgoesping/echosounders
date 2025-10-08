// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatacontainers {

namespace nb = nanobind;

// -- submodule declarations --
void init_c_simradrawpingcontainer(nb::module_& m);     // c_simradraw_specialized_types.cpp
void init_c_simradrawdatagramcontainer(nb::module_& m); // c_simradrawdatagramcontainer.cpp

// -- create submodule --
void init_m_simradrawfiledatacontainers(nanobind::module_& m)
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
