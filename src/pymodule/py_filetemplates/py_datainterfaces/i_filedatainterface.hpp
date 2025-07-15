// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
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
    cls.def_static("sort_by_time",
                   &T_BaseClass::sort_by_time,
                   DOC_FileDataInterface(sort_by_time),
                   py::arg("fileinterfaces"));

    cls.def(
        "per_file", py::overload_cast<>(&T_BaseClass::per_file), DOC_FileDataInterface(per_file));
    cls.def("per_file",
            py::overload_cast<int64_t>(&T_BaseClass::per_file),
            DOC_FileDataInterface(per_file_2),
            pybind11::return_value_policy::reference_internal,
            py::arg("file_nr"));
    cls.def("per_primary_file",
            &T_BaseClass::per_primary_file,
            DOC_FileDataInterface(per_primary_file));
    cls.def("per_secondary_file",
            &T_BaseClass::per_secondary_file,
            DOC_FileDataInterface(per_secondary_file));
    cls.def("verify_linked_file_interfaces_are_consistent",
            &T_BaseClass::verify_linked_file_interfaces_are_consistent,
            DOC_FileDataInterface(verify_linked_file_interfaces_are_consistent));

    cls.def("is_initialized", &T_BaseClass::is_initialized, DOC_FileDataInterface(is_initialized));
    cls.def("deinitialize", &T_BaseClass::deinitialize, DOC_FileDataInterface(deinitialize));

    cls.def("init_from_file",
            // py::overload_cast<bool>(void(T_BaseClass::*)(bool)(&T_BaseClass::init_from_file), //
            // compiler error on windows, but cstyle cast works
            // (https://github.com/pybind/pybind11/issues/1153)
            (void(T_BaseClass::*)(const std::unordered_map<std::string, std::string>&, bool, bool))(
                &T_BaseClass::init_from_file),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC_FileDataInterface(init_from_file),
            py::arg("index_paths") = std::unordered_map<std::string, std::string>(),
            py::arg("force")                      = false,
            py::arg("show_progress")              = true);
    cls.def("init_from_file",
            // py::overload_cast<I_ProgressBar&>(&T_BaseClass::init_from_file),
            (void(T_BaseClass::*)(
                const std::unordered_map<std::string, std::string>&, bool, I_ProgressBar&, bool))(
                &T_BaseClass::init_from_file),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC_FileDataInterface(init_from_file_2),
            py::arg("index_paths"),
            py::arg("force"),
            py::arg("progress_bar"),
            py::arg("external_progress_tick") = false);

    cls.def("deinitialize", &T_BaseClass::deinitialize, DOC_FileDataInterface(deinitialize));
    cls.def("is_initialized", &T_BaseClass::is_initialized, DOC_FileDataInterface(is_initialized));

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