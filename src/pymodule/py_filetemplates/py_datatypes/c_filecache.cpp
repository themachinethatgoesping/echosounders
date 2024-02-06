// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/filecache.hpp"
//

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {

#define DOC_FileCache(ARG)                                                                         \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, FileCache, ARG)

void init_c_filecache(pybind11::module& m)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;

    auto cls =
        py::class_<FileCache, std::shared_ptr<FileCache>>(
            m,
            "FileCache",
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, FileCache))
            .def(py::init<const std::string&, size_t>(),
                 py::arg("file_name"),
                 py::arg("file_size"),
                 DOC_FileCache(FileCache))
            .def(py::init<const std::string&, const std::string&, size_t>(),
                 py::arg("cache_path"),
                 py::arg("file_name"),
                 py::arg("file_size"),
                 DOC_FileCache(FileCache))
            .def("__eq__", &FileCache::operator==, DOC_FileCache(operator_eq), py::arg("other"))

            // accessors
            .def("get_file_name", &FileCache::get_file_name, DOC_FileCache(file_name))
            .def("get_file_size", &FileCache::get_file_size, DOC_FileCache(file_size))
            .def("get_cache_header", &FileCache::get_cache_header, DOC_FileCache(cache_header))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(FileCache)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(FileCache);
}

}
}
}
}
}