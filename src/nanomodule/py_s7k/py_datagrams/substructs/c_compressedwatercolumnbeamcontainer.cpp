// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/substructs/compressedwatercolumnbeamcontainer.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::substructs::CompressedWaterColumnBeamContainer;

#define DOC_CompressedWaterColumnBeamContainer(ARG)                                                \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        s7k,                                                                                       \
        datagrams,                                                                                 \
        substructs,                                                                                \
        CompressedWaterColumnBeamContainer,                                                        \
        ARG)

void init_c_compressedwatercolumnbeamcontainer(nanobind::module_& m)
{
    nb::class_<CompressedWaterColumnBeamContainer>(
        m,
        "CompressedWaterColumnBeamContainer",
        DOC_CompressedWaterColumnBeamContainer(CompressedWaterColumnBeamContainer))
        .def(nb::init<>(),
             DOC_CompressedWaterColumnBeamContainer(CompressedWaterColumnBeamContainer))

        .def_prop_rw("beams",
                     &CompressedWaterColumnBeamContainer::beams,
                     &CompressedWaterColumnBeamContainer::set_beams,
                     DOC_CompressedWaterColumnBeamContainer(beams),
                     nb::rv_policy::reference_internal)

        .def("get_beam_number_tensor",
             &CompressedWaterColumnBeamContainer::get_beam_number_tensor,
             DOC_CompressedWaterColumnBeamContainer(get_beam_number_tensor))
        .def("get_segment_number_tensor",
             &CompressedWaterColumnBeamContainer::get_segment_number_tensor,
             DOC_CompressedWaterColumnBeamContainer(get_segment_number_tensor))
        .def("get_sample_count_tensor",
             &CompressedWaterColumnBeamContainer::get_sample_count_tensor,
             DOC_CompressedWaterColumnBeamContainer(get_sample_count_tensor))

        .def("get_magnitude",
             &CompressedWaterColumnBeamContainer::get_magnitude,
             DOC_CompressedWaterColumnBeamContainer(get_magnitude),
             nb::arg("beam_index"))
        .def("get_phase",
             &CompressedWaterColumnBeamContainer::get_phase,
             DOC_CompressedWaterColumnBeamContainer(get_phase),
             nb::arg("beam_index"))
        .def("get_magnitude_in_db",
             &CompressedWaterColumnBeamContainer::get_magnitude_in_db,
             DOC_CompressedWaterColumnBeamContainer(get_magnitude_in_db),
             nb::arg("beam_index"))
        .def("get_phase_in_degrees",
             &CompressedWaterColumnBeamContainer::get_phase_in_degrees,
             DOC_CompressedWaterColumnBeamContainer(get_phase_in_degrees),
             nb::arg("beam_index"))

        .def("get_magnitudes",
             &CompressedWaterColumnBeamContainer::get_magnitudes,
             "magnitude arrays, one per beam (dB if the beam's magnitude_is_db, else raw)")
        .def("get_phases",
             &CompressedWaterColumnBeamContainer::get_phases,
             "phase arrays in radians, one per beam (empty beams if there is no phase)")
        .def("get_magnitudes_in_db",
             &CompressedWaterColumnBeamContainer::get_magnitudes_in_db,
             "magnitude in dB, one array per beam (see CompressedWaterColumnBeam.get_magnitude_in_db)")

        .def("get_number_of_beams",
             &CompressedWaterColumnBeamContainer::get_number_of_beams,
             DOC_CompressedWaterColumnBeamContainer(get_number_of_beams))
        .def("get_total_number_of_samples",
             &CompressedWaterColumnBeamContainer::get_total_number_of_samples,
             DOC_CompressedWaterColumnBeamContainer(get_total_number_of_samples))

        .def("get_samples_are_skipped",
             &CompressedWaterColumnBeamContainer::get_samples_are_skipped,
             DOC_CompressedWaterColumnBeamContainer(get_samples_are_skipped))
        .def("get_sample_position",
             &CompressedWaterColumnBeamContainer::get_sample_position,
             DOC_CompressedWaterColumnBeamContainer(get_sample_position))

        .def("__eq__",
             &CompressedWaterColumnBeamContainer::operator==,
             DOC_CompressedWaterColumnBeamContainer(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(CompressedWaterColumnBeamContainer)
        __PYCLASS_DEFAULT_PRINTING__(CompressedWaterColumnBeamContainer);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
