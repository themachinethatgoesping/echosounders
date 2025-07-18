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
#include "../../../themachinethatgoesping/echosounders/kongsbergall/filedatatypes/kongsbergallpingbottom.hpp"
#include "../../../themachinethatgoesping/echosounders/filetemplates/datastreams/mappedfilestream.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using namespace themachinethatgoesping::echosounders::filetemplates;

#define DOC_KongsbergAllPing(ARG)                                                                        \
    DOC(themachinethatgoesping, echosounders, kongsbergall, filedatatypes, KongsbergAllPingBottom, ARG)

template<typename T_FileStream>
void py_create_class_kongsbergallpingbottom(py::module& m, const std::string& CLASS_NAME)
{
    using t_KongsbergAllPingBottom = filedatatypes::KongsbergAllPingBottom<T_FileStream>;

    auto cls = py::class_<t_KongsbergAllPingBottom,
                          datatypes::I_PingBottom,
                          filedatatypes::KongsbergAllPingCommon<T_FileStream>,
                          std::shared_ptr<t_KongsbergAllPingBottom>>(
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
        //      operator_eq), py::arg("other"))
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

void init_c_kongsbergallpingbottom(pybind11::module& m)
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