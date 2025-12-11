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

#include "../../../themachinethatgoesping/echosounders/kmall/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/kmall/types.hpp"
#include "../../../themachinethatgoesping/echosounders/kmall/filedatatypes/kmallpingcommon.hpp"
#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_KMALLPingCommon(ARG)                                                                  \
    DOC(themachinethatgoesping, echosounders, kmall, filedatatypes, KMALLPingCommon, ARG)

template<typename T_FileStream>
void py_create_class_kmallpingcommon(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using t_KMALLPingCommon = filedatatypes::KMALLPingCommon<T_FileStream>;

    auto cls =
        nb::class_<t_KMALLPingCommon>(
            m,
            CLASS_NAME.c_str(),
            DOC(themachinethatgoesping, echosounders, kmall, filedatatypes, KMALLPingCommon))

            // --- file_data data access ---
            .def_prop_ro("file_data",
                         nb::overload_cast<>(&t_KMALLPingCommon::file_data),
                         DOC_KMALLPingCommon(file_data),
                         nb::rv_policy::reference_internal)

        // --- variable access ---
        //.def("is_dual_rx", &t_KMALLPingCommon::is_dual_rx, DOC_KMALLPingCommon(is_dual_rx))

        // ----- operators -----
        // .def("__eq__",
        //      &KMALLPingCommon::operator==,
        //      DOC(themachinethatgoesping, echosounders, kmall, filedatatypes,
        //      KMALLPingCommon, operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_KMALLPingCommon)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(KMALLPingCommon)
        // default printing functions
        // __PYCLASS_DEFAULT_PRINTING__(KMALLPingCommon)
        // end KMALLPingCommon
        ;
}

void init_c_kmallpingcommon(nanobind::module_& m)
{
    static const std::string name        = "KMALLPingCommon";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_kmallpingcommon<std::ifstream>(m, name_stream);
    py_create_class_kmallpingcommon<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}