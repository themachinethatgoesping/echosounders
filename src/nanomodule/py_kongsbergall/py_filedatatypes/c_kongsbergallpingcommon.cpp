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
#include "../../../themachinethatgoesping/echosounders/kongsbergall/filedatatypes/kongsbergallpingcommon.hpp"
#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_KongsbergAllPingCommon(ARG)                                                                  \
    DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes, KongsbergAllPingCommon, ARG)

template<typename T_FileStream>
void py_create_class_kongsbergallpingcommon(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using t_KongsbergAllPingCommon = filedatatypes::KongsbergAllPingCommon<T_FileStream>;

    auto cls =
        nb::class_<t_KongsbergAllPingCommon>(
            m,
            CLASS_NAME.c_str(),
            DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes, KongsbergAllPingCommon))

            // --- file_data data access ---
            .def_prop_ro("file_data",
                         nb::overload_cast<>(&t_KongsbergAllPingCommon::file_data),
                         DOC_KongsbergAllPingCommon(file_data),
                         nb::rv_policy::reference_internal)

        // --- variable access ---
        //.def("is_dual_rx", &t_KongsbergAllPingCommon::is_dual_rx, DOC_KongsbergAllPingCommon(is_dual_rx))

        // ----- operators -----
        // .def("__eq__",
        //      &KongsbergAllPingCommon::operator==,
        //      DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes,
        //      KongsbergAllPingCommon, operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_KongsbergAllPingCommon)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(KongsbergAllPingCommon)
        // default printing functions
        // __PYCLASS_DEFAULT_PRINTING__(KongsbergAllPingCommon)
        // end KongsbergAllPingCommon
        ;
}

void init_c_kongsbergallpingcommon(nanobind::module_& m)
{
    static const std::string name        = "KongsbergAllPingCommon";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_kongsbergallpingcommon<std::ifstream>(m, name_stream);
    py_create_class_kongsbergallpingcommon<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}