// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include <themachinethatgoesping/echosounders/filetemplates/datatypes/calibration/watercolumncalibration.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {
namespace py_calibration {

namespace py = pybind11;

#define DOC_WaterColumnCalibration(ARG)                                                            \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datatypes,                                                                                 \
        calibration,                                                                               \
        WaterColumnCalibration,                                                                    \
        ARG)

void init_c_watercolumncalibration(pybind11::module& m)
{
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;

    // add class
    py::class_<WaterColumnCalibration>(m,
                                       "WaterColumnCalibration",
                                       DOC(themachinethatgoesping,
                                           echosounders,
                                           filetemplates,
                                           datatypes,
                                           calibration,
                                           WaterColumnCalibration))
        .def(py::init<>(), DOC_WaterColumnCalibration(WaterColumnCalibration))
        .def(py::init<float>(),
             DOC_WaterColumnCalibration(WaterColumnCalibration),
             py::arg("system_offset"))
        .def(py::init<const WaterColumnCalibration&>(),
             DOC_WaterColumnCalibration(WaterColumnCalibration))

        // --- convenient data access ---
        .def("get_system_offset",
             &WaterColumnCalibration::get_system_offset,
             DOC_WaterColumnCalibration(get_system_offset))
        .def("set_system_offset",
             &WaterColumnCalibration::set_system_offset,
             DOC_WaterColumnCalibration(set_system_offset),
             py::arg("value"))
        .def("set_offset_per_beamangle",
             &WaterColumnCalibration::set_offset_per_beamangle,
             DOC_WaterColumnCalibration(set_offset_per_beamangle),
             py::arg("beamangle"),
             py::arg("offset"))
        .def("set_offset_per_range",
             &WaterColumnCalibration::set_offset_per_range,
             DOC_WaterColumnCalibration(set_offset_per_range),
             py::arg("range"),
             py::arg("offset"))

        .def("get_interpolator_offset_per_beamangle",
             &WaterColumnCalibration::get_interpolator_offset_per_beamangle,
             DOC_WaterColumnCalibration(get_interpolator_offset_per_beamangle))
        .def("get_interpolator_offset_per_range",
             &WaterColumnCalibration::get_interpolator_offset_per_range,
             DOC_WaterColumnCalibration(get_interpolator_offset_per_range))

        .def("get_offset_per_beamangle",
             &WaterColumnCalibration::get_offset_per_beamangle,
             DOC_WaterColumnCalibration(get_offset_per_beamangle),
             py::arg("beamangle"))
        .def("get_offset_per_range",
             &WaterColumnCalibration::get_offset_per_range,
             DOC_WaterColumnCalibration(get_offset_per_range),
             py::arg("range"))

        // ----- operators -----
        .def("__eq__",
             &WaterColumnCalibration::operator==,
             DOC_WaterColumnCalibration(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(WaterColumnCalibration)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(WaterColumnCalibration)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(WaterColumnCalibration)
        // end WaterColumnCalibration
        ;
}
}
}
}
}
}
}