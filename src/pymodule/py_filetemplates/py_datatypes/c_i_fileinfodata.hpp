#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/filetemplates/datatypes/fileinfo.hpp>

#define DOC_FileInfoData(ARG)                                                                      \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, FileInfoData, ARG)

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {

template<typename t_FileInfoData>
void add_file_index_types(pybind11::module& m, const std::string& CLASS_NAME)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::tools::progressbars;

    py::class_<t_FileInfoData>(
        m,
        (CLASS_NAME + "_FileInfoData").c_str(),
        DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, FileInfoData))
        .def(py::init<>(), DOC_FileInfoData(FileInfoData))
        // --- processed data access ---
        .def_readwrite("file_path", &t_FileInfoData::file_path, DOC_FileInfoData(file_path))
        .def_readwrite("file_size", &t_FileInfoData::file_size, DOC_FileInfoData(file_size))
        .def_readwrite(
            "datagram_infos", &t_FileInfoData::datagram_infos, DOC_FileInfoData(datagram_infos))

        // ----- operators -----
        .def("__eq__", &t_FileInfoData::operator==, DOC_FileInfoData(operator_eq), py::arg("other"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_FileInfoData)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(t_FileInfoData)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(t_FileInfoData);
}

} // namespace py_datatypes
} // namespace py_filetemplates
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping