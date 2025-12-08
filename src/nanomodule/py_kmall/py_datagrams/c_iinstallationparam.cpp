// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/map.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/iinstallationparam.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::IInstallationParam;

#define DOC_IInstallationParam(ARG)                                                                \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, IInstallationParam, ARG)

void init_c_iinstallationparam(nanobind::module_& m)
{
    nb::class_<IInstallationParam, datagrams::KMALLDatagram>(
        m,
        "IInstallationParam",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, IInstallationParam))
        .def(nb::init<>(), DOC_IInstallationParam(IInstallationParam))

        // --- convenient data access ---
        .def("get_bytes_content",
             &IInstallationParam::get_bytes_content,
             DOC_IInstallationParam(get_bytes_content))
        .def("get_info", &IInstallationParam::get_info, DOC_IInstallationParam(get_info))
        .def("get_status", &IInstallationParam::get_status, DOC_IInstallationParam(get_status))
        .def("get_install_txt",
             &IInstallationParam::get_install_txt,
             DOC_IInstallationParam(get_install_txt))
        .def("set_info",
             &IInstallationParam::set_info,
             DOC_IInstallationParam(set_info),
             nb::arg("info"))
        .def("set_status",
             &IInstallationParam::set_status,
             DOC_IInstallationParam(set_status),
             nb::arg("status"))
        .def("set_install_txt",
             &IInstallationParam::set_install_txt,
             DOC_IInstallationParam(set_install_txt),
             nb::arg("install_txt"))

        .def("get_bytes_datagram_check",
             &IInstallationParam::get_bytes_datagram_check,
             DOC_IInstallationParam(get_bytes_datagram_check))

        // --- processed data access ---
        .def("get_install_txt_decoded",
             &IInstallationParam::get_install_txt_decoded,
             DOC_IInstallationParam(get_install_txt_decoded))
        .def_static("decode_install_txt",
                    &IInstallationParam::decode_install_txt,
                    DOC_IInstallationParam(decode_install_txt),
                    nb::arg("install_txt"))
        .def_static("get_install_txt_key_info",
                    &IInstallationParam::get_install_txt_key_info,
                    DOC_IInstallationParam(get_install_txt_key_info),
                    nb::arg("key"))
        .def_static("get_install_txt_key_infos",
                    &IInstallationParam::get_install_txt_key_infos,
                    DOC_IInstallationParam(get_install_txt_key_infos))

        // --- sensor offset access ---
        .def_static("parse_sensor_string",
                    &IInstallationParam::parse_sensor_string,
                    DOC_IInstallationParam(parse_sensor_string),
                    nb::arg("sensor_string"))
        .def("get_transducer_offsets",
             &IInstallationParam::get_transducer_offsets,
             DOC_IInstallationParam(get_transducer_offsets),
             nb::arg("transducer_key"))
        .def("get_position_system_offsets",
             &IInstallationParam::get_position_system_offsets,
             DOC_IInstallationParam(get_position_system_offsets),
             nb::arg("position_system_number"))
        .def("get_attitude_sensor_offsets",
             &IInstallationParam::get_attitude_sensor_offsets,
             DOC_IInstallationParam(get_attitude_sensor_offsets),
             nb::arg("sensor_number"))
        .def("get_depth_sensor_offsets",
             &IInstallationParam::get_depth_sensor_offsets,
             DOC_IInstallationParam(get_depth_sensor_offsets))
        .def("get_water_line_vertical_location_in_meters",
             &IInstallationParam::get_water_line_vertical_location_in_meters,
             DOC_IInstallationParam(get_water_line_vertical_location_in_meters))
        .def("get_active_position_system_number",
             &IInstallationParam::get_active_position_system_number,
             DOC_IInstallationParam(get_active_position_system_number))
        .def("get_active_attitude_sensor_number",
             &IInstallationParam::get_active_attitude_sensor_number,
             DOC_IInstallationParam(get_active_attitude_sensor_number))
        .def("get_system_name",
             &IInstallationParam::get_system_name,
             DOC_IInstallationParam(get_system_name))
        .def("get_pu_serial_number",
             &IInstallationParam::get_pu_serial_number,
             DOC_IInstallationParam(get_pu_serial_number))
        .def("get_available_transducer_keys",
             &IInstallationParam::get_available_transducer_keys,
             DOC_IInstallationParam(get_available_transducer_keys))
        .def("has_transducer_key",
             &IInstallationParam::has_transducer_key,
             DOC_IInstallationParam(has_transducer_key),
             nb::arg("key"))

        // ----- operators -----
        .def("__eq__",
             &IInstallationParam::operator==,
             DOC_IInstallationParam(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(IInstallationParam)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(IInstallationParam)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(IInstallationParam)
        // end LinearInterpolator
        ;
}
}
}
}
}
}