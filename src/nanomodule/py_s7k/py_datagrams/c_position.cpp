// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>
#include <themachinethatgoesping/tools_nanobind/enumhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/position.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {
namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::s7k::datagrams;

#define DOC_C(CLASS, ...) DOC(themachinethatgoesping, echosounders, s7k, datagrams, CLASS, __VA_ARGS__)
#define DOC_Position(ARG) DOC(themachinethatgoesping, echosounders, s7k, datagrams, Position, ARG)

void init_c_position(nb::module_& m)
{
    using t_position_type_flag = Position::t_position_type_flag;
    using o_position_type_flag = Position::o_position_type_flag;
    using t_quality_flag       = Position::t_quality_flag;
    using o_quality_flag       = Position::o_quality_flag;
    using t_position_method    = Position::t_position_method;
    using o_position_method    = Position::o_position_method;

    // ----- enums -----
    nb::enum_<t_position_type_flag>(
        m, "Position_t_position_type_flag", "position type flag (7k DFD Table 15)")
        .value("geographic",
               t_position_type_flag::geographic,
               "geographical coordinates (latitude/longitude in radians)")
        .value("grid", t_position_type_flag::grid, "grid coordinates (northing/easting in meters)");
    themachinethatgoesping::tools::nanobind_helper::make_option_class<o_position_type_flag>(
        m, "Position_o_position_type_flag");

    nb::enum_<t_quality_flag>(m, "Position_t_quality_flag", "position quality flag (7k DFD Table 15)")
        .value("navigation", t_quality_flag::navigation, "navigation data")
        .value("dead_reckoning", t_quality_flag::dead_reckoning, "dead-reckoning");
    themachinethatgoesping::tools::nanobind_helper::make_option_class<o_quality_flag>(
        m, "Position_o_quality_flag");

    nb::enum_<t_position_method>(
        m, "Position_t_position_method", "positioning method (7k DFD Table 15)")
        .value("gps", t_position_method::gps, "GPS")
        .value("dgps", t_position_method::dgps, "DGPS")
        .value("inertial_start_from_gps",
               t_position_method::inertial_start_from_gps,
               "start of inertial positioning system from GPS")
        .value("inertial_start_from_dgps",
               t_position_method::inertial_start_from_dgps,
               "start of inertial positioning system from DGPS")
        .value("inertial_start_from_bottom_correlation",
               t_position_method::inertial_start_from_bottom_correlation,
               "start of inertial positioning system from bottom correlation")
        .value("inertial_start_from_bottom_object",
               t_position_method::inertial_start_from_bottom_object,
               "start of inertial positioning from bottom object")
        .value("inertial_start_from_inertial",
               t_position_method::inertial_start_from_inertial,
               "start of inertial positioning from inertial positioning")
        .value("inertial_start_from_optional_data",
               t_position_method::inertial_start_from_optional_data,
               "start of inertial positioning from optional data")
        .value("inertial_stop_to_gps",
               t_position_method::inertial_stop_to_gps,
               "stop of inertial positioning system to GPS")
        .value("inertial_stop_to_dgps",
               t_position_method::inertial_stop_to_dgps,
               "stop of inertial positioning system to DGPS")
        .value("inertial_stop_to_bottom_correlation",
               t_position_method::inertial_stop_to_bottom_correlation,
               "stop of inertial positioning system to bottom correlation")
        .value("inertial_stop_to_bottom_object",
               t_position_method::inertial_stop_to_bottom_object,
               "stop of inertial positioning to bottom object")
        .value("inertial_start_to_inertial",
               t_position_method::inertial_start_to_inertial,
               "start of inertial positioning to inertial positioning")
        .value("inertial_start_to_optional_data",
               t_position_method::inertial_start_to_optional_data,
               "start of inertial positioning to optional data")
        .value("user_defined", t_position_method::user_defined, "user defined")
        .value("rtk_fixed", t_position_method::rtk_fixed, "RTK fixed")
        .value("rtk_float", t_position_method::rtk_float, "RTK float");
    themachinethatgoesping::tools::nanobind_helper::make_option_class<o_position_method>(
        m, "Position_o_position_method");

    nb::class_<Position, S7KDatagram>(m, "Position", DOC(themachinethatgoesping, echosounders, s7k, datagrams, Position))
        .def(nb::init<>(), DOC_C(Position, Position))
        .def("get_datum_identifier", &Position::get_datum_identifier, DOC_C(Position, Content, datum_identifier))
        .def("set_datum_identifier", &Position::set_datum_identifier, DOC_C(Position, Content, datum_identifier), nb::arg("val"))
        .def("get_latency", &Position::get_latency, DOC_C(Position, Content, latency))
        .def("set_latency", &Position::set_latency, DOC_C(Position, Content, latency), nb::arg("val"))
        .def("get_latitude_or_northing", &Position::get_latitude_or_northing, DOC_C(Position, Content, latitude_or_northing))
        .def("set_latitude_or_northing", &Position::set_latitude_or_northing, DOC_C(Position, Content, latitude_or_northing), nb::arg("val"))
        .def("get_longitude_or_easting", &Position::get_longitude_or_easting, DOC_C(Position, Content, longitude_or_easting))
        .def("set_longitude_or_easting", &Position::set_longitude_or_easting, DOC_C(Position, Content, longitude_or_easting), nb::arg("val"))
        .def("get_height", &Position::get_height, DOC_C(Position, Content, height))
        .def("set_height", &Position::set_height, DOC_C(Position, Content, height), nb::arg("val"))
        .def("get_position_type_flag", &Position::get_position_type_flag, DOC_C(Position, Content, position_type_flag))
        .def("set_position_type_flag", &Position::set_position_type_flag, DOC_C(Position, Content, position_type_flag), nb::arg("val"))
        .def("get_utm_zone", &Position::get_utm_zone, DOC_C(Position, Content, utm_zone))
        .def("set_utm_zone", &Position::set_utm_zone, DOC_C(Position, Content, utm_zone), nb::arg("val"))
        .def("get_quality_flag", &Position::get_quality_flag, DOC_C(Position, Content, quality_flag))
        .def("set_quality_flag", &Position::set_quality_flag, DOC_C(Position, Content, quality_flag), nb::arg("val"))
        .def("get_position_method", &Position::get_position_method, DOC_C(Position, Content, position_method))
        .def("set_position_method", &Position::set_position_method, DOC_C(Position, Content, position_method), nb::arg("val"))
        .def("get_number_of_satellites", &Position::get_number_of_satellites, DOC_C(Position, Content, number_of_satellites))
        .def("set_number_of_satellites", &Position::set_number_of_satellites, DOC_C(Position, Content, number_of_satellites), nb::arg("val"))
        .def("get_checksum", &Position::get_checksum, DOC_C(Position, Content, checksum))
        .def("set_checksum", &Position::set_checksum, DOC_C(Position, Content, checksum), nb::arg("val"))
        .def("get_latitude_in_degrees", &Position::get_latitude_in_degrees, DOC_Position(get_latitude_in_degrees))
        .def("get_longitude_in_degrees", &Position::get_longitude_in_degrees, DOC_Position(get_longitude_in_degrees))
        .def("__eq__", &Position::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(Position)
        __PYCLASS_DEFAULT_BINARY__(Position)
        __PYCLASS_DEFAULT_PRINTING__(Position);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
