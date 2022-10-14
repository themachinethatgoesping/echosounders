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

// this is currently unused
#define __CLASS_PACKAGEINFO__(PYMODULE, t_DatagramIdentifier)                                      \
    py::class_<PackageInfo<t_DatagramIdentifier, t_ifstream>>(                                                 \
        PYMODULE,                                                                                  \
        #t_DatagramIdentifier "_PackageInfo",                                                      \
        DOC(themachinethatgoesping, echosounders, fileinterfaces, PackageInfo))                    \
        .def(py::init<>())                                                                         \
        .def_readwrite(                                                                            \
            "file_nr",                                                                             \
            &PackageInfo<t_DatagramIdentifier, t_ifstream>::file_nr,                                           \
            DOC(themachinethatgoesping, echosounders, fileinterfaces, PackageInfo, file_nr))       \
        .def_readwrite(                                                                            \
            "file_pos",                                                                            \
            &PackageInfo<t_DatagramIdentifier, t_ifstream>::file_pos,                                          \
            DOC(themachinethatgoesping, echosounders, fileinterfaces, PackageInfo, file_pos))      \
        .def_readwrite(                                                                            \
            "timestamp",                                                                           \
            &PackageInfo<t_DatagramIdentifier, t_ifstream>::timestamp,                                         \
            DOC(themachinethatgoesping, echosounders, fileinterfaces, PackageInfo, timestamp))     \
        .def_readwrite("datagram_identifier",                                                      \
                       &PackageInfo<t_DatagramIdentifier, t_ifstream>::datagram_identifier,                    \
                       DOC(themachinethatgoesping,                                                 \
                           echosounders,                                                           \
                           fileinterfaces,                                                         \
                           PackageInfo,                                                            \
                           datagram_identifier))


}
}
}
}
}