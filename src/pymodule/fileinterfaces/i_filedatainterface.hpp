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
void FileDataInterface_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    /* package access */
    cls.def_property_readonly("package_data_interface_per_file",
                              &T_BaseClass::package_data_interface_per_file,
                              DOC(themachinethatgoesping,
                                  echosounders,
                                  fileinterfaces,
                                  I_FileDataInterface,
                                  package_data_interface_per_file),
                              pybind11::return_value_policy::reference_internal);
}

}
}
}
}
}