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
    DOC(themachinethatgoesping, echosounders, kongsbergall, KongsbergAllAmpltitudeConverter, ARG)

template<typename T_type, size_t dim>
void create_c_kongsbergallamplitudeconverter(pybind11::module& m)
{
    using t_tensor = xt::pytensor<T_type, dim>;
    using t_class  = KongsbergAllAmpltitudeConverter<t_tensor>;

    std::string name =
        fmt::format("KongsbergAllAmpltitudeConverter_{}d_{}", dim, typeid(T_type).name());

    py::class_<t_class, std::shared_ptr<t_class>>(
        m,
        name.c_str(),
        DOC(themachinethatgoesping, echosounders, kongsbergall, KongsbergAllAmpltitudeConverter))
        .def(py::init<t_tensor, float, float, float, float, float>(),
             py::arg("sample_numbers"),
             py::arg("sample_interval"),
             py::arg("tvg_factor_applied"),
             py::arg("effective_pulse_length"),
             py::arg("sound_velocity"),
             py::arg("tvg_offset"),
             DOC_KongsbergAllAmpltitudeConverter(KongsbergAllAmpltitudeConverter))
        .def(py::init<t_tensor, float, float, float, float>(),
             py::arg("ranges"),
             py::arg("tvg_factor_applied"),
             py::arg("effective_pulse_length"),
             py::arg("sound_velocity"),
             py::arg("tvg_offset"),
             DOC_KongsbergAllAmpltitudeConverter(KongsbergAllAmpltitudeConverter_2))
        .def(py::init<t_tensor, float, float, t_tensor, float>(),
             py::arg("ranges"),
             py::arg("tvg_factor_applied"),
             py::arg("effective_pulse_length"),
             py::arg("sound_velocity"),
             py::arg("tvg_offset"),
             DOC_KongsbergAllAmpltitudeConverter(KongsbergAllAmpltitudeConverter_3))

        // --- setters ---
        .def("set_range_factor",
             py::overload_cast<const t_tensor&, float, float, float>(&t_class::set_range_factor),
             py::arg("sample_numbers"),
             py::arg("sample_interval"),
             py::arg("sound_velocity"),
             py::arg("tvg_factor_applied"),
             DOC_KongsbergAllAmpltitudeConverter(set_range_factor))
        .def("set_range_factor",
             py::overload_cast<const t_tensor&, float>(&t_class::set_range_factor),
             py::arg("ranges"),
             py::arg("tvg_factor_applied"),
             DOC_KongsbergAllAmpltitudeConverter(set_range_factor_2))
        .def("set_pulse_factor",
             py::overload_cast<float, float>(&t_class::set_pulse_factor),
             py::arg("sound_velocity"),
             py::arg("effective_pulse_length"),
             DOC_KongsbergAllAmpltitudeConverter(set_pulse_factor))
        .def("set_pulse_factor",
             py::overload_cast<const t_tensor&, float>(&t_class::set_pulse_factor),
             py::arg("sound_velocity"),
             py::arg("effective_pulse_length"),
             DOC_KongsbergAllAmpltitudeConverter(set_pulse_factor_2))
        .def("set_static_factor",
             py::overload_cast<float>(&t_class::set_static_factor),
             py::arg("system_gain_offset"),
             DOC_KongsbergAllAmpltitudeConverter(set_static_factor))

        // --- getters ---
        .def("get_total_compensation_factor",
             &t_class::get_total_compensation_factor,
             DOC_KongsbergAllAmpltitudeConverter(get_total_compensation_factor))
        .def("get_range_factor",
             &t_class::get_range_factor,
             DOC_KongsbergAllAmpltitudeConverter(get_range_factor))
        .def("get_pulse_factor",
             &t_class::get_pulse_factor,
             DOC_KongsbergAllAmpltitudeConverter(get_pulse_factor))
        .def("get_static_factor",
             &t_class::get_static_factor,
             DOC_KongsbergAllAmpltitudeConverter(get_static_factor))

        // --- operators ---
        .def("__call__",
             &t_class::operator(),
             DOC_KongsbergAllAmpltitudeConverter(operator_call),
             py::arg("amplitudes"))

        .def("__eq__",
             &t_class::operator==,
             DOC_KongsbergAllAmpltitudeConverter(operator_eq),
             py::arg("other"))

        .def("compute_total_compensation_factor",
             &t_class::compute_total_compensation_factor,
             DOC_KongsbergAllAmpltitudeConverter(compute_total_compensation_factor))

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

void init_c_kongsbergallamplitudeconverter(pybind11::module& m)
{
    create_c_kongsbergallamplitudeconverter<float, 1>(m);
    create_c_kongsbergallamplitudeconverter<float, 2>(m);
    create_c_kongsbergallamplitudeconverter<double, 1>(m);
    create_c_kongsbergallamplitudeconverter<double, 2>(m);
}

}
}
}
}