// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/array.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/enumhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/soundvelocityprofile.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::SoundVelocityProfile;

#define DOC_SoundVelocityProfile(ARG)                                                              \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, SoundVelocityProfile, ARG)
#define DOC_SoundVelocityProfileSensorFormat(ARG)                                                  \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kmall,                                                                                     \
        datagrams,                                                                                 \
        SoundVelocityProfile,                                                                      \
        t_sensor_format,                                                                           \
        ARG)

void init_c_soundvelocityprofile(nanobind::module_& m)
{
    using SVPPoint        = SoundVelocityProfile::SVPPoint;
    using t_sensor_format = SoundVelocityProfile::t_sensor_format;
    using o_sensor_format = SoundVelocityProfile::o_sensor_format;

    nb::enum_<t_sensor_format>(
        m, "SoundVelocityProfile_t_sensor_format", DOC_SoundVelocityProfile(t_sensor_format))
        .value("sound_velocity_profile",
               t_sensor_format::sound_velocity_profile,
               DOC_SoundVelocityProfileSensorFormat(sound_velocity_profile))
        .value("ctd_profile",
               t_sensor_format::ctd_profile,
               DOC_SoundVelocityProfileSensorFormat(ctd_profile))
        // end
        ;

    themachinethatgoesping::tools::nanobind_helper::make_option_class<o_sensor_format>(
        m, "SoundVelocityProfile_o_sensor_format");

    nb::class_<SVPPoint>(m, "SVPPoint", "Sound velocity profile sample point")
        .def(nb::init<>())
        .def_rw("depth_m", &SVPPoint::depth_m)
        .def_rw("soundVelocity_m_per_sec", &SVPPoint::soundVelocity_m_per_sec)
        .def_rw("padding", &SVPPoint::padding)
        .def_rw("temp_c", &SVPPoint::temp_c)
        .def_rw("salinity", &SVPPoint::salinity)

        // default copy
        __PYCLASS_DEFAULT_COPY__(SVPPoint)
        // default printing
        __PYCLASS_DEFAULT_PRINTING__(SVPPoint);
    ;

    nb::class_<SoundVelocityProfile, datagrams::KMALLDatagram>(
        m,
        "SoundVelocityProfile",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, SoundVelocityProfile))
        .def(nb::init<>(), DOC_SoundVelocityProfile(SoundVelocityProfile))

        // --- convenient data access ---
        .def("get_bytes_content",
             &SoundVelocityProfile::get_bytes_content,
             DOC_SoundVelocityProfile(get_bytes_content))
        .def("get_number_of_samples",
             &SoundVelocityProfile::get_number_of_samples,
             DOC_SoundVelocityProfile(get_number_of_samples))
        .def("get_sensor_format",
             &SoundVelocityProfile::get_sensor_format,
             DOC_SoundVelocityProfile(get_sensor_format))
        .def("get_svp_time_sec",
             &SoundVelocityProfile::get_svp_time_sec,
             DOC_SoundVelocityProfile(get_svp_time_sec))
        .def("get_latitude_deg",
             &SoundVelocityProfile::get_latitude_deg,
             DOC_SoundVelocityProfile(get_latitude_deg))
        .def("get_longitude_deg",
             &SoundVelocityProfile::get_longitude_deg,
             DOC_SoundVelocityProfile(get_longitude_deg))
        .def("get_sensor_data",
             &SoundVelocityProfile::get_sensor_data,
             DOC_SoundVelocityProfile(get_sensor_data))
        .def("set_bytes_content",
             &SoundVelocityProfile::set_bytes_content,
             DOC_SoundVelocityProfile(set_bytes_content),
             nb::arg("value"))
        .def("set_number_of_samples",
             &SoundVelocityProfile::set_number_of_samples,
             DOC_SoundVelocityProfile(set_number_of_samples),
             nb::arg("value"))
        .def("set_sensor_format",
             &SoundVelocityProfile::set_sensor_format,
             DOC_SoundVelocityProfile(set_sensor_format),
             nb::arg("value"))
        .def("set_svp_time_sec",
             &SoundVelocityProfile::set_svp_time_sec,
             DOC_SoundVelocityProfile(set_svp_time_sec),
             nb::arg("value"))
        .def("set_latitude_deg",
             &SoundVelocityProfile::set_latitude_deg,
             DOC_SoundVelocityProfile(set_latitude_deg),
             nb::arg("value"))
        .def("set_longitude_deg",
             &SoundVelocityProfile::set_longitude_deg,
             DOC_SoundVelocityProfile(set_longitude_deg),
             nb::arg("value"))
        .def("set_sensor_data",
             &SoundVelocityProfile::set_sensor_data,
             DOC_SoundVelocityProfile(set_sensor_data),
             nb::arg("data"))
        .def("get_bytes_datagram_check",
             &SoundVelocityProfile::get_bytes_datagram_check,
             DOC_SoundVelocityProfile(get_bytes_datagram_check))
        .def("set_bytes_datagram_check",
             &SoundVelocityProfile::set_bytes_datagram_check,
             DOC_SoundVelocityProfile(set_bytes_datagram_check),
             nb::arg("value"))

        // ----- operators -----
        .def("__eq__",
             &SoundVelocityProfile::operator==,
             DOC_SoundVelocityProfile(operator_eq),
             nb::arg("other"))

        // ----- pybind macros -----
        // default copying
        __PYCLASS_DEFAULT_COPY__(SoundVelocityProfile)
        // default streaming
        __PYCLASS_DEFAULT_BINARY__(SoundVelocityProfile)
        // default printing
        __PYCLASS_DEFAULT_PRINTING__(SoundVelocityProfile);
}

} // namespace py_datagrams
} // namespace py_kmall
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
