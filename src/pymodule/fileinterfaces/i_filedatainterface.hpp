// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/fileinterfaces/i_filedatainterface.hpp"
//#include "../docstrings.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_fileinterfaces {
namespace py_i_FileDataInterface {

template<typename T_BaseClass, typename T_PyClass>
void FileDataCollection_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    cls.def("init_from_file",
            &T_BaseClass::init_from_file,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_FileDataCollection,
                init_from_file));
    cls.def("get_file_nr",
            &T_BaseClass::get_file_nr,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_FileDataCollection,
                get_file_nr));
    cls.def("get_file_path",
            &T_BaseClass::get_file_path,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_FileDataCollection,
                get_file_path));
}

template<typename T_BaseClass, typename T_PyClass>
void FileDataInterface_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    /* datagram access */
    cls.def_property_readonly(
        "per_file",
        py::overload_cast<>(&T_BaseClass::per_file),
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_FileDataInterface, per_file),
        pybind11::return_value_policy::reference_internal);

    cls.def("init_from_file",
            &T_BaseClass::init_from_file,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_FileDataInterface,
                init_from_file));

    // cls.def(
    //     "per_file",
    //     py::overload_cast<long>(&T_BaseClass::per_file),
    //     DOC(themachinethatgoesping, echosounders, fileinterfaces, I_FileDataInterface,
    //     per_file_2), pybind11::return_value_policy::reference_internal, py::arg("file_nr"));

    // ----- ping convenience functions -----
    /* default copy functions */
    /* __PYCLASS_DEFAULT_COPY__(LinearInterpolator)*/
    /* default binary functions*/
    /* __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)*/
    /* default printing functions */
    cls __PYCLASS_DEFAULT_PRINTING__(T_BaseClass);
}

}
}
}
}
}