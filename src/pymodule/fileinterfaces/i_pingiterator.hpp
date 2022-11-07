// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelpers.hpp>

#include "../../themachinethatgoesping/echosounders/fileinterfaces/i_pingiterator.hpp"
//#include "../docstrings.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_fileinterfaces {
namespace py_i_PingIterator {

template<typename T_BaseClass, typename T_PyClass>
void _PingIterator_add_PackageReading(T_PyClass& cls)
{
    namespace py = pybind11;

    cls.def("size",
            &T_BaseClass::size,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingIterator, size));
    cls.def("__len__",
            &T_BaseClass::size,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingIterator, size));
    cls.def("__getitem__",
            &T_BaseClass::at,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingIterator, at),
            py::arg("index"),
            pybind11::return_value_policy::reference_internal);
    cls.def(
        "__call__",
        &T_BaseClass::operator(),
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingIterator, operator_call),
        py::arg("index_min")  = 0,
        py::arg("index_max")  = std::numeric_limits<size_t>::max(),
        py::arg("index_step") = 1);

    cls.def("max_number_of_samples",
            &T_BaseClass::max_number_of_samples,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_PingIterator,
                max_number_of_samples));
}

template<typename T_BaseClass, typename T_PyClass>
void add_PingIterator(T_PyClass& cls, const std::string& T_NAME)
{
    cls.def_property_readonly(
        ("i_" + T_NAME).c_str(),
        [](const T_BaseClass& self) { return self.pings(); },
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingIterator, pings),
        pybind11::return_value_policy::reference_internal);
}

template<typename T_PingType>
void create_PingIteratorType(pybind11::module& m, const std::string ITERATOR_NAME)
{
    using fileinterfaces::I_PingIterator;
    namespace py = pybind11;

    using T_ITERATOR = I_PingIterator<T_PingType>;

    auto cls_stream = py::class_<T_ITERATOR>(
        m,
        ITERATOR_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingIterator));

    _PingIterator_add_PackageReading<T_ITERATOR>(cls_stream);
}

}
}
}
}
}