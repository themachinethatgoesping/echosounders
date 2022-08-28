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

#define __INPUTFILEITERATOR_DEFAULT_CONSTRUCTORS__(T_CLASS)                                        \
    .def(py::init<>(const std::vector<std::string>&,                                               \
                    const std::vector<PackageInfo<t_DatagramIdentifier>>&),                        \
         DOC(themachinethatgoesping,                                                               \
             echosounders,                                                                         \
             fileinterfaces,                                                                       \
             I_InputFileIterator,                                                                  \
             I_InputFileIterator),                                                                 \
         py::arg("file_path"),                                                                     \
         py::arg("package_infos"))