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

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::fileinterfaces;

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

#define __INPUTFILEITERATOR_PACKAGE_READING__(T_CLASS)                                             \
    .def("number_of_packages",                                                                     \
         &T_CLASS::number_of_packages,                                                             \
         DOC(themachinethatgoesping,                                                               \
             echosounders,                                                                         \
             fileinterfaces,                                                                       \
             I_InputFileIterator,                                                                  \
             number_of_packages))                                                                  \
        .def("__len__",                                                                            \
             &T_CLASS::number_of_packages,                                                         \
             DOC(themachinethatgoesping,                                                           \
                 echosounders,                                                                     \
                 fileinterfaces,                                                                   \
                 I_InputFileIterator,                                                              \
                 number_of_packages))                                                              \
        .def("__getitem__",                                                                        \
             &T_CLASS::get_datagram,                                                               \
             DOC(themachinethatgoesping,                                                           \
                 echosounders,                                                                     \
                 fileinterfaces,                                                                   \
                 I_InputFileIterator,                                                              \
                 get_datagram),                                                                    \
             py::arg("index"))

#define ADD_ITERATOR(T_CLASS, T_DATAGRAM, T_DATAGRAM_TYPE, T_NAME)                                 \
    .def_property_readonly(                                                                        \
        (std::string("i_") + T_NAME).c_str(),                                                      \
        [](const T_CLASS& self) { return self.get_iterator<T_DATAGRAM>(T_DATAGRAM_TYPE); },        \
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFile, get_iterator))

#define ADD_ITERATOR_TYPE(T_MODULE, T_ITERATOR_NAME, T_DATAGRAM, T_DATAGRAM_TYPE)                  \
    {                                                                                              \
        using T_ITERATOR = I_InputFileIterator<T_DATAGRAM, T_DATAGRAM_TYPE>;                       \
        py::class_<I_InputFileIterator<T_DATAGRAM, T_DATAGRAM_TYPE>>(                              \
            T_MODULE,                                                                              \
            T_ITERATOR_NAME,                                                                       \
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_InputFileIterator))        \
            __INPUTFILEITERATOR_PACKAGE_READING__(T_ITERATOR);                                     \
    }
