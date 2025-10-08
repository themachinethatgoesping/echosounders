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

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/types.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/filedatatypes/kongsbergallpingbottom.hpp"
#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_KongsbergAllPing(ARG)                                                                        \
    DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes, KongsbergAllPingBottom, ARG)

template<typename T_FileStream>
void py_create_class_kongsbergallpingbottom(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using t_KongsbergAllPingBottom = filedatatypes::KongsbergAllPingBottom<T_FileStream>;

    using t_KongsbergAllPingCommon = filedatatypes::KongsbergAllPingCommon<T_FileStream>;

    auto cls = nb::class_<t_KongsbergAllPingBottom, datatypes::I_PingBottom>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes, KongsbergAllPingBottom))

        // --- pingbottom interface extension ---

        // --- variable access ---
        //.def("is_dual_rx", &t_KongsbergAllPingBottom::is_dual_rx, DOC_KongsbergAllPing(is_dual_rx))

        // ----- operators -----
        // .def("__eq__",
        //      &KongsbergAllPingBottom::operator==,
        //      DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes,  KongsbergAllPingBottom,
        //      operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_KongsbergAllPingBottom)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(KongsbergAllPingBottom)
        // default printing functions
        // __PYCLASS_DEFAULT_PRINTING__(KongsbergAllPingBottom)
        // end KongsbergAllPingBottom
        ;
}

void init_c_kongsbergallpingbottom(nanobind::module_& m)
{
    static const std::string name        = "KongsbergAllPingBottom";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_kongsbergallpingbottom<std::ifstream>(m, name_stream);
    py_create_class_kongsbergallpingbottom<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}