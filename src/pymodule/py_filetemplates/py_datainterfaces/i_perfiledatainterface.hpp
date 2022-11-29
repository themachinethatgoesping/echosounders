// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datainterfaces/i_filedatainterface.hpp"
//#include "../docstrings.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datainterfaces {
namespace py_i_filedatainterface {

template<typename T_BaseClass, typename T_PyClass>
void PerFileDataInterface_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    cls.def("init_from_file",
            &T_BaseClass::init_from_file,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datainterfaces,
                I_PerFileDataInterface,
                init_from_file),
                py::arg("force") = false);
    cls.def("get_file_nr",
            &T_BaseClass::get_file_nr,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datainterfaces,
                I_PerFileDataInterface,
                get_file_nr));
    cls.def("get_file_path",
            &T_BaseClass::get_file_path,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datainterfaces,
                I_PerFileDataInterface,
                get_file_path));
    cls.def("update",
            &T_BaseClass::update,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datainterfaces,
                I_PerFileDataInterface,
                update));
    cls.def("deinitialize",
            &T_BaseClass::deinitialize,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datainterfaces,
                I_PerFileDataInterface,
                deinitialize));
}

}
}
}
}
}
}