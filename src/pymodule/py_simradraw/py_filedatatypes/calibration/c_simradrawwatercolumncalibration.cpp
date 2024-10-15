// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pytensor.hpp>                 // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include <themachinethatgoesping/echosounders/simradraw/filedatatypes/calibration/simradrawwatercolumncalibration.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_filedatatypes {
namespace py_calibration {

namespace py = pybind11;

#define DOC_SimradRawWaterColumnCalibration(ARG)                                                \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simradraw,                                                                              \
        filedatatypes,                                                                             \
        calibration,                                                                               \
        SimradRawWaterColumnCalibration,                                                        \
        ARG)

void init_c_simradrawwatercolumncalibration(pybind11::module& m)
{
    using namespace themachinethatgoesping::echosounders::simradraw::filedatatypes::calibration;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;

    // add class
    auto c = py::class_<SimradRawWaterColumnCalibration,
                        WaterColumnCalibration,
                        std::shared_ptr<SimradRawWaterColumnCalibration>>(
                 m,
                 "SimradRawWaterColumnCalibration",
                 DOC(themachinethatgoesping,
                     echosounders,
                     simradraw,
                     filedatatypes,
                     calibration,
                     SimradRawWaterColumnCalibration))
                 .def(py::init<float, float, float, float, float>(),
                      DOC_SimradRawWaterColumnCalibration(SimradRawWaterColumnCalibration),
                      py::arg("sound_velocity"),
                      py::arg("effective_pulse_duration"),
                      py::arg("system_gain_offset"),
                      py::arg("tvg_absorption_db_m"),
                      py::arg("tvg_factor"))

                 //--- getters ---
                 .def("get_sound_velocity",
                      &SimradRawWaterColumnCalibration::get_sound_velocity,
                      DOC_SimradRawWaterColumnCalibration(get_sound_velocity))
                 .def("get_effective_pulse_duration",
                      &SimradRawWaterColumnCalibration::get_effective_pulse_duration,
                      DOC_SimradRawWaterColumnCalibration(get_effective_pulse_duration))
                 .def("get_system_gain_offset",
                      &SimradRawWaterColumnCalibration::get_system_gain_offset,
                      DOC_SimradRawWaterColumnCalibration(get_system_gain_offset))

                 // ----- operators -----
                 .def("__eq__",
                      &SimradRawWaterColumnCalibration::operator==,
                      DOC_SimradRawWaterColumnCalibration(operator_eq),
                      py::arg("other"))
             // ----- pybind macros -----
             // default copy functions
             __PYCLASS_DEFAULT_COPY__(SimradRawWaterColumnCalibration)
             // default binary functions
             __PYCLASS_DEFAULT_BINARY__(SimradRawWaterColumnCalibration)
             // default printing functions
             __PYCLASS_DEFAULT_PRINTING__(SimradRawWaterColumnCalibration)
        // end SimradRawWaterColumnCalibration
        ;
}
}
}
}
}
}
}