// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/bind_vector.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mrzsectorinfo.hpp>

#include "../module.hpp"

NB_MAKE_OPAQUE(
    std::vector<themachinethatgoesping::echosounders::kmall::datagrams::substructs::MRZSectorInfo>);
namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::substructs::MRZSectorInfo;

#define DOC_MRZSectorInfo(ARG)                                                                     \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, substructs, MRZSectorInfo, ARG)

void init_c_mrzsectorinfo(nanobind::module_& m)
{
    nb::class_<MRZSectorInfo>(m, "MRZSectorInfo", DOC_MRZSectorInfo(MRZSectorInfo))
        .def(nb::init<>(), DOC_MRZSectorInfo(MRZSectorInfo))
        .def("get_tx_sector_number",
             &MRZSectorInfo::get_tx_sector_number,
             DOC_MRZSectorInfo(get_tx_sector_number))
        .def("set_tx_sector_number",
             &MRZSectorInfo::set_tx_sector_number,
             DOC_MRZSectorInfo(set_tx_sector_number),
             nb::arg("val"))
        .def("get_tx_arrary_number",
             &MRZSectorInfo::get_tx_arrary_number,
             DOC_MRZSectorInfo(get_tx_arrary_number))
        .def("set_tx_arrary_number",
             &MRZSectorInfo::set_tx_arrary_number,
             DOC_MRZSectorInfo(set_tx_arrary_number),
             nb::arg("val"))
        .def("get_tx_sub_array",
             &MRZSectorInfo::get_tx_sub_array,
             DOC_MRZSectorInfo(get_tx_sub_array))
        .def("set_tx_sub_array",
             &MRZSectorInfo::set_tx_sub_array,
             DOC_MRZSectorInfo(set_tx_sub_array),
             nb::arg("val"))
        .def("get_padding_0", &MRZSectorInfo::get_padding_0, DOC_MRZSectorInfo(get_padding_0))
        .def("set_padding_0",
             &MRZSectorInfo::set_padding_0,
             DOC_MRZSectorInfo(set_padding_0),
             nb::arg("val"))
        .def("get_sector_transmit_delay_sec",
             &MRZSectorInfo::get_sector_transmit_delay_sec,
             DOC_MRZSectorInfo(get_sector_transmit_delay_sec))
        .def("set_sector_transmit_delay_sec",
             &MRZSectorInfo::set_sector_transmit_delay_sec,
             DOC_MRZSectorInfo(set_sector_transmit_delay_sec),
             nb::arg("val"))
        .def("get_tilt_angle_re_tx_deg",
             &MRZSectorInfo::get_tilt_angle_re_tx_deg,
             DOC_MRZSectorInfo(get_tilt_angle_re_tx_deg))
        .def("set_tilt_angle_re_tx_deg",
             &MRZSectorInfo::set_tilt_angle_re_tx_deg,
             DOC_MRZSectorInfo(set_tilt_angle_re_tx_deg),
             nb::arg("val"))
        .def("get_tx_nominal_source_level_db",
             &MRZSectorInfo::get_tx_nominal_source_level_db,
             DOC_MRZSectorInfo(get_tx_nominal_source_level_db))
        .def("set_tx_nominal_source_level_db",
             &MRZSectorInfo::set_tx_nominal_source_level_db,
             DOC_MRZSectorInfo(set_tx_nominal_source_level_db),
             nb::arg("val"))
        .def("get_tx_focus_range_m",
             &MRZSectorInfo::get_tx_focus_range_m,
             DOC_MRZSectorInfo(get_tx_focus_range_m))
        .def("set_tx_focus_range_m",
             &MRZSectorInfo::set_tx_focus_range_m,
             DOC_MRZSectorInfo(set_tx_focus_range_m),
             nb::arg("val"))
        .def("get_centre_frequency_hz",
             &MRZSectorInfo::get_centre_frequency_hz,
             DOC_MRZSectorInfo(get_centre_frequency_hz))
        .def("set_centre_frequency_hz",
             &MRZSectorInfo::set_centre_frequency_hz,
             DOC_MRZSectorInfo(set_centre_frequency_hz),
             nb::arg("val"))
        .def("get_signal_band_width_hz",
             &MRZSectorInfo::get_signal_band_width_hz,
             DOC_MRZSectorInfo(get_signal_band_width_hz))
        .def("set_signal_band_width_hz",
             &MRZSectorInfo::set_signal_band_width_hz,
             DOC_MRZSectorInfo(set_signal_band_width_hz),
             nb::arg("val"))
        .def("get_total_signal_length_sec",
             &MRZSectorInfo::get_total_signal_length_sec,
             DOC_MRZSectorInfo(get_total_signal_length_sec))
        .def("set_total_signal_length_sec",
             &MRZSectorInfo::set_total_signal_length_sec,
             DOC_MRZSectorInfo(set_total_signal_length_sec),
             nb::arg("val"))
        .def("get_pulse_shading",
             &MRZSectorInfo::get_pulse_shading,
             DOC_MRZSectorInfo(get_pulse_shading))
        .def("set_pulse_shading",
             &MRZSectorInfo::set_pulse_shading,
             DOC_MRZSectorInfo(set_pulse_shading),
             nb::arg("val"))
        .def("get_signal_wave_form",
             &MRZSectorInfo::get_signal_wave_form,
             DOC_MRZSectorInfo(get_signal_wave_form))
        .def("set_signal_wave_form",
             &MRZSectorInfo::set_signal_wave_form,
             DOC_MRZSectorInfo(set_signal_wave_form),
             nb::arg("val"))
        .def("get_padding_1", &MRZSectorInfo::get_padding_1, DOC_MRZSectorInfo(get_padding_1))
        .def("set_padding_1",
             &MRZSectorInfo::set_padding_1,
             DOC_MRZSectorInfo(set_padding_1),
             nb::arg("val"))
        .def("get_high_voltage_level_db",
             &MRZSectorInfo::get_high_voltage_level_db,
             DOC_MRZSectorInfo(get_high_voltage_level_db))
        .def("set_high_voltage_level_db",
             &MRZSectorInfo::set_high_voltage_level_db,
             DOC_MRZSectorInfo(set_high_voltage_level_db),
             nb::arg("val"))
        .def("get_sector_tracking_corr_db",
             &MRZSectorInfo::get_sector_tracking_corr_db,
             DOC_MRZSectorInfo(get_sector_tracking_corr_db))
        .def("set_sector_tracking_corr_db",
             &MRZSectorInfo::set_sector_tracking_corr_db,
             DOC_MRZSectorInfo(set_sector_tracking_corr_db),
             nb::arg("val"))
        .def("get_effective_signal_length_sec",
             &MRZSectorInfo::get_effective_signal_length_sec,
             DOC_MRZSectorInfo(get_effective_signal_length_sec))
        .def("set_effective_signal_length_sec",
             &MRZSectorInfo::set_effective_signal_length_sec,
             DOC_MRZSectorInfo(set_effective_signal_length_sec),
             nb::arg("val"))

        // ----- processed -----
        .def("get_tx_signal_type",
             &MRZSectorInfo::get_tx_signal_type,
             DOC_MRZSectorInfo(get_tx_signal_type))

        // ----- operators -----
        .def("__eq__", &MRZSectorInfo::operator==, DOC_MRZSectorInfo(operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // copy
        __PYCLASS_DEFAULT_COPY__(MRZSectorInfo)
        // print
        __PYCLASS_DEFAULT_PRINTING__(MRZSectorInfo)
        // end
        ;

    nb::bind_vector<std::vector<MRZSectorInfo>>(m, "MRZSectorInfoVector");
}

}
}
}
}
}
