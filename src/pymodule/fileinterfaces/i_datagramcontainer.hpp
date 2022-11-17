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

template<typename T_BaseClass, typename T_DatagramIdentifier, typename T_PyClass>
void _add_DatagramReading(T_PyClass& cls)
{
    namespace py = pybind11;

    /* get datagram infos */

    /* implement breakers */
    cls.def("break_by_time_diff",
            &T_BaseClass::break_by_time_diff,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_DatagramContainer,
                break_by_time_diff),
            py::arg("max_time_diff_seconds"));

    /* implement sorters */
    cls.def("get_sorted_by_time",
            &T_BaseClass::get_sorted_by_time,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_DatagramContainer,
                get_sorted_by_time));

    /* implement find info functions */
    cls.def("count_datagrams_per_type",
            &T_BaseClass::count_datagrams_per_type,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_DatagramContainer,
                count_datagrams_per_type));

    cls.def("find_datagram_types",
            &T_BaseClass::find_datagram_types,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_DatagramContainer,
                find_datagram_types));

    /* datagram infos filters */
    cls.def("__call__",
            py::overload_cast<T_DatagramIdentifier>(&T_BaseClass::operator(), py::const_),
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_DatagramContainer,
                operator_call),
            py::arg("datagram_identifier"));
    cls.def("__call__",
            py::overload_cast<const std::vector<T_DatagramIdentifier>&>(&T_BaseClass::operator(),
                                                                        py::const_),
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_DatagramContainer,
                operator_call_2),
            py::arg("datagram_identifiers"));

    /* datagram reading */
    cls.def("size",
            &T_BaseClass::size,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_DatagramContainer, size));
    cls.def("__len__",
            &T_BaseClass::size,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_DatagramContainer, size));
    cls.def("__getitem__",
            &T_BaseClass::at,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_DatagramContainer, at),
            py::arg("index"),
            pybind11::return_value_policy::reference_internal);
    cls.def("__getitem__",
            py::overload_cast<const tools::pyhelper::PyIndexer::Slice&>(&T_BaseClass::operator(),
                                                                        py::const_),
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_DatagramContainer,
                operator_call),
            py::arg("slice"),
            pybind11::return_value_policy::reference_internal);
    cls.def(
        "__reversed__",
        &T_BaseClass::reversed,
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_DatagramContainer, reversed),
        pybind11::return_value_policy::reference_internal);
}

template<typename T_DatagramType,
         typename T_DatagramIdentifier,
         typename T_DatagramFactory = T_DatagramType>
void create_DatagramContainerTypes(pybind11::module& m, const std::string CONTAINER_NAME)
{
    using fileinterfaces::I_DatagramContainer;
    using fileinterfaces::MappedFileStream;
    namespace py = pybind11;

    using T_CONTAINER =
        I_DatagramContainer<T_DatagramType, T_DatagramIdentifier, std::ifstream, T_DatagramFactory>;
    using T_CONTAINER_MAPPED = I_DatagramContainer<T_DatagramType,
                                                   T_DatagramIdentifier,
                                                   MappedFileStream,
                                                   T_DatagramFactory>;

    auto cls_stream = py::class_<T_CONTAINER>(
        m,
        CONTAINER_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_DatagramContainer));

    auto cls_mapped = py::class_<T_CONTAINER_MAPPED>(
        m,
        (CONTAINER_NAME + "_mapped").c_str(),
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_DatagramContainer));

    _add_DatagramReading<T_CONTAINER, T_DatagramIdentifier>(cls_stream);
    _add_DatagramReading<T_CONTAINER_MAPPED, T_DatagramIdentifier>(cls_mapped);
}

}
}
}
}
}