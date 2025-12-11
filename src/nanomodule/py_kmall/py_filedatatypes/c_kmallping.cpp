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
#include "../../../themachinethatgoesping/echosounders/kmall/filedatatypes/kmallping.hpp"
#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_KMALLPing(ARG)                                                                        \
    DOC(themachinethatgoesping, echosounders, kmall, filedatatypes, KMALLPing, ARG)

template<typename T_FileStream>
void py_create_class_kmallping(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using t_KMALLPing = filedatatypes::KMALLPing<T_FileStream>;

    using t_KMALLPingCommon = filedatatypes::KMALLPingCommon<T_FileStream>;

    auto cls = nb::class_<t_KMALLPing, datatypes::I_Ping>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, kmall, filedatatypes, KMALLPing))

        .def_prop_ro("file_data",
                     nb::overload_cast<>(&t_KMALLPingCommon::file_data),
                     DOC(themachinethatgoesping,
                         echosounders,
                         kmall,
                         filedatatypes,
                         KMALLPingCommon,
                         file_data),
                     nb::rv_policy::reference_internal)

        // --- ping interface (with individual documentation) ---

        // --- ping interface extension ---

        // --- variable access ---

        // ----- operators -----
        // .def("__eq__",
        //      &KMALLPing::operator==,
        //      DOC(themachinethatgoesping, echosounders, kmall, filedatatypes,  KMALLPing,
        //      operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_KMALLPing)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(KMALLPing)
        // default printing functions
        // __PYCLASS_DEFAULT_PRINTING__(KMALLPing)
        // end KMALLPing
        ;
}

void init_c_kmallping(nanobind::module_& m)
{
    static const std::string name        = "KMALLPing";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_kmallping<std::ifstream>(m, name_stream);
    py_create_class_kmallping<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}