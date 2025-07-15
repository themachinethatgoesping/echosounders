// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pytensor.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams/RAW3.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::RAW3;
using datagrams::SimradRawDatagram;

#define DOC_RAW3(arg) DOC(themachinethatgoesping, echosounders, simradraw, datagrams, RAW3, arg)

void init_c_RAW3(pybind11::module& m)
{

    py::class_<RAW3, datagrams::SimradRawDatagram>(
        m, "RAW3", DOC(themachinethatgoesping, echosounders, simradraw, datagrams, RAW3))
        .def(py::init<>(), DOC_RAW3(RAW3))

        // --- convenient data access ---
        .def("get_channel_id", &RAW3::get_channel_id, DOC_RAW3(channel_id))
        .def("set_channel_id", &RAW3::set_channel_id, DOC_RAW3(channel_id))
        .def("get_data_type", &RAW3::get_data_type, DOC_RAW3(data_type))
        .def("set_data_type", &RAW3::set_data_type, DOC_RAW3(data_type))
        .def("get_number_of_complex_samples",
             &RAW3::get_number_of_complex_samples,
             DOC_RAW3(data_type))
        .def("set_number_of_complex_samples",
             &RAW3::set_number_of_complex_samples,
             DOC_RAW3(number_of_complex_samples))
        .def("get_offset", &RAW3::get_offset, DOC_RAW3(offset))
        .def("set_offset", &RAW3::set_offset, DOC_RAW3(offset))
        .def("get_count", &RAW3::get_count, DOC_RAW3(count))
        .def("set_count", &RAW3::set_count, DOC_RAW3(count))
        .def("get_spare1", &RAW3::get_spare_1, DOC_RAW3(spare_1))
        .def("set_spare1", &RAW3::set_spare_1, DOC_RAW3(spare_1))
        .def("get_spare_2", &RAW3::get_spare_2, DOC_RAW3(spare_2))
        .def("set_spare_2", &RAW3::set_spare_2, DOC_RAW3(spare_2))
        .def("sample_data", py::overload_cast<>(&RAW3::sample_data), DOC_RAW3(sample_data))
        .def("get_sample_data", &RAW3::get_sample_data, DOC_RAW3(sample_data))
        .def("set_sample_data", &RAW3::set_sample_data, DOC_RAW3(sample_data))

        // --- processed data access ---
        .def("get_channel_id_stripped",
             &RAW3::get_channel_id_stripped,
             DOC_RAW3(get_channel_id_stripped))

        // ----- operators -----
        .def("__eq__", &RAW3::operator==, DOC_RAW3(operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RAW3)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(RAW3)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RAW3)
        // end LinearInterpolator
        ;
}
}
}
}
}
}