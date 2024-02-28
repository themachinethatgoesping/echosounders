// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <xtensor-python/pyarray.hpp> // Numpy bindings
#include <xtensor/xmath.hpp>          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/filedatainterfaces/kongsbergallnavigationdatainterface.hpp"

#include "../../py_filetemplates/py_datainterfaces/i_navigationdatainterface.hpp"
#include "c_kongsbergalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatainterfaces {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

#define LOCAL_DOC_PREFIX                                                                           \
    themachinethatgoesping, echosounders, kongsbergall, filedatainterfaces,                        \
        KongsbergAllNavigationDataInterface

template<typename T_FileStream>
void py_create_class_KongsbergAllNavigationDataInterface(py::module&        m,
                                                         const std::string& CLASS_NAME)
{
    using py_filetemplates::py_datainterfaces::py_i_navigationdatainterface::
        NavigationDataInterface_add_interface;
    using T_BaseClass = filedatainterfaces::KongsbergAllNavigationDataInterface<T_FileStream>;

    // initialize class
    auto cls = py::class_<T_BaseClass>(m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX))
        //    .def("set_min_gga_quality",
        //         &T_BaseClass::set_min_gga_quality,
        //         DOC(themachinethatgoesping,
        //             echosounders,
        //             kongsbergall,
        //             filedatainterfaces,
        //             KongsbergAllNavigationDataInterface,
        //             set_min_gga_quality),
        //         py::arg("min_gga_quality"))
        //    .def("set_max_gga_quality",
        //         &T_BaseClass::set_max_gga_quality,
        //         DOC(themachinethatgoesping,
        //             echosounders,
        //             kongsbergall,
        //             filedatainterfaces,
        //             KongsbergAllNavigationDataInterface,
        //             set_max_gga_quality),
        //         py::arg("max_gga_quality"))
        //
        ;

    //----- inherit functions from I_NavigationDataInterface -----
    NavigationDataInterface_add_interface<T_BaseClass>(cls);
}

void init_c_kongsbergallnavigationdatainterface(pybind11::module& m)
{
    static const std::string name        = "KongsbergAllNavigationDataInterface";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_KongsbergAllNavigationDataInterface<std::ifstream>(m, name_stream);
    py_create_class_KongsbergAllNavigationDataInterface<datastreams::MappedFileStream>(m,
                                                                                       name_mapped);
}

}
}
}
}
}