// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pytensor.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/types.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/filedatatypes/kongsbergallpingcommon.hpp"
#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_KongsbergAllPingCommon(ARG)                                                                  \
    DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes, KongsbergAllPingCommon, ARG)

template<typename T_FileStream>
void py_create_class_kongsbergallpingcommon(py::module& m, const std::string& CLASS_NAME)
{
    using t_KongsbergAllPingCommon = filedatatypes::KongsbergAllPingCommon<T_FileStream>;

    auto cls =
        py::class_<t_KongsbergAllPingCommon,
                   std::shared_ptr<t_KongsbergAllPingCommon>>(
            m,
            CLASS_NAME.c_str(),
            DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes, KongsbergAllPingCommon))

            // --- file_data data access ---
            .def_property_readonly("file_data",
                                   py::overload_cast<>(&t_KongsbergAllPingCommon::file_data),
                                   DOC_KongsbergAllPingCommon(file_data),
                                   py::return_value_policy::reference_internal)

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

void init_c_kongsbergallpingcommon(pybind11::module& m)
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