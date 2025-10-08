// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/raw3datatypes/raw3datatypes.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_raw3_datatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace datagrams::raw3datatypes;

// --- helper defines ---
#define DOC_RAW3DataComplexFloat32(NAME)                                                           \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simradraw,                                                                                 \
        datagrams,                                                                                 \
        raw3datatypes,                                                                             \
        RAW3DataComplexFloat32,                                                                    \
        NAME)

void init_c_raw3datacomplexfloat32(nanobind::module_& m)
{
    nb::class_<RAW3DataComplexFloat32, i_RAW3Data>(m,
                                                   "RAW3DataComplexFloat32",
                                                   DOC(themachinethatgoesping,
                                                       echosounders,
                                                       simradraw,
                                                       datagrams,
                                                       raw3datatypes,
                                                       RAW3DataComplexFloat32))
        .def(nb::init<>(), DOC_RAW3DataComplexFloat32(RAW3DataComplexFloat32))
        .def(nb::init<xt::xtensor<simradraw_float, 3>>(),
             DOC_RAW3DataComplexFloat32(RAW3DataComplexFloat32_2),
             nb::arg("complex_samples"))
        .def("__eq__", &RAW3DataComplexFloat32::operator==, nb::arg("other"))

        .def("get_complex_samples_bfloat16",
             &RAW3DataComplexFloat32::get_complex_samples_bfloat16,
             DOC_RAW3DataComplexFloat32(get_complex_samples_bfloat16),
             nb::arg("max_samples"))
        .def("get_power",
             &RAW3DataComplexFloat32::get_power,
             DOC_RAW3DataComplexFloat32(get_power),
             nb::arg("dB") = false)
        .def("get_coherent_sum",
             &RAW3DataComplexFloat32::get_coherent_sum,
             DOC_RAW3DataComplexFloat32(get_coherent_sum),
             nb::arg("dB") = false)
        .def("get_incoherent_sum",
             &RAW3DataComplexFloat32::get_incoherent_sum,
             DOC_RAW3DataComplexFloat32(get_incoherent_sum),
             nb::arg("dB") = false)
             
        .def("get_angle", &RAW3DataComplexFloat32::get_angle, DOC_RAW3DataComplexFloat32(get_angle))

        .def("get_power_xtensor",
             &RAW3DataComplexFloat32::get_power_xtensor,
             DOC_RAW3DataComplexFloat32(get_power_xtensor),
             nb::arg("dB") = false)
        .def("get_incoherent_sum_xtensor",
             &RAW3DataComplexFloat32::get_incoherent_sum_xtensor,
             DOC_RAW3DataComplexFloat32(get_incoherent_sum_xtensor),
             nb::arg("dB") = false)

        // ----- properties -----
        .def_rw("complex_samples",
                       &RAW3DataComplexFloat32::_complex_samples,
                       DOC_RAW3DataComplexFloat32(complex_samples))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RAW3DataComplexFloat32)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(RAW3DataComplexFloat32)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RAW3DataComplexFloat32)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}