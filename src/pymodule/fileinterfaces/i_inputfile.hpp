// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../themachinethatgoesping/echosounders/fileinterfaces/i_inputfile.hpp"
//#include "../docstrings.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {

namespace py_fileinterfaces {
namespace py_i_InputFile {

template<typename T_PyClass>
void add_DefaultConstructors(T_PyClass& cls)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::tools::progressbars;

    cls.def(py::init<const std::string&, bool>(),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, I_InputFile),
            py::arg("file_path"),
            py::arg("show_progress") = true);
    cls.def(py::init<const std::string&, I_ProgressBar&>(),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, I_InputFile_2),
            py::arg("file_path"),
            py::arg("progress_bar"));
    cls.def(py::init<const std::vector<std::string>&, bool>(),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, I_InputFile_3),
            py::arg("file_path"),
            py::arg("show_progress") = true);
    cls.def(py::init<const std::vector<std::string>&, I_ProgressBar&>(),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, I_InputFile_4),
            py::arg("file_paths"),
            py::arg("progress_bar"));
}

template<typename T_BaseClass, typename T_PyClass>
void add_FileOpenInterface(T_PyClass& cls)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::tools::progressbars;

    cls.def("append_file",
            py::overload_cast<const std::string&, bool>(&T_BaseClass::append_file),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, append_file),
            py::arg("file_path"),
            py::arg("show_progress") = true);
    cls.def("append_file",
            py::overload_cast<const std::string&, I_ProgressBar&>(&T_BaseClass::append_file),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, append_file),
            py::arg("file_path"),
            py::arg("progress_bar"));
    cls.def("append_files",
            py::overload_cast<const std::vector<std::string>&, bool>(&T_BaseClass::append_files),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, append_file),
            py::arg("file_path"),
            py::arg("show_progress") = true);
    cls.def("append_files",
            py::overload_cast<const std::vector<std::string>&, I_ProgressBar&>(
                &T_BaseClass::append_files),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, append_file),
            py::arg("file_path"),
            py::arg("progress_bar"));
    cls.def("static_datagram_identifier_to_string",
            &T_BaseClass::datagram_identifier_to_string,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_InputFile,
                datagram_identifier_to_string),
            py::arg("datagram_identifier"));
    cls.def("datagram_identifier_info",
            &T_BaseClass::datagram_identifier_info,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_InputFile,
                datagram_identifier_info),
            py::arg("datagram_identifier"));
}

template<typename T_BaseClass,
         typename T_DatagramType,
         typename T_DatagramFactory,
         typename T_PyClass>
void add_PackageReading(T_PyClass& cls)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::tools::progressbars;
    cls.def("size",
            &T_BaseClass::size,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, size));
    cls.def("__len__",
            &T_BaseClass::size,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, size));
    cls.def("__getitem__",
            &T_BaseClass::template get_datagram<T_DatagramType, T_DatagramFactory>,
            // []( T_BaseClass& self, long index) {
            //     return self.template get_datagram<T_DatagramType, T_DatagramFactory>(index);
            // },
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_datagram),
            py::arg("index"));
}

}
}
}
}
}