// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/filetemplates/i_inputfile.hpp"
//

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {

namespace py_filetemplates {
namespace py_i_InputFile {

template<typename T_PyClass>
void add_DefaultConstructors(T_PyClass& cls)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::tools::progressbars;

    cls.def(py::init<const std::string&, bool, bool>(),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFile, I_InputFile),
            py::arg("file_path"),
            py::arg("init")          = true,
            py::arg("show_progress") = true);
    cls.def(py::init<const std::string&, bool, I_ProgressBar&>(),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFile, I_InputFile_2),
            py::arg("file_path"),
            py::arg("init"),
            py::arg("progress_bar"));
    cls.def(py::init<const std::vector<std::string>&, bool, bool>(),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFile, I_InputFile_3),
            py::arg("file_path"),
            py::arg("init")          = true,
            py::arg("show_progress") = true);
    cls.def(py::init<const std::vector<std::string>&, bool, I_ProgressBar&>(),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFile, I_InputFile_4),
            py::arg("file_paths"),
            py::arg("init"),
            py::arg("progress_bar"));
}

template<typename T_BaseClass, typename T_PyClass>
void add_FileOpenInterface(T_PyClass& cls)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::tools::progressbars;

    // deactivate this for now. The problem with append_file is that it is not clear how to handle
    // the interface updates
    //     cls.def("append_file",
    //             py::overload_cast<const std::string&, bool>(&T_BaseClass::append_file),
    //             py::call_guard<py::scoped_ostream_redirect>(),
    //             DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFile,
    //             append_file), py::arg("file_path"), py::arg("show_progress") = true);
    //     cls.def("append_file",
    //             py::overload_cast<const std::string&, I_ProgressBar&>(&T_BaseClass::append_file),
    //             py::call_guard<py::scoped_ostream_redirect>(),
    //             DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFile,
    //             append_file), py::arg("file_path"), py::arg("progress_bar"));
    //     cls.def("append_files",
    //             py::overload_cast<const std::vector<std::string>&,
    //             bool>(&T_BaseClass::append_files), py::call_guard<py::scoped_ostream_redirect>(),
    //             DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFile,
    //             append_file), py::arg("file_path"), py::arg("show_progress") = true);
    //     cls.def("append_files",
    //             py::overload_cast<const std::vector<std::string>&, I_ProgressBar&>(
    //                 &T_BaseClass::append_files),
    //             py::call_guard<py::scoped_ostream_redirect>(),
    //             DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFile,
    //             append_file), py::arg("file_path"), py::arg("progress_bar"));

    cls.def("init_interfaces",
            // (https://github.com/pybind/pybind11/issues/1153)
            (void(T_BaseClass::*)(bool, bool))(&T_BaseClass::init_interfaces),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFile, init_interfaces),
            py::arg("force")         = false,
            py::arg("show_progress") = true);
    cls.def(
        "init_interfaces",
        // (https://github.com/pybind/pybind11/issues/1153)
        (void(T_BaseClass::*)(bool, I_ProgressBar&))(&T_BaseClass::init_interfaces),
        py::call_guard<py::scoped_ostream_redirect>(),
        DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFile, init_interfaces_2),
        py::arg("force"),
        py::arg("progress_bar"));
}

template<typename T_BaseClass, typename T_PyClass>
void add_DefaultContainers(T_PyClass& cls)
{
    namespace py = pybind11;

    cls.def_property_readonly(
        "datagram_interface",
        py::overload_cast<>(&T_BaseClass::datagram_interface, py::const_),
        DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFile, datagram_interface));
}

}
}
}
}
}