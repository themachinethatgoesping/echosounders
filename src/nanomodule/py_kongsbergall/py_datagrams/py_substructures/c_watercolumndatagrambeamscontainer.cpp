// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/watercolumndatagrambeamscontainer.hpp"

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::WatercolumnDatagramBeamsContainer;

#define DOC_WatercolumnDatagramBeamsContainer(ARG)                                                 \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        datagrams,                                                                                 \
        substructures,                                                                             \
        WatercolumnDatagramBeamsContainer,                                                         \
        ARG)

void init_c_watercolumndatagrambeamscontainer(nanobind::module_& m)
{
    nb::class_<WatercolumnDatagramBeamsContainer>(
        m,
        "WatercolumnDatagramBeamsContainer",
        DOC_WatercolumnDatagramBeamsContainer(WatercolumnDatagramBeamsContainer))
        .def(nb::init<>(),
             DOC_WatercolumnDatagramBeamsContainer(WatercolumnDatagramBeamsContainer))

        .def_prop_rw("beams",
                     &WatercolumnDatagramBeamsContainer::beams,
                     &WatercolumnDatagramBeamsContainer::set_beams,
                     DOC_WatercolumnDatagramBeamsContainer(beams),
                     nb::rv_policy::reference_internal)
        .def("get_beams",
             &WatercolumnDatagramBeamsContainer::get_beams,
             DOC_WatercolumnDatagramBeamsContainer(get_beams))
        .def("set_beams",
             &WatercolumnDatagramBeamsContainer::set_beams,
             DOC_WatercolumnDatagramBeamsContainer(set_beams),
             nb::arg("beams"))

        // ----- raw fields -----
        .def("get_beam_crosstrack_angle_tensor",
             &WatercolumnDatagramBeamsContainer::get_beam_crosstrack_angle_tensor,
             DOC_WatercolumnDatagramBeamsContainer(get_beam_crosstrack_angle_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_start_range_sample_number_tensor",
             &WatercolumnDatagramBeamsContainer::get_start_range_sample_number_tensor,
             DOC_WatercolumnDatagramBeamsContainer(get_start_range_sample_number_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_number_of_samples_tensor",
             &WatercolumnDatagramBeamsContainer::get_number_of_samples_tensor,
             DOC_WatercolumnDatagramBeamsContainer(get_number_of_samples_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detected_range_in_samples_tensor",
             &WatercolumnDatagramBeamsContainer::get_detected_range_in_samples_tensor,
             DOC_WatercolumnDatagramBeamsContainer(get_detected_range_in_samples_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_transmit_sector_number_tensor",
             &WatercolumnDatagramBeamsContainer::get_transmit_sector_number_tensor,
             DOC_WatercolumnDatagramBeamsContainer(get_transmit_sector_number_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_beam_number_tensor",
             &WatercolumnDatagramBeamsContainer::get_beam_number_tensor,
             DOC_WatercolumnDatagramBeamsContainer(get_beam_number_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})

        // ----- processed -----
        .def("get_beam_crosstrack_angle_in_degrees_tensor",
             &WatercolumnDatagramBeamsContainer::get_beam_crosstrack_angle_in_degrees_tensor,
             DOC_WatercolumnDatagramBeamsContainer(get_beam_crosstrack_angle_in_degrees_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})

        // ----- size -----
        .def("get_number_of_beams",
             &WatercolumnDatagramBeamsContainer::get_number_of_beams,
             DOC_WatercolumnDatagramBeamsContainer(get_number_of_beams))

        // ----- operators -----
        .def("__eq__",
             &WatercolumnDatagramBeamsContainer::operator==,
             DOC_WatercolumnDatagramBeamsContainer(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(WatercolumnDatagramBeamsContainer)
        __PYCLASS_DEFAULT_PRINTING__(WatercolumnDatagramBeamsContainer)
        ;
}

}
}
}
}
}
}
