// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/unordered_map.h>
#include <nanobind/stl/vector.h>


#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/ostream_redirect.hpp>

#include "../../themachinethatgoesping/echosounders/filetemplates/i_inputfilehandler.hpp"
//

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {

namespace py_filetemplates {
namespace py_i_inputfilehandler {

template<typename T_BaseClass, typename T_PyClass>
void add_default_constructors(T_PyClass& cls)
{
    namespace nb = nanobind;
    using namespace themachinethatgoesping::tools::progressbars;

    cls.def(nb::init<const std::string&,
                     const std::unordered_map<std::string, std::string>&,
                     bool,
                     bool>(),
            nb::call_guard<themachinethatgoesping::tools::nanobind_helper::ostream_redirect>(),
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                I_InputFileHandler,
                I_InputFileHandler),
            nb::arg("file_path"),
            nb::arg("index_paths") = std::unordered_map<std::string, std::string>(),
            nb::arg("init")                       = true,
            nb::arg("show_progress")              = true);
    cls.def(nb::init<const std::string&,
                     const std::unordered_map<std::string, std::string>&,
                     bool,
                     I_ProgressBar&>(),
            nb::call_guard<themachinethatgoesping::tools::nanobind_helper::ostream_redirect>(),
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                I_InputFileHandler,
                I_InputFileHandler_2),
            nb::arg("file_path"),
            nb::arg("index_paths"),
            nb::arg("init"),
            nb::arg("progress_bar"));
    cls.def(nb::init<const std::vector<std::string>&,
                     const std::unordered_map<std::string, std::string>&,
                     bool,
                     bool>(),
            nb::call_guard<themachinethatgoesping::tools::nanobind_helper::ostream_redirect>(),
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                I_InputFileHandler,
                I_InputFileHandler_3),
            nb::arg("file_path"),
            nb::arg("index_paths") = std::unordered_map<std::string, std::string>(),
            nb::arg("init")                       = true,
            nb::arg("show_progress")              = true);
    cls.def(nb::init<const std::vector<std::string>&,
                     const std::unordered_map<std::string, std::string>&,
                     bool,
                     I_ProgressBar&>(),
            nb::call_guard<themachinethatgoesping::tools::nanobind_helper::ostream_redirect>(),
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                I_InputFileHandler,
                I_InputFileHandler_4),
            nb::arg("file_paths"),
            nb::arg("index_paths"),
            nb::arg("init"),
            nb::arg("progress_bar"));
}

template<typename T_BaseClass, typename T_PyClass>
void add_open_file_interface(T_PyClass& cls)
{
    namespace nb = nanobind;
    using namespace themachinethatgoesping::tools::progressbars;

    // deactivate this for now. The problem with append_file is that it is not clear how to handle
    // the interface updates
    //     cls.def("append_file",
    //             nb::overload_cast<const std::string&, bool>(&T_BaseClass::append_file),
    //             nb::call_guard<nb::scoped_ostream_redirect>(),
    //             DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFileHandler,
    //             append_file), nb::arg("file_path"), nb::arg("show_progress") = true);
    //     cls.def("append_file",
    //             nb::overload_cast<const std::string&, I_ProgressBar&>(&T_BaseClass::append_file),
    //             nb::call_guard<nb::scoped_ostream_redirect>(),
    //             DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFileHandler,
    //             append_file), nb::arg("file_path"), nb::arg("progress_bar"));
    //     cls.def("append_files",
    //             nb::overload_cast<const std::vector<std::string>&,
    //             bool>(&T_BaseClass::append_files), nb::call_guard<nb::scoped_ostream_redirect>(),
    //             DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFileHandler,
    //             append_file), nb::arg("file_path"), nb::arg("show_progress") = true);
    //     cls.def("append_files",
    //             nb::overload_cast<const std::vector<std::string>&, I_ProgressBar&>(
    //                 &T_BaseClass::append_files),
    //             nb::call_guard<nb::scoped_ostream_redirect>(),
    //             DOC(themachinethatgoesping, echosounders, filetemplates, I_InputFileHandler,
    //             append_file), nb::arg("file_path"), nb::arg("progress_bar"));
    cls.def("get_index_paths",
            &T_BaseClass::get_index_paths,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                I_InputFileHandler,
                get_index_paths));

    cls.def("init_interfaces",
            // (https://github.com/pybind/pybind11/issues/1153)
            (void(T_BaseClass::*)(bool, bool))(&T_BaseClass::init_interfaces),
            nb::call_guard<themachinethatgoesping::tools::nanobind_helper::ostream_redirect>(),
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                I_InputFileHandler,
                init_interfaces),
            nb::arg("force")         = false,
            nb::arg("show_progress") = true);
    cls.def("init_interfaces",
            // (https://github.com/pybind/pybind11/issues/1153)
            (void(T_BaseClass::*)(bool, I_ProgressBar&))(&T_BaseClass::init_interfaces),
            nb::call_guard<themachinethatgoesping::tools::nanobind_helper::ostream_redirect>(),
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                I_InputFileHandler,
                init_interfaces_2),
            nb::arg("force"),
            nb::arg("progress_bar"));
}

template<typename T_BaseClass, typename T_PyClass>
void add_default_containers(T_PyClass& cls)
{
    namespace nb = nanobind;

    cls.def_prop_ro("datagram_interface",
                              nb::overload_cast<>(&T_BaseClass::datagram_interface, nb::const_),
                              DOC(themachinethatgoesping,
                                  echosounders,
                                  filetemplates,
                                  I_InputFileHandler,
                                  datagram_interface));
}

}
}
}
}
}