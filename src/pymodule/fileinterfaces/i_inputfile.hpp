// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../themachinethatgoesping/echosounders/fileinterfaces/i_inputfile.hpp"
//#include "../docstrings.hpp"

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;

#define __INPUTFILE_DEFAULT_CONSTRUCTORS__(T_CLASS)                                                \
    .def(py::init<const std::string&, bool>(),                                                     \
         py::call_guard<py::scoped_ostream_redirect>(),                                            \
         DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, I_InputFile),      \
         py::arg("file_path"),                                                                     \
         py::arg("show_progress") = true)                                                          \
        .def(                                                                                      \
            py::init<const std::string&, I_ProgressBar&>(),                                        \
            py::call_guard<py::scoped_ostream_redirect>(),                                         \
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, I_InputFile_2), \
            py::arg("file_path"),                                                                  \
            py::arg("progress_bar"))                                                               \
        .def(                                                                                      \
            py::init<const std::vector<std::string>&, bool>(),                                     \
            py::call_guard<py::scoped_ostream_redirect>(),                                         \
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, I_InputFile_3), \
            py::arg("file_path"),                                                                  \
            py::arg("show_progress") = true)                                                       \
        .def(                                                                                      \
            py::init<const std::vector<std::string>&, I_ProgressBar&>(),                           \
            py::call_guard<py::scoped_ostream_redirect>(),                                         \
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, I_InputFile_4), \
            py::arg("file_paths"),                                                                 \
            py::arg("progress_bar"))

#define __INPUTFILE_INTERFACE__(T_CLASS)                                                           \
    .def("append_file",                                                                            \
         py::overload_cast<const std::string&, bool>(&T_CLASS::append_file),                       \
         py::call_guard<py::scoped_ostream_redirect>(),                                            \
         DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, append_file),      \
         py::arg("file_path"),                                                                     \
         py::arg("show_progress") = true)                                                          \
        .def("append_file",                                                                        \
             py::overload_cast<const std::string&, I_ProgressBar&>(&T_CLASS::append_file),         \
             py::call_guard<py::scoped_ostream_redirect>(),                                        \
             DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, append_file),  \
             py::arg("file_path"),                                                                 \
             py::arg("progress_bar"))                                                              \
        .def("append_files",                                                                       \
             py::overload_cast<const std::vector<std::string>&, bool>(&T_CLASS::append_files),     \
             py::call_guard<py::scoped_ostream_redirect>(),                                        \
             DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, append_file),  \
             py::arg("file_path"),                                                                 \
             py::arg("show_progress") = true)                                                      \
        .def("append_files",                                                                       \
             py::overload_cast<const std::vector<std::string>&, I_ProgressBar&>(                   \
                 &T_CLASS::append_files),                                                          \
             py::call_guard<py::scoped_ostream_redirect>(),                                        \
             DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, append_file),  \
             py::arg("file_path"),                                                                 \
             py::arg("progress_bar"))
