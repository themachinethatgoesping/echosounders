// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/fileinterfaces/i_datagramcontainer.hpp"
//#include "../docstrings.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_fileinterfaces {
namespace py_i_DatagramContainer {

template<typename T_BaseClass, typename T_PyClass>
void _iterator_add_DatagramReading(T_PyClass& cls)
{
    namespace py = pybind11;

    cls.def("size",
            &T_BaseClass::size,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_DatagramContainer, size));
    cls.def("__len__",
            &T_BaseClass::size,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_DatagramContainer, size));
    cls.def("__getitem__",
            &T_BaseClass::at,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_DatagramContainer, at),
            py::arg("index"));
    cls.def("__call__",
            &T_BaseClass::operator(),
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_DatagramContainer,
                operator_call),
            py::arg("start") = 0,
            py::arg("end")   = std::numeric_limits<size_t>::max(),
            py::arg("step")  = 1);
}

template<typename T_DatagramType,
         typename T_DatagramIdentifier,
         typename T_DatagramFactory = T_DatagramType>
void create_IteratorTypes(pybind11::module& m, const std::string ITERATOR_NAME)
{
    using fileinterfaces::I_DatagramContainer;
    using fileinterfaces::MappedFileStream;
    namespace py = pybind11;

    using T_ITERATOR =
        I_DatagramContainer<T_DatagramType, T_DatagramIdentifier, std::ifstream, T_DatagramFactory>;
    using T_ITERATOR_MAPPED = I_DatagramContainer<T_DatagramType,
                                                  T_DatagramIdentifier,
                                                  MappedFileStream,
                                                  T_DatagramFactory>;

    auto cls_stream = py::class_<T_ITERATOR>(
        m,
        ITERATOR_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_DatagramContainer));

    auto cls_mapped = py::class_<T_ITERATOR_MAPPED>(
        m,
        (ITERATOR_NAME + "_mapped").c_str(),
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_DatagramContainer));

    _iterator_add_DatagramReading<T_ITERATOR>(cls_stream);
    _iterator_add_DatagramReading<T_ITERATOR_MAPPED>(cls_mapped);
}

}
}
}
}
}