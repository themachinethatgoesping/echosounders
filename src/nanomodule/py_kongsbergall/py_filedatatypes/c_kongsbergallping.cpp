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
#include "../../../themachinethatgoesping/echosounders/kongsbergall/filedatatypes/kongsbergallping.hpp"
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
    DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes, KongsbergAllPing, ARG)

template<typename T_FileStream>
void py_create_class_kongsbergallping(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using t_KongsbergAllPing = filedatatypes::KongsbergAllPing<T_FileStream>;

    using t_KongsbergAllPingCommon = filedatatypes::KongsbergAllPingCommon<T_FileStream>;

    auto cls = nb::class_<t_KongsbergAllPing, datatypes::I_Ping>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes, KongsbergAllPing))

        .def_prop_ro("file_data",
                     nb::overload_cast<>(&t_KongsbergAllPingCommon::file_data),
                     DOC(themachinethatgoesping,
                         echosounders,
                         kongsbergall,
                         filedatatypes,
                         KongsbergAllPingCommon,
                         file_data),
                     nb::rv_policy::reference_internal)

        // --- ping interface (with individual documentation) ---

        // --- ping interface extension ---

        // --- variable access ---

        // ----- operators -----
        // .def("__eq__",
        //      &KongsbergAllPing::operator==,
        //      DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes,  KongsbergAllPing,
        //      operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_KongsbergAllPing)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(KongsbergAllPing)
        // default printing functions
        // __PYCLASS_DEFAULT_PRINTING__(KongsbergAllPing)
        // end KongsbergAllPing
        ;
}

void init_c_kongsbergallping(nanobind::module_& m)
{
    static const std::string name        = "KongsbergAllPing";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_kongsbergallping<std::ifstream>(m, name_stream);
    py_create_class_kongsbergallping<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}