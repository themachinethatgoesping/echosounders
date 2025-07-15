// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datainterfaces/i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datainterfaces {
namespace py_i_filedatainterface {

#define DOC_FileDataInterfacePerFile(ARG)                                                          \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datainterfaces,                                                                            \
        I_FileDataInterfacePerFile,                                                                \
        ARG)

template<typename T_BaseClass, typename T_PyClass>
void FileDataInterfacePerFile_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    cls.def("init_from_file",
            &T_BaseClass::init_from_file,
            DOC_FileDataInterfacePerFile(init_from_file),
            py::arg("index_path") = "",
            py::arg("force")           = false);
    cls.def("get_file_nr", &T_BaseClass::get_file_nr, DOC_FileDataInterfacePerFile(get_file_nr));
    cls.def("get_linked_file_nr",
            &T_BaseClass::get_linked_file_nr,
            DOC_FileDataInterfacePerFile(get_linked_file_nr));
    cls.def(
        "get_file_path", &T_BaseClass::get_file_path, DOC_FileDataInterfacePerFile(get_file_path));
    cls.def(
        "get_file_name", &T_BaseClass::get_file_name, DOC_FileDataInterfacePerFile(get_file_name));
    cls.def(
        "get_file_size", &T_BaseClass::get_file_size, DOC_FileDataInterfacePerFile(get_file_size));
    cls.def("get_linked_file_path",
            &T_BaseClass::get_linked_file_path,
            DOC_FileDataInterfacePerFile(get_linked_file_path));
    cls.def("deinitialize", &T_BaseClass::deinitialize, DOC_FileDataInterfacePerFile(deinitialize));
    cls.def("is_initialized",
            &T_BaseClass::is_initialized,
            DOC_FileDataInterfacePerFile(is_initialized));
    cls.def("is_primary_file",
            &T_BaseClass::is_primary_file,
            DOC_FileDataInterfacePerFile(is_primary_file));
    cls.def("is_secondary_file",
            &T_BaseClass::is_secondary_file,
            DOC_FileDataInterfacePerFile(is_secondary_file));
    cls.def("has_linked_file",
            &T_BaseClass::has_linked_file,
            DOC_FileDataInterfacePerFile(has_linked_file));
}

}
}
}
}
}
}