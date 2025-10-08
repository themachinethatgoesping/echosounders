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
#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/filedatatypes/kongsbergallpingwatercolumn.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_KongsbergAllPing(ARG)                                                                  \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        filedatatypes,                                                                             \
        KongsbergAllPingWatercolumn,                                                               \
        ARG)

#define DOC_I_PingWatercolumn(ARG)                                                                 \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingWatercolumn, ARG)

template<typename T_FileStream>
void py_create_class_kongsbergallpingwatercolumn(nanobind::module_& m,
                                                 const std::string& CLASS_NAME)
{
    using t_KongsbergAllPingWatercolumn = filedatatypes::KongsbergAllPingWatercolumn<T_FileStream>;

    using t_KongsbergAllPingCommon = filedatatypes::KongsbergAllPingCommon<T_FileStream>;

    auto cls =
        nb::class_<t_KongsbergAllPingWatercolumn, datatypes::I_PingWatercolumn>(
            m,
            CLASS_NAME.c_str(),
            DOC(themachinethatgoesping,
                echosounders,
                kongsbergall,
                filedatatypes,
                KongsbergAllPingWatercolumn))

            // --- interface overwrites (necessary when type is changes) ---
          .def("get_watercolumn_calibration",
              nb::overload_cast<>(&t_KongsbergAllPingWatercolumn::get_watercolumn_calibration,
                              nb::const_),
                 DOC_I_PingWatercolumn(get_watercolumn_calibration))
            .def("get_multisectorwatercolumn_calibration",
                 &t_KongsbergAllPingWatercolumn::get_multisectorwatercolumn_calibration,
                 DOC_I_PingWatercolumn(get_multisectorwatercolumn_calibration))

            // --- pingwatercolumn interface extension ---
            // --- variable access ---
            .def("get_tvg_factor_applied",
                 &t_KongsbergAllPingWatercolumn::get_tvg_factor_applied,
                 DOC_KongsbergAllPing(get_tvg_factor_applied))
            .def("get_tvg_offset",
                 &t_KongsbergAllPingWatercolumn::get_tvg_offset,
                 DOC_KongsbergAllPing(get_tvg_offset))

            .def("has_amplitudes",
                 &t_KongsbergAllPingWatercolumn::has_amplitudes,
                 DOC_KongsbergAllPing(has_amplitudes))
          .def("get_raw_amplitudes",
              nb::overload_cast<>(
                     &t_KongsbergAllPingWatercolumn::template get_raw_amplitudes<int8_t>),
                 DOC_KongsbergAllPing(get_raw_amplitudes))
            .def("get_raw_amplitudes",
              nb::overload_cast<const pingtools::BeamSampleSelection&>(
                     &t_KongsbergAllPingWatercolumn::template get_raw_amplitudes<int8_t>),
                 DOC_KongsbergAllPing(get_raw_amplitudes),
              nb::arg("beam_selection"))
            .def("get_raw_amplitudes_float",
              nb::overload_cast<>(
                     &t_KongsbergAllPingWatercolumn::template get_raw_amplitudes<float>),
                 DOC_KongsbergAllPing(get_raw_amplitudes))
            .def("get_raw_amplitudes_float",
              nb::overload_cast<const pingtools::BeamSampleSelection&>(
                     &t_KongsbergAllPingWatercolumn::template get_raw_amplitudes<float>),
                 DOC_KongsbergAllPing(get_raw_amplitudes),
              nb::arg("beam_selection"))

        // ----- operators -----
        // .def("__eq__",
        //      &KongsbergAllPingWatercolumn::operator==,
        //      DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes,
        //      KongsbergAllPingWatercolumn, operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_KongsbergAllPingWatercolumn)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(KongsbergAllPingWatercolumn)
        // default printing functions
        // __PYCLASS_DEFAULT_PRINTING__(KongsbergAllPingWatercolumn)
        // end KongsbergAllPingWatercolumn
        ;
}

void init_c_kongsbergallpingwatercolumn(nanobind::module_& m)
{
    static const std::string name        = "KongsbergAllPingWatercolumn";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_kongsbergallpingwatercolumn<std::ifstream>(m, name_stream);
    py_create_class_kongsbergallpingwatercolumn<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}