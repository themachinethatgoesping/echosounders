// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datainterfaces/i_filedatainterface.hpp"
#include "i_filedatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datainterfaces {
namespace py_i_filedatainterface {

#define DOC_FileDataInterface(ARG)                                                                 \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datainterfaces,                                                                            \
        I_FileDataInterface,                                                                       \
        ARG)

template<typename T_BaseClass, typename T_PyClass>
void FileDataInterface_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::tools::progressbars;

    /* datagram access */
    cls.def("per_file",
            py::overload_cast<>(&T_BaseClass::per_file),
            DOC_FileDataInterface(per_file));
    cls.def("per_file",
            py::overload_cast<long>(&T_BaseClass::per_file),
            DOC_FileDataInterface(per_file_2),
            pybind11::return_value_policy::reference_internal,
            py::arg("file_nr"));

    cls.def("init_from_file",
            // py::overload_cast<bool>(void(T_BaseClass::*)(bool)(&T_BaseClass::init_from_file), //
            // compiler error on windows, but cstyle cast works
            // (https://github.com/pybind/pybind11/issues/1153)
            (void(T_BaseClass::*)(bool, bool))(&T_BaseClass::init_from_file),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC_FileDataInterface(init_from_file),
            py::arg("force")         = false,
            py::arg("show_progress") = true);
    cls.def("init_from_file",
            // py::overload_cast<I_ProgressBar&>(&T_BaseClass::init_from_file),
            (void(T_BaseClass::*)(bool, I_ProgressBar&))(&T_BaseClass::init_from_file),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC_FileDataInterface(init_from_file_2),
            py::arg("force"),
            py::arg("progress_bar"));

    cls.def("deinitialize", &T_BaseClass::deinitialize, DOC_FileDataInterface(deinitialize));
    cls.def("initialized", &T_BaseClass::initialized, DOC_FileDataInterface(initialized));

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
}