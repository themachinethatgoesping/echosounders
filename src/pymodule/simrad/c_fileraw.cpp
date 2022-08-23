// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

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

    py::class_<FileRaw>(m, "FileRaw", DOC(themachinethatgoesping, echosounders, simrad, FileRaw))
        __INPUTFILE_DEFAULT_CONSTRUCTORS__(FileRaw)
        __INPUTFILE_INTERFACE__(FileRaw)
        

        // .def("append_file",
        //      py::overload_cast<const std::string&>(&FileRaw::append_file),
        //      DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, append_file),
        //      py::arg("file_path"))
        // .def("append_file",
        //      py::overload_cast<const std::string&, I_ProgressBar&>(&InputFileBase::append_file),
        //      DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, append_file_2),
        //      py::arg("file_path"),
        //      py::arg("progressbar"))
        // .def("__call__",
        //      py::overload_cast<double>(&LinearInterpolator::operator()),
        //      DOC(themachinethatgoesping, tools, vectorinterpolators, I_Interpolator,
        //      operator_call), py::arg("target_x"))
        // .def("__call__",
        //      py::overload_cast<const std::vector<double>&>(&LinearInterpolator::operator()),
        //      DOC(themachinethatgoesping,
        //          tools,
        //          vectorinterpolators,
        //          I_Interpolator,
        //          operator_call_2),
        //      py::arg("targets_x"))
        // I_InputFile Interface
        // default copy functions
        // __PYCLASS_DEFAULT_COPY__(LinearInterpolator)
        // // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(LinearInterpolator)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(FileRaw)
        // end FileRaw
        ;
}
