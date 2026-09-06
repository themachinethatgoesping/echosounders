// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/types.hpp>

#include <themachinethatgoesping/echosounders/s7k/filedatainterfaces/s7knavigationdatainterface.hpp>

#include "../../py_filetemplates/py_datainterfaces/i_navigationdatainterface.hpp"
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
    themachinethatgoesping, echosounders, s7k, filedatainterfaces, S7KNavigationDataInterface

template<typename T_FileStream>
void py_create_class_S7KNavigationDataInterface(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using py_filetemplates::py_datainterfaces::py_i_navigationdatainterface::
        NavigationDataInterface_add_interface;

    using T_BaseClass = filedatainterfaces::S7KNavigationDataInterface<T_FileStream>;

    // initialize class
    auto cls = nb::class_<T_BaseClass>(m, CLASS_NAME.c_str(), DOC(LOCAL_DOC_PREFIX));

    //----- inherit functions from I_NavigationDataInterface -----
    NavigationDataInterface_add_interface<T_BaseClass>(cls);
}

void init_c_s7knavigationdatainterface(nanobind::module_& m)
{
    static const std::string name        = "S7KNavigationDataInterface";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_S7KNavigationDataInterface<std::ifstream>(m, name_stream);
    py_create_class_S7KNavigationDataInterface<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}
