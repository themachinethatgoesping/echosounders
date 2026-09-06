// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/variant.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/types.hpp>

#include <themachinethatgoesping/echosounders/s7k/filedatainterfaces/s7knavigationdatainterfaceperfile.hpp>

#include "../../py_filetemplates/py_datainterfaces/i_navigationdatainterfaceperfile.hpp"
#include "c_s7kdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatainterfaces {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::s7k;

#define LOCAL_DOC_PREFIX                                                                            \
    themachinethatgoesping, echosounders, s7k, filedatainterfaces,                                 \
        S7KNavigationDataInterfacePerFile

template<typename T_FileStream>
void py_create_class_S7KNavigationDataInterfacePerFile(nanobind::module_& m,
                                                       const std::string& CLASS_NAME)
{
    using namespace py_filetemplates::py_datainterfaces;

    using T_BaseClass = filedatainterfaces::S7KNavigationDataInterfacePerFile<T_FileStream>;

    // initialize class
    auto cls = nb::class_<T_BaseClass>(m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX))

                   // ----- datagram preference settings -----
                   .def("get_prefer_navigation_over_position",
                        &T_BaseClass::get_prefer_navigation_over_position,
                        DOC(LOCAL_DOC_PREFIX, get_prefer_navigation_over_position))
                   .def("set_prefer_navigation_over_position",
                        &T_BaseClass::set_prefer_navigation_over_position,
                        DOC(LOCAL_DOC_PREFIX, set_prefer_navigation_over_position),
                        nb::arg("prefer"))
                   .def("get_prefer_attitude_over_rollpitchheave",
                        &T_BaseClass::get_prefer_attitude_over_rollpitchheave,
                        DOC(LOCAL_DOC_PREFIX, get_prefer_attitude_over_rollpitchheave))
                   .def("set_prefer_attitude_over_rollpitchheave",
                        &T_BaseClass::set_prefer_attitude_over_rollpitchheave,
                        DOC(LOCAL_DOC_PREFIX, set_prefer_attitude_over_rollpitchheave),
                        nb::arg("prefer"))
        //
        ;

    //----- inherit functions from I_NavigationDataInterfacePerFile / I_DatagramInterface -----
    py_i_navigationdatainterface::NavigationDataInterfacePerFile_add_interface<T_BaseClass>(cls);
    S7KDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_s7knavigationdatainterfaceperfile(nanobind::module_& m)
{
    static const std::string name        = "S7KNavigationDataInterfacePerFile";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_S7KNavigationDataInterfacePerFile<std::ifstream>(m, name_stream);
    py_create_class_S7KNavigationDataInterfacePerFile<datastreams::MappedFileStream>(m,
                                                                                     name_mapped);
}

}
}
}
}
}
