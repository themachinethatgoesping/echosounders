// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pytensor.hpp>                 // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/filedatatypes/kongsbergallpingwatercolumn.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_KongsbergAllPing(ARG)                                                                  \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        filedatatypes,                                                                             \
        KongsbergAllPingWatercolumn,                                                               \
        ARG)

template<typename T_FileStream>
void py_create_class_kongsbergallpingwatercolumn(py::module& m, const std::string& CLASS_NAME)
{
    using t_KongsbergAllPingWatercolumn = filedatatypes::KongsbergAllPingWatercolumn<T_FileStream>;

    auto cls =
        py::class_<t_KongsbergAllPingWatercolumn,
                   datatypes::I_PingWatercolumn,
                   filedatatypes::KongsbergAllPingCommon<T_FileStream>,
                   std::shared_ptr<t_KongsbergAllPingWatercolumn>>(m,
                                                                   CLASS_NAME.c_str(),
                                                                   DOC(themachinethatgoesping,
                                                                       echosounders,
                                                                       kongsbergall,
                                                                       filedatatypes,
                                                                       KongsbergAllPingWatercolumn))

            // --- pingwatercolumn interface extension ---

            // --- variable access ---
            .def("get_tvg_factor_applied",
                 &t_KongsbergAllPingWatercolumn::get_tvg_factor_applied,
                 DOC_KongsbergAllPing(get_tvg_factor_applied))
            .def("get_tvg_offset",
                 &t_KongsbergAllPingWatercolumn::get_tvg_offset,
                 DOC_KongsbergAllPing(get_tvg_offset))

            .def("get_raw_amplitudes",
                 py::overload_cast<>(&t_KongsbergAllPingWatercolumn::template get_raw_amplitudes<int8_t>),
                 DOC_KongsbergAllPing(get_raw_amplitudes))
            .def("get_raw_amplitudes",
                 py::overload_cast<const pingtools::BeamSampleSelection&>(
                     &t_KongsbergAllPingWatercolumn::template get_raw_amplitudes<int8_t>),
                 DOC_KongsbergAllPing(get_raw_amplitudes),
                 py::arg("beam_selection"))
            .def("get_amplitudes2",
                 py::overload_cast<>(&t_KongsbergAllPingWatercolumn::get_amplitudes2),
                 DOC_KongsbergAllPing(get_amplitudes2))
            .def("get_amplitudes3",
                 py::overload_cast<>(&t_KongsbergAllPingWatercolumn::get_amplitudes2),
                 DOC_KongsbergAllPing(get_amplitudes2))
            .def("get_amplitudes4",
                 py::overload_cast<>(&t_KongsbergAllPingWatercolumn::get_amplitudes2),
                 DOC_KongsbergAllPing(get_amplitudes2))
            .def("get_amplitudes5",
                 py::overload_cast<>(&t_KongsbergAllPingWatercolumn::get_amplitudes2),
                 DOC_KongsbergAllPing(get_amplitudes2))
        // ----- operators -----
        // .def("__eq__",
        //      &KongsbergAllPingWatercolumn::operator==,
        //      DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes,
        //      KongsbergAllPingWatercolumn, operator_eq), py::arg("other"))
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

void init_c_kongsbergallpingwatercolumn(pybind11::module& m)
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