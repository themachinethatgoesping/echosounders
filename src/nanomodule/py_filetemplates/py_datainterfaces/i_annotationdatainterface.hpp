// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <nanobind/nanobind.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datainterfaces/i_annotationdatainterface.hpp"
#include "i_annotationdatainterfaceperfile.hpp"
#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datainterfaces {
namespace py_i_annotationdatainterface {

template<typename T_BaseClass, typename T_PyClass>
void AnnotationDataInterface_add_interface(T_PyClass& cls)
{
    namespace nb = nanobind;

    py_i_filedatainterface::FileDataInterface_add_interface<T_BaseClass>(cls);

    // cls.def("get_sensor_annotation",
    //         &T_BaseClass::get_sensor_annotation,
    //         DOC(themachinethatgoesping,
    //             echosounders,
    //             filetemplates,datainterfaces,
    //             I_AnnotationDataInterface,
    //             get_sensor_annotation),
    //             nb::arg("index"));
}

}
}
}
}
}
}