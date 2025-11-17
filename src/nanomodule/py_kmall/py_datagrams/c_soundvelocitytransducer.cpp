// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/array.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/enumhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/soundvelocitytransducer.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::SoundVelocityTransducer;

#define DOC_SoundVelocityTransducer(ARG)                                                           \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, SoundVelocityTransducer, ARG)
#define DOC_SoundVelocityTransducerSensorFormat(ARG)                                               \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kmall,                                                                                     \
        datagrams,                                                                                 \
        SoundVelocityTransducer,                                                                   \
        t_sensor_format,                                                                           \
        ARG)

void init_c_soundvelocitytransducer(nanobind::module_& m)
{
    using SVTSample       = SoundVelocityTransducer::SVTSample;
    using t_sensor_format = SoundVelocityTransducer::t_sensor_format;
    using o_sensor_format = SoundVelocityTransducer::o_sensor_format;

    nb::enum_<t_sensor_format>(
        m, "SoundVelocityTransducer_t_sensor_format", DOC_SoundVelocityTransducer(t_sensor_format))
        .value("AML_NMEA",
               t_sensor_format::AML_NMEA,
               DOC_SoundVelocityTransducerSensorFormat(AML_NMEA))
        .value("AML_SV", t_sensor_format::AML_SV, DOC_SoundVelocityTransducerSensorFormat(AML_SV))
        .value(
            "AML_SVT", t_sensor_format::AML_SVT, DOC_SoundVelocityTransducerSensorFormat(AML_SVT))
        .value(
            "AML_SVP", t_sensor_format::AML_SVP, DOC_SoundVelocityTransducerSensorFormat(AML_SVP))
        .value("Micro_SV",
               t_sensor_format::Micro_SV,
               DOC_SoundVelocityTransducerSensorFormat(Micro_SV))
        .value("Micro_SVT",
               t_sensor_format::Micro_SVT,
               DOC_SoundVelocityTransducerSensorFormat(Micro_SVT))
        .value("Micro_SVP",
               t_sensor_format::Micro_SVP,
               DOC_SoundVelocityTransducerSensorFormat(Micro_SVP))
        .value("Valeport_MiniSVS",
               t_sensor_format::Valeport_MiniSVS,
               DOC_SoundVelocityTransducerSensorFormat(Valeport_MiniSVS))
        .value("KSSIS_80",
               t_sensor_format::KSSIS_80,
               DOC_SoundVelocityTransducerSensorFormat(KSSIS_80))
        .value("KSSIS_43",
               t_sensor_format::KSSIS_43,
               DOC_SoundVelocityTransducerSensorFormat(KSSIS_43))
        .value("XDR_S", t_sensor_format::XDR_S, DOC_SoundVelocityTransducerSensorFormat(XDR_S))
        .value("Valeport_NMEA",
               t_sensor_format::Valeport_NMEA,
               DOC_SoundVelocityTransducerSensorFormat(Valeport_NMEA))
        // end
        ;

    themachinethatgoesping::tools::nanobind_helper::make_option_class<o_sensor_format>(
        m, "SoundVelocityTransducer_o_sensor_format");

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

    nb::class_<SoundVelocityTransducer, datagrams::KMALLDatagram>(
        m,
        "SoundVelocityTransducer",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, SoundVelocityTransducer))
        .def(nb::init<>(), DOC_SoundVelocityTransducer(SoundVelocityTransducer))

        // --- convenient data access ---
        .def("get_bytes_content",
             &SoundVelocityTransducer::get_bytes_content,
             DOC_SoundVelocityTransducer(get_bytes_content))
        .def("get_sensor_status",
             &SoundVelocityTransducer::get_sensor_status,
             DOC_SoundVelocityTransducer(get_sensor_status))
        .def("get_sensor_input_format",
             &SoundVelocityTransducer::get_sensor_input_format,
             DOC_SoundVelocityTransducer(get_sensor_input_format))
        .def("get_number_of_samples",
             &SoundVelocityTransducer::get_number_of_samples,
             DOC_SoundVelocityTransducer(get_number_of_samples))
        .def("get_number_of_bytes_per_sample",
             &SoundVelocityTransducer::get_number_of_bytes_per_sample,
             DOC_SoundVelocityTransducer(get_number_of_bytes_per_sample))
        .def("get_sensor_data_contents",
             &SoundVelocityTransducer::get_sensor_data_contents,
             DOC_SoundVelocityTransducer(get_sensor_data_contents))
        .def("get_filter_time_sec",
             &SoundVelocityTransducer::get_filter_time_sec,
             DOC_SoundVelocityTransducer(get_filter_time_sec))
        .def("get_sound_velocity_offset_m_per_sec",
             &SoundVelocityTransducer::get_sound_velocity_offset_m_per_sec,
             DOC_SoundVelocityTransducer(get_sound_velocity_offset_m_per_sec))
        .def("get_sensor_data",
             &SoundVelocityTransducer::get_sensor_data,
             DOC_SoundVelocityTransducer(get_sensor_data))
        .def("set_bytes_content",
             &SoundVelocityTransducer::set_bytes_content,
             DOC_SoundVelocityTransducer(set_bytes_content),
             nb::arg("value"))
        .def("set_sensor_status",
             &SoundVelocityTransducer::set_sensor_status,
             DOC_SoundVelocityTransducer(set_sensor_status),
             nb::arg("value"))
        .def("set_sensor_input_format",
             &SoundVelocityTransducer::set_sensor_input_format,
             DOC_SoundVelocityTransducer(set_sensor_input_format),
             nb::arg("value"))
        .def("set_number_of_samples",
             &SoundVelocityTransducer::set_number_of_samples,
             DOC_SoundVelocityTransducer(set_number_of_samples),
             nb::arg("value"))
        .def("set_number_of_bytes_per_sample",
             &SoundVelocityTransducer::set_number_of_bytes_per_sample,
             DOC_SoundVelocityTransducer(set_number_of_bytes_per_sample),
             nb::arg("value"))
        .def("set_sensor_data_contents",
             &SoundVelocityTransducer::set_sensor_data_contents,
             DOC_SoundVelocityTransducer(set_sensor_data_contents),
             nb::arg("value"))
        .def("set_filter_time_sec",
             &SoundVelocityTransducer::set_filter_time_sec,
             DOC_SoundVelocityTransducer(set_filter_time_sec),
             nb::arg("value"))
        .def("set_sound_velocity_offset_m_per_sec",
             &SoundVelocityTransducer::set_sound_velocity_offset_m_per_sec,
             DOC_SoundVelocityTransducer(set_sound_velocity_offset_m_per_sec),
             nb::arg("value"))
        .def("set_sensor_data",
             &SoundVelocityTransducer::set_sensor_data,
             DOC_SoundVelocityTransducer(set_sensor_data),
             nb::arg("data"))
        .def("get_bytes_datagram_check",
             &SoundVelocityTransducer::get_bytes_datagram_check,
             DOC_SoundVelocityTransducer(get_bytes_datagram_check))
        .def("set_bytes_datagram_check",
             &SoundVelocityTransducer::set_bytes_datagram_check,
             DOC_SoundVelocityTransducer(set_bytes_datagram_check),
             nb::arg("value"))

        // --- processed data access ---
        .def("get_sound_velocity_active",
             &SoundVelocityTransducer::get_sound_velocity_active,
             DOC_SoundVelocityTransducer(get_sound_velocity_active))
        .def("get_temperature_active",
             &SoundVelocityTransducer::get_temperature_active,
             DOC_SoundVelocityTransducer(get_temperature_active))
        .def("get_pressure_active",
             &SoundVelocityTransducer::get_pressure_active,
             DOC_SoundVelocityTransducer(get_pressure_active))
        .def("get_salinity_active",
             &SoundVelocityTransducer::get_salinity_active,
             DOC_SoundVelocityTransducer(get_salinity_active))
        .def("set_sound_velocity_active",
             &SoundVelocityTransducer::set_sound_velocity_active,
             DOC_SoundVelocityTransducer(set_sound_velocity_active),
             nb::arg("active"))
        .def("set_temperature_active",
             &SoundVelocityTransducer::set_temperature_active,
             DOC_SoundVelocityTransducer(set_temperature_active),
             nb::arg("active"))
        .def("set_pressure_active",
             &SoundVelocityTransducer::set_pressure_active,
             DOC_SoundVelocityTransducer(set_pressure_active),
             nb::arg("active"))
        .def("set_salinity_active",
             &SoundVelocityTransducer::set_salinity_active,
             DOC_SoundVelocityTransducer(set_salinity_active),
             nb::arg("active"))
        .def("get_svt_timestamps",
             &SoundVelocityTransducer::get_svt_timestamps,
             DOC_SoundVelocityTransducer(get_svt_timestamps))
        .def("get_svt_sound_velocities",
             &SoundVelocityTransducer::get_svt_sound_velocities,
             DOC_SoundVelocityTransducer(get_svt_sound_velocities))
        .def("get_svt_temperatures",
             &SoundVelocityTransducer::get_svt_temperatures,
             DOC_SoundVelocityTransducer(get_svt_temperatures))
        .def("get_svt_pressures",
             &SoundVelocityTransducer::get_svt_pressures,
             DOC_SoundVelocityTransducer(get_svt_pressures))
        .def("get_svt_salinities",
             &SoundVelocityTransducer::get_svt_salinities,
             DOC_SoundVelocityTransducer(get_svt_salinities))

        // ----- operators -----
        .def("__eq__",
             &SoundVelocityTransducer::operator==,
             DOC_SoundVelocityTransducer(operator_eq),
             nb::arg("other"))

        // ----- pybind macros -----
        // default copying
        __PYCLASS_DEFAULT_COPY__(SoundVelocityTransducer)
        // default streaming
        __PYCLASS_DEFAULT_BINARY__(SoundVelocityTransducer)
        // default printing
        __PYCLASS_DEFAULT_PRINTING__(SoundVelocityTransducer);
}

} // namespace py_datagrams
} // namespace py_kmall
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
