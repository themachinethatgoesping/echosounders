// SPDX-FileCopyrightText: 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <py_datatypes/py_calibration/c_multisectorwatercolumncalibration.hpp>
#include <themachinethatgoesping/echosounders/s7k/filedatatypes/calibration/s7kwatercolumncalibration.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatatypes {
namespace py_calibration {

namespace nb = nanobind;

#define DOC_S7KWaterColumnCalibration(ARG)                                                         \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        s7k,                                                                                       \
        filedatatypes,                                                                             \
        calibration,                                                                               \
        S7KWaterColumnCalibration,                                                                 \
        ARG)

void init_c_s7kwatercolumncalibration(nanobind::module_& m)
{
    using namespace themachinethatgoesping::echosounders::s7k::filedatatypes::calibration;
    using namespace themachinethatgoesping::pingprocessing::datatypes::calibration;

    // add class
    auto c =
        nb::class_<S7KWaterColumnCalibration, WaterColumnCalibration>(
            m,
            "S7KWaterColumnCalibration",
            DOC(themachinethatgoesping,
                echosounders,
                s7k,
                filedatatypes,
                calibration,
                S7KWaterColumnCalibration))
            .def(nb::init<float, float, float, float, float, bool>(),
                 DOC_S7KWaterColumnCalibration(S7KWaterColumnCalibration),
                 nb::arg("sound_velocity"),
                 nb::arg("effective_pulse_duration"),
                 nb::arg("system_gain_offset"),
                 nb::arg("tvg_absorption_db_m"),
                 nb::arg("tvg_factor"),
                 nb::arg("is_fm") = false)

            // --- modify calibration ---
            .def("modify_s7k_calibrations",
                 &S7KWaterColumnCalibration::modify_s7k_calibrations,
                 DOC_S7KWaterColumnCalibration(modify_s7k_calibrations),
                 nb::arg("sound_velocity")           = std::nullopt,
                 nb::arg("effective_pulse_duration") = std::nullopt,
                 nb::arg("system_gain_offset")       = std::nullopt,
                 nb::arg("tvg_absorption_db_m")      = std::nullopt,
                 nb::arg("tvg_factor")               = std::nullopt,
                 nb::arg("is_fm")                    = std::nullopt)

            //--- getters ---
            .def("get_sound_velocity",
                 &S7KWaterColumnCalibration::get_sound_velocity,
                 DOC_S7KWaterColumnCalibration(get_sound_velocity))
            .def("get_effective_pulse_duration",
                 &S7KWaterColumnCalibration::get_effective_pulse_duration,
                 DOC_S7KWaterColumnCalibration(get_effective_pulse_duration))
            .def("get_system_gain_offset",
                 &S7KWaterColumnCalibration::get_system_gain_offset,
                 DOC_S7KWaterColumnCalibration(get_system_gain_offset))
            .def("is_fm",
                 &S7KWaterColumnCalibration::is_fm,
                 DOC_S7KWaterColumnCalibration(is_fm))

            .def("initialized",
                 &S7KWaterColumnCalibration::initialized,
                 DOC_S7KWaterColumnCalibration(initialized))
            .def("check_initialized",
                 &S7KWaterColumnCalibration::check_initialized,
                 DOC_S7KWaterColumnCalibration(check_initialized))

            .def(
                "pre_hashed",
                [](const S7KWaterColumnCalibration& self) {
                    return boost::flyweight<S7KMultiSectorWaterColumnCalibration>(
                        S7KMultiSectorWaterColumnCalibration({ self }));
                },
                "Return this class as a flyweight with computed hash. "
                "This is faster when updating the ping calibration.")

            // ----- operators -----
            .def("__eq__",
                 &S7KWaterColumnCalibration::operator==,
                 DOC_S7KWaterColumnCalibration(operator_eq),
                 nb::arg("other"))
        // ----- nanobind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(S7KWaterColumnCalibration)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(S7KWaterColumnCalibration)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(S7KWaterColumnCalibration)
        // end S7KWaterColumnCalibration
        ;

    // add multisector calibration
    pingprocessing::pymodule::py_datatypes::py_calibration::init_multisectorcalibration<
        S7KWaterColumnCalibration>(m, "S7KMultiSectorWaterColumnCalibration");
}

} // namespace py_calibration
} // namespace py_filedatatypes
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
