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

#include <themachinethatgoesping/echosounders/filetemplates/datatypes/calibration/amplitudecalibration.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {
namespace py_calibration {

namespace py = pybind11;

#define DOC_AmplitudeCalibration(ARG)                                                              \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datatypes,                                                                                 \
        calibration,                                                                               \
        AmplitudeCalibration,                                                                      \
        ARG)

void init_c_amplitudecalibration(pybind11::module& m)
{
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::calibration;

    // add class
    auto c =
        py::class_<AmplitudeCalibration>(m,
                                         "AmplitudeCalibration",
                                         DOC(themachinethatgoesping,
                                             echosounders,
                                             filetemplates,
                                             datatypes,
                                             calibration,
                                             AmplitudeCalibration))
            .def(py::init<>(), DOC_AmplitudeCalibration(AmplitudeCalibration))
            .def(py::init<float>(),
                 DOC_AmplitudeCalibration(AmplitudeCalibration),
                 py::arg("system_offset"))
            .def(py::init<const AmplitudeCalibration&>(),
                 DOC_AmplitudeCalibration(AmplitudeCalibration))

            // --- get offsets ---
            .def("get_per_beam_offsets",
                 &AmplitudeCalibration::get_per_beam_offsets<xt::pytensor<float, 1>>,
                 DOC_AmplitudeCalibration(get_per_beam_offsets),
                 py::arg("beamangles"))
            .def("get_per_sample_offsets",
                 &AmplitudeCalibration::get_per_sample_offsets<xt::pytensor<float, 1>>,
                 DOC_AmplitudeCalibration(get_per_sample_offsets),
                 py::arg("ranges"))
            .def("apply_beam_sample_correction",
                 &AmplitudeCalibration::apply_beam_sample_correction < xt::pytensor<float, 2>,
                 xt::pytensor<float, 1>,
                 DOC_AmplitudeCalibration(apply_beam_sample_correction_2),
                 py::arg("wci"),
                 py::arg("beam_angles"),
                 py::arg("ranges"),
                 py::arg("absorption_db_m"),
                 py::arg("tvg_factor"),
                 py::arg("mp_cores") = 1)

            .def("inplace_beam_sample_correction",
                 &AmplitudeCalibration::inplace_beam_sample_correction,
                 DOC_AmplitudeCalibration(apply_beam_sample_correction_2),
                 py::arg("wci"),
                 py::arg("beam_angles"),
                 py::arg("ranges"),
                 py::arg("absorption_db_m"),
                 py::arg("tvg_factor"),
                 py::arg("min_beam_index") = std::nullopt,
                 py::arg("max_beam_index") = std::nullopt,
                 py::arg("mp_cores")       = 1)

            // --- convenient data access ---
            .def("get_system_offset",
                 &AmplitudeCalibration::get_system_offset,
                 DOC_AmplitudeCalibration(get_system_offset))
            .def("has_system_offset",
                 &AmplitudeCalibration::has_system_offset,
                 DOC_AmplitudeCalibration(has_system_offset))
            .def("set_system_offset",
                 &AmplitudeCalibration::set_system_offset,
                 DOC_AmplitudeCalibration(set_system_offset),
                 py::arg("value"))
            .def("set_offset_per_beamangle",
                 &AmplitudeCalibration::set_offset_per_beamangle,
                 DOC_AmplitudeCalibration(set_offset_per_beamangle),
                 py::arg("beamangle"),
                 py::arg("offset"))
            .def("has_offset_per_beamangle",
                 &AmplitudeCalibration::has_offset_per_beamangle,
                 DOC_AmplitudeCalibration(has_offset_per_beamangle))
            .def("set_offset_per_range",
                 &AmplitudeCalibration::set_offset_per_range,
                 DOC_AmplitudeCalibration(set_offset_per_range),
                 py::arg("range"),
                 py::arg("offset"))
            .def("has_offset_per_range",
                 &AmplitudeCalibration::has_offset_per_range,
                 DOC_AmplitudeCalibration(has_offset_per_range))

            .def("get_interpolator_offset_per_beamangle",
                 &AmplitudeCalibration::get_interpolator_offset_per_beamangle,
                 DOC_AmplitudeCalibration(get_interpolator_offset_per_beamangle))
            .def("get_interpolator_offset_per_range",
                 &AmplitudeCalibration::get_interpolator_offset_per_range,
                 DOC_AmplitudeCalibration(get_interpolator_offset_per_range))

            .def("get_offset_per_beamangle",
                 py::overload_cast<const std::vector<float>&>(
                     &AmplitudeCalibration::get_offset_per_beamangle),
                 DOC_AmplitudeCalibration(get_offset_per_beamangle),
                 py::arg("beamangle"))
            .def("get_offset_per_beamangle",
                 py::overload_cast<float>(&AmplitudeCalibration::get_offset_per_beamangle,
                                          py::const_),
                 DOC_AmplitudeCalibration(get_offset_per_beamangle),
                 py::arg("beamangle"))
            .def("get_offset_per_range",
                 py::overload_cast<const std::vector<float>&>(
                     &AmplitudeCalibration::get_offset_per_range),
                 DOC_AmplitudeCalibration(get_offset_per_range),
                 py::arg("range"))
            .def("get_offset_per_range",
                 py::overload_cast<float>(&AmplitudeCalibration::get_offset_per_range, py::const_),
                 DOC_AmplitudeCalibration(get_offset_per_range),
                 py::arg("range"))

            // ----- operators -----
            .def("__eq__",
                 &AmplitudeCalibration::operator==,
                 DOC_AmplitudeCalibration(operator_eq),
                 py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(AmplitudeCalibration)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(AmplitudeCalibration)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(AmplitudeCalibration)
        // end AmplitudeCalibration
        ;

    c.def("hash", &AmplitudeCalibration::binary_hash, DOC_AmplitudeCalibration(binary_hash));
    c.def("__hash__", &AmplitudeCalibration::binary_hash, DOC_AmplitudeCalibration(binary_hash));
}
}
}
}
}
}
}