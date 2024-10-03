// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pytensor.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/datetime.hpp>

#include <themachinethatgoesping/echosounders/filetemplates/datatypes/cache_structures/filepackagecache.hpp>
#include <themachinethatgoesping/echosounders/kongsbergall/datagrams/runtimeparameters.hpp>
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_parameter_channel.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {
namespace py_cache_structures {

#define DOC_FilePackageCache(ARG)                                                                  \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datatypes,                                                                                 \
        cache_structures,                                                                          \
        FilePackageCache,                                                                          \
        ARG)

template<typename t_CachedPackage>
void init_filepackagecache(pybind11::module& m, const std::string& typestr = "")
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::
        cache_structures;

    using t_FilePackageCache = FilePackageCache<t_CachedPackage>;

    auto cls =
        py::class_<t_FilePackageCache, std::shared_ptr<t_FilePackageCache>>(
            m,
            fmt::format("FilePackageCache<{}>", typestr).c_str(),
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datatypes,
                cache_structures,
                FilePackageCache))
            .def(py::init<>(), DOC_FilePackageCache(FilePackageCache))
            .def("__eq__",
                 &t_FilePackageCache::operator==,
                 DOC_FilePackageCache(operator_eq),
                 py::arg("other"))

            // ----- ping interface -----
            // define init

            // --- variable access ---
            .def("get_package",
                 &t_FilePackageCache::get_package,
                 DOC_FilePackageCache(get_package),
                 py::arg("file_pos"),
                 py::arg("timestamp"),
                 py::arg("sub_package_nr") = 0)
            .def("get_packages",
                 &t_FilePackageCache::get_packages,
                 DOC_FilePackageCache(get_packages),
                 py::arg("file_pos"),
                 py::arg("timestamp"))
            .def("get_subpackage_count",
                 &t_FilePackageCache::get_subpackage_count,
                 DOC_FilePackageCache(get_subpackage_count),
                 py::arg("file_pos"))
            .def("has_package",
                 &t_FilePackageCache::has_package,
                 DOC_FilePackageCache(has_package),
                 py::arg("file_pos"))

            .def("get_hash_cache",
                 &t_FilePackageCache::get_hash_cache,
                 DOC_FilePackageCache(get_hash_cache))
            .def("get_package_buffer",
                 &t_FilePackageCache::get_package_buffer,
                 DOC_FilePackageCache(get_package_buffer))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(t_FilePackageCache)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(t_FilePackageCache)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(t_FilePackageCache)
        // end of class definition
        ;
}

void init_c_filepackagecache(pybind11::module& m)
{
    init_filepackagecache<simradraw::datagrams::xml_datagrams::XML_Parameter_Channel>(
        m, "XML_Parameter_Channel");
}

}
}
}
}
}
}