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
    auto c = py::class_<KongsbergAllWaterColumnCalibration,
                        WaterColumnCalibration,
                        std::shared_ptr<KongsbergAllWaterColumnCalibration>>(
                 m,
                 "KongsbergAllWaterColumnCalibration",
                 DOC(themachinethatgoesping,
                     echosounders,
                     kongsbergall,
                     filedatatypes,
                     calibration,
                     KongsbergAllWaterColumnCalibration))
                 .def(py::init<float, float, float, float, float, float, float>(),
                      DOC_KongsbergAllWaterColumnCalibration(KongsbergAllWaterColumnCalibration),
                      py::arg("sound_velocity"),
                      py::arg("effective_pulse_duration"),
                      py::arg("beam_width_transmit"),
                      py::arg("beam_width_receive"),
                      py::arg("system_gain_offset"),
                      py::arg("tvg_absorption_db_m"),
                      py::arg("tvg_factor"))

                 // --- getters / setters ---
                 //    .def("get_absorption_db_m",
                 //         &KongsbergAllWaterColumnCalibration::get_absorption_db_m,
                 //         DOC_KongsbergAllWaterColumnCalibration(get_absorption_db_m))

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