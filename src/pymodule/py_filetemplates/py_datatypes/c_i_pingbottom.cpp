// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_pingbottom.hpp"
//

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {

#define DOC_I_PingBottom(ARG)                                                                      \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingBottom, ARG)

void init_c_i_pingbottom(pybind11::module& m)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;

    auto cls =
        py::class_<I_PingBottom, std::shared_ptr<I_PingBottom>>(
            m,
            "I_PingBottom",
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingBottom))

            // ----- features -----
            .def("has_xyz", &I_PingBottom::has_xyz, DOC_I_PingBottom(has_xyz))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(I_PingBottom)
        // default printing functions
        // cls __PYCLASS_DEFAULT_PRINTING__(I_PingBottom);
        ;
}

}
}
}
}
}