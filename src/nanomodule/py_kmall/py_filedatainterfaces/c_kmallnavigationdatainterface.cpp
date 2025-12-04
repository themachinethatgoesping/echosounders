// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum/magic_enum.hpp>

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/types.hpp>

#include <themachinethatgoesping/echosounders/kmall/filedatainterfaces/kmallnavigationdatainterface.hpp>

#include "../../py_filetemplates/py_datainterfaces/i_navigationdatainterface.hpp"
#include "c_kmalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_filedatainterfaces {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::kmall;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, kmall, filedatainterfaces,                        \
        KMALLNavigationDataInterface

template<typename T_FileStream>
void py_create_class_KMALLNavigationDataInterface(nanobind::module_& m,
                                                         const std::string& CLASS_NAME)
{
    using py_filetemplates::py_datainterfaces::py_i_navigationdatainterface::
        NavigationDataInterface_add_interface;
    using T_BaseClass = filedatainterfaces::KMALLNavigationDataInterface<T_FileStream>;

    // initialize class
    auto cls = nb::class_<T_BaseClass>(m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX))
        //    .def("set_min_gga_quality",
        //         &T_BaseClass::set_min_gga_quality,
        //         DOC(themachinethatgoesping,
        //             echosounders,
        //             kmall,
        //             filedatainterfaces,
        //             KMALLNavigationDataInterface,
        //             set_min_gga_quality),
        //         nb::arg("min_gga_quality"))
        //    .def("set_max_gga_quality",
        //         &T_BaseClass::set_max_gga_quality,
        //         DOC(themachinethatgoesping,
        //             echosounders,
        //             kmall,
        //             filedatainterfaces,
        //             KMALLNavigationDataInterface,
        //             set_max_gga_quality),
        //         nb::arg("max_gga_quality"))
        //
        ;

    //----- inherit functions from I_NavigationDataInterface -----
    NavigationDataInterface_add_interface<T_BaseClass>(cls);
}

void init_c_kmallnavigationdatainterface(nanobind::module_& m)
{
    static const std::string name        = "KMALLNavigationDataInterface";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_KMALLNavigationDataInterface<std::ifstream>(m, name_stream);
    py_create_class_KMALLNavigationDataInterface<datastreams::MappedFileStream>(m,
                                                                                       name_mapped);
}

}
}
}
}
}