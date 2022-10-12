// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../themachinethatgoesping/echosounders/fileinterfaces/i_pingcontainer.hpp"
//#include "../docstrings.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_fileinterfaces {
namespace py_i_PingContainer {

template<typename T_BaseClass, typename T_PyClass>
void _PingContainer_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    /* get ping infos */
    cls.def(
        "max_number_of_samples",
        &T_BaseClass::max_number_of_samples,
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingContainer, max_number_of_samples));

    
    /* implement filters */
    // cls.def(
    //     "channel",
    //     &T_BaseClass::channel,
    //     DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingContainer, channel),
    //     py::arg("channel_id"));
    // cls.def(
    //     "channels",
    //     &T_BaseClass::channels,
    //     DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingContainer, channels));

    /* package reading */
    cls.def("size",
            &T_BaseClass::size,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingContainer, size));
    cls.def("__len__",
            &T_BaseClass::size,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingContainer, size));
    cls.def("__getitem__",
            &T_BaseClass::at,
            DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingContainer, at),
            py::arg("index"),
            pybind11::return_value_policy::reference_internal);
    cls.def(
        "__call__",
        &T_BaseClass::operator(),
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingContainer, operator_call),
        py::arg("index_min")  = 0,
        py::arg("index_max")  = std::numeric_limits<size_t>::max(),
        py::arg("index_step") = 1);

}

template<typename T_BaseClass, typename T_PyClass>
void add_PingContainer(T_PyClass& cls, const std::string& T_NAME)
{
    cls.def_property_readonly(
        ("i_" + T_NAME).c_str(),
        [](const T_BaseClass& self) { return self.pings(); },
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingContainer, pings),
        pybind11::return_value_policy::reference_internal);
}

template<typename T_PingType>
void create_PingContainerType(pybind11::module& m, const std::string ITERATOR_NAME)
{
    using fileinterfaces::I_PingContainer;
    namespace py = pybind11;

    using T_ITERATOR        = I_PingContainer<T_PingType>;

    auto cls_stream = py::class_<T_ITERATOR>(
        m,
        ITERATOR_NAME.c_str(),
        DOC(themachinethatgoesping, echosounders, fileinterfaces, I_PingContainer));


    _PingContainer_add_interface<T_ITERATOR>(cls_stream);
}

}
}
}
}
}