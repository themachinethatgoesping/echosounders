// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/optional.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mwcrxbeamdata.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::substructs::MWCRxBeamData;

#define DOC_MWCRxBeamData(ARG)                                                                        \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, substructs, MWCRxBeamData, ARG)

void init_c_mwcrxbeamdata(nanobind::module_& m)
{
    nb::class_<MWCRxBeamData>(m, "MWCRxBeamData", DOC_MWCRxBeamData(MWCRxBeamData))
        .def(nb::init<>(), DOC_MWCRxBeamData(MWCRxBeamData))
        .def("get_beam_pointing_angle_re_vertical_deg",
             &MWCRxBeamData::get_beam_pointing_angle_re_vertical_deg,
             DOC_MWCRxBeamData(get_beam_pointing_angle_re_vertical_deg))
        .def("set_beam_pointing_angle_re_vertical_deg",
             &MWCRxBeamData::set_beam_pointing_angle_re_vertical_deg,
             nb::arg("val"))
        .def("get_start_range_sample_number",
             &MWCRxBeamData::get_start_range_sample_number,
             DOC_MWCRxBeamData(get_start_range_sample_number))
        .def("set_start_range_sample_number",
             &MWCRxBeamData::set_start_range_sample_number,
             nb::arg("val"))
        .def("get_detected_range_in_samples",
             &MWCRxBeamData::get_detected_range_in_samples,
             DOC_MWCRxBeamData(get_detected_range_in_samples))
        .def("set_detected_range_in_samples",
             &MWCRxBeamData::set_detected_range_in_samples,
             nb::arg("val"))
        .def("get_transmit_sector_number",
             &MWCRxBeamData::get_transmit_sector_number,
             DOC_MWCRxBeamData(get_transmit_sector_number))
        .def("set_transmit_sector_number",
             &MWCRxBeamData::set_transmit_sector_number,
             nb::arg("val"))
        .def("get_number_of_samples",
             &MWCRxBeamData::get_number_of_samples,
             DOC_MWCRxBeamData(get_number_of_samples))
        .def("set_number_of_samples",
             &MWCRxBeamData::set_number_of_samples,
             nb::arg("val"))
        .def("get_detected_range_in_samples_high_resolution",
             &MWCRxBeamData::get_detected_range_in_samples_high_resolution,
             DOC_MWCRxBeamData(get_detected_range_in_samples_high_resolution))
        .def("set_detected_range_in_samples_high_resolution",
             &MWCRxBeamData::set_detected_range_in_samples_high_resolution,
             nb::arg("val"))
        .def("get_sample_amplitudes_in_db",
             &MWCRxBeamData::get_sample_amplitudes_in_db,
             DOC_MWCRxBeamData(get_sample_amplitudes_in_db),
             nb::arg("db_offset") =0.0f)
        .def("set_sample_amplitudes_05dB",
             &MWCRxBeamData::set_sample_amplitudes_05dB,
             nb::arg("sample_amplitudes"))
        .def("get_sample_amplitudes_05dB",
             [](const MWCRxBeamData& self) -> nb::object {
                 if (auto amplitudes = self.get_sample_amplitudes_05dB())
                     return nb::cast(amplitudes.value());
                 return nb::none();
             })
        .def("set_rx_beam_phase", &MWCRxBeamData::set_rx_beam_phase, nb::arg("rx_beam_phase"))
        .def("get_rx_beam_phase",
             [](const MWCRxBeamData& self) -> nb::object {
                 if (auto phase = self.get_rx_beam_phase())
                     return nb::cast(phase.value());
                 return nb::none();
             })
        .def("get_samples_are_skipped", &MWCRxBeamData::get_samples_are_skipped)
        .def("set_sample_are_skipped",
             &MWCRxBeamData::set_sample_are_skipped,
             nb::arg("sample_pos"))
        .def("get_sample_position", &MWCRxBeamData::get_sample_position)
        .def("sample_amplitudes_05dB",
             &MWCRxBeamData::sample_amplitudes_05dB,
             DOC_MWCRxBeamData(sample_amplitudes_05dB),
             nb::rv_policy::reference_internal)
        .def("__eq__",
             &MWCRxBeamData::operator==,
             DOC_MWCRxBeamData(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(MWCRxBeamData)
        __PYCLASS_DEFAULT_PRINTING__(MWCRxBeamData);
}

} // namespace py_datagrams
} // namespace py_kmall
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
