// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/cposition.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::CPosition;

#define DOC_CPosition(ARG)                                                                         \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, CPosition, ARG)

void init_c_cposition(nanobind::module_& m)
{
    nb::class_<CPosition, datagrams::KMALLSensorDatagram>(
        m, "CPosition", DOC(themachinethatgoesping, echosounders, kmall, datagrams, CPosition))
        .def(nb::init<>(), DOC_CPosition(CPosition))

        // --- convenient data access ---
        .def("get_time_from_sensor_sec",
             &CPosition::get_time_from_sensor_sec,
             DOC_CPosition(get_time_from_sensor_sec))
        .def("get_time_from_sensor_nanosec",
             &CPosition::get_time_from_sensor_nanosec,
             DOC_CPosition(get_time_from_sensor_nanosec))
        .def("get_pos_fix_quality_m",
             &CPosition::get_pos_fix_quality_m,
             DOC_CPosition(get_pos_fix_quality_m))
        .def("get_corrected_lat_deg",
             &CPosition::get_corrected_lat_deg,
             DOC_CPosition(get_corrected_lat_deg))
        .def("get_corrected_lon_deg",
             &CPosition::get_corrected_lon_deg,
             DOC_CPosition(get_corrected_lon_deg))
        .def("get_speed_over_ground_m_per_sec",
             &CPosition::get_speed_over_ground_m_per_sec,
             DOC_CPosition(get_speed_over_ground_m_per_sec))
        .def("get_course_over_ground_deg",
             &CPosition::get_course_over_ground_deg,
             DOC_CPosition(get_course_over_ground_deg))
        .def("get_ellipsoid_height_re_ref_point_m",
             &CPosition::get_ellipsoid_height_re_ref_point_m,
             DOC_CPosition(get_ellipsoid_height_re_ref_point_m))
        .def(
            "get_pos_data_from_sensor",
            [](const CPosition& self) {
                const auto& data = self.get_pos_data_from_sensor();
                return nb::bytes(data.data(), data.size());
            },
            DOC_CPosition(get_pos_data_from_sensor))
        .def("get_pos_data_from_sensor_str",
             &CPosition::get_pos_data_from_sensor,
             DOC_CPosition(get_pos_data_from_sensor))
        .def("get_bytes_datagram_check",
             &CPosition::get_bytes_datagram_check,
             DOC_CPosition(get_bytes_datagram_check))
        .def("set_time_from_sensor_sec",
             &CPosition::set_time_from_sensor_sec,
             DOC_CPosition(set_time_from_sensor_sec),
             nb::arg("val"))
        .def("set_time_from_sensor_nanosec",
             &CPosition::set_time_from_sensor_nanosec,
             DOC_CPosition(set_time_from_sensor_nanosec),
             nb::arg("val"))
        .def("set_pos_fix_quality_m",
             &CPosition::set_pos_fix_quality_m,
             DOC_CPosition(set_pos_fix_quality_m),
             nb::arg("val"))
        .def("set_corrected_lat_deg",
             &CPosition::set_corrected_lat_deg,
             DOC_CPosition(set_corrected_lat_deg),
             nb::arg("val"))
        .def("set_corrected_lon_deg",
             &CPosition::set_corrected_lon_deg,
             DOC_CPosition(set_corrected_lon_deg),
             nb::arg("val"))
        .def("set_speed_over_ground_m_per_sec",
             &CPosition::set_speed_over_ground_m_per_sec,
             DOC_CPosition(set_speed_over_ground_m_per_sec),
             nb::arg("val"))
        .def("set_course_over_ground_deg",
             &CPosition::set_course_over_ground_deg,
             DOC_CPosition(set_course_over_ground_deg),
             nb::arg("val"))
        .def("set_ellipsoid_height_re_ref_point_m",
             &CPosition::set_ellipsoid_height_re_ref_point_m,
             DOC_CPosition(set_ellipsoid_height_re_ref_point_m),
             nb::arg("val"))
        .def("set_pos_data_from_sensor",
             &CPosition::set_pos_data_from_sensor,
             DOC_CPosition(set_pos_data_from_sensor),
             nb::arg("pos_data"))
        .def("set_bytes_datagram_check",
             &CPosition::set_bytes_datagram_check,
             DOC_CPosition(set_bytes_datagram_check),
             nb::arg("val"))

        // ----- processed -----
        .def("get_sensor_timestamp",
             &CPosition::get_sensor_timestamp,
             DOC_CPosition(get_sensor_timestamp))
        .def("get_sensor_date_string",
             &CPosition::get_sensor_date_string,
             DOC_CPosition(get_sensor_date_string),
             nb::arg("fractionalSecondsDigits") = 2,
             nb::arg("format")                  = "%z__%d-%m-%Y__%H:%M:%S")
        .def(
            "get_sensor_datetime",
            [](const CPosition& self, double timezone_offset_hours) {
                return tools::nanobind_helper::unixtime_to_datetime(self.get_sensor_timestamp(),
                                                                    timezone_offset_hours);
            },
            nb::arg("timezone_offset_hours") = 0.,
            "Return the timestamp as datetime object")

        // ----- operators -----
        .def("__eq__", &CPosition::operator==, DOC_CPosition(operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(CPosition)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(CPosition)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(CPosition)
        // end LinearInterpolator
        ;
}
}
}
}
}
}