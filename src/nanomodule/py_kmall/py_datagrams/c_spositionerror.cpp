// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/spositionerror.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::SPositionError;

#define DOC_SPositionError(ARG)                                                                    \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, SPositionError, ARG)

void init_c_spositionerror(nanobind::module_& m)
{
    nb::class_<SPositionError, datagrams::KMALLSensorDatagram>(
        m,
        "SPositionError",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, SPositionError))
        .def(nb::init<>(), DOC_SPositionError(SPositionError))

        // --- convenient data access ---
        .def("get_time_from_sensor_sec",
             &SPositionError::get_time_from_sensor_sec,
             DOC_SPositionError(get_time_from_sensor_sec))
        .def("get_time_from_sensor_nanosec",
             &SPositionError::get_time_from_sensor_nanosec,
             DOC_SPositionError(get_time_from_sensor_nanosec))
        .def("get_range_input_rms",
             &SPositionError::get_range_input_rms,
             DOC_SPositionError(get_range_input_rms))
        .def("get_ellipse_semi_major_axis_error_m",
             &SPositionError::get_ellipse_semi_major_axis_error_m,
             DOC_SPositionError(get_ellipse_semi_major_axis_error_m))
        .def("get_ellipse_semi_minor_axis_error_m",
             &SPositionError::get_ellipse_semi_minor_axis_error_m,
             DOC_SPositionError(get_ellipse_semi_minor_axis_error_m))
        .def("get_ellipse_erientation_error_deg",
             &SPositionError::get_ellipse_erientation_error_deg,
             DOC_SPositionError(get_ellipse_erientation_error_deg))
        .def("get_latitude_error_m",
             &SPositionError::get_latitude_error_m,
             DOC_SPositionError(get_latitude_error_m))
        .def("get_longitude_error_m",
             &SPositionError::get_longitude_error_m,
             DOC_SPositionError(get_longitude_error_m))
        .def("get_height_error_m",
             &SPositionError::get_height_error_m,
             DOC_SPositionError(get_height_error_m))
        .def(
            "get_pos_error_data_from_sensor",
            [](const SPositionError& self) {
                const auto& data = self.get_pos_error_data_from_sensor();
                return nb::bytes(data.data(), data.size());
            },
            DOC_SPositionError(get_pos_error_data_from_sensor))
        .def("get_pos_error_data_from_sensor_str",
             &SPositionError::get_pos_error_data_from_sensor,
             DOC_SPositionError(get_pos_error_data_from_sensor))
        .def("get_bytes_datagram_check",
             &SPositionError::get_bytes_datagram_check,
             DOC_SPositionError(get_bytes_datagram_check))
        .def("set_time_from_sensor_sec",
             &SPositionError::set_time_from_sensor_sec,
             DOC_SPositionError(set_time_from_sensor_sec),
             nb::arg("val"))
        .def("set_time_from_sensor_nanosec",
             &SPositionError::set_time_from_sensor_nanosec,
             DOC_SPositionError(set_time_from_sensor_nanosec),
             nb::arg("val"))
        .def("set_range_input_rms",
             &SPositionError::set_range_input_rms,
             DOC_SPositionError(set_range_input_rms),
             nb::arg("val"))
        .def("set_ellipse_semi_major_axis_error_m",
             &SPositionError::set_ellipse_semi_major_axis_error_m,
             DOC_SPositionError(set_ellipse_semi_major_axis_error_m),
             nb::arg("val"))
        .def("set_ellipse_semi_minor_axis_error_m",
             &SPositionError::set_ellipse_semi_minor_axis_error_m,
             DOC_SPositionError(set_ellipse_semi_minor_axis_error_m),
             nb::arg("val"))
        .def("set_ellipse_erientation_error_deg",
             &SPositionError::set_ellipse_erientation_error_deg,
             DOC_SPositionError(set_ellipse_erientation_error_deg),
             nb::arg("val"))
        .def("set_latitude_error_m",
             &SPositionError::set_latitude_error_m,
             DOC_SPositionError(set_latitude_error_m),
             nb::arg("val"))
        .def("set_longitude_error_m",
             &SPositionError::set_longitude_error_m,
             DOC_SPositionError(set_longitude_error_m),
             nb::arg("val"))
        .def("set_height_error_m",
             &SPositionError::set_height_error_m,
             DOC_SPositionError(set_height_error_m),
             nb::arg("val"))
        .def("set_pos_error_data_from_sensor",
             &SPositionError::set_pos_error_data_from_sensor,
             DOC_SPositionError(set_pos_error_data_from_sensor),
             nb::arg("pos_error_data"))
        .def("set_bytes_datagram_check",
             &SPositionError::set_bytes_datagram_check,
             DOC_SPositionError(set_bytes_datagram_check),
             nb::arg("val"))

        // ----- processed -----
        .def("get_sensor_timestamp",
             &SPositionError::get_sensor_timestamp,
             DOC_SPositionError(get_sensor_timestamp))
        .def("get_sensor_date_string",
             &SPositionError::get_sensor_date_string,
             DOC_SPositionError(get_sensor_date_string),
             nb::arg("fractionalSecondsDigits") = 2,
             nb::arg("format")                  = "%z__%d-%m-%Y__%H:%M:%S")
        .def(
            "get_sensor_datetime",
            [](const SPositionError& self, double timezone_offset_hours) {
                return tools::nanobind_helper::unixtime_to_datetime(self.get_sensor_timestamp(),
                                                                    timezone_offset_hours);
            },
            nb::arg("timezone_offset_hours") = 0.,
            "Return the timestamp as datetime object")

        // ----- operators -----
        .def("__eq__",
             &SPositionError::operator==,
             DOC_SPositionError(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(SPositionError)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(SPositionError)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(SPositionError)
        // end LinearInterpolator
        ;
}
}
}
}
}
}