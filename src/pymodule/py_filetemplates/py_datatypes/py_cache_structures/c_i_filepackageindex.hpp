#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>


#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/filetemplates/datatypes/cache_structures/filepackageindex.hpp>

#define DOC_FilePackageIndex(ARG)                                                                  \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datatypes,                                                                                 \
        cache_structures,                                                                          \
        FilePackageIndex,                                                                          \
        ARG)

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {
namespace py_cache_structures {

template<typename t_FilePackageIndex>
void add_file_index_types(pybind11::module& m, const std::string& CLASS_NAME)
{
    namespace py = pybind11;

    py::classh<t_FilePackageIndex>(m,
                                   (CLASS_NAME + "_FilePackageIndex").c_str(),
                                   DOC(themachinethatgoesping,
                                       echosounders,
                                       filetemplates,
                                       datatypes,
                                       cache_structures,
                                       FilePackageIndex))
        .def(py::init<>(), DOC_FilePackageIndex(FilePackageIndex))
        // --- processed data access ---
    .def_readwrite("file_path", &t_FilePackageIndex::file_path, DOC_FilePackageIndex(file_path))
    .def_readwrite("file_size", &t_FilePackageIndex::file_size, DOC_FilePackageIndex(file_size))
    .def_readwrite("datagram_info_data",
               &t_FilePackageIndex::datagram_info_data,
               DOC_FilePackageIndex(datagram_info_data))

        // ----- operators -----
        .def("__eq__",
             &t_FilePackageIndex::operator==,
             DOC_FilePackageIndex(operator_eq),
             py::arg("other"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_FilePackageIndex)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(t_FilePackageIndex)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(t_FilePackageIndex);
}

} // namespace py_cache_structures
} // namespace py_datatypes
} // namespace py_filetemplates
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping