// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp>
#include <themachinethatgoesping/echosounders/s7k/datagrams.hpp>
#include <themachinethatgoesping/echosounders/s7k/filedatatypes/s7kpingwatercolumn.hpp>
#include <themachinethatgoesping/echosounders/s7k/types.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_S7KPingWatercolumn(ARG)                                                                \
    DOC(themachinethatgoesping, echosounders, s7k, filedatatypes, S7KPingWatercolumn, ARG)

template<typename T_FileStream>
void py_create_class_s7kpingwatercolumn(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using t_S7KPingWatercolumn = filedatatypes::S7KPingWatercolumn<T_FileStream>;

    auto cls = nb::class_<t_S7KPingWatercolumn, datatypes::I_PingWatercolumn>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, s7k, filedatatypes, S7KPingWatercolumn))

        // ----- s7k specific: raw (unconverted) water column access -----
        .def("get_raw_amplitudes",
             nb::overload_cast<>(&t_S7KPingWatercolumn::get_raw_amplitudes),
             DOC_S7KPingWatercolumn(get_raw_amplitudes))
        .def("get_raw_amplitudes",
             nb::overload_cast<const pingtools::BeamSampleSelection&>(
                 &t_S7KPingWatercolumn::get_raw_amplitudes),
             DOC_S7KPingWatercolumn(get_raw_amplitudes),
             nb::arg("beam_selection"))
        .def("get_raw_phase",
             nb::overload_cast<>(&t_S7KPingWatercolumn::get_raw_phase),
             DOC_S7KPingWatercolumn(get_raw_phase))
        .def("get_raw_phase",
             nb::overload_cast<const pingtools::BeamSampleSelection&>(
                 &t_S7KPingWatercolumn::get_raw_phase),
             DOC_S7KPingWatercolumn(get_raw_phase),
             nb::arg("beam_selection"))
        .def("get_phase",
             nb::overload_cast<>(&t_S7KPingWatercolumn::get_phase),
             DOC_S7KPingWatercolumn(get_phase))
        .def("get_phase",
             nb::overload_cast<const pingtools::BeamSampleSelection&>(
                 &t_S7KPingWatercolumn::get_phase),
             DOC_S7KPingWatercolumn(get_phase),
             nb::arg("beam_selection"))

        // ----- nanobind macros -----
        __PYCLASS_DEFAULT_COPY__(t_S7KPingWatercolumn)
        //
        ;
}

void init_c_s7kpingwatercolumn(nanobind::module_& m)
{
    static const std::string name        = "S7KPingWatercolumn";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_s7kpingwatercolumn<std::ifstream>(m, name_stream);
    py_create_class_s7kpingwatercolumn<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}
