// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp>

#include "../../../py_filetemplates/py_datatypes/py_calibration/c_multisectorwatercolumncalibration.hpp"
#include <themachinethatgoesping/echosounders/kmall/filedatatypes/calibration/kmallwatercolumncalibration.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_filedatatypes {
namespace py_calibration {

namespace nb = nanobind;

#define DOC_KMALLWaterColumnCalibration(ARG)                                                \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kmall,                                                                              \
        filedatatypes,                                                                             \
        calibration,                                                                               \
        KMALLWaterColumnCalibration,                                                        \
        ARG)

void init_c_kmallwatercolumncalibration(nanobind::module_& m)
{
    using namespace themachinethatgoesping::echosounders::kmall::filedatatypes::calibration;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;

    // add class
    auto c = nb::class_<KMALLWaterColumnCalibration, WaterColumnCalibration>(
                 m,
                 "KMALLWaterColumnCalibration",
                 DOC(themachinethatgoesping,
                     echosounders,
                     kmall,
                     filedatatypes,
                     calibration,
                     KMALLWaterColumnCalibration))
                 .def(nb::init<float, float, float, float, float>(),
                      DOC_KMALLWaterColumnCalibration(KMALLWaterColumnCalibration),
                      nb::arg("sound_velocity"),
                      nb::arg("effective_pulse_duration"),
                      nb::arg("system_gain_offset"),
                      nb::arg("tvg_absorption_db_m"),
                      nb::arg("tvg_factor"))

                 // --- modify calibration ---
               //   .def("modify_kongsberg_em_calibrations",
               //        &KMALLWaterColumnCalibration::modify_kongsberg_em_calibrations,
               //        DOC_KMALLWaterColumnCalibration(modify_kongsberg_em_calibrations),
               //        nb::arg("sound_velocity")           = std::nullopt,
               //        nb::arg("effective_pulse_duration") = std::nullopt,
               //        nb::arg("system_gain_offset")       = std::nullopt,
               //        nb::arg("tvg_absorption_db_m")      = std::nullopt,
               //        nb::arg("tvg_factor")               = std::nullopt)

               //   //--- getters ---
               //   .def("get_sound_velocity",
               //        &KMALLWaterColumnCalibration::get_sound_velocity,
               //        DOC_KMALLWaterColumnCalibration(get_sound_velocity))
               //   .def("get_effective_pulse_duration",
               //        &KMALLWaterColumnCalibration::get_effective_pulse_duration,
               //        DOC_KMALLWaterColumnCalibration(get_effective_pulse_duration))
               //   .def("get_system_gain_offset",
               //        &KMALLWaterColumnCalibration::get_system_gain_offset,
               //        DOC_KMALLWaterColumnCalibration(get_system_gain_offset))

               //   .def("initialized",
               //        &KMALLWaterColumnCalibration::initialized,
               //        DOC_KMALLWaterColumnCalibration(initialized))
               //   .def("check_initialized",
               //        &KMALLWaterColumnCalibration::check_initialized,
               //        DOC_KMALLWaterColumnCalibration(check_initialized))
               //   .def("check_initialization",
               //        &KMALLWaterColumnCalibration::check_initialization,
               //        DOC_KMALLWaterColumnCalibration(check_initialization))

               //   .def(
               //       "pre_hashed",
               //       [](const KMALLWaterColumnCalibration& self) {
               //           return boost::flyweight<KMALLMultiSectorWaterColumnCalibration>(
               //               KMALLMultiSectorWaterColumnCalibration({ self }));
               //       },
               //       "Return this class as a flyweight with computed hash. "
               //       "This faster when updating the ping calibration.")

                 // ----- operators -----
                 .def("__eq__",
                      &KMALLWaterColumnCalibration::operator==,
                      DOC_KMALLWaterColumnCalibration(operator_eq),
                      nb::arg("other"))
             // ----- pybind macros -----
             // default copy functions
             __PYCLASS_DEFAULT_COPY__(KMALLWaterColumnCalibration)
             // default binary functions
             __PYCLASS_DEFAULT_BINARY__(KMALLWaterColumnCalibration)
             // default printing functions
             __PYCLASS_DEFAULT_PRINTING__(KMALLWaterColumnCalibration)
        // end KMALLWaterColumnCalibration
        ;

    // add multisector calibration
    py_filetemplates::py_datatypes::py_calibration::init_multisectorcalibration<
        KMALLWaterColumnCalibration>(m, "KMALLMultiSectorWaterColumnCalibration");
}
}
}
}
}
}
}