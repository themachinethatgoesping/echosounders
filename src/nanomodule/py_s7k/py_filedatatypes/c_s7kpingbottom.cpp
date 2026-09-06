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
#include <themachinethatgoesping/echosounders/s7k/filedatatypes/s7kpingbottom.hpp>
#include <themachinethatgoesping/echosounders/s7k/types.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_S7KPingBottom(ARG)                                                                     \
    DOC(themachinethatgoesping, echosounders, s7k, filedatatypes, S7KPingBottom, ARG)

template<typename T_FileStream>
void py_create_class_s7kpingbottom(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using t_S7KPingBottom = filedatatypes::S7KPingBottom<T_FileStream>;

    auto cls = nb::class_<t_S7KPingBottom, datatypes::I_PingBottom>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, s7k, filedatatypes, S7KPingBottom))

        // ----- nanobind macros -----
        __PYCLASS_DEFAULT_COPY__(t_S7KPingBottom)
        //
        ;
}

void init_c_s7kpingbottom(nanobind::module_& m)
{
    static const std::string name        = "S7KPingBottom";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_s7kpingbottom<std::ifstream>(m, name_stream);
    py_create_class_s7kpingbottom<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}
