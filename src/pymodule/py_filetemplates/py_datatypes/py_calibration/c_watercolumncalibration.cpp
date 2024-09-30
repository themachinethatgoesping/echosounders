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
    auto c = py::class_<WaterColumnCalibration, std::shared_ptr<WaterColumnCalibration>>(
                 m,
                 "WaterColumnCalibration",
                 DOC(themachinethatgoesping,
                     echosounders,
                     filetemplates,
                     datatypes,
                     calibration,
                     WaterColumnCalibration))
                 .def(py::init<>(), DOC_WaterColumnCalibration(WaterColumnCalibration))
                 .def(py::init<const AmplitudeCalibration&,
                               const AmplitudeCalibration&,
                               const AmplitudeCalibration&>(),
                      DOC_WaterColumnCalibration(WaterColumnCalibration),
                      py::arg("power_calibration") = AmplitudeCalibration(),
                      py::arg("ap_calibration")    = AmplitudeCalibration(),
                      py::arg("av_calibration")    = AmplitudeCalibration())
                 .def(py::init<const WaterColumnCalibration&>(),
                      DOC_WaterColumnCalibration(WaterColumnCalibration))

                 // --- getters / setters ---
                 .def("get_absorption_db_m",
                      &WaterColumnCalibration::get_absorption_db_m,
                      DOC_WaterColumnCalibration(get_absorption_db_m))
                 .def("get_tvg_absorption_db_m",
                      &WaterColumnCalibration::get_tvg_absorption_db_m,
                      DOC_WaterColumnCalibration(get_tvg_absorption_db_m))
                 .def("get_tvg_factor",
                      &WaterColumnCalibration::get_tvg_factor,
                      DOC_WaterColumnCalibration(get_tvg_factor))

                 // --- convenient data access ---
                 .def("has_power_calibration",
                      &WaterColumnCalibration::has_power_calibration,
                      DOC_WaterColumnCalibration(has_power_calibration))
                 .def("has_ap_calibration",
                      &WaterColumnCalibration::has_ap_calibration,
                      DOC_WaterColumnCalibration(has_ap_calibration))
                 .def("has_av_calibration",
                      &WaterColumnCalibration::has_av_calibration,
                      DOC_WaterColumnCalibration(has_av_calibration))
                 .def("has_sp_calibration",
                      &WaterColumnCalibration::has_sp_calibration,
                      DOC_WaterColumnCalibration(has_sp_calibration))
                 .def("has_sv_calibration",
                      &WaterColumnCalibration::has_sv_calibration,
                      DOC_WaterColumnCalibration(has_sv_calibration))
                 .def("get_power_calibration",
                      &WaterColumnCalibration::get_power_calibration,
                      DOC_WaterColumnCalibration(get_power_calibration))
                 .def("set_power_calibration",
                      &WaterColumnCalibration::set_power_calibration,
                      DOC_WaterColumnCalibration(set_power_calibration),
                      py::arg("calibration"))
                 .def("set_ap_calibration",
                      &WaterColumnCalibration::set_ap_calibration,
                      DOC_WaterColumnCalibration(set_ap_calibration),
                      py::arg("calibration"))
                 .def("set_av_calibration",
                      &WaterColumnCalibration::set_av_calibration,
                      DOC_WaterColumnCalibration(set_av_calibration),
                      py::arg("calibration"))
                 .def("set_sp_calibration",
                      &WaterColumnCalibration::set_sp_calibration,
                      DOC_WaterColumnCalibration(set_sp_calibration),
                      py::arg("calibration"))
                 .def("set_sv_calibration",
                      &WaterColumnCalibration::set_sv_calibration,
                      DOC_WaterColumnCalibration(set_sv_calibration),
                      py::arg("calibration"))

                 .def("initialized",
                      &WaterColumnCalibration::initialized,
                      DOC_WaterColumnCalibration(initialized))

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

    c.def("cached_hash",
          &WaterColumnCalibration::cached_hash,
          DOC_WaterColumnCalibration(cached_hash));
    c.def("hash", &WaterColumnCalibration::cached_hash, DOC_WaterColumnCalibration(cached_hash));
    c.def(
        "__hash__", &WaterColumnCalibration::cached_hash, DOC_WaterColumnCalibration(cached_hash));
}
}
}
}
}
}
}