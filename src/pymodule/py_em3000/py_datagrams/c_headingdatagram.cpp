// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/em3000/datagrams/headingdatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using datagrams::HeadingDatagram;

#define DOC_HeadingDatagram(ARG)                                                               \
    DOC(themachinethatgoesping, echosounders, em3000, datagrams, HeadingDatagram, ARG)

void init_c_headingdatagram(pybind11::module& m)
{
    py::class_<HeadingDatagram, datagrams::EM3000Datagram>(
        m,
        "HeadingDatagram",
        DOC(themachinethatgoesping, echosounders, em3000, datagrams, HeadingDatagram))
        .def(py::init<>(), DOC_HeadingDatagram(HeadingDatagram))
        // --- convenient data access ---
        .def("set_heading_counter",
             &HeadingDatagram::set_heading_counter,
             DOC_HeadingDatagram(heading_counter))
        .def("get_heading_counter",
             &HeadingDatagram::get_heading_counter,
             DOC_HeadingDatagram(heading_counter))
        .def("set_system_serial_number",
             &HeadingDatagram::set_system_serial_number,
             DOC_HeadingDatagram(system_serial_number))
        .def("get_system_serial_number",
             &HeadingDatagram::get_system_serial_number,
             DOC_HeadingDatagram(system_serial_number))
        .def("set_number_of_entries",
             &HeadingDatagram::set_number_of_entries,
             DOC_HeadingDatagram(number_of_entries))
        .def("get_number_of_entries",
             &HeadingDatagram::get_number_of_entries,
             DOC_HeadingDatagram(heading_indicator))
        .def("set_heading_indicator",
             &HeadingDatagram::set_heading_indicator,
             DOC_HeadingDatagram(heading_indicator))
        .def("get_heading_indicator",
             &HeadingDatagram::get_heading_indicator,
             DOC_HeadingDatagram(heading_indicator))
       

        // --- data structure access ---
        .def("get_times_headings",
             &HeadingDatagram::get_times_headings,
             DOC_HeadingDatagram(times_headings),
             py::return_value_policy::reference_internal)
        .def("set_times_headings", &HeadingDatagram::set_times_headings, DOC_HeadingDatagram(times_headings))
        .def("times_headings",
             &HeadingDatagram::times_headings,
             DOC_HeadingDatagram(times_headings),
             py::return_value_policy::reference_internal)

        // --- processed member access ---
        .def("get_heading_timestamps",
             &HeadingDatagram::get_heading_timestamps,
             DOC_HeadingDatagram(get_heading_timestamps))
        .def("get_headings_in_degrees",
             &HeadingDatagram::get_headings_in_degrees,
             DOC_HeadingDatagram(get_headings_in_degrees))

        // --- checksum access ---
        .def("get_etx", &HeadingDatagram::get_etx, DOC_HeadingDatagram(etx))
        .def("set_etx", &HeadingDatagram::set_etx, DOC_HeadingDatagram(etx))
        .def("get_checksum", &HeadingDatagram::get_checksum, DOC_HeadingDatagram(checksum))
        .def("set_checksum", &HeadingDatagram::set_checksum, DOC_HeadingDatagram(checksum))

        // ----- operators -----
        .def("__eq__",
             &HeadingDatagram::operator==,
             DOC_HeadingDatagram(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(HeadingDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(HeadingDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(HeadingDatagram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}