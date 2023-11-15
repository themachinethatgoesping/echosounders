// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/seabedimagedatabeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::SeabedImageDataBeam;

#define DOC_SeabedImageDataBeam(ARG)                                                               \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                                    \
        datagrams,                                                                                 \
        substructures,                                                                             \
        SeabedImageDataBeam,                                                                       \
        ARG)

void init_c_seabedimagedatabeam(pybind11::module& m)
{

    py::class_<SeabedImageDataBeam>(m,
                                    "SeabedImageDataBeam",
                                    DOC(themachinethatgoesping,
                                        echosounders,
                                        kongsbergall,
                                        datagrams,
                                        substructures,
                                        SeabedImageDataBeam))
        .def(py::init<>(), DOC_SeabedImageDataBeam(SeabedImageDataBeam))
        // --- convenient data access ---
        .def("set_sorting_direction",
             &SeabedImageDataBeam::set_sorting_direction,
             DOC_SeabedImageDataBeam(sorting_direction))
        .def("get_sorting_direction",
             &SeabedImageDataBeam::get_sorting_direction,
             DOC_SeabedImageDataBeam(sorting_direction))
        .def("set_detection_info",
             &SeabedImageDataBeam::set_detection_info,
             DOC_SeabedImageDataBeam(detection_info))
        .def("get_detection_info",
             &SeabedImageDataBeam::get_detection_info,
             DOC_SeabedImageDataBeam(detection_info))
        .def("set_number_of_samples",
             &SeabedImageDataBeam::set_number_of_samples,
             DOC_SeabedImageDataBeam(number_of_samples))
        .def("get_number_of_samples",
             &SeabedImageDataBeam::get_number_of_samples,
             DOC_SeabedImageDataBeam(number_of_samples))
        .def("set_centre_sample_number",
             &SeabedImageDataBeam::set_centre_sample_number,
             DOC_SeabedImageDataBeam(centre_sample_number))
        .def("get_centre_sample_number",
             &SeabedImageDataBeam::get_centre_sample_number,
             DOC_SeabedImageDataBeam(centre_sample_number))

        // --- processed member access ---
        .def("get_detection_is_valid",
             &SeabedImageDataBeam::get_detection_is_valid,
             DOC_SeabedImageDataBeam(get_detection_is_valid))
        .def("get_detection_type",
             &SeabedImageDataBeam::get_detection_type,
             DOC_SeabedImageDataBeam(get_detection_type))
        .def("get_backscatter_is_compensated",
             &SeabedImageDataBeam::get_backscatter_is_compensated,
             DOC_SeabedImageDataBeam(get_backscatter_is_compensated))

        // ----- operators -----
        .def("__eq__",
             &SeabedImageDataBeam::operator==,
             DOC_SeabedImageDataBeam(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(SeabedImageDataBeam)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(SeabedImageDataBeam)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}