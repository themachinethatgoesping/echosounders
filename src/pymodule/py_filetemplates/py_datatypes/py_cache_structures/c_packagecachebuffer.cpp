// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/datetime.hpp>

#include <themachinethatgoesping/echosounders/filetemplates/datatypes/cache_structures/packagecachebuffer.hpp>
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_parameter_channel.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {
namespace py_cache_structures {

#define DOC_PackageCacheBuffer(ARG)                                                                \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datatypes,                                                                                 \
        cache_structures,                                                                          \
        PackageCacheBuffer,                                                                        \
        ARG)

template<typename t_CachedPackage>
void init_packagecachebuffer(pybind11::module& m, const std::string& typestr = "")
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes::
        cache_structures;

    using t_PackageCacheBuffer = PackageCacheBuffer<t_CachedPackage>;

    auto cls = py::class_<t_PackageCacheBuffer, std::shared_ptr<t_PackageCacheBuffer>>(
                   m,
                   fmt::format("PackageCacheBuffer<{}>", typestr).c_str(),
                   DOC(themachinethatgoesping,
                       echosounders,
                       filetemplates,
                       datatypes,
                       cache_structures,
                       PackageCacheBuffer))
                   .def(py::init<>(), DOC_PackageCacheBuffer(PackageCacheBuffer))
                   .def("__eq__",
                        &t_PackageCacheBuffer::operator==,
                        DOC_PackageCacheBuffer(operator_eq),
                        py::arg("other"))

                   // ----- ping interface -----
                   // define init

                   // --- variable access ---
                   .def("add_package",
                        &t_PackageCacheBuffer::template add_package<t_CachedPackage>,
                        DOC_PackageCacheBuffer(add_package_2),
                        py::arg("file_pos"),
                        py::arg("timestamp"),
                        py::arg("package"),
                        py::arg("sub_package_nr") = 0)
                   .def("get_package",
                        &t_PackageCacheBuffer::get_package,
                        DOC_PackageCacheBuffer(get_package),
                        py::arg("file_pos"),
                        py::arg("timestamp"),
                        py::arg("sub_package_nr") = 0)

                   .def("get_hash_cache",
                        &t_PackageCacheBuffer::get_hash_cache,
                        DOC_PackageCacheBuffer(get_hash_cache))
                   .def("get_package_buffer",
                        &t_PackageCacheBuffer::get_package_buffer,
                        DOC_PackageCacheBuffer(get_package_buffer))

               // ----- pybind macros -----
               // default copy functions
               __PYCLASS_DEFAULT_COPY__(t_PackageCacheBuffer)
               // default binary functions
               __PYCLASS_DEFAULT_BINARY__(t_PackageCacheBuffer)
               // default printing functions
               __PYCLASS_DEFAULT_PRINTING__(t_PackageCacheBuffer)
        // end of class definition
        ;
}

void init_c_packagecachebuffer(pybind11::module& m)
{
    init_packagecachebuffer<simradraw::datagrams::xml_datagrams::XML_Parameter_Channel>(
        m, "XML_Parameter_Channel");
}

}
}
}
}
}
}