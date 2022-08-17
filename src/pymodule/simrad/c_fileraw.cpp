// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>
#include <pybind11/iostream.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../themachinethatgoesping/echosounders/simrad/fileraw.hpp"
#include "../docstrings.hpp"
#include "module.hpp"

#include "../fileinterfaces/i_inputfile.hpp"

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;
using namespace themachinethatgoesping::echosounders::simrad;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

void init_c_fileraw(pybind11::module& m)
{

    py::class_<FileRaw>(
        m,
        "FileRaw",
        DOC(themachinethatgoesping, echosounders, simrad, FileRaw))
        .def(py::init<const std::string&>(),
             py::call_guard<py::scoped_ostream_redirect>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 fileinterfaces,
                 I_InputFile,
                 I_InputFile),
             py::arg("file_path"))

        .def(py::init<const std::string&, I_ProgressBar& >(),
             py::call_guard<py::scoped_ostream_redirect>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 fileinterfaces,
                 I_InputFile,
                 I_InputFile_2),
             py::arg("file_path"),
             py::arg("progressbar"))

        .def(py::init<const std::vector<std::string>&>(),
             py::call_guard<py::scoped_ostream_redirect>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 fileinterfaces,
                 I_InputFile,
                 I_InputFile_3),
             py::arg("file_path"))

        .def(py::init<const std::vector<std::string>&, I_ProgressBar& >(),
             py::call_guard<py::scoped_ostream_redirect>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 fileinterfaces,
                 I_InputFile,
                 I_InputFile_4),
             py::arg("file_paths"),
             py::arg("progressbar"))
        // .def("__call__",
        //      py::overload_cast<double>(&LinearInterpolator::operator()),
        //      DOC(themachinethatgoesping, tools, vectorinterpolators, I_Interpolator, operator_call),
        //      py::arg("target_x"))
        // .def("__call__",
        //      py::overload_cast<const std::vector<double>&>(&LinearInterpolator::operator()),
        //      DOC(themachinethatgoesping,
        //          tools,
        //          vectorinterpolators,
        //          I_Interpolator,
        //          operator_call_2),
        //      py::arg("targets_x"))
        // I_InputFile Interface
        __INPUTFILE_INTERFACE__(FileRaw)
        // default copy functions
        // __PYCLASS_DEFAULT_COPY__(LinearInterpolator)
        // // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)
        // // default printing functions
        // __PYCLASS_DEFAULT_PRINTING__(LinearInterpolator)
        // // end LinearInterpolator
        ;
}
