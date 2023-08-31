// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0



#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simrad/datagrams/raw3datatypes/raw3datatypes.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py_raw3_datatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using namespace datagrams::raw3datatypes;

// --- helper defines ---
#define DOC_i_RAW3Data(NAME)                                                                       \
    DOC(themachinethatgoesping, echosounders, simrad, datagrams, raw3datatypes, i_RAW3Data, NAME)

void init_c_i_raw3data(pybind11::module& m)
{
    py::class_<i_RAW3Data>(
        m,
        "i_RAW3Data",
        DOC(themachinethatgoesping, echosounders, simrad, datagrams, raw3datatypes, i_RAW3Data))
        .def(py::init<std::string_view>(), DOC_i_RAW3Data(i_RAW3Data), py::arg("name"))
        .def("get_name", &i_RAW3Data::get_name, DOC_i_RAW3Data(get_name))
        .def("has_power", &i_RAW3Data::has_power, DOC_i_RAW3Data(has_power))
        .def("has_angle", &i_RAW3Data::has_angle, DOC_i_RAW3Data(has_angle))
        .def("get_power", &i_RAW3Data::get_power, DOC_i_RAW3Data(get_power), py::arg("dB") = false)
        .def("get_angle", &i_RAW3Data::get_angle, DOC_i_RAW3Data(get_angle))

        // ----- pybind macros -----
        // default copy functions
        //__PYCLASS_DEFAULT_COPY__(i_RAW3Data)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(i_RAW3Data)
        // default printing functions
        //__PYCLASS_DEFAULT_PRINTING__(i_RAW3Data)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}