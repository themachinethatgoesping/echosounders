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
#include <themachinethatgoesping/echosounders/kongsbergall/filedatatypes/calibration/kongsbergallwatercolumncalibration.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatatypes {
namespace py_calibration {

namespace nb = nanobind;

#define DOC_KongsbergAllWaterColumnCalibration(ARG)                                                \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        filedatatypes,                                                                             \
        calibration,                                                                               \
        KongsbergAllWaterColumnCalibration,                                                        \
        ARG)

void init_c_kongsbergallwatercolumncalibration(nanobind::module_& m)
{
    using namespace themachinethatgoesping::echosounders::kongsbergall::filedatatypes::calibration;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;

    // add class
    auto c = nb::class_<KongsbergAllWaterColumnCalibration, WaterColumnCalibration>(
                 m,
                 "KongsbergAllWaterColumnCalibration",
                 DOC(themachinethatgoesping,
                     echosounders,
                     kongsbergall,
                     filedatatypes,
                     calibration,
                     KongsbergAllWaterColumnCalibration))
                 .def(nb::init<float, float, float, float, float>(),
                      DOC_KongsbergAllWaterColumnCalibration(KongsbergAllWaterColumnCalibration),
                      nb::arg("sound_velocity"),
                      nb::arg("effective_pulse_duration"),
                      nb::arg("system_gain_offset"),
                      nb::arg("tvg_absorption_db_m"),
                      nb::arg("tvg_factor"))

                 // --- modify calibration ---
                 .def("modify_kongsberg_em_calibrations",
                      &KongsbergAllWaterColumnCalibration::modify_kongsberg_em_calibrations,
                      DOC_KongsbergAllWaterColumnCalibration(modify_kongsberg_em_calibrations),
                      nb::arg("sound_velocity")           = std::nullopt,
                      nb::arg("effective_pulse_duration") = std::nullopt,
                      nb::arg("system_gain_offset")       = std::nullopt,
                      nb::arg("tvg_absorption_db_m")      = std::nullopt,
                      nb::arg("tvg_factor")               = std::nullopt)

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

                 .def(
                     "pre_hashed",
                     [](const KongsbergAllWaterColumnCalibration& self) {
                         return boost::flyweight<KongsbergAllMultiSectorWaterColumnCalibration>(
                             KongsbergAllMultiSectorWaterColumnCalibration({ self }));
                     },
                     "Return this class as a flyweight with computed hash. "
                     "This faster when updating the ping calibration.")

                 // ----- operators -----
                 .def("__eq__",
                      &KongsbergAllWaterColumnCalibration::operator==,
                      DOC_KongsbergAllWaterColumnCalibration(operator_eq),
                      nb::arg("other"))
             // ----- pybind macros -----
             // default copy functions
             __PYCLASS_DEFAULT_COPY__(KongsbergAllWaterColumnCalibration)
             // default binary functions
             __PYCLASS_DEFAULT_BINARY__(KongsbergAllWaterColumnCalibration)
             // default printing functions
             __PYCLASS_DEFAULT_PRINTING__(KongsbergAllWaterColumnCalibration)
        // end KongsbergAllWaterColumnCalibration
        ;

    // add multisector calibration
    py_filetemplates::py_datatypes::py_calibration::init_multisectorcalibration<
        KongsbergAllWaterColumnCalibration>(m, "KongsbergAllMultiSectorWaterColumnCalibration");
}
}
}
}
}
}
}