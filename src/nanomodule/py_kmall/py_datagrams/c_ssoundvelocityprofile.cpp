// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/array.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/enumhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/ssoundvelocityprofile.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::SSoundVelocityProfile;

#define DOC_SSoundVelocityProfile(ARG)                                                              \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, SSoundVelocityProfile, ARG)
#define DOC_SSoundVelocityProfileSensorFormat(ARG)                                                  \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kmall,                                                                                     \
        datagrams,                                                                                 \
        SSoundVelocityProfile,                                                                      \
        t_sensor_format,                                                                           \
        ARG)

void init_c_ssoundvelocityprofile(nanobind::module_& m)
{
    using SVPPoint        = SSoundVelocityProfile::SVPPoint;
    using t_sensor_format = SSoundVelocityProfile::t_sensor_format;
    using o_sensor_format = SSoundVelocityProfile::o_sensor_format;

    nb::enum_<t_sensor_format>(
        m, "SSoundVelocityProfile_t_sensor_format", DOC_SSoundVelocityProfile(t_sensor_format))
        .value("sound_velocity_profile",
               t_sensor_format::sound_velocity_profile,
               DOC_SSoundVelocityProfileSensorFormat(sound_velocity_profile))
        .value("ctd_profile",
               t_sensor_format::ctd_profile,
               DOC_SSoundVelocityProfileSensorFormat(ctd_profile))
        // end
        ;

    themachinethatgoesping::tools::nanobind_helper::make_option_class<o_sensor_format>(
        m, "SSoundVelocityProfile_o_sensor_format");

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

    nb::class_<SSoundVelocityProfile, datagrams::KMALLDatagram>(
        m,
        "SSoundVelocityProfile",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, SSoundVelocityProfile))
        .def(nb::init<>(), DOC_SSoundVelocityProfile(SSoundVelocityProfile))

        // --- convenient data access ---
        .def("get_bytes_content",
             &SSoundVelocityProfile::get_bytes_content,
             DOC_SSoundVelocityProfile(get_bytes_content))
        .def("get_number_of_samples",
             &SSoundVelocityProfile::get_number_of_samples,
             DOC_SSoundVelocityProfile(get_number_of_samples))
        .def("get_sensor_format",
             &SSoundVelocityProfile::get_sensor_format,
             DOC_SSoundVelocityProfile(get_sensor_format))
        .def("get_svp_time_sec",
             &SSoundVelocityProfile::get_svp_time_sec,
             DOC_SSoundVelocityProfile(get_svp_time_sec))
        .def("get_latitude_deg",
             &SSoundVelocityProfile::get_latitude_deg,
             DOC_SSoundVelocityProfile(get_latitude_deg))
        .def("get_longitude_deg",
             &SSoundVelocityProfile::get_longitude_deg,
             DOC_SSoundVelocityProfile(get_longitude_deg))
        .def("get_sensor_data",
             &SSoundVelocityProfile::get_sensor_data,
             DOC_SSoundVelocityProfile(get_sensor_data))
        .def("set_bytes_content",
             &SSoundVelocityProfile::set_bytes_content,
             DOC_SSoundVelocityProfile(set_bytes_content),
             nb::arg("value"))
        .def("set_number_of_samples",
             &SSoundVelocityProfile::set_number_of_samples,
             DOC_SSoundVelocityProfile(set_number_of_samples),
             nb::arg("value"))
        .def("set_sensor_format",
             &SSoundVelocityProfile::set_sensor_format,
             DOC_SSoundVelocityProfile(set_sensor_format),
             nb::arg("value"))
        .def("set_svp_time_sec",
             &SSoundVelocityProfile::set_svp_time_sec,
             DOC_SSoundVelocityProfile(set_svp_time_sec),
             nb::arg("value"))
        .def("set_latitude_deg",
             &SSoundVelocityProfile::set_latitude_deg,
             DOC_SSoundVelocityProfile(set_latitude_deg),
             nb::arg("value"))
        .def("set_longitude_deg",
             &SSoundVelocityProfile::set_longitude_deg,
             DOC_SSoundVelocityProfile(set_longitude_deg),
             nb::arg("value"))
        .def("set_sensor_data",
             &SSoundVelocityProfile::set_sensor_data,
             DOC_SSoundVelocityProfile(set_sensor_data),
             nb::arg("data"))
        .def("get_bytes_datagram_check",
             &SSoundVelocityProfile::get_bytes_datagram_check,
             DOC_SSoundVelocityProfile(get_bytes_datagram_check))
        .def("set_bytes_datagram_check",
             &SSoundVelocityProfile::set_bytes_datagram_check,
             DOC_SSoundVelocityProfile(set_bytes_datagram_check),
             nb::arg("value"))

        // --- processed data access ---
        .def("get_svp_depths",
             &SSoundVelocityProfile::get_svp_depths,
             DOC_SSoundVelocityProfile(get_svp_depths))
        .def("get_svp_sound_velocities",
             &SSoundVelocityProfile::get_svp_sound_velocities,
             DOC_SSoundVelocityProfile(get_svp_sound_velocities))
        .def("get_svp_sound_velocities_computed",
             &SSoundVelocityProfile::get_svp_sound_velocities_computed,
             DOC_SSoundVelocityProfile(get_svp_sound_velocities_computed))
        .def("get_svp_absorption_computed",
             &SSoundVelocityProfile::get_svp_absorption_computed,
             DOC_SSoundVelocityProfile(get_svp_absorption_computed),
             nb::arg("frequency"),
             nb::arg("ph") = 8)
        .def("get_svp_salinities",
             &SSoundVelocityProfile::get_svp_salinities,
             DOC_SSoundVelocityProfile(get_svp_salinities))
        .def("get_svp_temperatures",
             &SSoundVelocityProfile::get_svp_temperatures,
             DOC_SSoundVelocityProfile(get_svp_temperatures))

        // ----- operators -----
        .def("__eq__",
             &SSoundVelocityProfile::operator==,
             DOC_SSoundVelocityProfile(operator_eq),
             nb::arg("other"))

        // ----- pybind macros -----
        // default copying
        __PYCLASS_DEFAULT_COPY__(SSoundVelocityProfile)
        // default streaming
        __PYCLASS_DEFAULT_BINARY__(SSoundVelocityProfile)
        // default printing
        __PYCLASS_DEFAULT_PRINTING__(SSoundVelocityProfile);
}

} // namespace py_datagrams
} // namespace py_kmall
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
