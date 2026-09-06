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
#include <themachinethatgoesping/echosounders/s7k/filedatatypes/s7kping.hpp>
#include <themachinethatgoesping/echosounders/s7k/types.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_S7KPing(ARG) DOC(themachinethatgoesping, echosounders, s7k, filedatatypes, S7KPing, ARG)

template<typename T_FileStream>
void py_create_class_s7kping(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using t_S7KPing       = filedatatypes::S7KPing<T_FileStream>;
    using t_S7KPingCommon = filedatatypes::S7KPingCommon<T_FileStream>;

    auto cls = nb::class_<t_S7KPing, datatypes::I_Ping>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, s7k, filedatatypes, S7KPing))

        // --- file_data access ---
        .def_prop_ro(
            "file_data",
            nb::overload_cast<>(&t_S7KPingCommon::file_data),
            DOC(themachinethatgoesping, echosounders, s7k, filedatatypes, S7KPingCommon, file_data),
            nb::rv_policy::reference_internal)

        // ----- nanobind macros -----
        __PYCLASS_DEFAULT_COPY__(t_S7KPing)
        //
        ;
}

void init_c_s7kping(nanobind::module_& m)
{
    static const std::string name        = "S7KPing";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_s7kping<std::ifstream>(m, name_stream);
    py_create_class_s7kping<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}
