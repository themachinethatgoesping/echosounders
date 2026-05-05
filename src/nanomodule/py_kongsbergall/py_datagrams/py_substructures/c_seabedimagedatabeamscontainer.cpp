// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/seabedimagedatabeamscontainer.hpp"

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::SeabedImageDataBeamsContainer;

#define DOC_SeabedImageDataBeamsContainer(ARG)                                                     \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        datagrams,                                                                                 \
        substructures,                                                                             \
        SeabedImageDataBeamsContainer,                                                             \
        ARG)

void init_c_seabedimagedatabeamscontainer(nanobind::module_& m)
{
    nb::class_<SeabedImageDataBeamsContainer>(
        m,
        "SeabedImageDataBeamsContainer",
        DOC_SeabedImageDataBeamsContainer(SeabedImageDataBeamsContainer))
        .def(nb::init<>(), DOC_SeabedImageDataBeamsContainer(SeabedImageDataBeamsContainer))

        .def_prop_rw("beams",
                     &SeabedImageDataBeamsContainer::beams,
                     &SeabedImageDataBeamsContainer::set_beams,
                     DOC_SeabedImageDataBeamsContainer(beams),
                     nb::rv_policy::reference_internal)
        .def("get_beams",
             &SeabedImageDataBeamsContainer::get_beams,
             DOC_SeabedImageDataBeamsContainer(get_beams))
        .def("set_beams",
             &SeabedImageDataBeamsContainer::set_beams,
             DOC_SeabedImageDataBeamsContainer(set_beams),
             nb::arg("beams"))

        // ----- raw fields -----
        .def("get_sorting_direction_tensor",
             &SeabedImageDataBeamsContainer::get_sorting_direction_tensor,
             DOC_SeabedImageDataBeamsContainer(get_sorting_direction_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_info_tensor",
             &SeabedImageDataBeamsContainer::get_detection_info_tensor,
             DOC_SeabedImageDataBeamsContainer(get_detection_info_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_number_of_samples_tensor",
             &SeabedImageDataBeamsContainer::get_number_of_samples_tensor,
             DOC_SeabedImageDataBeamsContainer(get_number_of_samples_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_centre_sample_number_tensor",
             &SeabedImageDataBeamsContainer::get_centre_sample_number_tensor,
             DOC_SeabedImageDataBeamsContainer(get_centre_sample_number_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})

        // ----- processed -----
        .def("get_detection_is_valid_tensor",
             &SeabedImageDataBeamsContainer::get_detection_is_valid_tensor,
             DOC_SeabedImageDataBeamsContainer(get_detection_is_valid_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_type_tensor",
             &SeabedImageDataBeamsContainer::get_detection_type_tensor,
             DOC_SeabedImageDataBeamsContainer(get_detection_type_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_backscatter_is_compensated_tensor",
             &SeabedImageDataBeamsContainer::get_backscatter_is_compensated_tensor,
             DOC_SeabedImageDataBeamsContainer(get_backscatter_is_compensated_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})

        // ----- size -----
        .def("get_number_of_beams",
             &SeabedImageDataBeamsContainer::get_number_of_beams,
             DOC_SeabedImageDataBeamsContainer(get_number_of_beams))

        // ----- operators -----
        .def("__eq__",
             &SeabedImageDataBeamsContainer::operator==,
             DOC_SeabedImageDataBeamsContainer(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        __PYCLASS_DEFAULT_COPY__(SeabedImageDataBeamsContainer)
        __PYCLASS_DEFAULT_PRINTING__(SeabedImageDataBeamsContainer)
        ;
}

}
}
}
}
}
}
