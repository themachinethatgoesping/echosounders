// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../docstrings.hpp"
#include "module.hpp"
#include <themachinethatgoesping/echosounders/simrad/datagrams/RAW3_datatypes/RAW3_datatypes.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py_raw3_datatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using namespace datagrams::RAW3_datatypes;

// --- helper defines ---
#define DOC_i_RAW3_Data(NAME)                                                                      \
    DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3_datatypes, i_RAW3_Data, NAME)

void init_c_i_raw3_data(pybind11::module& m)
{
    py::class_<i_RAW3_Data>(
        m,
        "i_RAW3_Data",
        DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3_datatypes, i_RAW3_Data))
        .def(py::init<std::string_view>(), DOC_i_RAW3_Data(i_RAW3_Data), py::arg("name"))
        .def("get_name", &i_RAW3_Data::get_name, DOC_i_RAW3_Data(get_name))
        .def("has_power", &i_RAW3_Data::has_power, DOC_i_RAW3_Data(has_power))
        .def("has_angle", &i_RAW3_Data::has_angle, DOC_i_RAW3_Data(has_angle))
        .def(
            "get_power", &i_RAW3_Data::get_power, DOC_i_RAW3_Data(get_power), py::arg("dB") = false)
        .def("get_angle", &i_RAW3_Data::get_angle, DOC_i_RAW3_Data(get_angle))

        // ----- pybind macros -----
        // default copy functions
        //__PYCLASS_DEFAULT_COPY__(i_RAW3_Data)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(i_RAW3_Data)
        // default printing functions
        //__PYCLASS_DEFAULT_PRINTING__(i_RAW3_Data)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}