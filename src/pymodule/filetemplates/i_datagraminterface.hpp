// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/filetemplates/i_inputfile.hpp"
//#include "../docstrings.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {

namespace py_filetemplates {
namespace py_i_DatagramInterface {

template<typename T_BaseClass, typename T_PyClass>
void add_InterfaceFunctions(T_PyClass& cls)
{
    namespace py = pybind11;

    cls.def("static_datagram_identifier_to_string",
            &T_BaseClass::datagram_identifier_to_string,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                I_DatagramInterface,
                datagram_identifier_to_string),
            py::arg("datagram_identifier"));
    cls.def("datagram_identifier_info",
            &T_BaseClass::datagram_identifier_info,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                I_DatagramInterface,
                datagram_identifier_info),
            py::arg("datagram_identifier"));
}

}
}
}
}
}