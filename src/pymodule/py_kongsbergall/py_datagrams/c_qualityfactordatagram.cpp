// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pytensor.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/qualityfactordatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::QualityFactorDatagram;

#define DOC_QualityFactorDatagram(ARG)                                                             \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, QualityFactorDatagram, ARG)

void init_c_qualityfactordatagram(pybind11::module& m)
{
    py::class_<QualityFactorDatagram, datagrams::KongsbergAllDatagram>(
        m,
        "QualityFactorDatagram",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, QualityFactorDatagram))
        .def(py::init<>(), DOC_QualityFactorDatagram(QualityFactorDatagram))

        // --- convenient data access ---
        .def("set_ping_counter",
             &QualityFactorDatagram::set_ping_counter,
             DOC_QualityFactorDatagram(ping_counter))
        .def("get_ping_counter",
             &QualityFactorDatagram::get_ping_counter,
             DOC_QualityFactorDatagram(ping_counter))
        .def("set_system_serial_number",
             &QualityFactorDatagram::set_system_serial_number,
             DOC_QualityFactorDatagram(system_serial_number))
        .def("get_system_serial_number",
             &QualityFactorDatagram::get_system_serial_number,
             DOC_QualityFactorDatagram(system_serial_number))
        .def("set_number_of_receive_beams",
             &QualityFactorDatagram::set_number_of_receive_beams,
             DOC_QualityFactorDatagram(number_of_receive_beams))
        .def("get_number_of_receive_beams",
             &QualityFactorDatagram::get_number_of_receive_beams,
             DOC_QualityFactorDatagram(number_of_receive_beams))
        .def("set_number_of_parameters_per_beam",
             &QualityFactorDatagram::set_number_of_parameters_per_beam,
             DOC_QualityFactorDatagram(number_of_parameters_per_beam))
        .def("get_number_of_parameters_per_beam",
             &QualityFactorDatagram::get_number_of_parameters_per_beam,
             DOC_QualityFactorDatagram(number_of_parameters_per_beam))
        .def("set_spare", &QualityFactorDatagram::set_spare, DOC_QualityFactorDatagram(spare))
        .def("get_spare", &QualityFactorDatagram::get_spare, DOC_QualityFactorDatagram(spare))

        // --- data structure access ---
        .def("get_quality_factors",
             &QualityFactorDatagram::get_quality_factors,
             DOC_QualityFactorDatagram(quality_factors),
             py::return_value_policy::reference_internal)
        .def("set_quality_factors",
             &QualityFactorDatagram::set_quality_factors,
             DOC_QualityFactorDatagram(quality_factors))
        .def("quality_factors",
             &QualityFactorDatagram::quality_factors,
             DOC_QualityFactorDatagram(quality_factors),
             py::return_value_policy::reference_internal)

        .def("qf_shape", &QualityFactorDatagram::qf_shape, DOC_QualityFactorDatagram(qf_shape))

        // --- processed member access ---

        // --- checksum access ---
        .def("get_etx", &QualityFactorDatagram::get_etx, DOC_QualityFactorDatagram(etx))
        .def("set_etx", &QualityFactorDatagram::set_etx, DOC_QualityFactorDatagram(etx))
        .def("get_checksum",
             &QualityFactorDatagram::get_checksum,
             DOC_QualityFactorDatagram(checksum))
        .def("set_checksum",
             &QualityFactorDatagram::set_checksum,
             DOC_QualityFactorDatagram(checksum))

        // ----- operators -----
        .def("__eq__",
             &QualityFactorDatagram::operator==,
             DOC_QualityFactorDatagram(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(QualityFactorDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(QualityFactorDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(QualityFactorDatagram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}