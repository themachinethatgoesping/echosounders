// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams/simradrawdatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::SimradRawDatagram;

#define DOC_SimradRawDatagram(arg)                                                                 \
    DOC(themachinethatgoesping, echosounders, simradraw, datagrams, SimradRawDatagram, arg)

void init_c_SimradRawDatagram(nanobind::module_& m)
{
    nb::class_<SimradRawDatagram>(
        m,
        "SimradRawDatagram",
        DOC(themachinethatgoesping, echosounders, simradraw, datagrams, SimradRawDatagram))
        .def(nb::init<>(), DOC_SimradRawDatagram(SimradRawDatagram))

        // --- convenient data access ---
        .def("get_length", &SimradRawDatagram::get_length, DOC_SimradRawDatagram(length))
        .def("set_length", &SimradRawDatagram::set_length, DOC_SimradRawDatagram(length))
        .def("get_datagram_type",
             &SimradRawDatagram::get_datagram_type,
             DOC_SimradRawDatagram(datagram_type))
        .def("set_datagram_type",
             &SimradRawDatagram::set_datagram_type,
             DOC_SimradRawDatagram(datagram_type))
        .def("get_low_date_time",
             &SimradRawDatagram::get_low_date_time,
             DOC_SimradRawDatagram(low_date_time))
        .def("set_low_date_time",
             &SimradRawDatagram::set_low_date_time,
             DOC_SimradRawDatagram(low_date_time))
        .def("get_high_date_time",
             &SimradRawDatagram::get_high_date_time,
             DOC_SimradRawDatagram(high_date_time))
        .def("set_high_date_time",
             &SimradRawDatagram::set_high_date_time,
             DOC_SimradRawDatagram(high_date_time))

        // --- processed data access
        .def("get_timestamp",
             &SimradRawDatagram::get_timestamp,
             DOC_SimradRawDatagram(get_timestamp))
        .def("set_timestamp",
             &SimradRawDatagram::set_timestamp,
             DOC_SimradRawDatagram(set_timestamp))
        .def("get_datagram_identifier",
             &SimradRawDatagram::get_datagram_identifier,
             DOC_SimradRawDatagram(get_datagram_identifier))
        .def("set_datagram_identifier",
             &SimradRawDatagram::set_datagram_identifier,
             DOC_SimradRawDatagram(set_datagram_identifier))
        .def("get_date_string",
             &SimradRawDatagram::get_date_string,
             DOC_SimradRawDatagram(get_date_string))

        // ----- datetime access -----
        .def(
            "get_datetime",
            [](const SimradRawDatagram& self, double timezone_offset_hours) {
                return tools::nanobind_helper::unixtime_to_datetime(self.get_timestamp(),
                                                                    timezone_offset_hours);
            },
            nb::arg("timezone_offset_hours") = 0.,
            "Return the timestamp as datetime object")
        .def(
            "set_datetime",
               [](SimradRawDatagram& self, const nb::handle& datetime) {
                    self.set_timestamp(tools::nanobind_helper::datetime_to_unixtime(datetime));
            },
            nb::arg("datetime"),
            "Set the timestamp using a datetime object")

        // ----- operators -----
        .def("__eq__",
             &SimradRawDatagram::operator==,
             DOC_SimradRawDatagram(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(SimradRawDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(SimradRawDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(SimradRawDatagram)
        // end LinearInterpolator
        ;
}

}
}
}
}
}