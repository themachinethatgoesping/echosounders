// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pytensor.hpp>                 // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>


#include <themachinethatgoesping/echosounders/kongsbergall/filedatatypes/calibration/kongsbergallwatercolumncalibration.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatatypes {
namespace py_calibration {

namespace py = pybind11;

#define DOC_KongsbergAllWaterColumnCalibration(ARG)                                                \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        filedatatypes,                                                                             \
        calibration,                                                                               \
        KongsbergAllWaterColumnCalibration,                                                        \
        ARG)

void init_c_kongsbergallwatercolumncalibration(pybind11::module& m)
{
    using namespace themachinethatgoesping::echosounders::kongsbergall::filedatatypes::calibration;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;

    // add class
    auto c = py::classh<KongsbergAllWaterColumnCalibration,
                        WaterColumnCalibration>(
                 m,
                 "KongsbergAllWaterColumnCalibration",
                 DOC(themachinethatgoesping,
                     echosounders,
                     kongsbergall,
                     filedatatypes,
                     calibration,
                     KongsbergAllWaterColumnCalibration))
                 .def(py::init<float, float, float, float, float>(),
                      DOC_KongsbergAllWaterColumnCalibration(KongsbergAllWaterColumnCalibration),
                      py::arg("sound_velocity"),
                      py::arg("effective_pulse_duration"),
                      py::arg("system_gain_offset"),
                      py::arg("tvg_absorption_db_m"),
                      py::arg("tvg_factor"))

                 // --- modify calibration ---
                 .def("modify_kongsberg_em_calibrations",
                      &KongsbergAllWaterColumnCalibration::modify_kongsberg_em_calibrations,
                      DOC_KongsbergAllWaterColumnCalibration(modify_kongsberg_em_calibrations),
                      py::arg("sound_velocity")           = std::nullopt,
                      py::arg("effective_pulse_duration") = std::nullopt,
                      py::arg("system_gain_offset")       = std::nullopt,
                      py::arg("tvg_absorption_db_m")      = std::nullopt,
                      py::arg("tvg_factor")               = std::nullopt)

                 //--- getters ---
                 .def("get_sound_velocity",
                      &KongsbergAllWaterColumnCalibration::get_sound_velocity,
                      DOC_KongsbergAllWaterColumnCalibration(get_sound_velocity))
                 .def("get_effective_pulse_duration",
                      &KongsbergAllWaterColumnCalibration::get_effective_pulse_duration,
                      DOC_KongsbergAllWaterColumnCalibration(get_effective_pulse_duration))
                 .def("get_system_gain_offset",
                      &KongsbergAllWaterColumnCalibration::get_system_gain_offset,
                      DOC_KongsbergAllWaterColumnCalibration(get_system_gain_offset))

                 .def("initialized",
                      &KongsbergAllWaterColumnCalibration::initialized,
                      DOC_KongsbergAllWaterColumnCalibration(initialized))
                 .def("check_initialized",
                      &KongsbergAllWaterColumnCalibration::check_initialized,
                      DOC_KongsbergAllWaterColumnCalibration(check_initialized))
                 .def("check_initialization",
                      &KongsbergAllWaterColumnCalibration::check_initialization,
                      DOC_KongsbergAllWaterColumnCalibration(check_initialization))

                 // ----- operators -----
                 .def("__eq__",
                      &KongsbergAllWaterColumnCalibration::operator==,
                      DOC_KongsbergAllWaterColumnCalibration(operator_eq),
                      py::arg("other"))
             // ----- pybind macros -----
             // default copy functions
             __PYCLASS_DEFAULT_COPY__(KongsbergAllWaterColumnCalibration)
             // default binary functions
             __PYCLASS_DEFAULT_BINARY__(KongsbergAllWaterColumnCalibration)
             // default printing functions
             __PYCLASS_DEFAULT_PRINTING__(KongsbergAllWaterColumnCalibration)
        // end KongsbergAllWaterColumnCalibration
        ;
}
}
}
}
}
}
}