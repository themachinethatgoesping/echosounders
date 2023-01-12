// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/RAW3.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::RAW3;
using datagrams::SimradDatagram;

void init_c_RAW3(pybind11::module& m)
{

    py::class_<RAW3, datagrams::SimradDatagram>(
        m, "RAW3", DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3))
        .def(py::init<>(), DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3, RAW3))
        // --- convenient data access ---
        .def_property("channel_id",
                      &RAW3::get_channel_id,
                      &RAW3::set_channel_id,
                      DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3, ChannelID))
        .def_property_readonly("channel_id_stripped",
                               &RAW3::get_channel_id,
                               DOC(themachinethatgoesping,
                                   echosounders,
                                   simrad,
                                   datagrams,
                                   RAW3,
                                   get_channel_id_stripped))
        .def_property(
            "data_type",
            &RAW3::get_data_type,
            &RAW3::set_data_type,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3, get_data_type))
        .def_property("number_of_complex_samples",
                      &RAW3::get_number_of_complex_samples,
                      &RAW3::set_number_of_complex_samples,
                      DOC(themachinethatgoesping,
                          echosounders,
                          simrad,
                          datagrams,
                          RAW3,
                          get_number_of_complex_samples))
        .def_property("offset",
                      &RAW3::get_offset,
                      &RAW3::set_offset,
                      DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3, Offset))
        .def_property("count",
                      &RAW3::get_count,
                      &RAW3::set_count,
                      DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3, Count))
        .def_property(
            "sample_data",
            &RAW3::sample_data,
            &RAW3::set_sample_data,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3, sample_data))

        // --- raw data access ---
        .def_readwrite(
            "_raw_ChannelID",
            &RAW3::_ChannelID,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3, ChannelID))
        .def_readwrite("_raw_Datatype",
                       &RAW3::_Datatype,
                       DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3, Datatype))
        .def_readwrite("_raw_NumberOfComplexSamples",
                       &RAW3::_NumberOfComplexSamples,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           RAW3,
                           NumberOfComplexSamples))
        .def_readwrite("_raw_Spare_1",
                       &RAW3::_Spare_1,
                       DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3, Spare_1))
        .def_readwrite("_raw_Spare_2",
                       &RAW3::_Spare_2,
                       DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3, Spare_2))
        .def_readwrite("_raw_Offset",
                       &RAW3::_Offset,
                       DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3, Offset))
        .def_readwrite("_raw_Count",
                       &RAW3::_Count,
                       DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3, Count))
        // ----- operators -----
        .def("__eq__",
             &RAW3::operator==,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, RAW3, operator_eq),
             py::arg("other"))
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