// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pytensor.hpp>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../themachinethatgoesping/echosounders/kongsbergall/kongsbergallamplitudeconverter.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;

#define DOC_KongsbergAllAmpltitudeConverter(ARG)                                                   \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        KongsbergAllAmpltitudeConverter,                                                           \
        ARG)

template<typename T_type, typename T_dim>
void init_c_kongsbergallamplitudeconverter(pybind11::module& m)
{
    using t_tensor = xt::pytensor<T_type, T_dim>;

    py::class_<KongsbergAllAmpltitudeConverter<t_tensor>, algorithms::KongsbergAllDatagram>(
        m,
        "KongsbergAllAmpltitudeConverter",
        DOC(themachinethatgoesping,
            echosounders,
            kongsbergall,
            KongsbergAllAmpltitudeConverter))
        .def(py::init<t_tensor, float, float, float, float, float>(),
             py::arg("sample_numbers"),
             py::arg("sample_interval"),
             py::arg("X"),
             py::arg("effective_pulse_length"),
             py::arg("sound_velocity"),
             py::arg("GOFF"),
             DOC_KongsbergAllAmpltitudeConverter(KongsbergAllAmpltitudeConverter))
        .def(py::init<t_tensor, float, float, float, float>(),
             py::arg("ranges"),
             py::arg("X"),
             py::arg("effective_pulse_length"),
             py::arg("sound_velocity"),
             py::arg("GOFF"),
             DOC_KongsbergAllAmpltitudeConverter(KongsbergAllAmpltitudeConverter_2))
        .def(py::init<t_tensor, float, float, t_tensor, float>(),
             py::arg("ranges"),
             py::arg("X"),
             py::arg("effective_pulse_length"),
             py::arg("sound_velocity"),
             py::arg("GOFF"),
             DOC_KongsbergAllAmpltitudeConverter(KongsbergAllAmpltitudeConverter_3))

        // --- setters ---
        .def("set_range_factor",
             py::overload_cast<t_tensor, float, float, float>(
                 &KongsbergAllAmpltitudeConverter::set_range_factor),
             py::arg("sample_numbers"),
             py::arg("sample_interval"),
             py::arg("sound_velocity"),
             py::arg("X"),
             DOC_KongsbergAllAmpltitudeConverter(set_range_factor))
        .def("set_range_factor",
             py::overload_cast<t_tensor, float>(&KongsbergAllAmpltitudeConverter::set_range_factor),
             py::arg("ranges"),
             py::arg("X"),
             DOC_KongsbergAllAmpltitudeConverter(set_range_factor_2))
        .def("set_pulse_factor",
             py::overload_cast<float, float>(&KongsbergAllAmpltitudeConverter::set_pulse_factor),
             py::arg("sound_velocity"),
             py::arg("effective_pulse_length"),
             DOC_KongsbergAllAmpltitudeConverter(set_pulse_factor))
        .def("set_pulse_factor",
             py::overload_cast<t_tensor, float>(&KongsbergAllAmpltitudeConverter::set_pulse_factor),
             py::arg("sound_velocity"),
             py::arg("effective_pulse_length"),
             DOC_KongsbergAllAmpltitudeConverter(set_pulse_factor_2))
        .def("set_static_factor",
             py::overload_cast<float>(&KongsbergAllAmpltitudeConverter::set_static_factor),
             py::arg("system_gain_offset"),
             DOC_KongsbergAllAmpltitudeConverter(set_static_factor))

        // --- getters ---
        .def("get_total_factor",
             &KongsbergAllAmpltitudeConverter::get_total_factor,
             DOC_KongsbergAllAmpltitudeConverter(get_total_factor))
        .def("get_range_factor",
             &KongsbergAllAmpltitudeConverter::get_range_factor,
             DOC_KongsbergAllAmpltitudeConverter(get_range_factor))
        .def("get_pulse_factor",
             &KongsbergAllAmpltitudeConverter::get_pulse_factor,
             DOC_KongsbergAllAmpltitudeConverter(get_pulse_factor))
        .def("get_static_factor",
             &KongsbergAllAmpltitudeConverter::get_static_factor,
             DOC_KongsbergAllAmpltitudeConverter(get_static_factor))

        // --- operators ---
        .def("__call__",
             &KongsbergAllAmpltitudeConverter::operator(),
             DOC_KongsbergAllAmpltitudeConverter(operator_call),
             py::arg("amplitudes"))

        .def("__eq__",
             &KongsbergAllAmpltitudeConverter::operator==,
             DOC_KongsbergAllAmpltitudeConverter(operator_eq),
             py::arg("other"))

        // ----- operators -----
        .def("__eq__",
             &KongsbergAllAmpltitudeConverter::operator==,
             DOC_KongsbergAllAmpltitudeConverter(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(KongsbergAllAmpltitudeConverter)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(KongsbergAllAmpltitudeConverter)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(KongsbergAllAmpltitudeConverter)
        // end LinearInterpolator
        ;
}
}
}
}
}