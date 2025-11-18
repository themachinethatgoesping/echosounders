// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/enumhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/skmbinary.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::SKMBinary;

#define DOC_SKMBinary(ARG)                                                                         \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, SKMBinary, ARG)
#define DOC_SKMBinarySensorFormat(ARG)                                                             \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, SKMBinary, t_sensor_format, ARG)

void init_c_skmbinary(nanobind::module_& m)
{
    using KMBinary        = SKMBinary::KMBinary;
    using KMDelayedHeave  = SKMBinary::KMDelayedHeave;
    using SKMSample       = SKMBinary::SKMSample;
    using t_sensor_format = SKMBinary::t_sensor_format;
    using o_sensor_format = SKMBinary::o_sensor_format;

    nb::enum_<t_sensor_format>(m, "SKMBinary_t_sensor_format", DOC_SKMBinary(t_sensor_format))
        .value("KM_binary_Sensor_Input",
               t_sensor_format::KM_binary_Sensor_Input,
               DOC_SKMBinarySensorFormat(KM_binary_Sensor_Input))
        .value(
            "EM_3000_data", t_sensor_format::EM_3000_data, DOC_SKMBinarySensorFormat(EM_3000_data))
        .value("Sagem", t_sensor_format::Sagem, DOC_SKMBinarySensorFormat(Sagem))
        .value("Seapath_binary_11",
               t_sensor_format::Seapath_binary_11,
               DOC_SKMBinarySensorFormat(Seapath_binary_11))
        .value("Seapath_binary_23",
               t_sensor_format::Seapath_binary_23,
               DOC_SKMBinarySensorFormat(Seapath_binary_23))
        .value("Seapath_binary_26",
               t_sensor_format::Seapath_binary_26,
               DOC_SKMBinarySensorFormat(Seapath_binary_26))
        .value("POS_M_V_GRP_102_103",
               t_sensor_format::POS_M_V_GRP_102_103,
               DOC_SKMBinarySensorFormat(POS_M_V_GRP_102_103))
        // end
        ;

    themachinethatgoesping::tools::nanobind_helper::make_option_class<o_sensor_format>(
        m, "SKMBinary_o_sensor_format");

    nb::class_<KMBinary>(m, "KMBinary", "Kongsberg KM Binary navigation sample")
        .def(nb::init<>())
        .def_rw("datagram_identifier", &KMBinary::datagram_identifier)
        .def_rw("bytes_content", &KMBinary::bytes_content)
        .def_rw("dgm_version", &KMBinary::dgm_version)
        .def_rw("time_sec", &KMBinary::time_sec)
        .def_rw("time_nanosec", &KMBinary::time_nanosec)
        .def_rw("status", &KMBinary::status)
        .def_rw("latitude_deg", &KMBinary::latitude_deg)
        .def_rw("longitude_deg", &KMBinary::longitude_deg)
        .def_rw("ellipsoid_height_m", &KMBinary::ellipsoid_height_m)
        .def_rw("roll_deg", &KMBinary::roll_deg)
        .def_rw("pitch_deg", &KMBinary::pitch_deg)
        .def_rw("heading_deg", &KMBinary::heading_deg)
        .def_rw("heave_m", &KMBinary::heave_m)
        .def_rw("roll_rate", &KMBinary::roll_rate)
        .def_rw("pitch_rate", &KMBinary::pitch_rate)
        .def_rw("yaw_rate", &KMBinary::yaw_rate)
        .def_rw("vel_north", &KMBinary::vel_north)
        .def_rw("vel_east", &KMBinary::vel_east)
        .def_rw("vel_down", &KMBinary::vel_down)
        .def_rw("latitude_error_m", &KMBinary::latitude_error_m)
        .def_rw("longitude_error_m", &KMBinary::longitude_error_m)
        .def_rw("ellipsoid_height_error_m", &KMBinary::ellipsoid_height_error_m)
        .def_rw("roll_error_deg", &KMBinary::roll_error_deg)
        .def_rw("pitch_error_deg", &KMBinary::pitch_error_deg)
        .def_rw("heading_error_deg", &KMBinary::heading_error_deg)
        .def_rw("heave_error_m", &KMBinary::heave_error_m)
        .def_rw("north_acceleration", &KMBinary::north_acceleration)
        .def_rw("east_acceleration", &KMBinary::east_acceleration)
        .def_rw("down_acceleration", &KMBinary::down_acceleration)

        // processed
        // .def("get_status_bits", &KMBinary::get_status_bits)
        // .def("set_status_bits", &KMBinary::set_status_bits, nb::arg("bits"))

        .def("get_horizontal_position_and_velocity_valid",
             &KMBinary::get_horizontal_position_and_velocity_valid)
        .def("get_roll_and_pitch_valid", &KMBinary::get_roll_and_pitch_valid)
        .def("get_heading_valid", &KMBinary::get_heading_valid)
        .def("get_heave_valid", &KMBinary::get_heave_valid)
        .def("get_acceleration_valid", &KMBinary::get_acceleration_valid)
        .def("get_delayed_heave1_valid", &KMBinary::get_delayed_heave1_valid)
        .def("get_delayed_heave2_valid", &KMBinary::get_delayed_heave2_valid)

        .def("get_horizontal_position_and_velocity_reduced_performance",
             &KMBinary::get_horizontal_position_and_velocity_reduced_performance)
        .def("get_roll_and_pitch_reduced_performance",
             &KMBinary::get_roll_and_pitch_reduced_performance)
        .def("get_heading_reduced_performance", &KMBinary::get_heading_reduced_performance)
        .def("get_heave_reduced_performance", &KMBinary::get_heave_reduced_performance)
        .def("get_acceleration_reduced_performance",
             &KMBinary::get_acceleration_reduced_performance)
        .def("get_delayed_heave1_reduced_performance",
             &KMBinary::get_delayed_heave1_reduced_performance)
        .def("get_delayed_heave2_reduced_performance",
             &KMBinary::get_delayed_heave2_reduced_performance)

        .def("set_horizontal_position_and_velocity_valid",
             &KMBinary::set_horizontal_position_and_velocity_valid,
             nb::arg("valid"))
        .def("set_roll_and_pitch_valid", &KMBinary::set_roll_and_pitch_valid, nb::arg("valid"))
        .def("set_heading_valid", &KMBinary::set_heading_valid, nb::arg("valid"))
        .def("set_heave_valid", &KMBinary::set_heave_valid, nb::arg("valid"))
        .def("set_acceleration_valid", &KMBinary::set_acceleration_valid, nb::arg("valid"))
        .def("set_delayed_heave1_valid", &KMBinary::set_delayed_heave1_valid, nb::arg("valid"))
        .def("set_delayed_heave2_valid", &KMBinary::set_delayed_heave2_valid, nb::arg("valid"))

        .def("set_horizontal_position_and_velocity_reduced_performance",
             &KMBinary::set_horizontal_position_and_velocity_reduced_performance,
             nb::arg("reduced_performance"))
        .def("set_roll_and_pitch_reduced_performance",
             &KMBinary::set_roll_and_pitch_reduced_performance,
             nb::arg("reduced_performance"))
        .def("set_heading_reduced_performance",
             &KMBinary::set_heading_reduced_performance,
             nb::arg("reduced_performance"))
        .def("set_heave_reduced_performance",
             &KMBinary::set_heave_reduced_performance,
             nb::arg("reduced_performance"))
        .def("set_acceleration_reduced_performance",
             &KMBinary::set_acceleration_reduced_performance,
             nb::arg("reduced_performance"))
        .def("set_delayed_heave1_reduced_performance",
             &KMBinary::set_delayed_heave1_reduced_performance,
             nb::arg("reduced_performance"))
        .def("set_delayed_heave2_reduced_performance",
             &KMBinary::set_delayed_heave2_reduced_performance,
             nb::arg("reduced_performance"))

        // copy
        __PYCLASS_DEFAULT_COPY__(KMBinary)
        // print
        __PYCLASS_DEFAULT_PRINTING__(KMBinary)
        // end
        ;

    nb::class_<KMDelayedHeave>(m, "KMDelayedHeave", "KM Binary delayed heave sample")
        .def(nb::init<>())
        .def_rw("time_sec", &KMDelayedHeave::time_sec)
        .def_rw("time_nanosec", &KMDelayedHeave::time_nanosec)
        .def_rw("delayed_heave_m", &KMDelayedHeave::delayed_heave_m)

        // copy
        __PYCLASS_DEFAULT_COPY__(KMDelayedHeave)
        // print
        __PYCLASS_DEFAULT_PRINTING__(KMDelayedHeave)
        // end
        ;

    nb::class_<SKMSample>(m, "SKMSample", "KM Binary composite sample")
        .def(nb::init<>())
        .def_rw("km_binary", &SKMSample::km_binary)
        .def_rw("km_delayed_heave", &SKMSample::km_delayed_heave)

        // copy
        __PYCLASS_DEFAULT_COPY__(SKMSample)
        // print
        __PYCLASS_DEFAULT_PRINTING__(SKMSample)
        // end
        ;

    nb::class_<SKMBinary, datagrams::KMALLDatagram>(
        m, "SKMBinary", DOC(themachinethatgoesping, echosounders, kmall, datagrams, SKMBinary))
        .def(nb::init<>(), DOC_SKMBinary(SKMBinary))

        // --- convenient data access ---
        .def("get_bytes_content", &SKMBinary::get_bytes_content, DOC_SKMBinary(get_bytes_content))
        .def("get_sensor_system", &SKMBinary::get_sensor_system, DOC_SKMBinary(get_sensor_system))
        .def("get_sensor_status", &SKMBinary::get_sensor_status, DOC_SKMBinary(get_sensor_status))
        .def("get_sensor_format", &SKMBinary::get_sensor_format, DOC_SKMBinary(get_sensor_format))
        .def("get_number_of_samples",
             &SKMBinary::get_number_of_samples,
             DOC_SKMBinary(get_number_of_samples))
        .def("get_number_of_bytes_per_sample",
             &SKMBinary::get_number_of_bytes_per_sample,
             DOC_SKMBinary(get_number_of_bytes_per_sample))
        .def("get_sensor_data_contents",
             &SKMBinary::get_sensor_data_contents,
             DOC_SKMBinary(get_sensor_data_contents))
        .def("get_sensor_data", &SKMBinary::get_sensor_data, DOC_SKMBinary(get_sensor_data))
        .def("get_bytes_datagram_check",
             &SKMBinary::get_bytes_datagram_check,
             DOC_SKMBinary(get_bytes_datagram_check))
        .def("set_bytes_content",
             &SKMBinary::set_bytes_content,
             DOC_SKMBinary(set_bytes_content),
             nb::arg("value"))
        .def("set_sensor_system",
             &SKMBinary::set_sensor_system,
             DOC_SKMBinary(set_sensor_system),
             nb::arg("value"))
        .def("set_sensor_status",
             &SKMBinary::set_sensor_status,
             DOC_SKMBinary(set_sensor_status),
             nb::arg("value"))
        .def("set_sensor_format",
             &SKMBinary::set_sensor_format,
             DOC_SKMBinary(set_sensor_format),
             nb::arg("value"))
        .def("set_number_of_samples",
             &SKMBinary::set_number_of_samples,
             DOC_SKMBinary(set_number_of_samples),
             nb::arg("value"))
        .def("set_number_of_bytes_per_sample",
             &SKMBinary::set_number_of_bytes_per_sample,
             DOC_SKMBinary(set_number_of_bytes_per_sample),
             nb::arg("value"))
        .def("set_sensor_data_contents",
             &SKMBinary::set_sensor_data_contents,
             DOC_SKMBinary(set_sensor_data_contents),
             nb::arg("value"))
        .def("set_sensor_data",
             &SKMBinary::set_sensor_data,
             DOC_SKMBinary(set_sensor_data),
             nb::arg("data"))
        .def("set_bytes_datagram_check",
             &SKMBinary::set_bytes_datagram_check,
             DOC_SKMBinary(set_bytes_datagram_check),
             nb::arg("value"))

        // --- processed data access ---
        .def("get_horizontal_position_and_velocity_active",
             &SKMBinary::get_horizontal_position_and_velocity_active,
             DOC_SKMBinary(get_horizontal_position_and_velocity_active))
        .def("get_roll_and_pitch_active",
             &SKMBinary::get_roll_and_pitch_active,
             DOC_SKMBinary(get_roll_and_pitch_active))
        .def(
            "get_heading_active", &SKMBinary::get_heading_active, DOC_SKMBinary(get_heading_active))
        .def("get_heave_active", &SKMBinary::get_heave_active, DOC_SKMBinary(get_heave_active))
        .def("get_acceleration_active",
             &SKMBinary::get_acceleration_active,
             DOC_SKMBinary(get_acceleration_active))
        .def("get_delayed_heave1_active",
             &SKMBinary::get_delayed_heave1_active,
             DOC_SKMBinary(get_delayed_heave1_active))
        .def("get_delayed_heave2_active",
             &SKMBinary::get_delayed_heave2_active,
             DOC_SKMBinary(get_delayed_heave2_active))

        .def("set_horizontal_position_and_velocity_active",
             &SKMBinary::set_horizontal_position_and_velocity_active,
             DOC_SKMBinary(set_horizontal_position_and_velocity_active),
             nb::arg("active"))
        .def("set_roll_and_pitch_active",
             &SKMBinary::set_roll_and_pitch_active,
             DOC_SKMBinary(set_roll_and_pitch_active),
             nb::arg("active"))
        .def("set_heading_active",
             &SKMBinary::set_heading_active,
             DOC_SKMBinary(set_heading_active),
             nb::arg("active"))
        .def("set_heave_active",
             &SKMBinary::set_heave_active,
             DOC_SKMBinary(set_heave_active),
             nb::arg("active"))
        .def("set_acceleration_active",
             &SKMBinary::set_acceleration_active,
             DOC_SKMBinary(set_acceleration_active),
             nb::arg("active"))
        .def("set_delayed_heave1_active",
             &SKMBinary::set_delayed_heave1_active,
             DOC_SKMBinary(set_delayed_heave1_active),
             nb::arg("active"))
        .def("set_delayed_heave2_active",
             &SKMBinary::set_delayed_heave2_active,
             DOC_SKMBinary(set_delayed_heave2_active),
             nb::arg("active"))

        // ----- operators -----
        .def("__eq__", &SKMBinary::operator==, DOC_SKMBinary(operator_eq), nb::arg("other"))

        // ----- pybind macros -----
        __PYCLASS_DEFAULT_COPY__(SKMBinary) __PYCLASS_DEFAULT_BINARY__(SKMBinary)
            __PYCLASS_DEFAULT_PRINTING__(SKMBinary);
}

} // namespace py_datagrams
} // namespace py_kmall
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
