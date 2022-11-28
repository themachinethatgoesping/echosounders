// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datainterfaces/i_annotationdatainterface.hpp"
#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datainterfaces {
namespace py_i_annotationdatainterface {

template<typename T_BaseClass, typename T_PyClass>
void AnnotationPerFileDataInterface_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    py_i_filedatainterface::PerFileDataInterface_add_interface<T_BaseClass>(cls);

    // cls.def("read_sensor_annotation",
    //         &T_BaseClass::read_sensor_annotation,
    //         DOC(themachinethatgoesping,
    //             echosounders,
    //             filetemplates,datainterfaces,
    //             I_AnnotationPerFileDataInterface,
    //             read_sensor_annotation));
}

template<typename T_BaseClass, typename T_PyClass>
void AnnotationDataInterface_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    py_i_filedatainterface::FileDataInterface_add_interface<T_BaseClass>(cls);

    // cls.def("get_sensor_annotation",
    //         &T_BaseClass::get_sensor_annotation,
    //         DOC(themachinethatgoesping,
    //             echosounders,
    //             filetemplates,datainterfaces,
    //             I_AnnotationDataInterface,
    //             get_sensor_annotation),
    //             py::arg("index"));
}

}
}
}
}
}
}