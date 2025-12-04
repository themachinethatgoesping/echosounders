// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/complex.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"
#include "../../../themachinethatgoesping/echosounders/kmall/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/kmall/filedatatypes/kmallpingwatercolumn.hpp"
#include "../../../themachinethatgoesping/echosounders/kmall/types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_KMALLPing(ARG)                                                                  \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kmall,                                                                              \
        filedatatypes,                                                                             \
        KMALLPingWatercolumn,                                                               \
        ARG)

#define DOC_I_PingWatercolumn(ARG)                                                                 \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingWatercolumn, ARG)

template<typename T_FileStream>
void py_create_class_kmallpingwatercolumn(nanobind::module_& m,
                                                 const std::string& CLASS_NAME)
{
    using t_KMALLPingWatercolumn = filedatatypes::KMALLPingWatercolumn<T_FileStream>;

    auto cls =
        nb::class_<t_KMALLPingWatercolumn, datatypes::I_PingWatercolumn>(
            m,
            CLASS_NAME.c_str(),
            DOC(themachinethatgoesping,
                echosounders,
                kmall,
                filedatatypes,
                KMALLPingWatercolumn))

            // --- interface overwrites (necessary when type is changes) ---
            // .def("get_watercolumn_calibration",
            //      nb::overload_cast<>(&t_KMALLPingWatercolumn::get_watercolumn_calibration,
            //                          nb::const_),
            //      DOC_I_PingWatercolumn(get_watercolumn_calibration))
            // .def("get_multisectorwatercolumn_calibration",
            //      &t_KMALLPingWatercolumn::get_multisectorwatercolumn_calibration,
            //      DOC_I_PingWatercolumn(get_multisectorwatercolumn_calibration))
            // .def("update_calibration",
            //      &t_KMALLPingWatercolumn::update_calibration,
            //      DOC_KMALLPing(update_calibration),
            //      nb::arg("calibration_flyweight"))

            // --- pingwatercolumn interface extension ---
            // // --- variable access ---
            // .def("get_tvg_factor_applied",
            //      &t_KMALLPingWatercolumn::get_tvg_factor_applied,
            //      DOC_KMALLPing(get_tvg_factor_applied))
            // .def("get_tvg_offset",
            //      &t_KMALLPingWatercolumn::get_tvg_offset,
            //      DOC_KMALLPing(get_tvg_offset))

            // .def("has_amplitudes",
            //      &t_KMALLPingWatercolumn::has_amplitudes,
            //      DOC_KMALLPing(has_amplitudes))
            // .def("get_raw_amplitudes",
            //      nb::overload_cast<>(
            //          &t_KMALLPingWatercolumn::template get_raw_amplitudes<int8_t>),
            //      DOC_KMALLPing(get_raw_amplitudes))
            // .def("get_raw_amplitudes",
            //      nb::overload_cast<const pingtools::BeamSampleSelection&>(
            //          &t_KMALLPingWatercolumn::template get_raw_amplitudes<int8_t>),
            //      DOC_KMALLPing(get_raw_amplitudes),
            //      nb::arg("beam_selection"))
            // .def("get_raw_amplitudes_float",
            //      nb::overload_cast<>(
            //          &t_KMALLPingWatercolumn::template get_raw_amplitudes<float>),
            //      DOC_KMALLPing(get_raw_amplitudes))
            // .def("get_raw_amplitudes_float",
            //      nb::overload_cast<const pingtools::BeamSampleSelection&>(
            //          &t_KMALLPingWatercolumn::template get_raw_amplitudes<float>),
            //      DOC_KMALLPing(get_raw_amplitudes),
            //      nb::arg("beam_selection"))

        // ----- operators -----
        // .def("__eq__",
        //      &KMALLPingWatercolumn::operator==,
        //      DOC(themachinethatgoesping, echosounders, kmall, filedatatypes,
        //      KMALLPingWatercolumn, operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_KMALLPingWatercolumn)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(KMALLPingWatercolumn)
        // default printing functions
        // __PYCLASS_DEFAULT_PRINTING__(KMALLPingWatercolumn)
        // end KMALLPingWatercolumn
        ;
}

void init_c_kmallpingwatercolumn(nanobind::module_& m)
{
    static const std::string name        = "KMALLPingWatercolumn";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_kmallpingwatercolumn<std::ifstream>(m, name_stream);
    py_create_class_kmallpingwatercolumn<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}