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
#include "../../../themachinethatgoesping/echosounders/kmall/filedatatypes/kmallpingbottom.hpp"
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
    DOC(themachinethatgoesping, echosounders, kmall, filedatatypes, KMALLPingBottom, ARG)

template<typename T_FileStream>
void py_create_class_kmallpingbottom(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using t_KMALLPingBottom = filedatatypes::KMALLPingBottom<T_FileStream>;

    auto cls = nb::class_<t_KMALLPingBottom, datatypes::I_PingBottom>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, kmall, filedatatypes, KMALLPingBottom))

        // --- pingbottom interface extension ---

        // --- variable access ---
        //.def("is_dual_rx", &t_KMALLPingBottom::is_dual_rx, DOC_KMALLPing(is_dual_rx))

        // ----- operators -----
        // .def("__eq__",
        //      &KMALLPingBottom::operator==,
        //      DOC(themachinethatgoesping, echosounders, kmall, filedatatypes,  KMALLPingBottom,
        //      operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_KMALLPingBottom)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(KMALLPingBottom)
        // default printing functions
        // __PYCLASS_DEFAULT_PRINTING__(KMALLPingBottom)
        // end KMALLPingBottom
        ;
}

void init_c_kmallpingbottom(nanobind::module_& m)
{
    static const std::string name        = "KMALLPingBottom";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_kmallpingbottom<std::ifstream>(m, name_stream);
    py_create_class_kmallpingbottom<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}