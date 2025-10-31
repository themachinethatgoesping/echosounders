// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/sposition.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::SPosition;

#define DOC_SPosition(ARG)                                                                         \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, SPosition, ARG)

void init_c_sposition(nanobind::module_& m)
{
    nb::class_<SPosition, datagrams::KMALLSensorDatagram>(
        m, "SPosition", DOC(themachinethatgoesping, echosounders, kmall, datagrams, SPosition))
        .def(nb::init<>(), DOC_SPosition(SPosition))

        // --- convenient data access ---
        .def("get_time_from_sensor_sec",
             &SPosition::get_time_from_sensor_sec,
             DOC_SPosition(get_time_from_sensor_sec))
        .def("get_time_from_sensor_nanosec",
             &SPosition::get_time_from_sensor_nanosec,
             DOC_SPosition(get_time_from_sensor_nanosec))
        .def("get_pos_fix_quality_m",
             &SPosition::get_pos_fix_quality_m,
             DOC_SPosition(get_pos_fix_quality_m))
        .def("get_corrected_lat_deg",
             &SPosition::get_corrected_lat_deg,
             DOC_SPosition(get_corrected_lat_deg))
        .def("get_corrected_lon_deg",
             &SPosition::get_corrected_lon_deg,
             DOC_SPosition(get_corrected_lon_deg))
        .def("get_speed_over_ground_m_per_sec",
             &SPosition::get_speed_over_ground_m_per_sec,
             DOC_SPosition(get_speed_over_ground_m_per_sec))
        .def("get_course_over_ground_deg",
             &SPosition::get_course_over_ground_deg,
             DOC_SPosition(get_course_over_ground_deg))
        .def("get_ellipsoid_height_re_ref_point_m",
             &SPosition::get_ellipsoid_height_re_ref_point_m,
             DOC_SPosition(get_ellipsoid_height_re_ref_point_m))
        .def(
            "get_pos_data_from_sensor",
            [](const SPosition& self) {
                const auto& data = self.get_pos_data_from_sensor();
                return nb::bytes(data.data(), data.size());
            },
            DOC_SPosition(get_pos_data_from_sensor))
        .def("get_pos_data_from_sensor_str",
             &SPosition::get_pos_data_from_sensor,
             DOC_SPosition(get_pos_data_from_sensor))
        .def("get_bytes_datagram_check",
             &SPosition::get_bytes_datagram_check,
             DOC_SPosition(get_bytes_datagram_check))
        .def("set_time_from_sensor_sec",
             &SPosition::set_time_from_sensor_sec,
             DOC_SPosition(set_time_from_sensor_sec),
             nb::arg("val"))
        .def("set_time_from_sensor_nanosec",
             &SPosition::set_time_from_sensor_nanosec,
             DOC_SPosition(set_time_from_sensor_nanosec),
             nb::arg("val"))
        .def("set_pos_fix_quality_m",
             &SPosition::set_pos_fix_quality_m,
             DOC_SPosition(set_pos_fix_quality_m),
             nb::arg("val"))
        .def("set_corrected_lat_deg",
             &SPosition::set_corrected_lat_deg,
             DOC_SPosition(set_corrected_lat_deg),
             nb::arg("val"))
        .def("set_corrected_lon_deg",
             &SPosition::set_corrected_lon_deg,
             DOC_SPosition(set_corrected_lon_deg),
             nb::arg("val"))
        .def("set_speed_over_ground_m_per_sec",
             &SPosition::set_speed_over_ground_m_per_sec,
             DOC_SPosition(set_speed_over_ground_m_per_sec),
             nb::arg("val"))
        .def("set_course_over_ground_deg",
             &SPosition::set_course_over_ground_deg,
             DOC_SPosition(set_course_over_ground_deg),
             nb::arg("val"))
        .def("set_ellipsoid_height_re_ref_point_m",
             &SPosition::set_ellipsoid_height_re_ref_point_m,
             DOC_SPosition(set_ellipsoid_height_re_ref_point_m),
             nb::arg("val"))
        .def("set_pos_data_from_sensor",
             &SPosition::set_pos_data_from_sensor,
             DOC_SPosition(set_pos_data_from_sensor),
             nb::arg("pos_data"))
        .def("set_bytes_datagram_check",
             &SPosition::set_bytes_datagram_check,
             DOC_SPosition(set_bytes_datagram_check),
             nb::arg("val"))

        // ----- processed -----
        .def("get_sensor_timestamp",
             &SPosition::get_sensor_timestamp,
             DOC_SPosition(get_sensor_timestamp))
        .def("get_sensor_date_string",
             &SPosition::get_sensor_date_string,
             DOC_SPosition(get_sensor_date_string),
             nb::arg("fractionalSecondsDigits") = 2,
             nb::arg("format")                  = "%z__%d-%m-%Y__%H:%M:%S")
        .def(
            "get_sensor_datetime",
            [](const SPosition& self, double timezone_offset_hours) {
                return tools::nanobind_helper::unixtime_to_datetime(self.get_sensor_timestamp(),
                                                                    timezone_offset_hours);
            },
            nb::arg("timezone_offset_hours") = 0.,
            "Return the timestamp as datetime object")

        // ----- operators -----
        .def("__eq__", &SPosition::operator==, DOC_SPosition(operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(SPosition)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(SPosition)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(SPosition)
        // end LinearInterpolator
        ;
}
}
}
}
}
}