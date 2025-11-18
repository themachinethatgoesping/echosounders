// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/array.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/enumhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/ssoundvelocitytransducer.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::SSoundVelocityTransducer;

#define DOC_SSoundVelocityTransducer(ARG)                                                           \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, SSoundVelocityTransducer, ARG)
#define DOC_SSoundVelocityTransducerSensorFormat(ARG)                                               \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kmall,                                                                                     \
        datagrams,                                                                                 \
        SSoundVelocityTransducer,                                                                   \
        t_sensor_format,                                                                           \
        ARG)

void init_c_ssoundvelocitytransducer(nanobind::module_& m)
{
    using SVTSample       = SSoundVelocityTransducer::SVTSample;
    using t_sensor_format = SSoundVelocityTransducer::t_sensor_format;
    using o_sensor_format = SSoundVelocityTransducer::o_sensor_format;

    nb::enum_<t_sensor_format>(
        m, "SSoundVelocityTransducer_t_sensor_format", DOC_SSoundVelocityTransducer(t_sensor_format))
        .value("AML_NMEA",
               t_sensor_format::AML_NMEA,
               DOC_SSoundVelocityTransducerSensorFormat(AML_NMEA))
        .value("AML_SV", t_sensor_format::AML_SV, DOC_SSoundVelocityTransducerSensorFormat(AML_SV))
        .value(
            "AML_SVT", t_sensor_format::AML_SVT, DOC_SSoundVelocityTransducerSensorFormat(AML_SVT))
        .value(
            "AML_SVP", t_sensor_format::AML_SVP, DOC_SSoundVelocityTransducerSensorFormat(AML_SVP))
        .value("Micro_SV",
               t_sensor_format::Micro_SV,
               DOC_SSoundVelocityTransducerSensorFormat(Micro_SV))
        .value("Micro_SVT",
               t_sensor_format::Micro_SVT,
               DOC_SSoundVelocityTransducerSensorFormat(Micro_SVT))
        .value("Micro_SVP",
               t_sensor_format::Micro_SVP,
               DOC_SSoundVelocityTransducerSensorFormat(Micro_SVP))
        .value("Valeport_MiniSVS",
               t_sensor_format::Valeport_MiniSVS,
               DOC_SSoundVelocityTransducerSensorFormat(Valeport_MiniSVS))
        .value("KSSIS_80",
               t_sensor_format::KSSIS_80,
               DOC_SSoundVelocityTransducerSensorFormat(KSSIS_80))
        .value("KSSIS_43",
               t_sensor_format::KSSIS_43,
               DOC_SSoundVelocityTransducerSensorFormat(KSSIS_43))
        .value("XDR_S", t_sensor_format::XDR_S, DOC_SSoundVelocityTransducerSensorFormat(XDR_S))
        .value("Valeport_NMEA",
               t_sensor_format::Valeport_NMEA,
               DOC_SSoundVelocityTransducerSensorFormat(Valeport_NMEA))
        // end
        ;

    themachinethatgoesping::tools::nanobind_helper::make_option_class<o_sensor_format>(
        m, "SSoundVelocityTransducer_o_sensor_format");

    nb::class_<SVTSample>(m, "SVTSample", "Sound velocity transducer sample point")
        .def(nb::init<>())
        .def_rw("time_sec", &SVTSample::time_sec)
        .def_rw("time_nanosec", &SVTSample::time_nanosec)
        .def_rw("soundVelocity_m_per_sec", &SVTSample::soundVelocity_m_per_sec)
        .def_rw("temp_c", &SVTSample::temp_c)
        .def_rw("pressure_pa", &SVTSample::pressure_pa)
        .def_rw("salinity", &SVTSample::salinity)

        // default copy
        __PYCLASS_DEFAULT_COPY__(SVTSample)
        // default printing
        __PYCLASS_DEFAULT_PRINTING__(SVTSample);
    ;

    nb::class_<SSoundVelocityTransducer, datagrams::KMALLDatagram>(
        m,
        "SSoundVelocityTransducer",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, SSoundVelocityTransducer))
        .def(nb::init<>(), DOC_SSoundVelocityTransducer(SSoundVelocityTransducer))

        // --- convenient data access ---
        .def("get_bytes_content",
             &SSoundVelocityTransducer::get_bytes_content,
             DOC_SSoundVelocityTransducer(get_bytes_content))
        .def("get_sensor_status",
             &SSoundVelocityTransducer::get_sensor_status,
             DOC_SSoundVelocityTransducer(get_sensor_status))
        .def("get_sensor_input_format",
             &SSoundVelocityTransducer::get_sensor_input_format,
             DOC_SSoundVelocityTransducer(get_sensor_input_format))
        .def("get_number_of_samples",
             &SSoundVelocityTransducer::get_number_of_samples,
             DOC_SSoundVelocityTransducer(get_number_of_samples))
        .def("get_number_of_bytes_per_sample",
             &SSoundVelocityTransducer::get_number_of_bytes_per_sample,
             DOC_SSoundVelocityTransducer(get_number_of_bytes_per_sample))
        .def("get_sensor_data_contents",
             &SSoundVelocityTransducer::get_sensor_data_contents,
             DOC_SSoundVelocityTransducer(get_sensor_data_contents))
        .def("get_filter_time_sec",
             &SSoundVelocityTransducer::get_filter_time_sec,
             DOC_SSoundVelocityTransducer(get_filter_time_sec))
        .def("get_sound_velocity_offset_m_per_sec",
             &SSoundVelocityTransducer::get_sound_velocity_offset_m_per_sec,
             DOC_SSoundVelocityTransducer(get_sound_velocity_offset_m_per_sec))
        .def("get_sensor_data",
             &SSoundVelocityTransducer::get_sensor_data,
             DOC_SSoundVelocityTransducer(get_sensor_data))
        .def("set_bytes_content",
             &SSoundVelocityTransducer::set_bytes_content,
             DOC_SSoundVelocityTransducer(set_bytes_content),
             nb::arg("value"))
        .def("set_sensor_status",
             &SSoundVelocityTransducer::set_sensor_status,
             DOC_SSoundVelocityTransducer(set_sensor_status),
             nb::arg("value"))
        .def("set_sensor_input_format",
             &SSoundVelocityTransducer::set_sensor_input_format,
             DOC_SSoundVelocityTransducer(set_sensor_input_format),
             nb::arg("value"))
        .def("set_number_of_samples",
             &SSoundVelocityTransducer::set_number_of_samples,
             DOC_SSoundVelocityTransducer(set_number_of_samples),
             nb::arg("value"))
        .def("set_number_of_bytes_per_sample",
             &SSoundVelocityTransducer::set_number_of_bytes_per_sample,
             DOC_SSoundVelocityTransducer(set_number_of_bytes_per_sample),
             nb::arg("value"))
        .def("set_sensor_data_contents",
             &SSoundVelocityTransducer::set_sensor_data_contents,
             DOC_SSoundVelocityTransducer(set_sensor_data_contents),
             nb::arg("value"))
        .def("set_filter_time_sec",
             &SSoundVelocityTransducer::set_filter_time_sec,
             DOC_SSoundVelocityTransducer(set_filter_time_sec),
             nb::arg("value"))
        .def("set_sound_velocity_offset_m_per_sec",
             &SSoundVelocityTransducer::set_sound_velocity_offset_m_per_sec,
             DOC_SSoundVelocityTransducer(set_sound_velocity_offset_m_per_sec),
             nb::arg("value"))
        .def("set_sensor_data",
             &SSoundVelocityTransducer::set_sensor_data,
             DOC_SSoundVelocityTransducer(set_sensor_data),
             nb::arg("data"))
        .def("get_bytes_datagram_check",
             &SSoundVelocityTransducer::get_bytes_datagram_check,
             DOC_SSoundVelocityTransducer(get_bytes_datagram_check))
        .def("set_bytes_datagram_check",
             &SSoundVelocityTransducer::set_bytes_datagram_check,
             DOC_SSoundVelocityTransducer(set_bytes_datagram_check),
             nb::arg("value"))

        // --- processed data access ---
        .def("get_sound_velocity_active",
             &SSoundVelocityTransducer::get_sound_velocity_active,
             DOC_SSoundVelocityTransducer(get_sound_velocity_active))
        .def("get_temperature_active",
             &SSoundVelocityTransducer::get_temperature_active,
             DOC_SSoundVelocityTransducer(get_temperature_active))
        .def("get_pressure_active",
             &SSoundVelocityTransducer::get_pressure_active,
             DOC_SSoundVelocityTransducer(get_pressure_active))
        .def("get_salinity_active",
             &SSoundVelocityTransducer::get_salinity_active,
             DOC_SSoundVelocityTransducer(get_salinity_active))
        .def("set_sound_velocity_active",
             &SSoundVelocityTransducer::set_sound_velocity_active,
             DOC_SSoundVelocityTransducer(set_sound_velocity_active),
             nb::arg("active"))
        .def("set_temperature_active",
             &SSoundVelocityTransducer::set_temperature_active,
             DOC_SSoundVelocityTransducer(set_temperature_active),
             nb::arg("active"))
        .def("set_pressure_active",
             &SSoundVelocityTransducer::set_pressure_active,
             DOC_SSoundVelocityTransducer(set_pressure_active),
             nb::arg("active"))
        .def("set_salinity_active",
             &SSoundVelocityTransducer::set_salinity_active,
             DOC_SSoundVelocityTransducer(set_salinity_active),
             nb::arg("active"))
        .def("get_svt_timestamps",
             &SSoundVelocityTransducer::get_svt_timestamps,
             DOC_SSoundVelocityTransducer(get_svt_timestamps))
        .def("get_svt_sound_velocities",
             &SSoundVelocityTransducer::get_svt_sound_velocities,
             DOC_SSoundVelocityTransducer(get_svt_sound_velocities))
        .def("get_svt_temperatures",
             &SSoundVelocityTransducer::get_svt_temperatures,
             DOC_SSoundVelocityTransducer(get_svt_temperatures))
        .def("get_svt_pressures",
             &SSoundVelocityTransducer::get_svt_pressures,
             DOC_SSoundVelocityTransducer(get_svt_pressures))
        .def("get_svt_salinities",
             &SSoundVelocityTransducer::get_svt_salinities,
             DOC_SSoundVelocityTransducer(get_svt_salinities))

        // ----- operators -----
        .def("__eq__",
             &SSoundVelocityTransducer::operator==,
             DOC_SSoundVelocityTransducer(operator_eq),
             nb::arg("other"))

        // ----- pybind macros -----
        // default copying
        __PYCLASS_DEFAULT_COPY__(SSoundVelocityTransducer)
        // default streaming
        __PYCLASS_DEFAULT_BINARY__(SSoundVelocityTransducer)
        // default printing
        __PYCLASS_DEFAULT_PRINTING__(SSoundVelocityTransducer);
}

} // namespace py_datagrams
} // namespace py_kmall
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
