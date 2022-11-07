// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelpers.hpp>

#include "../../themachinethatgoesping/echosounders/fileinterfaces/i_ping.hpp"
//#include "../docstrings.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_fileinterfaces {
namespace py_i_Ping {

template<typename T_BaseClass, typename T_PyClass>
void add_ping_data_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    cls.def(
        "get_number_of_samples",
        &T_BaseClass::get_number_of_samples,
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_Ping, get_number_of_samples));
    cls.def("load_data",
            &T_BaseClass::load_data,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_Ping, load_data));
    cls.def("release_data",
            &T_BaseClass::release_data,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_Ping, release_data));
}

}
}
}
}
}