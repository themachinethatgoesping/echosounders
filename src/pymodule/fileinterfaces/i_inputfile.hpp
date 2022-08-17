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

#define __INPUTFILE_INTERFACE__(T_CLASS)                                                           \
    // .def("append_file",                                                                            \
    //      &T_CLASS::append_file,                                                                    \
    //      DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, append_file),      \
    //      py::arg("file_path"))                                                                     \
    //     .def("append_files",                                                                       \
    //          &T_CLASS::append_files,                                                                \
    //          DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, append_files), \
    //          py::arg("file_paths"))
