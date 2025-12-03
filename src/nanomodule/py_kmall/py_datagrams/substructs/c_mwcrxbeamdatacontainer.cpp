// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mwcrxbeamdatacontainer.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::substructs::MWCRxBeamData;
using datagrams::substructs::MWCRxBeamDataContainer;

#define DOC_MWCRxBeamDataContainer(ARG)                                                    \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, substructs, MWCRxBeamDataContainer, ARG)

void init_c_mwcrxbeamdatacontainer(nanobind::module_& m)
{
    nb::class_<MWCRxBeamDataContainer>(
        m, "MWCRxBeamDataContainer", DOC_MWCRxBeamDataContainer(MWCRxBeamDataContainer))
        .def(nb::init<>(), DOC_MWCRxBeamDataContainer(MWCRxBeamDataContainer))

          .def_prop_rw(
               "beams",
               [](MWCRxBeamDataContainer& self) -> std::vector<MWCRxBeamData>& {
                    return self.beams();
               },
               &MWCRxBeamDataContainer::set_beams,
               DOC_MWCRxBeamDataContainer(beams),
               nb::rv_policy::reference_internal)
        .def("get_beams",
             &MWCRxBeamDataContainer::get_beams,
             DOC_MWCRxBeamDataContainer(get_beams),
             nb::rv_policy::reference_internal)
        .def("set_beams",
             &MWCRxBeamDataContainer::set_beams,
             DOC_MWCRxBeamDataContainer(set_beams),
             nb::arg("beams"))

        .def("get_beam_pointing_angle_re_vertical_deg_tensor",
             &MWCRxBeamDataContainer::get_beam_pointing_angle_re_vertical_deg_tensor,
             DOC_MWCRxBeamDataContainer(get_beam_pointing_angle_re_vertical_deg_tensor))
        .def("get_start_range_sample_number_tensor",
             &MWCRxBeamDataContainer::get_start_range_sample_number_tensor,
             DOC_MWCRxBeamDataContainer(get_start_range_sample_number_tensor))
        .def("get_detected_range_in_samples_tensor",
             &MWCRxBeamDataContainer::get_detected_range_in_samples_tensor,
             DOC_MWCRxBeamDataContainer(get_detected_range_in_samples_tensor))
        .def("get_transmit_sector_number_tensor",
             &MWCRxBeamDataContainer::get_transmit_sector_number_tensor,
             DOC_MWCRxBeamDataContainer(get_transmit_sector_number_tensor))
        .def("get_number_of_samples_tensor",
             &MWCRxBeamDataContainer::get_number_of_samples_tensor,
             DOC_MWCRxBeamDataContainer(get_number_of_samples_tensor))
        .def("get_detected_range_in_samples_high_resolution_tensor",
             &MWCRxBeamDataContainer::get_detected_range_in_samples_high_resolution_tensor,
             DOC_MWCRxBeamDataContainer(get_detected_range_in_samples_high_resolution_tensor))

        .def("get_number_of_beams",
             &MWCRxBeamDataContainer::get_number_of_beams,
             DOC_MWCRxBeamDataContainer(get_number_of_beams))
        .def("get_total_number_of_samples",
             &MWCRxBeamDataContainer::get_total_number_of_samples,
             DOC_MWCRxBeamDataContainer(get_total_number_of_samples))

        .def("__eq__",
             &MWCRxBeamDataContainer::operator==,
             DOC_MWCRxBeamDataContainer(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(MWCRxBeamDataContainer)
        __PYCLASS_DEFAULT_PRINTING__(MWCRxBeamDataContainer);
}

} // namespace py_datagrams
} // namespace py_kmall
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
