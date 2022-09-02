// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../themachinethatgoesping/echosounders/fileinterfaces/i_inputfileiterator.hpp"
//#include "../docstrings.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_fileinterfaces {
namespace py_i_InputFileIterator {

#define __CLASS_PACKAGEINFO__(PYMODULE, t_DatagramIdentifier)                                      \
    py::class_<PackageInfo<t_DatagramIdentifier>>(                                                 \
        PYMODULE,                                                                                  \
        #t_DatagramIdentifier "_PackageInfo",                                                      \
        DOC(themachinethatgoesping, echosounders, fileinterfaces, PackageInfo))                    \
        .def(py::init<>())                                                                         \
        .def_readwrite(                                                                            \
            "file_nr",                                                                             \
            &PackageInfo<t_DatagramIdentifier>::file_nr,                                           \
            DOC(themachinethatgoesping, echosounders, fileinterfaces, PackageInfo, file_nr))       \
        .def_readwrite(                                                                            \
            "file_pos",                                                                            \
            &PackageInfo<t_DatagramIdentifier>::file_pos,                                          \
            DOC(themachinethatgoesping, echosounders, fileinterfaces, PackageInfo, file_pos))      \
        .def_readwrite(                                                                            \
            "timestamp",                                                                           \
            &PackageInfo<t_DatagramIdentifier>::timestamp,                                         \
            DOC(themachinethatgoesping, echosounders, fileinterfaces, PackageInfo, timestamp))     \
        .def_readwrite("datagram_identifier",                                                      \
                       &PackageInfo<t_DatagramIdentifier>::datagram_identifier,                    \
                       DOC(themachinethatgoesping,                                                 \
                           echosounders,                                                           \
                           fileinterfaces,                                                         \
                           PackageInfo,                                                            \
                           datagram_identifier))

template<typename T_BaseClass, typename T_PyClass>
void _iterator_add_PackageReading(T_PyClass& cls)
{
    namespace py = pybind11;

    cls.def("size",
            &T_BaseClass::size,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFileIterator, size));
    cls.def("__len__",
            &T_BaseClass::size,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFileIterator, size));
    cls.def("__getitem__",
            &T_BaseClass::at,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFileIterator, at),
            py::arg("index"));
    cls.def("__call__",
            &T_BaseClass::operator(),
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_InputFileIterator,
                operator_call),
            py::arg("index_min")  = 0,
            py::arg("index_max")  = std::numeric_limits<size_t>::max(),
            py::arg("index_step") = 1);
}

template<typename T_BaseClass,
         typename T_DatagramType,
         typename T_DatagramFactory = T_DatagramType,
         typename T_DatagramIdentifier,
         typename T_PyClass>
void add_Iterator(T_PyClass&           cls,
                  T_DatagramIdentifier datagram_identifier,
                  const std::string    T_NAME)
{
    cls.def_property_readonly(
        (std::string("i_") + T_NAME).c_str(),
        [datagram_identifier](const T_BaseClass& self) {
            return self.template get_iterator<T_DatagramType, T_DatagramFactory>(
                datagram_identifier);
        },
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator));
}

template<typename T_BaseClass,
         typename T_DatagramType,
         typename T_DatagramFactory = T_DatagramType,
         typename T_PyClass>
void add_Iterator(T_PyClass& cls, const std::string T_NAME)
{
    cls.def_property_readonly(
        (std::string("i_") + T_NAME).c_str(),
        [](const T_BaseClass& self) {
            return self.template get_iterator<T_DatagramType, T_DatagramFactory>();
        },
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator));
}

template<typename T_DatagramType,
         typename T_DatagramIdentifier,
         typename T_DatagramFactory = T_DatagramType>
void create_IteratorTypes(pybind11::module& m, const std::string ITERATOR_NAME)
{
    using fileinterfaces::I_InputFileIterator;
    using fileinterfaces::MappedFileStream;
    namespace py = pybind11;

    using T_ITERATOR =
        I_InputFileIterator<T_DatagramType, T_DatagramIdentifier, std::ifstream, T_DatagramFactory>;
    using T_ITERATOR_MAPPED = I_InputFileIterator<T_DatagramType,
                                                  T_DatagramIdentifier,
                                                  MappedFileStream,
                                                  T_DatagramFactory>;

    auto cls_stream         = py::class_<T_ITERATOR>(
        m,
        ITERATOR_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFileIterator));

    auto cls_mapped = py::class_<T_ITERATOR_MAPPED>(
        m,
        (ITERATOR_NAME + "_mapped").c_str(),
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFileIterator));


    _iterator_add_PackageReading<T_ITERATOR>(cls_stream);
    _iterator_add_PackageReading<T_ITERATOR_MAPPED>(cls_mapped);
}

}
}
}
}
}