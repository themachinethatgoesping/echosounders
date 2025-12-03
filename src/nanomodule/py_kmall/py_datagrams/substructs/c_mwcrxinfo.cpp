// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mwcrxinfo.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::substructs::MWCRxInfo;

#define DOC_MWCRxInfo(ARG)                                                                           \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, substructs, MWCRxInfo, ARG)

void init_c_mwcrxinfo(nanobind::module_& m)
{
    nb::class_<MWCRxInfo>(m, "MWCRxInfo", DOC_MWCRxInfo(MWCRxInfo))
        .def(nb::init<>(), DOC_MWCRxInfo(MWCRxInfo))
        .def("get_bytes_content",
             &MWCRxInfo::get_bytes_content,
             DOC_MWCRxInfo(get_bytes_content))
        .def("set_bytes_content",
             &MWCRxInfo::set_bytes_content,
             DOC_MWCRxInfo(set_bytes_content),
             nb::arg("val"))
        .def("get_number_of_beams",
             &MWCRxInfo::get_number_of_beams,
             DOC_MWCRxInfo(get_number_of_beams))
        .def("set_number_of_beams",
             &MWCRxInfo::set_number_of_beams,
             DOC_MWCRxInfo(set_number_of_beams),
             nb::arg("val"))
        .def("get_number_bytes_per_beam_entry",
             &MWCRxInfo::get_number_bytes_per_beam_entry,
             DOC_MWCRxInfo(get_number_bytes_per_beam_entry))
        .def("set_number_bytes_per_beam_entry",
             &MWCRxInfo::set_number_bytes_per_beam_entry,
             DOC_MWCRxInfo(set_number_bytes_per_beam_entry),
             nb::arg("val"))
        .def("get_phase_flag",
             &MWCRxInfo::get_phase_flag,
             DOC_MWCRxInfo(get_phase_flag))
        .def("set_phase_flag",
             &MWCRxInfo::set_phase_flag,
             DOC_MWCRxInfo(set_phase_flag),
             nb::arg("val"))
        .def("get_tvg_function_applied",
             &MWCRxInfo::get_tvg_function_applied,
             DOC_MWCRxInfo(get_tvg_function_applied))
        .def("set_tvg_function_applied",
             &MWCRxInfo::set_tvg_function_applied,
             DOC_MWCRxInfo(set_tvg_function_applied),
             nb::arg("val"))
        .def("get_tvg_offset_db",
             &MWCRxInfo::get_tvg_offset_db,
             DOC_MWCRxInfo(get_tvg_offset_db))
        .def("set_tvg_offset_db",
             &MWCRxInfo::set_tvg_offset_db,
             DOC_MWCRxInfo(set_tvg_offset_db),
             nb::arg("val"))
        .def("get_sample_freq_hz",
             &MWCRxInfo::get_sample_freq_hz,
             DOC_MWCRxInfo(get_sample_freq_hz))
        .def("set_sample_freq_hz",
             &MWCRxInfo::set_sample_freq_hz,
             DOC_MWCRxInfo(set_sample_freq_hz),
             nb::arg("val"))
        .def("get_sound_velocity_m_per_sec",
             &MWCRxInfo::get_sound_velocity_m_per_sec,
             DOC_MWCRxInfo(get_sound_velocity_m_per_sec))
        .def("set_sound_velocity_m_per_sec",
             &MWCRxInfo::set_sound_velocity_m_per_sec,
             DOC_MWCRxInfo(set_sound_velocity_m_per_sec),
             nb::arg("val"))
        .def("__eq__",
             &MWCRxInfo::operator==,
             DOC_MWCRxInfo(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(MWCRxInfo)
        __PYCLASS_DEFAULT_PRINTING__(MWCRxInfo);
}

}
}
}
}
}
