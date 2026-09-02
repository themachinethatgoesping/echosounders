// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "c_s7kdatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_filedatainterfaces {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::s7k;

template<typename T_FileStream>
void py_create_class_S7KDatagramInterface(nanobind::module_& m, const std::string& CLASS_NAME)
{
    using T_BaseClass = filedatainterfaces::S7KDatagramInterface<T_FileStream>;

    // initialize class
    auto cls = nb::class_<T_BaseClass>(
        m,
        CLASS_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, s7k, filedatainterfaces, S7KDatagramInterface));

    //----- inherit functions from I_DatagramInterface -----
    S7KDatagramInterface_add_interface_functions<T_BaseClass>(cls);
}

void init_c_s7kdatagraminterface(nanobind::module_& m)
{
    static const std::string name        = "S7KDatagramInterface";
    static const std::string name_stream = name + "_stream";
    static const std::string name_mapped = name + "";

    py_create_class_S7KDatagramInterface<std::ifstream>(m, name_stream);
    py_create_class_S7KDatagramInterface<datastreams::MappedFileStream>(m, name_mapped);
}

}
}
}
}
}
