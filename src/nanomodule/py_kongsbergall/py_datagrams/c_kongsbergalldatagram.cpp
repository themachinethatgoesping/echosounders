// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/kongsbergalldatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::KongsbergAllDatagram;

void init_c_kongsbergalldatagram(nanobind::module_& m)
{
    nb::class_<KongsbergAllDatagram>(
        m,
        "KongsbergAllDatagram",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, KongsbergAllDatagram))
    .def(nb::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 KongsbergAllDatagram))
        // --- convenient data access ---
        .def("get_bytes",
             &KongsbergAllDatagram::get_bytes,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 bytes))
        .def("set_bytes",
             &KongsbergAllDatagram::set_bytes,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 bytes))
        .def("get_stx",
             &KongsbergAllDatagram::get_stx,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 stx))
        .def("set_stx",
             &KongsbergAllDatagram::set_stx,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 stx))
        .def("get_datagram_identifier",
             &KongsbergAllDatagram::get_datagram_identifier,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 datagram_identifier))
        .def("set_datagram_identifier",
             &KongsbergAllDatagram::set_datagram_identifier,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 datagram_identifier))
        .def("get_model_number",
             &KongsbergAllDatagram::get_model_number,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 model_number))
        .def("set_model_number",
             &KongsbergAllDatagram::set_model_number,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 model_number))
        .def("get_date",
             &KongsbergAllDatagram::get_date,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 date))
        .def("set_date",
             &KongsbergAllDatagram::set_date,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 date))
        .def("get_time_since_midnight",
             &KongsbergAllDatagram::get_time_since_midnight,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 time_since_midnight))
        .def("set_time_since_midnight",
             &KongsbergAllDatagram::set_time_since_midnight,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 time_since_midnight))

        // --- convenient processed data access ---
        .def("get_timestamp",
             &KongsbergAllDatagram::get_timestamp,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 get_timestamp))

        .def(
            "get_datetime",
            [](const KongsbergAllDatagram& self, double timezone_offset_hours) {
                return tools::nanobind_helper::unixtime_to_datetime(self.get_timestamp(),
                                                                   timezone_offset_hours);
            },
            nb::arg("timezone_offset_hours") = 0.,
            "Return the timestamp as datetime object")

        .def("get_date_string",
             &KongsbergAllDatagram::get_date_string,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 get_date_string),
             nb::arg("fractional_seconds_digits") = 2,
             nb::arg("format")                    = "%z__%d-%m-%Y__%H:%M:%S")

        .def("get_model_number_as_string",
             &KongsbergAllDatagram::get_model_number_as_string,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 get_model_number_as_string))

        // ----- operators -----
        .def("__eq__",
             &KongsbergAllDatagram::operator==,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllDatagram,
                 operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(KongsbergAllDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(KongsbergAllDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(KongsbergAllDatagram)
        // end LinearInterpolator
        ;
}

}
}
}
}
}